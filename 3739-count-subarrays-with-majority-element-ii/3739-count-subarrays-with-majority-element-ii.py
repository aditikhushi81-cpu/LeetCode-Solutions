from typing import List

class BinaryIndexedTree:
    __slots__ = ("n", "c")

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int) -> None:
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        tree = BinaryIndexedTree(2 * n + 1)

        # Shift prefix sum to avoid negative indices
        s = n + 1
        tree.update(s, 1)

        ans = 0

        for x in nums:
            if x == target:
                s += 1
            else:
                s -= 1

            ans += tree.query(s - 1)
            tree.update(s, 1)

        return ans