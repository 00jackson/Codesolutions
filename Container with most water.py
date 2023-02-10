# Ques: 
# You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

# Find two lines that together with the x-axis form a container, such that the container contains the most water.

# Return the maximum amount of water a container can store.

# Notice that you may not slant the container.


# Solution:

        class Solution:
    def maxArea(self, height: List[int]) -> int:
        p1 = 0 # first (left) pointer
        p2 = len(height) - 1 #second (right) pointer
        max_area = 0
        while p1 != p2:
            if height[p1] > height[p2]:
                area = height[p2] * (p2 - p1) #height of smaller edge multiples on length 
                p2 -= 1#changing smaller edge
            
            else:
                area = height[p1] * (p2 - p1)
                p1 += 1
            if area > max_area: max_area = area #increasing max area if possible
        return max_area
