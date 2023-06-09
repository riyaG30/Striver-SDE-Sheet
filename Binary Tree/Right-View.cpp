void RightV(Node* root,vector<int> &v, int level)
{
    if(root == NULL  )
   return ;
   if(level == v.size())
   v.push_back(root->data); 
 
 RightV(root->right,v,level+1);
  RightV(root->left,v,level+1);
  
   
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> vtr;
   if(root == NULL)
   return vector<int>();
   
   
   RIghtV(root,vtr,0);
   return vtr;
   
}
