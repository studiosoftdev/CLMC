#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNewLine(char newLine[]);

int main()
{
    char newLine[50];
    int lineNum = 1;
    do{
        printf("%d| ", lineNum);
        fgets(newLine, 25, stdin);
        lineNum++;
    } while (strcmp(newLine, "END\n") != 0);
    return 0;
}
