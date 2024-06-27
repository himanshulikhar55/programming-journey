#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter the string. We are testing how the string is stored in a char array: ");
    char str[100];
    scanf("%s", str);
    printf("%s\n", str);
    char *ptrToStr = str;
    int i = 0;
    for(i=0;i<100;i++)
        if(ptrToStr[i] == '\0')
            break;
    printf("String length is: %d\n", i);
    printf("Lets explore fgets...\n");
    printf("Remember: If the newline char is still present then that will be read by fgets and we wont be able to read the input...\n");
    printf("Enter a few words with space between them: ");
    char buff[20];
    fgets(buff, sizeof(buff), stdin);
    printf("lets print the input: %s", buff);
    printf("Now let us enter the input again and see if the input is taken properly. Enter a few words with space between them: ");
    fgets(buff, sizeof(buff), stdin);
    printf("lets print the input again: %s\n", buff);
    /*
        fgests will store the newline char and then terminate the input. So if the input is 19chars and newline then only 19 chars will be
        stored. but if you input anything less than 19 chars and newline char, then newline will be a part of input and the char after newline
        will be \0 (the string terminating char).
        Note here were are assuming that the buffer len is 20.
    */
    return 0;
}