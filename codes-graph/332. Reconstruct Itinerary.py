class Solution:
    
    def dfs(self, node, result):
        if len(result) == self.length:
            self.answer = result
            return True
        
        res = False
        
        for i,adj in enumerate(self.graph[node]):
            if adj != '#':
                city = adj
                self.graph[node][i] = '#'
                result.append(city)
                res = (res or self.dfs(city, result))
                if res:
                    return res
                self.graph[node][i]= city # backtrack
                result.pop()
        
        return res
        
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
     
        self.length = len(tickets) + 1
        self.graph = collections.defaultdict(list)
        
        for ticket in tickets:
            self.graph[ticket[0]].append(ticket[1])
        
        for g in self.graph:
            self.graph[g].sort()
            
        self.answer = []
        
        self.dfs('JFK', ['JFK'])
        
        return self.answer
        