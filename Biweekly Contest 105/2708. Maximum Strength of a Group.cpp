// problem of maximum subsequence product
#include <bits/stdc++.h>
using namespace std;


struct muliplication
{
    long long minM;
    long long maxM;
};


class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();

        muliplication dp[n];

        dp[0].minM=nums[0],dp[0].maxM=nums[0];

        for(int i=1;i<n;i++)
        {
            vector<long long> v1={dp[i-1].minM,(long long)dp[i-1].minM*nums[i],(long long)dp[i-1].maxM*nums[i],nums[i]};
            vector<long long> v2={dp[i-1].maxM,(long long)dp[i-1].minM*nums[i],(long long)dp[i-1].maxM*nums[i],nums[i]};
           
            dp[i].minM=*min_element(v1.begin(),v1.end());
            dp[i].maxM=*max_element(v2.begin(),v2.end());
        }

        return dp[n-1].maxM;
    }
};
