#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];  /* Adjacency matrix */
int n;              /* Number of vertices in the graph */

int main() {
    int max_edges, i, j, origin, destin;
    int graph_type;

    /* Initialize the adjacency matrix to 0 */
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter 1 for undirected graph or 2 for directed graph: ");
    scanf("%d", &graph_type);

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    /* Determine maximum edges based on graph type */
    if(graph_type == 1)
        max_edges = n * (n - 1) / 2;  /* Undirected graph */
    else
        max_edges = n * (n - 1);      /* Directed graph */

    for(i = 1; i <= max_edges; i++) {
        printf("Enter edge %d ( -1 -1 to quit ): ", i);
        scanf("%d %d", &origin, &destin);

        /* Break condition if user wants to stop input */
        if((origin == -1) && (destin == -1))
            break;

        /* Check if the entered vertices are valid */
        if(origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid vertex! Please enter valid vertices between 0 and %d\n", n-1);
            i--;  /* Don't count this invalid input as a valid edge */
        } else {
            adj[origin][destin] = 1;  /* Mark the edge in the adjacency matrix */
            if(graph_type == 1) {
                adj[destin][origin] = 1;  /* If undirected graph, add reverse edge */
            }
        }
    }

    /* Display the adjacency matrix */
    printf("The adjacency matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%4d", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}



Enter 1 for undirected graph or 2 for directed graph: 1
Enter number of vertices: 4
Enter edge 1 ( -1 -1 to quit ): 0 1
Enter edge 2 ( -1 -1 to quit ): 0 2
Enter edge 3 ( -1 -1 to quit ): 1 2
Enter edge 4 ( -1 -1 to quit ): 1 3
Enter edge 5 ( -1 -1 to quit ): -1 -1
