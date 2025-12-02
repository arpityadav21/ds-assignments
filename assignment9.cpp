#include <iostream>
using namespace std;
#define INF 10000
int adj[100][100];
int parentArr[100];
void BFS(int V, int start) {
    int queue[100], front = 0, rear = 0;
    int visited[100] = {0};
    visited[start] = 1;
    queue[rear++] = start;
    cout << "BFS: ";
    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";
        for (int i = 0; i < V; i++) {
            if (adj[node][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}
void DFSUtil(int V, int node, int visited[]) {
    visited[node] = 1;
    cout << node << " ";
    for (int i = 0; i < V; i++) {
        if (adj[node][i] != 0 && !visited[i])
            DFSUtil(V, i, visited);
    }
}
void DFS(int V, int start) {
    int visited[100] = {0};
    cout << "DFS: ";
    DFSUtil(V, start, visited);
    cout << endl;
}
int findSet(int x) {
    if (parentArr[x] == x)
        return x;
    return parentArr[x] = findSet(parentArr[x]);
}
void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    parentArr[b] = a;
}
void Kruskal(int V) {
    int edges = 0, mst_cost = 0;
    for (int i = 0; i < V; i++) parentArr[i] = i;
    cout << "Kruskal MST:\n";
    while (edges < V - 1) {
        int u = -1, v = -1, minW = INF;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] != 0 && adj[i][j] < minW &&
                    findSet(i) != findSet(j)) {
                    minW = adj[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        if (u != -1 && v != -1) {
            cout << u << " -- " << v << " weight " << minW << endl;
            mst_cost += minW;
            unionSet(u, v);
            edges++;
        }
    }
    cout << "Total cost = " << mst_cost << "\n\n";
}
void Prim(int V, int start) {
    int key[100], visited[100] = {0}, parent[100];
    for (int i = 0; i < V; i++)
        key[i] = INF, parent[i] = -1;
    key[start] = 0;
    cout << "Prim MST:\n";
    for (int k = 0; k < V - 1; k++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " -- " << i << " weight " << key[i] << endl;
            total += key[i];
        }
    }
    cout << "Total cost = " << total << "\n\n";
}
void Dijkstra(int V, int start) {
    int dist[100], visited[100] = {0};
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[start] = 0;
    for (int k = 0; k < V; k++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 &&
                dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    cout << "Dijkstra distances:\n";
    for (int i = 0; i < V; i++)
        cout << "Node " << i << ": " << dist[i] << endl;
}
int main() {
    int V = 6;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    adj[0][1] = 4; adj[1][0] = 4;
    adj[0][2] = 3; adj[2][0] = 3;
    adj[1][2] = 1; adj[2][1] = 1;
    adj[1][3] = 2; adj[3][1] = 2;
    adj[2][3] = 4; adj[3][2] = 4;
    adj[3][4] = 2; adj[4][3] = 2;
    adj[4][5] = 6; adj[5][4] = 6;
    BFS(V, 0);
    DFS(V, 0);
    cout << endl;
    Kruskal(V);
    Prim(V, 0);
    Dijkstra(V, 0);
    return 0;
}

