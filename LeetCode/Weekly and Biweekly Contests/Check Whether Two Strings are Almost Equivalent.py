class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        freq1 = {}
        for a in word1:
            freq1[a] = freq1.get(a, 0) + 1
            
        freq2 = {}
        for a in word2:
            freq2[a] = freq2.get(a, 0) + 1
        
        for x in set(freq1.keys()).union(set(freq2.keys())):
            if abs(freq1.get(x, 0) - freq2.get(x, 0)) > 3:
                return False
            
        return True