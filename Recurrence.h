#ifndef RECURRENCE_H
#define RECURRENCE_H
#include <bits/stdc++.h>

template <typename T, int N, int mod = 1000000007>
struct Matrix
{
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

    Matrix operator*(Matrix a);
    Matrix operator^(int n);
};

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator*(Matrix<T, N, mod> a)
{
    Matrix<T, N, mod> res;
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            for (int k = 0; k < order; k++)
                res.m[i][j] = (res.m[i][j] + (m[i][k]*1ll* a.m[k][j]) % mod) % mod;
    return res;
}

template <typename T, int N, int mod>
Matrix<T, N, mod> Matrix<T, N, mod>::operator^(int n)
{
    Matrix<T, N, mod> res;
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

// This is Homogeneous Recurrence Relation
template <typename T, int order, int mod = 1000000007>
class Recurrence
{
protected:
    Matrix<T, order, mod> mat;
    T base[order];
    T coeff[order];

public:
    Recurrence() {}

    Recurrence(T base[], T coeff[])
    {
        for (int i = 0; i < order; i++)
        {
            this->base[i] = base[i];
            this->coeff[i] = coeff[i];
        }
        for (int i = 0; i < order; i++)
            mat.m[0][i] = coeff[i];
        for (int i = 1; i < order; i++)
            mat.m[i][i - 1] = 1;
    }

    Recurrence(std::vector<T> base, std::vector<T> coeff)
    {
        for (int i = 0; i < order; i++)
        {
            this->base[i] = base[i];
            this->coeff[i] = coeff[i];
        }
        for (int i = 0; i < order; i++)
            mat.m[0][i] = coeff[i];
        for (int i = 1; i < order; i++)
            mat.m[i][i - 1] = 1;
    }

    void setBase(T base[])
    {
        for (int i = 0; i < order; i++)
            this->base[i] = base[i];
    }
    void setCoeff(T coeff[])
    {
        for (int i = 0; i < order; i++)
            this->coeff[i] = coeff[i];
        for (int i = 0; i < order; i++)
            mat.m[0][i] = coeff[i];
        for (int i = 1; i < order; i++)
            mat.m[i][i - 1] = 1;
    }

    T getNthTerm(int n)
    {
        n--;
        if (n < order)
            return base[n];
        Matrix<T, order, mod> res = mat ^ (n - order + 1);
        T ans = 0;


        for (int i = 0; i < order; i++)
            ans = (ans + (res.m[0][i] * base[order - i - 1]) % mod) % mod;
        return ans;
    }

    T getNthTerm(int n, T base[], T coeff[])
    {
        n--;
        if (n < order)
            return base[n];
        Matrix<T, order, mod> res = mat ^ (n - order + 1);
        T ans = 0;
        this->setCoeff(coeff);
        this->setBase(base);
        for (int i = 0; i < order; i++)
            ans = (ans + (res.m[0][i] * base[order - i - 1]) % mod) % mod;
        return ans;
    }

    T *getFirstNthTerms(int n)
    {
        T *ans = new T[n];
        for (int i = 0; i < order; i++)
            ans[i] = base[i];
        if (n <= order)
            return ans;
        Matrix<T, order, mod> res = mat ^ (n - order);
        for (int i = order; i < n; i++)
        {
            ans[i] = 0;
            for (int j = 0; j < order; j++)
                ans[i] = (ans[i] + (res.m[0][j] * ans[i - j - 1]) % mod) % mod;
        }
        return ans;
    }
};

// This is Non-Homogeneous Recurrence Relation
template <typename T, int order, int mod = 1000000007>
class RecurrenceNH
{
protected:
    Matrix<T, order + 1, mod> mat;
    T base[order + 1];
    T coeff[order + 1];

public:
    RecurrenceNH() {}
    RecurrenceNH(T base[], T coeff[])
    {
        for (int i = 0; i < order; i++)
        {
            this->base[i] = base[i];
            this->coeff[i] = coeff[i];
        }
        this->coeff[order] = coeff[order];
        this->base[order] = 1;
        for (int i = 0; i <= order; i++)
            mat.m[0][i] = coeff[i];
        for (int i = 1; i < order; i++)
            mat.m[i][i - 1] = 1;
        mat.m[order][order] = 1;
    }

    RecurrenceNH(std::vector<T> base, std::vector<T> coeff)
    {
        for (int i = 0; i < order; i++)
        {
            this->base[i] = base[i];
            this->coeff[i] = coeff[i];
        }
        this->coeff[order] = coeff[order];
        this->base[order] = 1;
        for (int i = 0; i <= order; i++)
            mat.m[0][i] = coeff[i];
        for (int i = 1; i < order; i++)
            mat.m[i][i - 1] = 1;
        mat.m[order][order] = 1;
    }

    void setBase(T base[])
    {
        for (int i = 0; i < order; i++)
            this->base[i] = base[i];
        this->base[order] = 1;
        return;
    }

    void setCoeff(T coeff[])
    {
        for (int i = 0; i <= order; i++)
            this->coeff[i] = coeff[i];
        for (int i = 0; i <= order; i++)
            mat.m[0][i] = coeff[i];
        for (int i = 1; i < order; i++)
            mat.m[i][i - 1] = 1;
        mat.m[order][order] = 1;
        return;
    }

    T getNthTerm(int n)
    {
        if (n < order)
            return base[n];
        Matrix<T, order + 1, mod> res = mat ^ (n - order + 1);
        T ans = 0;
        for (int i = 0; i <= order; i++)
            ans = (ans + (res.m[0][i] * base[order - i]) % mod) % mod;
        return ans;
    }

    T getNthTerm(int n, T base[], T coeff[])
    {
        if (n < order)
            return base[n];
        this->setBase(base);
        this->setCoeff(coeff);
        Matrix<T, order + 1, mod> res = mat ^ (n - order + 1);
        T ans = 0;
        for (int i = 0; i <= order; i++)
            ans = (ans + (res.m[0][i] * base[order - i]) % mod) % mod;
        return ans;
    }

    T *getFirstNthTerms(int n)
    {
        T *ans = new T[n];
        for (int i = 0; i < order; i++)
            ans[i] = base[i];
        if (n <= order)
            return ans;
        Matrix<T, order + 1, mod> res = mat ^ (n - order);
        for (int i = order; i < n; i++)
        {
            ans[i] = 0;
            for (int j = 0; j <= order; j++)
                ans[i] = (ans[i] + (res.m[0][j] * ans[i - j - 1]) % mod) % mod;
        }
        return ans;
    }
};

#endif