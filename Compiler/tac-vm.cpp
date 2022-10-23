#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> tac;
vector<string> vm;
map<string, pair<int, string>> constant;
map<string, pair<int, string>> local;
int local_idx = 0;
map<string, pair<int, string>> argument;
map<string, pair<int, string>> temp;
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
        if(local.find(var) == local.end()){
            local[var].first = local_idx++;
            local[var].second = type;
        }
        temp_var.first.first = local[var].first;
        temp_var.first.second = local[var].second;
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
                pair<pair<int, string>, string> type_a = get_type(tac[i][0], tac[i][5]);
                pair<pair<int, string>, string> type_b = get_type(tac[i][2], "null");
                pair<pair<int, string>, string> type_c = get_type(tac[i][4], "null");
                vm.push_back("push " + type_b.second + " " + to_string(type_b.first.first) + " " + type_b.first.second);
                vm.push_back("push " + type_c.second + " " + to_string(type_c.first.first) + " " + type_c.first.second);
                vm.push_back(op_map[tac[i][3]]);
                vm.push_back("pop " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
            }
            else if(tac[i].size() == 3){
                if(tac[i][0] == "return"){
                    pair<pair<int, string>, string> type_a = get_type(tac[i][1], tac[i][2]);
                    vm.push_back("push " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                    vm.push_back("return");
                }
                else if(tac[i][0] == "-"){
                    // for local variable declaration
                    local[tac[i][2]].first = local_idx++;
                    local[tac[i][2]].second = tac[i][1];
                }
            }
            else if(tac[i].size() == 4){
                pair<pair<int, string>, string> type_a = get_type(tac[i][0], tac[i][3]);
                pair<pair<int, string>, string> type_b = get_type(tac[i][2], "null");
                vm.push_back("push " + type_b.second + " " + to_string(type_b.first.first) + " " + type_b.first.second);
                vm.push_back("pop " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
            }
            else if(tac[i].size() == 7){
                vm.push_back("push constant 1 INT");
                pair<pair<int, string>, string> type_a = get_type(tac[i][1], "null");
                vm.push_back("push " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
                vm.push_back("Eq");
                vm.push_back("if-goto " + tac[i][3]);
                vm.push_back("push constant 0 INT");
                vm.push_back("push " + type_a.second + " " + to_string(type_a.first.first) + " " + type_a.first.second);
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