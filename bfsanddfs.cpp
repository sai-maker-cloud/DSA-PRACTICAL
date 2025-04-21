#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class edge{
    public:
    int src;
    int dest;
    edge(int s,int d){
        src=s;
        dest=d;
    }
};
class classroom{
    public:
 static   void create(vector<edge>*graph,int e){
        cout<<"enter source and distination:";
        for(int i=0;i<e;i++){
            int src,dest;
            cin>>src>>dest;
            graph[src].push_back(edge(src,dest));
        }
    }
 static   void bfs(vector<edge>*graph,int v){
        queue<int>q;
        vector<bool>visi(v,false);
        q.push(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(visi[curr]==false){
                cout<<curr<<" ";
                visi[curr]=true;
                for(int i=0;i<graph[curr].size();i++){
                    edge e=graph[curr][i];
                    q.push(e.dest);

                }

            }
        }

    }
  static  void dfs(vector<edge>*graph,int curr,vector<bool>& visi){
        cout<<curr<<" ";
    
        visi[curr]=true;
        for(int i=0;i<graph[curr].size();i++){
            edge e=graph[curr][i];
            if (!visi[e.dest]) {
                dfs(graph,e.dest,visi);
            }
        }
    }
};
int main(){
    int v,e,curr;
    cout<<"enter a number of vertices:";
    cin>>v;
    cout<<"enter a number of edges:";
    cin>>e;
    vector<edge>*graph=new vector<edge>[v];
   classroom:: create(graph,e);
   cout<<"bfs traversal:";
   classroom::bfs(graph,v);
   cout<<"dfs traversal:";
   vector<bool> visi(v, false);
   classroom::dfs(graph,0,visi);
   return 0;

}
