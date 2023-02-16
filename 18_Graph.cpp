#include<iostream>
#include "./LinkedList.cpp"
#include "./Queue.cpp"
using namespace std;
#define N 7

#define I INT_MAX
int GRAPH2[N+1][N+1]={
    {0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

int GRAPH[N+1][N+1]= {
    {I,I,I,I,I,I,I,I},
    {I,I,25,I,I,I,5,I},
    {I,25,I,12,I,I,I,10},
    {I,I,12,I,8,I,I,I},
    {I,I,I,8,I,16,I,14},
    {I,I,I,I,16,I,20,18},
    {I,5,I,I,I,20,I,I},
    {I,I,10,I,14,18,I,I}
};

void bfs(int start) {
    Queue <int> * q = new Queue<int>();
    q->enqueue(start);
    cout<<start<<" ";
    int * explored=new int[N+1];
    explored[start]=1;
        
    while(!q->isEmpty()) {
        int v=q->dequeue();
        for(int i=1; i<=N; i++) {
            if(!explored[i] && GRAPH[v][i]){
                explored[i]=1;
                cout<<i<<" ";
                q->enqueue(i);
            }    
        }
    }   
    cout<<endl;
}      

int * explored=new int[N+1];
void display(int *arr){
    for(int i=1;i<=N;i++)cout<<arr[i]<<" ";
    cout<<endl;
}
void dfs(int u){ 
    if(!explored[u]) {
        cout<<u<<" ";
        explored[u]=1;
        for(int i=1;i<=N;i++)
            if(GRAPH[u][i] && !explored[i]) dfs(i);
    }
}

void prims() {
    int * near=new int[N+1];
    
    int v=0,u=0,edge=0,minEdge=INT_MAX; 
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) { 
            if(GRAPH[i][j] < minEdge) {
                minEdge=GRAPH[i][j]; 
                v=i;
                u=j;
            }
        }
    } 
    
    int spanningTree[N][2];
    spanningTree[edge][0]=v;
    spanningTree[edge][1]=u;
    edge++;
    near[v]=0;
    near[u]=0;

    for(int i=1;i<=N;i++){
        if(GRAPH[i][v] < GRAPH[i][u])
            near[i]=v;
        else near[i]=u;
    }
    near[v]=0;
    near[u]=0;
    
    while(edge<N-1){
        minEdge=INT_MAX;
        for(int i=1; i<=N; i++)
            if(near[i] && GRAPH[i][near[i]] < minEdge) {
                minEdge=GRAPH[i][near[i]];
                v=i; 
                u=near[i];
            }
        near[v]=0;
        spanningTree[edge][0]=u;
        spanningTree[edge][1]=v;
        edge++;

        for(int i=1;i<=N;i++){
            if(near[i] && GRAPH[i][v] < GRAPH[i][near[i]])
                near[i]=v;
        }
    }

    for(int i=0;i<N-1;i++){
        cout<<spanningTree[i][0]<<" "<<spanningTree[i][1]<<" => ";
    }
    cout<<endl;
}

void wtUnion(int a, int b, int *arr) {
    if(arr[a] < arr[b]) {
        arr[a]=arr[a]+arr[b];
        arr[b]=a;
    } else {
        arr[b]=arr[a]+arr[b];
        arr[a]=b;
    }
}

int find(int u,int* arr){
    while(arr[u]>0) u=arr[u];
    return u;
}

void kruskal(){
    int arr[N][4],k=0;
    
    for(int i=1;i<=N;i++)
        for(int j=i;j<=N;j++){
            if(GRAPH[i][j] != I) {
                arr[k][0]=i;
                arr[k][1]=j;
                arr[k][2]=GRAPH[i][j];
                arr[k++][3]=0;
            }
        }
    for(int i=0;i<k;i++)
        cout<<i<<" - "<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<endl;
    int total=k;    
    int * set = new int[N+1];
    for(int i=0;i<=N;i++) set[i]=-1;
    int spanningTree[N][2];
    
    for(int edge=0;edge<N-1;) {
        cout<<" ------------------ "<<endl;
        int min=INT_MAX,k=0;
        for(int i=0;i<total;i++){
            if(!arr[i][3] && arr[i][2] < min) {
                k=i;
                min=arr[i][2];
            }
        }
        cout<<"k = "<<k<<" ,edge = "<<edge<<endl;
        // <<" , i = "<<arr[k][0]<<" , j =  "<<arr[k][1]<<" , v = " <<arr[k][2]<<", inc = " <<arr[k][3]<<endl;
        arr[k][3]=1;

        int pOfI=find(arr[k][0],set);
        int pOfJ=find(arr[k][1],set);
        cout<<"pOfI = "<<pOfI<<" , pOfJ = "<<pOfJ<<endl;
        // break;
        if( pOfI!=pOfJ ) {
            spanningTree[edge][0]=arr[k][0];
            spanningTree[edge][1]=arr[k][1];
            wtUnion(pOfI,pOfJ,set);
            display(set);
            edge++;
            // break;
        }
        cout<<"Endl"<<endl;
    }

    for(int i=0;i<k;i++)
        cout<<i<<" - "<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<endl;

    for(int i=0; i<N-1; i++) {
        // cout<<spanningTree[i][0] << " "<<spanningTree[i][1]<<" => ";
    }
    cout<<endl;


}
int main() {
    // for(int i=1;i<=N;i++){ 
    //     for(int j=0;j<=N;j++) explored[j]=0;
    //     dfs(i);
    //     cout<<endl;
    // } 
    // prims();
    kruskal();
    return 0;
}