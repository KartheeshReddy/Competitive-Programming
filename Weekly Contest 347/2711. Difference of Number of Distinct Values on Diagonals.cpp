#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int rows,cols;
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        rows=grid.size(),cols=grid[0].size();
        unordered_map<int,unordered_set<int>> distinctValues;

        vector<vector<int>> res(rows,vector<int>(cols,0));

        // find assign top-left  
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                res[i][j]=distinctValues[i-j].size();
                distinctValues[i-j].insert(grid[i][j]);
            }
        }

        distinctValues.clear();

        // get bottom-right and subtract
        for(int i=rows-1;i>=0;i--)
        {
            for(int j=cols-1;j>=0;j--)
            {
                res[i][j]-=distinctValues[i-j].size();
                if(res[i][j]<0)
                    res[i][j]*=-1;
                distinctValues[i-j].insert(grid[i][j]);
            }
        }

        return res;
    }
};
