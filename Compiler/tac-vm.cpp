#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> tac;
vector<string> vm;
map<string, int> constant;
map<string, int> local;
int local_idx = 0;
map<string, int> argument;
map<string, int> temp;
int temp_idx = 0;
map<string, string> op_map;

void initialize(){
    // adding binary operations
    op_map["+"] = "Add";
    op_map["-"] = "Sub";
    op_map["=="] = "Eq";
    op_map[">"] = "Gt";
    op_map["<"] = "Lt";
    op_map["&"] = "And";
    op_map["|"] = "Or";
}

vector<string> tokenize(string in){
    vector<string> res;
    string temp = "";
    for(int i=0; i<in.size(); i++){
        if(in[i] == ' '){
            res.push_back(temp);
            temp = "";
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

pair<int, string> get_type(string var){
    pair<int, string> temp_var;
    if(var[0] == '@'){
        if(temp.find(var) == temp.end()){
            temp[var] = temp_idx++;
        }
        temp_var.first = temp[var];
        temp_var.second = "temp";
    }
    else if(isNumber(var)){
        if(constant.find(var) == constant.end()){
            constant[var] = stoi(var);
        }
        temp_var.first = constant[var];
        temp_var.second = "constant";
    }
    else{
        if(local.find(var) == local.end()){
            local[var] = local_idx++;
        }
        temp_var.first = local[var];
        temp_var.second = "local";
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
            else if(tac[i][0] != "end:"){
                local_idx = 0;
                temp_idx = 0;
                local.clear();
                argument.clear();
                temp.clear();
            }
        }
        if(tac[i].size() > 1){
            if(tac[i].size() == 6 and tac[i][1] == "=" and isOperator(tac[i][3])){
                pair<int, string> type_a = get_type(tac[i][0]);
                pair<int, string> type_b = get_type(tac[i][2]);
                pair<int, string> type_c = get_type(tac[i][4]);
                vm.push_back("push " + type_b.second + " " + to_string(type_b.first));
                vm.push_back("push " + type_c.second + " " + to_string(type_c.first));
                vm.push_back(op_map[tac[i][3]]);
                vm.push_back("pop " + type_a.second + " " + to_string(type_a.first));
            }
            else if(tac[i].size() == 3){
                if(tac[i][0] == "return"){
                    pair<int, string> type_a = get_type(tac[i][1]);
                    vm.push_back("push " + type_a.second + " " + to_string(type_a.first));
                    vm.push_back("return");
                }
                else if(tac[i][0] == "-"){
                    // for local variable declaration
                    local[tac[i][2]] = local_idx++;
                }
            }
            else if(tac[i].size() == 4){
                pair<int, string> type_a = get_type(tac[i][0]);
                pair<int, string> type_b = get_type(tac[i][2]);
                vm.push_back("push " + type_b.second + " " + to_string(type_b.first));
                vm.push_back("pop " + type_a.second + " " + to_string(type_a.first));
            }
            else if(tac[i].size() == 7){
                vm.push_back("push constant 1");
                pair<int, string> type_a = get_type(tac[i][1]);
                vm.push_back("push " + type_a.second + " " + to_string(type_a.first));
                vm.push_back("Eq");
                vm.push_back("if-goto " + tac[i][3]);
                vm.push_back("push constant 0");
                vm.push_back("push " + type_a.second + " " + to_string(type_a.first));
                vm.push_back("Eq");
                vm.push_back("if-goto " + tac[i][6]);
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
    print();
    initialize();
    conversion();
    print_vm();

}

// Do for unary operations
// Do for *, /
// Do for arguments, arrays