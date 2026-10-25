package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Point struct {
	x int64
	y int64
}

func cross(a, b Point) int64 {
	return a.x*b.y - a.y*b.x
}

func upper(p Point) bool {
	return p.y > 0 || (p.y == 0 && p.x > 0)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var T int
	fmt.Fscan(in, &T)
	for ; T > 0; T-- {
		var N int
		fmt.Fscan(in, &N)
		p := make([]Point, N)
		for i := range p {
			fmt.Fscan(in, &p[i].x, &p[i].y)
		}
		sort.Slice(p, func(i, j int) bool {
			if upper(p[i]) != upper(p[j]) {
				return upper(p[i])
			}
			return cross(p[i], p[j]) > 0
		})
		p = append(p, make([]Point, N)...)
		copy(p[N:], p[:N])

		ans, j := 1, 0
		for i := 0; i < N; i++ {
			if j < i {
				j = i
			}
			for j+1 < i+N && cross(p[i], p[j+1]) > 0 {
				j++
			}
			if j-i+1 > ans {
				ans = j - i + 1
			}
		}
		fmt.Fprintln(out, ans)
	}
}
