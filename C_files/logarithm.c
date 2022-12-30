#include <stdio.h>
#include <stdlib.h>

long double logarithm(long double number)
{
  long double vaule, part;
  int i;
  for (i = 1, part = 1, vaule = 0; part > (1e-16) || part < (-1e-16); ++i)
  {
    part *= (number);
    if (i % 2 == 1)
      vaule += (part / i);
    else
      vaule -= (part / i);
  }
  return vaule;
}

int main()
{
  long double log;
  double mod, base;
  int index;
  printf("In this logarithm calculation, base 1 mean e.\n And If you to exit from this computaion enter base =0;\n\n");
  while (1)
  {
    printf("Enter the vaule of M and base of log(M) respectively (M,base) : ");
    scanf("%lf%lf", &mod, &base);
    if (base == 0)
      break;
    if (mod <= 0 || base < 0)
    {
      printf("your input is invalid for find logarithm vaule.\nAgain ");
    }
    else
    {
      for (index = 0; mod > 1.8; ++index)
        mod /= 10;
      log = (logarithm(mod - 1) + index * (2.302585092994));

      for (index = 0; base > 1.8; ++index)
        base /= 10;
      if (base != 1)
        log /= (logarithm(base - 1) + index * (2.302585092994));

      printf("vaule of log(M,base) = %0.12lf.\n\n", (double)log);
      printf("Computation again start.\nAgain ");
    }
  }
  return 0;
}