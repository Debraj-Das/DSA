/*

Given an unsorted integer array, find a pair with the given sum in it.

• Each input can have multiple solutions. The output should match with either one of them.

Input : nums[] = [8, 7, 2, 5, 3, 1], target = 10
Output: (8, 2) or (7, 3)

• The solution can return pair in any order. If no pair with the given sum exists, the solution should return the pair (-1, -1).

Input : nums[] = [5, 2, 6, 8, 1, 9], target = 12
Output: (-1, -1)

*/
#include <bits/stdc++.h>

using namespace std ;

class Solution
{
public:
     vector<int> nums ;
	void findPair(vector<int> const &nums, int target)
	{
		const int n = nums.size();
          int output = 0 ;
          for(int i=0,j,m;i<n;++i)
          {
               m = target - nums[i];
               for(j = (i+1);j<n;++j)
               {
                    if(m==nums[j])
                    {
                         printf("(%d %d)\n",nums[i],nums[j]);
                         ++output ;
                         break;
                    }
               }
          }
          if(output == 0)
          printf("(-1 , -1)\n");
          return ;
	}
};

int main()
{
     Solution obj ;
     int n ;
     cout<<"Enter the (-1) for exit input loop "<<endl;
     while(true)
     {
          cout<<"\t";
          cin>>n;
          if(n==(-1))
          break;
          obj.nums.push_back(n);
     }
     // cout<<"Element of the member ::\n";
     // for(int n = obj.nums.size();n;--n)
     // cout<<obj.nums[n-1]<<endl;

     cout<<"Enter the target number :: ";
     cin>>n;
     cout<<"Output of the target number is :: "<<endl;
     obj.findPair(obj.nums,n);

     return 0;
}
