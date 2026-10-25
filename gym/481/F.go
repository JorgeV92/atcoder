package main

import (
	"bufio"
	"fmt"
	"os"
)

type Edge struct {
	to    int
	digit int
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	const MOD = 998244353
	var N, M int
	fmt.Fscan(in, &N, &M)
	graph := make([][]Edge, N+1)
	for i := 0; i < M; i++ {
		var A, B, C int
		fmt.Fscan(in, &A, &B, &C)
		graph[A] = append(graph[A], Edge{B, C})
	}

	ans := make([]int, N+1)
	visited := make([]bool, N+1)
	visited[1] = true
	groups := [][]int{{1}}
	for len(groups) > 0 {
		var nextGroups [][]int
		for _, group := range groups {
			for digit := 1; digit <= 9; digit++ {
				var next []int
				for _, u := range group {
					for _, edge := range graph[u] {
						if edge.digit != digit || visited[edge.to] {
							continue
						}
						visited[edge.to] = true
						ans[edge.to] = (ans[u]*10 + edge.digit) % MOD
						next = append(next, edge.to)
					}
				}
				if len(next) > 0 {
					nextGroups = append(nextGroups, next)
				}
			}
		}
		groups = nextGroups
	}
	for v := 2; v <= N; v++ {
		fmt.Fprintln(out, ans[v])
	}
}
