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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), group_cnt = n;
        UF uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    group_cnt -= uf._union(i, j);
                }
            }
        }
        return group_cnt;
    }
    bool isSimilar(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            diff += a[i] != b[i];
        }
        return diff == 0 || diff == 2;
    }
};