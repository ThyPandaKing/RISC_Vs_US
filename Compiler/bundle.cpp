#include<bits/stdc++.h>
using namespace std;


int main(){
    string file_list_string;
    getline(cin, file_list_string);
    vector<string> file_list;

    string temp = "";

    for(int i=0; i<file_list_string.size(); i++){
        if(file_list_string[i] == ' ' or file_list_string[i] == '\n'){
            file_list.push_back(temp);
            temp = "";
        }
        else{
            temp += file_list_string[i];
        }
    }
    file_list.push_back(temp);



    for(int i=0; i<file_list.size(); i++){
        ifstream fin;
        fin.open(file_list[i]);
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }

    return 0;
}

// test-cases/header1.txt test-cases/main1.txt