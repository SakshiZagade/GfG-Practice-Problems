class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        if(root == NULL)
        {
            return NULL;
        }
        
        if(n1->data == root->data || n2->data==root->data)
        return root;
        
        Node *Left = LCA(root->left,n1,n2);
        Node *Right = LCA(root->right,n1,n2);
        
        if(Left == NULL)
        return Right;
        
        if(Right == NULL)
        return Left;
        
        return root;
        
    }
};
