#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

class Solution {
public:
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
        
        return isNegative? -reverseNum: reverseNum;
    }
};

int main()
{
    Solution mySol;
    cout<<mySol.reverse(-2147483648) << endl;
}