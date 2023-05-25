// approach 1 

#include <bits/stdc++.h>
using namespace std;





class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();

        vector<vector<int>> dp;

        int rowSize=1;

        for(int i=0;i<rows;i++)
        {
            if(rowSize==1)
                dp.push_back({triangle[0][0]});
            else
            {
                vector<int> v(rowSize,0);
                dp.push_back(v);

                for(int j=0;j<rowSize;j++)
                {
                    if(j==0)
                        dp[i][j]=triangle[i][j]+dp[i-1][j];
                    else
                        dp[i][j]=triangle[i][j]+min(j!=rowSize-1?dp[i-1][j]:INT_MAX,dp[i-1][j-1]);
                }
            }
            rowSize++;
        }

        return *min_element(dp[rows-1].begin(),dp[rows-1].end());
    }
};


// approach 2
