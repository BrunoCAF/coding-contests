class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.hash = {v: [] for v in arr}
        
        #self.hash = defaultdict(list)
        for i, x in enumerate(arr): self.hash[x].append(i)
        

    def query(self, left: int, right: int, value: int) -> int:
        if value not in self.hash:
            return 0
        else:
            x = self.hash[value]
            n = len(x)
            a, b = 0, n-1
            if left <= x[a]:
                l = 0
            elif x[b] < left:
                l = n
            else:
                l = (a+b)//2
                if left <= x[l]:
                    m, b = (a+l)//2, l
                else:
                    a, m = l, (l+b+1)//2
                while not (x[l-1] < left <= x[l]):
                    #print(f"a = {a}, b = {b}, l = {l}, x[l] = {x[l]}")
                    l = m
                    if left <= x[l]:
                        m, b = (a+l)//2, l
                    else:
                        a, m = l, (l+b+1)//2
            
            a, b = 0, n-1
            if x[b] <= right:
                r = n-1
            elif right < x[a]:
                r = -1
            else:
                r = (a+b)//2
                if x[r] <= right:
                    a, m = r, (r+b+1)//2
                else:
                    m, b = (a+r)//2, r
                while not (x[r] <= right < x[r+1]):
                    #print(f"a = {a}, b = {b}, r = {r}, x[r] = {x[r]}")
                    r = m
                    if x[r] <= right:
                        a, m = r, (r+b+1)//2
                    else:
                        m, b = (a+r)//2, r
            
            
            return r - l + 1
        
        


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)