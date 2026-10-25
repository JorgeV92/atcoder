package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var N, M, S, T int
	fmt.Fscan(in, &N, &M, &S, &T)
	graph := make([][]int, N+1)
	smallest := make([]int, N+1)
	for i := range smallest {
		smallest[i] = N + 1
	}
	for i := 0; i < M; i++ {
		var A, B int
		fmt.Fscan(in, &A, &B)
		graph[A] = append(graph[A], B)
		if B < smallest[A] {
			smallest[A] = B
		}
	}

	const INF = int(1e9)
	dist := make([]int, N+1)
	for i := range dist {
		dist[i] = INF
	}
	dist[S] = 0
	dq := list.New()
	dq.PushFront(S)
	for dq.Len() > 0 {
		u := dq.Remove(dq.Front()).(int)
		d := dist[u]
		for _, v := range graph[u] {
			w := 1
			if v == smallest[u] {
				w = 0
			}
			if dist[v] > d+w {
				dist[v] = d + w
				if w == 0 {
					dq.PushFront(v)
				} else {
					dq.PushBack(v)
				}
			}
		}
	}
	if dist[T] == INF {
		fmt.Fprintln(out, -1)
	} else {
		fmt.Fprintln(out, dist[T])
	}
}
