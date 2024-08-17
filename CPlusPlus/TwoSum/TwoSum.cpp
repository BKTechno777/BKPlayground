#include <iostream>
#include <vector>
using namespace std;


vector<int> TwoSum(vector<int>& nums, int target )
{
	vector<int> result;
	for (int i = 0; i < nums.size()-1; i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				result.insert(result.end(), { nums[i], nums[j] });
			}
		}
	}
	return result;
}

int main()
{
	vector<int> nums = { 3, 2, 4 };
	int target = 6;

	vector<int> res = TwoSum(nums, target);
	for (auto val : res)
	{
		cout << val << endl;
	}
	return 0;
}