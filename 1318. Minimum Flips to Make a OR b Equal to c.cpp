// as the number of bits can be 32 bits in any number at max..the solution has constant time and space complexity

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minFlips(int a, int b, int c) {
        int noOfBitsFlipped=0;

        while(a!=0 or b!=0 or c!=0)
        {
            int bitA=((a&1)==0?0:1);
            a>>=1;
            int bitB=((b&1)==0?0:1);
            b>>=1;
            int bitC=((c&1)==0?0:1);
            c>>=1;
            
            // cout<<bitA<<" "<<bitB<<" "<<bitC<<endl;

            if(bitC==0)
            {
                if(bitA==0 and bitB==0)
                    continue;
                // if any of the bit is 1 then it must be flipped to 0
                if(bitA==1) noOfBitsFlipped++;
                if(bitB==1) noOfBitsFlipped++;
            }
            else
            {
                if(bitA==1 or bitB==1)
                    continue;
                // it says that both the bits are 0 hence flip any of them to 1
                noOfBitsFlipped++;
            }
        }      

        return noOfBitsFlipped;
    }
};
