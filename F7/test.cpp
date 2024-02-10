#include <fstream> 
#include <iostream> 
using namespace std; 
int main() {
    ifstream file("example.txt"); // Open the file "example.txt" for reading
    if (!file) { // Check if the file was not opened successfully
        cerr << "Error opening file" << endl; // Output error message to the standard error stream
        return 1; 
    }

    // Initialize counters for each type of assignment operator
    int countEqual = 0, countPlusEqual = 0, countStarEqual = 0, countMinusEqual = 0, countSlashEqual = 0, countPercentEqual = 0;
    char prevChar = '\0', ch; // Initialize previous character to null character and declare current character variable

    // Read the file character by character
    while (file.get(ch)) {
        // Check if current character is '=' and not part of comparison or logical operators
        if (ch == '=' && prevChar != '=' && prevChar != '<' && prevChar != '>' && prevChar != '!' && prevChar != '&' && prevChar != '|') {
            // Use the value of the previous character to determine the type of assignment operator
            switch (prevChar) {
                case '+': countPlusEqual++; break; // Increment count for '+=' operator
                case '*': countStarEqual++; break; // Increment count for '*=' operator
                case '-': countMinusEqual++; break; // Increment count for '-=' operator
                case '/': countSlashEqual++; break; // Increment count for '/=' operator
                case '%': countPercentEqual++; break; // Increment count for '%=' operator
                default: countEqual++; break; // Increment count for simple '=' operator
            }
        }
        prevChar = ch; // Set previous character to current character for next iteration
    }

    // Output the counts of each assignment operator found in the file
    cout << "\tSimple assignment (=) count: " << countEqual << endl;
    cout << "\tPlus assignment (+=) count: " << countPlusEqual << endl;
    cout << "\tMultiplication assignment (*=) count: " << countStarEqual << endl;
    cout << "\tSubtraction assignment (-=) count: " << countMinusEqual << endl;
    cout << "\tDivision assignment (/=) count: " << countSlashEqual << endl;
    cout << "\tModulo assignment (%=) count: " << countPercentEqual << endl;

    file.close(); // Close the file
    return 0; // Return with success code 0
}
