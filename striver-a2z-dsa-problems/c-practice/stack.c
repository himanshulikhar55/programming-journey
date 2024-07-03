#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stringcmp(char *str1, char *str2){
    while(*str1!='\0' && *str2!='0'){
        if(*str1 == *str2){
            ++str1;
            ++str2;
        } else {
            return 1;
        }
    }
    if(*str1 == *str2 && *str1 == '\0')
        return 0;
    return 1;
}
int main(){
    int size;
    int *arr;
    char c;
    printf("Please enter the maximum size of the stack: ");
    scanf("%d", &size);
    arr = (int *)malloc(sizeof(int) * size);
    if(!arr){
        printf("Memory allocation failed. Please try again!\n");
        return 0;
    }
    printf("Memory allocation was successfull. Let us proceed...\n");
    printf("Please enter commands in the following manner (without quotes) to interact with the stack: \n");
    printf("1) 'pu <number>' to push <number> into the stack\n");
    printf("2) 'pop' to pop from the stack\n");
    printf("3) 'top' to see the top of the stack\n");
    printf("4) 'exit' to exit the program\n");
    char input[15];
    char *option;
    int num, top = -1;
    //scan the trailing newline of last ip
    scanf("%c", &c);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    while(stringcmp(input, "exit")!=0){
        option = strtok(input, " ");
        if(stringcmp(option, "pop") == 0){
            if(top < 0)
                printf("Stack is empty!\n");
            else{
                printf("Top element popped: %d\n", arr[top]);
                --top;
            }
        } else if(stringcmp(option, "top") == 0) {
            if(top < 0)
                printf("Stack is empty!\n");
            else {
                printf("Top of stack is: %d\n", arr[top]);
            }
        } else {
            if(stringcmp(option, "pu") == 0){
                ++top;
                if(top >= size){
                    printf("Overflow! Will not push into the stack!\n");
                    --top;
                } else {
                    option = strtok(NULL, " ");
                    if(!option){
                        printf("Invalid format for pushing the number! Please follow the following format: pu <number>\n");
                    } else {
                        num = atoi(option);
                    }
                    arr[top] = num;
                }
            } else {
                printf("Invalid option!\n");
            }
        }
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
    }

}