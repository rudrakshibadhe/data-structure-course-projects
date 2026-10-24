```mermaidflowchart TD
    A([START]) --> B[Initialize adjacency matrix with 0]
    B --> C[/Input number of water tanks and pipelines/]
    C --> D[/Input pipeline connections/]
    D --> E[Set adj[u][v] = 1 and adj[v][u] = 1]
    E --> F[Display adjacency matrix]
    F --> G[Find direct pipeline connections]
    G --> H[Display connected tank pairs]
    H --> I([STOP])
```
