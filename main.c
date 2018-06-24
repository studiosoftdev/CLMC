#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkLine(/*char *newLine*/);
void addNewLine(char newLine[], int lineNum);
void startFile();
void closeFile();

int main()
{
    printf("CLMCE Editor V0.1\n");
    char newLine[25];
    int lineNum = 1;
    startFile();
    do{
        printf("%d| ", lineNum);
        fgets(newLine, 25, stdin);
        lineNum++;
        bool doNewLine = checkLine();
        if(doNewLine == true){
            addNewLine(newLine, lineNum);
        }
    } while (strcmp(newLine, "END\n") != 0);
    closeFile();
    return 0;
}

bool checkLine(/*char *newLine*/){
    return true;
}

void addNewLine(char newLine[], int lineNum){
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
