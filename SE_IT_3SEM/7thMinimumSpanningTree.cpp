#include <bits/stdc++.h>
using namespace std ; 

struct edge
{
    int u,v,w;
    edge(int u,int v, int w){
        this->u = u ;
        this->v = v ;
        this->w = w ;
    }
};

struct comp
{
    bool operator()(edge e1, edge e2 ){
        return e1.w > e2.w ;
    }
};

void prims(vector<pair<int,int>>adj[], int n){
    int mst=0 ;
    vector<bool>vis(n+1,0) ;
    priority_queue< edge , vector<edge> , comp > pq ;

    pq.push({1,-1,0}) ; // {node, parent , edge Weight }

    cout<<"Edges in prims MST : "<<endl; 
    
    while(!pq.empty()){
        int u = pq.top().u ;
        int v = pq.top().v ;
        int w = pq.top().w ;
        pq.pop() ;

        if(vis[u]) continue;
        vis[u] = 1 ;
        if(v != -1 ) {
            cout<<u<<" - "<<v<<" : "<<w<<endl; 
            mst += w ;
        }

        // for(auto edg : adj[u]){
        //     int adjNode = edg.first ;
        //     int edw = edg.second ;
        //     if(!vis[adjNode]){
        //         pq.push(edge(adjNode,u,edw)) ;
        //     } 
        // }

        for(int i=0 ; i<adj[u].size() ; i++ ){
            int adjNode = adj[u][i].first ;
            int edw = adj[u][i].second ;
            if(!vis[adjNode]){
                pq.push(edge(adjNode,u,edw)) ;
            }
        }

    }

    cout<<"Prims MST value : "<<mst<<endl;
}

int findParent(vector<int>&parent, int v){
    if(v==parent[v] ) return v ;
    return parent[v]=findParent(parent,parent[v]) ;
}

void krushkal(vector<pair<int,int>>adj[], int n){
    int mst=0 ;
    vector<edge>edges;
    for(int i=1 ; i<=n ; i++ ){
        for(auto edg : adj[i]){
            if(i<edg.first) edges.push_back(edge(i,edg.first,edg.second)) ;
        }
    }
    sort(edges.begin(),edges.end(),[](const edge& e1, const edge& e2){
        return e1.w<e2.w ;
    });
    vector<int>parent(n+1) ;
    for(int i=0 ; i<=n ; i++ ) parent[i]=i ;

    cout<<"Edges in Krushkal MST : "<<endl; 
    for(auto edg : edges){
        int u=edg.u ;
        int v=edg.v ;
        int w = edg.w ;
        if(findParent(parent,u) != findParent(parent,v) ) {
            cout<<u<<" - "<<v<<" : "<<w<<endl; 
            mst += w ;
            parent[findParent(parent,u)] = parent[findParent(parent,v)] ;
        }
    }
    cout<<"Krushkal MST value : "<<mst<<endl; 

}

void menue(){
    cout<<"--------------------------------------------------"<<endl;
    cout<<"case 1 : Find MST using Prim's algo."<<endl; 
    cout<<"case 2 : Find MST using Krushkal's algo."<<endl; 
    cout<<"case 3 : To print the Adjacency List "<<endl; 
    cout<<"Press any other digit to EXIT "<<endl ;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"YOUR CHOICE : " ;
}

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

int main(){
    int n,m ; // no of nodes, no of edges 
    cout<<"Enter the no of nodes : " ; cin>>n;
    cout<<"Enter the no of edges : " ; cin>>m ;
    vector<pair<int,int>>adj[n+1] ;
    for(int i=0 ; i<m ; i++ ){
        int u,v,w ;
        cout<<"Enter nodes (1 to "<<n<<") of the edge and edge weight : ";cin>>u>>v>>w ;
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;
    }
    int choice;
    do{
        menue() ; cin>>choice ;
        switch (choice)
        {
        case 1:
            prims(adj,n) ;
            break;
        case 2:
            krushkal(adj,n) ;
            break ;
        case 3:
            print(adj,n) ;
            break ;
        }
    }while(choice>=1 && choice<=3 ) ;

    cout<<"Program EXITTED Successfully :)"<<endl; 
    return 0 ; 
}