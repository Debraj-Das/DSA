#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
     string n_temp;
     getline(cin, n_temp); // it take input a line of string
     // cout<<n_temp<<endl;
     int n = stoi(ltrim(rtrim(n_temp)));  // this function converted string into number
     // cout<<n<<endl;
     // Write the for number chance to word.
     switch (n)
     {
     case 1:
          cout << "one" << endl;
          break;
     case 2:
          cout << "two" << endl;
          break;
     case 3:
          cout << "three" << endl;
          break;
     case 4:
          cout << "four" << endl;
          break;
     case 5:
          cout << "five" << endl;
          break;
     case 6:
          cout << "six" << endl;
          break;
     case 7:
          cout << "seven" << endl;
          break;
     case 8:
          cout << "eight" << endl;
          break;
     case 9:
          cout << "nine" << endl;
          break;
     default:
          cout << "Greater than 9" << endl;
     }

     return 0;
}

string ltrim(const string &str)
{
     string s(str);

     s.erase(
          s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

     return s;
}

string rtrim(const string &str)
{
     string s(str);

     s.erase(
          find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
          s.end());

     return s;
}
