
class Trie:
    def __init__(self):
        self.word = False
        self.dic = {}

    def insert(self, word: str) -> None:
        tree = self
        for w in word:
            if w not in tree.dic:
                tree.dic[w] = Trie()
            tree = tree.dic[w]
        tree.word = True

    def search(self, word: str) -> bool:
        tree = self
        for w in word:
            if w not in tree.dic:
                return False
            tree = tree.dic[w]
        return tree.word
    
    def startsWith(self, prefix: str) -> bool:
        tree = self
        for w in prefix:
            if w not in tree.dic:
                return False
            tree = tree.dic[w]
        return True