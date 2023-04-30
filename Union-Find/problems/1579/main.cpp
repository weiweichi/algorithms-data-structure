#include <vector>
using namespace std;
// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/
class UF {
public:
    vector<int> rank, par;
    UF(int n):rank(n+1), par(n+1) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int a) {
        if (par[a] != a)
            par[a] = find(par[a]);
        return par[a];
    }
    int union_set(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb)
            return 1;
        if (rank[pa] < rank[pb]) {
            par[pa] = pb;
        } else if (rank[pa] == rank[pb]) {
            par[pa] = pb;
            rank[pb]++;
        } else {
            par[pb] = pa;
        }
        return 0;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UF alice(n);
        int alice_group = n, redundant = 0, flag = 0;
        for (auto &edge:edges) {
            if (edge[0] == 3) {
                alice.union_set(edge[1], edge[2])? redundant++: alice_group--;
            }
        }
        UF bob = alice;
        int bob_group = alice_group;
        for (auto &edge: edges) {
            if (edge[0] == 2) {
                bob.union_set(edge[1], edge[2])? redundant++: bob_group--;
            } else if (edge[0] == 1){
                alice.union_set(edge[1], edge[2])? redundant++: alice_group--;
            } 
        }
        return (alice_group == 1 && bob_group == 1)? redundant: -1;
    }
};