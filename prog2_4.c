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

int prog2d(){
    char buff[65], buff2[65];
    char *intCheck;
    printf("> ");
    fgets(buff,65,stdin);
    buff[strlen(buff)-1]='\0';
    strcpy(buff2,buff);
    int numtokens=0;
    char **tokens = tokenizer(buff,&numtokens);
    intCheck = strtok (buff," ");
    if(strcasecmp(buff,"QUIT") == 0)
        goto quit;
    if(strlen(buff2) > 20){
        printf("ERROR! Input string too long.\n");
        prog2d();
    }
    else if(numtokens > 2 || numtokens == 0){
        printf("ERROR! Incorrect number of tokens found.\n");
        prog2d();
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
    prog2d();
    }
    quit: return (0);
}

int main(){

    printf("Assignment #2-4, Micah Joseph Grande, micah.grande@gmail.com\n");
    return (prog2d());
}
