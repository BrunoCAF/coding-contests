class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda I: I[0])
        
        print(intervals)
        
        i = 0
        while i < len(intervals)-1:
            while (i+1 < len(intervals)) and (intervals[i][1] >= intervals[i+1][0]):
                j = max(k for k in range(len(intervals)) if intervals[k][0] <= intervals[i][1])
                M = max(intervals[k][1] for k in range(i, j+1))
                iv = [intervals[i][0], M]
                intervals = intervals[:i] + [iv] + intervals[j+1:]
                
            i += 1
            
        return intervals