// the code can be optimized further in terms of space and number of iterations by calculating the evens count during the single iteration
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n=nums.size(),res=0;

        vector<int> countEvensBefore(n,0),countEvensAfter(n,0);
        
        int evensCount=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2!=0)
            {
                countEvensBefore[i]=evensCount;
                evensCount=0;
            }
            else
                evensCount++;
        }

        evensCount=0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]%2!=0)
            {
                countEvensAfter[i]=evensCount;
                evensCount=0;
            }
            else
                evensCount++;
        }

        int l=0;
        int countOdds=0;
        
        for(int r=0;r<n;r++)
        {
            while(l<r and nums[l]%2==0)
                l++;

            if(nums[r]%2!=0)
                countOdds++;

            while(countOdds>k)
            {
                if(nums[l]%2!=0)
                    countOdds--;
                l++;
            }

            while(l<r and nums[l]%2==0)
                l++;

            if(countOdds==k and nums[r]%2!=0)
            {
                res+=(countEvensBefore[l]+1)*(countEvensAfter[r]+1);
            }
        }

        return res;
    }
};


// for a subarray to be nice i've defined it in the following way
// [e1,o1,e2,o2,e3,e4] say k=2
// the subarray should start and end with odd nos
// now the number of nice subarrays possible for this subarray is as follows:
// [o1,e2,o2]
// [e1,o1,e2,o2]
// [e1,o1,e2,o2,e3]
// [e1,o1,e2,o2,e3,e4]
// [o1,e2,o2,e3]
// [o1,e2,o2,e3,e4]
// it depends on the number of even nos on either side of it
