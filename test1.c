#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];
    char full_path[MAX_COMMAND_LENGTH + 10]; // Increase buffer size to handle the format string

    while (1) {
        printf("$ ");

        // Read the user's command
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove the newline character from the end of the command
        command[strcspn(command, "\n")] = '\0';

        // Exit the loop if the user enters "exit" as the command
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Get the full path of the command
        snprintf(full_path, sizeof(full_path), "/usr/bin/%s", command);

        // Execute the command using execve
        if (access(full_path, X_OK) == 0) {
            char* args[] = {full_path, NULL}; // Provide a non-null array of pointers to arguments
            if (execve(full_path, args, NULL) == -1) {
                perror("Error in execve");
                exit(EXIT_FAILURE);
            }
        } else {
            printf("Command not found: %s\n", command);
        }
    }

    printf("Exiting the shell.\n");
    return 0;
}

