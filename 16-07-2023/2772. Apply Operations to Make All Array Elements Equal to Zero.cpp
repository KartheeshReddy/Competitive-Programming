// approach 1

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();

        // an minute optimization where the array is increasing it can never be made zero...but takes time to perform the below looping
        // by using the below condition answer is returned as false in the first iteration itself
        if(nums[n-1]>nums[0])
            reverse(nums.begin(),nums.end());

        int i=0;
        while(i<n)
        {
            // skip all zeros
            while(i<n and nums[i]==0)
                i++;
            // all elements are made zero hence return true
            if(i==n)
                return true;
            
            // make every element in nums[i:i+k-1] reduced by nums[i]
            // you can think of a case where subarray is reduced by the min element in it
            // but if that's the case then nums[i] will not become zero when nums[i]>min_element
            for(int count=1;count<k;count++)
            {
                // if remaining elements form a subarray of length less than k
                if(i+count>=n)
                    return false;
                nums[i+count]-=nums[i];
                // element becomes negative then it means that nums[i] can never become zero
                if(nums[i+count]<0)
                    return false;
            }

            nums[i]=0;
            i++;
        }      

        return true;
    }
};

https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/discuss/3744509/C%2B%2B-oror-Sliding-window-technique-oror-Beginner-Friendly

