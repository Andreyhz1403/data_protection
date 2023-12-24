#include <iostream>
#include <string>
#include <openssl/md5.h>

using namespace std;

string calculateMD5(const string& input) {
    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, input.c_str(), input.length());

    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5_Final(digest, &context);

    char md5String[33];
    for (int i = 0; i < 16; ++i)
        sprintf(&md5String[i * 2], "%02x", (unsigned int)digest[i]);

    return string(md5String);
}

string crack(const string& hash) {
  // C0D3 g03s h3r3
  for (int pin = 0; pin <= 99999; ++pin) {
        // Format the PIN code with leading zeros
        string pinCode = to_string(pin);
        while (pinCode.length() < 5)
            pinCode = "0" + pinCode;

        string hashedPin = calculateMD5(pinCode);

        if (hashedPin == hash) {
            cout << "Cracked PIN code: " << pinCode << endl;
            break;
        }
    }
  
  return 0;
}
