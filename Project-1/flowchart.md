# System Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Display Main Menu]
    B --> C{Select Operation}

    C -->|1. Add Component| D[Enter Component Details]
    D --> E[Store Component]
    E --> B

    C -->|2. Display Components| F[Display All Components]
    F --> B

    C -->|3. Search Component| G[Enter Component ID]
    G --> H{Component Found?}
    H -->|Yes| I[Display Component Details]
    H -->|No| J[Display Component Not Found]
    I --> B
    J --> B

    C -->|4. Update Status| K[Select Component]
    K --> L[Update Stage and Status]
    L --> M[Record Processing History]
    M --> B

    C -->|5. Delete Component| N[Select Component]
    N --> O[Remove Component]
    O --> B

    C -->|6. Add to Queue| P[Add Component to Queue]
    P --> B

    C -->|7. Process Queue| Q[Remove Component from Front]
    Q --> R[Process Component]
    R --> M

    C -->|8. Display Queue| S[Display Waiting Components]
    S --> B

    C -->|9. Display History| T[Display Processing History]
    T --> B

    C -->|10. Remove History| U[Remove Latest History Entry]
    U --> B

    C -->|0. Exit| V([End])
