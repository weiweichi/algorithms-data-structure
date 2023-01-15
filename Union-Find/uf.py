
class Union_Find:
    def __init__(self, n) -> None:
        self.rank = [0] * n
        self.par = [i for i in range(n)]
    
    def union(self, a, b):
        pa = self.find(a)
        pb = self.find(b)
        if pa != pb:
            if self.rank[pa] < self.rank[pb]:
                self.par[pb] = pa
            elif self.rank[pa] == self.rank[pb]:
                self.par[pb] = pa
                self.rank[pa] += 1
            else:
                self.par[pa] = pb
        
    def find(self, a):
        if a != self.par[a]:
            self.par[a] = self.find(self.par[a])
        return self.par[a]

class Union_Find_lazy:
    def __init__(self, n) -> None:
        self.par = [i for i in range(n)]
    
    def union(self, a, b):
        pa = self.find(a)
        pb = self.find(b)
        if pa != pb:
            self.par[pa] = pb
        
    def find(self, a):
        if a != self.par[a]:
            self.par[a] = self.find(self.par[a])
        return self.par[a]