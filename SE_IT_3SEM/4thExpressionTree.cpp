#include <bits/stdc++.h>
using namespace std ; 

struct Node{
    char data ;
    Node *left, *right ;
    Node(char data){
        this->data = data ;
        left = NULL ;
        right = NULL ;
    }
};

bool isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' ) ;
}

Node* buildFromPostfix(string postf){
    stack<Node*>st ;
    for(char ch:postf ){
        if(isOperator(ch)){
            Node *temp = new Node(ch) ;
            temp->right = st.top() ; st.pop() ;
            temp->left = st.top() ; st.pop() ;
            st.push(temp) ;
        }
        else{
            st.push(new Node(ch)) ;
        }
    }
    return st.top() ;
}

Node* buildFromPrefix(string pref){
    stack<Node*>st ;
    reverse(pref.begin(),pref.end()) ;

    for(char ch:pref){
        if(isOperator(ch)){
            Node* temp = new Node(ch) ;
            temp->left = st.top() ; st.pop() ;
            temp->right = st.top() ; st.pop() ;
            st.push(temp) ;
        }
        else st.push(new Node(ch)) ;
    }

    return st.top() ;
}

void inorderRecursive(Node* root ){
    if(root==NULL ) return ;
    inorderRecursive(root->left) ;
    cout<<(root->data)<<" "; 
    inorderRecursive(root->right);
}

void preorderRecursive(Node* root ){
    if(root==NULL ) return ;
    cout<<(root->data)<<" "; 
    preorderRecursive(root->left) ;
    preorderRecursive(root->right);
}

void postorderRecursive(Node* root ){
    if(root==NULL ) return ;
    postorderRecursive(root->left) ;
    postorderRecursive(root->right);
    cout<<(root->data)<<" "; 
}

void inorderNonRecursive(Node* root){
    stack<Node*>st ;
    Node* curr = root ;
    while(curr || !st.empty() ){
        while(curr){
            st.push(curr) ;
            curr = curr->left ;
        }
        curr = st.top() ; st.pop() ;
        cout<<(curr->data)<<" " ;
        curr = curr->right ;
    }
}
void preorderNonRecursive(Node* root){
    if(root==NULL) return ;
    stack<Node*>st;
    st.push(root) ;
    while(!st.empty()){
        Node* curr = st.top() ; st.pop() ;
        cout<<(curr->data)<<" " ;
        if(curr->right) st.push(curr->right) ;
        if(curr->left) st.push(curr->left) ;
    }
}
void postorderNonRecursive(Node* root){
    if(root==NULL) return ;
    stack<Node*>st1,st2 ;
    st1.push(root) ;
    while(!st1.empty()){
        Node *curr = st1.top() ; st1.pop() ;
        st2.push(curr) ;
        if(curr->left) st1.push(curr->left) ;
        if(curr->right) st1.push(curr->right) ;
    }
    while (!st2.empty())
    {
        cout<<st2.top()->data<<" " ;
        st2.pop() ;
    }
    
}

void menue(){
    cout<<"-----------------------------------------------------"<<endl; 
    cout << "1. Build Tree from Postfix Expression\n";
    cout << "2. Build Tree from Prefix Expression\n";
    cout << "3. Recursive In-order Traversal\n";
    cout << "4. Recursive Pre-order Traversal\n";
    cout << "5. Recursive Post-order Traversal\n";
    cout << "6. Non-Recursive In-order Traversal\n";
    cout << "7. Non-Recursive Pre-order Traversal\n";
    cout << "8. Non-Recursive Post-order Traversal\n";
    cout<<"Press any other integer to EXIT"<<endl ;
    cout<<"-----------------------------------------------------"<<endl; 
    cout<<"YOUR CHOICE : ";
}

int main(){
    Node *root = NULL ;
    int choice ;
    string pref,postf ;

    do{
        menue() ; cin>>choice ;
        switch (choice)
        {
        case 1:
            cout<<"Enter postfix string : "; cin>>postf ;
            root = buildFromPostfix(postf) ;
            break;
        case 2:
            cout<<"Enter PrefiX string : "; cin>>pref ;
            root = buildFromPrefix(pref) ;
            break;
        case 3:
            inorderRecursive(root) ;
            cout<<endl; 
            break;
        case 4:
            preorderRecursive(root) ;
            cout<<endl; 
            break;
        case 5:
            postorderRecursive(root) ;
            cout<<endl ;
            break;
        case 6:
            inorderNonRecursive(root) ;
            cout<<endl;
            break;
        case 7:
            preorderNonRecursive(root) ;
            cout<<endl; 
            break;
        case 8:
            postorderNonRecursive(root) ;
            cout<<endl; 
            break;
        
        default:
            break;
        }
    }while(choice>=1 && choice <=8 ) ;

    cout<<"PROGRAM EXITTED SUCCESSFULLY :)"<<endl; 

    return 0 ;
}