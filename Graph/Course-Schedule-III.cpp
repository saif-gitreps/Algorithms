// 22 / 100 cases. edge case { {5, 5} , {2, 6} , {4, 6} }. ans -> 2-6 and 4-6 . 

type Pair struct {
	first  int
	second int
}

type PairHeap []Pair

func (h PairHeap) Len() int           { return len(h) }
func (h PairHeap) Less(i, j int) bool { return h[i].first < h[j].first }
func (h PairHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *PairHeap) Push(x interface{}) {
	*h = append(*h, x.(Pair))
}

func (h *PairHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func scheduleCourse(courses [][]int) int {
    pq := &PairHeap{};
    heap.Init(pq); 

    for i, course := range courses {
        heap.Push(pq, Pair{first: (course[1] - course[0]), second: i });
    }

    time := 0;
    count := 0;

    for pq.Len() > 0 {
        front := (*pq)[0]
        if time + courses[front.second][0] <= courses[front.second][1] {
            time += courses[front.second][0];
            count++ ;
            heap.Pop(pq) ;
        } else {
            break;
        }
    }

    return count;
    
}
