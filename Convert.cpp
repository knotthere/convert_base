// Philip Knott
// Period 4
// Computer Programming 1
// Classwork #10


#include "iostream"
#include "string"
#include <cassert>	// assert
#include <map>
#include <functional>
using namespace std;

// Propmpt the user for an Int.
bool getInt(string strPrompt, int& nInput)
{
	string strInput;
	cout << strPrompt;
	getline(cin, strInput);
	if ("" == strInput) {
		return false;	// All done
	} else {
		// Get the c style pointer to the string array
		const char* pStr = strInput.c_str();
		// Convert that to an integer
		// https://msdn.microsoft.com/en-us/library/yd5xkb5c.aspx
		nInput = atoi(pStr);
		return true;
	}
}

// Convert a base 10 integer (one that uses ten characters per digit) to another base, such
// as base 16.
int Convert()
{
	int 	nBase = 16,		// What base do you want to conver to?
			nInput = 0;

	// Use the string array for mapping from decimal to the new base
	string strMap = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// Ask for the new base
	if (!getInt("Convert base 10 integers to this base: ", nBase)) {
		return 0;	// We are done
	}

	while (getInt("Integer to convert: ", nInput)) {
		// Now, iterate over the passed integer, and collect each right-most remainder in base format
		string strOutput;
		do {
			int nRemainder = nInput % nBase;
			// Simply assert what we expect...
			assert((nRemainder >= 0) && (nRemainder < nBase));

			// Get the character at this indicie in our array
			const char chDigit = strMap[nRemainder];
			// and pre-pend it to out output string
			strOutput = chDigit + strOutput;

			// Reset out input variable, for the next digit
			nInput = (int)(nInput / nBase);
		} while (nInput > 0);

		cout << strOutput;
		cout << "\n";
	}

	return 0;
}


int main(int argc, const char * argv[])
{
	Convert();
}

