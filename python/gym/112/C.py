import sys

def main():
    input = sys.stdin.readline
    n = int(input())
    par = list(map(int, input().split()))
    g = [[] for _ in range(n)]
    for u, p in enumerate(par, start=1):
        g[p-1].append(u)
    size = [1] * n
    diff = [0] * n
    for v in range(n-1,-1,-1):
        neg_even_sum = 0
        nonneg_even_sum = 0
        odd = []
        for u in g[v]:
            size[v] += size[u]
            if size[u] % 2 == 1:
                odd.append(diff[u])
            elif diff[u] < 0:
                neg_even_sum += diff[u]
            else:
                nonneg_even_sum += diff[u]
        odd.sort()
        cur = 1 
        cur += neg_even_sum
        for i, val in enumerate(odd):
            if i % 2 == 0:
                cur += val
            else:
                 cur -= val 
        if len(odd) % 2 == 0:
            cur += nonneg_even_sum
        else:
            cur -= nonneg_even_sum
        diff[v] = cur 
    tak = (n + diff[0]) // 2
    print(tak)

if __name__ == "__main__":
    main()
