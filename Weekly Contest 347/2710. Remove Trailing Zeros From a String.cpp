#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    string removeTrailingZeros(string num) {
        int n=num.length();

        int index=n-1;

        for(;index>=0;index--)
        {
            if(num[index]!='0')
                break;
        }      

        return num.substr(0,index+1);
    }
};
