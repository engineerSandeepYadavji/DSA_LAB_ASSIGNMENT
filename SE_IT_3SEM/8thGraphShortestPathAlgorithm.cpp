#include <bits/stdc++.h>
using namespace std ;

void print(vector<pair<int,int>>adj[],int n){
    cout<<"Adjacency List (node , edge weighht ) : "<<endl; 
    for(int i=1 ; i<=n ; i++ ){
        if(adj[i].size()) cout<<i<<" : " ;
        for(auto edge: adj[i]){
            cout<<"("<<edge.first<<", "<<edge.second<<")"<<" ";
        }
        if(adj[i].size()) cout<<endl; 
    }
}

void dijkstra(vector<pair<int,int>>adj[], int n){
    int source; 
    cout<<"Enter the source node : " ; cin>>source ;
    vector<int>dist(n+1,1e9) ;
    dist[source]=0 ;
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ; // {dist,node}
    pq.push({0,source}) ;
    while(!pq.empty()){
        int u = pq.top().second ;
        int w = pq.top().first ;
        pq.pop() ;

        if(w > dist[u] ) continue; 

        // for(auto edg : adj[u]){
        //     int v = edg.first ;
        //     int wt = edg.second ;
        //     if(dist[u]+wt < dist[v]){
        //         dist[v] = dist[u]+wt ;
        //         pq.push({dist[v],v}) ;
        //     }
        // }
        for(int i=0 ; i<adj[u].size() ; i++ ){
            int v = adj[u][i].first ;
            int wt = adj[u][i].second ;
            if(dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt ;
                pq.push({dist[v],v}) ;
            }
        }


    }
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " : ";
        if (dist[i] >= 1e9 )
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }
}

void menue(){
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"case 1 : Print adjacency List "<<endl; 
    cout<<"case 2 : To find shortest distance "<<endl ;
    cout<<"Press any other digit to EXIT "<<endl ;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"YOUR CHOICE : " ;
}

int main(){
    int n,m ;
    cout<<"Enter the no of vertices : "; cin>>n ;
    cout<<"Enter the no of edges : "; cin>>m ;
    vector<pair<int,int>>adj[n+1] ;
    for(int i=0 ; i<m ; i++ ){
        int u,v,w ; 
        cout<<"Enter the edge(1 to "<<n<<") and edge weight : " ; cin>>u>>v>>w ;
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ; 
    }
    int choice ;
    do{
        menue() ; cin>>choice ;
        switch(choice){
            case 1:
                print(adj,n) ;
                break ;
            case 2: 
                dijkstra(adj,n) ;
                break;
        }
    }while(choice <=2 && choice >=1 ) ;

    return 0 ;
}