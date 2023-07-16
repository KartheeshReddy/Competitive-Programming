#include <bits/stdc++.h>
using namespace std;

// dp

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        
        if(n==0)
            return 1;
        
        int res=1;
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1,dp[0][1]=1;
    
        for(int i=1;i<n;i++)
        {
            dp[i][0]=1;
            dp[i][1]=1;
            
            if(nums1[i]>=nums1[i-1])
                dp[i][0]=max(dp[i][0],1+dp[i-1][0]);
            if(nums1[i]>=nums2[i-1])
                dp[i][0]=max(dp[i][0],1+dp[i-1][1]);
            
            if(nums2[i]>=nums2[i-1])
                dp[i][1]=max(dp[i][1],1+dp[i-1][1]);
            if(nums2[i]>=nums1[i-1])
                dp[i][1]=max(dp[i][1],1+dp[i-1][0]);
        
            res=max(res,max(dp[i][0],dp[i][1]));
        }   

        return res;
    } 
};

// recursion

class Solution {
public:
    int res=0;
    void solve(vector<int> nums1,vector<int> nums2,int n,int index,int count,int prev)
    {
        res=max(res,count);

        if(index>=n)
            return;

        if(prev<nums1[index])
            solve(nums1,nums2,n,index+1,count+1,nums1[index]);
        else
            solve(nums1,nums2,n,index+1,0,nums1[index]);
    
        if(prev<nums2[index])
            solve(nums1,nums2,n,index+1,count+1,nums2[index]);
        else
            solve(nums1,nums2,n,index+1,0,nums2[index]);
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        solve(nums1,nums2,n,0,0,INT_MIN);
        return res;
    }
};



// initial thought but all cases doesn't pass
// nums1 = [1,3,2,1], nums2 = [2,2,3,4]
// so here if you choose 4 then there might be a possibility that there can be a bigger subarray starting with 1 in future
// and also if 1 is choosen then a subarray continuation with 4 is lost 
// hence consider both the cases

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),res=0,count=0;

        int prev=INT_MIN;


        for(int i=0;i<n;i++)
        {
            if(prev<=min(nums1[i],nums2[i]))
            {
                count++;
                prev=min(nums1[i],nums2[i]);
            }
            else
            {
                res=max(res,count);
                count=0;
                prev=INT_MIN;
            }
        }      

        res=max(res,count);
        return res;    
    }
};
