#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkLine(char *newLine);
void addNewLine(char newLine[], int lineNum, int len);
void startFile();
void closeFile();

int instructnum;

int main()
{
    printf("CLMCE Editor V0.1\n[DATs will be automatically implemented. Dont include them in your program]\n");
    char newLine[25];
    int lineNum = 1;
    int fileLineNum = 1;
    startFile();
    do{
        printf("%d| ", lineNum);
        fgets(newLine, 25, stdin);
        lineNum++;
        fileLineNum++;
        printf("%s\n", "1.before checkLine");
        bool doNewLine = checkLine(newLine);
        if(!doNewLine){
            fileLineNum--;
        }
        if(doNewLine == true){
            int len = sizeof(newLine)/sizeof(newLine[0]);
            printf("%s\n", "4.before addNewLine");
            addNewLine(newLine, fileLineNum, len);
        }
    } while (strcmp(newLine, "HLT\n") != 0);
    closeFile();
    return 0;
}

bool checkLine(char *newLine){
    char *instruction;
    printf("2.%s\n", newLine);
    instruction = (char*) calloc(4, sizeof(int));
    if(instruction == NULL){
        printf("ERROR FAILURE TO ALLOCATE MEMEORY");
        exit(1);
    }
    for(int i = 0; i < 3; i++){
        instruction[i] = newLine[i];
    }
    printf("3.%s", instruction);
    instruction[3] = '\0';
    if(strcmp(instruction, "LDA") == 0){
        instructnum = 5;
        free(instruction);
        return true;
    }
    if(strcmp(instruction, "STA") == 0){
        instructnum = 3;
        free(instruction);
        return true;
    }
    if(strcmp(instruction, "ADD") == 0){
        instructnum = 1;
        return true;
    }
    if(strcmp(instruction, "SUB") == 0){
        instructnum = 2;
        return true;
    }
    if(strcmp(instruction, "INP") == 0){
        instructnum = 901;
        return true;
    }
    if(strcmp(instruction, "OUT") == 0){
        instructnum = 902;
        return true;
    }
    if(strcmp(instruction, "BRA") == 0){
        instructnum = 6;
        return true;
    }
    if(strcmp(instruction, "BRZ") == 0){
        instructnum = 7;
        return true;
    }
    if(strcmp(instruction, "BRP") == 0){
        instructnum = 8;
        return true;
    }
    if(strcmp(instruction, "HLT") == 0){
        instructnum = 0;
        return true;
    }
    free(instruction);
    return false;
}

void addNewLine(char newLine[], int lineNum, int len){
    int *operand = (int*) malloc (17);
    printf("%s", newLine);
    if(len > 4){
        for(int i = 4; i < len; i++){
            operand[i - 4] = newLine[i];
        }
        printf("%s\n", newLine);
        printf("%s\n", operand);
    }
    FILE *tempFile;
    tempFile = fopen("temp.txt", "a");
    fprintf(tempFile, "%d,%s", lineNum - 1, newLine);
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
