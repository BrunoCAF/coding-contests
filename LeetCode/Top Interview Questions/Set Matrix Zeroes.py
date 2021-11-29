class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        mi = (0 in matrix[0])
        mj = (0 in [row[0] for row in matrix])
        
        for j, a in enumerate(matrix[0][1:]):
            if 0 in [row[j+1] for row in matrix]:
                matrix[0][j+1] = 0
        
        for i, b in enumerate(matrix[1:]):
            if 0 in b:
                matrix[i+1][0] = 0
                
        for j, a in enumerate(matrix[0][1:]):
            if a == 0:
                for i, row in enumerate(matrix):
                    matrix[i][j+1] = 0
        
        for i, b in enumerate(matrix):
            if b[0] == 0:
                for j, x in enumerate(b):
                    matrix[i][j] = 0
                
        if mi:
            matrix[0] = [0]*len(matrix[0])
        
        if mj:
            for i, row in enumerate(matrix):
                matrix[i][0] = 0
        
                
                    
                    