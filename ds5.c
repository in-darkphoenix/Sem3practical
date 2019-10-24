#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{

    int id;
    char name[20];
    char director[20];
    char add[20];
    char contact[11];
    struct node*next;
}
  *start,*rear,*k;
  typedef struct node node ;

  node *create();
  void display();
  void addbeg(node *);
  node *del(node *);
  int main()
  {
      int m,o;
      node *p;
      start=NULL;
      printf("\n\tNAME-Ankit Kumar\n");
      printf("\n\tMaharaja Agrasen Institute of Technology\n");
      printf("\n\t");
      printf("To perform deletion at end ");
      printf("\n\n\t");
      printf("\n\tpress enter ");
      getch();
      printf("\n\t");
      printf("\n\tEnter initial no of college ");
      scanf("%d",&m);
      while(m--){
        p=create();
        addbeg(p);

      }
        while(o!=0)
        {
            printf("\n\n\tpress enter");
            getch();
            printf("\n\n\tpress 1 to insert new record at front: ");
            printf("\n\n\t press 2 to delete record from end ");
            printf("\n\n\tpress3 to display all records ");
            scanf("%d",&o);
            switch(o)
            {

                case 1 : p=create();
                         addbeg(p);
                         break;
                case 2 : start=del(start);
                         break;
                case 3 : display();
                         break;
            }
        }
  }
              node *create()
              {

                  node *k;
                  k=(node *)malloc(sizeof(node));
                  printf("\n\tenter the id ");
                  scanf("%d",&k->id);
                   printf("\n\tenter the name of college  ");
                  scanf("%s",k->name);
                  printf("\n\tenter name of director ");
                  scanf("%s",k->director);
                  printf("\n\tenter the address of college ");
                  scanf("%s",k->add);
                  printf("\n\tenter contact no. : ");
                  scanf("%s",k->contact);
                  k->next=NULL;
                  return k;
              }
               void display()
               {

                   node *k;
                   int count =0;
                   k=start;
                   printf("\n\n\tS.No.\tid\tdirector\taddress\t\tcontact\n");
                   do
                   {

                       count++;
                       printf("\n\t%d\t%d\t%s\t%s\t%s\t\t%s\n",count,k->id,k->name,k->director,k->add,k->contact);
                       k=k->next;
                   }
                     while(k!=start);

               }
                  void addbeg(node *k)
                  {

                      node *n=start;
                      if(start==NULL)
                      {

                          start=k;
                          start->next=start;
                      }
                         else
                         {

                             while(n->next!=start)
                                n=n->next;
                                k->next=start;
                                start=k;
                                n->next=start;

                         }
                      }
                      node *del(node *start)
                      {
                          node *p,*q;
                          p=start;
                          if(p==NULL)
                          {
                              printf("\n\tList is empty\n");
                          }
                          else
                          {
                              while(p->next!=rear)
                              {
                                  q=p;
                                  p=p->next;
                              }
                              printf("\n\tRecord Deleted");
                              q->next=p->next;
                          }
                          rear=q;
                          return start;
                      }
