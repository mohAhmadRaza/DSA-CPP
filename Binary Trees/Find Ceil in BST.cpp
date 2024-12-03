void Ceil(Node* root, int key, int &minimum){
        if (root == nullptr){
            return;
        }

        else if (root->age < key){
            Ceil(root->right, key, minimum);
        }
        else if (root->age > key){
            minimum = max(minimum, root->age);
            Ceil(root->left, key, minimum);
        }
        else if (root->age == key){
            minimum = root->age;
            return;
        }
    }
