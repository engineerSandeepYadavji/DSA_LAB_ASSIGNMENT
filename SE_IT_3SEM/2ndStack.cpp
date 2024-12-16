#include <bits/stdc++.h>
using namespace std ;

class StackLL{
    int sz=0 ;
    struct Node
    {
        int data ;
        Node *next ;
        Node(int data){
            this->data = data ;
            next = NULL ;
        }
    };
    Node *topPointer = NULL ;
    public:
        void push(int ele ){
            Node *temp = new Node(ele) ;
            temp->next = topPointer ;
            topPointer = temp ;
            sz++ ;
        }
        void pop(){
            if(topPointer==NULL){
                cout<<"UNDERFLOW"<<endl ; 
                return ;
            }
            Node *temp = topPointer ;
            topPointer = topPointer->next ;
            free(temp) ;
            sz-- ;
        }
        void display(){
            cout<<"[ ";
            for(Node *temp = topPointer ; temp!= NULL ; temp = temp->next ){
                cout<<temp->data<<", ";
            }
            cout<<"]"<<endl;
        }
        int top(){
            if(topPointer==NULL) return -99999 ;
            return topPointer->data ;
        }
        int size(){
            return sz ;
        }
        bool isEmpty(){
            return (sz==0) ;
        }
};

void menue(){
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Enter your choice from given MENU : " << endl;
    cout<<"case 1 : infix to postfix " << endl;
    cout<<"case 2 : infix to prefix " << endl; 
    cout<<"case 3 : postfix evaluation  " << endl;
    cout<<"case 4 : prefix evaluation  " << endl; 
    cout<<"Press any other Integer to EXIT " <<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"YOUR CHOICE : " ; 
}

bool isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/') ;
}
int precedence(char ch){
    if(ch=='*' || ch=='/') return 2 ;
    if(ch=='+' || ch=='-' ) return 1 ;
    return 0 ;
}

int calculate(int a, char ch, int b ){
    if(ch=='+') return a+b ;
    if(ch=='-') return a-b ;
    if(ch=='*') return a*b ;
    if(ch=='/') return a/b ;
}

string infixToPostfix(string inf){
    string postf="";
    StackLL st ;

    for(char ch:inf){
        if(ch==' ') continue ;
        if(ch=='(') st.push(ch) ;
        else if(ch==')'){
            while(char(st.top()) != '('){
                postf.push_back(char(st.top())) ;
                st.pop() ;
            }
            st.pop() ;
        }
        else if(isOperator(ch)){
            while(!st.isEmpty() && precedence(ch) <= precedence(char(st.top()))){
                postf.push_back(char(st.top())) ;
                st.pop() ;
            }
            st.push(ch) ;
        }
        else postf.push_back(ch) ;
    }
    while (st.size())
    {
        postf.push_back(char(st.top())) ;
        st.pop() ;
    }
    
    return postf ;
}
string infixToPrefix(string inf){
    string pref ;
    reverse(inf.begin(),inf.end()) ;
    for(char &ch : inf ){
        if(ch=='(') ch=')' ;
        else if(ch==')') ch='(' ;
    }
    pref = infixToPostfix(inf) ;
    reverse(pref.begin(), pref.end()) ;
    return pref ;
}
int postfixEvaluation(string postf){
    StackLL st ;
    for(char ch:postf){
        if(ch==' ') continue ;
        else if(isOperator(ch)){
            int op1 = st.top() ; st.pop() ;
            int op2 = st.top() ; st.pop() ;
            int res = calculate(op2,ch,op1) ;
            st.push(res) ;
        }
        else st.push(ch-'0') ;
    }
    return st.top() ;
}
int prefixEvaluation(string pref){
    reverse(pref.begin(),pref.end()) ;
    StackLL st ;
    for(char ch:pref){
        if(ch==' ') continue ;
        if(isOperator(ch)){
            int op1 = st.top() ; st.pop() ;
            int op2 = st.top() ; st.pop() ;
            int res = calculate(op1,ch,op2) ;
            st.push(res) ;
        }
        else st.push(ch-'0') ;
    }
    return st.top() ;
}

int main(){
    int choice ;
    string inf,postf,pref ;

    do{
        menue() ; cin>>choice ;
        switch(choice){
            case 1 :
                cout<<"Enter infix expression : " ; cin>> inf ;
                postf = infixToPostfix(inf) ;
                cout<<"Postfix expression : " <<postf<<endl;
                break ;
            case 2 :
                cout<<"Enter infix expression : " ; cin>> inf ;
                pref = infixToPrefix(inf) ;
                cout<<"Prefix expression : " <<pref<<endl;
                break ;
            case 3 :
                cout<<"Enter postfix expression : " ; cin>> postf ;
                cout<<"Evaluated value : " <<postfixEvaluation(postf)<<endl;
                break ;
            case 4 :
                cout<<"Enter prefix expression : " ; cin>> pref ;
                cout<<"Evaluated value : " <<prefixEvaluation(pref)<<endl;
                break ;
        }         
    }while(choice>=1 && choice<=4);

    cout<<"PROGRAM EXITTED SUCCESSFULLY :)"<<endl ;

    return 0 ;
}