#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n=s.length(),res=0;

        int countOfPairsWithConsecutiveDigits=0;
        int l=0;
        for(int r=0;r<n;r++)
        {
            if(r>0 and s[r]==s[r-1])
                countOfPairsWithConsecutiveDigits++;

            while(countOfPairsWithConsecutiveDigits>1)
            {
                if(l<n and s[l]==s[l+1])
                    countOfPairsWithConsecutiveDigits--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};
