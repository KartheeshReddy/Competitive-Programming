// approach 1 
// TC: O(N*sqrt(N))
// Time Limit Exceeded - 546 / 554 test cases passed.

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isPrime(int n)
    {
        if(n==1)
            return false;
        
        if(n==2)
            return true;

        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> res;

        for(int num=1;num<=n/2;num++)
        {
            if(num%2==0 and num!=2)
                continue;

            if(!isPrime(num))
                continue;
            
            if(!isPrime(n-num))
                continue;
            
            res.push_back({num,n-num});
        }

        return res;      
    }
};

// approach 2 - an opt to above..reducing the number of iterations for n by half
// 552 / 554 test cases passed.

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isPrime(int n)
    {
        if(n<=1)
            return false;
        
        if(n==2)
            return true;

        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> res;

        // for num=2
        if(isPrime(n-2))
            res.push_back({2,n-2});

        for(int num=3;num<=n/2;num+=2)
        {
            if(num%2==0 and num!=2)
                continue;

            if(!isPrime(num))
                continue;
            
            if(!isPrime(n-num))
                continue;
            
            res.push_back({num,n-num});
        }

        return res;      
    }
};

