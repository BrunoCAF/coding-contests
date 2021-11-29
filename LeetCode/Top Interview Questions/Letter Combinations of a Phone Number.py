class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if digits == "":
            return []
        
        associatedLetters = {'2': "abc", 
                             '3': "def", 
                             '4': "ghi",
                             '5': "jkl",
                             '6': "mno",
                             '7': "pqrs",
                             '8': "tuv",
                             '9': 'wxyz'}
        l, aux = [""], []
        
        for d in digits:
            for s in l:
                for letter in associatedLetters[d]:
                    aux.append(s+letter)
            
            l, aux = aux, []
            
        return l