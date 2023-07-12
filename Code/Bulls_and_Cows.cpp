/*
    অভিজ্ঞতা একটি কঠিন শিক্ষক,
    সে প্রথমে তোমার পরীক্ষা নেয় এবং
    পরে তার পাঠ দেয়।
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define el '\n'
#define f(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
void solve();

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int t = 1;
    //	cin >> t;
    while (t--)
        solve();

    return 0;
}

string getHint(string secret, string guess)
{
    int secretFreq[10] = {0};
    int guessFreq[10] = {0};
    int bull = 0 ;
    
    for(int i = 0 ; secret[i];i++)
    {
        if(secret[i] == guess[i])
            bull++;
        else
        {
            secretFreq[secret[i] - '0']++;
            guessFreq[guess[i] - '0']++;
        }
    }
    int cow = 0 ;
    for(int i = 0 ; i < 10 ; i++)
    {
        cow += min(secretFreq[i], guessFreq[i]);
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
}

void solve()
{
    string secret = "1123", guess = "0111";
    cout << getHint(secret, guess) << el;

    return;
}