#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices.size();

        if(n<2)
            return money;
        
        int firstMin=min(prices[0],prices[1]),secondMin=max(prices[0],prices[1]);        

        for(int i=2;i<n;i++)
        {
            if(prices[i]<firstMin)
            {
                secondMin=firstMin;
                firstMin=prices[i];
            }
            else if(prices[i]<secondMin)
                secondMin=prices[i];
        }
        
        if(firstMin+secondMin>money)
            return money;
        return money-(firstMin+secondMin);
    }
};

