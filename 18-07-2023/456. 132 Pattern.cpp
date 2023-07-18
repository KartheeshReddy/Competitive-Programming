// approach 1 - using a stack find 32 pattern then search for 1

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        stack<int> stack;
        int second=INT_MIN;

        for(int i=n-1;i>=0;i--)
        {
            // this number indicated as second is the one for which 3 has been found i.e., in 132..3 is found for 2 then next step is to find a 1
            // when a number(1) less than (2) is found then we've found a pattern
            if(nums[i]<second)
                return true;
            // the stack is monotonic i.e., contains elements in decreasing order from top->bottom
            // so it is made sure that second is maximum among such so that a smaller number can be easily found
            while(!stack.empty() and nums[i]>stack.top())
            {
                second=stack.top();
                stack.pop();
            }
            stack.push(nums[i]);
        }
        
        return false;
    }
};

// approach 2 - storing min elements (highly difficult)

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        int minToLeft[n];
        int minimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            minToLeft[i]=minimum;
            minimum=min(minimum,nums[i]);
        }

        stack<int> stack;
        // s1<s3<s2
        for(int i=n-1;i>=0;i--)// nums[i] would be s3
        {
            // pop all the elements in stack which are less than min to left
            // so that s1<s2 can be seen where s2 is top of stack
            while(!stack.empty() and stack.top()<=minToLeft[i])
                stack.pop();
            // if s3 is greater than s2 then 132 is observed
            if(!stack.empty() and nums[i]>stack.top())
                return true;
            
            stack.push(nums[i]);
        }        
        return false;
    }
};

// approach 3


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();

        stack<pair<int,int>> stack;

        int minimum=INT_MAX;

        // s1<s3<s2
        // nums[i] is s2
        for(int i=0;i<n;i++)
        {
            // find s3 such that s3<s2 by removing all the <= to elements in between
            while(!stack.empty() and nums[i]>=stack.top().second)
                stack.pop();
            // if the minimum element exists to left of s3 then 132 is found
            if(!stack.empty() and stack.top().first<nums[i])
                return true;

            stack.push(make_pair(minimum,nums[i]));
            minimum=min(minimum,nums[i]);
        }

        return false;
    }
};

