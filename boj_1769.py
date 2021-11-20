num = input()
total = 0
counter = 0

while int(num) >= 10 :
    total = sum(int(n) for n in num)
    counter += 1
    num = str(total)
    
num = int(num)

print(counter)
message = "YES" if num == 3 or num == 6 or num == 9 else "NO"
print(message)