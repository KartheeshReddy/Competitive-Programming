// approach 1 - using line sweep

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();

        int minValPossible=INT_MAX,maxValPossible=INT_MIN;

        for(int i=0;i<n;i++)
        {
            minValPossible=min(minValPossible,nums[i]-k);
            maxValPossible=max(maxValPossible,nums[i]+k);
        }

        int freqCount[maxValPossible-minValPossible+1];
        memset(freqCount,0,sizeof(freqCount));
        for(int i=0;i<n;i++)
        {
            int rangeLow=nums[i]-k,rangeHigh=nums[i]+k;
            freqCount[rangeLow-minValPossible]+=1;
            if(rangeHigh-minValPossible+1<(maxValPossible-minValPossible+1))
                freqCount[rangeHigh-minValPossible+1]-=1;
        }
        int res=freqCount[0];
        for(int i=1;i<(maxValPossible-minValPossible+1);i++)
        {
            freqCount[i]+=freqCount[i-1];
            res=max(res,freqCount[i]);
        }
  
        return res;
    }
};

// approach 2 - using intervals

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size(),res=0;

        sort(nums.begin(),nums.end());
        int startIndex=0;

        for(int endIndex=0;endIndex<n;endIndex++)
        {
            // if intervals doesn't overlap then there is no common elements present
            while(nums[startIndex]+k<nums[endIndex]-k)
                startIndex++;
            // if intervals overlap then there are common elements present and diff b/w the indices gives the frequency
            res=max(res,endIndex-startIndex+1);
        }

        return res;        
    }
};
