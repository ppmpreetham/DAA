nums = [4,56,67,2]

def merge(nums):
    if len(nums) > 1:
        mid = len(nums) >> 1
        left = nums[:mid]
        right = nums[mid:]

        merge(left)
        merge(right)

        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                nums[k] = left[i]
                i += 1
            else:
                nums[k] = right[j]
                j += 1
            k += 1

        while(i < len(left)):
            nums[k] = left[i]
            i+=1
            r+=1
        while(j < len(right)):
            nums[k] = left[j]
            j+=1
            r+=1
            