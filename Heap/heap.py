
class max_heap:
    def __init__(self, arr: list[int]) -> None:
        self.arr = arr
        self.heapify()
    
    def heapify(self):
        for idx in range(len(self.arr) - 1, -1, -1):
            self._sift(idx)

    def _sift(self, idx):
        n = len(self.arr)
        while 1:
            child = idx * 2 + 1
            if child >= n:
                break
            if child + 1 < n and self.arr[child] < self.arr[child+1]:
                child += 1
            if self.arr[idx] < self.arr[child]:
                self.arr[idx], self.arr[child] = self.arr[child], self.arr[idx]
                idx = child
            else:
                break

    def push(self, value):
        idx = len(self.arr)
        self.arr.append(value)
        while idx:
            if self.arr[(idx - 1) // 2] >= value:
                break
            self.arr[idx] = self.arr[(idx - 1) // 2]
            idx = (idx - 1) // 2
        self.arr[idx] = value
    
    def top(self):
        return self.arr[0] if self.arr else -1
    
    def pop(self):
        maxi = self.arr[0]
        self.arr[0] = self.arr.pop()
        self._sift(0)
        return maxi

    def __len__(self):
        return len(self.arr)
    
    def empty(self):
        return len(self.arr) == 0