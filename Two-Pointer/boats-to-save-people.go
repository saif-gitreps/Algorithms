func numRescueBoats(people []int, limit int) int {
  // fakkk i forgot to read the question properly, we can save at most two people at the same time.
  // i was wondering how we could do two pointer on this.
    sort.SliceStable(people, func(i int, j int) bool{
        return people[i] > people[j];
    });

    left := 0;
    right := len(people) - 1;

    for left = 0; left <= right; left++ {
        if(people[left] + people[right] <= limit){
            right--;
        }
    }

    return left; 
}

/*
  more simplified :
        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                boatCount++;
                left++;
                right--;
            }
            else{
                boatCount++;
                right--;
            }
        }
        return boatCount;

*/
