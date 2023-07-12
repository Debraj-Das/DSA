#include <iostream>

using namespace std ;

// volume of cube.
int volume(int a)
{
  return (a*a*a);
}
 // volume of retangal
 int volume(int l,int w,int h)
 {
  return (l*w*h);
 }
 //volume of cylinder
 double volume(int l,int r)
 {
  return (3.14*l*r*r);
 }

//        // volume of sphere     
//        double volume(int r)   // this decleration is not valid because of same name and argument.
//        {
//         return (3.14*r*r*r);
//        }

       // volume of sphere     
       double volume(double r)   // this decleration is not valid because of same name and argument.
       {
        return (3.14*r*r*r);
       }

int main()
 {
    cout<<"volume of cube of side 5 is "<<volume(5)<<endl ;
    cout<<"volume of retangle of lenght 10 ,width 8,hight 5 is "<<volume(10,8,5)<<endl ;
    cout <<"volume of cylinder of lenght 1 ,radious 2 is "<<volume(1,5)<<endl ;
    cout<< "volumn of sphere of radious 2 is "<<volume(2.0)<<endl ;
  
  return 0;
 }