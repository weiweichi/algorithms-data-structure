#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {delete left, right, val;};
};

struct nary_tree {
    int val;
    vector<nary_tree> child;
    nary_tree() : val(0), child({}) {}
    nary_tree(int x) : val(x), child({}) {}
    nary_tree(int x, vector<nary_tree> &child) : val(x), child(child) {}
    ~nary_tree() {;};
};

