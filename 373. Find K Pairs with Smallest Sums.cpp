// approach 1 - O(n1*n2*logk)
// Wrong Answer - 22 / 35 test cases passed.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size(),n2=nums2.size();

        priority_queue<pair<int,pair<int,int>>> maxHeap;

        for(int k1=0;k1<n1;k1++)
        {
            for(int k2=0;k2<n2;k2++)
            {
                if(k>0)
                {
                    maxHeap.push({nums1[k1]+nums2[k2],{nums1[k1],nums2[k2]}});
                    k--;
                }
                else
                {
                    if((nums1[k1]+nums2[k2])<maxHeap.top().first)
                    {
                        maxHeap.pop();
                        maxHeap.push({nums1[k1]+nums2[k2],{nums1[k1],nums2[k2]}});
                    }
                }
            }
        }

        vector<vector<int>> res;
        while(!maxHeap.empty())
        {
            res.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
            maxHeap.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};



// approach 2 - O(k) 

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size(),n2=nums2.size();
        k=min(k,n1*n2);
        vector<vector<int>> res;
        vector<int> indexInNums2ToProcess(n1,0);
        int startIndex=0;
        int index=startIndex;
        
        for(int _=0;_<k;_++)    
        {
            // if the current index is having sum greater than that of next then process next
            if(index<n1-1 and nums1[index]+nums2[indexInNums2ToProcess[index]]>nums1[index+1]+nums2[indexInNums2ToProcess[index+1]])
                index++;
            // but if the current index still has a sum greater than that of startIndex process from startIndex
            if(startIndex<index and nums1[index]+nums2[indexInNums2ToProcess[index]]>=nums1[startIndex]+nums2[indexInNums2ToProcess[startIndex]])
                index=startIndex;

            res.push_back({nums1[index],nums2[indexInNums2ToProcess[index]]});
            indexInNums2ToProcess[index]++;
            // if nums2 corresponding to an index in n1 is exhausted then shift the startIndex further (the indices will be exhausted from left to right)
            if(indexInNums2ToProcess[index]>=n2)
            {
                startIndex++;
                index=startIndex;
            }        
        }

        return res;
    }
};


// apporach 2 -- understand more

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size(),n2=nums2.size();
        k=min(k,n1*n2);
        vector<vector<int>> res;
        
        auto cmp = [&nums1,&nums2] (const pair<int,int> &a,const pair<int,int> &b)
        {
            return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> minHeap(cmp);

        bool visited[n1][n2];
        memset(visited,false,sizeof(visited));

        minHeap.push(make_pair(0,0));

        while(k--)
        {
            pair<int,int> p=minHeap.top();
            minHeap.pop();

            res.push_back({nums1[p.first],nums2[p.second]});

            if(p.first+1<n1 and !visited[p.first+1][p.second])
            {
                visited[p.first+1][p.second]=true;
                minHeap.push(make_pair(p.first+1,p.second));
            }
            if(p.second+1<n2 and !visited[p.first][p.second+1])
            {
                visited[p.first][p.second+1]=true;
                minHeap.push(make_pair(p.first,p.second+1));
            }
        }

        return res;
    }
};

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84583/Three-different-solutions-in-C%2B%2B-well-explained

