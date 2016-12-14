// Philip Knott
// Period 4
// Computer Programming 1
// Classwork #10


#include "iostream"
#include "string"
#include <cassert>    // assert
#include <map>
#include <stdlib.h>

using namespace std;

// Propmpt the user for an Int.
bool getInt(string strPrompt, int& nInput)
{
    string strInput;
    cout << strPrompt;
    getline(cin, strInput);
    if ("" == strInput) {
        return false;    // All done
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
    // Use the string array for mapping from decimal to the new base (up to 36)
    const string strMap = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Ask for the new base
    int nBase = 0;  // What base do you want to conver to?
    if (!getInt("Convert base 10 integers to this base: ", nBase)) {
        return 0;   // We are done
    } else if ((nBase < 1) || (nBase > 36)) {
        cout << "Target base must be greater than 0 and less than 37.";
        return 1;   // Error condition
    }

    int nInput = 0;
    while (getInt("Integer to convert: ", nInput)) {
        // Let's show 5 numbers around the one entered, 2 before and 2 after...
        int nBegInput = nInput - 2,
            nEndInput = nInput + 2;
        for (int nCurInput = nBegInput; nCurInput <= nEndInput; nCurInput++) {
            // Now, iterate over the integer, and collect each right-most remainder in base format
            string strOutput;
            int nWorkingInput = nCurInput;  // Use this variable for computations
            do {
                int nRemainder = nWorkingInput % nBase;
                // Simply assert what we expect...
                //assert((nRemainder >= 0) && (nRemainder < nBase));

                // Get the character at this indicie in our array
                const char chDigit = strMap[nRemainder];
                // and pre-pend it to out output string
                strOutput = chDigit + strOutput;

                // Reset out input variable, for the next digit
                nWorkingInput = (int)(nWorkingInput / nBase);
            } while (nWorkingInput > 0);

            cout << to_string(nCurInput) + ": ";
            cout << strOutput;
            cout << "\n";
        }
    }

    return 0;   // Success condition
}


int main(int argc, const char * argv[])
{
    Convert();
}

