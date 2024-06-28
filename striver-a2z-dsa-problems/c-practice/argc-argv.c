#include<stdio.h>
#include<stdlib.h>
/*
    argv and argc are how command line arguments are passed to main() in C and C++.

    argc will be the number of strings pointed to by argv. This will (in practice) be 1 plus the number of arguments, as virtually all
    implementations will prepend the name of the program to the array (ie, at the start).

    https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean
*/
int main(int argc, char *argv[]){
    for(int i=0; i<argc; i++)
        printf("%s\n", argv[i]);
    return 0;
}