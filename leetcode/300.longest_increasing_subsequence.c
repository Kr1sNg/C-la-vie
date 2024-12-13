/*
Given an integer array nums, return the length of the longest strictly increasing
subsequence
.
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/

int ft_max(int* nums, int numsSize)
{
    int i = 0;
    int maxi = 0;
    
    while (i < numsSize)
    {
        if (maxi < nums[i])
            maxi = nums[i];
        i++;
    }
    return (maxi);
}

void    ft_bzero(int *nums, int numsSize)
{
    int i = 0;

    while (i < numsSize)
    {
        nums[i] = 0;
        i++;
    }
}

int lengthOfLIS(int* nums, int numsSize)
{
    int len_list[numsSize];
    int i = 1;
    int j = 0;
    int max_len;

    ft_bzero(len_list, numsSize);
    while (i < numsSize)
    {
        j = 0;
        while (j < i)
        {
            if (nums[i] > nums[j])
                if (len_list[i] < len_list[j] + 1)
                    len_list[i] = len_list[j] + 1;
            j++;
        }
        i++;
    }
    max_len = ft_max(len_list, numsSize) + 1;
    return (max_len);
}

#include <stdio.h>
int main(void)
{
    int nums[9] = {0,1,0,3,2,3};
    int max_len = lengthOfLIS(nums, 9);
    printf("%i\n", max_len);
}


