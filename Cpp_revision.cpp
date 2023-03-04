
/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    //	cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

void solve()
{

    // size_t is actually unsigned int
    // cout << sizeof(size_t) << endl;
    // for (size_t i{}; i < 10; i++) // {} it is used for brashed assigned operator
    // {
    //     cout << "I Love C++" << endl;
    // }

    // int arr[10]{2, 5, 3, 42, 23};
    // // size(arr); it is not working in C++20
    // int* point = arr , name = 23 ; // pointer and their name is integer type variable
    // cout<<"size of the pointer "<<sizeof(point)<<endl;
    // // double *p = arr ; it give error because double pointer(double *) did not store in int pointer(int *)
    // cout<<point<<' '<<name<<endl;
    // for (auto x : arr)  // range type for loop
    //     cout << x << ' ';
    // cout << endl;

    // int var(34);
    // int *point{&var};
    // cout << "value of variable " << *point << "\naddress of variable " << point << endl;

    // char *message {"hello world"}; // It create a const type char array
    // cout<<message <<endl;
    // message[0] = 'd' ;
    // cout<<message<<endl;

    // int *point = new int(34);
    // cout << point << endl;
    // cout << *point << endl;
    // delete point;
    // cout << *point << endl;  //* Dangline pointer
    // cout << point << endl<<endl;

    // int *point = new (nothrow) int(83); //* nothrow mechenism for fail the dynamic mechnism. and return nullptr at fail time
    // cout << *point << endl;
    // delete point;

    //* Exception Mechanic for control the error in runtime error
    // for(int i = 0 ; i<1000 ; i++)
    // try
    // {
    //     point = new int[100000000];
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    //     break;
    // }

    // cout << point << endl;
    // delete[] point;

    // int *point = nullptr;
    // delete point; //* delete the null pointer is no problem
    // cout << "HElo world" << endl;

    // int *point = new int(90);

    // delete point;
    // point = nullptr;            // Remove the Dangline variable risks
    // cout << point << endl;

    //* memory leak --> reallocated before the previous pointer delete or poiner scope finish before delete the pointer


    // int *point = new int[10]{1, 3, 5, 5, 2, 2, 5, 2, 2};
    // for (auto x : point)     //* in dynamic array range base for loop no work it give error
    //     cout << x << endl;

    

    return;
}

//$ This is the Theory part For Revision Propose
/*

~ C++ languege made by 1979 by Bjange Stroustrope as a extention of C languege
 at intial it call as C with Class
 but after some year later it call C++(mean C with some addition)
 It has Same working style with OOPS style

Usefull of C++ -->
    i. High memory Control
    ii. High speed and profomation
    iii. POP and OOPS both type of style presents
    iv. High stander library supports

POP --> Procure oriented Programming
OOP --> Object oriented Programming


* In C++ is a POP AND OOPS ASSOCIATED Languege
    POP like C languege except -->
                    i. new and delete
                    ii. refferce variable and gobal keyword
                    iii. function and operator overloading
                    iv. String associated program and cin and cout
                    v. range for loop
                    vi. inline function and default arguments
                    vii. Less memory control compare to C languege like register variable

    OOP associate some importance Concepts -->
                    i. Class and objects , constructor and distructor
                    ii. Data Abstraction and Encapsulation
                    iii. Inheritance and virtual function
                    iv. Polymorphism
                    v. Dynamic Binding and Message passing


* I feels some missing concept in C++ are
            i. ellipse function
            ii. try and Catch
            iii. Proper template and stander library use
            iv. practise OOP idea in C++ languege(it is intial state of System design)
            v. Some pointer associated idea and termology
            vi. structure in C++ languege advence part

*/

/*
some new concept in C++ which I did not know untill now -->

* memory of *.exe is reload at time at program memory
* Dangling pointer
    a pointer which has no valid address store call Danling pointer
    1. unintialsed pointer
    2. Delete pointer
    3. Multipal pointer pointing same memory
    solution of this type of dangling pointer
    1. intialised the pointer at decliear the pointer
    2. Reset the pointer after the delete the pointer
    3. for the multiple pointer always clear about the owner of the pointer



    *Exception mechanism in C++
        try and catch keyword
    *std::nothrow setting

*/