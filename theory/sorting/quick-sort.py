nums = [4,56,67,2]

def quick(nums):
    if len(nums) <= 1:
        return nums
    pivot = nums[len(nums)>>1]
    left = [x for x in nums if x < pivot]
    mid = [x for x in nums if x == pivot]
    right = [x for x in nums if x > pivot]
    return quick(left) + mid + quick(right)

