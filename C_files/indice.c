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
  long double vaule, part;
  double index, base;
  int i;
  printf("We know (1)^(any number)=1,so if you enter base=1 then if assumsed base=e.\n\tIf you want to exit enter Zero base.\n\n");
  while (1)
  {
    printf("Enter the base & index of (base)^index respectively : ");
    scanf("%lf%lf", &base, &index);

    if (base < 0)
    {
      printf("\nYou enter nagative number so again give input.\nAgain ");
      continue;
    }
    else if (base == 0)
    {
      printf("vaule of (0)^(%0.2lf) = 0\n", index);
      break;
    }
    else if (base != 1)
    {
      for (i = 0; base > 1.8; ++i)
        base /= 10;
      part = (logarithm(base - 1) + i * (2.302585092994));
      index = (index * part); // this line create problem for long double of index varible.
    }

    if (index < 150)
    {
      for (i = 1, part = index, vaule = 1; part > (1e-15); ++i, part *= (index / i))
        vaule += part;
      if (vaule < (1e4))
        printf("vaule =%0.9lf\n\nAgain ", (double)vaule);
      else
      {
        for (i = 0; vaule > 10; ++i)
          vaule /= 10;
        printf("vaule =%0.9lf*EXP(%d)\n\nAgain ", (double)vaule, i);
      }
    }
    else
    {
      int exp;
      long double fraction;
      part = (0.4342944819033);
      part *= index;
      exp = part;
      fraction = (part - exp);
      fraction *= (2.302585092994);
      for (i = 1, part = fraction, vaule = 1; part > (1e-16); ++i, part *= (fraction / i))
        vaule += part;
      printf("vaule =%0.9lf*EXP(%d)\n\nAgain ", (double)vaule, i);
    }
  }
  printf("\nComputation is finished.\n");
  return 0;
}