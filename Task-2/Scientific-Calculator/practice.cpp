#include<iostream>
#include<queue>
using namespace std;

class Node{

public:
    int data;
    Node* left;
    Node* right;


    Node(int d){

        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }


};

void levelOrderTraversal(Node* root){

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            // purana level complete traverse ho chuka hai
            cout<<endl;

            if(!q.empty()){
                // queue still has some child nodes
                q.push(NULL);

            }
        }

        else{

            cout<<temp->data<<" ";
            if(temp -> left){
                q.push(temp->left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

Node* insertIntoBST(Node* &root, int d){

    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){

    // right partmei insert karna hai
    root->right = insertIntoBST(root->right,d);

    }

    else{
        // left part mei insert karna hai
        root->left = insertIntoBST(root->left , d);
    }

    return root;
}

// delete node func

Node*  deleteFromBST(Node* root , int val){
      
    //   base case
    if(root == NULL) return root;

    if(root->data == val){

        //********************** CASE1:-  0 child *************************

        if(root->left == NULL && root->right == NULL){

            delete root;
            return NULL;
        }

        //**************************** CASE2:-  1 child (i.e if it has left child or right child) **************************

        // -->>  if its left child

        if(root->left != NULL && root->right == NULL){

            Node* temp = root->left;
            delete root;
            return temp;

        }

        // -->>  if its right child

        if(root->left == NULL && root->right != NULL){

            Node* temp = root->right;
            delete root;
            return temp;

        }




        // ****************************** CASE3:- 2 child ********************************

        if(root->left != NULL && root->right != NULL){

            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right , mini);
            return root;

        }

    }

    else if(root->data > val){
        
        // -->> left part mei jaao
        root->left = deleteFromBST(root->left , val);
        return root;
    }

    else{

        // -->> right part mei jaao
        root->right = deleteFromBST(root->right , val);
        return root;


    }

}

// minm value of BST
Node* minVal(Node* root){
    
    Node* temp = root;

    while(temp->left != NULL){

        temp = temp->left;

    }

    return temp;

}

// maxm value of BST
Node* maxVal(Node* root){
    
    Node* temp = root;

    while(temp->right != NULL){

        temp = temp->right;

    }

    return temp;

}


void takeInput(Node* &root){

    int data;
    cin>>data;

    while(data != -1){

       root = insertIntoBST(root,data);
        cin>>data;
    }
     
}



int main(){

    Node* root = NULL;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    
    cout<<" Printing the BST"<<endl;
    levelOrderTraversal(root);

    // cout<<" Min value is "<< minVal(root)->data<<endl;
    // cout<<" Max value is "<< maxVal(root)->data<<endl;
    
    // deletion
    root = deleteFromBST(root,30);



    return 0;
}