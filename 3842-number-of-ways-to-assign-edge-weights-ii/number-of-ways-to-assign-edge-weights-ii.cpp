class Solution {
public:
    static constexpr long long MOD = 1000000007LL;
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n + 1);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        vector<vector<int>> parent(LOG, vector<int>(n + 1, 0));
        vector<int> depth(n + 1, 0);
        stack<pair<int, int>> st;
        st.push({1, 0});

        while (!st.empty()) {
            auto [node, par] = st.top();
            st.pop();
            parent[0][node] = par;
            for (int nei : graph[node]) {
                if (nei != par) {
                    depth[nei] = depth[node] + 1;
                    st.push({nei, node});
                }
            }
        }

        for (int k = 1; k < LOG; k++) {
            for (int v = 1; v <= n; v++) {
                parent[k][v] = parent[k - 1][parent[k - 1][v]];
            }
        }
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++) {
                if (diff & (1 << k)) {
                    u = parent[k][u];
                }
            }
            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (parent[k][u] != parent[k][v]) {
                    u = parent[k][u];
                    v = parent[k][v];
                }
            }
            return parent[0][u];
        };
        auto modPow = [&](long long base, int exp) {
            long long result = 1;

            while (exp > 0) {
                if (exp & 1) {
                    result = (result * base) % MOD;
                }

                base = (base * base) % MOD;
                exp >>= 1;
            }
            return result;
        };
        vector<int> ans;
        for (auto& q : queries) {
            int u = q[0];
            int v = q[1];

            int w = lca(u, v);

            int edgesInPath = depth[u] + depth[v] - 2 * depth[w];

            if (edgesInPath == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)modPow(2, edgesInPath - 1));
            }
        }
        return ans;
    }
};