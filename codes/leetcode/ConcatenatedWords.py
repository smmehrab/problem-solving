# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:

    def _dfs(self, word):
        if word in self.dp:
            return self.dp[word]
        n = len(word)
        for i in range(1, n):
            prefix = word[:i]
            suffix = word[i:]
            if prefix in self.word_set and suffix in self.word_set:
                self.dp[word] = True
                return self.dp[word]
            elif prefix in self.word_set and self._dfs(suffix):
                self.dp[word] = True
                return self.dp[word]
        self.dp[word] = False
        return self.dp[word]

    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        self.word_set = set(words)
        self.dp = {}
        concatenated_words = []
        for word in words:
            if self._dfs(word):
                concatenated_words.append(word)
        return concatenated_words
