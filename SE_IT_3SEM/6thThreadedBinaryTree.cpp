#include <bits/stdc++.h>
using namespace std ; 

struct Node{
    int data;
    Node *left ;
    Node *right ;
    bool leftThread ;
    bool rightThread ;
    Node(int val){
        data = val ;
        left = right = NULL ;
        leftThread = rightThread = true ;
    }
};

Node* insert(Node* root, int val) {
   if(root == NULL ) return new Node(val) ;
   
   Node *parent = NULL ;
   Node *curr = root ;

   while(curr != NULL ){
        if(val==curr->data){
            cout<<"DUPLICATE DATA !!"<<endl ;
            return root ;
        }
        parent = curr ;
        if(val<curr->data){
            if(curr->leftThread) break;
            curr = curr->left ;
        }
        else{
            if(curr->rightThread) break ;
            curr = curr->right ;
        }
   }

   Node* newNode = new Node(val) ;

   if(val<parent->data){
        newNode->left = parent->left ;
        newNode->right = parent ;
        parent->leftThread = false ;
        parent->left = newNode ;
   }
   else{
        newNode->right = parent->right ;
        newNode->left = parent;
        parent->rightThread = false ;
        parent->right = newNode ;
   }
    return root ;
}

Node* leftMost(Node* node){
    while(node && !node->leftThread) node = node->left ;
    return node ;
}

void inorder(Node* root){
    Node* curr = leftMost(root) ;
    cout<<"In-order : ";
    while(curr){
        cout<<(curr->data)<<" ";
        if(curr->rightThread) curr = curr->right ;
        else curr = leftMost(curr->right) ;
    }
    cout<<endl; 
}

void preorder(Node* root) { 
    cout<<"Pre-order : ";
    Node* curr = root; 
    while (curr) { 
        cout << curr->data << " "; 
 
        if (!curr->leftThread) 
            curr = curr->left; 
        else if (!curr->rightThread) 
            curr = curr->right; 
        else { 
            // Find the next preorder node 
            while (curr && curr->rightThread) {
                curr = curr->right;
            } 
            if(curr) curr = curr->right ;
        } 
    } 
    cout<<endl; 
} 

void menue(){
    cout<<"-------------------------------------------------"<<endl;
    cout<<"case 1 : Insert a node "<<endl;
    cout<<"case 2 : In-order Traversal"<<endl; 
    cout<<"case 3 : Pre-order Traversal"<<endl; 
    cout<<"Press any other integer to EXIT "<<endl; 
    cout<<"-------------------------------------------------"<<endl; 
    cout<<"YOUR CHOICE : " ;
}

int main(){
    Node* root=NULL ;
    int choice , val ;

    do{
        menue() ; cin>>choice ;
        switch (choice)
        {
        case 1:
            cout<<"Enter the value to insert : " ; cin>>val ;
            root = insert(root,val) ;
            break;
        case 2:
            inorder(root) ;
            break; 
        case 3:
            preorder(root) ;
            break;
        }
    }while(choice<=3 && choice>=1) ;
    cout<<"PROGRAM EXITTED SUCCESSFULLY :)"<<endl; 
    return 0 ;
}