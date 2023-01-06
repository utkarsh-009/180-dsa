/*
Find the element that appears once in a sorted array, and the rest element appears twice.

Problem Statement: You are given a sorted array consisting of only integers where every element appears exactly twice,
except for one element which appears exactly once. Return the single element that appears only once.

    Input: nums = [1,1,2,3,3,4,4,8,8]
    Output: 2
*/

// Better Solution: Using XOR [TC: O(n), AS: O(1)]
/*
As every number in the array repeats twice and only one number occurs once, we can take advantage of the XOR(^) operator.
As: 1.) p^p=0, 2.) p^0=p => All the twice occuring numbers will vanish after using XOR operations
*/
class Solution1
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {

        int Xor = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            Xor ^= nums[i];
        }

        return Xor;
    }
};

// Efficient Solution: Using Binary Search [TC: O(logn), AS: O(1)]
/*
-> Using Pair Index Property: According to this property, the first of twice occuring element will occur at even index and
second of twice occuring element will be at odd index and as soon as element with one occurence in encountered, it will
disrupt the pattern and first of twice occuring element will occur at odd index and second of twice occuring element
will be at even index

Left Half: first of twice occuring element will occur at even index and second of twice occuring element will be at odd index
Right Half: first of twice occuring element will occur at odd index and second of twice occuring element will be at even index

-> Using Unique Element Property: As the element only occurs once in the array => nums[i-1] != nums[i] && nums[i] != nums[i+1]
*/
class Solution2
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {

        int n = nums.size();
        int low = 0, high = n - 1, mid = 0;

        // Corner Cases:
        if (n == 1) // when size is 1
            return nums[0];
        else if (nums[0] != nums[1]) // when first and second element not equal
            return nums[0];
        else if (nums[n - 1] != nums[n - 2]) // when last and second last element not equal
            return nums[n - 1];

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            // Unique Element Property
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            // Pair Index Property
            else if (mid % 2 == 0 && nums[mid] == nums[mid + 1] || mid % 2 == 1 && nums[mid] == nums[mid - 1]) // the mid is in left half
            {
                low = mid + 1; // trim the left half
            }
            else // the mid is in right half
            {
                high = mid - 1; // trim the right half
            }
        }

        return -1;
    }
};