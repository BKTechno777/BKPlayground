#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string palindrome;
        int length = 0;
        int start = 0;
        for (int i = 0;i<s.length(); i++)
        {
            int left = i;
            int right = i;

            /*For even length palindrome*/
            /*Expand from the center of the character towards left and right towrads start and end of string*/
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                if ((right - left +1) > length)
                {
                    start = left;
                    length = right - left + 1;
                }
                left--;
                right++;
            }

            /*For odd length palindrome*/
            left = i;
            right = i + 1;
            /*Expand from the center of the character towards left and right towrads start and end of string*/
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                if ((right - left + 1) > length)
                {
                    start = left;
                    length = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, length);
    }
};

int main()
{

    Solution mySol;
    cout << mySol.longestPalindrome("abba") << endl;
}