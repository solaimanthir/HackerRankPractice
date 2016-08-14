#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <cstring>

using namespace std;

class Graph {
  int V;
  list<int> *adj;
public:
    Graph(int V);
    void addEdg(int u, int v);
    void BFS(int s, int *dist);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V]; //V+1 since vertex labeled from 1, not the zero
}

void Graph::addEdg(int u, int v)
{
    if(find(adj[u-1].begin(), adj[u-1].end(), v-1) == adj[u-1].end())
        adj[u-1].push_back(v-1);
        
    if(find(adj[v-1].begin(), adj[v-1].end(), u-1) == adj[v-1].end())
        adj[v-1].push_back(u-1);
}
void Graph::BFS(int s, int *dist)
{
    bool * visited = new bool[this->V];
    for(int i = 0; i < this->V; ++i)
        visited[i] = false;
    
    list<int> queue;
    //mark s as visited and enqueue
    visited[s-1] = true;
    queue.push_back(s-1);
    dist[s-1] = 0;
    
    while(!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        list<int>::iterator i;
        
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                dist[*i] = dist[s]+6;
                queue.push_back(*i);
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    short int q;
    cin >> q;
    while(q--) {
        int n, m, s, u, v,  *dist_from_src;
        cin >> n >> m;
        Graph g(n);
        dist_from_src = new int[n];
        for(int i = 0; i < n; ++i){
            dist_from_src[i] = -1;
        }
        for(int i = 1; i <= m; ++i) {
         cin >> u >> v;
         g.addEdg(u, v);
        }
        cin >> s;
        g.BFS(s, dist_from_src);
        for(int i = 0; i < n; ++i){
            if(i != (s-1))
                cout << dist_from_src[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
