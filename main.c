#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int checkLine(char *newLine, int fileLineNum);
void addNewLine(char newLine[], int len);
void addDatLine(char *instruction, char *newLine, int fileLineNum);
void startFile();
void closeFile();

int instructnum;
int lineNum = 1;
int fileLineNum = 1;

int main()
{
    printf("CLMCE Editor V0.1\n[DATs will be automatically implemented - Dont include them in your program]\n");
    char newLine[25];
    startFile();
    do{
        printf("%d| ", lineNum);
        fgets(newLine, 25, stdin);
        lineNum++;
        int doNewLine = checkLine(newLine, fileLineNum);
        if(doNewLine == 0){
            fileLineNum--;
        }
        if(doNewLine == 1){
            int len = sizeof(newLine)/sizeof(newLine[0]);
            addNewLine(newLine, len);
        }
        fileLineNum++;
    } while (strcmp(newLine, "HLT\n") != 0);
    closeFile();
    return 0;
}

int checkLine(char *newLine, int fileLineNum){
    char instruction[4] = {80,80,80,'\0'};
    for(int i = 0; i < 3; i++){
        instruction[i] = newLine[i];
    }
    if(strcmp(instruction, "LDA") == 0){
        instructnum = 5;
        return 1;
    }
    if(strcmp(instruction, "STA") == 0){
        instructnum = 3;
        return 1;
    }
    if(strcmp(instruction, "ADD") == 0){
        instructnum = 1;
        return 1;
    }
    if(strcmp(instruction, "SUB") == 0){
        instructnum = 2;
        return 1;
    }
    if(strcmp(instruction, "INP") == 0){
        instructnum = 901;
        return 1;
    }
    if(strcmp(instruction, "OUT") == 0){
        instructnum = 902;
        return 1;
    }
    if(strcmp(instruction, "BRA") == 0){
        instructnum = 6;
        return 1;
    }
    if(strcmp(instruction, "BRZ") == 0){
        instructnum = 7;
        return 1;
    }
    if(strcmp(instruction, "BRP") == 0){
        instructnum = 8;
        return 1;
    }
    if(strcmp(instruction, "HLT") == 0){
        instructnum = 0;
        return 1;
    }
    if(instruction[0] == '#'){
        addDatLine(instruction, newLine, fileLineNum);
        return 2;
    }
    return 0;
}

void addNewLine(char newLine[], int len){
    char operand[21];
    if(len > 4){
        for(int i = 4; i < len; i++){
            operand[i - 4] = newLine[i];
        }
    }
    FILE *tempFile;
    tempFile = fopen("temp.txt", "a");
    if(operand[0] != 0){
        fprintf(tempFile, "%d,%d,%s", fileLineNum, instructnum, operand);
    }
    if(operand[0] == 0){
        fprintf(tempFile, "%d,%d\n", fileLineNum, instructnum);
    }
    fclose(tempFile);
}

void startFile(){
    FILE *tempFile;
    tempFile = fopen("temp.txt", "w");
    fprintf(tempFile, "START\n");
    fclose(tempFile);
}

void closeFile(){
    FILE *tempFile;
    tempFile = fopen("temp.txt", "a");
    fprintf(tempFile, "END");
    fclose(tempFile);
}

void addDatLine(char *instruction, char *newLine, int fileLineNum){
    char operand[21];
    char instruction2[5] = {0,0,0,0,'\0'};
    for(int i = 0; i < 4; i++){
        instruction2[i] = newLine[i];
    }
    for(int i = 4; i < 25; i++){
        operand[i - 4] = newLine[i];
    }
    char datLine[5] = {0,0,0,0,'\0'};
    for(int i = 0; i < 4; i++){
        datLine[i] = instruction2[i];
    }
    FILE *tempFile;
    tempFile = fopen("temp.txt", "a");
    fprintf(tempFile, "%d,%s,%s", fileLineNum, datLine, operand);
    fclose(tempFile);
}
