#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(){

    printf("Assignment #2-1, Micah Joseph Grande, micah.grande@gmail.com\n");
    char buff[65];
    fgets(buff,65,stdin);
    buff[strlen(buff)-1]='\0';
    int numtokens=0;
    char **tokens = tokenizer(buff,&numtokens);    
    for(int i = 0; i<numtokens;i++){
    printf("=%s=\n", tokens[i]);
    }
    return (0);
}
