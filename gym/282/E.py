import sys 
input = sys.stdin.readline

class DSU:
    def __init__(self, n):
        self.e = [-1]*n

    def find(self, x: int):
        if self.e[x] < 0: return x
        self.e[x] = self.find(self.e[x]) 
        return self.e[x]

    def union(self, x, y):
        x = self.find(x); y = self.find(y)
        if x == y: return False 
        if self.e[x] > self.e[y]: x, y = y, x 
        self.e[x] += self.e[y]
        self.e[y] = x
        return True 

def modpow(a, e, mod):
    r = 1
    a %= mod 
    while e:
        if e&1: r = r * a % mod 
        a = a * a % mod 
        e >>= 1
    return r 

n, m = map(int, input().split())
A = list(map(int,input().split()))
edges = []
for i in range(n):
    for j in range(i+1,n):
        w = (modpow(A[i], A[j], m) + modpow(A[j], A[i], m)) % m
        edges.append((i,j,w))
edges.sort(key=lambda x: x[2], reverse=True)
d = DSU(n)
mst_sum = 0
for u, v, w in edges:
    if d.union(u, v): mst_sum += w 
print(mst_sum)
