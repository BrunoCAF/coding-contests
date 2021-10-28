class Solution:
    def tribonacci(self, n: int) -> int:
        T = [0, 1, 1]
        
        if n < 3:
            return T[n]
        
        for n in range(3, n+1):
            T[2], T[1], T[0] = T[2] + T[1] + T[0], T[2], T[1]
            
        return T[2]