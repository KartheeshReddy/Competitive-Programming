// recursive

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    long long solve(vector<int> nums1,int n,vector<int> nums2,int minimum,int summation,int k)
    {
        if(k<0)
            return INT_MIN;
        if(k==0)
            return (long long)summation*minimum;
        if(n<0)
            return INT_MIN;
        return max(solve(nums1,n-1,nums2,min(minimum,nums2[n]),summation+nums1[n],k-1),solve(nums1,n-1,nums2,minimum,summation,k));
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();

        return solve(nums1,n-1,nums2,INT_MAX,0,k);
    }
};



// memoization

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    long long solve(unordered_map<string,int> &memo,vector<int> nums1,int n,vector<int> nums2,int minimum,int summation,int k)
    {
        if(k<0)
            return INT_MIN;
        if(k==0)
            return (long long)summation*minimum;
        if(n<0)
            return INT_MIN;

        string key=to_string(n)+','+to_string(k);
        
        if(memo.find(key)!=memo.end())
            return memo[key];

        return memo[key]=max(solve(memo,nums1,n-1,nums2,min(minimum,nums2[n]),summation+nums1[n],k-1),solve(memo,nums1,n-1,nums2,minimum,summation,k));
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();

        unordered_map<string,int> memo;

        return solve(memo,nums1,n-1,nums2,INT_MAX,0,k);
    }
};
