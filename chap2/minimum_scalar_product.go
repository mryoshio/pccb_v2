package main

import "fmt"
import "sort"

func solve(n int, v1 []int, v2 []int) {
  sort.Sort(sort.IntSlice(v1))
  sort.Sort(sort.Reverse(sort.IntSlice(v2)))
  sum := 0
  for i := 0; i < n; i++ {
    sum += v1[i] * v2[i];
  }
  fmt.Println(sum)
}

func main() {
  solve(3, []int { 1, 3, -5 }, []int { -2, 4, 1 })
  solve(5, []int { 1, 2, 3, 4, 5 }, []int { 1, 0, 1, 0, 1 })
}
