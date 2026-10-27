#include <iostream>
using namespace std;

int main() {
    int n, e;
    int adj[20][20] = {0};

    cout << "Enter number of water tanks: ";
    cin >> n;

    cout << "Enter number of pipelines: ";
    cin >> e;

    int u, v;

    cout << "Enter pipeline connections (tank1 tank2):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int choice;

    do {
        cout << "\n--- Water Tank Network ---\n";
        cout << "1. Add a pipeline\n";
        cout << "2. Remove a damaged pipeline\n";
        cout << "3. Display connected tanks\n";
        cout << "4. Display adjacency matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter two tank numbers: ";
            cin >> u >> v;

            if (u >= 0 && u < n && v >= 0 && v < n && u != v) {
                adj[u][v] = 1;
                adj[v][u] = 1;
                cout << "Pipeline added successfully.\n";
            } else {
                cout << "Invalid tank numbers.\n";
            }
            break;

        case 2:
            cout << "Enter damaged pipeline tank numbers: ";
            cin >> u >> v;

            if (u >= 0 && u < n && v >= 0 && v < n &&
                adj[u][v] == 1) {
                adj[u][v] = 0;
                adj[v][u] = 0;
                cout << "Pipeline removed successfully.\n";
            } else {
                cout << "Pipeline not found or invalid tanks.\n";
            }
            break;

        case 3:
            cout << "Enter selected tank number: ";
            cin >> u;

            if (u >= 0 && u < n) {
                cout << "Tanks directly connected to Tank "
                     << u << ": ";

                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (adj[u][i] == 1) {
                        cout << i << " ";
                        found = true;
                    }
                }

                if (!found)
                    cout << "None";

                cout << endl;
            } else {
                cout << "Invalid tank number.\n";
            }
            break;

        case 4:
            cout << "Adjacency Matrix:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << adj[i][j] << " ";
                cout << endl;
            }
            break;

        case 5:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
