#include <bits/stdc++.h>
using namespace std ; 

void maxHeapify(vector<int>&arr, int n, int i ){
    int largest = i ;
    int leftChild = 2*i+1 ;
    int rightChild = 2*i+2 ;

    if(leftChild<n && arr[leftChild]>arr[largest]) largest = leftChild ;
    if(rightChild<n && arr[rightChild]>arr[largest]) largest = rightChild ;

    if(largest != i){
        swap(arr[i],arr[largest]) ;
        maxHeapify(arr,n,largest) ;
    }

}

void heapSortAscending(vector<int>&arr){
    int n = arr.size() ;

    for(int i=n/2-1 ; i>=0 ; i-- ) maxHeapify(arr,n,i) ;

    for(int i=n-1 ; i>0 ; i-- ){
        swap(arr[0],arr[i]) ;
        maxHeapify(arr,i,0) ;
    }

}

void minHeapify(vector<int>&arr , int n, int i){

    int smallest = i ;
    int l=2*i+1 ;
    int r=2*i+2 ;
    
    if(l<n && arr[l]<arr[smallest]) smallest=l ;
    if(r<n && arr[r]<arr[smallest]) smallest=r ;

    if(smallest != i){
        swap(arr[i],arr[smallest]) ;
        minHeapify(arr,n,smallest) ;
    }

}

void heapSortDescending(vector<int>&arr ){
    int n=arr.size() ;

    for(int i=n/2-1 ; i>=0 ; i-- ) minHeapify(arr,n,i) ;

    for(int i=n-1 ; i>0 ; i--){
        swap(arr[0],arr[i]) ;
        minHeapify(arr,i,0) ;
    }
}

void print(vector<int>& arr ){
    cout<<"Sorted array after heap sort : "<<endl; 
    for(int i: arr) cout<<i<<" ";
    cout<<endl; 
}

void menue(){
    cout<<"------------------------------------=-------------------------------"<<endl; 
    cout<<"case 1 : sort using min heap(Descending order) "<<endl ;
    cout<<"case 2 : sort using max heap(Ascending ordrer )"<<endl; 
    cout<<"Press any other digit to EXIT "<<endl ;
    cout<<"------------------------------------=-------------------------------"<<endl; 
    cout<<"YOUR CHOICE : " ;
}

int main(){
    int chioce,n,val; 
    do{
        menue() ; cin>>chioce ;
        switch (chioce)
        {
        case 1:{
            cout<<"Enter the no of elements in array : "; cin>>n ;
            vector<int>arr(n) ;
            cout<<"Enter "<<n<<" elements : ";
            for(auto &i : arr ) cin>>i ;
            heapSortDescending(arr);
            print(arr) ;
            break;
        }
        case 2:{
            cout<<"Enter the no of elements in array : "; cin>>n ;
            vector<int>arr(n) ;
            cout<<"Enter "<<n<<" elements : ";
            for(auto &i : arr ) cin>>i ;
            heapSortAscending(arr);
            print(arr) ;
            break;
        }

        }
    }while(chioce<=2 && chioce>=1) ;
    cout<<"Program EXITTED Successfully :)"<<endl; 
    return 0 ;
}