class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        line = []
        for l in grid:
            line += l
        
        N = len(line)
        
        line.sort(reverse=True)
        
        tgt = max(line)
        
        cnt = 0
        for a in line:
            if (tgt - a) % x == 0:
                cnt += (tgt-a)//x
            else:
                return -1
            
        for i in range(1, len(line)):
            delta = (line[i-1] - line[i])//x
            newcnt = cnt - (N-2*i)*delta
            if newcnt <= cnt:
                cnt = newcnt
            else:
                return cnt
        
        return cnt