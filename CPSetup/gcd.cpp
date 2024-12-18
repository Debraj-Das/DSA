int gcd(int a, int b)
{
   if (a == 0 or b == 0)
      return (a ^ b);
   return __gcd(a, b);
}

void extendgcdUtills(int a, int b, pair<int, int> &ans)
{
   if (b == 0)
   {
      ans.first = 1;
      ans.second = 0;
      return;
   }

   extendgcdUtills(b, a % b, ans);
   int x = ans.second;

   ans.second = ans.first - ans.second * (a / b);
   ans.first = x;

   return;
}

pair<int, int> Egcd(int a, int b, int c)
{
   int g = gcd(a, b);
   
   // answer not present if c%g != 0
   if (c % g != 0)
      return make_pair(0, 0);

   pair<int, int> ans;
   extendgcdUtills(a, b, ans);

   int k = c / g;
   ans.first *= k;
   ans.second *= k;

   /*
      There are infinity solution
      ans.first = ans.first + (b/g)*t;
      ans.second = ans.second - (a/g)*t;
      here t is any interger
   */

   return ans;
}
