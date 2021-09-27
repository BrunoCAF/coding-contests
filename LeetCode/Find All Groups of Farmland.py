class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        farms: List[List[int]] = []
        l = lambda p,v: p[1] == 0 or land[p[0]][p[1]-1] == v
        r = lambda p,v: len(land[p[0]]) == p[1]+1 or land[p[0]][p[1]+1] == v
        u = lambda p,v: p[0] == 0 or land[p[0]-1][p[1]] == v
        d = lambda p,v: len(land) == p[0]+1 or land[p[0]+1][p[1]] == v
            
        isTopLeft = lambda i,j: l((i,j), 0) and u((i,j), 0) and land[i][j] == 1
        isBottomRight = lambda i,j: r((i,j), 0) and d((i,j), 0) and land[i][j] == 1
        
        for i in range(len(land)):
            for j in range(len(land[i])):
                if isTopLeft(i,j):
                    m, n = i, j
                    while n+1 < len(land[i]) and land[i][n+1] == 1:
                        n += 1
                    while m+1 < len(land) and land[m+1][n] == 1:
                        m += 1
                    farms.append([i, j, m, n])
                    
        return farms
        
        
        