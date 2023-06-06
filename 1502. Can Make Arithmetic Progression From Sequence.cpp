#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();

        int firstMin=min(arr[0],arr[1]),secondMin=max(arr[0],arr[1]);

        for(int i=2;i<n;i++)
        {
            if(arr[i]<firstMin)
            {
                secondMin=firstMin;
                firstMin=arr[i];
            }
            else if(arr[i]<secondMin)
                secondMin=arr[i];
        }        

        int a=firstMin,d=secondMin-firstMin;

        // unordered_set<int> uset(arr.begin(),arr.end());
        // [0,0,1] check this testcase when set is used
        unordered_map<int,int> umap;
        for(auto x:arr) umap[x]++;

        int count=0;

        while(count<=n and umap.find(a+count*d)!=umap.end())
        {
            umap[a+count*d]--;
            if(umap[a+count*d]==0)
                umap.erase(a+count*d);
            count++;
        }
        return count==n;
    }
};
