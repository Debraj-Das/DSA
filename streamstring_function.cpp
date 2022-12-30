#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
    // Complete this function with idea of steamstring
    str+='~';
    stringstream ss(str);
    vector<int> integers;
    int n;
    for (char ch = ','; ch != '~'; integers.push_back(n))
    {
        ss >> n >> ch ;
    }
    return integers;
}

int main()
{
    string str;
    // cin >> str;
    getline(cin,str);
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}