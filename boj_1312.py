buf = input()
buf = buf.split(' ')

a = int(buf[0])
b = int(buf[1])
N = int(buf[2])

ret = 0
for i in range(N) : 
    a %= b
    a *= 10
    
ret = int(a / b)
print(ret)