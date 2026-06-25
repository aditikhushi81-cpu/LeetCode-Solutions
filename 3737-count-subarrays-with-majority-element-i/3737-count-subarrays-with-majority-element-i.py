class Solution:
    def countMajoritySubarrays(self, nums, target):
        ans = 0
        n = len(nums)

        for i in range(n):
            count = 0

            for j in range(i, n):

                if nums[j] == target:
                    count += 1

                length = j - i + 1

                if count > length // 2:
                    ans += 1

        return ans