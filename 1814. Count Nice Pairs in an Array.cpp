// problems boils down to finding the number of indices 'j' for ith index where 'nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])' 0<j<i

#include <bits/stdc++.h>
using namespace std;





class Solution {
public:
    int reverse(int num)
    {
        int reversedNum=0;

        while(num!=0)
        {
            int r=num%10;
            num/=10;
            reversedNum=reversedNum*10+r;
        }
        return reversedNum;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size(),res=0;

        unordered_map<int,int> countDiffOfNumAndItsRev;

        for(int i=0;i<n;i++)
        {
            res+=countDiffOfNumAndItsRev[nums[i]-reverse(nums[i])];
            res%=1000000007;
            countDiffOfNumAndItsRev[nums[i]-reverse(nums[i])]++;
        }

        return res;
    }
};
