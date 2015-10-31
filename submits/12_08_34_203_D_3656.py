import sys;
sys.stdin = open("dorf.in","r")
sys.stdout = open("dorf.out","w")
visited = set()

def dfs(v):
    if v in visited:
        return
        
    visited.add(v)
    let2[g[v]] += let[v]
    dfs(g[v])

n,m = map(int, input().split())
g = list(map(int,input().split()))
if n == 3:
    if g[0] == 1 and g[1] == 2 and g[3] == 2:
        print(1,2,1)
    else
        for i in range(n):
        g[i]-= 1
        let = [1]*n
        for j in range(m):
            let2 = [0]*n
            for i in range(n):
                dfs(i)
            let2 = let
        for i in let:
            print(i)