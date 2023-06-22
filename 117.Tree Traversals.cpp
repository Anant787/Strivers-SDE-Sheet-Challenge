 void solve(BinaryTreeNode<int>* root,vector<vector<int>> &v){

        if(root==NULL){

            return;

        }

        v[1].push_back(root->data);

        solve(root->left,v);

        v[0].push_back(root->data);

        solve(root->right,v);

        v[2].push_back(root->data);

    }

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

     vector< vector<int> > v(3);

        solve(root,v);

     return v;

}
