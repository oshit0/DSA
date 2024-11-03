#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define endl '\n'

using namespace std;

void add_edge(vector<pair <int, int>> adj[], int v, int u, int wt){
    adj[v].push_back(make_pair(wt * -1, u));
    adj[u].push_back(make_pair(wt * -1, v));
}

void print_adj_list(const vector<pair <int, int>> adj[], int V){
    cout << "Vertices and Edges:" << endl;
    for(int v = 0; v < V; ++v){
        for(auto it = adj[v].begin(); it != adj[v].end(); ++it){
            cout << v << "->";
            cout << it->second << ' ' << "Weight: " << it->first * -1 << endl;
        }
    }
}

void print_min_heap(priority_queue<pair <int, int>> min_heap){
    while(!min_heap.empty()){
        cout << min_heap.top().second << ' ' << "Weight: " << min_heap.top().first * -1 << endl;
        min_heap.pop();
    }
    cout << endl;
}

void dijkstra(vector<pair <int, int>> adj[], int origin, int V){
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);
    priority_queue<pair <int, int>> min_heap;

    distance[origin] = 0;
    min_heap.push(make_pair(distance[origin], origin));

    while(!min_heap.empty()){
        int v = min_heap.top().second;
        min_heap.pop();

        if(visited[v]) continue;
        else visited[v] = true;

        for(const auto& edge : adj[v]){
            int weight = edge.first * -1;
            int u = edge.second;
            if(!visited[u] && distance[v] + weight < distance[u]){
                distance[u] = distance[v] + weight;
                min_heap.push(make_pair(-distance[u], u));
            }
        }
    }
    for (size_t i = 0; i < distance.size(); i++){
        cout << "Distance from source to " << i << " is: " << distance[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //Vertices
    const int V = 5;
    //Adjacency List
    vector<pair <int, int>> adj[V];

    //Init
    add_edge(adj, 0, 1, 7);
    add_edge(adj, 0, 2, 1);
    add_edge(adj, 1, 2, 8);
    add_edge(adj, 1, 3, 3);
    add_edge(adj, 2, 3, 2);
    add_edge(adj, 2, 4, 7);
    print_adj_list(adj, V);
    dijkstra(adj, 0, V);


    return 0;
}