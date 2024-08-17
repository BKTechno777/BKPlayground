#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLength = 0;

		string nonRepStr;
		for (const char& ch : s)
		{
			if (nonRepStr.size() > 0 && nonRepStr.back() == ch)
			{
				nonRepStr.clear();
				nonRepStr += ch;
			}
			else if (nonRepStr.find(ch) == std::string::npos)
			{
				nonRepStr += ch;
			}
			else
			{
				nonRepStr.clear();
			}
			if (nonRepStr.length() > maxLength)
			{
				maxLength = nonRepStr.length();
			}
		}

		return maxLength;
	}
	int lengthOfLongestSubstringMap(string s)
	{
		std::unordered_map<char, int> charMap;
		int l = 0;
		int r = 0;
		int maxLength = 0;
		for (const char& ch : s)
		{
			if (charMap.find(ch) != charMap.end() and charMap[ch] >= l)
			{
				l = charMap[ch] + 1;
			}
			else
			{
				maxLength = max(maxLength, r - l + 1);
			}
			charMap[ch] = r;
			r++;
		}
		return maxLength;
	}


};


int main()
{
    Solution sol;
    cout << sol.lengthOfLongestSubstringMap("dvdffdeklm") << endl;
}