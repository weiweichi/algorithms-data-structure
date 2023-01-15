
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {delete left, right, val;};
};

TreeNode* search(TreeNode *root, int val) {
    if (!root)
        return nullptr;
    TreeNode* curr=root;
    while (curr) {
        if (curr->val == val)
            return curr;
        if (curr->val < val)
            curr = curr->right;
        else
            curr = curr->left;
    }
    return nullptr;
}

TreeNode* insert(TreeNode *root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    TreeNode *curr = root;
    while (curr) {
        if (curr->val <= val) {
            if (curr->right == nullptr) {
                curr->right = new TreeNode(val);
                break;
            }
            curr=curr->right;
        } else {
            if (curr->left == nullptr) {
                curr->left = new TreeNode(val);
                break;
            }
            curr=curr->left;
        }
    }
    return root;
}
void go_tail_and_remove(TreeNode *node, TreeNode *par) {
    bool lnode = node->val <= par->val;
    TreeNode *left=node->left, *right=node->right;
    if (left == nullptr) {
        if (lnode) 
            par->left = right;
        else
            par->right = right;
        return;
    } else if (right) {
        TreeNode *tail = right;
        while (tail->left) 
            tail = tail->left;
        tail->left = left->right;
        left->right = right;
    }
    if (lnode)
        par->left = left;
    else
        par->right = right;
}
TreeNode* remove(TreeNode *root, int val) {
    if (!root || (root->val == val && root->left == nullptr))
        return nullptr;
    TreeNode *curr = root, *par = new TreeNode(0, root, nullptr);
    while (curr) {
        if (curr->val == val) {
            go_tail_and_remove(curr, par);
            break;
        }
        if (curr->val < val) {
            par = curr;
            curr = curr->right;
        } else {
            par = curr;
            curr = curr->left;
        }
    }
    return root;
}