package main

import "fmt"

func extgcd(a int, b int, x *int, y *int) int {
	d := a
	if b != 0 {
		d = extgcd(b, a%b, y, x)
		*y -= (a / b) * *x;
	} else {
		*x = 1; *y = 0
	}
	return d
}

func main() {
	x := 0
	y := 0
	extgcd(4, 11, &x, &y)
	fmt.Printf("x: %d, y: %d\n", x, y)
}
