void DescendingTraversal(Node * temp){

        if (!temp){
            return;
        }

        DescendingTraversal(temp->right);
        cout << temp->age << " -> ";
        DescendingTraversal(temp->left);

    }
