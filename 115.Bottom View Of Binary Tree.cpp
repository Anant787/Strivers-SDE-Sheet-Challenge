vector<int> bottomView(BinaryTreeNode<int> * root){

 

    vector<int>ans;

 

    if(!root)

    return ans;

 

    map<int,int> mp;

 

    queue<pair<BinaryTreeNode<int> *,int>> q;

 

    q.push({root,0});  

    while(!q.empty()){

        auto temp = q.front();

        q.pop();

        BinaryTreeNode<int> *N = temp.first;

        int hd = temp.second;

 

        mp[hd]=N->data;

         if(N->left)

        q.push({N->left,hd-1});

         if(N->right)

        q.push({N->right,hd+1});

 

    }

    

       for(auto i:mp)

       ans.push_back(i.second);

 

    return ans;    

}
