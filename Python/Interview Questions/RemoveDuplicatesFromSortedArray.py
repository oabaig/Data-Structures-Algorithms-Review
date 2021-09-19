def removeDuplicates(nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        new_dict = dict()
        
        for num in nums:
            if num not in new_dict.keys():
                new_dict[num] = 0
            else:
                new_dict[num] += 1
                
        print(new_dict)
                
        for num in new_dict.keys():
            if new_dict[num] > 0:
                for i in range(new_dict[num]):
                    nums.remove(num)

nums = [0,0,1,1,1,2,2,3,3,4]

print(nums)

removeDuplicates(nums)

print(nums)
