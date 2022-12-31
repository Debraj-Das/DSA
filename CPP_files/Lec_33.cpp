#include <iostream>
#include <cmath>

using namespace std;

class Point
{
  int x, y;

public:
  void display()
  {
    cout << "the point is (" << x << "," << y << ")\n";
    return;
  }
  Point(double a = 0, double b = 0) 
  {                        
    x = a;
    y = b;
  }
  // Point() { }  // if you not give all agrument by default then creat a blank constructor.
          // for  fexible of code. it gives fexible on not runed that constructor with arguments.      

  friend void dis_btw_points(Point, Point);
};

void dis_btw_points(Point p1, Point p2)
{
  double distance = 0;
  distance = pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2);
  cout << "distance btw those two point is " << sqrt(distance) << endl;
  return;
}

int main()
{
  int x = 1;
  Point point1 = Point(x, 1); // used called constructor by calling.use x only testing the constructed invoved.
  Point point2(2, 5);         // used directedly.
  Point point3;               // if you not give parameter it use it default argument & run constucted.
  point1.display();
  point2.display();
  point3.display();
  cout << endl;
  // point1 = Point(5, 1); 
   //#  This above code of line working properly.so constructed can also be use as set data function any time.

  dis_btw_points(point1, point2);
  dis_btw_points(point3, point2);

  return 0;
}