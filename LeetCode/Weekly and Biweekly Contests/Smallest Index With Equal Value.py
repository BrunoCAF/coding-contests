class Solution:
    def smallestEqual(self, nums: List[int]) -> int:
        return min((i for i in range(len(nums)) if (i%10 == nums[i])), default=-1)