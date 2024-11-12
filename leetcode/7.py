class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        return heapq.nlargest(k, freq, key=lambda x:freq[x])
