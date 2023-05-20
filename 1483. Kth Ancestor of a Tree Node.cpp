// approach 1: Storing the ancestors of all the nodes (Memory Limit Exceeded-8 / 16 test cases passed.)

#include <bits/stdc++.h>
using namespace std;


// struct TreeNode
// {
//     int val;
//     vector<int> children;
//     TreeNode(int val)
//     {
//         this->val=val;
//         this->children={};
//     }
// };


class TreeAncestor {
public:
    //unordered_map<int,int> nodesAndLevels;
    unordered_map<int,vector<int>> nodesAndTheirChildren;
    // unordered_map<int,int> parent;
    unordered_map<int,pair<int,vector<int>>> nodesAndTheirAncestors;
    int root;


    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                root=i;
                continue;
            }
            nodesAndTheirChildren[parent[i]].push_back(i);
        }
        processAncestors(root,{root},0);

        // for(auto x:nodesAndTheirChildren)
        // {
        //     cout<<x.first<<" : ";
        //     for(auto y:x.second)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }

        // for(auto x:nodesAndTheirAncestors)
        // {
        //     cout<<x.first<<" : ";
        //     cout<<x.second.first<<" , ";
        //     for(auto y:x.second.second)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
    }

    void processAncestors(int root,vector<int> path,int level)
    {
        
        nodesAndTheirAncestors[root].first=level;
        nodesAndTheirAncestors[root].second=path;

        for(auto child:nodesAndTheirChildren[root])
        {
            path.push_back(child);
            processAncestors(child,path,level+1);
            path.pop_back();
        }
    }
    

    int getKthAncestor(int node, int k) {
        if(k>nodesAndTheirAncestors[node].first)   
            return -1;
        return nodesAndTheirAncestors[node].second[nodesAndTheirAncestors[node].first-k];
    }
};


// approach 2: Storing the ancestors of just the leaves and some processing to access the ancestors of other nodes (MLE)

#include <bits/stdc++.h>
using namespace std;


// struct TreeNode
// {
//     int val;
//     vector<int> children;
//     TreeNode(int val)
//     {
//         this->val=val;
//         this->children={};
//     }
// };


class TreeAncestor {
public:
    //unordered_map<int,int> nodesAndLevels;
    unordered_map<int,vector<int>> nodesAndTheirChildren;
    // unordered_map<int,int> parent;
    unordered_map<int,int> nodesAndTheirLevel;
    unordered_map<int,int> leafContainingNodeAsAnc;
    unordered_map<int,vector<int>> leavesAndTheirAnc;
    int root;


    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                root=i;
                continue;
            }
            nodesAndTheirChildren[parent[i]].push_back(i);
        }
        processAncestors(root,{root},0);

        // for(auto x:nodesAndTheirChildren)
        // {
        //     cout<<x.first<<" : ";
        //     for(auto y:x.second)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }

        // for(auto x:nodesAndTheirAncestors)
        // {
        //     cout<<x.first<<" : ";
        //     cout<<x.second.first<<" , ";
        //     for(auto y:x.second.second)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        for(auto x:leafContainingNodeAsAnc)
            cout<<x.first<<" : "<<x.second<<" ";
        cout<<endl;
    }

    void processAncestors(int root,vector<int> path,int level)
    {
        
        nodesAndTheirLevel[root]=level;

        for(auto child:nodesAndTheirChildren[root])
        {
            path.push_back(child);
            processAncestors(child,path,level+1);
            path.pop_back();
        }

        if(nodesAndTheirChildren[root].empty())
        {
            leavesAndTheirAnc[root]=path;
            leafContainingNodeAsAnc[root]=root;
            for(auto ancestor:path)
            {
                if(leafContainingNodeAsAnc.find(ancestor)==leafContainingNodeAsAnc.end() or path.size()<leavesAndTheirAnc[leafContainingNodeAsAnc[ancestor]].size())
                    leafContainingNodeAsAnc[ancestor]=root;
            }
        }

        
    }
    

    int getKthAncestor(int node, int k) {
        if(k>nodesAndTheirLevel[node])   
            return -1;
        return leavesAndTheirAnc[leafContainingNodeAsAnc[node]][2*nodesAndTheirLevel[leafContainingNodeAsAnc[node]]-nodesAndTheirLevel[node]-k];
    }
};




