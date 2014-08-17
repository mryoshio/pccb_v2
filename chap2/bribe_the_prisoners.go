package main

import "fmt"

func d(a []int) {
  for _, v := range a {
    fmt.Printf("%d\t", v)
  }
  fmt.Println()
}

func release(target int, targets []int, prisoners []int) {
  fmt.Println(target);
  d(targets)
}

func solve(p int, q int, a []int) {
  prisoners := make([]int, p)
  for i := 0; i < p; i++ { prisoners[i] = 1 }
  for i, v := range a {
    b := make([]int, len(a))
    copy(b, a)
    b = append(b[:i], b[i+1:]...)
    release(v, b, prisoners)
  }
}

func main() {
  solve(8, 1, []int { 3, 4, 5 })
}
