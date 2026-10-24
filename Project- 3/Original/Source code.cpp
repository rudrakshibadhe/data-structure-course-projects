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

    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nDirect Pipeline Connections:\n";

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] == 1) {
                cout << "Tank " << i
                     << " is connected to Tank "
                     << j << endl;
            }
        }
    }

    return 0;
}
