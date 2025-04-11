t = int(input())

for _ in range(t):
    n,k = input().split()
    k = int(k)
    i = 5

    s = n*k 
    num = int(s)

    def is_True(x):
        if x<= 1:
            return False
        if x <= 3:
            return True
        if x%2 == 0 or x%3 == 0:
            return False
        i = 5
        while i*i <= x:
            if x%i == 0 or x%(i+2) == 0:
                return False
            i += 6
        return True

    if is_True(n) == True:
        print("Yes")
    else:
        print("Yes" if is_True(num) else "No")