#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int numberascii(string mess, int i) {
    int num = -1;  
    if (mess[i] >= 48 && mess[i] <= 57) num = mess[i] - '0';
    if(mess[i] >= 97 && mess[i] <= 102) num = 10 + mess[i] - 'a'; 
    return num;
}

int numchar(int a, int b) {
    int res = (a << 4) + b;
    return res;
}

int main()
{
    string message_1;
    getline(cin, message_1);
    string message_2;
    getline(cin, message_2);
    string message_3;
    getline(cin, message_3);
    int a1, a2, a3;
    int resXor;
    int res;
    string result;
    char resultChar;
    for(int i = 0; i < message_1.size(); i++) {
        a1 = numberascii(message_1, i);
        a2 = numberascii(message_2, i);
        a3 = numberascii(message_3, i);
        resXor = a1 ^ a2 ^ a3;        
        if(i%2) {
            resultChar = numchar(res, resXor);
            result += resultChar;
        }
        res = resXor;        
    }
    
    cout << result << endl;
}

