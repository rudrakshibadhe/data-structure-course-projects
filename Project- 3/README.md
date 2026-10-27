# Water Tank Network Using Adjacency Matrix

## 1. Project Overview
This project represents water tanks as vertices and pipelines as edges using a graph in C++. An adjacency matrix stores the connections between tanks. The program displays the matrix and identifies direct pipeline connections.

The modified program also allows users to add pipelines, remove damaged pipelines, and find tanks directly connected to a selected tank.

## 2. Problem Statement
Develop a C++ program to represent water tanks as vertices and pipelines as edges. Apply an adjacency matrix to store the network, accept the tanks and pipeline connections, display the matrix, and show which tanks have direct pipeline connections.

## 3. Objectives
- Represent a water distribution network using a graph.
- Store connections using an adjacency matrix.
- Display the adjacency matrix.
- Identify directly connected tanks.
- Add new pipelines and update the matrix.
- Remove damaged pipelines.
- Display tanks directly connected to a selected tank.

## 4. Technologies Used
- Language: C++
- Data Structure: Graph
- Representation: Adjacency Matrix
- Compiler: GCC / Code::Blocks / Dev-C++
- Platform: GitHub

## 5. Graph Representation
- **Vertices:** Water tanks.
- **Edges:** Pipelines connecting tanks.
- **1:** A direct pipeline exists.
- **0:** No direct pipeline exists.

The graph is undirected because each pipeline connection is stored in both directions.

## 6. Original Algorithm
1. START
2. Initialize the adjacency matrix with 0.
3. Input the number of tanks and pipelines.
4. Input pipeline connections.
5. Set `adj[u][v] = 1` and `adj[v][u] = 1`.
6. Display the adjacency matrix.
7. Find and display direct pipeline connections.
8. STOP

## 7. Modifications

### A. Add a Pipeline
1. Input two tank numbers.
2. Validate the tank numbers.
3. Set both corresponding matrix entries to 1.
4. Display the updated matrix.

### B. Remove a Damaged Pipeline
1. Input the two tank numbers.
2. Check whether the pipeline exists.
3. Set both corresponding matrix entries to 0.
4. Display the revised matrix.

### C. Display Directly Connected Tanks
1. Input the selected tank number.
2. Traverse its row in the adjacency matrix.
3. Display tank numbers whose matrix value is 1.
4. If no connections exist, display `None`.

## 8. Modified Algorithm
1. START
2. Initialize the adjacency matrix with 0.
3. Input the number of tanks and existing pipelines.
4. Display the menu of operations.
5. Add a pipeline by setting both matrix entries to 1.
6. Remove a pipeline by setting both matrix entries to 0.
7. Display directly connected tanks by checking the selected tank's row.
8. Display the adjacency matrix when required.
9. Repeat the menu until Exit is selected.
10. STOP

## 9. Sample Input
```text
Enter number of water tanks: 4
Enter number of pipelines: 3

Enter pipeline connections:
0 1
0 2
1 3
```

## 10. Original Output
```text
Adjacency Matrix:
0 1 1 0
1 0 0 1
1 0 0 0
0 1 0 0

Direct Pipeline Connections:
Tank 0 is connected to Tank 1
Tank 0 is connected to Tank 2
Tank 1 is connected to Tank 3
```

## 11. Modified Outputs

### A. Add a Pipeline
Add a pipeline between Tank 2 and Tank 3.

```text
Pipeline added successfully.

Updated Adjacency Matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
```

### B. Remove a Damaged Pipeline
Remove the pipeline between Tank 0 and Tank 1.

```text
Pipeline removed successfully.

Revised Adjacency Matrix:
0 0 1 0
0 0 0 1
1 0 0 1
0 1 1 0
```

### C. Display Directly Connected Tanks
Select Tank 2.

```text
Tanks directly connected to Tank 2: 0 3
```

## 12. How to Run
1. Save the C++ program as `main.cpp`.
2. Open a terminal in the project directory.
3. Compile the program:

```bash
g++ main.cpp -o water_tank
```

4. Run on Linux or macOS:

```bash
./water_tank
```

5. On Windows, run:

```bash
water_tank.exe
```

6. Enter the required details and select an operation from the menu.

## 13. Applications
- Water distribution network management.
- Pipeline connection monitoring.
- Identification of directly connected tanks.
- Planning pipeline additions and removals.
- Basic infrastructure network analysis.

## 14. Advantages
- Simple graph representation.
- Easy checking of direct connections.
- Supports adding and removing pipelines.
- Clearly displays network connections.

## 15. Limitations
- Supports a maximum of 20 tanks.
- Requires `O(V²)` space for the adjacency matrix.
- Does not calculate water pressure or flow rate.
- Assumes pipelines are bidirectional.

## 16. Future Scope
- Store pipeline lengths and capacities.
- Find alternative routes between tanks.
- Detect disconnected tanks and pipeline failures.
- Use weighted graphs for distance and cost.
- Extend the program to larger water distribution networks.

## 17. Conclusion
This project demonstrates the use of graphs and adjacency matrices to represent a water distribution network. The modified program supports adding pipelines, removing damaged pipelines, displaying the updated matrix, and identifying directly connected tanks.

## 18. Repository Structure
```text
Water-Tank-Network/
├── README.md
├── main.cpp
├── Algorithm.md
└── Flowchart.md
```

## Author
**Project:** Water Tank Network Using Adjacency Matrix  
**Programming Language:** C++  
**Subject:** Data Structures and Algorithms
