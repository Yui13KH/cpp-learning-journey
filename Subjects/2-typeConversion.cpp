#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. Convert string with fractions to an integer
    string str = "45.67";  // String with a fraction
    float f = stof(str);   // Convert string to float
    int i = int(f); // Convert float to int (fraction removed)
    
    // Print before and after conversion
    cout << "String with fraction: " << str << endl;
    cout << "Converted to float: " << f << endl;
    cout << "Converted to int (fraction removed): " << i << endl;

    cout << "------------------------" << endl;

    // 2. Convert float to int (fraction part is truncated)
    float num = 123.99f;  // A float with a fraction
    int int_num = int(num); // Convert float to int (fraction removed)
    
    // Print before and after conversion
    cout << "Float value: " << num << endl;
    cout << "Converted to int (fraction removed): " << int_num << endl;

    cout << "------------------------" << endl;

    // 3. Convert numbers to string
    int integer = 99;
    float float_num = 45.67f;

    // Convert integer and float to string
    string int_str = to_string(integer);
    string float_str = to_string(float_num);

    // Print before and after conversion
    cout << "Integer as string: " << int_str << endl;
    cout << "Float as string: " << float_str << endl;

    return 0;
}
