n = int(input())

a = [0, 1, 1]
if n > 2 :
    for i in range(3, n+1) :
        buf = a[i-1] + a[i-2]
        a.append(buf)

print(a[n])
