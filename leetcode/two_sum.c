/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_sum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:27:34 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/10/03 13:08:08 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** *//*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?*/

#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	*returnSize = 2;
	int *result = malloc(sizeof(int) * 2);
	if (!result)
		return (NULL);
	int i = 0;
	while (i < numsSize)
	{
		int z = i + 1;
		while (z < numsSize)
		{
			if (nums[i] + nums[z] == target)
			{
				result[0] = i;
				result[1] = z;
				return (result);
			}
			z++;
		}
		i++;
	}
	free (result);
	return (NULL);
}

#include <stdio.h>
int	main(void)
{
	int nums[] = {3, 2, 4};
	int target = 6;
	int numsSize = 3;
	int returnSize = 0;
	int *result = twoSum(nums, numsSize, target, &returnSize);
	int i = 0;
	while (i < 2)
	{
		printf("result[%i]: %i\n", i, result[i]);
		i++;
	}
	free(result);
}
