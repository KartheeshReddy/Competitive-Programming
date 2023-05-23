// the idea is using sliding window -- in the current window there can atmost two characters (with frequency of one of them as 1)
// then check if the greater frequency character exists outside the window so that it can be swapped with the character outside the window
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.length(),res=0;

        unordered_map<int,int> umap,charCount;

        for(auto x:text)
            charCount[x]++;

        int l=0;
        for(int r=0;r<n;r++)
        {
            umap[text[r]]++;

            int count1=umap.begin()->second,count2=0;
            if(umap.size()>1)
                count2=(++umap.begin())->second;
            
            while(umap.size()>2 or (count1>1 and count2>1))
            {
                umap[text[l]]--;
                if(umap[text[l]]==0)
                    umap.erase(text[l]);

                l++;
                count1=umap.begin()->second;
                if(umap.size()>1)
                    count2=(++umap.begin())->second;
                else
                    count2=0;
            }

            if(umap.size()==1)
                res=max(res,r-l+1);
            else
            {
                count1=umap.begin()->second;
                if(umap.size()>1)
                    count2=(++umap.begin())->second;
                else
                    count2=0;

                if((count1==1 and charCount[(++umap.begin())->first]-umap[(++umap.begin())->first]>0) or (count2==1 and charCount[umap.begin()->first]-umap[umap.begin()->first]>0))
                    res=max(res,r-l+1);
            }
            cout<<l<<" "<<r<<endl;
        }

        while(l<n)
        {
            if(umap.size()==1)
                res=max(res,n-1-l+1);
            else
            {
                int count1,count2;
                count1=umap.begin()->second;
                if(umap.size()>1)
                    count2=(++umap.begin())->second;
                else
                    count2=0;

                if((count1==1 and charCount[(++umap.begin())->first]-umap[(++umap.begin())->first]>0) or (count2==1 and charCount[umap.begin()->first]-umap[umap.begin()->first]>0))
                    res=max(res,n-1-l+1);
            }
            l++;
        }
        return res;
    }
};


