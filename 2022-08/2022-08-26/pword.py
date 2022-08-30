from distutils.command.build import build
from logging import root


class Trie:
    def __init__(self):
        self.children = [None]*26
        self.word = None
        self.isEndOfWord = False


class Solution:
    def insert(self, root, key):
        pCrawl = root
        length = len(key)
        for level in range(length):
            index = ord(key[level]) - ord('a')

            # if current character is not present
            if not pCrawl.children[index]:
                pCrawl.children[index] = Trie()
            pCrawl = pCrawl.children[index]
            pCrawl.word = key

        # mark last node as leaf
        pCrawl.isEndOfWord = True

    def build(self, words):
        root = Trie()
        for w in words:
            self.insert(root, w)
        return root

    def getWordsWithPrefix(self, words, prefix):
        result = []
        pCrawl = self.build(words)
        length = len(prefix)
        for level in range(length):
            index = ord(prefix[level]) - ord('a')
            if not pCrawl.children[index]:
                return []
            pCrawl = pCrawl.children[index]

        return self.getAllwordsHelper(pCrawl, result)

    def getAllwordsHelper(self, node, result):
        if node.isEndOfWord:
            result.append(node.word)
        for c in node.children:
            if c is not None:
                self.getAllwordsHelper(c, result)

        return result


s = Solution()
res = s.getWordsWithPrefix(["hello", "halo", "hh", "hao", "ao"], "h")
print(res)
