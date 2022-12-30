#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	int num ,i ;
  char *strain ;
  for(num =1,i=1;i<=n;++i)
    num*=i;
    static int j =0 ;    
    for(i = (j%(n-1)) ;j<(num-1);++j)
    {
      if(strcmp(s[i],s[i+1])!=0)  
     {
         strain = s[i] ;
         s[i] = s[i+1] ;
         s[i+1] = strain ;
         ++j ;
         return 1 ;
      }
    }
    return 0;
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