#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, vector<pair<string, int>>> m;
    unordered_map<string, int> v;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string u, vtx;
        int w;
        cin >> u >> vtx >> w;

        m[u].push_back({vtx, w});
        m[vtx].push_back({u, w});
    }

    priority_queue<
        pair<int, pair<string, string>>,
        vector<pair<int, pair<string, string>>>,
        greater<pair<int, pair<string, string>>>
    > pq;

    string start = "A";   // same as your code
    pq.push({0, {start, "-1"}});

    int total_weight = 0;
    vector<pair<string, string>> mst;

    while (!pq.empty()) {
        auto a = pq.top();
        pq.pop();

        int wt = a.first;
        string cn = a.second.first;
        string parent = a.second.second;

        if (v[cn]) continue;

        v[cn] = 1;
        total_weight += wt;

        if (parent != "-1") {
            mst.push_back({parent, cn});
        }

        for (auto i : m[cn]) {
            if (!v[i.first]) {
                pq.push({i.second, {i.first, cn}});
            }
        }
    }

    cout << "Edges in spanning tree are:\n";
    for (auto e : mst) {
        cout << e.first << " - " << e.second << "\n";
    }

    cout << "Total weight: " << total_weight << endl;

    return 0;
}