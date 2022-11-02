#include<bits/stdc++.h>
using namespace std;


int main(int argc, char*argv[]){

    char cmd3[100] = "echo \"\" > merge.txt";
    system(cmd3);

    char cmd4[100] = "echo \"\" > ../tac.txt";
    system(cmd4);
    
    for(int i=1; i<argc; i++){
        printf("Filename: %s\n", argv[i]);
        char cmd2[100] = "cat ";
        strcat(cmd2, argv[i]);
        strcat(cmd2, " >> merge.txt");
        int ret = system(cmd2);
        if(ret==0)
            printf("Executed1\n");
        else
            printf("Not Executed1\n");
    }
    char pre_cmd[100] = ".././parser < merge.txt > ../tac.txt";
    printf("Command: %s\n", pre_cmd);
    int ret = system(pre_cmd);

    if(ret==0)
        printf("Executed1\n");
    else
        printf("Not Executed1\n");
    return 0;
}

// ./merge ../test-cases/header1.txt ../test-cases/main1.txt 