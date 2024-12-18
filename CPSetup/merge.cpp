long long inversion(int ar[], int l, int r)
{
   if (l >= r)
      return 0;

   const int mid = (r + l) / 2;

   long long ans = inversion(ar, l, mid);
   ans += inversion(ar, mid + 1, r);

   int i = l, j = mid + 1, k = 0, temp[r - l + 1];

   while (i <= mid and j <= r)
   {
      if (ar[i] <= ar[j])
      {
         temp[k++] = ar[i++];
         // inversion calculation between two array part
         ans += j - mid - 1;
      }
      else
      {
         temp[k++] = ar[j++];
      }
   }

   while (i <= mid)
   {
      temp[k++] = ar[i++];
      // inversion calculation for first part of array due ot second part of the array
      ans += (r - mid);
   }
   while (j <= r)
   {
      temp[k++] = ar[j++];
   }

   for (i = l, k = 0; i <= r; i++, k++)
      ar[i] = temp[k];

   return ans;
}

