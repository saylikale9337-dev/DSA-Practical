#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, edges;

    cout << "Enter number of routers: ";
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter number of communication links: ";
    cin >> edges;

    cout << "Enter links (router1 router2 cost):\n";

    for (int i = 0; i < edges; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;

        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }

    int source;
    cout << "Enter source router: ";
    cin >> source;

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int> >,
        greater<pair<int, int> >
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int cost = edge.second;

            if (dist[u] != INT_MAX &&
                dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nMinimum link costs from router "
         << source << ":\n";

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Router " << i << ": Unreachable\n";
        else
            cout << "Router " << i << ": "
                 << dist[i] << "\n";
    }

    int destination;
    cout << "\nEnter destination router: ";
    cin >> destination;

    if (dist[destination] == INT_MAX) {
        cout << "Destination is unreachable.\n";
    } else {
        vector<int> path;

        for (int v = destination; v != -1;
             v = parent[v]) {
            path.push_back(v);
        }

        reverse(path.begin(), path.end());

        cout << "Shortest path: ";

        for (int i = 0; i < path.size(); i++) {
            cout << path[i];

            if (i < path.size() - 1)
                cout << " -> ";
        }

        cout << "\nMinimum total cost: "
             << dist[destination] << "\n";
    }

    return 0;
}
