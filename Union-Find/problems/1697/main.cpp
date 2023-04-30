#include <vector>
using namespace std;
class UF {
public:
    vector<int> parent;
    vector<int> rank;
    UF(int n) {
        rank.resize(n);
        for (int i = 0; i < n; ++i)
            parent.push_back(i);
    }
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }
    int _union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb)
            return 0;
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        } else if (rank[pa] == rank[pb]) {
            parent[pa] = pb;
            rank[pb]++;
        } else {
            parent[pb] = pa;
        }
        return 1;
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> queries_idx(m, 0);
        iota(queries_idx.begin(), queries_idx.end(), 0);
        sort(queries_idx.begin(), queries_idx.end(), [&](const int a, const int b) {
            return queries[a][2] < queries[b][2];
            });
        sort(edgeList.begin(), edgeList.end(), [](vector<int> &a, vector<int> &b) {return a[2] < b[2];});
        UF uf(n);
        int edgeList_idx = 0;
        vector<bool> res(m, 0);
        for (int i = 0; i < m; ++i) {
            auto query = queries[queries_idx[i]];
            for (;edgeList_idx < edgeList.size() && edgeList[edgeList_idx][2] < query[2]; ++edgeList_idx) {
                uf._union(edgeList[edgeList_idx][0], edgeList[edgeList_idx][1]);
            }
            res[queries_idx[i]] = (uf.find(query[0]) == uf.find(query[1]));
        }
        return res;
    }
};