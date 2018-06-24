#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        addNewLine(newLine, lineNum);
    } while (strcmp(newLine, "END\n") != 0);
    //closeFile();
    return 0;
}

void addNewLine(char newLine[], int lineNum){
    FILE *tempFile;
    tempFile = fopen("temp.txt", "a");
    fprintf(tempFile, "%d,%s", lineNum - 1, newLine);
}

void startFile(){
    FILE *tempFile;
    tempFile = fopen("temp.txt", "w");
    fprintf(tempFile, "START\n");
}

void closeFile(){
    FILE *tempFile;
    tempFile = fopen("temp.txt", "a");
    fprintf(tempFile, "enter important stuff you might need here");
    fclose(tempFile);
}
