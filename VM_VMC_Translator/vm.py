import enum


class Instructions(enum.Enum):
    push = 'push'
    pop = 'pop'
    function = 'function'
    label = 'label'
    goto = 'goto'
    ret = 'return'
    if_goto = 'if-goto'
    print

    Eq = 'Eq'
    Lt = 'Lt'
    Gt = 'Gt'
    Ge = 'Ge'
    Le = 'Le'
    Neq = 'Neq'

    Add = 'Add'
    Sub = 'Sub'


class VM:
    def __init__(self):
        self.RAM = [0 for _ in range(2048)]

        self.RAM[0] = 1280          # stack segment is from 1280 to 2047
        self.sp = self.RAM[0]

        self.RAM[1] = 0
        self.lcl = self.RAM[1]      # local segment is from 0 to 635

        self.RAM[2] = 636
        self.arg = self.RAM[2]      # argument segment is from 636 to 643

        self.RAM[3] = 644
        self.tmp = self.RAM[3]      # temp segment is from 644 to 1279

    def generate_target_code(self, vm_code):

        for line in vm_code.splitlines():
            stmt = self.get_stmt(line)

            if(stmt ==)
