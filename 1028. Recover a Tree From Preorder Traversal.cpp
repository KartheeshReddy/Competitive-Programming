
class Solution {
public:
    TreeNode* solve(string traversal,int n,int &index,int currDepth,int &depth)
    {
        if(currDepth!=depth or index>=n)
            return nullptr;

        int value=0;
        while(index<n and isdigit(traversal[index]))
        {
            value=value*10+(traversal[index]-'0');
            index++;
        }

        TreeNode *root=new TreeNode(value);

        int nextDepth=0;
        while(index<n and traversal[index]=='-')
        {
            nextDepth++;
            index++;
        }
        
        depth=nextDepth;

        root->left=solve(traversal,n,index,currDepth+1,depth);
        root->right=solve(traversal,n,index,currDepth+1,depth);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int index=0,depth=0;
        return solve(traversal,traversal.length(),index,0,depth);
    }
};


