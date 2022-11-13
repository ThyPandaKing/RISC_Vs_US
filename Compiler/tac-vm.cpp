#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> tac;
vector<string> vm;
map<string, pair<string, string>> constant;
map<string, pair<string, string>> local;
int local_idx = 0;
map<string, pair<string, string>> argument;
int arg_idx = 0;
map<string, pair<string, string>> temp;
int temp_idx = 0;
map<string, string> op_map;
map<string, int> strings;
int str_idx=0;

map<string, pair<int, int>> fun_var_count;
string curr_fun_name, curr_ret_type;


void initialize(){
    // adding binary operations
    op_map["+"] = "add";
    op_map["-"] = "sub";
    op_map["=="] = "eq";
    op_map[">"] = "gt";
    op_map["<"] = "lt";
    op_map["&"] = "and";
    op_map["|"] = "or";
}

vector<string> tokenize(string in){
    vector<string> res;
    string temp_t = "";
    for(int i=0; i<in.size(); i++){
        if(in[i] == ' '){
            res.push_back(temp_t);
            temp_t = "";
            while(i<in.size() && in[i] == ' '){
                i++;
            }
            i--;
        }
        else{
            if(in[i] == '"'){
                string str="";
                while(i<in.size() && in[i] != '\n')
                    str += in[i++];

                int l=0;
                while(in[i] != '"'){
                    i--;
                    l++;
                }

                temp_t = str.substr(0,str.length()-l+1);
            }
            else{
                temp_t += in[i];
            }
        }
    }
    if(temp_t.size())
        res.push_back(temp_t);
    return res;
}

void print(){
    for(auto i: tac){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}

bool isNumber(string& str){
    for (char const &c : str){      
        if (isdigit(c) == 0 && c != '.')
          return false;
    }
    return true;
}

bool isOperator(string op){
    if(op_map.find(op) != op_map.end())
        return true;
    return false;
}

pair<pair<string, string>, string> get_type(string var, string type){
    pair<pair<string, string>, string> temp_var;
    if(var[0] == '@'){
        if(temp.find(var) == temp.end()){
            temp[var].first = to_string(temp_idx);
            temp[var].second = type;
            temp_idx++;
        }
        temp_var.first.first = temp[var].first;
        temp_var.first.second = temp[var].second;
        temp_var.second = "temp";
    }
    else if(isNumber(var) || var[0] == '\''){
        if(constant.find(var) == constant.end()){
            constant[var].first = var;
            constant[var].second = type;
            // check for the constant type
        }
        temp_var.first.first = constant[var].first;
        temp_var.first.second = constant[var].second;
        temp_var.second = "constant";
    }
    else{
        if(argument.find(var) != argument.end()){
            temp_var.first.first = argument[var].first;
            temp_var.first.second = argument[var].second;
            temp_var.second = "argument";
        }
        else{
            if(local.find(var) == local.end()){
                local[var].first = to_string(local_idx);
                local[var].second = type;
                local_idx++;
            }
            temp_var.first.first = local[var].first;
            temp_var.first.second = local[var].second;
            temp_var.second = "local";
        }
    }
    return temp_var;
}

void conversion(){
    for(int i=0; i<tac.size(); i++){
        if(tac[i].size() == 1 and tac[i][0][tac[i][0].size()-1] == ':'){
            string ins = "";
            if(tac[i][0][0] == '#'){
                ins += "label ";
                ins += tac[i][0];
                ins.pop_back();
                vm.push_back(ins);
            }
            else if(tac[i][0] == "end:"){
                fun_var_count[curr_fun_name] = {local_idx, temp_idx};
                if(curr_ret_type == "VOID"){
                    vm.push_back("push constant 0 INT");
                    vm.push_back("pop argument 0 INT");
                    vm.push_back("return");
                }
                local_idx = 0;
                temp_idx = 0;
                local.clear();
                argument.clear();
                temp.clear();
            }
        }
        if(tac[i].size() > 1){
            if(tac[i].size() == 6 and tac[i][1] == "=" and isOperator(tac[i][3])){
                pair<pair<string, string>, string> type_a = get_type(tac[i][0], tac[i][5]);
                pair<pair<string, string>, string> type_b = get_type(tac[i][2], tac[i][5]);
                pair<pair<string, string>, string> type_c = get_type(tac[i][4], tac[i][5]);
                vm.push_back("push " + type_b.second + " " + type_b.first.first + " " + type_b.first.second);
                vm.push_back("push " + type_c.second + " " + type_c.first.first + " " + type_c.first.second);
                vm.push_back(op_map[tac[i][3]] + " " + tac[i][5]);
                if(op_map[tac[i][3]] != "eq")
                    vm.push_back("pop " + type_a.second + " " + type_a.first.first + " " + type_a.first.second);
            }
            else if(tac[i].size() == 2){
                if(tac[i][0] == "GOTO"){
                    vm.push_back("goto " + tac[i][1]);
                }
                else if(tac[i][0][tac[i][0].size()-1] == ':'){
                    string ins = "function " + tac[i][0];
                    ins.pop_back();
                    ins += " " + tac[i][1];
                    vm.push_back(ins);
                    curr_fun_name = tac[i][0].substr(0, tac[i][0].size()-1);
                    curr_ret_type = tac[i][1];
                }
            }
            else if(tac[i].size() == 3){
                if(tac[i][0] == "return"){
                    pair<pair<string, string>, string> type_a = get_type(tac[i][1], tac[i][2]);
                    vm.push_back("push " + type_a.second + " " + type_a.first.first + " " + type_a.first.second);
                    vm.push_back("pop argument 0 " + type_a.first.second);
                    vm.push_back("return");
                }
                else if(tac[i][0] == "-"){
                    // for local variable declaration
                    if(tac[i][1] == "STR")
                        continue;
                    if(tac[i].size() == 3){
                        local[tac[i][2]].first = to_string(local_idx++);
                        local[tac[i][2]].second = tac[i][1];
                    }
                }
                else if(tac[i][0] == "param"){
                    pair<pair<string, string>, string> type_a = get_type(tac[i][1], tac[i][2]);
                    vm.push_back("push " + type_a.second + " " + type_a.first.first + " " + type_a.first.second);
                }
                else if(tac[i][0] == "input"){
                    pair<pair<string, string>, string> type_a = get_type(tac[i][1], tac[i][2]);
                    vm.push_back("scan " + type_a.second + " " + type_a.first.first + " " + tac[i][2]);
                }
                else if(tac[i][0] == "output"){
                    if(tac[i][2] == "STR"){
                        if(tac[i][1][0] == '"'){
                            vm.push_back("push data " + to_string(str_idx) + " " + tac[i][1] + " STR");
                            strings[tac[i][1]] = str_idx++;
                        }
                        vm.push_back("push data " + to_string(strings[tac[i][1]]) + " STR");
                    }
                    else{
                        pair<pair<string, string>, string> type_a = get_type(tac[i][1], tac[i][2]);
                        vm.push_back("push " + type_a.second + " " + type_a.first.first + " " + type_a.first.second);
                    }
                    vm.push_back("print " + tac[i][2]);
                }
            }
            else if(tac[i].size() == 4){
                if(tac[i][1] == "arg"){
                    // function parameters
                    argument[tac[i][2]].first = to_string(arg_idx++);
                    argument[tac[i][2]].second = tac[i][2];
                }
                else{
                    // simple assign : t0 = t1 INT
                    if(tac[i][3] == "STR"){
                        vm.push_back("push data " + to_string(str_idx) + " " + tac[i][2] + " STR");
                        strings[tac[i][0]] = str_idx++;
                    }
                    else{
                        pair<pair<string, string>, string> type_a = get_type(tac[i][0], tac[i][3]);
                        pair<pair<string, string>, string> type_b = get_type(tac[i][2], tac[i][3]);
                        if(type_b.second == "constant")
                            vm.push_back("push " + type_b.second + " " + tac[i][2] + " " + type_b.first.second);
                        else
                            vm.push_back("push " + type_b.second + " " + type_b.first.first + " " + type_b.first.second);
                        vm.push_back("pop " + type_a.second + " " + type_a.first.first + " " + type_a.first.second);
                    }
                }
            }
            else if(tac[i].size() == 5){
                // unary operations : t0 = - t1 INT
                auto a = get_type(tac[i][0], tac[i][4]);
                auto b = get_type(tac[i][3], tac[i][4]);

                vm.push_back("push " + b.second + " " + b.first.first + " " + a.first.second);
                if(tac[i][2] == "-")
                    vm.push_back("neg " + tac[i][4]);
                else
                    vm.push_back("not " + tac[i][4]);
                vm.push_back("pop " + a.second + " " + a.first.first + " " + a.first.second);
            }
            else if(tac[i].size() == 6){
                if(tac[i][2] == "@call"){
                    vm.push_back("call " + tac[i][3] + " " + tac[i][5]);
                    pair<pair<string, string>, string> a = get_type(tac[i][0], tac[i][4]);
                    vm.push_back("push argument 0 " + tac[i][4]);
                    vm.push_back("pop " + a.second + " " + a.first.first + " " + a.first.second);
                }
                else if(tac[i][3] == "["){
                    // array declarations
                    local[tac[i][2]].first = to_string(local_idx);
                    local_idx += stoi(tac[i][4]);
                    local[tac[i][2]].second = tac[i][1];
                }
            }
            else if(tac[i].size() == 7){
                if(tac[i][1] == "["){
                    // arr [ 8 ] = @t0 INT
                    auto a = get_type(tac[i][5], tac[i][6]);
                    auto b = get_type(tac[i][2], "INT");
                    vm.push_back("push " + a.second + " " + a.first.first + " " + a.first.second);

                    vm.push_back("push constant " + local[tac[i][0]].first + " INT");
                    vm.push_back("push " + b.second + " " + b.first.first + " " + b.first.second);
                    vm.push_back("push " + b.second + " " + b.first.first + " " + b.first.second);
                    vm.push_back("add INT");
                    vm.push_back("push " + b.second + " " + b.first.first + " " + b.first.second);
                    vm.push_back("push " + b.second + " " + b.first.first + " " + b.first.second);
                    vm.push_back("add INT");
                    vm.push_back("add INT");
                    vm.push_back("add INT");
                    // vm.push_back("pop pointer 0");
                    vm.push_back("pop that 0 " + tac[i][6]);
                }
                else if(tac[i][3] == "["){
                    // @t5 = arr [ c ] INT
                    auto a = get_type(tac[i][0], tac[i][6]);
                    auto b = get_type(tac[i][4], "INT");

                    vm.push_back("push constant " + local[tac[i][2]].first + " " + tac[i][6]);
                    vm.push_back("push " + b.second + " " + b.first.first + " " + b.first.second);
                    vm.push_back("push " + b.second + " " + b.first.first + " " + b.first.second);
                    vm.push_back("add INT");
                    vm.push_back("push " + b.second + " " + b.first.first + " " + b.first.second);
                    vm.push_back("push " + b.second + " " + b.first.first + " " + b.first.second);
                    vm.push_back("add INT");
                    vm.push_back("add INT");
                    vm.push_back("add INT");
                    // vm.push_back("pop pointer 0");
                    vm.push_back("push that 0 " + tac[i][6]);
                    vm.push_back("pop " + a.second + " " + a.first.first + " " + tac[i][6]);
                }
                else{
                    // if t0 goto L1 else goto L2
                    pair<pair<string, string>, string> type_a = get_type(tac[i][1], "null");
                    // vm.push_back("push constant 0 INT");
                    // vm.push_back("push " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                    // vm.push_back("eq INT");
                    vm.push_back("if-goto " + tac[i][3]);
                    vm.push_back("goto " + tac[i][6]);
                }
            }
        }
    }
}

void print_vm(){
    for(int i=0; i<vm.size(); i++){
        if(vm[i].substr(0,8) == "function"){
            vector<string> temp;
            temp = tokenize(vm[i]);
            cout << temp[0] + " " + temp[1] + " " + to_string(fun_var_count[temp[1]].first) + " " + to_string(fun_var_count[temp[1]].second) << " " << temp[2] << endl;
        }
        else
            cout << vm[i] << endl;
    }
}

int main(){
    fstream newfile;
    newfile.open("tac.txt",ios::in);
    if (newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
            vector<string> temp;
            temp = tokenize(tp);
            tac.push_back(temp);
        }
        newfile.close();
    }
    // print();
    initialize();
    conversion();
    print_vm();

}

// for now arrays are considered to be local
// arguments loading at the time of function call is pending

// Do for unary operations   :DONE
// Do for *, /   :DONE
// Do for arguments, arrays   :DONE