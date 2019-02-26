arr = [ 0 for i in range(10001) ]
N=input()
 
for i in range(1,int(N)+1):
    start,end = input().split()
    for j in range ( int(start), int(end) ):
        arr[j]=1
sum=0
for i in range(1, 10001):
    if arr[i]==1:
        sum+=1
print(sum)