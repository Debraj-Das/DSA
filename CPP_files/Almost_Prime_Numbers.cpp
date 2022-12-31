/*
     অভিজ্ঞতা একটি কঠিন শিক্ষক,
     সে প্রথমে তোমার পরীক্ষা নেয় এবং
     পরে তার পাঠ দেয়।
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void printKAlmostPrimes(int k, int n);

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // your code goes here
    clock_t z = clock();
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        printKAlmostPrimes(n, k);
        cout << endl;
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
// } Driver Code Ends

/*You are required to complete this function*/
void printKAlmostPrimes(int k, int n)
{
    // Your code here
    for (int i = 0, j, num = 2, temp, div; i < n; ++num)
    {
        j = 0;
        div = 2;
        temp = num;
        while ((j < k)&&(temp >= div))
        {
            if (temp % div)
                ++div;
            else
            {
                ++j;
                temp /= div;
            }
        }
        if ((temp == 1)&&(j==k))
        {
            cout << num <<' ';
            ++i;
        }
    }
    return ;
}