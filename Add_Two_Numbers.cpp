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
    //	cin >> t;
    while (t--)
        solve(); // solve the problem inside of drive function for test cases.

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sum = NULL, *p;
        int carry, s;
        for (s = 0, carry = 0; (l1 != NULL) && (l2 != NULL); l1 = l1->next, l2 = l2->next)
        {
            s = (l1->val + l2->val + carry);
            carry = s / 10;
            s %= 10;
            if (sum == NULL)
            {
                sum = new ListNode(s);
                p = sum;
            }
            else
            {
                p->next = new ListNode(s);
                p = p->next;
            }
        }
        while (l1 != NULL)
        {
            s = (l1->val + carry);
            carry = s / 10;
            s %= 10;
            if (sum == NULL)
            {
                sum = new ListNode(s);
                p = sum;
            }
            else
            {
                p->next = new ListNode(s);
                p = p->next;
            }
            l1 = l1->next ;
        }

        while (l2 != NULL)
        {
            s = (l2->val + carry);
            carry = s / 10;
            s %= 10;
            if (sum == NULL)
            {
                sum = new ListNode(s);
                p = sum;
            }
            else
            {
                p->next = new ListNode(s);
                p = p->next;
            }
            l2 = l2->next ;
        }
            if (carry)
                p->next = new ListNode(carry);

        return sum;
    }
};

void solve()
{

    int n;
    // take input for l1 ;
    cin >> n;
    ListNode *l1 = NULL , *p;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        if (l1 == NULL)
        {
            l1 = new ListNode(x);
            p = l1;
        }
        else
        {
            p->next = new ListNode(x);
            p = p->next;
        }
    }
    // take input for l2 ;
    cin >> n;
    ListNode *l2 = NULL ;
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        if (l2 == NULL)
        {
            l2 = new ListNode(x);
            p = l2;
        }
        else
        {
            p->next = new ListNode(x);
            p = p->next;
        }
    }

    Solution obj ;
    ListNode *sum = obj.addTwoNumbers(l1,l2);
    for(p = sum;p;p = p->next)
    cout<<p->val<<' ';
    return;
}
