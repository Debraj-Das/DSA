const int N = 1e6+1;
bool prime[N];

void sieve()
{
   for(int i = 2 ;i < N ;i++){
      prime[i] = true;
   }
   
   prime[0] = false;
   prime[1] = false;
   
   for (int i = 2, j; i * i < N; i++)
   {
      if (prime[i] == false)
         continue;
      for (j = i * i; j < N; j += i)
         prime[j] = false;
   }

   return;
}