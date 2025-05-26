# Two Sum Problem

This repository contains the solution to the classic **2 Sum problem** — finding indices of two numbers in an array that add up to a given target.

## Problem Statement

Given an array `arr` of size `n` and a target value `target`, return the **indices** of the two numbers such that they add up to the target.

You may assume that each input has **exactly one solution**, and you may not use the same element twice.

## Brute Force Approach
- Check every possible pair of numbers.
- For each element, iterate over the rest to find if a pair sums to the target.
- Time Complexity: **O(n²)**
- Space Complexity: **O(1)**

## Thought Process for Optimizing

- Can we do better than O(n²) brute force?  
  **Yes!** Brute force checks all pairs, which is expensive.

- How to reduce time complexity?  
  We can use extra space (hash map) to track elements we’ve seen and check for complements in O(1).

- What happens during iteration?  
  For each element, we check if its complement exists. If yes, we’ve found our pair in constant time.

## Optimal Approach
- Use a hash map to store elements and their indices.
- For each element `num`, check if `target - num` exists in the map.
- If yes, return the pair of indices.
- Otherwise, add the current element and its index to the map.
- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

## Optimal Approach without Using Hash Map  
**Two Pointer Approach**

- Sort the array first.
- Use two pointers: one at the start, one at the end.
- Calculate the sum of elements at the two pointers:
  - If sum equals target, return the pair.
  - If sum is less, move the left pointer forward.
  - If sum is more, move the right pointer backward.
- Continue until pointers meet.
- Time Complexity: **O(n*logn)**
- Space Complexity: **O(1)**

### Important Note:
- This method finds the pair values efficiently in **O(n*log n)** due to sorting.
- **However, it does NOT return the original indices** because sorting changes element positions.
- To get original indices, additional bookkeeping is needed (e.g., storing element-value and original-index pairs before sorting).

### When to use:
- When only the values matter (not indices).
- When extra space is constrained and hashing is not preferred.
