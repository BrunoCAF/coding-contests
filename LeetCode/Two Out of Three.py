class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        n1, n2, n3 = set(nums1), set(nums2), set(nums3)
        counter = {x: 0 for x in nums1+nums2+nums3}
        for x in n1: counter[x] += 1
        for x in n2: counter[x] += 1
        for x in n3: counter[x] += 1
            
        return [x for x in counter if counter[x] >= 2]