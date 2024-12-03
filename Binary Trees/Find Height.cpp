int FindHeight(Node * root){

        if (!root){
            return 0;
        }

        int LeftHeight = FindHeight(root->left);
        int RightHeight = FindHeight(root->right);

        return max(LeftHeight, RightHeight) + 1;
    }
