void levelOrder(Node* root, unordered_map<int, vector<int>>& mpp) {
    if (root == NULL) {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    int i = 0;  // Initialize i for indexing levels
    
    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelNodes;  // Vector to store nodes at the current level
        
        for (int j = 0; j < levelSize; j++) {
            Node* temp = q.front();
            q.pop();
            levelNodes.push_back(temp->data);
            
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        
        mpp[i] = levelNodes;  // Insert levelNodes vector into mpp at index i
        i++;
    }
}
