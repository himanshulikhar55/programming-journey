#include<stdio.h>
#include<stdlib.h>
/*
    calloc() gives you a zero-initialized buffer, while malloc() leaves the memory uninitialized.

    For large allocations, most calloc implementations under mainstream OSes will get known-zeroed pages from the OS
    (e.g. via POSIX mmap(MAP_ANONYMOUS) or Windows VirtualAlloc) so it doesn't need to write them in user-space. This is how normal malloc
    gets more pages from the OS as well; calloc just takes advantage of the OS's guarantee.

    This means calloc memory can still be "clean" and lazily-allocated, and copy-on-write mapped to a system-wide shared physical page of
    zeros. (Assuming a system with virtual memory.) The effects are visible with performance experiments on Linux, for example
*/
int main(){
    int *arr;
    int n;
    printf("Please enter the array size follwed by the elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("The array that you entered is: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Will free the block of arr now...\n");
    free(arr);
    //arr now becomes a dangling pointer (if we use it)
    return 0;
}