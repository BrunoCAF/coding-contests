"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        if head:
            flat = lambda x: Node(x.val, x.prev, x.next, None)
            
            resp = head
            q = deque()
            
            
            p = head
            while p:
                q.append(p)
                p = p.next
            
            p = resp
            while q:
                x = q.popleft()
                if x.child:
                    r = x.child
                    u = deque()
                    while r:
                        u.appendleft(r)
                        r = r.next
                    
                    while u:
                        q.appendleft(u.popleft())
                
                p.next = flat(x)
                p.next.prev = p
                p = p.next
            
            
            resp = resp.next
            resp.prev = None
            return resp
            
        else:
            return head