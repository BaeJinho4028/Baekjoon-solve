import sys

input = sys.stdin.readline

n = int(input())
st = []

for _ in range(n):
    a = int(input())

    while st and st[-1] <= a:
        st.pop()
    st.append(a)

print(len(st))