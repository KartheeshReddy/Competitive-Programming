// make sure the jump starts from 0th index
// [0,2,1,3]
// 1

// the above is the case where jump is considered from 1st index which gives a wrong result

#include <bits/stdc++.h>
using namespace std;


struct dpStruct
{
    int val;
    bool madeTransitionFromZero;
};


class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();

        dpStruct dp[n];
        for(int i=0;i<n;i++)
        {
            dp[i].val=0;
            dp[i].madeTransitionFromZero=false;
        }

        dp[0].madeTransitionFromZero=true;

        for(int j=1;j<n;j++)
        {
            for(int i=0;i<j;i++)
            {
                if(-target<=nums[j]-nums[i] and nums[j]-nums[i]<=target)
                {
                    if(dp[i].madeTransitionFromZero)
                    {
                        dp[j].val=max(dp[j].val,dp[i].val+1);
                        dp[j].madeTransitionFromZero=true;
                    }
                }
            }
        }   
        
        return (dp[n-1].val!=0 and dp[n-1].madeTransitionFromZero)?dp[n-1].val:-1;   
    }
};
