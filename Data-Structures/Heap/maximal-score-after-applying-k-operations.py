from queue import PriorityQueue

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        pq = PriorityQueue()
        ans:int = 0

        for num in nums:
            pq.put(-num)

        while k and not pq.empty():
            num: int = -pq.get()
            ans += num
            num = math.ceil(num / 3)
            pq.put(-num)
            k -= 1

        return ans



        
