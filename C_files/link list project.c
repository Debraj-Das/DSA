//name -Debraj Das
//roll no -21CH30010

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct link{
  int a;
  struct link *next;
}link;

link * store(link *,link *v );
link * del(link *,int ,int );

link * store(link *head,link *v){
  link *p,*q;
  if(head ==NULL) return v;
   if(v->a<head->a) {
    v->next=head;
    return v;
   }
  p=q=head;
  while(p!=NULL){
    if(v->a<p->a){
     q->next=v;
     v->next=p;
     return head;
    }
    q=p;
    p=p->next;
  }
  q->next=v;
  return head;
}

link *del(link *head,int min,int max) {
      link *p,*q;
      if(head == NULL) return head;
      p=q=head;
      while(p!=NULL){
      if(p->a>min) break ;
      q=p;
      p=p->next;
      }
      while(p!=NULL){
        if(p->a>max) break ;
      p=p->next;
      }
      q->next=p;
      if(head->a>min) return p;
      else return head;
}





int main()
{
   link *head=NULL,*p;
   int i,min,max;
   while(1){
   printf("\n1.Insert\n2.Delete number in a range\n3.Search\n4.Display\n5.Exit.\nEnter the number :");
   scanf("%d",&i);
   switch(i){
   case 1:{
   printf("If you want to exit from the insert than enter Zero.\nEnter the numbers : ");
   while(1){
        p=(link *)malloc(sizeof(link));
        scanf("%d",&(p->a));
        p->next =NULL;
   if(p->a==0) {  free(p);   break ;}
   head = store(head,p);
  printf("Enter the next number : ");
   }
   }
   break ;
   case 2:{
   printf("Enter the lowercase : ");
   scanf("%d",&min);
   printf("Enter the uppercase : ");
   scanf("%d",&max);
   head = del(head,min,max);
   }
   break ;
   case 3:{
   printf("Enter the searching number : ");
   scanf("%d",&max);
   p=head;
   while(p!=NULL){
   if(max==p->a) {printf("Searching number is present.\n");  break ;}
    p=p->next;
   }
   if(p==NULL) printf("Searching number is not present.\n");
   }
   break ;
   case 4:{
       p =head;
       printf("Display the store : ");
       if(p==NULL) printf("List is empty.");
   while(p!=NULL){
    printf("%2d ",p->a);
    p=p->next;
   }
   }
   break ;
   case 5:{
   printf("\nThe process is finish.\n");
   return 0;
   }
   default : {
   printf("Enter wrong number.So enter right option.");
   } }
    }  }
