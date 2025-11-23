class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int,int>& inMap){
        if(prestart>preend || instart>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - instart;
        root->left = solve(preorder, prestart+1, prestart+numsLeft, inorder, instart, inRoot-1, inMap);
        root->right = solve(preorder, prestart+numsLeft+1, preend, inorder, inRoot+1, inend, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<preorder.size();i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root = solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};

TC - O(n)
SC - O(n)