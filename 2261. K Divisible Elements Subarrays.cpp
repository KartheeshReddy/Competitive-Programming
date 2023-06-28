// approach 1 - O(n^2) time and O(n^2*n)->O(n^3) space

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size(),res=0;
        unordered_set<string> uset;

        for(int i=0;i<n;i++)
        {
            string s="";
            int countOfElementsDivByP=0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%p==0)
                    countOfElementsDivByP++;
                if(countOfElementsDivByP>k)
                    break;
                if(s!="")
                    s+=',';
                s+=to_string(nums[j]);
                if(uset.find(s)!=uset.end())
                    continue;
                uset.insert(s);
                res++;
            }
        }

        return res;
    }
};
