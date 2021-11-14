class Robot:

    def __init__(self, width: int, height: int):
        self.W, self.H = width, height
        self.pos = [0, 0]
        self.dir = "East"
        self.dirdict = {"East": [1, 0], "North": [0, 1], "West": [-1, 0], "South": [0, -1]}
        self.turn = {"East": "North", "North": "West", "West": "South", "South": "East"}
        self.d = lambda: self.dirdict.get(self.dir)
        self.next = lambda p, d: [list(p)[0] + list(d)[0], list(p)[1] + list(d)[1]]
        self.outofbounds = lambda p: not ((0 <= list(p)[0] < width) and (0 <= list(p)[1] < height))
        
        self.disttobound = lambda: {"East": width - 1 - list(self.pos)[0], 
                                    "North": height - 1 - list(self.pos)[1], 
                                    "West": list(self.pos)[0], 
                                    "South": list(self.pos)[1]}[self.dir]
        
        self.simplemove = lambda p, n: {"East": [p[0]+n, p[1]],
                                        "North": [p[0], p[1]+n],
                                        "West": [p[0]-n, p[1]],
                                        "South": [p[0], p[1]-n]}[self.dir]
        
    def move(self, num: int) -> None:
        if num <= self.disttobound():
            self.pos = self.simplemove(list(self.pos), num)
        
        else:
            num -= self.disttobound()
            self.pos = self.simplemove(list(self.pos), self.disttobound())
            
            num %= 2*(self.W + self.H - 2)
            if num:
                self.dir = self.turn[self.dir]
                        
            while num:
                dist = min(num, self.disttobound())
                num -= dist
                self.pos = self.simplemove(list(self.pos), dist)
                if num:
                    self.dir = self.turn[self.dir]
            
        

    def getPos(self) -> List[int]:
        return self.pos

    def getDir(self) -> str:
        return self.dir
        


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.move(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()