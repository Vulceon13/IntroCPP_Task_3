#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    // Test 1: Output "Hello, World" to the console
    String str1 = "Hello, World";
    str1.WriteToConsole();
    cout << endl;

    // Testing all the functions and operators
    String str2 = "Hello";
    String str3 = "World";
    String str4;

    // Testing Append
    str2.Append(", ").Append(str3);
    str2.WriteToConsole();
    cout << endl;

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

