const int N = 1e6 + 1;
int prime[N] = {0};

void Divisor_sieve()
{
    for (int i = 2, j; i * i < N; i++)
    {
        if (prime[i])
            continue;

        for (j = i * i; j < N; j += i)
            prime[j] = i;
    }

    for (int i = 1; i < N; i++)
        if (prime[i] == 0)
            prime[i] = i;

    return;
}


const int N = 1e7 + 1;
bitset<N> prime;

void sieve()
{
    for (int i = 2, j; i * i < N; i++)
    {
        if (prime[i])
            continue;
        for (j = i * i; j < N; j += i)
            prime.set(j);
    }

    prime.flip();

    return;
}

vector<int> segmentSieve(int a, int b)
{
    vector<int> p(b - a + 1, false);
    
    for (int i = 2, j; i * i <= b; i++)
    {
        if (prime[i] == 0)
            continue;

        j = ((a + i - 1) / i) * i;

        for (j += i * (j == i); j <= b; j += i)
            p[j - a] = true;
    }

    return p;
}

bool is_prime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;

    return true;
}

vector<int> divisor(int x)
{
    vector<int> ans = {1, x};

    int i;
    for (i = 2; i * i < x; i++)
        if (x % i == 0)
        {
            ans.push_back(i);
            ans.push_back(x / i);
        }

    if (i * i == x)
        ans.push_back(i);

    sort(ans.begin(), ans.end());

    return ans;
}

vector<pair<int, int>> factor(int x)
{
    vector<pair<int, int>> ans;

    for (int i = 2, cnt; i * i <= x; i++)
    {
        cnt = 0;
        while (x % i == 0)
        {
            cnt++;
            x /= i;
        }
        if (cnt)
            ans.push_back({i, cnt});
    }

    if (x > 1)
        ans.push_back({x, 1});

    return ans;
}

