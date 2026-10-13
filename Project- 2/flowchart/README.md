flowchart TD
    A([Start]) --> B[Initialize empty AVL tree]
    B --> C[Insert elements 30, 20, 10]
    C --> D[Update node heights]
    D --> E[Calculate balance factors]
    E --> F{LL imbalance at node 30?}
    F -- Yes --> G[Detect LL imbalance]
    G --> H[Perform right rotation at node 30]
    H --> I[Set node 20 as root]
    I --> J[Set 10 as left child and 30 as right child]
    J --> K[Display balanced AVL tree]
    F -- No --> K
    K --> L[Display inorder traversal]
    L --> M([Stop])

    style A fill:#ffffff,stroke:#000000,color:#000000
    style B fill:#ffffff,stroke:#000000,color:#000000
    style C fill:#ffffff,stroke:#000000,color:#000000
    style D fill:#ffffff,stroke:#000000,color:#000000
    style E fill:#ffffff,stroke:#000000,color:#000000
    style F fill:#ffffff,stroke:#000000,color:#000000
    style G fill:#ffffff,stroke:#000000,color:#000000
    style H fill:#ffffff,stroke:#000000,color:#000000
    style I fill:#ffffff,stroke:#000000,color:#000000
    style J fill:#ffffff,stroke:#000000,color:#000000
    style K fill:#ffffff,stroke:#000000,color:#000000
    style L fill:#ffffff,stroke:#000000,color:#000000
    style M fill:#ffffff,stroke:#000000,color:#000000
