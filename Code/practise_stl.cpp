/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define sp ' '

void Pair();
void Vector();

int32_t main()
{
    // Pair();
    Vector();

    return 0;
}

/*	Iterator brief discussion

	in iterator there are four function ->
	1. begin() -> first element of the container
	2. end() -> after the last element of container
	3. rbegin() -> last element of the container
	4. rend() -> before the first element of the container

	if you want to travel whole container then used the for each loop
*/

void Vector()
{
    // intialised the vector
    vector<int> v; // intiallised the empty vector and you inialised by any other vector
    // push element in back of vector
    v.push_back(10);
    v.push_back(12);
    // for each loop
    for (int &i : v)
        cout << i << sp;
    cout << el;
    // pop of last element (pop the back element)
    v.pop_back();
    // print the last element
    cout << *(v.rbegin()) << el;

}

void Pair()
{
    // how to declear the pair of int and string
    pair<int, string> p;
    p = {2, "avec"};
    cout << p.first << sp << p.second << el;
    // you can create any type of variable pair like pair<set<int>,vector<int>> p ;
}
