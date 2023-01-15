
class Binary_Tree:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right
    
    
class n_ary_Tree:
    def __init__(self, val=0, child: list=[]) -> None:
        self.val = val
        self.child = child