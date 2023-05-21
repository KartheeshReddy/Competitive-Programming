// approach 1 TLE(68 / 97 test cases passed.)

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int rows,cols,res;
    bool isValidPos(int i,int j)
    {
        if(i<0 or j<0 or i>=rows or j>=cols)
            return false;
        return true;
    }
    void colorIsland(vector<vector<int>> &grid,int i,int j,int color)
    {
        grid[i][j]=color;
        if(isValidPos(i-1,j) and grid[i-1][j]==1)
            colorIsland(grid,i-1,j,color);
        if(isValidPos(i+1,j) and grid[i+1][j]==1)
            colorIsland(grid,i+1,j,color);
        if(isValidPos(i,j-1) and grid[i][j-1]==1)
            colorIsland(grid,i,j-1,color);
        if(isValidPos(i,j+1) and grid[i][j+1]==1)
            colorIsland(grid,i,j+1,color);
    }
    int getMinDistancesThroughBFS(vector<vector<int>>& grid,int i,int j)
    {
        int minDistForColor1=INT_MAX,minDistForColor2=INT_MAX;

        vector<vector<bool>> visited(rows,vector<bool>(cols,false));

        int dist=0;

        queue<pair<int,int>> queue;
        queue.push(make_pair(i,j));
        visited[i][j]=true;

        while(!queue.empty())
        {
            int m=queue.size();
            while(m--)
            {
                int r,c;
                r=queue.front().first;
                c=queue.front().second;
                queue.pop();
                if(grid[r][c]==1)
                    minDistForColor1=min(minDistForColor1,dist);
                if(grid[r][c]==2)
                    minDistForColor2=min(minDistForColor2,dist);

                if(minDistForColor1!=INT_MAX and minDistForColor2!=INT_MAX)
                    break;

                if(isValidPos(r-1,c) and !visited[r-1][c])
                {
                    visited[r-1][c]=true;
                    queue.push(make_pair(r-1,c));
                }
                if(isValidPos(r+1,c) and !visited[r+1][c])
                {
                    visited[r+1][c]=true;
                    queue.push(make_pair(r+1,c));
                }
                if(isValidPos(r,c-1) and !visited[r][c-1])
                {
                    visited[r][c-1]=true;
                    queue.push(make_pair(r,c-1));
                }
                if(isValidPos(r,c+1) and !visited[r][c+1])
                {
                    visited[r][c+1]=true;
                    queue.push(make_pair(r,c+1));
                }
            }
            dist++;
        }
        return minDistForColor1+minDistForColor2-2;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        rows=grid.size(),cols=grid[0].size();
        res=INT_MAX;

        // differentiate the islands through colors 1,2 
        int color=2;
        bool flag=true;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1 and flag)
                {
                    colorIsland(grid,i,j,color);
                    flag=false;
                }
            }
            if(flag==false) break;
        }

        // for each cell valued zero find the min distance from it to both islands through BFS
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]!=0)
                    continue;

                res=min(res,1+getMinDistancesThroughBFS(grid,i,j));
            }
        }

        return res;
        
    }
};

