#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

typedef long long ll;
ll helper(TreeNode<int> *root,ll &ans,ll &leaf) {
    if(!root) {
        return 0;
    }
    if(!root->left && !root->right) {
        leaf++;
    }
    ll l=helper(root->left,ans,leaf);
    ll r=helper(root->right,ans,leaf);
    ans=max(ans,l+root->val+r);
    return root->val+max(l,r);
}
ll findMaxSumPath(TreeNode<int> *root) {
    if(!root) {
        return -1;
    }
    ll ans=INT_MIN,leaf=0;
    helper(root,ans,leaf);
    return leaf>1?ans:-1;
}
