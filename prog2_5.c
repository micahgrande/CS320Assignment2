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
    char buff[256], buff2[256];
    char *intCheck;
    printf("> ");
    fgets(buff,256,stdin);
    buff[strlen(buff)-1]='\0';
    if(strcasecmp(buff,"QUIT") == 0)
        goto quit;
    strcpy(buff2,buff);
    int numtokens=0;
    char **tokens = tokenizer(buff,&numtokens);
    intCheck = strtok (buff," ");
    if(strlen(buff2) > 65){
        printf("ERROR! Input string too long.\n");
        prog2d();
    }
    else if(numtokens > 2 || numtokens == 0){
        printf("ERROR! Incorrect number of tokens found.\n");
        prog2d();
    }   
    else {
        int STR,INT;
        STR = INT = 0;
        while (intCheck) {
            int letterCount,digitCount;
            letterCount = digitCount = 0;
            for(int i = 0;i < strlen(intCheck);i++){
                if (isalpha(intCheck[i]) != 0)
                    letterCount++;
                if (isdigit(intCheck[i]) != 0)
                    digitCount++;
            }
                if(letterCount > 0)
                    STR++;
                if(digitCount > 0)
                    INT++;
        intCheck = strtok (NULL," ");
        }
            if (numtokens == 2 && (STR != 1 || INT != 1))
                printf("ERROR! Expected STR INT.");
            else if (numtokens == 1 && INT > 0)
                printf("ERROR! Expected STR.");
            else if (numtokens == 1 && STR > 0)
                printf("STR");
            else 
                printf("STR INT");
    printf("\n");
    prog2d();
    }
    quit: return (0);
}

int main(){

    printf("Assignment #2-5, Micah Joseph Grande, micah.grande@gmail.com\n");
    return (prog2d());
}
