class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        res , l , r = 0 , 0 , 0
        while r < len(nums) - 1:
            farthest = 0
            for i in range( l , r + 1 ):
                n = i + nums[i]
                farthest = farthest if farthest > n else n
            l = r + 1
            r = farthest
            res += 1
        return res
