class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def RemoveNode(root: TreeNode, val: int):
    def dfs(par, node):
        if not node:
            return
        if node.val == val:
            delete(par, node)
        elif node.val < val:
            dfs(node, node.right)
        else:
            dfs(node, node.left)
            
    def delete(par, node):
        l, r = node.left, node.right
        lnode = par.val > node.val
        if not l:
            if lnode:
                par.left = r
            else:
                par.right = r
            return
        elif r:
            tail = r
            while tail.left:
                tail = tail.left
            tail.left = l.right
            l.right = r
        if lnode:
            par.left = l
        else:
            par.right = l

    dummy = TreeNode(float('inf'), left = root)
    dfs(dummy, root)
    return dummy.left

def SearchNode(root: TreeNode, val: int):
    if not root:
        return None
    curr = root
    while curr:
        if curr.val == val:
            return curr
        if curr.val < val:
            curr = curr.right
        else:
            curr = curr.left
    return None

def InsertNode(root: TreeNode, val: int):
    if not root:
        return TreeNode(val)
    
    curr = root
    while True:
        if curr.val <= val:
            if not curr.right:
                curr.right = TreeNode(val)
                break
            curr = curr.right
        else:
            if not curr.left:
                curr.left = TreeNode(val)
                break
            curr = curr.left
    return root