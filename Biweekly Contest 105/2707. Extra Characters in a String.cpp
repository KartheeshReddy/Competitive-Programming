// approach 1 - 
// 163 / 2027 test cases passed, Wrong Answer
// find intervals for a word existing in the string s for ex, leetcode->leet->{0,3}
// find max size non-overlapping intervals

#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    void findIntervalsSizeCoveringTheString(vector<pair<int,int>> intervals,int m,int prevStart,int portionsSum,int &maxSize)
    {
        if(m<0)
        {
            maxSize=max(maxSize,portionsSum);
            return;
        }

        if(intervals[m].second<prevStart)
            findIntervalsSizeCoveringTheString(intervals,m-1,intervals[m].first,portionsSum+intervals[m].second-intervals[m].first+1,maxSize);

        findIntervalsSizeCoveringTheString(intervals,m-1,prevStart,portionsSum,maxSize);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();

        vector<pair<int,int>> intervals;

        for(auto word:dictionary)
        {
            int startIndex=s.find(word);
            if(startIndex==-1)
                continue;
            intervals.push_back(make_pair(startIndex,startIndex+word.length()-1));
        }      

        int maxSize=0;

        findIntervalsSizeCoveringTheString(intervals,intervals.size()-1,INT_MAX,0,maxSize);

        return n-maxSize;
    }
};
