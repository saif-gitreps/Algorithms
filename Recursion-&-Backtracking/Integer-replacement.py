class Solution:
# this worked without memo
    def integerReplacement(self, n: int) -> int:
        def kev(n: int) -> int:
            if n == 1:
                return 0
            
            if n % 2 == 0:
                return 1 + kev(n / 2)
            else:
                return 1 + min(kev(n + 1), kev(n - 1))

        return kev(n)



class Solution:
# this one with map worked, using an array dp gave TLE
    def integerReplacement(self, n: int) -> int:
        def kev(n: int) -> int:
            if n == 1:
                return 0
            
            if n % 2 == 0:
                return 1 + kev(n / 2)
            else:
                return 1 + min(kev(n + 1), kev(n - 1))

        return kev(n)

        
