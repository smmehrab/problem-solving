# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class TrieNode:
    def __init__(self, character=None):
        self.value = character
        self.end_of_word = False
        self.children = {}

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