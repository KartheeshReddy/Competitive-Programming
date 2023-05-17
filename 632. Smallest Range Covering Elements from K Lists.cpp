#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int noOfLists=nums.size();
        int rangeLow=-1,rangeHigh=-1;

        int minimum=INT_MAX,maximum=INT_MIN;
        unordered_map<int,unordered_set<int>> umap;

        for(int k=0;k<nums.size();k++)
        {
            for(int i=0;i<nums[k].size();i++)
            {
                umap[nums[k][i]].insert(k);
                minimum=min(minimum,nums[k][i]);
                maximum=max(maximum,nums[k][i]);
            }
        }    

        unordered_map<int,int> listsCovered;
        int l=minimum;
        for(int r=minimum;r<=maximum;r++)
        {
            while(l<r and umap.find(l)==umap.end())
                l++;
            
            for(auto x:umap[r])
                listsCovered[x]++;

            while(listsCovered.size()==noOfLists)
            {
                if(rangeLow==-1 or r-l+1<rangeHigh-rangeLow+1)
                    rangeLow=l,rangeHigh=r;
                if(umap.find(l)!=umap.end())
                {
                    for(auto x:umap[l])
                    {
                        if(listsCovered.find(x)!=listsCovered.end())
                        {
                            listsCovered[x]--;
                            if(listsCovered[x]==0)
                                listsCovered.erase(x);
                        }
                    }
                }
                l++;
            }  

            // if(listsCovered.size()==noOfLists) 
            // {
            //     cout<<l<<" "<<r<<" "<<listsCovered.size()<<endl;
            //     if(rangeLow==-1 or r-l+1<rangeHigh-rangeLow+1)
            //         rangeLow=l,rangeHigh=r;
            // }
        }

        return {rangeLow,rangeHigh};
    }
};
