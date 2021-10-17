class Solution:
    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
        
        n = len(patience)
        dist = [0 for i in patience]
        visit = [0 for i in patience]
        
        nbrs = [[] for v in patience]
        
        for [a,b] in edges:
            nbrs[a].append(b);nbrs[b].append(a);
        
        def bfs():
            d = 0
            dist[0] = d
            visit[0] = 1
            voisinage = nbrs[0]
            
            while voisinage:
                d += 1
                newvoisinage = []
                for u in voisinage:
                    if visit[u] == 0:
                        visit[u] = 1
                        dist[u] = d
                        newvoisinage += nbrs[u]
                    
                voisinage = newvoisinage
                
        bfs()
        
        t = [2*dist[v] + (2*dist[v]-1)//patience[v] * patience[v] for v in range(1,n)]
        
        return max(t)+1