class Solution:
    def permuteUnique(self, nums):
        res = []
        keys = set()
        
        def backtrack(ind, ds, flag):
            if len(ds) == len(nums):
                key = '_'.join(map(str, ds))
                if key not in keys:
                    keys.add(key)
                    res.append(ds[:])
                return
            
            for i in range(len(nums)):
                if not flag[i]:
                    ds.append(nums[i])
                    flag[i] = True
                    backtrack(i + 1, ds, flag)
                    ds.pop()
                    flag[i] = False
        
        backtrack(0, [], [False] * len(nums))
        return res
