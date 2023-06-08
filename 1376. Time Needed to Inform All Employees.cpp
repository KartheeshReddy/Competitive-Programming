#include <bits/stdc++.h>
using namespace std;


struct qStruct
{
    int node;
    int time;
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> childrenOf;

        int head;
        for(int i=0;i<n;i++)
        {
            childrenOf[manager[i]].push_back(i);
            if(manager[i]==-1)
                head=i;
        }
        
        int res=0;

        queue<qStruct> queue;
        queue.push({head,informTime[head]});

        while(!queue.empty())
        {
            int node=queue.front().node;
            int time=queue.front().time;
            queue.pop();

            if(!childrenOf[node].empty())
                res=max(res,time);

            for(auto child:childrenOf[node])
                queue.push({child,time+informTime[child]});  
        }

        return res;
    }
};

