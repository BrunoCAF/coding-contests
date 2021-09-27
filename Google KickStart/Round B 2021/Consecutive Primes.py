from math import sqrt

def is_prime(n):
    if(n < 2):
        return False
    else:
        for i in range(2, int(sqrt(n))+1):
            if n%i == 0:
                return False
            
        return True
        

T = int(input())

for k in range(T):
    Z = int(input())
    # Achar o maior p menor que sqrt(Z):
    p1 = int(sqrt(Z))
    while (not is_prime(p1)):
        p1-=1
    # Achar o menor p maior que sqrt(Z)
    p2 = int(sqrt(Z))+1
    while (not is_prime(p2)):
        p2+=1
    if(p1*p2 <= Z):
        x = p1*p2
    else:
        p3 = p1-1
        while (not is_prime(p3)):
            p3-=1
        x = p3*p1
    print(f"Case #{k+1}: {x}")