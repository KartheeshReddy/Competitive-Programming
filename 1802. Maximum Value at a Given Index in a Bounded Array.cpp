// approach 1 - Time Limit Exceeded(54 / 370 test cases passed.)

// intuition:
// for both sides to the left and right of the index i shall fill the values in decreasing order [2,3,4,  5  ,4,3,2,1,1,1,1]
// i shall fill the sides from sumAtIndex-1 to 1 and the rest indices will be filled with 1s(observe to the right side of 5)
// care should be taken when filling if number of indices is less then only 4,3,2 should be filled not 1(see the left side)


class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        for(int k=maxSum;k>=1;k--)
        {
            int nToLeft=index;
            long long minSumToLeft;
            if(nToLeft>=k-1)
                minSumToLeft=(long long)(k-1)*((k-1)+1)/2+(nToLeft-(k-1));
            else
                minSumToLeft=((long long)(k-1)*((k-1)+1)/2)-((long long)((k-1)-nToLeft)*(((k-1)-nToLeft)+1)/2);

            int nToRight=n-index-1;
            long long minSumToRight;
            if(nToRight>=k-1)
                minSumToRight=(long long)(k-1)*((k-1)+1)/2+(nToRight-(k-1));
            else
                minSumToRight=((long long)(k-1)*((k-1)+1)/2)-((long long)((k-1)-nToRight)*(((k-1)-nToRight)+1)/2);

            //cout<<k<<" : "<<minSumToLeft<<","<<minSumToRight<<endl;
            if((long long)minSumToLeft+k+minSumToRight<=maxSum)
                return k;
        }
        return -1;
    }
};
