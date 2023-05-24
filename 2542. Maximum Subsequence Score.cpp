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


// approach 2 -- beautiful (https://leetcode.com/problems/maximum-subsequence-score/discuss/3083376/Easy-or-C%2B%2B-or-With-intuition-and-detailed-explanation-for-beginners)


#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        
        long long res=0;

        priority_queue<pair<int,int>> maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;    
    
        for(int i=0;i<n;i++)
            maxHeap.push(make_pair(nums1[i],i));
    
        long long summation=0;
        while(!maxHeap.empty() and k>0)
        {
            summation+=maxHeap.top().first;
            minHeap.push(make_pair(nums2[maxHeap.top().second],maxHeap.top().second));
            maxHeap.pop();
            k--;
        }

        long long minElement=minHeap.top().first;

        res=max(res,summation*minElement);
        while(!maxHeap.empty())
        {
            summation-=nums1[minHeap.top().second];
            minHeap.pop();
            summation+=maxHeap.top().first;
            minHeap.push(make_pair(nums2[maxHeap.top().second],maxHeap.top().second));
            maxHeap.pop();
            minElement=minHeap.top().first;
            res=max(res,summation*minElement);
        }

        return res;
    }
};


// approach 3 -- similar to above but instead of maxheap for nums1 vector can used by sorting in descending order
