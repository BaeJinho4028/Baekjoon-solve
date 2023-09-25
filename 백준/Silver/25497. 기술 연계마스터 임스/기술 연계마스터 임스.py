import sys

n = int(input())

a = input()

lr = []
sk = []
cnt = 0
for c in a:
    if c == "R":
        if lr and lr[-1] == "L":
            lr.pop()
            cnt += 1
        else:
            print(cnt)
            sys.exit() # 본 기술 실패 시 바로 종료
    elif c == "K":
        if sk and sk[-1] == "S":
            sk.pop()
            cnt += 1
        else:
            print(cnt)
            sys.exit()

    elif(c == 'L'):
        lr.append(c)
    elif(c == 'S'):
        sk.append(c)

    elif(c in "123456789") :
        cnt += 1

print(cnt)

