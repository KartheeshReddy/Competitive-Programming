#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size(),res=0;

        stack<char> stack;
        for(int i=0;i<n;i++)
        {
            if(stack.empty())
            {
                stack.push(directions[i]);
                continue;
            }

            if(directions[i]=='S')
            {
                // all the things moving to right will collide with S
                while(!stack.empty() and stack.top()=='R')
                {
                    res++;
                    stack.pop();
                }
                stack.push('S');
            }
            else if(directions[i]=='L')
            {
                // the thing moving to right will collide with L and will form S
                if(!stack.empty() and stack.top()=='R')
                {
                    // as they move in opposite directions +2
                    res+=2;
                    stack.pop();

                    // now all the Rs in stack will collide with S
                    while(!stack.empty() and stack.top()=='R')
                    {
                        res++;
                        stack.pop();
                    }
                    stack.push('S');
                }
                // L will collide with S to form S
                else if(!stack.empty() and stack.top()=='S')
                    res++;
                else
                    stack.push('L');
            }
            else
            {
                stack.push('R');
            }
        }      

        return res;
    }
};


// a non-stack soln from discuss

class Solution {
public:
    int countCollisions(string dir) {
        
        int res(0), n(size(dir)), i(0), carsFromRight(0);
        
        while (i < n and dir[i] == 'L') i++; // skipping all the cars going to left from beginning as they will never collide
        
        for ( ; i<n; i++) {
            if (dir[i] == 'R')  carsFromRight++;
            else {
                // if dir[i] == 'S' then there will be carsFromRight number of collission
                // if dir[i] == 'L' then there will be carsFromRight+1 number of collision (one collision for the rightmost cars and carsFromRight collision for the cars coming from left)
                res += (dir[i] == 'S') ? carsFromRight : carsFromRight+1;
                carsFromRight = 0;
            }
        }
        return res;
    }
};
