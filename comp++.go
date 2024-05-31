package main

import (
	"fmt"
	"container/heap"
	"sort"
)

// Pair
/*=====================================*/
type pair struct {
	x int
	y int
}

func makePair(x, y int) *pair {
	p := pair{x: x, y: y}
	return &p
}

/*=====================================*/

// pq 
/*=====================================*/
type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func remove(h *MaxHeap, value int) {
	for i, v := range *h {
		if v == value {
			*h = append((*h)[:i], (*h)[i+1:]...)
			heap.Init(h)
			break
		}
	}
}

/* 
	declaring :
	pq := &MaxHeap{0}
	heap.Init(pq)

	heap.Push(pq, -s.y);
	remove(pq, s.y);
*/

/*=====================================*/

func main(){
	return 1;
}