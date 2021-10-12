class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        tgtSum = mean*(n+m) - sum(rolls)
        
        if tgtSum < n or tgtSum > 6*n:
            return []
        
        a = tgtSum//n
        b = tgtSum - a*n
        
        return [a + (1 if j <= b else 0) for j in range(1, n+1)]