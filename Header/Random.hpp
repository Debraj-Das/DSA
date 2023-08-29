/*
 * Random Int generator in range [l = INT_MIN , r = INT_MAX]
 * Random number generator [l = 0, r = 1e9]
 * Random vector
 * Random array
 * Random shuffle the vector
 * Random shuffle the array
 * Repeate the code n seconds
  
 * Usage:
 ~ l = left range(default = 0) and r = right range(default = 1e9)
 1. rdn(l, r) -> return a random number between l and r
 2. rdv(n, l, r) -> return a random vector of size n with elements between l and r
 3. rda(arr, n, l, r) -> return a random array of size n with elements between l and r
 4. shuffle(v) -> shuffle the vector v
 5. shuffle(arr, n) -> shuffle the array arr

# 6. time(n) -> repeat the code n seconds(double)

*/

#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <bits/stdc++.h>

// Random number generator
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int rdn(int l = 0, int r = 1e9) { return std::uniform_int_distribution<int>(l, r)(rng); }

// Random Int generator in range [l = INT_MIN , r = INT_MAX]
int rni(int l = INT_MIN, int r = INT_MAX) { return std::uniform_int_distribution<int>(l, r)(rng); }

// Random vector
std::vector<int> rdv(int n, int l = 0, int r = 1e9)
{
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = rdn(l, r);
	return v;
}

// Random array
void rna(int arr[], int n, int l = 0, int r = 1e9)
{
	for (int i = 0; i < n; i++)
		arr[i] = rdn(l, r);
	return;
}

// Random shuffle the vector
void shuffle(std::vector<int> &v) { std::shuffle(v.begin(), v.end(), rng); }

// Random shuffle the array
void shuffle(int a[], int n) { std::shuffle(a, a + n, rng); }

// Repeate the code n seconds
#define time(n) clock_t tt = clock(); while ((double)(clock() - tt) / CLOCKS_PER_SEC < n)

#endif // RANDOM_HPP