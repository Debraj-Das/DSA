#ifndef MATRIX_H
#define MATRIX_H

#include <bits/stdc++.h>

template <typename T, int N, int mod = 1000000007>
struct Matrix
{
public:
    int order = N;
    T m[N][N];

    Matrix(T init = 0)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                m[i][j] = init;
    }

    void identity()
    {
        for (int i = 0; i < order; i++)
            m[i][i] = 1;
        return;
    }

    void digonal(T arr[], int n)
    {
        n = std::min(n, order);
        for (int i = 0; i < n; i++)
            m[i][i] = arr[i];
        return;
    }

    Matrix operator+(Matrix a);
    Matrix operator-(Matrix a);
    Matrix operator*(Matrix a);
    Matrix operator*(T a);
    Matrix operator^(int n);
    Matrix adjoint();
    Matrix inverse();
    Matrix transpose();
    T determinant();
    T trace();

    Matrix operator=(Matrix a);
    Matrix operator=(std::vector<std::vector<T>> a);
    Matrix operator+=(Matrix a);
    Matrix operator-=(Matrix a);
    Matrix operator*=(Matrix a);
    Matrix operator*=(T a);
    Matrix operator^=(int n);

};

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator+(Matrix<T, N, mod> a)
{
    Matrix<T, N, mod> res(order);
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            res.m[i][j] = (m[i][j] + a.m[i][j]) % mod;
    return res;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator-(Matrix<T, N, mod> a)
{
    Matrix<T, N, mod> res(order);
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            res.m[i][j] = (m[i][j] - a.m[i][j] + mod) % mod;
    return res;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator*(Matrix<T, N, mod> a)
{
    Matrix<T, N, mod> res(order);
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            for (int k = 0; k < order; k++)
                res.m[i][j] = (res.m[i][j] + (m[i][k] * a.m[k][j]) % mod) % mod;
    return res;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator*(T a)
{
    Matrix<T, N, mod> res(order);
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            res.m[i][j] = (m[i][j] * a) % mod;
    return res;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator^(int n)
{
    if(n<0)
        return inverse() ^ (-n);
    Matrix<T, N, mod> res(order);
    res.identity();
    Matrix<T, N, mod> a(*this);
    while (n)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::adjoint()
{
    Matrix<T, N, mod> res(order);
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
        {
            Matrix<T, N - 1, mod> temp(order - 1);
            for (int k = 0; k < order; k++)
                for (int l = 0; k != i && l < order; l++)
                    temp.m[k - (k > i)][l - (l > j)] = m[k][l];
            res.m[j][i] = temp.determinant();
            if ((i + j) & 1)
                res.m[j][i] = -res.m[j][i];
        }
    return res;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::inverse()
{
    Matrix<T, N, mod> res(order);
    T det = determinant();
    if (det == 0)
        exit(-1);
    res = adjoint();
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            res.m[i][j] = (res.m[i][j] * modpow(det, mod - 2, mod)) % mod;
    return res;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::transpose()
{
    Matrix<T, N, mod> res(order);
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            res.m[i][j] = m[j][i];
    return res;
}

template <typename T, int N, int mod>
T Matrix<T, N, mod>::determinant()
{
    T res = 0;
    if (order == 1)
        return m[0][0];
    for (int i = 0; i < order; i++)
    {
        Matrix<T, N - 1, mod> temp(order - 1);
        for (int j = 0; j < order; j++)
            for (int k = 0; k != i && k < order; k++)
                temp.m[j][k - (k > i)] = m[j][k];
        res = (res + m[0][i] * temp.determinant()) % mod;
    }
    return res;
}

template <typename T, int N, int mod>
T Matrix<T, N, mod>::trace()
{
    T res = 0;
    for (int i = 0; i < order; i++)
        res = (res + m[i][i]) % mod;
    return res;
}



template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator=(Matrix<T, N, mod> a)
{
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            m[i][j] = a.m[i][j];
    return *this;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator=(std::vector<std::vector<T>> a)
{
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            m[i][j] = a[i][j];
    return *this;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator+=(Matrix<T, N, mod> a)
{
    *this = (*this) + a;
    return *this;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator-=(Matrix<T, N, mod> a)
{
    *this = (*this) - a;
    return *this;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator*=(Matrix<T, N, mod> a)
{
    *this = (*this) * a;
    return *this;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator*=(T a)
{
    *this = (*this) * a;
    return *this;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator^=(int n)
{
    *this = (*this) ^ n;
    return *this;
}




#endif // MATRIX_H_INCLUDED