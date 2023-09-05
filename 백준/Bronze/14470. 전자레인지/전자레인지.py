a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

ans = c * (-a) + d + b * e

if a >= 0:
	ans = (b-a) * e
print(ans)
