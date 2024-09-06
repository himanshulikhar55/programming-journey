#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_HISTORY 100

struct termios orig_termios;

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char history[MAX_HISTORY][MAX_COMMAND_LENGTH];
    int history_count = 0;
    int history_index = 0;
    int cursor_position = 0;

    enable_raw_mode();

    while (1) {
        printf("$ ");
        fflush(stdout);

        memset(command, 0, sizeof(command));
        cursor_position = 0;

        while (1) {
            char c;
            if (read(STDIN_FILENO, &c, 1) == 1) {
                if (c == '\n') {
                    printf("\n");
                    break;
                } else if (c == 27) {
                    char seq[3];
                    if (read(STDIN_FILENO, &seq[0], 1) != 1) break;
                    if (read(STDIN_FILENO, &seq[1], 1) != 1) break;

                    if (seq[0] == '[') {
                        switch (seq[1]) {
                            case 'A': // Up arrow
                                if (history_index > 0) {
                                    history_index--;
                                    strcpy(command, history[history_index]);
                                    cursor_position = strlen(command);
                                    printf("\r$ %s", command);
                                }
                                break;
                            case 'B': // Down arrow
                                if (history_index < history_count - 1) {
                                    history_index++;
                                    strcpy(command, history[history_index]);
                                    cursor_position = strlen(command);
                                    printf("\r$ %s", command);
                                }
                                break;
                            case 'C': // Right arrow
                                if (cursor_position < strlen(command)) {
                                    cursor_position++;
                                    printf("\033[1C");
                                }
                                break;
                            case 'D': // Left arrow
                                if (cursor_position > 0) {
                                    cursor_position--;
                                    printf("\033[1D");
                                }
                                break;
                        }
                    }
                } else {
                    if (cursor_position < MAX_COMMAND_LENGTH - 1) {
                        memmove(&command[cursor_position + 1], &command[cursor_position], strlen(command) - cursor_position);
                        command[cursor_position] = c;
                        cursor_position++;
                        printf("\r$ %s", command);
                        printf("\033[%dG", cursor_position + 2);
                    }
                }
            }
        }

        if (strlen(command) > 0) {
            if (history_count < MAX_HISTORY) {
                strcpy(history[history_count], command);
                history_count++;
            } else {
                memmove(history[0], history[1], sizeof(history[0]) * (MAX_HISTORY - 1));
                strcpy(history[MAX_HISTORY - 1], command);
            }
            history_index = history_count;
        }

        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Here you would typically execute the command
        printf("You entered: %s\n", command);
    }

    return 0;
}