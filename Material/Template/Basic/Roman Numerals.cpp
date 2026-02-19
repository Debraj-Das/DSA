// Roman Numerals

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> is;
const char el = '\n';

// Arabic to Roman
string AtoR(int A) {
   vector<pair<int, string>> convert({{1000, "M"},
                                      {900, "CM"},
                                      {500, "D"},
                                      {400, "CD"},
                                      {100, "C"},
                                      {90, "XC"},
                                      {50, "L"},
                                      {40, "XL"},
                                      {10, "X"},
                                      {9, "IX"},
                                      {5, "V"},
                                      {4, "IV"},
                                      {1, "I"}});

   string ans;
   for (auto &p : convert)
      while (A >= p.first) {
         ans += p.second;
         A -= p.first;
      }
   return ans;
}

int value(char letter) {
   switch (letter) {
      case 'I':
         return 1;
      case 'V':
         return 5;
      case 'X':
         return 10;
      case 'L':
         return 50;
      case 'C':
         return 100;
      case 'D':
         return 500;
      case 'M':
         return 1000;
   }
   return 0;
}

// Roman to Arabic
int RtoA(string R) {
   int ans = 0;
   for (int i = 0; R[i]; ++i) {
      if (R[i + 1] && (value(R[i]) < value(R[i + 1]))) {
         ans += value(R[i + 1]) - value(R[i]);
         ++i;
      } else
         ans += value(R[i]);
   }
   return ans;
}

int main() {
   string S;
   while (getline(cin, S)) {
      if (isdigit(S[0]))
         cout << AtoR(stoi(S)) << el;  // Arabic to Roman Numerals
      else
         cout << RtoA(S) << el;  // Roman to Arabic Numerals
   }
   return 0;
}