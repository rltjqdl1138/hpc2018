import sys
sys.setrecursionlimit(10**6)

par = [i for i in range(1001)]

def find(x):
    if par[x] == x:
        return x
    par[x] = find(par[x])
    return par[x]

def merge(x, y):
    par[x] = y


n = int(input())
p = []
for i in range(n):
    p.append([int(x) for x in sys.stdin.readline().strip().split()])

edges = []
for i in range(n):
    for j in range(i+1, n):
        edges.append((p[i][j], i, j))
edges.sort()

ans = 0
for e in edges:
    u = find(e[1])
    v = find(e[2])
    c = e[0]
    if u != v:
        merge(u, v)
        ans += c
print(ans)