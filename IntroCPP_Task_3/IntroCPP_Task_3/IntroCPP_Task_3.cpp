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
    // Current  date  and time
    time_t currentTime = time(nullptr);
    struct tm* localTime = localtime(&currentTime);

    // Open the log file 
    ofstream logFile;
    logFile.open("test_log.txt", ios::app); //Opens the file in append mode
    if (logFile.is_open()) 
    {
       // Writes the date and time to the log file
        logFile << "Date: " << put_time(localTime, "%x") << " Time: " << put_time(localTime, "%X") << endl;
    }

    // Run tests and write the results to the log file
    int totalTests = 0;
    int passedTests = 0;

    // Test 1: Output "Hello, World" to the console
    totalTests++;
    String str1 = "Hello, World";
    str1.WriteToConsole();
    cout << endl;
    passedTests++;
    WriteTestResults("test_log.txt", "Test 1", true);
    
    /*String str1 = "Hello, World";
    str1.WriteToConsole();
    cout << endl;*/

    //// Testing all the functions and operators
    //String str2 = "Hello";
    //String str3 = "World";
    //String str4;

    // Testing Append
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
    
    /*str2.Append(", ").Append(str3);
    str2.WriteToConsole();
    cout << endl;*/

    // Testing Prepend
    str3.Prepend("Hello, ");
    str3.WriteToConsole();
    cout << endl;

    // Testing EqualTo
    cout << boolalpha << str2.EqualTo(str3) << endl;

    // Testing Length
    cout << str2.Length() << endl;

    // Testing CharacterAt
    cout << str2.CharacterAt(0) << str2.CharacterAt(1) << endl;

    // Testing ToUpper and ToLower
    str2.ToUpper().WriteToConsole();
    cout << endl;
    str2.ToLower().WriteToConsole();
    cout << endl;

    // Testing Find
    str2.ToLower();
    cout << "String: " << str2.CStr() << ", Substring: " << "World" << endl;
    cout << "Expected output: 7" << endl;
    cout << "Actual output: " << str2.Find(String("world")) << endl;

    // Testing Replace
    str2.Replace("World", "there").WriteToConsole();
    cout << endl;

    // Testing use Append
    str4.Append(str2);
    str4.WriteToConsole();
    cout << endl;

    return 0;
}

