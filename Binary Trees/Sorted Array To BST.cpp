void ArrayToBST(NewNode * temp, int arr[], int start, int end){
        if (start > end){
            return;
        }
        
        int mid = int((start + end) / 2);

        if (start <= mid + 1){
            temp->left = new NewNode(0);
            ArrayToBST(temp->left, arr, start, mid-1);
        }

        if (mid +1 <=  end){
            temp->right = new NewNode(0);
            ArrayToBST(temp->right, arr, mid + 1, end);
        }
    }
