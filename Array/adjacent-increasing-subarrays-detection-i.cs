public class Solution
{
    public bool isIncreasing(List<int> a)
    {
        if (a.Count() == 1) {
            return true;
        }
        
        for (int i = 1; i < a.Count; i++)
        {
            if (a[i - 1] >= a[i])
            {
                return false;
            }
        }
        return true;
    }

    public bool HasIncreasingSubarrays(IList<int> nums, int k)
    {
        List<List<int>> a = new List<List<int>>();

        for (int i = 0; i < nums.Count; i++)
        {
            int p = 0;
            List<int> temp = new List<int>();

            for (int j = i; j < nums.Count; j++)
            {
                if (p == k)
                {
                    // check operation
                    if (isIncreasing(temp))
                    {
                        a.Add(new List<int> { i, j - 1 });
                    }
                    break;
                }
                else
                {
                    temp.Add(nums[j]);
                    p++;
                }
            }
        }

        for (int i = 1; i < a.Count; i++)
        {
            // checking if subarrays are adjacent
            if (a[i][0] - a[i - 1][1] == 1)
            {
                return true;
            }
        }

        return false;
    }
}

public class Solution
  this works aparaently but i am not sure how
{
    public bool HasIncreasingSubarrays(IList<int> nums, int k)
    {
        int n = nums.Count;
        int count = 1; // length of current increasing sequence

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                count++;
            else
                count = 1;

            // Once we have 2 * k consecutive increasing elements,
            // that means we can form two adjacent k-length subarrays.
            if (count >= 2 * k)
                return true;
        }

        return false;
    }
}

