#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rows,cols;
    bool isValidPos(int i,int j)
    {
        return !(i<0 or j<0 or i>=rows or j>=cols);
    }
    int maxDistance(vector<vector<int>>& grid) {
        rows=grid.size(),cols=grid[0].size();

        queue<pair<int,int>> queue;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1)
                {
                    if(isValidPos(i-1,j) and grid[i-1][j]==0)
                        queue.push(make_pair(i-1,j));
                    if(isValidPos(i+1,j) and grid[i+1][j]==0)
                        queue.push(make_pair(i+1,j));
                    if(isValidPos(i,j-1) and grid[i][j-1]==0)
                        queue.push(make_pair(i,j-1));
                    if(isValidPos(i,j+1) and grid[i][j+1]==0)
                        queue.push(make_pair(i,j+1));
                }
            }
        }

        int res=-1;

        int dist=1;
        while(!queue.empty())
        {
            int m=queue.size();
            while(m--)
            {
                int i=queue.front().first;
                int j=queue.front().second;
                queue.pop();

                // the below checking is needed considering the following scenario
                // suppose there is (i,j) and (i+1,j) in the queue
                // (i,j) will be assigned say 'dist' and is processed before (i+1,j)
                // now (i+1,j) will are pushed by (i,j)
                // but though (i+1,j) is already processed it is still assigned a greater distance which is incorrect 
                // hence the below checking 
                if(grid[i][j]!=0)
                    continue;
                
                grid[i][j]=dist;

                res=max(res,grid[i][j]);

                if(isValidPos(i-1,j) and grid[i-1][j]==0)
                    queue.push(make_pair(i-1,j));
                if(isValidPos(i+1,j) and grid[i+1][j]==0)
                    queue.push(make_pair(i+1,j));
                if(isValidPos(i,j-1) and grid[i][j-1]==0)
                    queue.push(make_pair(i,j-1));                
                if(isValidPos(i,j+1) and grid[i][j+1]==0)
                    queue.push(make_pair(i,j+1));
            }
            dist++;
        }
        
        return res;
    }
};


