#include <iostream>
#include <queue>
using namespace std;
#define MAX 10  // Maximum number of vertices
#define TRUE 1
#define FALSE 0

// Class representing the graph using an adjacency list
class Graph {
private:
    struct Node {
        int vertex;
        Node* next;
    };
    
    Node* head[MAX]; // Adjacency list array
    int visited[MAX]; // Visited array for DFS and BFS

public:
    Graph();  
    void create();  
    void dfs(int);  
    void bfs(int);  
};

// Constructor: Initializes adjacency list and visited array
Graph::Graph() {
    for (int i = 0; i < MAX; i++) {
        head[i] = NULL;
        visited[i] = FALSE;
    }
}

// Function to create the graph using an adjacency list
void Graph::create() {
    int v1, v2;
    char ans;
    
    cout << "Enter the vertices starting from 0: \n";
    do {
        cout << "Enter an edge (v1 v2): ";
        cin >> v1 >> v2;

        if (v1 >= MAX || v2 >= MAX) {
            cout << "Invalid Vertex Value!!\n";
        } else {
            // Creating link from v1 to v2
            Node* newNode = new Node{v2, head[v1]};
            head[v1] = newNode;

            // Creating link from v2 to v1 (Undirected Graph)
            newNode = new Node{v1, head[v2]};
            head[v2] = newNode;
        }

        cout << "Want to add more edges? (y/n): ";
        cin >> ans;
    } while (ans == 'y');
}

// Depth First Search (DFS) - Recursive
void Graph::dfs(int v) {
    cout << v << " ";  
    visited[v] = TRUE;

    Node* temp = head[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }
}

// Breadth First Search (BFS) - Using Queue
void Graph::bfs(int start) {
    queue<int> q;
    for (int i = 0; i < MAX; i++)
        visited[i] = FALSE;  // Reset visited array

    visited[start] = TRUE;
    q.push(start);

    cout << "\nBFS Traversal: ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        Node* temp = head[v];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = TRUE;
                q.push(temp->vertex);
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

int main() {
    Graph g;
    g.create();

    int start;
    cout << "\nEnter the starting vertex for DFS: ";
    cin >> start;
    
    if (start >= MAX) {
        cout << "Invalid Vertex!\n";
    } else {
        cout << "DFS Traversal: ";
        g.dfs(start);
        cout << endl;
    }

    cout << "\nEnter the starting vertex for BFS: ";
    cin >> start;
    
    if (start >= MAX) {
        cout << "Invalid Vertex!\n";
    } else {
        g.bfs(start);
    }

    return 0;
}c13