// dp - O(n^2) 
// for hashmap its O(1) on average 

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),res=0;

        if(n==0 or n==1)
            return n;

        vector<pair<int,unordered_map<int,int>>> dp(n);

        for(int i=0;i<n;i++)    
            dp[i].first=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j];
                dp[i].second[diff]=max(dp[i].second[diff],dp[j].second[diff]+1);
                dp[i].first=max(dp[i].first,dp[j].second[diff]+1);
            }
            res=max(res,dp[i].first);
        }

        return res+1;
    }
};


// dp - O(n^2) 
// making search for common difference a constant time operation using indexing

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),res=0;

        if(n==0 or n==1)
            return n;

        vector<vector<int>> dp(n,vector<int>(20001,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[i]-nums[j]+10000; // incase d is -ve..beautiful idea
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                res=max(res,dp[i][diff]);
            }
        }

        return res+1;
    }
};
