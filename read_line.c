#include <string.h>
#include <stdio.h>

int main() {
    char command[100];

    printf("$ ");
    fgets(command, 100, stdin);   
    int i;
    while (command[i] != '\0')
    {
	    i++;
    }
    command[i - 1] = '\0';

    // Print the entered command on the next line
        printf("You entered: %s\n", command);
   

    return 0;
}

