// assuming there is no empty spaces between labels

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> tac;

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

void replace_label(string alpha, string beta){
    for(int i=0; i<tac.size(); i++){
        replace(tac[i].begin(), tac[i].end(), beta, alpha);
    }
}

void pop_label(int lineno){
    auto itr = tac.begin() + lineno;
    tac.erase(itr);
}

void label_optimize(){
    int lineno = 0;
    while(lineno != tac.size()-1){
        if(tac[lineno].size() and tac[lineno][0][0] == '#' and tac[lineno+1][0][0] == '#'){
            string primary_label = tac[lineno][0];
            primary_label.pop_back();
            string secondary_label = tac[lineno+1][0];
            secondary_label.pop_back();
            pop_label(lineno+1);
            replace_label(primary_label, secondary_label);
        }
        else{
            lineno++;
        }
    }
}

void print(){
    for(auto i: tac){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    fstream newfile;
    // newfile.open("../test-cases/optimize1.txt",ios::in);
    newfile.open("test-cases/optimize1.txt",ios::in);
    if (newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
            vector<string> temp;
            temp = tokenize(tp);
            tac.push_back(temp);
        }
        newfile.close();
    }

    // cout << "Before optimization: " << endl;

    // print();

    // label_optimize();
    
    // cout << endl << "##########################################" << endl;
    // cout << "After optimization: " << endl;

    print();

    return 0;
}