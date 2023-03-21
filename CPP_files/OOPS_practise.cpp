/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

/*
* This Program is for pratice and write of objective oriention example small concept
    Some importance point -->
    1. Try to always attribute as a private member of class
    2. And accordingly create property function for all those attributes
    3. For any attribute which type of property function, it can be rw or r- or -w (read - r) and (write - w)


    Proper Structure of Class -->
    class
        private :
            Personal Attribute not Inherited Attribute
        protected :
            Inherited Attribute and Internal Function
        public :
            Methods -->
                Constructor -> 1. nonparameter 2. parameter 3. copy
                mutator
                Accessor
                Facilitator
                Enquiry
                Destructor
*/


#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
private:
    // Attributes of the Class
    double lenght = 1; // Default of this function is 1(given default vaule)
    double weight = 1;

protected:
    // This is used for inherited Attributed and Internal Function Impliment

public:
    //* some method of the Rectangle class

    // constructor
    Rectangle(double lenght = 1, double weight = 1)
    {
        this->lenght = lenght;
        this->weight = weight;
    }
    // Modifier Function
    void set_length(double a)
    {
        lenght = a;
        return;
    }
    void set_weight(double a)
    {
        weight = a;
        return;
    }
    // Accessor Function
    double get_length()
    {
        return lenght;
    }
    double get_weight()
    {
        return weight;
    }
    // Facilitator Function
    double area()
    {
        return weight * lenght;
    }

    double parameter()
    {
        return 2 * (weight + lenght);
    }

    double diagonal()
    {
        return sqrt(pow(lenght, 2) + pow(weight, 2));
    }
    // Enquiry Function
    bool check_sq();

    // Destruction
    ~Rectangle()
    {
        cout << "This Rectangle is Distroded" << endl;
    }
};

bool Rectangle::check_sq()
{
    if (lenght == weight)
        return true;
    else
        return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //* starting podouble of write the driveing code

    return 0;
}
