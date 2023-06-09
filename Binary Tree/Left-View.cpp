

//Function to return a list containing elements of left view of the binary tree.
void leftV(Node* root,vector<int> &v, int level)
{
    if(root == NULL  )
   return ;
   if(level == v.size())
   v.push_back(root->data); // will store all left side data , but we will be needing leaf nodes as well
 
 
  leftV(root->left,v,level+1);
  
   leftV(root->right,v,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> vtr;
   if(root == NULL)
   return vector<int>();
   
   
   leftV(root,vtr,0);
   return vtr;
   
}
