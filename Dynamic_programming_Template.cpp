/*
    * In this file we will see the template for the dynamic programming problem
    so I store mother problem in the dynamic programming problem in this file
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
void solve();

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1 ;
    // cin>>t ;
    while(t--) solve();
    return 0;
}


// Gobal variable for the dynamic programming problem 
// This approach is called top down approach or memorised approach

const int N = 100;
int v[N], w[N], W, n, memo[N][100001];


// it returns the maximum value total value
int knapsack(int index, int weight)
{
    // Base case
    if (index >= n)
        return 0;

    // memoissation part
    int &ans = memo[index][weight]; // ans referrence to memo[index][weight]
    if (ans != -1)
        return ans;

    // combination two idea by taking and not taking the item , and then taking the maximum

    // do not take the item
    ans = knapsack(index + 1, weight);
    // take the item at index
    if (w[index] + weight <= W)
        ans = max(ans, v[index] + knapsack(index + 1, w[index] + weight));

    return ans;
}



void solve()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    memset(memo, -1, sizeof(memo));
    cout << knapsack(0, 0);

    return ;
}

/*
    Dynamic programming is a method for solving a complex problem by breaking it down into a collection of simpler subproblems, solving each of those subproblems just once, and storing their solutions using a memory-based data structure.
    Dynamic programming is both a mathematical optimization method and a computer programming method.
    In both contexts it refers to simplifying a complicated problem by breaking it down into simpler subproblems in a recursive manner.
    While some decision problems cannot be taken apart this way, decisions that span several points in time do often break apart recursively.
    Likewise, in computer science, if a problem can be solved optimally by breaking it into subproblems and then recursively finding the optimal solutions to the subproblems, then it is said to have optimal substructure.
    A dynamic programming algorithm examines each subproblem only once, typically in a top-down fashion, and so has exponential time complexity.
    The saving of work by the memoization allows the evaluation of each recursive call in constant time, so that the complete algorithm runs in time proportional to the number of items multiplied by the knapsack capacity.

    In Dynamic programming we have two approach
    1. Top down approach or memorised approach
    2. Bottom up approach or tabulation approach

*    There some mother problem in dynamic programming
    1. 0-1 knapsack problem
    2. Unbounded knapsack problem
    3. Longest common subsequence
    4. Longest increasing subsequence
    5. Edit distance
    6. Coin change problem
    7. Matrix chain multiplication
    8. Rod cutting problem
    9. Partition problem
    10. Subset sum problem
    11. Word break problem
    12. Palindrome partitioning problem
    13. Egg dropping problem
    14. Boolean parenthesization problem
    15. 0-1 knapsack problem with duplicate items
    16. Minimum sum partition problem
    17. Count number of ways to cover a distance
    18. Minimum number of jumps to reach end
    19. Longest path in matrix
    20. Count number of ways to reach a given score in a game
    21. Maximum sum increasing subsequence
    22. Maximum length chain of pairs
    23. Maximum sum rectangle in a 2D matrix
    24. Maximum size square sub-matrix with all 1s
    25. Maximum sum path in two arrays
    26. Maximum length of pair chain
    27. Maximum sum of i*arr[i] among all rotations of a given array
    28. Maximum profit by buying and selling a share at most twice
    29. Maximum profit by buying and selling a share at most k times
    30. Maximum profit by buying and selling a share any number of times
    31. Maximum profit by buying and selling a share at most once with transaction fee
    32. Maximum profit by buying and selling a share at most once with cooldown
    33. Maximum profit by buying and selling a share at most once with k transaction
    34. Maximum profit by buying and selling a share at most once with k transaction and cooldown
    35. Maximum profit by buying and selling a share at most once with k transaction and transaction fee
    36. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown
    37. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee
    38. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee and cooldown
    39. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee and cooldown and transaction fee
    40. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown
    41. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee
    42. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown
    43. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee
    44. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown
    45. Maximum profit by buying and selling a share at most once with k transaction and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee and cooldown and transaction fee
    




*/