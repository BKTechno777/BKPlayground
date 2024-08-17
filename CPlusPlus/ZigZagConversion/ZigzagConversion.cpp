#include <iostream>
using namespace std;


class Solution
{
public:
	string convert(string s, int numRows)
	{
		string convertedString = "";
		/*Create a 2D array to store the characters*/
		char** zigzagArray = new char*[numRows];
		int numCols = s.length();
		for (int i = 0; i < numRows; i++)
		{
			zigzagArray[i] = new char[numCols]();
		}

		int row = 0;
		int col = 0;
		bool startDown = true;
		for (const char& ch : s)
		{
			zigzagArray[row][col] = ch;
			
			if (row == 0)
			{
				startDown = true;
			}
			if (row == numRows - 1 || numRows == 1)
			{
				startDown = false;
			}

			if (startDown == true)
			{
				row++;
			}
			else
			{
				if (numRows > 1)
				{
					row--;
				}
				col++;
			}
		}
		
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				if (zigzagArray[i][j] != '\0')
				{
					convertedString += zigzagArray[i][j];
				}
			}
		}

		/*Deallocate memory*/
		for (int i = 0; i < numRows; i++)
		{
			delete[] zigzagArray[i];
		}
		delete[] zigzagArray;

		return convertedString;
	}
};

int main()
{
	Solution mySol;
	cout << mySol.convert("AB", 1) << endl;
}