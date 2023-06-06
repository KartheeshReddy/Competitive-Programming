#include <bits/stdc++.h>
using namespace std;

// 48 - [1,2,3,4,6,8,12,16,24,48]
// 25 - [1,5,25]
// observe the above pattern of factors
// after sqrt(n) the factors would be like (8=48/6),(4=48/12)...
// the same concept is used below

class Solution {
public:
    int kthFactor(int n, int k) {
        // if n=48

        int d=1;
        // go till sqrt(n) i.e checking for 1,2,3,4,6
        for(;d*d<=n;d++)
        {
            if(n%d==0)
            {
                --k;
                if(k==0)
                    return d;
            }
        }

        // here it will be d=7 hence deduce
        if(d*d>n)
            d--;
        // incase of 25, 5*5 is 25 this case is checked in previous loop hence skip it
        if(d*d==n)
            d--;

        // loop from sqrt(n) by decrementing 6,4,3,2,1
        for(;d>=1;d--)
        {
            if(n%d==0)
            {
                // if 48%6==0 and also k==0 then 48/6 would be the answer as they will be in pairs
                --k;
                if(k==0)
                    return n/d;
            }
        }

        return -1;
    }
};
