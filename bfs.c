#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INITIAL 1
#define WAITING 2
#define VISITED 3

int n; // Number of vertices in the graph
int adj[MAX][MAX]; // Adjacency Matrix
int state[MAX]; // can be initial, waiting or visited

void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1, rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main() {
    create_graph();
    BF_Traversal();
    return 0; // Properly return from main
} // End of main()

void BF_Traversal() {
    int v;

    for (v = 0; v < n; v++) {
        state[v] = INITIAL; // Initialize all vertices as initial state
    }

    printf("Enter starting vertex for Breadth First Search: ");
    scanf("%d", &v);
    if (v >= 0 && v < n) {
        BFS(v);
    } else {
        printf("Invalid starting vertex!\n");
        return;
    }

    // Perform BFS for any unvisited vertices
    for (v = 0; v < n; v++) {
        if (state[v] == INITIAL) {
            BFS(v);
        }
    }
} // End of BF_Traversal()

void BFS(int v) {
    int i;

    insert_queue(v);
    state[v] = WAITING; // Mark as waiting

    while (!isEmpty_queue()) {
        v = delete_queue();
        printf("%d ", v);
        state[v] = VISITED; // Mark as visited

        for (i = 0; i < n; i++) {
            // Check for adjacent unvisited vertices
            if (adj[v][i] == 1 && state[i] == INITIAL) {
                insert_queue(i);
                state[i] = WAITING; // Mark as waiting
            }
        }
    }
    printf("\n");
} // End of BFS()

void insert_queue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0; // If queue is initially empty
        }
        rear = rear + 1;
        queue[rear] = vertex;
    }
} // End of insert_queue()

int isEmpty_queue() {
    return (front == -1 || front > rear);
} // End of isEmpty_queue()

int delete_queue() {
    if (isEmpty_queue()) {
        printf("Queue Underflow\n");
        exit(1);
    }

    int del_item = queue[front];
    front = front + 1;
    return del_item;
} // End of delete_queue()

void create_graph() {
    int i, max_edges, origin, destin;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    max_edges = n * (n - 1); // For directed graph

    // Initialize the adjacency matrix
    for (i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }

    for (i = 1; i <= max_edges; i++) {
        printf("Enter edge %d ( -1 -1 to quit ): ", i);
        scanf("%d %d", &origin, &destin);

        if ((origin == -1) && (destin == -1)) break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            i--; // Decrement i to repeat the edge input
        } else {
            adj[origin][destin] = 1; // For directed graph
            // Uncomment the next line if the graph is undirected
            // adj[destin][origin] = 1; 
        }
    } // End of for
} // End of create_graph()








Enter number of vertices: 5
Enter edge 1 ( -1 -1 to quit ): 0 1
Enter edge 2 ( -1 -1 to quit ): 0 2
Enter edge 3 ( -1 -1 to quit ): 1 3
Enter edge 4 ( -1 -1 to quit ): 1 4
Enter edge 5 ( -1 -1 to quit ): -1 -1
Enter starting vertex for Breadth First Search: 0
0 1 2 3 4 
