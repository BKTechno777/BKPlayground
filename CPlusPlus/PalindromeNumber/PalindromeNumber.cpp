#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        bool isPalimdromeInteger = false;
        if (x > 0)
        {
            int reverseNum = reverse(abs(x));
            if (reverseNum == x)
            {
                isPalimdromeInteger = true;
            }
        }
        return isPalimdromeInteger;
    }

    int reverse(int x) {
        int reverseNum = 0;
        bool isNegative = x < 0;
        int newNum = std::abs(x);
        int quotiont = 0;
        while (newNum != 0)
        {
            quotiont = newNum % 10;
            newNum = newNum / 10;
            if (reverseNum > (numeric_limits<int>::max() / 10) || (reverseNum == numeric_limits<int>::max() / 10 &&
                quotiont > numeric_limits<int>::max() % 10))
            {
                reverseNum = 0;
            }
            else
            {
                reverseNum = reverseNum * 10 + quotiont;
            }
        }

        return isNegative ? -reverseNum : reverseNum;
    }
};

int main()
{
	cout << "Hello World" << endl;
}