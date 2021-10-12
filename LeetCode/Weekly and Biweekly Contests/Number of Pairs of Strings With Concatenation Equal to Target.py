class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        resp = 0
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i != j:
                    resp += 1 if nums[i] + nums[j] == target else 0
                    
        return resp