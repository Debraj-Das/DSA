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
    cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

int count_Occurrences_Of_Anagrams(string str, string ana)
{
    int k = ana.length(), i, count_map, anagrams_num;

    // # create a map for anagram of given ana
    unordered_map<char, int> obser;
    for (i = 0, count_map = 0; ana[i]; ++i)
    {
        if (obser.find(ana[i]) == obser.end())
        {
            obser[ana[i]] = 1;
            ++count_map;
        }
        else
            obser[ana[i]]++;
    }

    // # create a window and intialed the importance part
    for (i = 0; i < k; ++i)
    {
        if (obser.find(str[i]) != obser.end())
        {
            --obser[str[i]];
            if (obser[str[i]] == 0)
                --count_map;
        }
    }
    if (count_map == 0)
        anagrams_num = 1;
    else
        anagrams_num = 0;

    // # Sliding the window
    for (i = k; str[i]; ++i)
    {
        if (str[i] != str[i - k])
        {
            if (obser.find(str[i]) != obser.end())
            {
                --obser[str[i]];
                if (obser[str[i]] == 0)
                    --count_map;
            }
            if (obser.find(str[i - k]) != obser.end())
            {
                ++obser[str[i - k]];
                if (obser[str[i - k]] == 1)
                    ++count_map;
            }
        }
        // # if the count of map element is zero then we do increment of count_map
        if (count_map == 0)
            ++anagrams_num;
    }

    return anagrams_num;
}

void solve()
{
    string str, ana;
    cin >> str >> ana;
    //* try to find count occurrences of Anagrams of a given string
    cout << count_Occurrences_Of_Anagrams(str, ana) << endl;
    return;
}
