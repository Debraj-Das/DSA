#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

string solve(int numerator, int denominator)
{
   bool isNeg = false;
   if (numerator < 0)
      isNeg ^= 1;
   if (denominator < 0)
      isNeg ^= 1;

   if (!numerator)
      isNeg = false;

   long long num = abs(numerator);
   long long denom = abs(denominator);

   string ans = "";
   if (isNeg)
      ans = "-";

   long long intPart = num / denom;

   ans += to_string(intPart);

   num %= denom;

   if (!num)
      return ans;

   unordered_map<long long, int> decPos;

   ans += ".";

   int recPos = -1;

   while (true)
   {
      if (!num)
         break;
      long long temp = num * 10;
      if (decPos.find(num) != decPos.end())
      {
         recPos = decPos[num];
         break;
      }
      decPos[num] = (int)ans.length();
      intPart = temp / denom;
      ans += to_string(intPart);
      num = temp % denom;
   }

   if (recPos != -1)
   {
      int len = (int)ans.length();
      ans = ans.substr(0, recPos) + "(" + ans.substr(recPos, len - recPos) + ")";
   }

   return ans;
}

signed main()
{
   // freopen("IN", "r", stdin);
   // freopen("OUT", "w", stdout);

   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int T;
   cin >> T;
   while (T--)
   {
      int num, den;
      cin >> num >> den;
      cout << solve(num, den) << "\n";
   }

   return 0;
}