#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sorting(int *arr,int n)
{
     int *tem , i , j ;
     for(i = 1;i<n;++i)
     {
      for(tem = &arr[i],j=(i+1);j<n;++j)
      {
        if((*tem)>arr[j]) tem = &arr[j];
      }
        j = *tem ;
        *tem = arr[i];
        arr[i] = j ;
     }
     for(j=1;j<n;++j)
      {
        if(arr[0] < arr[j]) 
        {
          i= arr[0];
          arr[0] = arr[j];
          arr[j]=i;
          return ;
        }
      }
}

int next_permutation(int n, char **s)
{
  static char **string ;
	static int step = 0 , no_step , *a;
  int i  ;
  if(step==0)
  {    
     a = (int *)malloc(n*sizeof(int ));
     for(i=0;i<n;++i) a[i]=i ;

      for(i=2,no_step=1;i<=n;++i)  no_step*=i;

      	string = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		string[i] = calloc(11, sizeof(char));
		strcpy(string[i],s[i]);
	}
  }
       ++step ;
  for(int tem , p ; step < no_step ;++step)
  {  
  if((step%2)==0)
  {
    for(i=0,p=(no_step/n);(step%p)!=0;p/=(n-i))  ++i ;
    tem = a[i];
     sorting(&a[i],n-i);
  }
  else
  {
     i = n-2;
     tem = a[i];
     a[i] = a[i+1];
     a[i+1] = tem ;
  }
  
    if(strcmp(string[tem],string[a[i]])!=0)  
     {  
        for(i=0,tem=1;i<(n);++i)
        {
          for(p=i+1;p<n;++p)
          {
            if(a[i]>a[p]&&strcmp(string[a[p]],string[a[i]])==0)  
          {
            tem = 0 ;
            goto end ;
          }
          }
        }
        end:
        if(tem!=0)
        {
         for(i=0;i<n;++i)
              strcpy(s[i],string[a[i]]);
         return 1 ;
        }
         
      }
      
  }
  return 0 ;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}