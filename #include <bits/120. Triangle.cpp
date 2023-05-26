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


// approach 2 (with o(n) space)

#include <bits/stdc++.h>
using namespace std;





class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();

        vector<int> v(rows,INT_MAX);

        v[0]=triangle[0][0];

        // cout<<v[0]<<endl;
        for(int i=1;i<rows;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(j==0)
                    v[j]+=triangle[i][j];
                else
                    v[j]=triangle[i][j]+min(v[j-1],v[j]);
            }
            // for(auto x:v)
            //     cout<<x<<" ";
            // cout<<endl;
        }
        return *min_element(v.begin(),v.end());
    }
};
