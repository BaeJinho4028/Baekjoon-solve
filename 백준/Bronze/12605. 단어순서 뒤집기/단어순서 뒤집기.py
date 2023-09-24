import sys

input = sys.stdin.readline

n = int(input())

for i in range(0, n):
    st = input().split()
    print("Case #" + str(i+1) + ":", end=" ")
    for _ in range(len(st)):
        print(st.pop(), end=" ")
    print()