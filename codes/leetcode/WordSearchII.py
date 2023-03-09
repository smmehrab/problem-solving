# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class TrieNode:
    def __init__(self, character):
        self.value = character
        self.count = 1
        self.word_status = False
        self.word_count = 0
        self.children = {}

class Trie:
    def __init__(self, words=None):
        self.root = TrieNode("")
        if words != None:
            for word in words:
                self.insert(word)

    def insert(self, word):
        node = self.root
        for character in word:
            if character in node.children:
                node.children[character].count += 1
            else:
                node.children[character] = TrieNode(character)
            node = node.children[character]
        node.word_status = True
        node.word_count += 1

    def remove(self, word):
        node = self.root
        for character in word:
            if character in node.children:
                node.children[character].count -= 1
        if node.word_count>0:
            node.word_count -= 1
        if node.word_count == 0:
            node.word_status = False

class Solution:
    def __dfs(self, dfs_node, trie_node, word):
        x, y = dfs_node
        # out of bound
        if x<0 or y<0 or x>=self.n or y>=self.m:
            return
        # already visited
        if self.visited[x][y]:
            return

        character = self.graph[x][y]
        # no words with this prefix
        if character not in trie_node.children:
            return

        # backtracking
        self.visited[x][y] = True
        trie_node = trie_node.children[character]
        word += character
        if trie_node.word_status:
            self.matches.add(word)
            self.trie.remove(word)
        self.__dfs((x+1, y), trie_node, word)
        self.__dfs((x-1, y), trie_node, word)
        self.__dfs((x, y+1), trie_node, word)
        self.__dfs((x, y-1), trie_node, word)
        self.visited[x][y] = False

    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        self.trie = Trie(words)

        self.n = len(board)
        self.m = len(board[0])
        self.graph = board

        self.matches = set()
        self.visited = [[False]*self.m]*self.n
        for i in range(self.n):
            for j in range(self.m):
                self.__dfs((i, j), self.trie.root, "")
        return list(self.matches)
