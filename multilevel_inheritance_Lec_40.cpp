#include <iostream>

using namespace std;

class Student
{
  int roll_no;

public:
  void set_roll_no(int a)
  {
    roll_no = a;
    return;
  }
  int get_roll_no()
  {
    return roll_no;
  }
};

class Exam : public Student
{
protected:
  float maths;
  float physics;

public:
  void set_roll_no_math_physic(int a, float b, float c)
  {
    set_roll_no(a);
    maths = b;
    physics = c;
    return;
  }
};

class Result : public Exam
{
public:
  void display()
  {
    cout << "\nRoll no is " << get_roll_no() << endl
         << "Maths mark is " << maths << "and Physic mark is " << physics << endl
         << "And overall percentile " << (maths + physics) / 2.0 << " %\n";
    return;
  }
};

int main()
{
  int roll ;
  float math , phy ;
  cout<<"Enter the roll no of student ";
  cin >> roll ;
  cout<<" Enter math and physic marks respectively ";
  cin >> math >>phy ;
  Result obj;
  obj.set_roll_no_math_physic(roll, math, phy);
  obj.display();
  return 0;
}