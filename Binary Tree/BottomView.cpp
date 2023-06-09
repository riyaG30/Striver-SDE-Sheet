vector <int> bottomView(Node *root) {
        // Your Code Here

    
        //Your code here
        vector<int> ans;
        map<int,int> mpp; // for storing the line number and first node data from top
        queue<pair<Node*,int>> q ; // to store all node and their line number
        q.push({root,0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
            mpp[line] = node->data;
            if(node->left)
            q.push({node->left,line-1});
            if(node->right)
            q.push({node->right,line+1});
            
        }
        for(auto it :mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    
    }
