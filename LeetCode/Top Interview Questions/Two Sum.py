class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        inums = [(nums[i], i) for i in range(len(nums))]
        inums.sort(key = lambda p: p[0])
        
        n = len(nums)
        i, j = 0, 1
        while i < n-j:
            s = inums[i][0] + inums[-j][0] - target
            if s < 0:
                i += 1
            elif s > 0:
                j += 1
            else:
                return [inums[i][1], inums[-j][1]]