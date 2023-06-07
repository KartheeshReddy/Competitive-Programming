// thought 1 -- though the approach seems correct..147 / 160 test cases passed.

// intuition: treat the given points as a graph
// the way adjacency between two points is calculated as..if dist between them is less or equal to radius of either of them...if any of them is detonated the other would be detonated automatically
// for finding the maximum number of bombs that can be detonated..treating the graph as disconnnected, find the component with maximum number of vertices

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    unordered_map<int,unordered_set<int>> adj;
    int n;

    void dfs(int v,unordered_set<int> &visited,int &countVertices)
    {
        for(auto neighbour:adj[v])
        {
            if(visited.find(neighbour)!=visited.end())
                continue;
            countVertices++;
            visited.insert(neighbour);
            dfs(neighbour,visited,countVertices);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
       
        int n=bombs.size();
        for(int i=0;i<n;i++)
        {
            int x1=bombs[i][0],y1=bombs[i][1];
            double r1=bombs[i][2];
            for(int j=i+1;j<n;j++)
            {
                int x2=bombs[j][0],y2=bombs[j][1];
                double r2=bombs[j][2];
                
                double dist=sqrt((long long)(x2-x1)*(x2-x1)+(long long)(y2-y1)*(y2-y1));

                if(dist<=r1 or dist<=r2)
                {
                    adj[i].insert(j);
                    adj[j].insert(i);
                }
            }

        }        

        int res=0;

        unordered_set<int> visited;
        int countVertices;
        
        for(int i=0;i<n;i++)
        {
            if(visited.find(i)!=visited.end())
                continue;
            visited.insert(i);
            countVertices=1;
            
            dfs(i,visited,countVertices);
            res=max(res,countVertices);
        }

        return res;
    }
};


// approach-2
// from every vertex checking number of vertices it could reach

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    unordered_map<int,unordered_set<int>> adj;
    int n;

    void dfs(int v,unordered_set<int> &visited,int &countVertices)
    {
        for(auto neighbour:adj[v])
        {
            if(visited.find(neighbour)!=visited.end())
                continue;
            countVertices++;
            visited.insert(neighbour);
            dfs(neighbour,visited,countVertices);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
       
        int n=bombs.size();
        for(int i=0;i<n;i++)
        {
            int x1=bombs[i][0],y1=bombs[i][1];
            double r1=bombs[i][2];
            for(int j=i+1;j<n;j++)
            {
                int x2=bombs[j][0],y2=bombs[j][1];
                double r2=bombs[j][2];
                
                double dist=sqrt((long long)(x2-x1)*(x2-x1)+(long long)(y2-y1)*(y2-y1));

                if(dist<=r1)
                    adj[i].insert(j);
                if(dist<=r2)
                    adj[j].insert(i);
            }

        }        

        int res=0;

        int countVertices;
        
        for(int i=0;i<n;i++)
        {
            unordered_set<int> visited;

            visited.insert(i);
            countVertices=1;
            
            dfs(i,visited,countVertices);
            res=max(res,countVertices);
        }

        return res;
    }
};
