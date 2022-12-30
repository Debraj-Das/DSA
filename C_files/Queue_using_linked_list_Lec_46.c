/*
~ This code impliment for Queue using linked list
# there are some function impliment -->
   1. enqueue
   2. dequeue
   3. is_empty
   4. is_full
   5. init
   6. queuefree
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct linked
{
   int data ;
   struct linked *next ;
}list ;

typedef struct 
{
   list *font ;
   list *rare ;
}queue ;

queue *init()   //* this function for iniatialised the the new variable.
{
   queue *q = (queue *)malloc(sizeof(queue ));
   q->font = NULL ;
   q->rare = NULL ;
   return q ;
}

void enqueue(queue *q , int n)
{
   list *new ;
   new = (list *)malloc(sizeof(list ));

   if(new == NULL)                     //$ is_full function small code part.
   {
      printf("Queue is full\nSo %d is not enter the queue\n",n);
      return ;
   }
   else
   {
      new->data = n ;
      new->next = NULL ;
   }

   if(q->font)                          //$ is_empty function small code part.
   {
      q->rare->next = new ;
      q->rare = q->rare->next ;
   }
   else 
      q->font = q->rare = new ;

   return ;
}

int dequeue(queue *q)
{
      int val = -1 ; //$ (-1) value representence of empty value of of queue.
      if(q->font)
      {
         list *p ;
         p = q->font ;
         val = p->data ;
         q->font = q->font->next ;
         free(p);
      }
      return val ;
}

void queuefree(queue *q)   //* this function free the whole queue.
{
   list *p ;
   while(q->font)
   {
      p = q->font ;
      q->font = q->font->next ;
      free(p);
   }
   free(q);
   return ;
}

int main()
{
   queue *q = init();
   enqueue(q,23);
   enqueue(q,315);
   enqueue(q,124);
   printf("First element in queue is %d\n",dequeue(q));
   printf("second element in queue is %d\n",dequeue(q));
   queuefree(q);
   
   return 0;
}
