int binary(int lo, int hi, function<bool(int)> check)
{
    int ans = hi + 1, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}
/* How to used the binary function in binary search operation
1. lower ranage = lo , higher range = hi ;
2. check function => which respect the solution space is NNNNNYYYYY(first no then yes)

auto check = [&](int mid) {
	// body of the check function
	// return true or false depend on mid ;
}

	int ar[n] ;
eg. int ans = binary(0, n - 1, [&](int i) { return ar[i] < ar[0]; });

*/
