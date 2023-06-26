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
