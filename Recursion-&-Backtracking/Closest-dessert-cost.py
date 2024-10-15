class Solution:
    def __init__(self):
        self.t: int = 0  

    def is_close(self, a: int, b: int) -> int:
        if a == b:
            return b

        if b == 0:
            return a

        if abs(self.t - a) == abs(self.t - b):
            return a if a < b else b
        
        return a if abs(self.t - a) < abs(self.t - b) else b

    def dfs(self, i: int, sum: int, a: List[int]) -> int:
        if i >= len(a):
            return sum

        pick: int = self.dfs(i + 1, sum + a[i], a)
        not_pick: int = self.dfs(i + 1, sum, a)
        pick_twice: int = self.dfs(i + 1, sum + 2 * a[i], a)

        return self.is_close(pick, self.is_close(not_pick, pick_twice))

    def closestCost(self, bc: List[int], tc: List[int], target: int) -> int:
        ans: int = 0
        self.t = target  

        for base in bc:
            ans = self.is_close(self.dfs(0, base, tc), ans)
        
        return ans
