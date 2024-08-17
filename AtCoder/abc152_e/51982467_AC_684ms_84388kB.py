import math
from functools import reduce

# Function to return LCM of two numbers
def lcm(a, b):
    return (a * b) // math.gcd(a, b)

def main():
    n = int(input())
    v = list(map(int, input().split()))
    
    x = v[0]
    for i in range(1, n):
        tmp=v[i]
        x = lcm(x, tmp)
    
    M = 1000000007
    ans = 0
    for i in range(n):
        ans += (x // v[i])
        ans %= M
    
    print(ans)

if __name__ == "__main__":
    main()
