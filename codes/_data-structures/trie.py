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
        self.count = 0
        self.word_status = False
        self.word_count = 0
        self.children = {}

class Trie:
    def __init__(self, words=None):
        self.root = TrieNode("")
        if words:
            for word in words:
                self.insert(word)

    def __dfs(self, node, current_prefix):
        if node.word_status:
            self.matches.append((current_prefix+node.value, node.word_count))
        for child in node.children.values():
            self.__dfs(child, current_prefix+node.value)

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

    def remove(self, word):
        node = self.root
        for character in word:
            if character in node.children:
                node.children[character].count -= 1
                if node.children[character].count<=0:
                    node.children.pop(character)
                    return
                node = node.children[character]
        if node.word_count>0:
            node.word_count -= 1
        if node.word_count == 0:
            node.word_status = False




class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for character in word:
            if character not in node.children:
                node.children[character] = TrieNode(character)
            node = node.children[character]
        node.end_of_word = True

    def search(self, word: str) -> bool:
        node = self.root
        for character in word:
            if character not in node.children:
                return False
            node = node.children[character]
        return node.end_of_word

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for character in prefix:
            if character not in node.children:
                return False
            node = node.children[character]
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)