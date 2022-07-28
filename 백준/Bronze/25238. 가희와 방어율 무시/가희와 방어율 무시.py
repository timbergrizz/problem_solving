a, b = map(int, input().split())
print(int(int((a / 100) * (100 - b)) < 100))