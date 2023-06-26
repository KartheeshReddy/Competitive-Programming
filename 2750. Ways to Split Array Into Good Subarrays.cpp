#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int solve(vector<int>& nums,int n,int index,int countOnes)
    {
        // if the current subarray includes more than a single 1 it not a good split
        if(countOnes>1)
            return 0;

        if(index>=n)
        {
            // the last subarray should have single 1
            if(countOnes==1)
                return 1;
            return 0;
        }

        int x=0,y=0;
        // continue the current subarray as it is, track the count of 1s
        x=solve(nums,n,index+1,countOnes+nums[index]);

        // if the current subarray has a 1 then split it here
        if(countOnes==1)
            y=solve(nums,n,index+1,nums[index]);

        return x+y;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();

        return solve(nums,n,0,0);
    }
};


// linear time

// this logic comes purely from visualization 
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size(),res=0;

        long long noOfWaysToSplitAtPrev1=-1;
        long long countZeros;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                countZeros++;
            else
            {
                // for the first 1 there will be only 1 split
                if(noOfWaysToSplitAtPrev1==-1)
                    noOfWaysToSplitAtPrev1=1;
                else
                {
                    // [1,0,0,0,1]
                    // [1][0,0,0,1]
                    // [1,0][0,0,1]
                    // [1,0,0][0,1]
                    // [1,0,0,0][1]
                    // the number of ways to split at the current 1 depends on the number of ways it can be splitted at previous 1 and zeros between the 1s

                    noOfWaysToSplitAtPrev1=(long long)(noOfWaysToSplitAtPrev1*(countZeros+1))%1000000007;
                }
                countZeros=0;
            }
        }

        return noOfWaysToSplitAtPrev1!=-1?noOfWaysToSplitAtPrev1%1000000007:0;
    }
};


// take a look on how the count changes with each number added to the array

[0]
[0]
---------------
[0,1]
[0,1]
---------------
[0,1,0]
[0,1,0]
-----------------
[0,1,0,0]
[0,1,0,0]
------------------
[0,1,0,0,1]
[0,1] [0,0,1]
[0,1,0] [0,1]
[0,1,0,0] [1]
--------------------
[0,1,0,0,1,0]
[0,1] [0,0,1,0]
[0,1,0] [0,1,0]
[0,1,0,0] [1,0]
---------------------
[0,1,0,0,1,0,1]
[0,1] [0,0,1] [0,1]
[0,1] [0,0,1,0] [1]

[0,1,0] [0,1] [0,1]
[0,1,0] [0,1,0] [1]

[0,1,0,0] [1] [0,1]
[0,1,0,0] [1,0] [1]
