#include <vector>
using namespace std;


class Union_Find {
public:
    Union_Find(int n) {
        for (int i = 0; i < n; ++i) {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    ~Union_Find() {

    }

    void _union(int a, int b) {
        int pa = _find(a);
        int pb = _find(b);
        if (pa != pb) {
            if (rank[pa] < rank[pb]) {
                par[pb] = pa;
            } else if (rank[pa] == rank[pb]) {
                par[pb] = pa;
                rank[pa]++;
            } else {
                par[pa] = pb;
            }
        }
    }

    int _find(int a) {
        if (par[a] != a) {
            par[a] = _find(par[a]);
        }
        return par[a];
    }
private:
    vector<int> par, rank;
};

class Union_Find_lazy {
public:
    Union_Find_lazy(int n) {
        for (int i = 0; i < n; ++i) {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    ~Union_Find_lazy() {

    }

    void _union(int a, int b) {
        int pa = _find(a);
        int pb = _find(b);
        par[pa] = pb;
    }

    int _find(int a) {
        if (par[a] != a) {
            par[a] = _find(par[a]);
        }
        return par[a];
    }
private:
    vector<int> par;
};

int main() {
    return 0;
};