#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double *sort_by_area(triangle* tr, int n) {
	double *area , p  ;
  area = (double *)malloc(n*sizeof(double ));
  int i ;
  for(i=0 ;i<n;++i)
  {
      p = (tr[i].a+tr[i].b+tr[i].c)/2.0 ;
      area[i] = sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c)) ;
  }
  triangle tem ;
  for(int j = 0 ;j<(n-1);++j)
  {
    for(i=0,p=0;i<(n-j-1);++i)
    {
      if(area[i]>area[i+1]){
          p = area[i] ;
          area[i] = area[i+1];
          area[i+1] = p ;
          tem = tr[i];
          tr[i]= tr[i+1];
          tr[i+1] = tem ;
          p = (-1);
      }
    }
    if(p==0) break;
  }
  return area ;
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	double *area = sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("\n%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
   printf("Associated area = %lf\n",area[i]);
	}
	return 0;
}