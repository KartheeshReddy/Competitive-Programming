// Solution is ok but check for more optimal one


#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    unordered_map<char,unordered_set<char>> equals,nonEquals;
    unordered_map<char,unordered_set<char>> listOfConnectedComponents;

    void dfs(int v,unordered_set<char> &visited,unordered_set<char> &currConnectedComp)
    {
        for(auto neighbour:equals[v])
        {
            if(visited.find(neighbour)!=visited.end())
                continue;
            currConnectedComp.insert(neighbour);
            visited.insert(neighbour);
            dfs(neighbour,visited,currConnectedComp);
        }
    }

    bool equationsPossible(vector<string>& equations) {
        
        // cout<<"hello\n\n";
        for(auto e:equations)
        {
            char a=e[0],b=e[3];
            bool isEqual=(e.substr(1,2))=="==";
            
            if(isEqual)
            {
                if((nonEquals.find(a)!=nonEquals.end() and nonEquals[a].find(b)!=nonEquals[a].end()) or (nonEquals.find(b)!=nonEquals.end() and nonEquals[b].find(a)!=nonEquals[b].end()))
                    return false;
                equals[a].insert(b);
                equals[b].insert(a);
            }
            else
            {
                if(a==b or (equals.find(a)!=equals.end() and equals[a].find(b)!=equals[a].end()) or (equals.find(b)!=equals.end() and equals[b].find(a)!=equals[b].end()))
                    return false;
                
                nonEquals[a].insert(b);
                nonEquals[b].insert(a);
            }
            // cout<<a<<" "<<b<<endl;
        }    

        // for(auto x:equals)
        // {
        //     cout<<x.first<<":";
        //     for(auto y:x.second)
        //         cout<<y<<" ";
        // }
        // cout<<endl;

        // for(auto x:nonEquals)
        // {
        //     cout<<x.first<<":";
        //     for(auto y:x.second)
        //         cout<<y<<" ";
        // }
        // cout<<endl;

        

        // sets of connected components

        unordered_set<char> visited;
        for(auto x:equals)
        {
            if(visited.find(x.first)!=visited.end()) 
                continue;
            
            unordered_set<char> currConnectedComp;
            currConnectedComp.insert(x.first);
            visited.insert(x.first);
            dfs(x.first,visited,currConnectedComp);
            // listOfConnectedComponents.push_back(currConnectedComp);
            for(auto x:currConnectedComp)
                listOfConnectedComponents[x]=currConnectedComp;
        }


        // for(auto x:listOfConnectedComponents)
        // {
        //     cout<<x.first<<":";
        //     for(auto y:x.second)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }

        for(auto x:nonEquals)
        {
            for(auto y:x.second)
            {
                if(listOfConnectedComponents[x.first].find(y)!=listOfConnectedComponents[x.first].end() or listOfConnectedComponents[y].find(x.first)!=listOfConnectedComponents[y].end())
                    return false;
            }
        }

        return true;
    }
};
