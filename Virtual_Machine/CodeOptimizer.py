import imp
import re
from CodeGenerator import CodeGenerator
import os
import sys


class Node:
    def __init__(self, index, code_block):
        self.index = index
        self.code_block = code_block
        self.next = set()
        self.leading_label = None
        if ':' in code_block.split('\n')[0]:
            self.leading_label = code_block.split('\n')[0].split(':')[0]
        self.function_next = None


class CodeOptimizer:

    operators = set("+ - * / % && || > < >= <= ! != = ==".split())
    relational_operators = set("> < >= <= != ==".split())
    logical_operators = set("&& || !".split())

    def __init__(self):
        self.blocks = []
        self.label_index = 100
        self.temp_index = 0
        self.register_allocation = CodeGenerator()

    def is_condition_statement(self, instruction) -> bool:
        """
        returns true if the given instruction
        is a condition statement
        """
        split = instruction.split(' ')
        if(len(split) != 6):
            return False
        if(len(set(split).intersection(self.relational_operators)) == 1 and
                split[1] == '='):
            return True
        return False

    def is_logical_statement(self, instruction) -> bool:
        """
        returns true if the given instruction
        is a condition statement
        """
        split = instruction.split(' ')
        if(len(split) != 6):
            return False
        if(len(set(split).intersection(self.logical_operators)) == 1 and
                split[1] == '='):
            return True
        return False

    def get_new_temp(self) -> str:
        temp = '@_t'+str(self.temp_index)
        self.temp_index += 1
        return temp

    def get_new_label(self) -> str:
        label = '___L'+str(self.label_index)
        self.label_index += 1
        return label

    def get_node(self, graph, index) -> Node:
        for node in graph:
            if node.index == index:
                return node
        return None

    def DFS(self, visited=None, graph=[], node=None) -> None:
        if node not in visited:
            visited.add(node)
            for neighbour_index in node.next:
                neighbour = self.get_node(graph, neighbour_index)
                self.DFS(visited, graph, neighbour)

    def generate_target_code(self, tac_code) -> None:
        """
        basic blocks will be built here
        by reading the tac code
        """

        modified_tac = ''
        for line in tac_code.splitlines():
            # directly converting to risc v code
            if(self.is_logical_statement(line)):
                line = line.split(' ')
                if(line[3] == '||'):
                    # t0 = t1 || t2
                    """
                        if t1 != 0 GOTO ___L0
                        if t2 == 0 GOTO ___L1
                        ___L0:
                            t0 = 1
                            GOTO ___L2
                        ___L1:
                            t0 = 0
                        ___L2:
                    """
                    l0 = self.get_new_label()
                    l1 = self.get_new_label()
                    l2 = self.get_new_label()
                    replacement_str += f"if {line[2]} != 0 GOTO {l0}\n"
                    replacement_str += f"if {line[4]} == 0 GOTO {l1}\n"
                    replacement_str += f"{l0}:\n"
                    replacement_str += f"{line[0]} = 1\n"
                    replacement_str += f"GOTO {l2}\n"
                    replacement_str += f"{l1}:\n"
                    replacement_str += f"{line[0]} = 0\n"
                    replacement_str += f"{l2}:\n"
                elif(line[3] == '&&'):
                    # t0 = t1 && t2
                    """
                        if t1 == 0 GOTO ___L1
                        if t2 == 0 GOTO ___L1
                        ___L0:
                            t0 = 1
                            GOTO ___L2
                        ___L1:
                            t0 = 0
                        ___L2:
                    """
                    l0 = self.get_new_label()
                    l1 = self.get_new_label()
                    l2 = self.get_new_label()
                    replacement_str += f"if {line[2]} == 0 GOTO {l1}\n"
                    replacement_str += f"if {line[4]} == 0 GOTO {l1}\n"
                    replacement_str += f"{l0}:\n"
                    replacement_str += f"{line[0]} = 1\n"
                    replacement_str += f"GOTO {l2}\n"
                    replacement_str += f"{l1}:\n"
                    replacement_str += f"{line[0]} = 0\n"
                    replacement_str += f"{l2}:\n"

            if(self.is_condition_statement(line)):
                relop = line.split()[3]
                temp = line.split()[0]
                t0 = self.get_new_temp()
                left_operand = line.split()[2]
                right_operand = line.split()[4]
                replacement_str = f"{t0} = {left_operand} - {right_operand} INT\n"
                l0 = self.get_new_label()
                l1 = self.get_new_label()
                l2 = self.get_new_label()
                replacement_str += f"if {t0} {relop} 0 GOTO {l0} else GOTO {l1}\n"
                replacement_str += f"{l0}:\n"
                replacement_str += f"{temp} = 1 INT\n"
                replacement_str += f"GOTO {l2}\n"
                replacement_str += f"{l1}:\n"
                replacement_str += f"{temp} = 0 INT\n"
                replacement_str += f"{l2}:\n"
                modified_tac += replacement_str
            else:
                modified_tac += line+'\n'

        # manually declaring temporaries
        declared_temps = []
        final_tac = ''
        for line in modified_tac.splitlines():
            if(re.search(r'^@.+', line) is not None and line.split(' ')[0] not in declared_temps
                    and re.search(r'^@call+', line) is None):
                final_tac += f"- {line.split(' ')[-1]} {line.split(' ')[0]}\n"
                declared_temps.append(line.split(' ')[0])
            final_tac += line+'\n'

        # replacing '#' with '__' for labels
        final_tac = final_tac.replace('#', '__')

        # print(final_tac)

        final_tac = self.pre_optimizations(final_tac)

        block_lines = ''
        for line in final_tac.splitlines():
            if(line.lower().startswith('.global')):
                block_lines += line
            elif line.strip() == '' or line.strip() == 'end:':
                pass
            elif line.lower().startswith('if') or line.lower().startswith('goto') \
                    or line.startswith('return') or '@call' in line:
                block_lines += line
                self.blocks.append(block_lines)
                block_lines = ''
            elif line.endswith(':'):
                if(block_lines.strip() != ''):
                    self.blocks.append(block_lines)
                block_lines = line
            else:
                block_lines += line
            block_lines += '\n'

        if(block_lines.strip() != ''):
            self.blocks.append(block_lines)

        # printing the generated blocks
        # print(*self.blocks, sep='\n----------------\n')

        self.optimize()

    def pre_optimizations(self, intermediate_code) -> str:
        """
        function that performs basic
        optimizations before generating blocks 
        """

        goto_labels = set()
        for lines in intermediate_code.splitlines():
            line_arr=lines.split(' ')
            if 'GOTO' in line_arr[0]:
                goto_labels.add(line_arr[-1])
            elif 'GOTO' in lines:
                for i in range(len(line_arr)):
                    if(line_arr[i]=='GOTO'):
                        goto_labels.add(line_arr[i+1])

        # removes all labels that have no goto statements pointing to them
        optimized_code0 = ""
        for lines in intermediate_code.splitlines():
            if (lines.startswith('__L') or lines.startswith('___L')) and lines.split(':')[0] not in goto_labels:
                pass
            else:
                optimized_code0 += lines + '\n'

        intermediate_code_list = optimized_code0.splitlines()
        optimized_code1 = intermediate_code_list[0] + '\n'
        i = 1
        while i < len(intermediate_code_list):
            if 'return' in intermediate_code_list[i-1] and 'return' in intermediate_code_list[i]:
                pass
            else:
                optimized_code1 += intermediate_code_list[i] + '\n'
            i += 1

        # removes labels in consecutive lines and replaces all the occurences of the label with the first one
        optimized_code2 = ""
        redundant_labels = {}
        optimized_code_list = optimized_code1.splitlines()
        i = 0
        while i < len(optimized_code_list):
            lines = optimized_code_list[i]
            if (lines.startswith('__L') or lines.startswith('___L')):
                optimized_code2 += lines + '\n'
                k = i
                for j in range(i+1, len(optimized_code_list)):
                    if (optimized_code_list[j].startswith('__L') or optimized_code_list[j].startswith('___L')):
                        try:
                            redundant_labels[optimized_code_list[i].split(
                                ':')[0]].append(optimized_code_list[j].split(':')[0])
                        except KeyError:
                            redundant_labels[optimized_code_list[i].split(
                                ':')[0]] = [optimized_code_list[j].split(':')[0]]
                        k = j
                    else:
                        k += 1
                        break
                i = k
            else:
                optimized_code2 += lines + '\n'
                i += 1

        for label in redundant_labels.keys():
            for l in redundant_labels[label]:
                optimized_code2 = optimized_code2.replace(l+':', '')
                optimized_code2 = optimized_code2.replace(l, label)

        # removes all the goto statements that occur in consecutive statements
        optimized_code3 = ""
        optimized_code_list = optimized_code2.splitlines()
        i = 0
        while i < len(optimized_code_list):
            lines = optimized_code_list[i]
            if lines.lower().startswith('goto'):
                optimized_code3 += lines+'\n'
                k = i
                for j in range(i+1, len(optimized_code_list)):
                    if optimized_code_list[j].lower().startswith('goto'):
                        k = j
                    else:
                        k += 1
                        break
                i = k
            else:
                optimized_code3 += lines+'\n'
                i += 1

        # removes goto X and label X statements if they occur in consecutive lines
        optimized_code4 = ""
        optimized_code_list = optimized_code3.splitlines()
        i = 0
        while i < len(optimized_code_list):
            lines = optimized_code_list[i]
            if lines.lower().startswith('goto'):
                label = lines.split(' ')[-1]
                k = 0
                flag = True
                for k in range(len(optimized_code_list)):
                    if k != i and optimized_code_list[k].lower().startswith('goto') and optimized_code_list[k].split(' ')[-1] == label:
                        flag = False
                        break
                if (optimized_code_list[i+1].startswith('__L') or optimized_code_list[i+1].startswith('___L')) and optimized_code_list[i+1].split(':')[0] == label and flag:
                    i += 1
                else:
                    optimized_code4 += lines+'\n'
            else:
                optimized_code4 += lines+'\n'
            i += 1

        return optimized_code4

    def eliminate_dead_code(self, blocks) -> list:
        """
        function that eliminates dead code
        """

        full_code = '\n'.join(blocks)
        all_lines = full_code.split('\n')

        return_map = []
        return_pointer = 0
        for index, line in enumerate(all_lines):
            if 'return' in line:
                return_map.append(index)

        CFG = []
        blocks_current = []
        for block in blocks:
            block = block.strip('\n')
            if block.isspace() or len(block) == 0:
                continue
            else:
                blocks_current.append(block)
        for index, block in enumerate(blocks_current):
            new_node = Node(index, block)
            CFG.append(new_node)

        # Find all the function calls
        for i in range(1, len(CFG)):
            block = CFG[i-1].code_block
            last_line = block.split('\n')[-1]
            if len(last_line.split(' ')) >= 4 and last_line.split(' ')[-4] == '@call':
                # funct = last_line.split(' ')[-2].split(',')[0]
                funct = last_line.split(' ')[-3]
                CFG[i].function_next = funct

        # Start creating Control Flow Graph connections
        for node in CFG:
            last_line = node.code_block.split('\n')[-1]
            words = last_line.split(' ')
            if (len(words) >= 1 and (words[0].lower() == 'goto' or words[0].lower() == 'return')) or '@call' in words:
                # The direct goto statements (without condition)
                if words[0].lower() == 'goto':
                    label = words[1]
                    for search_node in CFG:
                        if search_node.leading_label is not None and search_node.leading_label == label:
                            node.next.add(search_node.index)
            else:
                # Add a connection from current block to the next block in sequence as there is no break of control flow
                if node.index < (len(blocks_current)-1):
                    node.next.add(node.index+1)

            if len(words) > 2 and words[-2].lower() == 'goto':
                # For the gotos that accompany an if or ifFalse statement (with condition)
                label = words[-1]
                for search_node in CFG:
                    if search_node.leading_label is not None and search_node.leading_label == label:
                        node.next.add(search_node.index)
            # Identify the return statements and connect them to the points where they are called
            if len(words) >= 1 and words[0] == 'return':
                index = return_map[return_pointer]
                # Returns the location of the current return statement in the list of all code lines
                # we go upwards and search for the first functin label -> This is the function that this return statement belongs to
                # Hence we need to find all calls to this functin and make a connection going from this return statement to the next line after the specific function call
                while index >= 0:
                    words = all_lines[index].split(' ')
                    word = None
                    if len(words) < 1:
                        index -= 1
                        continue
                    else:
                        word = words[0]

                    if not (word.startswith('__L') or word.startswith('___L')) and word.endswith(':'):
                        word = word.split(':')[0]
                        # print("Function label found", word)
                        for search_node in CFG:
                            if search_node.function_next is not None and search_node.function_next == word:
                                node.next.add(search_node.index)
                        break
                    index -= 1

                return_pointer += 1
            # print('current line', words)
            if (len(words) > 3 and words[0] == '@call') or (len(words) > 5 and words[-4] == 'call'):
                # print("call found")
                # funct = words[-2].split(',')[0]
                funct = words[-3]
                # print('index of this block: ', node.index)
                for search_node in CFG:
                    if search_node.leading_label is not None and search_node.leading_label == funct:
                        node.next.add(search_node.index)

            # print("Current node index", node.index)
            # print('Current node code\n', node.code_block)
            # print('in case of a call -> Function next stores: ', node.function_next)
            # print('Next blocks', node.next)
            # print("================================================")

        # The CFG is now completed - we now perform a depth first search to identify the dead code blocks
        # And block unfreachable from the start block is dead code

        # Step 1: Find the start block, i.e., the one that contains 'start' as the leading label
        start_block = None
        for node in CFG:
            if node.leading_label == 'main':
                start_block = node
                break
        # print('start_block', start_block, type(start_block))
        visited = set()
        # Call DFS and obtin the visited blocks
        self.DFS(visited=visited, graph=CFG, node=start_block)
        list_of_visited_blocks = list(visited)
        list_of_visited_blocks.sort(key=lambda x: x.index)
        # COnvert the visited set to a list and append only the code blocks to blocks and then return it
        blocks = []
        for node in list_of_visited_blocks:
            blocks.append(node.code_block)
            # print(node.index)

        # print("dead code elimination:")
        # print(*blocks, sep = '\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n')

        return blocks


    def optimize(self) -> None:
        """
        all optimizations occur here
        """

        self.eliminate_dead_code(self.blocks)

        final_asm = self.register_allocation.main(self.blocks)

        final_asm = self.post_optimizations(final_asm)

        # print(final_asm)
        script_dir = os.path.dirname(__file__)
        rel_path = 'outputs/'+sys.argv[1].split('/')[-1].split('.')[0]+'.asm'
        abs_file_path = os.path.join(script_dir, rel_path)

        with open(abs_file_path, 'w+') as file:
            file.write(final_asm)

    def post_optimizations(self, asm_code):
        """
        function that performs optimizations
        on asm code generated
        """

        final_asm=''

        # sw x5, -4(x8)
        # # ---- end of block ----
        # sw x5, -4(x8)
        lines=asm_code.splitlines()
        i=0
        while(i<len(lines)-1):
            j=i+1
            while(j<len(lines) and lines[j].startswith('#')):
                j+=1
            # print(lines[i],lines[j])
            if(lines[i]!=lines[j]):
                final_asm+=lines[i]+'\n'
            i+=1
        final_asm+=lines[-1]
        
        return final_asm
            
