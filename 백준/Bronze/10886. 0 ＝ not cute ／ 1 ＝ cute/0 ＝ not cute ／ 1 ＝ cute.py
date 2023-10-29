n = int(input())

cute = 0

for i in range(n):
    cute += int(input())

if cute > (n//2):
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")