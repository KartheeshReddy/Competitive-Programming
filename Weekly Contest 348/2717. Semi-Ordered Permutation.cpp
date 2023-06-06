// note: much shorter solution can be possible for this

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(nums.begin(),nums.end());

        int swaps1=0,swaps2=0;

        int index;
        // case 1
        for(int i=0;i<n;i++)
        {
            if(temp[i]==n)
            {
                index=i;
                break;
            }
        }
        while(index<n-1)
        {
            swap(temp[index],temp[index+1]);
            swaps1++;
            index++;
        }

        for(int i=0;i<n;i++)
        {
            if(temp[i]==1)
            {
                index=i;
                break;
            }
        }
        while(index>0)
        {
            swap(temp[index],temp[index-1]);
            swaps1++;
            index--;
        }

        temp=nums;

        // case 2
        for(int i=0;i<n;i++)
        {
            if(temp[i]==1)
            {
                index=i;
                break;
            }
        }
        while(index>0)
        {
            swap(temp[index],temp[index-1]);
            swaps2++;
            index--;
        }

        for(int i=0;i<n;i++)
        {
            if(temp[i]==n)
            {
                index=i;
                break;
            }
        }
        while(index<n-1)
        {
            swap(temp[index],temp[index+1]);
            swaps2++;
            index++;
        }
        

        return min(swaps1,swaps2);
    }
};
