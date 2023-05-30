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

// approach 2

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();

        int totSum=mean*(m+n);
        int sumOfMElements=accumulate(rolls.begin(),rolls.end(),0);        
        // self understandable 
        int targetSum=totSum-sumOfMElements;

        // if the n elements are all ,1s then sum would be n..,6s then sum would be 6*n if the target sum is not in this range then return nothing
        if(targetSum<n or targetSum>6*n)
            return {};

        // initialize n-sized array with 1s
        vector<int> arr(n,1);
        // reduce the target by n as n 1s have been considered
        targetSum-=n;

        for(int i=0;i<n;i++)
        {
            // the idea is to fill the array with 6s as much as possible and remaining values will be 1s
            while(arr[i]<6 and targetSum>0)
            {
                arr[i]++;
                targetSum--;
            }
        }

        return arr;
    }
};
