void Mirror(Node * &root){
        
        if (root == nullptr){
            return;
        }
        if (root->left == nullptr && root->right == nullptr){
            return;
        }

        Node * temp = root->right;
        root->right = root->left;
        root->left = temp;

        Mirror(root->left);
        Mirror(root->right);
    }
