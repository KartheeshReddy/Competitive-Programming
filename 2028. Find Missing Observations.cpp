// approach 1

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<int> res;
    void findValues(int target,vector<int> curr,int k)
    {
        if(target==0 and k==0)
        {
            res=curr;
            terminate;
        }

        if(target<0 or k<0)
            return;

        for(int i=1;i<=6;i++)
        {   
            curr.push_back(i);
            findValues(target-i,curr,k-1);
            curr.pop_back();
        }
    }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();

        int summation=mean*(m+n);
        int rollsSum=accumulate(rolls.begin(),rolls.end(),0);
        int target=summation-rollsSum;

        findValues(target,{},n);

        return res;
    }
};


