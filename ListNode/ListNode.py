from collections import defaultdict

class ListNode:
    def __init__(self, key=0, value=0, next=None, prev=None) -> None:
        self.key = key
        self.value = value
        self.next = next
        self.prev = prev
    

class LRUCache:
    def __init__(self, capacity=float('inf')) -> None:
        assert capacity > 0, f"Should has capacity > 0, but get {capacity}"

        self.head = ListNode()
        self.tail = ListNode()
        self.head.next = self.tail
        self.tail.prev = self.head

        self.capacity = capacity
        self.memo = defaultdict(ListNode)
    
    def get(self, key : int):
        if key in self.memo:
            node = self.memo[key]
            self._remove(node)
            self._insert(node)
            return node.value
        else:
            return -1
    
    def put(self, key, value):
        
        if key in self.memo:
            node = self.memo[key]
            self._remove(node)
            self.memo[key] = node.value = value
        else:
            if self.capacity == 0:
                node = self.tail.prev
                del self.memo[node.key]
                node.key, node.value = key, value
                self._remove(node)
            else:
                node = ListNode(key, value)
                self.capacity -= 1
            self.memo[key] = node
        self._insert(node)
    
    def _remove(self, node: ListNode) -> ListNode: 
        prev = node.prev
        next = node.next

        prev.next = next
        next.prev = prev
        return node
    
    def _insert(self, node: ListNode):
        node.prev = self.head
        node.next = self.head.next

        self.head.next = node
        node.next.prev = node
        return node