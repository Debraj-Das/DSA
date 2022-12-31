#include <iostream>
#include <cmath>

using namespace std;

class Simple_calculator
{
public:
  double add(double a, double b)
  {
    return (a + b);
  }

  double substracted(double a, double b)
  {
    return (a - b);
  }

  double multiple(double a, double b)
  {
    return (a * b);
  }

  double divition(double a, double b)
  {
    return (a / b);
  }

  double power(double a, int b)
  {
    double vaule = 1;
    for (int i = 0; i < b; ++i)
    {
      vaule *= a;
    }
    return vaule;
  }

  int fl(double a)
  {
    return floor(a);
  }

  int celling(double a)
  {
    return ceil(a);
  }

  double fraction(double a)
  {
    return (a - floor(a));
  }
};

class Scientific_calculator
{
public:
  double exp(double a, double b)
  {
    return pow(a, b);
  }

  double ln(double a)
  {
    return log(a);
  }

  double tri_sin(double a)
  {
    a *= (3.141592654 / 180);
    return sin(a);
  }

  double tri_cos(double a)
  {
    a *= (3.141592654 / 180);
    return cos(a);
  }

  double tri_tan(double a)
  {
    a *= (3.141592654 / 180);
    return tan(a);
  }

  double inver_sin(double a)
  {
    a = asin(a);
    a *= (180 / 3.141592654);
    return a;
  }

  double inver_cos(double a)
  {
    a = acos(a);
    a *= (180 / 3.141592654);
    return a;
  }

  double inver_tan(double a)
  {
    a = atan(a);
    a *= (180 / 3.141592654);
    return a;
  }

  double hyperblic_sin(double a)
  {
    return sinh(a);
  }

  double hyperblic_cos(double a)
  {
    return cosh(a);
  }

  double hyperblic_tan(double a)
  {
    return tanh(a);
  }
};

class Combined_calculator : public Simple_calculator, public Scientific_calculator
{
public:
  double answer;
  ~Combined_calculator() {}
};

int main()
{
  double a, b;
  char option;
  Combined_calculator obj;
  cout << "option for access function (for exit enter x) " << endl
       << "\tadd + \t substuct - \t multipul * \t division /" << endl
       << "\tfloor f \t ceil c \t fraction 0 \t power p" << endl
       << "\t e^x e\t a^x a \t ln n \t log l" << endl
       << "\tsin 1\tcos 2 \ttan 3 value are in degree" << endl
       << "\t arcsin 4 \t arccos 5 \t arctan 6" << endl
       << "\thyperbolic sin 7 \t cos 8 \t tan 9\n" << endl;
  while (true)
  {
    cout << "Enter the option : ";
    cin >> option;
    switch (option)
    {
    case 'x':
    {
      cout << "process is finished" << endl;
      goto jump;
    }

    case '+':
    {
      cout << "Enter the numbers(a,b) :";
      cin >> a >> b;
      cout << "Sum of " << a << " and " << b << " = " << obj.add(a, b) << endl;
      break;
    }
    case '-':
    {
      cout << "Enter the numbers(a,b) :";
      cin >> a >> b;
      cout << "Substraction of " << a << " and " << b << " = " << obj.substracted(a, b) << endl;
      break;
    }
    case '*':
    {
      cout << "Enter the numbers(a,b) :";
      cin >> a >> b;
      cout << "multiple of " << a << " and " << b << " = " << obj.multiple(a, b) << endl;
      break;
    }
    case '/':
    {
      cout << "Enter the numbers(a,b) :";
      cin >> a >> b;
      if (b != 0)
        cout << "Division of " << a << " and " << b << " = " << obj.add(a, b) << endl;
      else
        cout << "Division not valid because denominarator Zero." << endl;
      break;
    }
    case 'f':
    {
      cout << "Enter the numbers for floor : ";
      cin >> a;
      cout << "floor of "<< a << " = " << obj.fl(a) << endl;
      break;
    }
    case 'c':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "ceil of " << a << " = " << obj.celling(a) << endl;
      break;
    }
    case '0':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "fraction of " << a << " = " << obj.fraction(a) << endl;
      break;
    }
    case 'p':
    {
      cout << "Enter the numbers(a,b(integer power)) : ";
      cin >> a >> b;
      cout << " vaule of " << a << " to the power " << b << " = " << obj.power(a, b) << endl;
      break;
    }
    case 'e':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "exp of " << a << " = " << obj.exp(2.718281828, a) << endl;
      break;
    }
    case 'a':
    {
      cout << "Enter the numbers(a,b) : ";
      cin >> a >> b;
      cout << " vaule of " << a << " to the power " << b << " = " << obj.exp(a, b) << endl;
      break;
    }
    case 'n':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "ln of " << a << " = " << obj.ln(a) << endl;
      break;
    }
    case 'l':
    {
      cout << "Enter the numbers(M,base) : ";
      cin >> a >> b;
      cout << "log(" << a << ") base " << b << " = " << (obj.ln(a) / obj.ln(b)) << endl;
      break;
    }
    case '1':
    {
      cout << "Enter the numbers( in degree) : ";
      cin >> a;
      cout << "sin of " << a << " = " << obj.tri_sin(a) << endl;
      break;
    }
    case '2':
    {
      cout << "Enter the numbers( in degree) : ";
      cin >> a;
      cout << "cos of " << a << " = " << obj.tri_cos(a) << endl;
      break;
    }
    case '3':
    {
      cout << "Enter the numbers( in degree) : ";
      cin >> a;
      cout << "tan of " << a << " = " << obj.tri_tan(a) << endl;
      break;
    }
    case '4':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "arcsin of " << a << " = " << obj.inver_sin(a) << " in degree." << endl;
      break;
    }
    case '5':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "arccos of " << a << " = " << obj.inver_cos(a) << " in degree." << endl;
      break;
    }
    case '6':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "arctan of " << a << " = " << obj.inver_tan(a) << " in degree.";
      break;
    }
    case '7':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "sinh of " << a << " = " << obj.hyperblic_sin(a) << endl;
      break;
    }
    case '8':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "cosh of " << a << " = " << obj.hyperblic_cos(a) << endl;
      break;
    }
    case '9':
    {
      cout << "Enter the numbers : ";
      cin >> a;
      cout << "tanh of " << a << " = " << obj.hyperblic_tan(a) << endl;
      break;
    }
    default :
    {
      cout<<"You enter wrong option.s"<<endl ;
      break;
    }
    }
    cout<<"\nAgain enter next computation.\n"<<endl ;
  }
jump:
  return 0;
}