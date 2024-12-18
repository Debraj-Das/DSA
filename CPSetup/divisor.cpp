const int N = 1e7 + 1;
int divisor[N] = {0};

void primeDivisor()
{
    divisor[1] = 1;
    for (int i = 2, j; i < N; i++)
        if (divisor[i] == 0)
        {
            for (j = i; j < N; j += i)
                if (divisor[j] == 0)
                    divisor[j] = i;
        }

    return;
}

// All the Prime Divisor of any interger(<= 1e7) (e.g, 45 = 3*3*5)
vector<int> APD(int a)
{
    vector<int> ans;
    while (a > 1)
    {
        ans.pb(divisor[a]);
        a /= divisor[a];
    }
    sort(ans.begin(), ans.end());

    return ans;
}
