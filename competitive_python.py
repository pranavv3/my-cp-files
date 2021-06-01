import math
n, k = map(int, input().split())
x=list(map(int, input().split())) #array

ans=0
for i in range (1, 1<<k):
    cnt=0
    prod=1
    for j in range (0, k):
        if ((1<<j)&i):
            cnt=cnt+1
            prod*=x[j]
    nums=math.floor(n/prod)
    if (cnt%2==0):
        ans-=nums
    else:
        ans+=nums
print(ans)
    
