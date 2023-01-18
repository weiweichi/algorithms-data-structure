from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def BFS(root : TreeNode):
    if not root:
        return -1
    dq = deque([root])
    while dq:
        node = dq.popleft()

        # do something here

        if node.left:
            dq.append(node.left)
        if node.right:
            dq.append(node.right)

def DFS(root : TreeNode):
    if not root:
        return -1
    
    s = [root]
    while s:

        while s[-1].left:
            s.append(s[-1].left)
        
        node = s.pop()
        # do something here
        if node.right:
            s.append(node.right)

def traversal(root: TreeNode):
    if not root:
        return []
    
    # preorder
    return [root.val] + traversal(root.left) + traversal(root.right)
    # inorder
    return  traversal(root.left) + [root.val] + traversal(root.right)
    # postorder
    return traversal(root.left) + traversal(root.right) + [root.val]