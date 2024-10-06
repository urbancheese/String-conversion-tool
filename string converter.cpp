#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

// string to binary
string stringToBinary(const string& text) {
    string binaryStr = "";
    for (char c : text) {
        binaryStr += bitset<8>(c).to_string() + " "; // convert each character to an 8b it binary
    }
    return binaryStr;
}

// binary to string
string binaryToString(const string& binaryStr) {
    stringstream ss(binaryStr);
    string segment;
    string result = "";

    while (ss >> segment) {
        bitset<8> bits(segment);
        result += char(bits.to_ulong()); // binary to character
    }
    return result;
}

// convert string to hex
string stringToHex(const string& text) {
    stringstream ss;
    for (char c : text) {
        ss << hex << setw(2) << setfill('0') << (int)c; // convert each character to 2-digit hex
    }
    return ss.str();
}

// hex 
string hexToString(const string& hexStr) {
    string output = "";
    for (size_t i = 0; i < hexStr.length(); i += 2) {
        string byte = hexStr.substr(i, 2); // Get two hex characters
        char chr = (char)(int)strtol(byte.c_str(), nullptr, 16); // Convert hex to a char
        output += chr;
    }
    return output;
}

int main() {
    string input, binary, hexStr, choice;
    char continueChoice = 'y';  // Variable to keep the loop going

    while (continueChoice == 'y' || continueChoice == 'Y') {
        cout << "Choose conversion:\n";
        cout << "1. Text to Binary\n";
        cout << "2. Binary to Text\n";
        cout << "3. Text to Hex\n";
        cout << "4. Hex to Text\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        if (choice == "1") {
            cout << "Enter text: ";
            getline(cin, input); // Correctly take input for text
            binary = stringToBinary(input);
            cout << "Binary: " << binary << endl;
        }
        else if (choice == "2") {
            cout << "Enter binary string (space-separated 8-bit binary): ";
            getline(cin, input); // Use getline to get the entire binary string
            string text = binaryToString(input);
            cout << "Text: " << text << endl;
        }
        else if (choice == "3") {
            cout << "Enter text: ";
            getline(cin, input); // Correctly take input for text
            hexStr = stringToHex(input);
            cout << "Hex: " << hexStr << endl;
        }
        else if (choice == "4") {
            cout << "Enter hex string: ";
            getline(cin, hexStr); // Correctly take hex string input
            string text = hexToString(hexStr);
            cout << "Text: " << text << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        // Ask if the user wants to perform another conversion
        cout << "Do you want to perform another conversion? (y/n): ";
        cin >> continueChoice;
    }

    cout << "Exiting the program. Goodbye!" << endl;

    return 0;
}
