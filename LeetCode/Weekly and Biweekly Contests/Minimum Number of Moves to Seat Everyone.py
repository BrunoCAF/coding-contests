class Solution:
    def minMovesToSeat(self, seats: List[int], students: List[int]) -> int:
        n = len(seats)
        seats.sort(); students.sort()
        
        moves = 0
        for t in range(n):
            #print(seats[t:])
            #print(students)
            l = [i for i in range(n-t) if students[i] <= seats[t]]
            stu = max(l) if l else min(i for i in range(n-t))
            
            #print(f"moves = {moves}")
            
            moves += abs(seats[t]-students[stu])
            
            students.remove(students[stu])
            
        return moves