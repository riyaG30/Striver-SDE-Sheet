class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       
    vector<vector<int>> ans;
    map<int, vector<int>> mpp; // for storing the line number and first node data from top
    queue<pair<TreeNode *,int>> q ; // to store all node and their line number
    q.push({root,0});
    while(!q.empty())
    {
        int size = q.size();
        map<int, multiset<int>> temp; // Using multiset to allow duplicate values
        
        for(int i = 0; i < size; i++)
        {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int line = it.second;

            temp[line].insert(node->val);
            if(node->left)
                q.push({node->left,line-1});
            if(node->right)
                q.push({node->right,line+1});
        }

        for(auto it : temp)
        {
            mpp[it.first].insert(mpp[it.first].end(), it.second.begin(), it.second.end());
        }
    }

    for(auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;


    }
};
