#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Define a structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int num_vertices;
    Node** adj_lists;
} Graph;

// Function to create a new adjacency list node
Node* create_node(int vertex) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

// Function to create a graph with a given number of vertices
Graph* create_graph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    graph->adj_lists = (Node**)malloc(vertices * sizeof(Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adj_lists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* new_node = create_node(dest);
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;

    // Add an edge from dest to src (because it's an undirected graph)
    new_node = create_node(src);
    new_node->next = graph->adj_lists[dest];
    graph->adj_lists[dest] = new_node;
}

// DFS recursive function
void dfs(Graph* graph, int vertex, int* visited) {
    // Mark the current node as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    Node* adj_list = graph->adj_lists[vertex];
    while (adj_list != NULL) {
        int adjacent_vertex = adj_list->vertex;
        if (!visited[adjacent_vertex]) {
            dfs(graph, adjacent_vertex, visited);
        }
        adj_list = adj_list->next;
    }
}

// BFS iterative function
void bfs(Graph* graph, int start_vertex) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the start vertex as visited and enqueue it
    visited[start_vertex] = 1;
    queue[rear++] = start_vertex;

    while (front != rear) {
        int current_vertex = queue[front++];
        printf("%d ", current_vertex);

        // Get all adjacent vertices of the dequeued vertex
        Node* adj_list = graph->adj_lists[current_vertex];
        while (adj_list != NULL) {
            int adjacent_vertex = adj_list->vertex;
            if (!visited[adjacent_vertex]) {
                visited[adjacent_vertex] = 1;
                queue[rear++] = adjacent_vertex;
            }
            adj_list = adj_list->next;
        }
    }
}

// Main function
int main() {
    Graph* graph = create_graph(6);

    // Adding edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 5);

    printf("DFS Traversal starting from vertex 0:\n");
    int visited[MAX_VERTICES] = {0};  // Array to keep track of visited nodes for DFS
    dfs(graph, 0, visited);

    printf("\nBFS Traversal starting from vertex 0:\n");
    bfs(graph, 0);

    return 0;
}
