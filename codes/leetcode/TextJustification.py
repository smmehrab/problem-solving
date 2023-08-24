# ************************************************
# username  :   smmehrab
# fullname  :   s.m.mehrabul islam
# email     :   smmehrabul-2017614964@cs.du.ac.bd
# institute :   university of dhaka, bangladesh
# reg       :   2017614964
# ************************************************

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        justified, line = [], []
        letter_count, space_count, width = 0, 0, -1
        for word in words:
            if width + len(word) > maxWidth:
                for i in range(maxWidth - letter_count):
                    line[i % (space_count - 1 or 1)] += ' '
                justified.append(''.join(line))
                line, letter_count, space_count = [], 0, 0
            line += [word]
            space_count += 1
            letter_count += len(word)
            width = letter_count + space_count
        justified.append((' '.join(line)) + (' ' * (maxWidth-width+1)))
        return justified