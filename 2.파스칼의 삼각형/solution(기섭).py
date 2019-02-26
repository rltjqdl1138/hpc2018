n,k=input().split()
arr = [[0]*31 for i in range(31) ]
n=int(n)
k=int(k)
for i in range (1,n+1):
    arr[i][i] = arr[i][1] = 1
    for j in range (2,i):
        arr[i][j]=arr[i-1][j]+arr[i-1][j-1]
print(arr[n][k])