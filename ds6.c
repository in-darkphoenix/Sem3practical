#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stack
{
    int info;
    struct stack*next;
}

*top,*rear,*k;

typedef struct stack stack;

stack *create(int);
void push(stack *);
void display(stack *);
void peep(int);
void pop();

void main()
{
    int m=8,a,choice1;
    stack *p;
    top=NULL;
    printf("\n\tName - Ankit Kumar\n\t");
    printf("\n\tMaharaja Agrasen Institute of Technology\n\t");
    printf("\n\t");
    printf("\n\tPlease press ENTER to continue\n\t");

    getch();

    printf("\n\tEnter 8 numbers\n");

    while(m--)
    {
        printf("\t");
        scanf("%d",&a);
        p=create(a);
        push(p);
    }
    printf("\n\t");
    display(top);
    printf("\n\t");
    do
    {
        printf("\n\tEnter 1 to PUSH\n\t");
         printf("\n\tEnter 2 to POP\n\t");
          printf("\n\tEnter 3 to SEARCH\n\t");
           printf("\n\tEnter your choice : ");
           scanf("%d",&m);
           switch(m)
           {
               case 1:
                    printf("\n\tEnter a value - \n\t");
                    scanf("%d",&m);
                    printf("\n");
                    p=create(m);
                    push(p);
                    break;

               case 2:
                printf("\n");
                pop();
                break;

               case 3:
                    printf("\n\tEnter the value to search - ");
                    scanf("%d",&a);
                    printf("\n\n");
                    peep(a);
                    break;

               default: printf("\n\tWrong choice\n");
           }
           printf("\t");
           display(top);
           printf("\n\t");
           printf("\n\tEnter 1 to continue : ");
           scanf("%d",&choice1);
    }
    while(choice1==1);
    getch();
}

stack *create(int m)
{
    stack *k;
    k=((stack*)malloc(sizeof(stack)));
    k->info=m;
    k->next=NULL;
    return k;
}

void push(stack *n)
{
    if(top==NULL)
    {
        top=n;
    }
    else
    {
        n->next=top;
        top=n;
    }
}

display(stack *k)
{
    while(k!=NULL)
    {
        printf("%d->",k->info);
        k=k->next;
    }
}
void peep(int val)
{
    stack *p=top;
    stack *k;
    int found=1;
    while(p!=NULL)
    {
        if(p->info==val)
        {
            printf("\tValue found\n\n");
            found=0;
            break;
        }
        p=p->next;
    }
    if(found)
        printf("\n\tValue not found");
}
void pop()
{
    stack *k=top;
    top=top->next;
    free(k);
}
