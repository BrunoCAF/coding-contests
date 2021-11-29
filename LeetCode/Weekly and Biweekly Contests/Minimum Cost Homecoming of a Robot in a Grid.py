class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        
        
        Vcost = sum(colCosts[j] for j in range(startPos[1]+1, 
                    homePos[1]+1)) if startPos[1] < homePos[1] else sum(colCosts[j] for j in range(homePos[1], startPos[1]))
        
        Hcost = sum(rowCosts[i] for i in range(startPos[0]+1, 
                    homePos[0]+1)) if startPos[0] < homePos[0] else sum(rowCosts[i] for i in range(homePos[0], startPos[0]))
        
        return Vcost + Hcost
                