#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string operation;
    getline(cin, operation);
    int pseudo_random_number;
    cin >> pseudo_random_number; cin.ignore();
    string rotor[3];
    for (int i = 0; i < 3; i++) {
        getline(cin, rotor[i]);
    }
    string message;
    getline(cin, message);

    if (operation == "ENCODE") {
        for (int i = 0; i < message.length(); i++) {     //виконуємо здвиг на задане число та шифруємо першим ротором
            int adress = message[i];
            adress = adress - 65 + pseudo_random_number + i;
            while (adress > 25) adress -= 26;
            message[i] = rotor[0][adress];
        }
        for (int j = 1; j < 3; j++) {        //шифрування 2 та 3 ротором
            for (int i = 0; i < message.length(); i++) {
                int adress = message[i];
                adress = adress - 65;
                message[i] = rotor[j][adress];
            }
        }
        cout << message << endl;
    }

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (operation == "DECODE") {
        for (int k = 2; k >= 0; k--) {    // проводимо декодування 3 роторами
            for (int i = 0; i < message.length(); i++) {
                for (int j = 0; j < rotor[k].length(); j++) {
                    if (message[i] == rotor[k][j]) {
                        message[i] = alphabet[j];

                        break;
                    }
                }
            }
        }

        for (int i = 0; i < message.length(); i++) {     //робимо здвиг вліво на задане число
            int adress = message[i] - 65 - i - pseudo_random_number;
            while (adress < 0) {
                adress += 26;
            }
            message[i] = alphabet[adress];
        }
        cout << message << endl;
    }
}
