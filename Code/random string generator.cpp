/*
 * Random Int generator in range [l = INT_MIN , r = INT_MAX]
 * Random vector
 * Random array
 * Random shuffle the vector
 * Random shuffle the array
 * Random char
 * Random String a length with type

 * Repeate the code n seconds

 * Usage:
 ~ l = left range(default = 0) and r = right range(default = 1e9)
 1. rdi(l, r) -> return a random number between l and r
 2. rdv(n, l, r) -> return a random vector of size n with elements between l and r
 3. rda(arr, n, l, r) -> return a random array of size n with elements between l and r
 4. shuffle(v) -> shuffle the vector v
 5. shuffle(arr, n) -> shuffle the array arr
 6. rdc()

# 6. time(n) -> repeat the code n seconds(double)

*/

#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int rnd()
{
	// range 0 to 1000
    return std::uniform_int_distribution<int>(0, 1000)(rng);
}

struct randomNumber
{
    int l, r;
    randomNumber(int l = INT_MIN, int r = INT_MAX)
    {
        this->l = l;
        this->r = r;
    }

    int rdi()
    {
        return std::uniform_int_distribution<int>(l, r)(rng);
    }

    // Random vector
    std::vector<int> rdv(int n)
    {
        std::vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = rdi();
        return v;
    }

    // Random array
    void rna(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            arr[i] = rdi();
        return;
    }
};
// Random Int generator in range [l = INT_MIN , r = INT_MAX]

// Random shuffle the vector
void shuffle(std::vector<int> &v)
{
    std::shuffle(v.begin(), v.end(), rng);
}

// Random shuffle the array
void shuffle(int a[], int n)
{
    std::shuffle(a, a + n, rng);
}

struct randomString
{
    std::string s;
    int n;

    randomString(std::string s = "abcdefghijklmnopqrstuvwxyz")
    {
        this->s = s;
        this->n = s.size() - 1;
    }

    int rdi()
    {
        return std::uniform_int_distribution<int>(0, n)(rng);
    }

    char rdc()
    {
        return s[rdi()];
    }

    std::string rds(size_t length)
    {
        std::string ans(length, 0);
        for (size_t i = 0; i < length; i++)
            ans[i] = s[rdi()];

        return ans;
    }
};

// Repeate the code n seconds
#define time(n) clock_t tt = clock(); while ((double)(clock() - tt) / CLOCKS_PER_SEC < n)

int32_t main()
{
    randomString rc("()?");
    std::cout << rc.rds(10) << '\n';

    std::cout << rnd() << '\n';

    return 0;
}