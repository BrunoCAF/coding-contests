class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3: 
            return []
        
        nums.sort()
        
        sols = {}
        
        for i in range(n-2):
            j, k = i+1, 1
            while j < n - k:
                s = nums[i] + nums[j] + nums[-k]
                if s < 0:
                    j += 1
                elif s > 0: 
                    k += 1
                else:
                    if nums[i] in sols.keys():
                        sols[nums[i]].add(nums[j])  
                    else: 
                        sols[nums[i]] = set([nums[j]])
                    j, k = j+1, k+1
        
        resp = []
        for a in sols:
            for b in sols[a]:
                resp.append([a, b, -a-b])
                            
        return resp