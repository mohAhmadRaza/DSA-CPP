void LevelOrderTraversal(){

        deque<Node*> dq;

        dq.push_back(root);

        while (!dq.empty()){

            int length = dq.size();

            for (int i=0 ; i<length ; i++ ){
                Node * temp = dq.front();
                cout << temp->patientId << " -> ";
                dq.pop_front();

                if (temp->left){
                    dq.push_back(temp->left);
                }
                if (temp->right){
                    dq.push_back(temp->right);
                }
            }
        }
        
        cout << "NULL" << endl;
    }
