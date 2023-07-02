// brute force approaches -- you know


// approach - 1 (using two stacks)
// TC: O(1) SC: O(2*N)


#include <bits/stdc++.h>
using namespace std;


// consider this testcase
// ["MinStack","push","push","push","push","push","push","push","push","push"]
// [[],[10],[90],[45],[1],[32],[190],[-1],[240],[900]]

// s1: [10,90,45,1,32,190,-1,240,900] <-top
// s2: [10,1,-1] <-top

// as long as you find an element min then current one you can ignore the rest elements in between..check above

class MinStack {
public:
    stack<int> stack1,stack2;
    MinStack() {
        // 
    }
    
    void push(int val) {
        stack1.push(val);
        if(stack2.empty() or val<=stack2.top())
            stack2.push(val);
    }
    
    void pop() {
        if(stack1.top()==stack2.top())
            stack2.pop();

        stack1.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
};

// approach 2 - using single stack

#include <bits/stdc++.h>
using namespace std;

// here a little similar to the prev approach
// if the current minimum is to be popped then the next minimum is stored right under it

class MinStack {
public:
    int minimum;
    stack<int> stack;
    MinStack() {
        minimum=INT_MAX;
    }
    
    void push(int val) {
        // if minimum is to be changed
        if(val<=minimum)
        {
            // push the current minimum so that incase if this element is popped then the next minimum can be tracked
            stack.push(minimum);
            minimum=val;
        }
        stack.push(val);
    }
    
    void pop() {
        // if the top element is minimum
        if(stack.top()==minimum)
        {
            stack.pop();
            // its' under one would be the next minimum
            minimum=stack.top();
            stack.pop();
        }
        else
            stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minimum;
    }
};

// approach 3 - Stack of Pair of Int

The first value of the pair would store the element of the normal stack and the second value would store the minimum up to that point in the stack.
So even if the minimum element of the stack is removed from the top, we still have a backup of the next minimum element in the pair. So for every element pushed in the stack, it stores its corresponding minimum value.

// approach 4 - stack with arithmetic

#include <bits/stdc++.h>
using namespace std;


class MinStack {
public:
    stack<int> stack;
    int minimum=INT_MAX;
    MinStack() {
        // 
    }
    
    void push(int val) {
        if(stack.empty())
        {
            stack.push(0);
            minimum=val;
        }
        else
        {
            stack.push(val-minimum);
            if(val<minimum)
                minimum=val;
        }
    }
    
    void pop() {
        int popped=stack.top();
        stack.pop();

        // the value becomes negative when a new minimum element is found hence subtract to get previous minimum value
        if(popped<0)
            minimum=minimum-popped;
    }
    
    int top() {
        return stack.top()+minimum;
    }
    
    int getMin() {
        return minimum;
    }
};
