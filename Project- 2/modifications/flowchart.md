flowchart TD
    A([Start]) --> B[Initialize empty AVL tree]
    B --> C[Insert 50, 40, 30]
    C --> D[Update node heights]
    D --> E[Calculate balance factors]
    E --> F{LL imbalance detected?}
    F -- No --> G[Continue insertion]
    G --> D
    F -- Yes --> H[Display tree before rotation]
    H --> I[Print balance factors before rotation]
    I --> J[Perform right rotation]
    J --> K[Display tree after rotation]
    K --> L[Print balance factors after rotation]
    L --> M[Display inorder traversal]
    M --> N[Display root node and balance factor]
    N --> O([Stop])
