package main

import "fmt"
import "math"

const MAX_ML = 10000
const MAX_MD = 10000
const MAX_N = 1000

func main() {
	N := 4
	ML := 2
	MD := 1
	INF := math.MaxFloat64

	var al, bl, dl [MAX_ML]float64
	var ad, bd, dd [MAX_MD]float64

	al[0] = 1; al[1] = 2
	bl[0] = 3; bl[1] = 4
	dl[0] = 10; dl[1] = 20

	ad[0] = 2
	bd[0] = 3
	dd[0] = 3

	var d [MAX_N]float64

	for i := 0; i < N; i++ { d[i] = INF }
	d[0] = 0

	for k := 0; k < N; k++ {
		for i := 0; i+1 < N; i++ {
			if d[i+1] < INF {
				d[i] = math.Min(d[i], d[i+1])
			}
		}

		// al -> bl
		for i := 0; i < ML; i++ {
			if d[int(al[i]-1)] < INF {
				d[int(bl[i]-1)] = math.Min(d[int(bl[i]-1)], d[int(al[i]-1)] + dl[i])
			}
		}

		for i := 0; i < MD; i++ {
			if d[int(bd[i]-1)] < INF {
				d[int(ad[i]-1)] = math.Min(d[int(ad[i]-1)], d[int(bd[i]-1)] - dd[i])
			}
		}
	}

	var res = d[N-1]
	if d[0] < 0 {
		res = -1
	} else if res == INF {
		res = -2
	}
	fmt.Println(res)
}

