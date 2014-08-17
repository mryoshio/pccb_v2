package main

import "fmt"

func d(a []int) {
  fmt.Print("-------> ")
  for i := 0; i < len(a); i++ {
    fmt.Printf("%d\t", a[i])
  }
  fmt.Println()
}

func solve(n int, rows [][]int) {
  last_one_per_row := make([]int, n, n+1)
  for i := 0; i < n; i++ {
    last_one_per_row[i] = -1
    for j := 0; j < n; j++ {
      if rows[i][j] == 1 { last_one_per_row[i] = j }
    }
  }
  swap := 0
  for i := 0; i < n; i++ {
    //    d(last_one_per_row)
    pos := -1
    for j := i; j < n; j++ {
      // mis! for j := i+1; j < n; j++ {
      if last_one_per_row[j] <= i {
        pos = j
        break
      }
    }
    for j := pos; j > i; j-- {
      tmp := last_one_per_row[j]
      last_one_per_row[j] = last_one_per_row[j-1]
      last_one_per_row[j-1] = tmp
      swap++
    }
    // fmt.Printf("swap: %d\n", swap)
  }
  fmt.Println(swap)
}

func main() {
  solve(2, [][]int {
    { 1, 0 },
    { 1, 1 },
  })
  solve(3, [][]int {
    { 0, 0, 1 },
    { 1, 0, 0 },
    { 0, 1, 0 },
  })
  solve(4, [][]int {
    { 1, 1, 1, 0 },
    { 1, 1, 0, 0 },
    { 1, 1, 0, 0 },
    { 1, 0, 0, 0 },
  })
}
