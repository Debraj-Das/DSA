/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

/*
    This Code used for the Basic practise and ideas for the C++ language

    Predure oriented programming parts
*    1. C++ Basic -> Builden data type , input/output , operation
*    2. Statement -> a. Operator b. Control flow c. Loop d. Jump e. Function
calling and data declearation
*    3. Function and Library(basic library)
*    4. Structure and Class , enum and dynamic memory allocation

    Objective oriented programming parts
*    5. OOPs ideas and philosopy and basic analogy
*    6. Inheritance and Friend , static , Inner class
*    7. Overloading and polymorphism
*    8. Virtual function and friend function and constructor and destructor and
    some Advence part
*    9. Constants , preprocessor , Directives
*   10. Template
*   11. STL Librarys and other type of library

*/

#include <bits/stdc++.h> // This is the header file of the C++ language which is also of specific collection of standard library
using namespace std; // This is the namespace of the C++ language which is also
                     // of collection of standard library
void solve();
class Rectangle; // This is the forward declaration of the class

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); // This is the input file which is used
                                      // for the input of the program
#endif

    clock_t z = clock();

    int t = 1;
    //	cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

/*
    some important point of the C++ language as POPs, which not present in C
   language -->
    1. Some advence builtin data type like bool , string etc.
    2. Some advence library like <string> , <cmath> , <algorithm> etc.
    3. operator overloading and function overloading
    4. Reference variable
    5. Default argument
    6. Inline function

*/

bool compare(int a, int b) // This used of the
{
    return a > b;
}
// its lambda function is [](int a , int b) {return a<b;}

void solve() {
    // int n;
    // cin >> n;
    // vector<vector<int>>v(n,vector<int>(n,0));   // decleartion and filled the
    // 2D vector by Zeroes cout << (typeid(string).name() == typeid(int).name())
    // << endl; // This is for check the data type is same or not

    // cout<<sizeof(int64_t)<<endl; // This is use for the long long int

    vector<int> arr = {4, 6, 2, 8, 10};
    sort(arr.begin(), arr.end(), [](int a, int b) { return a < b; });
    for (auto x : arr)
        cout << x << ' ';
    cout << endl;
    return;
}

/*
* This Program is for pratice and write of objective oriention example small
concept Some importance point -->
    1. Try to always attribute as a private member of class
    2. And accordingly create property function for all those attributes
    3. For any attribute which type of property function, it can be rw or r- or
-w (read - r) and (write - w)


    Proper Structure of Class -->
    class
        private :
            Personal Attribute not Inherited Attribute  (which is not inherited
from the parent class attribute)

        protected :
            1. Inherited Attribute (which is inherited from the parent class
attribute)
            2. Internal Function (which is used for the internal work of the
class)

        public :
            Methods -->
                Constructor -> 1. nonparameter 2. parameter 3. copy
                mutator (assign value and change value of the attribute)
                Accessor (get value of the attribute)
                Facilitator (do some work with the attribute and return value )
                Enquiry (check some condition and return value)
                Destructor (destroy the object of the class)
*/

class Rectangle {
  private:
    // Attributes of the Class
    double lenght = 1; // Default of this function is 1(given default vaule)
    double weight = 1;

  protected:
    // This is used for inherited Attributed and Internal Function Impliment

  public:
    //* some method of the Rectangle class

    // constructor
    Rectangle(double lenght = 1, double weight = 1) {
        this->lenght = lenght;
        this->weight = weight;
    }

    // Modifier Function
    void set_length(double a) {
        lenght = a;
        return;
    }
    void set_weight(double a) {
        weight = a;
        return;
    }

    // Accessor Function
    double get_length() { return lenght; }
    double get_weight() { return weight; }
    // Facilitator Function
    double area() { return weight * lenght; }

    double parameter() { return 2 * (weight + lenght); }

    double diagonal() { return sqrt(pow(lenght, 2) + pow(weight, 2)); }
    // Enquiry Function
    bool check_sq();

    // Destruction
    ~Rectangle() { cout << "This Rectangle is Distroded" << endl; }
};

// if a function is defined inside of the class then it is called inline
// function if a function is defined outside of the class then it is called
// online function

bool Rectangle::check_sq() // External defintion of the function which is not a
                           // online function
{
    if (lenght == weight)
        return true;
    else
        return false;
}

/*
*componeent of OOPs
    1. class and object
    2. Encapsulation and Data Abstraction
    3. Inheritance
    4. Polymorphism
    5. Dynamic Binding
    6. Message Passing

* Benefits of object oriented programming
    1. Better code reusability
    2. principle of data hiding helps the programmer to build secure programs
    3. Multiple objects can co-exist without any interference
    4. Software complexity can be easily managed

* Advantage of OOPs over Procedure-oriented programming language
    1. Modularity for easier troubleshooting
    2. Reuse of code through inheritance
    3. Flexibility through polymorphism
    4. Effective problem solving

*/
