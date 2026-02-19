// number of coprime with n with less then n number. it call phi number

const int N = 1e6 + 1;
int phi[N];

void coprime()
{
    for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2, j; i < N; i++)
        if (phi[i] == i)
            for (j = i; j < N; j += i)
                phi[j] -= (phi[j] / i);

    return;
}
