#include <iostream>

using namespace std;

class Student
{
private:
  int roll_number;

public:
  void set_roll_number(int a)
  {
    roll_number = a;
    return;
  }
  void print_roll_number()
  {
    cout << "Your roll number is " << roll_number << endl;
    return;
  }
};

class Test : virtual public Student   //!  virtual public and public virtual work same.
{
protected:
  double math_marks;
  double phy_marks;

public:
  void set_marks(double a, double b)
  {
    math_marks = a;
    phy_marks = b;
    return;
  }
  void print_marks()
  {
    cout << "Marks of mathematic is " << math_marks << endl
         << "Marks of physic is " << phy_marks << endl;
    return;
  }
};

class Sport : public virtual Student   //* virtual keywork syntex both.
{
protected:
  double score;

public:
  void set_score(double a)
  {
    score = a;
    return;
  }
  void print_score()
  {
    cout << "Score of sports is " << score << endl;
    return;
  }
};

class Result : public Test, public Sport
{
protected:
  double total;

public:
  void display()
  {
    total = math_marks + phy_marks + score;
    print_roll_number();
    print_marks();
    print_score();
    cout <<"Total result is "<<total<<endl;
    return;
  }
  ~Result()
  {
    cout<<"\nobj is distored\n"<<endl ;
  }
};

int main()
{
  Result obj;
  obj.set_roll_number(12);
  obj.set_marks(98, 96.5);    //@ if you want it do as input output by take input from user.
  obj.set_score(9.5);
  obj.display();

  return 0;
}