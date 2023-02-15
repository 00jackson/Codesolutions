The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.


class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        num.reverse()
        i = 0
        while k:
            digit = k % 10 #4 - 3
            if i < len(num):
                num[i] += digit # skip \/ - 1234
            else:
                num.append(digit) #1204 - skip
            
            carry = num[i] // 10 #0 - 0
            num[i] = num[i] % 10 #0 - 3

            k = k//10 #3 - 0
            k += carry #3+0 - 0 + 0
            i += 1 #1 - 2
        num.reverse()
        return num
