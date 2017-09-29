#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int countTokens(char *in){
       char buff[65];
        int count = 0;
        strcpy(buff, in);
        char *token = strtok(buff, " ");
        while (token != NULL){
            count++;
            token = strtok(NULL, " ");
        }
        return count;
}

char **tokenizer(char *in, int *size){
    char buff[65];
    strcpy(buff, in);
    *size = countTokens(in);
    char **output;
    output = (char**) malloc (sizeof(char*) * (*size));
  
    char *token = strtok(buff, " ");
    for (int i = 0; token != NULL; i++){
        output[i] = (char*) malloc(sizeof(char) * (strlen(token)+1));
        strcpy(output[i],token);
        token = strtok(NULL, " ");
    }
    return output;
}

int prog2c(){
    char buff[65];
    char *intCheck;
    printf(">");
    fgets(buff,65,stdin);
    buff[strlen(buff)-1]='\0';
    int numtokens=0;
    char **tokens = tokenizer(buff,&numtokens);
    intCheck = strtok (buff," ");
    if(numtokens > 2 || numtokens == 0){
        printf("ERROR! Incorrect number of tokens found.\n");
        prog2c();
    }
    else {
        while (intCheck) {
            int STR = 0;
            for(int i = 0;i < strlen(intCheck);i++){
                if (isdigit(intCheck[i]) == 0)
                    STR++;
            }
            if(STR > 0)
                printf("STR ");
            else
                printf("INT ");
        intCheck = strtok (NULL," ");
        }
    printf("\n");
    }
    return (0);
}

int main(){

    printf("Assignment #2-3, Micah Joseph Grande, micah.grande@gmail.com\n");
    return (prog2c());
}
