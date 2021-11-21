class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        steps = 0
        water = capacity
        
        done = 0
        
        steps += 1; water -= plants[done]; done += 1;
        while done < len(plants):
            if water >= plants[done]:
                steps += 1
                water -= plants[done]
                done += 1
            else:
                steps += done
                water = capacity
                steps += done
                
        return steps
                