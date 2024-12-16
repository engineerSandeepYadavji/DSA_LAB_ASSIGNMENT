#include <bits/stdc++.h>
using namespace std ;
class CircularQueue{
    int sz=0 ;
    int cap ;
    int fr=-1,rear=-1 ;
    int* arr;
    public:
    CircularQueue(){
        cap = 10 ;
        arr = new int[cap] ;
    }
    CircularQueue(int cap){
        this->cap = cap ;
        arr = new int[cap] ;
    }
    
    void enqueue(int ele){
        if(sz==cap){
            cout<<"OVERFLOW !! "<<endl; 
            return ;
        }
        if(sz==0){
            fr=rear=0 ;
            arr[rear]=ele ;
        }
        else{
            rear = (rear+1)%cap ;
            arr[rear] = ele ; 
        }
        sz++ ;
    }
    void dequeue(){
        if(sz==0){
            cout<<"UNDERFLOW !!"<<endl; 
        }
        else{
            cout<<"Dequeued element : "<<arr[fr]<<endl; 
            fr = (fr+1)%cap ;
            sz-- ;
        }
    }
    int front(){
        if(sz==0){
            cout<<"UNDERFLOW !!"<<endl; 
            return -99999 ;
        }
        return arr[fr] ;
    }
    void display(){
        if(sz==0){
            cout<<"QUEUE is empty"<<endl; 
            return ;
        }
        cout<<"[ " ;
        if(fr <= rear ){
            for(int i=fr ; i<=rear ; i++ ){ 
                cout<<arr[i] ;
                if(i != rear) cout<<", " ;
            }
        } 
        else{
            for(int i=fr ; i<cap ; i++ ){ cout<<arr[i]<<", " ;}
            for(int i=0 ; i<=rear ; i++ ){ 
                cout<<arr[i] ;
                if(i != rear ) cout<<", ";
            }
        }
        cout<<" ]"<<endl ;
    }
};

void menue(){
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"case 1: enqueue "<<endl;
    cout<<"case 2: dequeue "<<endl;
    cout<<"case 3: display "<<endl;
    cout<<"Press any other interger to EXIT"<<endl; 
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"YOUR CHOICE : ";
}

int main(){
    CircularQueue q;
    int choice , val;
    do{
        menue() ; cin>>choice ;
        switch (choice)
        {
        case 1:
            cout<<"Enter the value to be enqueue : " ; cin>>val ;
            q.enqueue(val) ;
            break;
        case 2:
            q.dequeue();
            break ;
        case 3:
            q.display() ;
            break ;
        
        }
    }while(choice<=3 && choice >=1 ) ;
    return 0 ;
}