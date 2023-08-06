class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        flag = False
        for i in (range(n-2,-1,-1)):
            if nums[i] < nums[i+1]:
                for j in (range(n-1,i,-1)):
                    if nums[i] < nums[j]:
                        tmp = nums[i]
                        nums[i] = nums[j]
                        nums[j] = tmp
                        flag = True
                        nums[i+1:] = sorted(nums[i+1:])
                        break
            if flag == True:
                break
        if flag == False:
            nums.sort()