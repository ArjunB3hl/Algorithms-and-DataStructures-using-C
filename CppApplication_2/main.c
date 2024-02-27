#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    char command[100];
    int index = 0;
    bool ampFlag = false;
    
    char *argPtr[100];
    int argPtrIndex = 0;
    
    printf("Your command> \n");
    argPtr[argPtrIndex] = &command[0];
    
    while((command[index] = getchar()) != '\n'){
        if(command[index] == ' '){
            command[index] = '\0';
            argPtrIndex++;
            argPtr[argPtrIndex] = &command[index + 1];
        }
        index++;
    }
    command[index] = '\0'; // Null-terminate the string

    // Trim trailing spaces
    int lastIndex = index - 1;
    while (lastIndex > 0 && command[lastIndex] == ' ') {
        command[lastIndex] = '\0';
        lastIndex--;
    }

    // Check for ampersand
    if(command[lastIndex] == '&'){
        ampFlag = true;
        command[lastIndex] = '\0';  // Remove the '&' from the command
        argPtrIndex--;  // Adjust the argument count
    }

    argPtr[argPtrIndex + 1] = NULL; // Null-terminate the argument list

    // Create new process
    pid_t cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(cpid == 0){
        printf("A Child Process has been created.\n");
        execvp(argPtr[0], argPtr);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        printf("Parent process is currently waiting.\n");
        if(!ampFlag){
            wait(NULL);
        }
        printf("Parent Process has ended.\n");
    }
    
    return EXIT_SUCCESS;
}
