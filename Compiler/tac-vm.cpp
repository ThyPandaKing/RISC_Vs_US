#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> tac;
vector<string> vm;
map<string, pair<int, string>> constant;
map<string, pair<int, string>> local;
int local_idx = 0;
map<string, pair<int, string>> argument;
int arg_idx = 0;
map<string, pair<int, string>> temp;
int temp_idx = 0;
map<string, string> op_map;
// int label_counter = 0;


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
    string temp = "";
    for(int i=0; i<in.size(); i++){
        if(in[i] == ' '){
            res.push_back(temp);
            temp = "";
            while(i<in.size() && in[i] == ' '){
                i++;
            }
            i--;
        }
        else
            temp += in[i];
    }
    if(temp.size())
        res.push_back(temp);
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
        if (isdigit(c) == 0)
          return false;
    }
    return true;
}

bool isOperator(string op){
    if(op_map.find(op) != op_map.end())
        return true;
    return false;
}

pair<pair<int, string>, string> get_type(string var, string type){
    pair<pair<int, string>, string> temp_var;
    if(var[0] == '@'){
        if(temp.find(var) == temp.end()){
            temp[var].first = temp_idx++;
            temp[var].second = type;
        }
        temp_var.first.first = temp[var].first;
        temp_var.first.second = temp[var].second;
        temp_var.second = "temp";
    }
    else if(isNumber(var)){
        if(constant.find(var) == constant.end()){
            constant[var].first = stoi(var);
            constant[var].second = "INT";
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
                local[var].first = local_idx++;
                local[var].second = type;
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
            else if(tac[i][0] != "end:"){
                ins += "function ";
                ins += tac[i][0];
                ins.pop_back();
                vm.push_back(ins);
                // deal with arguments
            }
            else if(tac[i][0] == "end:"){
                local_idx = 0;
                temp_idx = 0;
                local.clear();
                argument.clear();
                temp.clear();
            }
        }
        if(tac[i].size() > 1){
            if(tac[i].size() == 6 and tac[i][1] == "=" and isOperator(tac[i][3])){
                pair<pair<int, string>, string> type_a = get_type(tac[i][0], tac[i][5]);
                pair<pair<int, string>, string> type_b = get_type(tac[i][2], "null");
                pair<pair<int, string>, string> type_c = get_type(tac[i][4], "null");
                vm.push_back("push " + type_b.second + " " + to_string(type_b.first.first) + " " + type_b.first.second);
                vm.push_back("push " + type_c.second + " " + to_string(type_c.first.first) + " " + type_c.first.second);
                vm.push_back(op_map[tac[i][3]] + " " + tac[i][5]);
                // vm.push_back("pop " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                // string label1 = "#E" + to_string(label_counter++);
                // string label2 = "#E" + to_string(label_counter++);
                // string label3 = "#E" + to_string(label_counter++);
                // vm.push_back("if-goto " + label1);
                // vm.push_back("goto " + label2);
                // vm.push_back("label " + label1);
                // vm.push_back("push constant 1 INT");
                // vm.push_back("pop " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                // vm.push_back("goto " + label3);
                // vm.push_back("label " + label2);
                // vm.push_back("push constant 0 INT");
                // vm.push_back("pop " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                // vm.push_back("label " + label3);
            }
            else if(tac[i].size() == 2 and tac[i][0] == "GOTO"){
                vm.push_back("goto " + tac[i][1]);
            }
            else if(tac[i].size() == 3){
                if(tac[i][0] == "return"){
                    pair<pair<int, string>, string> type_a = get_type(tac[i][1], tac[i][2]);
                    vm.push_back("push " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                    vm.push_back("return " + tac[i][2]);
                }
                else if(tac[i][0] == "-"){
                    // for local variable declaration
                    if(tac[i].size() == 3){
                        local[tac[i][2]].first = local_idx++;
                        local[tac[i][2]].second = tac[i][1];
                    }
                    else{
                        // array declarations
                        local[tac[i][2]].first = local_idx;
                        local_idx += stoi(tac[i][4]);
                        local[tac[i][2]].second = tac[i][1];
                    }
                }
                else if(tac[i][0] == "param"){
                    pair<pair<int, string>, string> type_a = get_type(tac[i][1], tac[i][2]);
                    vm.push_back("push " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                }
                else if(tac[i][0] == "output"){
                    pair<pair<int, string>, string> type_a = get_type(tac[i][1], tac[i][2]);
                    vm.push_back("push " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                    vm.push_back("print " + tac[i][2]);
                }
            }
            else if(tac[i].size() == 4){
                if(tac[i][1] == "arg"){
                    // function parameters
                    argument[tac[i][2]].first = arg_idx++;
                    argument[tac[i][2]].second = tac[i][2];
                }
                else{
                    // simple assign : t0 = t1 INT
                    pair<pair<int, string>, string> type_a = get_type(tac[i][0], tac[i][3]);
                    pair<pair<int, string>, string> type_b = get_type(tac[i][2], "null");
                    vm.push_back("push " + type_b.second + " " + to_string(type_b.first.first) + " " + type_b.first.second);
                    vm.push_back("pop " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                }
            }
            else if(tac[i].size() == 5){
                // unary operations : t0 = - t1 INT
                auto a = get_type(tac[i][0], tac[i][4]);
                auto b = get_type(tac[i][3], tac[i][4]);

                vm.push_back("push " + b.second + " " + to_string(b.first.first) + " " + a.first.second);
                if(tac[i][2] == "-")
                    vm.push_back("neg");
                else
                    vm.push_back("not");
                vm.push_back("pop " + a.second + " " + to_string(a.first.first) + " " + a.first.second);
            }
            else if(tac[i].size() == 7){
                if(tac[i][1] == "["){
                    // arr [ 8 ] = @t0 INT
                    auto a = get_type(tac[i][5], tac[i][6]);
                    auto b = get_type(tac[i][2], "INT");
                    vm.push_back("push " + a.second + " " + to_string(a.first.first) + " " + a.first.second);

                    vm.push_back("push constant " + to_string(local[tac[i][0]].first) + " INT");
                    vm.push_back("push " + b.second + " " + to_string(b.first.first) + " " + b.first.second);
                    vm.push_back("add");
                    vm.push_back("pop pointer 0");
                    vm.push_back("pop that 0");
                    // vm.push_back("pop local " + to_string(local[tac[i][0]].first + stoi(tac[i][2])) + " " + tac[i][6]);
                }
                else if(tac[i][3] == "["){
                    // @t5 = arr [ c ] INT
                    auto a = get_type(tac[i][0], tac[i][6]);
                    auto b = get_type(tac[i][4], "INT");

                    vm.push_back("push constant " + to_string(local[tac[i][2]].first) + " " + tac[i][6]);
                    vm.push_back("push " + b.second + " " + to_string(b.first.first) + " " + b.first.second);
                    vm.push_back("add");
                    vm.push_back("pop pointer 0");
                    vm.push_back("push that 0");
                    vm.push_back("pop " + a.second + " " + to_string(a.first.first) + " " + tac[i][6]);
                }
                else{
                    pair<pair<int, string>, string> type_a = get_type(tac[i][1], "null");
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