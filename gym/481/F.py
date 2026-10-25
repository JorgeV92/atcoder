import sys


def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    n, m = data[0], data[1]
    graph = [[] for _ in range(n + 1)]
    index = 2
    for _ in range(m):
        a, b, c = data[index], data[index + 1], data[index + 2]
        graph[a].append((b, c))
        index += 3

    mod = 998244353
    ans = [0] * (n + 1)
    visited = bytearray(n + 1)
    visited[1] = 1
    groups = [[1]]

    while groups:
        next_groups = []
        for group in groups:
            for digit in range(1, 10):
                next_group = []
                for u in group:
                    for v, c in graph[u]:
                        if c != digit or visited[v]:
                            continue
                        visited[v] = 1
                        ans[v] = (ans[u] * 10 + c) % mod
                        next_group.append(v)
                if next_group:
                    next_groups.append(next_group)
        groups = next_groups

    sys.stdout.write("\n".join(map(str, ans[2:])) + "\n")


if __name__ == "__main__":
    main()
