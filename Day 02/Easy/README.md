# Second Largest and Second Smallest Element in an Array
This repository demonstrates three different approaches to find the **second largest** and **second smallest** elements in an integer array using C++.
## Problem Statement
Given an array, find the second smallest and second largest elements.  
If either of them doesn’t exist, print `-1`.
## Brute Force Approach
- Sort the array in ascending order.
- The second largest element will be at index `n-2`.
- The second smallest element will be at index `1`.
- **Time Complexity:** `O(n log n)`  
- **Space Complexity:** `O(1)`
> ⚠️ This approach does **not** work correctly if the array contains duplicate values.
## Better Approach
- Traverse the array once to find the smallest and largest elements.
- Traverse it again to find the second smallest and second largest, excluding the previously found values.
- **Time Complexity:** `O(n) + O(n)`  
- **Space Complexity:** `O(1)`
## Optimal Approach
- We use four variables: small, second_small, large, and second_large.
- Initialize small and second_small to INT_MAX, and large and second_large to INT_MIN.
- Second Smallest Logic:
  - If the current element is less than small, we update both second_small and small.
  - Else if the element is less than second_small and not equal to small, we update only second_small.
  - After the loop, second_small holds the second smallest value.
- Second Largest Logic:
  - If the current element is greater than large, we update both second_large and large.
  - Else if the element is greater than second_large and not equal to large, we update only second_large.
  - After the loop, second_large holds the second largest value.
- This approach ensures that we find both values in just one pass through the array, making it the most efficient.
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`
## Thought Process
> Breaking down how we improve from the brute-force approach to the optimal one.

**Can we improve from O(n*logn)?**  
Yes — by avoiding sorting, we can bring down the time complexity.

**How can we avoid sorting?**  
Instead of sorting, we can first find the smallest and largest elements. Then, using them as references, we look for the next smallest and next largest values.

**Can we make it even more efficient?**  
Absolutely! Instead of using two separate passes, we can update all four values — `smallest`, `second_smallest`, `largest`, and `second_largest` — in a single traversal.

**How does that work?**  
While going through each element:
- If an element is greater than the current `largest`, it becomes the new `largest`, and the previous `largest` becomes `second_largest`.
- Similarly, if an element is smaller than the current `smallest`, it becomes the new `smallest`, and the previous `smallest` becomes `second_smallest`.

This way, we get both values in just one pass — making the approach both optimal and elegant.
