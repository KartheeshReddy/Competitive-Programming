// Ref: https://leetcode.com/problems/minimum-window-substring/discuss/226911/Python-two-pointer-sliding-window-with-explanation

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    string minWindow(string s, string t) {
        int lenS=s.length(),lenT=t.length();
        int winL=-1,winR=-1;
        int requiredCharCount=lenT;
        unordered_map<char,int> charCountOfS;

        for(auto x:t)
            charCountOfS[x]++;

        int l=0;
        for(int r=0;r<lenS;r++)
        {
            if(charCountOfS[s[r]]>0)
                requiredCharCount--;

            charCountOfS[s[r]]--;

            while(requiredCharCount==0)
            {
                if(winL==-1 or r-l<winR-winL)
                    winL=l,winR=r;
                charCountOfS[s[l]]++;
                if(charCountOfS[s[l]]>0)
                    requiredCharCount++;
                l++;
            }
        }

        if(winL==-1)
            return "";
        return s.substr(winL,winR-winL+1);
    }
};


// My solution (189 / 267)

// Take a map containing the char counts of t
// Traverse through s with two pointers
// It the current window has every char counts greater than or equal to that of t then consider it as resultant substring (if the size is low than earlier seen one)
// If all counts and satisfied and count of one char is greater than required then move the window for further possibilities

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isCountsSufficient(unordered_map<char,int> charCountOfS,unordered_map<char,int> charCountOfT)
    {
        for(auto x:charCountOfT)
        {
            if(charCountOfS[x.first]<x.second)
                return false;
        }
        return true;
    }
    bool isCountOfOneExceeding(unordered_map<char,int> charCountOfS,unordered_map<char,int> charCountOfT)
    {
        int equalCount=0,greaterCount=0;
        for(auto x:charCountOfT)
        {
            if(charCountOfS[x.first]==x.second)
                equalCount++;
            if(charCountOfS[x.first]>x.second)
                greaterCount++;
        }
        return equalCount==charCountOfT.size()-1 and greaterCount==1;
    }
    string minWindow(string s, string t) {
        int lenS=s.length(),lenT=t.length();

        int winL=-1,winR=-1;

        unordered_map<char,int> charCountOfS,charCountOfT;
        // int totalCharsInWin=0;

        for(auto x:t)
        {
            charCountOfT[x]++;
            charCountOfS[x]=0;
        }
        
        int l=0;
        for(int r=0;r<lenS;r++)
        {
            while(l<r and charCountOfT.find(s[l])==charCountOfT.end())
                l++;
            
            if(charCountOfS.find(s[r])==charCountOfS.end())
                continue;
            
            charCountOfS[s[r]]++;
            //totalCharsInWin=totalCharsInWin-(charCountOfS[s[r]]-1)+(charCountOfS[s[r]]);

            while(isCountOfOneExceeding(charCountOfS,charCountOfT))
            {
                if(charCountOfS.find(s[l])!=charCountOfS.end())
                    charCountOfS[s[l]]--;
                    //totalCharsInWin=totalCharsInWin-(charCountOfS[s[l]]-1)+(charCountOfS[s[l]]);
                l++;
            }

            while(l<r and charCountOfT.find(s[l])==charCountOfT.end())
                l++;

            if(isCountsSufficient(charCountOfS,charCountOfT))
            {
                // cout<<l<<","<<r<<endl;
                if(winL==-1 or (r-l+1<=winR-winL+1))
                    winL=l,winR=r;
            }
        }

        while(l<lenS-1)
        {
            charCountOfS[s[l]]--;
            if(isCountsSufficient(charCountOfS,charCountOfT))
            {
                // cout<<l<<","<<lenS-1<<endl;
                if(winL==-1 or (lenS-1-l+1<=winR-winL+1))
                    winL=l+1,winR=lenS-1;
            }
            l++;
        }


        if(winL==-1)
            return "";
        return s.substr(winL,winR-winL+1);
    }
};
