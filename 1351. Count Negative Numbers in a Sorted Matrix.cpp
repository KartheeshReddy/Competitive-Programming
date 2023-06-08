#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        
        int res=0;

        int i=0,j=cols-1;

        while(j>=0)
        {
            while(i<rows and grid[i][j]>=0)
                i++;
            res+=(rows-i);
            j--;
        }

        return res;
    }
};

// [
//    [4,3,2,-1],
//    [3,2,1,-1],
//    [1,1,-1,-2],
//    [-1,-1,-2,-3]
//]
// if observed the positives in the matrix would be in upper right triangle..
// the above code traverses each column until it encounters the first negative..adds to result..then proceeds with further column
// here each row and column is traversed exactly once hence time would be m+n
