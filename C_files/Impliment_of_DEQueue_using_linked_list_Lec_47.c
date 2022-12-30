/*
~ This code impliment for DEQueue using linked list
# there are some function impliment -->
   1. init
   2. dequeuefree
   3. IsEmpty
   4. IsFull
   5. enqueueR
   6. enqueueF
   7. dequeueF
   8. dequeueR
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct linked
{
   int data;
   struct linked *next;
} list;

typedef struct
{
   list *font;
   list *rare;
} queue;

queue *init() //* this function for iniatialised the the new variable.
{
   queue *q = (queue *)malloc(sizeof(queue));
   q->font = NULL;
   q->rare = NULL;
   return q;
}

void enqueueR(queue *q, int n)
{
   list *new;
   new = (list *)malloc(sizeof(list));

   if (new == NULL) //$ is_full function small code part.
   {
      printf("Queue is full\nSo %d is not enter the queue\n", n);
      return;
   }
   else
   {
      new->data = n;
      new->next = NULL;
   }

   if (q->font) //$ is_empty function small code part.
   {
      q->rare->next = new;
      q->rare = q->rare->next;
   }
   else
      q->font = q->rare = new;

   return;
}

void enqueueF(queue *q, int n)
{
   list *new;
   new = (list *)malloc(sizeof(list));

   if (new == NULL) //$ is_full function small code part.
   {
      printf("Queue is full\nSo %d is not enter the queue\n", n);
      return;
   }
   else
      new->data = n;

   if (q->font) //$ is_empty function small code part.
   {
      new->next = q->font;
      q->font = new;
   }
   else
      q->font = q->rare = new;

   return;
}

int dequeueF(queue *q)
{
   int val = -1; //$ (-1) value representence of empty value of of queue.
   if (q->font)
   {
      list *p;
      p = q->font;
      val = p->data;
      q->font = q->font->next;
      free(p);
   }
   return val;
}

int dequeueR(queue *q)
{
   int val = -1; //$ (-1) value representence of empty value of of queue.
   if (q->font)
   {
      list *p, *new;
      for (new = q->font; new->next != q->rare; new = new->next)
         ; //$ find the previous element of rare.
      p = q->rare;

      new->next = NULL;
      q->rare = new;
      val = p->data;

      free(p);
   }
   return val;
}

void print(queue *q)
{
   list *new;
   printf("Elements in DEQueue is :: \n");
   for (new = q->font; new; new = new->next)
      printf("%d\n", new->data);
   return;
}

void dequeuefree(queue *q) //* this function free the whole queue.
{
   list *p;
   while (q->font)
   {
      p = q->font;
      q->font = q->font->next;
      free(p);
   }
   free(q);
   return;
}

int main()
{
   queue *q = init();
   enqueueR(q, 23);
   enqueueR(q, 315);
   enqueueR(q, 124);
   print(q);
   enqueueF(q, 74);
   printf("First element in queue is %d\n", dequeueF(q));
   printf("Last element in queue is %d\n", dequeueR(q));
   print(q);
   dequeuefree(q);

   return 0;
}
