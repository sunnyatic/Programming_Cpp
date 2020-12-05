#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
	Roman Numerals:
	1    -> I
	5    -> V
	10   -> X
	50   -> L
	100  -> C
	500  -> D
	1000 -> M

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
	Follow similar logic for Tens and Ones
*/
string IntToRoman(int x)
{
	// create lookups for the 'special cases' i.e., 4/5/9, 40/50/90 and 400/500/900
	map<int, string> romansOnes = { {4, "IV"}, {5, "V"}, {9, "IX"} };
	map<int, string> romansTens = { {40, "XL" }, {50, "L"}, {90, "XC"} };
	map<int, string> romansHundreds = { {400, "CD"}, {500, "D"}, {900, "CM"} };
	
	string roman("");
	
	// THOUSANDS place
	if (x >= 1000)
	{
		int y = x / 1000;       // y represents the thousand's place
		roman.append(y, 'M');   // add as many 'M's as the thousand's place

		// done with thousands place. reduce the number to only contain the hundres/tens/ones
		x = x - (y * 1000);
	}

	// HUNDREDS place
	if (x >= 100)
	{
		int y = x / 100;  // y represents the hundred's place 
 
		if (y == 4 || y == 5 || y == 9)
			roman += romansHundreds[y * 100]; // use lookup for special cases (400/500/900)

		else   // y is either 1 or 2 or 3 or 6 or 7 or 8
		{
			int temp = y;
			if (y > 5)  
			{
				roman.append("D");    // 600, 700, 800 -> DC, DCC, DCCC respectively
				temp = y - 5; 
			}
			roman.append(temp, 'C');  // 100, 200, 300 -> C, CC, CCC respectively
		}

		// done with hundred's place. reduce the number to only contain the tens/ones
		x = x - (y * 100);
	}

	// TENS place
	if (x >= 10)
	{
		int y = x / 10;   // y represents the ten's place

		if (y == 4 || y == 5 || y == 9)
			roman += romansTens[y * 10];    // use lookup for special cases (40/50/90)    
		else 
		{
			int temp = y;
			if (y > 5)  // y is 6 or 7 or 8
			{
				roman.append("L");    // 60, 70, 80 -> LX, LXX, LXXX respectively
				temp = y - 5; 
			}
			roman.append(temp, 'X');  // 10, 20, 30 -> X, XX, XXX respectively
		}

		// done with ten's place. reduce the number to only contain the ones
		x = x - (y * 10);
	}

	// ONES place
	if (x >= 1)
	{
		if (x == 4 || x == 5 || x == 9)
			roman += romansOnes[x];    // use lookup for special cases (4/5/9)
		else
		{
			int temp = x;
			if (x > 5)  
			{
				roman.append("V");    // 6, 7, 8 -> VI, VII, VIII respectively
				temp = x - 5;
			}
			roman.append(temp, 'I');  // 1, 2, 3, -> I, II, III respectively
		}
	}
	return roman;
}

	

