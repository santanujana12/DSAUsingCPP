#include <bits/stdc++.h>
using namespace std;

int maximizeRob(vector<int> &nums, int i)
{
    if (i >= nums.size())
    {
        return 0;
    }
    int rob = nums[i] + maximizeRob(nums, i + 2);
    int skip = maximizeRob(nums, i + 1);

    return max(rob, skip);
}

int rob(vector<int> &nums)
{
    return maximizeRob(nums, 0);
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums) << endl;
}