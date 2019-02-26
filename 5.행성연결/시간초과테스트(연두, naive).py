import heapq

parent = [-1]*1000

def find(x) :
	if parent[x] < 0 :
		return x
	parent[x] = find(parent[x])
	return parent[x]

def merge(x, y) :
	x = find(x)
	y = find(y)
	if x == y :
		return
	if parent[x] < parent[y] :
		parent[x], parent[y] = parent[y], parent[x]
	parent[y] += parent[x]
	parent[x] = y


n = int(input())
arr = []
for i in range(n) :
	arr.append([int(x) for x in input().split()])

Q = []
for i in range(n) :
	for j in range(n) :
		if i == j :
			continue
		heapq.heappush(Q, (arr[i][j], i, j))

ans = 0
while Q :
	a = Q[0]
	heapq.heappop(Q)

	if find(a[1]) == find(a[2]) :
		continue
	merge(a[1], a[2])
	ans += a[0]
print(ans)
	