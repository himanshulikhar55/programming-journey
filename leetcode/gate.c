#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sqr(x) (x*x)
// struct node{
//     int data;
//     struct node *next;
// };
// void printList(struct node *head){
//     struct node *curr = head;
//     while(curr){
//         printf("%d ", curr->data);
//         curr = curr->next;
//     }
// }
// void testFunc(struct node *head){
//     struct node *curr = head;
//     while(curr != NULL){
//         struct node *runner = curr;
//         while(runner->next != NULL){
//             if(runner->next->data == curr->data){
//                 struct node *temp = runner->next;
//                 runner->next = runner->next->next;
//                 free(temp);
//             } else {
//                 runner = runner->next;
//             }
//         }
//         curr = curr->next;
//     }
// }
// int main(){
//     struct node* head = (struct node *)malloc(sizeof(struct node));
//     struct node* temp = (struct node *)malloc(sizeof(struct node));
//     int n = 0;
//     scanf("%d", &n);
//     head->data = n;
//     head->next = NULL;
//     temp = head;
//     while(1){
//         scanf("%d", &n);
//         if(n == -1)
//             break;
//         temp->next = (struct node *)malloc(sizeof(struct node));
//         temp->next->data = n;
//         temp->next->next = NULL;
//         temp = temp->next;
//     }
//     printList(head);
//     printf("\n");
//     testFunc(head);
//     printList(head);
//     printf("\n");
//     return 0;
// }
char *f(char *c);
int main(){
    // char str[] = "abcdefgh";
    // printf("%c", *str+1);
    // int a = 3;
    // while(a>0){
    //     printf("%d",a);
    //     switch (a%2){
    //         case 1: printf("odd");
    //         case 0: printf("even");
    //         a--;
    //         break;
    //         default: printf("Invalid Ip");
    //     }
    // }
    // char str[8] = "ACE GATE";
    // int x = strlen(str);
    // if(str[8]=='\0')
    //     printf("%c\n",str[8]);
    // for(int i=0;i<x;str[i++]=str[x--]);
    // printf("%s",str);
    // x = strlen(str);
    // for(int i=0;i<x;i++)
    //     printf("%d %c",i,str[i]);
    // int a, b=5,c=8;
    // a = sqr(c/b+2);
    // printf("%d\n",a);
    // char *x;
    // int a = 512;
    // x = (char*)&a;
    // printf("%d\n",x[0]);
    // x[0]=1;
    // x[1]=2;
    // printf("%d\n",x[0]);
    // int a = 5;
    // switch(a){
    //     // default:
    //     //     a=4;
    //     // case 6:
    //     //     a--;
    //     case 5:
    //         a=a+1;
    //     // case 1:
    //     //     a=a-1;
    // }
    // printf("%d\n",a);
    // char s[10] = "GATE_2024", *p;
    // p = s+4;
    // *p = 0;
    // printf("%s", s);
    // int arr[5] = {1,2,3,4,5};
    // printf("%d %d\n",arr[2], 2[arr]);
    // return 0;
    // char c = 'A'+'A';
    // printf("%d", c);
    // int x = 5;
    // switch(x){
    //     case 1:
    //         printf("1- %d\n",x);
    //     default:
    //         printf("default: %d\n",x);
    //     case 5:
    //         printf("5- %d\n",x);
    //     case 6:
    //         printf("6- %d\n",x);
    //         break;
    // }
    // // char *f()[]; -> not allowed
    // char* (*fp[4])(char *);
    // int x = 255;
    // short int a = x;
    // printf("%d", a);
    char *x = "abc";
    char *y = "defgh";
    unsigned int c = 0;
    if((strlen(x) - strlen(y)) > c)
        printf("OMG! It is: %u. And c is %u\n", (strlen(x) - strlen(y)), c);
    printf("%d", (((strlen(x) - strlen(y)) > c) ? strlen(x) : strlen(y)));
}