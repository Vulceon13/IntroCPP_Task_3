#include "String.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

void WriteTestResults(const string& filename, const string& testName, bool result) 
{
    ofstream logFile;
    logFile.open(filename, ios::app); // Opens the file in append mode
    if (logFile.is_open()) 
    {
        logFile << testName << " " << (result ? "Successful" : "Failed") << endl;
        logFile.close();

    }
    else 
    {
        cout << "Unable to open log file!" << endl;
    }
}

int main()
{
    // Current date and time
    time_t currentTime = time(nullptr);
    struct tm localTimeStruct;
    localtime_s(&localTimeStruct, &currentTime);

    // Open the log file
    ofstream logFile;
    logFile.open("test_log.txt", ios::app); // Open the file in append mode
    if (logFile.is_open()) {
        
        // Write date and time to the log file
        char dateBuffer[20];
        char timeBuffer[20];
        strftime(dateBuffer, sizeof(dateBuffer), "%x", &localTimeStruct);
        strftime(timeBuffer, sizeof(timeBuffer), "%X", &localTimeStruct);
        logFile << "Date: " << dateBuffer << " Time: " << timeBuffer << endl;

        // Run tests and write results to the log file
        int totalTests = 0;
        int passedTests = 0;

        // Test 1: Output "Hello, World" to the console
        totalTests++;
        String str1 = "Hello, World";
        str1.WriteToConsole();
        cout << endl;
        passedTests++;
        WriteTestResults("test_log.txt", "Test 1", true);

        // Test 2: Append
        totalTests++;
        String str2 = "Hello";
        String str3 = "World";
        str2.Append(", ").Append(str3);
        cout << "Appended String: ";
        str2.WriteToConsole();
        cout << endl;
        if (str2.EqualTo("Hello, World")) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 2 Append", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 2 Append", false);
        }

        // Test 3: Prepend
        totalTests++;
        str3.Prepend("Hello, ");
        cout << "Prepended String: ";
        str3.WriteToConsole();
        cout << endl;
        if (str3.EqualTo("Hello, World")) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 3 Prepend", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 3 Prepend", false);
        }

        // Test 4: EqualTo
        totalTests++;
        cout << "Is str2 equal to str3? " << boolalpha << str2.EqualTo(str3) << endl;
        if (str2.EqualTo(str3)) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 4 EqualTo", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 4 EqualTo", false);
        }

        // Test 5: Length
        totalTests++;
        cout << "Length of str2: " << str2.Length() << endl;
        if (str2.Length() == 12) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 5 Length", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 5 Length", false);
        }

        // Test 6: CharacterAt
        totalTests++;
        cout << "Characters at index 0 and 1 in str2: " << str2.CharacterAt(0) << str2.CharacterAt(1) << endl;
        if (str2.CharacterAt(0) == 'H' && str2.CharacterAt(1) == 'e') {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 6 CharacterAt", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 6 CharacterAt", false);
        }

        // Test 7: ToUpper and ToLower
        totalTests++;
        cout << "ToUpper: ";
        str2.ToUpper().WriteToConsole();
        cout << endl;
        if (str2.EqualTo("HELLO, WORLD")) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 7 ToUpper", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 7 ToUpper", false);
        }

        totalTests++;
        cout << "ToLower: ";
        str2.ToLower().WriteToConsole();
        cout << endl;
        if (str2.EqualTo("hello, world")) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 7 ToLower", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 7 ToLower", false);
        }

        // Test 8: Find
        totalTests++;
        str2.ToLower();
        cout << "String: " << str2.CStr() << ", Substring: " << "world" << endl;
        cout << "Expected output: 7" << endl;
        cout << "Actual output: " << str2.Find(String("world")) << endl;
        if (str2.Find(String("world")) == 7) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 8 Find", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 8 Find", false);
        }

        // Test 9: Replace
        totalTests++;
        cout << "Replace 'World' with 'there': ";
        str2.Replace("world", "there").WriteToConsole();
        cout << endl;
        if (str2.EqualTo("hello, there")) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 9 Replace", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 9 Replace", false);
        }

        // Test 10: Append
        totalTests++;
        String str4;
        str4.Append(str2);
        cout << "Appended string to str4: ";
        str4.WriteToConsole();
        cout << endl;
        if (str4.EqualTo("hello, there")) {
            passedTests++;
            WriteTestResults("test_log.txt", "Test 10 Append", true);
        }
        else {
            WriteTestResults("test_log.txt", "Test 10 Append", false);
        }

        // Calculate percentage of successful tests
        double successPercentage = (static_cast<double>(passedTests) / totalTests) * 100;

        // Write the success percentage to the log file
        logFile << fixed << setprecision(2) << "Successful: " << successPercentage << "%" << endl;

        // Close the log file
        logFile.close();
    }
    else {
        cout << "Unable to open log file!" << endl;
    }

    return 0;
}

