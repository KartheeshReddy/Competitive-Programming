#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();

        stack<int> stack;

        for(int i=0;i<n;i++)
        {
            if(asteroids[i]>0 or stack.empty())
                stack.push(asteroids[i]);
            else
            {
                while(!stack.empty() and stack.top()>0 and stack.top()<abs(asteroids[i]))
                    stack.pop();
                
                if(!stack.empty() and stack.top()==abs(asteroids[i]))
                    stack.pop();
                else if(!stack.empty() and stack.top()>abs(asteroids[i]))
                    ;// this asteroid will be destoryed
                else
                    stack.push(asteroids[i]);
            }
        }
        vector<int> res;
        while(!stack.empty())
        {
            res.push_back(stack.top());
            stack.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};
