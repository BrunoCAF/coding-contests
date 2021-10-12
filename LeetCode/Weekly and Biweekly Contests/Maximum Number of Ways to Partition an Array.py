class Solution:
    def waysToPartition(self, nums: List[int], k: int) -> int:
        n = len(nums)
        pref, suff = [0]*n, [0]*n
        pref[0] = nums[0]
        suff[-1] = nums[-1]
        
        for i in range(1, n):
            pref[i] = pref[i-1] + nums[i]
            suff[-1-i] = suff[-i] + nums[-1-i]
            
        diff = [0]*n
        diff[0] = suff[0]
        for i in range(1, n):
            diff[i] = pref[i-1] - suff[i]
            
        left = {}
        right = {diff[i] : 0 for i in range(1, n)}
        for i in range(1, n):
            right[diff[i]] += 1
            
        parts = right.get(0, 0)
        
        d = 0
        for j in range(n):
            d = nums[j] - k
            pr = right.get(d, 0)
            pl = left.get(-d, 0)
            parts = max(pl + pr, parts)
            
            if j < n-1:
                v = diff[j+1]
                right[v] -= 1
                left[v] = left.get(v, 0) + 1
                if right[v] == 0:
                    right.pop(v)
            
        return parts
            
        