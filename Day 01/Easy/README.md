# Largest Element in an Array

This program finds the **largest element** in a given array of integers.

## Problem Statement

Given an array of `n` integers, return the largest element present in the array.

## Brute Force Approach
- Sort the array in ascending order using a built-in sorting function.
- After sorting, the **last element** in the array will be the largest.
- **Return** the last element.

**Time Complexity** - O(n*logn)

**Space Complexity** - O(n)

## Thought Process for Optimizing
**1. Can we reduce the time complexity?**

Yes. Sorting takes O(n log n), which is unnecessary just to find the largest element.

**2. Then how can we find the largest element efficiently?**

By doing a linear scan of the array. We can maintain a variable (say, largest) and compare it with every element as we iterate.

**3. What happens during the scan?**

Every time we find an element greater than largest, we update it. This way, we’re only making one pass — which brings the time complexity down to O(n).

## Optimal Approach
- Initialize `largest = INT_MIN`.
- Traverse the array:
  - If `arr[i] > largest`, update `largest`.
- Return `largest`.
**Time Complexity** - O(n)
**Space Complexity** - O(1)
