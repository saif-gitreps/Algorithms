class Solution:
    def findComplement(self, num: int) -> int:
        mask = 1
        while mask <= num:
            mask = mask << 1
        mask -= 1

        return mask ^ num
        
        # create a mask of that number's binary length.
        # for 5, binary is 101, length is 3, a mask is all 1s of lenght 3
        # loop till we get the mask. for 5, loop will end at 1000 (decimal 8), -1. 0111,
        # which is 111. Then we XOR mask with the original number. 101 ^ 111 = 010
