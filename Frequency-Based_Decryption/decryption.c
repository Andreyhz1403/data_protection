#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

char maxWord (string inputMess) {
    unordered_map<char, int> charCount;

    // Підрахунок кількості кожного символу в рядку
    for (char c : inputMess) {
        if (isalpha(c)) {  // Ігноруємо не-буквенні символи
            charCount[c]++;
        }
    }

    // Знаходження символу, який зустрічається найчастіше
    char mostFrequentChar = '\0';
    int maxCount = 0;

    for (const auto& pair : charCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequentChar = pair.first;
        }
    }
    return mostFrequentChar;
}

string shiftWord(string mess, int shiftAmount) {
    string result;
    result = mess;
    for (char& c : result) {
        if (std::isalpha(c)) {
            char base = (std::islower(c)) ? 'a' : 'A';
            char baseZ = (std::islower(c)) ? 'z' : 'Z';
            if(shiftAmount > 0)
                c = (base + (c - base + shiftAmount) % 26);
            else {
                if((c - base + shiftAmount) < 0) {
                    //cout << "dasdsa " << (c - base + shiftAmount) << endl;
                    c = baseZ + (c - base + shiftAmount + 1);
                }
                else 
                    c = base + (c - base + shiftAmount);
            }
            //cout << "base " << c << endl;

        }
    }

    return result;

}

int main()
{
    string message;
    getline(cin, message);
    char wordShift;
    int shift;
    wordShift = maxWord(message);
    shift = 'e' - wordShift;
    string result;
    result = shiftWord(message, shift);
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // Створення мапи для зберігання кількості кожного символу
    

    // Виведення результатів
   
        // cout << "word: " << wordShift << endl;
        // cout << "shift: " << shift << endl;
        //cout << "res: " << wordShift << endl;
       
  

    cout << result << endl;
}

