#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For memset if needed, though not strictly for this version

#define MAX_VERTICES 101 // n <= 100, 1-based indexing
#define MAX_EDGES 5000   // Max m for n=100 is 100*99/2 = 4950

typedef struct {
    int u, v, weight;
} Edge;

// DSU (Disjoint Set Union) data
int parent[MAX_VERTICES];
int sz[MAX_VERTICES]; // For union by size optimization

// Comparison function for qsort
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    if (edgeA->weight < edgeB->weight) return -1;
    if (edgeA->weight > edgeB->weight) return 1;
    // Optional: if weights are equal, sort by u, then v for deterministic output
    // if (edgeA->u < edgeB->u) return -1;
    // if (edgeA->u > edgeB->u) return 1;
    // if (edgeA->v < edgeB->v) return -1;
    // if (edgeA->v > edgeB->v) return 1;
    return 0;
}

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // Path compression
}

// Returns 1 if union was successful, 0 otherwise
int unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) { // Union by size
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        sz[a] += sz[b];
        return 1;
    }
    return 0;
}

int main() {
    FILE *inputFile, *outputFile;
    int n, m;
    Edge edges[MAX_EDGES];
    Edge mst_edges[MAX_VERTICES -1]; // Max n-1 edges in MST

    inputFile = fopen("CK.INP", "r");
    if (inputFile == NULL) {
        // Attempt to write 0 to output if input file fails to open
        outputFile = fopen("CK.OUT", "w");
        if (outputFile != NULL) {
            fprintf(outputFile, "0\n");
            fclose(outputFile);
        }
        return 1; // Indicate error
    }

    fscanf(inputFile, "%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        fscanf(inputFile, "%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    fclose(inputFile);

    // Handle n=0 case specifically as per problem constraints (n is positive integer)
    // However, if n could be 0, or if n=1 and m=0.
    if (n == 0) {
        outputFile = fopen("CK.OUT", "w");
        if (outputFile != NULL) {
            fprintf(outputFile, "0\n");
            fclose(outputFile);
        }
        return 0;
    }
    
    // Sort edges by weight
    qsort(edges, m, sizeof(Edge), compareEdges);

    // Initialize DSU
    for (int i = 1; i <= n; ++i) {
        make_set(i);
    }

    int total_weight = 0;
    int edges_in_mst = 0;

    for (int i = 0; i < m; ++i) {
        if (unite_sets(edges[i].u, edges[i].v)) {
            mst_edges[edges_in_mst] = edges[i];
            total_weight += edges[i].weight;
            edges_in_mst++;
            if (n > 0 && edges_in_mst == n - 1) { // MST is complete
                break;
            }
        }
    }

    outputFile = fopen("CK.OUT", "w");
    if (outputFile == NULL) {
        // Error opening output file
        return 1; // Indicate error
    }

    // Check if a valid MST was formed
    // For n=1, MST has 0 edges.
    // For n>1, MST must have n-1 edges.
    if ((n == 1 && edges_in_mst == 0) || (n > 1 && edges_in_mst == n - 1)) {
        fprintf(outputFile, "%d\n", total_weight);
        for (int i = 0; i < edges_in_mst; ++i) {
            fprintf(outputFile, "%d %d %d\n", mst_edges[i].u, mst_edges[i].v, mst_edges[i].weight);
        }
    } else {
        // Graph is not connected or no MST found (or n=0 handled earlier)
        fprintf(outputFile, "0\n");
    }

    fclose(outputFile);
    return 0;
}
