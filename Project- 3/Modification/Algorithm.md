# Algorithm

## A. Add a Pipeline
1. Start.
2. Input two tank numbers `u` and `v`.
3. Set `adj[u][v] = 1` and `adj[v][u] = 1`.
4. Display the updated adjacency matrix.

## B. Remove a Damaged Pipeline
1. Input two tank numbers `u` and `v`.
2. Set `adj[u][v] = 0` and `adj[v][u] = 0`.
3. Display the revised adjacency matrix.

## C. Display Directly Connected Tanks
1. Input the selected tank number `u`.
2. Traverse row `u` of the adjacency matrix.
3. If `adj[u][i] == 1`, display tank `i`.
4. If no connection exists, display "None".

5. Stop.
