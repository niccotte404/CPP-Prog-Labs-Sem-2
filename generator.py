n = int(input())
gray_code = [2**n][n]
gray_code[0][n-1] = False
gray_code[1][n-1] = True
p = 1
for i in range(1, n):
    t = p
    p *= 2
    for k in range(p//2 + 1, p):
        gray_code[k] = gray_code[t]
        gray_code[t][n-i] = False
        gray_code[k][n-i] = True
        t -= 1
    
for i in range(2**n):
    for j in range(n):
        print(gray_code[i][j])
    print()