#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int kthSmallest(TreeNode<int> *root, int k)
{
	// Iterative Approach
    // Morris Traversal: Inorder Traversal
    int ans = -1;
    // Case 1: Create a current pointer and points it to the root node.
    TreeNode<int>* curr = root;
    // Case 2: Loop until the current pointer will become NULL.
    while(curr != NULL){
        // Case 3: Case: if left child of the current pointer is NULL or not?
        if(curr->left == NULL){
            k--;
            if(k == 0) ans = curr->data;
            curr = curr->right;
        }
        else{
            // Case 4: Find the predecessor of the current pointer.
            TreeNode<int>* pred = curr->left;
            while(pred->right != NULL && pred->right != curr){
                pred = pred->right;
            }
            // Case 5: Case: if the right child of the predecessor is NULL or not?
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                k--;
                if(k == 0) ans = curr->data;
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
    
    return ans;
}
