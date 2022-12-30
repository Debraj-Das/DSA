#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print(char *format, ...)
{
   va_list args;
   va_start(args, format);
   for (int i = 0; format[i] != '\0'; ++i)
   {
      if (format[i] == '%')
      {
         ++i;
         switch (format[i])
         {
         case 'd':
         case 'i':
         case 'h':
         {
            printf("%d", va_arg(args, int));
            break;
         }
         case 'f':
         case 'e':
         case 'g':
         {
            printf("%lf", (float)va_arg(args, double));
            break;
         }
         case 'c':
         {
            printf("%c", va_arg(args, int));
            break;
         }
         case 'l':
         {
            ++i;
            switch (format[i])
            {
            case 'd':
            case 'i':
            {
               printf("%ld", (long int)va_arg(args, int));
               break;
            }
            case 'f':
            case 'e':
            case 'g':
            {
               printf("%lf", va_arg(args, double));
               break;
            }
            case 'l':
            {
               ++i;
               switch (format[i])
               {
               case 'd':
               case 'i':
               {
                  printf("%lld", (long long int)va_arg(args, int));
                  break;
               }
               case 'f':
               case 'e':
               case 'g':
               {
                  printf("%llf", (long double)va_arg(args, double));
                  break;
               }
               default:
               {
                  print("\n format error.\n");
                  return;
               }
               }
               break;
            }
            default:
            {
               print("\n format error.\n");
               return;
            }
            }
            break;
         }
         case 'L':
         {
            ++i;
            switch (format[i])
            {
            case 'd':
            case 'i':
            {
               printf("%Ld", (long long int)va_arg(args, int));
               break;
            }
            case 'f':
            case 'e':
            case 'g':
            {
               printf("%0.9lf",va_arg(args, double));
               break;
            }
            default:
            {
               print("\n format error.\n");
               return;
            }
            }
            break;
         }
         case 'p':
         case 'x':
         {
            printf("%p", va_arg(args, int));
            break;
         }
         case 'o':
         {
            printf("%o", va_arg(args, int));
            break;
         }
         case 's':
         {
            printf("%s", va_arg(args,char *));
            break;
         }
         default:
         {
            print("\n format error.\n");
            return;
         }
         }
      }
      else
      {
         printf("%c", format[i]);
      }
   }
   return;
}

int main()
{
   print("my name is Debraj Das.\tint = %d , float = %f , char = %c \n", 25, 5.5, 'p');
   print("Double = %lf , long double = %Lf , long long int = %lld\n",6.2,6.235,5682);
   print("%h\t%lg\t%p\t%o\"",45,2.5,5454,4563);
   print("\n %s Finished\n","one variadic function create completed.");
   return 0;
}