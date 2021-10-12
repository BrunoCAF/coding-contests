class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if len(original) != m*n:
            return []
        
        return [[original[i] for i in range(k*n, (k+1)*n)] for k in range(m)]