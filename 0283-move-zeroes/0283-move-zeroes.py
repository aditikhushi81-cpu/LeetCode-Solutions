class Solution:
    def moveZeroes(self, nums: List[int]) -> None:

        left = 0

        # Step 1: Move all non-zero elements to the front
        for right in range(len(nums)):

            if nums[right] != 0:

                nums[left] = nums[right]
                left += 1

        # Step 2: Fill the remaining positions with zeros
        while left < len(nums):

            nums[left] = 0
            left += 1