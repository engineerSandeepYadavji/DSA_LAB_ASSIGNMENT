#include <bits/stdc++.h>
using namespace std ; 

struct  Node
{
    int data ;
    Node *left;
    Node *right ;
    Node(int data){
        this->data = data ;
        left = NULL ;
        right = NULL ;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL ) return new Node(val) ;
    if(val < root->data ) root->left = insert(root->left,val) ;
    else if(val > root->data ) root->right = insert(root->right, val ) ; 
    return root ;
}

Node* findMin(Node* root){
    while(root && root->left) root = root->left ;
    return root ;
}

Node* deleteNode(Node* root , int val){
    if(root == NULL ) return NULL;
    if(val < root->data ) root->left = deleteNode(root->left,val) ;
    if(val > root->data ) root->right = deleteNode(root->right,val) ;
    else{
        if(root->left == NULL ) return root->right ;
        if(root->right == NULL ) return root->left ;
        Node* temp = findMin(root->right) ;
        root->data = temp->data ;
        root->right = deleteNode(root->right,temp->data) ;
    }
    return root ;
}

bool search(Node* root, int val){
    Node* curr = root ;
    while(curr){
        if(val== curr->data) return true ;
        if(val < curr->data ) curr = curr->left ;
        else curr = curr->right ;
    }
    return false ;
}

void inorder(Node* root){
    if(root == NULL ) return ;
    inorder(root->left) ;
    cout<<(root->data)<<" " ;
    inorder(root->right) ;
}
void preorder(Node* root){
    if(root == NULL) return ;
    cout<<(root->data)<<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}
void postorder(Node* root){
    if(root == NULL) return ;
    postorder(root->left) ;
    postorder(root->right) ;
    cout<<(root->data)<<" ";
}

void displayTraversal(Node* root){
    cout<<"In-order : " ; inorder(root) ; cout<<endl;
    cout<<"Pre-order : " ; preorder(root) ; cout<<endl; 
    cout<<"Post-order : " ; postorder(root) ; cout<<endl; 
}

int depth(Node* root){
    if(root==NULL) return -1 ;
    int leftHeight = depth(root->left) ;
    int rightHeight = depth(root->right);
    return 1+max(leftHeight,rightHeight) ;
}

Node* mirror(Node* root ){
    if(root == NULL ) return NULL ;
    Node* mirrored = new Node(root->data) ;
    mirrored->left = mirror(root->right) ;
    mirrored->right = mirror(root->left) ;
    return mirrored ;
}

void displayMirror(Node* root){
    Node* mirrored = mirror(root) ;
    cout<<"Mirror (inorder traversal ) : " ; inorder(mirrored) ; cout<<endl ;
}

Node* copyTree(Node* root){
    if(root == NULL ) return NULL ;
    Node* copied = new Node(root->data) ;
    copied->left = copyTree(root->left) ;
    copied->right = copyTree(root->right) ;
    return copied ;
}

void displayCopy(Node* root){
    Node* copied = copyTree(root) ;
    cout<<"Copy (In-order) : " ; inorder(copied) ; cout<<endl; 
}

void displayParentAndChildNodes(Node* root){
    if(root==NULL) return ;
    if(root->left) cout<<"Parent : "<<(root->data)<<", Left Child : "<<(root->left->data)<<endl; 
    if(root->right) cout<<"Parent : "<<(root->data)<<", Right Child : "<<(root->right->data)<<endl; 
    displayParentAndChildNodes(root->left) ;
    displayParentAndChildNodes(root->right) ;
}

void displayLeaves(Node* root){
    if(root == NULL ) return ;
    if((root->left==NULL) && (root->right==NULL)) cout<<(root->data)<<" " ;
    displayLeaves(root->left) ;
    displayLeaves(root->right) ;
}

void levelOrder(Node* root ){
    if(root==NULL){
        cout<<"Tree is Empty !!"<<endl; 
        return ; 
    }
    cout<<"Level order Traversal : " ;
    queue<Node*>q ; q.push(root ) ;
    while(!q.empty()){
        Node* curr = q.front() ; q.pop() ;
        cout<<(curr->data)<<" " ;
        if(curr->left) q.push(curr->left) ;
        if(curr->right) q.push(curr->right) ;
    }
    cout<<endl; 
}

void menue(){
    cout<<"------------------------------------------------------------------------------------"<<endl ;
    cout<<"case 1 : Insert a node "<<endl;
    cout<<"case 2 : Delete a node "<<endl;
    cout<<"case 3 : Search"<<endl;
    cout<<"case 4 : Display tree (Traversal)"<<endl; 
    cout<<"case 5 : Display - Depth of tree "<<endl; 
    cout<<"case 6 : Display - Mirror image"<<endl;
    cout<<"case 7 : Create a copy"<<endl;
    cout<<"case 8 : Display all parent nodes with their child nodes"<<endl;
    cout<<"case 9 : Display leaf Nodes "<<endl;
    cout<<"case 10 : Display tree level wise "<<endl; 
    cout<<"Press any other integer to EXIT"<<endl; 
    cout<<"------------------------------------------------------------------------------------"<<endl ;
    cout<<"YOUR CHOICE : " ;
}

int main(){
    int choice,val;
    Node *root = NULL ;

    do{
        menue() ; cin>>choice ;

        switch (choice)
        {
        case 1:
            cout<<"Enter the value to insert : "; cin>>val ;
            root = insert(root,val) ;
            break;
        case 2:
            cout<<"Enter the value to delete : "; cin>>val ;
            root = deleteNode(root,val) ;
            break; 
        case 3:
            cout<<"Enter the value to search : "; cin>>val ;
            if(search(root,val)) cout<<"value found in tree :) "<<endl; 
            else cout<<"value not found in tree :("<<endl; 
            break; 
        case 4:
            displayTraversal(root) ;
            break; 
        case 5:
            cout<<"Depth of the tree : "<<depth(root)<<endl; 
            break; 
        case 6:
            displayMirror(root) ;
            break; 
        case 7:
            displayCopy(root) ;
            break; 
        case 8:
            displayParentAndChildNodes(root) ;
            break; 
        case 9:
            cout<<"Leaf Nodes : "; displayLeaves(root) ; cout<<endl; 
            break; 
        case 10:
            levelOrder(root) ;
            break; 
        }

    }while(choice<=10 && choice>=1 ) ;

    cout<<"Program EXITTED Successfully :) "<<endl; 
    return 0 ;
}