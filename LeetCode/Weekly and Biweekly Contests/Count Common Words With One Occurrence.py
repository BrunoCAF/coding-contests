class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        cnt = 0
        for a in set(words1):
            if words2.count(a) == 1 and words1.count(a) == 1:
                cnt += 1
                
        return cnt