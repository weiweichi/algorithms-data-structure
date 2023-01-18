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

void BFS(TreeNode* root) {
    if (root == nullptr)
        return;
    vector<TreeNode*> level = {root};
    while (!level.empty()) {
        vector<TreeNode*> _temp;
        for (TreeNode* node: level) {
            if (node->left) 
                _temp.push_back(node->left);
            if (node->right)
                _temp.push_back(node->right);
        }
        swap(_temp, level);
    }
    return;
}

void DFS(TreeNode* root) {
    if (root == nullptr)
        return;
    DFS(root->left);
    // do something here
    DFS(root->right);
}

