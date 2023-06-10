// approach 1 -- using BST (<O(nlogn))
// Time Limit Exceeded - 56 / 65 test cases passed. -- it forms a skew tree hence operations may take O(n) for insertion

#include <bits/stdc++.h>
using namespace std;


struct Treenode
{
    int val;
    long long frequency;
    long long countOfNodesInSubTree;
    Treenode *left,*right;
    Treenode(int val)
    {
        this->val=val;
        this->frequency=0;
        this->countOfNodesInSubTree=0;
        this->left=nullptr;
        this->right=nullptr;
    }
};


class Solution {
public:
    Treenode *root;

    int insert(int item,int n)
    {
        Treenode *newnode=new Treenode(item);

        Treenode *parent=nullptr,*curr=root;

        while(curr!=nullptr)
        {
            if(curr->val>item)
            {
                // as you go down the tree increase the node count as a node will be inserted down
                curr->countOfNodesInSubTree++;
                parent=curr;
                curr=curr->left;
            }
            // now the 'curr' subtree will have values smaller than item
            else if(curr->val<item)
                break;
            else
            {
                curr->countOfNodesInSubTree++;
                curr->frequency++;
                // min(nodes having value less than item, nodes having value greater than item) -- check below statement
                return min(curr->countOfNodesInSubTree-curr->frequency,n-curr->countOfNodesInSubTree);
            }
        }

        if(parent==nullptr)
        {
            newnode->left=curr;
            newnode->frequency=1;
            newnode->countOfNodesInSubTree=curr!=nullptr?curr->countOfNodesInSubTree+1:1;
            root=newnode;
            // no greater nodes for this hence min(x,0)=0
            return 0;
        } 

        if(parent->left==curr)
        {
            parent->left=newnode;
            newnode->left=curr;
            newnode->frequency=1;
            // curr can be null when the node is to be inserted to left or right of a leaf
            newnode->countOfNodesInSubTree=(curr!=nullptr?curr->countOfNodesInSubTree:0)+1;
        }
        else
        {
            parent->right=newnode;
            newnode->left=curr;
            newnode->frequency=1;
            newnode->countOfNodesInSubTree=(curr!=nullptr?curr->countOfNodesInSubTree:0)+1;
        }
        return min(curr!=nullptr?curr->countOfNodesInSubTree:0,n-(curr!=nullptr?curr->countOfNodesInSubTree:0)-1);
    }
    int createSortedArray(vector<int>& instructions) {
        int n=instructions.size();

        root=nullptr;
        int res=0;

        for(int i=0;i<n;i++)
            res+=insert(instructions[i],i+1);

        return res;
    }
};
