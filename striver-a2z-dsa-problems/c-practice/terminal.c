#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
#define DELIM " "
char *read_line(){
    char *buffer;
    int buffer_size = 64, curr_pos = 0;
    //Let us initially make the buffer of size 64
    //if it overflows then we can increase the size
    buffer = (char *)malloc(sizeof(char) * buffer_size);
    char c = getchar();
    while(c != '\n' && c != EOF){
        buffer[curr_pos] = c;
        ++curr_pos;
        if(curr_pos >= buffer_size) {
            buffer_size += 64;
            buffer = (char *)realloc(buffer, buffer_size);
            buffer[curr_pos] = c;
        }
        c = getchar();
    }
    buffer[curr_pos] = '\0';
    return buffer;
}
char **parse_line(char *line){
    char **command = malloc(64 * sizeof(char*));
    char *token = strtok(line, DELIM);
    int pos = 0, buff_size = 64;
    while(token != NULL){
        command[pos] = token;
        ++pos;
        if(pos >= 64){
            buff_size += 64;
            command = (char**)realloc(command, buff_size * sizeof(char *));
        }
        token = strtok(NULL, DELIM);
    }
    //command should be a NULL terminated string
    command[pos] = NULL;
    return command;
}
int execute_command(char **args){
    pid_t pid;
    int status;

    pid = fork();
    //we will fork a child process that will run our command for us
    if(pid == 0){
        if(execvp(args[0], args) < 0){
            printf("Command '%s' not found\n", args[0]);
            exit(-1);
        }
    } else if(pid < 0){
        printf("Error while forking\n");
    } else {
        //wait for child to complete
        waitpid(pid, &status, WUNTRACED);
    }
    return 1;
}
void run_terminal(){
    char *line = NULL;
    char **command = NULL;
    int status;
    //Terminal runs on RPEL principle: Read, Parse, Execute and Loop
    //First read
    while(1){
        //we need to tell the user that the terminal is ready to take input
        printf("$");
        line = read_line();
        if(strcmp(line, "exit") == 0)
            break;
        command = parse_line(line);
        status = execute_command(command);
        //free memory
        free(line);
        free(command);
    }
}
int main(int argc, char *argv[]){
    run_terminal();
    return 0;
}
//try implementing arrow key functions