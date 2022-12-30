/*Name-Debraj Das
Roll no-21CH30010*/

#include <stdio.h>
#if defined(_WIN32) || defined(__MSDOS__)
   #define club    "\x05"
   #define diamond "\x04"
   #define heart   "\x03"
   #define spade   "\x06"
#else
   #define club    "\xe2\x99\xa3"
   #define diamond "\xe2\x99\xa6"
   #define heart   "\xe2\x99\xa5"
   #define spade   "\xe2\x99\xa0"
#endif
  typedef struct {
  char num;
  char suit;
  }card;

int main()
{   card s[48],t;
int i,j;
printf("Enter the sequence of cards:/n");
     scanf("%[^\n]s", s);
     for(i=0;s[i].num!='/0';i++) {
        for(j=i;s[j].num!='/0';j++){
            if(s[i].num>s[j].suit)  {
                t=s[i];
                s[i]=s[j];
                s[j]=s[j];
            }
            else if(s[i].suit==s[j].suit) {
                if(s[i].num>s[j].num)  {
                t=s[i];
                s[i]=s[j];
                s[j]=s[j];
            }
        }

     }
    printf("After ordering:\n");
    for(i=0;s[i].num!='/0';i++) {
    switch(s[i].suit){
    case 'c':
    }
    }
    return 0;
}
