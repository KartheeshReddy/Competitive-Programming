#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) {
        int n=arr.size();

        // maintain groupSize and corresponding members
        unordered_map<int,pair<vector<int>,int>> groupSizeAndCorresGroup;

        vector<vector<int>> res;      
    
        for(int i=0;i<n;i++)
        {
            groupSizeAndCorresGroup[arr[i]].first.push_back(i);
            groupSizeAndCorresGroup[arr[i]].second++;

            // when the group gets filled enough then clear the group i.e., remove the group from map
            if(groupSizeAndCorresGroup[arr[i]].second==arr[i])
            {
                res.push_back(groupSizeAndCorresGroup[arr[i]].first);
                groupSizeAndCorresGroup.erase(arr[i]);
            }
        }

        return res;
    }
};
