# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        p, q = head, head.next
        
        critical = []
        i = 1
        
        while q:
            if q.next:
                if q.val < min(p.val, q.next.val) or q.val > max(p.val, q.next.val):
                    critical.append(i)
            
            p, q = p.next, q.next
            i += 1
            
        if len(critical) < 2:
            return [-1, -1]
        else:
            m = min(critical[t] - critical[t-1] for t in range(1,len(critical)))
            M = critical[-1] - critical[0]
            return [m, M]