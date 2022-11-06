class TrieNode:
    def __init__(self, character):
        self.value = character
        self.word_status = False
        self.word_count = 0
        self.children = {}

class Trie:
    def __init__(self):
        self.root = TrieNode("")

    def __dfs(self, node, current_prefix):
        if node.word_status:
            self.matches.append((current_prefix+node.value, node.word_count))
        for child in node.children.values():
            self.__dfs(child, current_prefix+node.value)

    def insert(self, word):
        node = self.root
        for character in word:
            if character in node.children:
                node = node.children[character]
            else:
                new_node = TrieNode(character)
                node.children[character] = new_node
                node = new_node
        node.word_status = True
        node.word_count += 1

    def query(self, prefix):
        self.matches = []
        node = self.root
        for character in prefix:
            if character in node.children:
                node = node.children[character]
            else:
                return self.matches
        self.__dfs(node, prefix[:-1])
        self.matches = sorted(self.matches, key=lambda pair: pair[1], reverse=True)
        return self.matches
