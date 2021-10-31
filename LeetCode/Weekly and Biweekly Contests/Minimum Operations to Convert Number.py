class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        v = set()
        q = deque([(start, 0)])
        
        while q:
            x, n = q.popleft()
            
            if x == goal:
                return n
            if x not in v:
                if 0 <= x <= 1000:
                    for a in nums:
                        q.append((x+a, n+1))
                        q.append((x-a, n+1))
                        q.append((x^a, n+1))

                v.add(x)
        
        return -1

            