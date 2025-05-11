#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> revAdj;

    void fillOrder(int v, vector<bool>& visited, stack<int>& st) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                fillOrder(u, visited, st);
            }
        }
        st.push(v);
    }

    void DFSUtil(int v, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        
        for (int u : revAdj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited, component);
            }
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
        revAdj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        revAdj[w].push_back(v);
    }

    vector<vector<int>> findSCCs() {
        stack<int> st;
        vector<bool> visited(V, false);
        vector<vector<int>> sccs;

        // First DFS to fill the stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                fillOrder(i, visited, st);
            }
        }

        // Reset visited array for second DFS
        fill(visited.begin(), visited.end(), false);

        // Second DFS to find SCCs
        while (!st.empty()) {
            int v = st.top();
            st.pop();

            if (!visited[v]) {
                vector<int> component;
                DFSUtil(v, visited, component);
                sccs.push_back(component);
            }
        }

        return sccs;
    }
};

int main() {
    // Example usage
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    vector<vector<int>> sccs = g.findSCCs();

    cout << "Strongly Connected Components:\n";
    for (int i = 0; i < sccs.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int v : sccs[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
} 