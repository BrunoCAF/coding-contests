class Solution:
    def minimumBuckets(self, street: str) -> int:
        if len(street) == 1:
            return 0 if street[0] == '.' else -1
        
        if 'H' not in street:
            return 0
        
        if street[:2] == "HH" or street[-2:] == "HH":
            return -1
        
        if max(len(s) for s in street.split('.')) > 2:
            return -1
        
        cont = 0
        scope = street
        
        place_before = lambda scope, i: (i > 0)
        place_after = lambda scope, i: (i+1 < len(scope)) and (scope[i+1] == '.')
        double_profit = lambda scope, i: (i+2 < len(scope)) and (scope[i+2] == 'H')
        
        while len(scope) > 0:
            i = scope.find('H')
            if i < 0:
                break
            
            if place_after(scope, i):
                cont += 1
                if double_profit(scope, i):
                    scope = scope[i+3:]
                else: 
                    scope = scope[i+2:]
                
            elif place_before(scope, i):
                cont += 1
                scope = scope[i+1:]
                
            else:
                return -1
            
        return cont

                
        
        