#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool flag;
    vector<int> flippedNodes;
    int n;


    void traverse(TreeNode *root,TreeNode *parent,vector<int> preorder,int &index)
    {
        if(root==nullptr)
            return;

        // this is case where there are still some nodes in the tree but preorder array has exhausted
        if(index>=n)
        {
            flag=false;
            return;
        }
        
        if(root->val!=preorder[index])
        {
            // if root itself isn't equal to the preorder seq then nothing can be done
            if(parent==nullptr)
            {
                flag=false;
                return;
            }
            // if root is to left of the parent
            if(parent->left!=nullptr and parent->left->val==root->val)
            {
                // to swap right must exist else flipping isn't possible
                if(parent->right==nullptr or parent->right->val!=preorder[index])
                {
                    flag=false;
                    return;
                }

                // swap(parent->left,parent->right);
                // merely we tend to use the statement above but it's incorrect
                // after processing the current node the traversing must happen with the flipped node
                // check in the history of submissions for this question to understand this logic better

                // the function call is already made to parent's left (root.left) but it must now process the flipped node's descendents hence swapping

                swap(parent->left->val,parent->right->val);
                swap(parent->left->left,parent->right->left);
                swap(parent->left->right,parent->right->right);
                flippedNodes.push_back(parent->val);
                index++;
            }
            else if(parent->right!=nullptr and parent->right->val==root->val)
            {
                if(parent->left==nullptr or parent->left->val!=preorder[index])
                {
                    flag=false;
                    return;
                }
                swap(parent->left->val,parent->right->val);
                swap(parent->left->left,parent->right->left);
                swap(parent->left->right,parent->right->right);
                flippedNodes.push_back(parent->val);
                index++;
            }
        }
        else
            index++;
        
        traverse(root->left,root,preorder,index);
        traverse(root->right,root,preorder,index);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& preorder) {
        n=preorder.size();
        flag=true;
        
        int index=0;
        traverse(root,nullptr,preorder,index);

        // when any of the conditions mentioned in the function call fails or preorder array is not completely processed(when there are not enough nodes in the tree)
        if(!flag or !(index>=n))
            return {-1};
        return flippedNodes;
    }
};
