#include <iostream>
#include <string>
#include <map>
using namespace std;

string IntToRoman(int x)
{
	//map<int, string> romansOnes = { {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"} };
	//map<int, string> romansTens = { {10, "X"}, {40, "XL" }, {50, "L"}, {90, "XC"} };
	//map<int, string> romansHundreds = { {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"} };
	//map<int, string> romansThousands = { {1000, "M" } };

	string roman("");
	
	// thousand's place
	if (x >= 1000)
	{
		int y = x / 1000;
		roman.append(y, 'M');

		// done with thousands place. reduce the number to only contain the hundres/tens/ones
		x = x - (y * 1000);
	}

	// hundred's place
	if (x >= 100)
	{
		int y = x / 100; // y represents the hundred's place number

		// if we end up in this if loop, it means y will be non-zero 
		if (y == 4)
			roman.append("CD"); //400 --> "CD"
		else if (y == 5)
			roman.append("D");  //500 --> "D" 
		else if (y == 9)
			roman.append("CM"); //900 --> "CM"

		// y is either 1 or 2 or 3 or 6 or 7 or 8
		else
		{
			if (y > 5) // if y is 6/7/8
			{
				roman.append("D");
				roman.append(y - 5, 'C');   //600, 700, 800 -> DC, DCC, DCCC respectively
			}
			else      // if y is 1/2/3
			{
				roman.append(y, 'C'); //100, 200, 300 -> C, CC, CCC respectively
			}
		}

		// done with hundred's place. reduce the number to only contain the tens/ones
		x = x - (y * 100);
	}

	// ten's place
	if (x >= 10)
	{
		int y = x / 10;
		if (y == 4)
			roman.append("XL"); //40 --> "XL"
		else if (y == 5)
			roman.append("L");  //50 --> "L" 
		else if (y == 9)
			roman.append("XC"); //90 --> "XC"
		else 
		{
			if (y > 5)
			{
				roman.append("L");
				roman.append(y - 5, 'X'); //60, 70, 80 -> LX, LXX, LXXX respectively
			}
			else 
				roman.append(y, 'X'); //10, 20, 30 -> X, XX, XXX respectively
		}

		// done with ten's place. reduce the number to only contain the ones
		x = x - (y * 10);
	}

	if (x >= 1)
	{
		if (x == 4)
			roman.append("IV"); //4 --> "IV"
		else if (x == 5)
			roman.append("V");  //5 --> "V" 
		else if (x == 9)
			roman.append("IX"); //9 --> "IX"
		else 
		{
			if (x > 5)
			{
				roman.append("V");
				roman.append(x - 5, 'I'); //6, 7, 8 -> VI, VII, VIII respectively
			}
			else
				roman.append(x, 'I'); //1, 2, 3 -> I, II, III respectively
		}
	}
	return roman;
}


	

	/*
	Pesuedo code:
	Thousands:
		- For this problem the constraint is input number should be < 3999
		- So for the Thousands part, we just repeat 'M' 'n' times where n is the # of Thousands (n = (int)(number/1000))
	Hundreds:
		- Let's say temp = (Number / 100);
		- If temp == 5, then D
		- If (temp > 5 && temp != 9) , then D followed by C repeated temp times (700 = DCC)
		- If (temp == 9), then CM
		- If (temp < 5 && temp != 4), then repeat C temp times (300 = CCC)
		- If (temp == 4), then CD
	Tens:


	Ones:

	1 -> I
	2 -> II
	3 -> III
	4 -> IV
	5 -> V
	6 -> VI
	7 -> VII
	8 -> VIII
	9 -> IX
	10 -> X

	2449 -> MMCDXLIX
	Step 1: 2449/1000 = 2 -> MM
	Step 2: 2449 - 1000 * 2449/1000 = 449 (Num2)
	Step 3: If (Num2  > 500) 
			{ 
			   (Num2 - 500)/100

			} 
	        else if (Num2 (i.e.,449) < 500) 
			{
				500-449 < 100 -> which means its a 400+ number, so it is CD
			}
	
	
	*/

