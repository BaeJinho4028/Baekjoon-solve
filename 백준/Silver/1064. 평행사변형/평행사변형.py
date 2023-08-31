ax, ay, bx, by, cx, cy = map(int, input().split())

if ((ax-bx)*(ay-cy)==(ay-by)*(ax-cx)):
    print(-1.0)
    exit(0)

ab_len = ((ax-bx)**2 + (ay-by)**2)**0.5
ac_len = ((ax-cx)**2 + (ay-cy)**2)**0.5
bc_len = ((bx-cx)**2 + (by-cy)**2)**0.5

len = [ab_len+ac_len, ab_len+bc_len, ac_len+bc_len]
print( 2 * (max(len) - min(len)))