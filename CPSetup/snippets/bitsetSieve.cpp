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