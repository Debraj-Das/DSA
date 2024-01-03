// Problem: Z. Fraction
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/Z
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
   "You cannot believe in God until you believe in yourself."
                                          by Swami Vivekananda
*/

#include <bits/stdc++.h>

int main()
{
   int a, b, c, d;
   char ch;
   std::cin >> a >> ch >> b >> c >> ch >> d;
   std::cout << ((a * c) / std::__gcd(a, c)) << ch << std::__gcd(b, d);

   return 0;
}