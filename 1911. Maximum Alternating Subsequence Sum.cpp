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

// approach 3 - dp O(N^2)
// Time Limit Exceeded - 47 / 65 test cases passed.

#include <bits/stdc++.h>
using namespace std;


struct dpStruct
{
    // considering the number as odd-indexed hence subtracted
    long long NSummation;
    // considering the number as even-indexed hence added
    long long PSummation;
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long res=nums[0];

        dpStruct dp[n];
        
        dp[0].PSummation=nums[0];

        // indicated as -1 because it to be included as negative there must be a positive ahead of it 
        // hence can't tell in advance what can be the max sum value with it included as odd indexed
        dp[0].NSummation=-1;

        for(int i=1;i<n;i++)
        {
            dp[i].PSummation=nums[i];

            dp[i].NSummation=-1;

            for(int j=0;j<i;j++)
            {
                if(dp[j].PSummation-nums[i]>dp[i].NSummation)
                    dp[i].NSummation=dp[j].PSummation-nums[i];

                // 'j'th index can be considered for 'i'th index positive summation if the NSummation has been processed earlier(!=-1)
                if(dp[j].NSummation!=-1 and dp[j].NSummation+nums[i]>dp[i].PSummation)
                    dp[i].PSummation=dp[j].NSummation+nums[i];
            }
            res=max(res,max(dp[i].PSummation,dp[i].NSummation));
        }

        return res;
    }
};

