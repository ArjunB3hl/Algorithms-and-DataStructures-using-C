#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CMD_LEN 100
#define MAX_ARGS 10

char** parse_command(char* command) {
    char** argv = malloc(MAX_ARGS * sizeof(char*));
    int argc = 0;

    // Split the command into arguments
    char* token = strtok(command, " \n");
    while (token != NULL && argc < MAX_ARGS - 1) {
        argv[argc++] = token;
        token = strtok(NULL, " \n");
    }
    argv[argc] = NULL; // End of arguments
    return argv;
}

int main(int argc, char** argv) {
    char *parent_command = (char *)malloc(MAX_CMD_LEN * sizeof(char));
    char *child_command = (char *)malloc(MAX_CMD_LEN * sizeof(char));
    int c, index = 0;

    printf("Your Command> ");
    while (index < MAX_CMD_LEN - 1 && (c = getchar()) != '\n' && c != EOF) {
        parent_command[index++] = (char)c;
    }
    parent_command[index] = '\0';

    child_command = strchr(parent_command, '|') + 1;
    if (child_command == (char *)1) {
        fprintf(stderr, "No Pipe Found\n");
        exit(1);
    }

    // Remove the pipe character and trailing spaces
    *(child_command - 1) = '\0';
    for (char *temp = child_command; temp[0] == ' '; temp++) {
        child_command++;
    }
    for (char *temp = strchr(parent_command, '\0') - 1; temp > parent_command && temp[0] == ' '; temp--) {
        *temp = '\0';
    }

    int pd[2];
    if (pipe(pd) < 0) {
        fprintf(stderr, "Error in creating pipe\n");
        exit(1);
    }

    if (fork() == 0) {
        // Child process
        dup2(pd[0], STDIN_FILENO);
        close(pd[1]);
        char** child_args = parse_command(child_command);
        execvp(child_args[0], child_args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        dup2(pd[1], STDOUT_FILENO);
        close(pd[0]);
        char** parent_args = parse_command(parent_command);
        execvp(parent_args[0], parent_args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    return 0;
}



