// approach 1 - recursive

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    void solve(vector<int> nums,int n,int indexOfSS,long long summation,long long &res)
    {
        if(n<0)
        {
            res=max(res,summation);
            return;
        }

        if(indexOfSS%2==0)
            solve(nums,n-1,indexOfSS+1,summation+nums[n],res);
        else
            solve(nums,n-1,indexOfSS+1,summation-nums[n],res);
        
        solve(nums,n-1,indexOfSS,summation,res);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        reverse(nums.begin(),nums.end());

        long long res=0;
        solve(nums,n-1,0,0,res);

        return res;
    }
};


// approach 2 - clean recursive 

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    long long solve(vector<int> nums,int n,int indexOfSS)
    {
        if(n<0)
            return 0;

        return max((indexOfSS%2==0?nums[n]:-nums[n])+solve(nums,n-1,indexOfSS+1),solve(nums,n-1,indexOfSS));
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        reverse(nums.begin(),nums.end());

        return solve(nums,n-1,0);
    }
};

// approach 3 - memoization

