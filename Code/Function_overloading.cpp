#include <iostream>

using namespace std;

#define el '\n'

// Gobal lambda function with calling gobally
auto init = []()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    return 0;
}();

// lambda function definition
auto hello = []()
{
    cout << "Hello world" << el;
};

void fun(double a, double b = 10.23)
{
    cout << "First" << el;
    return;
}

void fun(double a, int b = 10)
{
    cout << "Second" << el;
    return;
}

void fun1(double a)
{
    cout << "Third" << el;
    return;
}

void fun1(float a)
{
    cout << "Fourth" << el;
    return;
}

class two_d
{
    int a;
    int b;

public:
    two_d(int a = 0, int b = 0)
    {
        this->a = a;
        this->b = b;
    }

    friend istream &operator>>(istream &in, two_d &c)
    {
        in >> c.a >> c.b;
        return in;
    }

    friend ostream &operator<<(ostream &out, const two_d &c)
    {
        out << c.a << ' ' << c.b << ' ';
        return out;
    }

    two_d operator+(two_d &obj)
    {
        two_d temp(0, 0);
        temp.a = this->a + obj.a;
        temp.b = this->b + obj.b;
        return temp;
    }
};

int main()
{
    // fun(10.23,20.23);
    // fun(10,20);
    //  fun1(10); // It give error because it is ambiguous at calling time
    // fun1(10.23); // it called the double data type function (because it is more prior than float data type)
    // fun1(10.23f); // it called the float data type function(beacuse it is specified by f)

    two_d obj1(10, 20);
    two_d obj2;
    cin >> obj2;
    cout << (obj1 + obj2) << el;
    // calling the lambda function;
    hello();

    return 0;
}
