#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> tac;
vector<string> vm;
map<string, int> constant;
int constant_idx = 0;
map<string, int> local;
int local_idx = 0;
map<string, int> argument;
map<string, int> temp;
int temp_idx = 0;

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
            constant[var] = constant_idx++;
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
            vm.push_back(tac[i][0]);
        }
        if(tac[i].size() > 1){
            if(tac[i].size() == 6 and tac[i][1] == "=" and tac[i][3] == "+"){
                pair<int, string> type_a = get_type(tac[i][0]);
                pair<int, string> type_b = get_type(tac[i][2]);
                pair<int, string> type_c = get_type(tac[i][4]);
                vm.push_back("push " + type_b.second + " " + to_string(type_b.first));
                vm.push_back("push " + type_c.second + " " + to_string(type_c.first));
                vm.push_back("Add");
                vm.push_back("pop " + type_a.second + " " + to_string(type_a.first));
            }
            else if(tac[i].size() == 3){
                if(tac[i][0] == "return"){
                    pair<int, string> type_a = get_type(tac[i][1]);
                    vm.push_back("push " + type_a.second + " " + to_string(type_a.first));
                    vm.push_back("return");
                }
                else if(tac[i][0] == "-"){
                local[tac[i][2]] = local_idx++;
                }
            }
            else if(tac[i].size() == 4){
                pair<int, string> type_a = get_type(tac[i][0]);
                pair<int, string> type_b = get_type(tac[i][2]);
                vm.push_back("push " + type_b.second + " " + to_string(type_b.first));
                vm.push_back("pop " + type_a.second + " " + to_string(type_a.first));
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
    conversion();
    print_vm();

}