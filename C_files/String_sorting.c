#include <stdio.h>
#include <stdlib.h>

int lexicographic_sort(const char* a, const char* b) {
    int i;
     for(i=0;a[i]&&b[i];++i)
     {
         if(a[i]<b[i]) return 0;
         if(a[i]>b[i]) return 1;
     }
     if(b[i]) return 0;
     else return 1;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  int i;
     for(i=0;a[i]&&b[i];++i)
     {
         if(a[i]>b[i]) return 0;
         if(a[i]<b[i]) return 1;
     }
     if(a[i]) return 0;
     else return 1;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int i,n=0;
    for(i=0;a[i];++i,++n)
    {
        for(int j=0;j<i;++j)
        {
            if(a[i]==a[j])
            {
                --n;
                break;
            }
        }
    }
    for(i=0;b[i];++i,--n)
    {
        for(int j=0;j<i;++j)
        {
            if(b[i]==b[j])
            {
                ++n;
                break;
            }
        }
    }
    if(n==0) 
    {
        for(i=0;a[i]&&b[i];++i)
     {
         if(a[i]<b[i]) return 0;
         if(a[i]>b[i]) return 1;
     }
     if(b[i]) return 0;
     else return 1;
    }
    else if(n<0) return 0;
    else return 1;
}

int sort_by_length(const char* a, const char* b) {
  int i,n=0;
  for(i=0;a[i];++i,++n);
  for(i=0;b[i];++i,--n);
  if(n==0)
  {
      for(i=0;a[i]&&b[i];++i)
     {
         if(a[i]<b[i]) return 0;
         if(a[i]>b[i]) return 1;
     }
     if(b[i]) return 0;
     else return 1;
  }
  else if(n<0) return 0;
  else return 1;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char **tum,*chance;
    for(int i=0,j;i<len;++i)
    {
        tum=&arr[i];
        for(j=i+1;j<len;++j)
        {
            if(cmp_func(*tum,arr[j])) tum=&arr[j];
        }
        chance=arr[i];
        arr[i]=*tum;
        *tum=chance;
    }

}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0,j; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        for(j=0;arr[i][j];++j);
        *(arr + i) = realloc(*(arr + i), j);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}