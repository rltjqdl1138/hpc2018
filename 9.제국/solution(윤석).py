n, m =  map(int, input().split())
stoi = {}
itos = {}
chk = [1] * n
parent = []
for i in range(n) :
	parent.append(i)

def find(x) :
	if parent[x] == x :
		return x
	parent[x] = find(parent[x])
	return parent[x]

def merge(pu, pv) :
	#print(itos[pu] + " win " + itos[pv] + " (merge)")
	parent[pv] = pu
	chk[pv] = 0

def merge_in(u, v) :
	#print(itos[u] + " win " + itos[v] + " (merge_in)")
	parent[u] = v
	parent[v] = v
	chk[u] = 0
	chk[v] = 1

tmp = []

for i in range(n):
    s = input()
    tmp.append(s);
tmp.sort()

for i in range(n):
    s = tmp[i]
    stoi[s] = i
    itos[i] = s
    chk[0] = 1

for T in range(m) :
    a,b,c = input().split(",")
    u = stoi[a]
    v = stoi[b]
    pu = find(u)
    pv = find(v)
    if c == "1" :
        if pu != pv :
            merge(pu, pv)
        elif pu == v :
            merge_in(v,u)
    else :
        if pu != pv :
            merge(pv, pu)
        elif pv == u :
            merge_in(u,v)

print(sum(chk))
for i in range(n) :
    if chk[i] == 1 :
        print(itos[i])

