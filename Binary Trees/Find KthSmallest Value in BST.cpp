void KthSmallest(Node * root, int k, int count){

        if (root == nullptr){
            return;
        }

        KthSmallest(root->left, k, count);
        count += 1;

        if (count == k){
            cout << "Element is : " << root->patientId << endl;
        }
        KthSmallest(root->right, k, count);

    }
