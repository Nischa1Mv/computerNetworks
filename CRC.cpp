#include <iostream>
#include <string>

using namespace std;

// Function to perform XOR operation
string xorOperation(string a, string b) {
    string result = "";
    int n = b.length();
    
    for (int i = 1; i < n; i++) {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

// Function to perform CRC division
string mod2div(string dividend, string divisor) {
    int pick = divisor.length();
    string tmp = dividend.substr(0, pick);
    
    int n = dividend.length();
    
    while (pick < n) {
        if (tmp[0] == '1')
            tmp = xorOperation(divisor, tmp) + dividend[pick];
        else
            tmp = xorOperation(string(pick, '0'), tmp) + dividend[pick];
        
        pick += 1;
    }
    
    if (tmp[0] == '1')
        tmp = xorOperation(divisor, tmp);
    else
        tmp = xorOperation(string(pick, '0'), tmp);
    
    return tmp;
}

// Function to encode data using CRC
void encodeData(string data, string key) {
    int l_key = key.length();
    
    string appended_data = (data + string(l_key - 1, '0'));
    
    string remainder = mod2div(appended_data, key);
    
    string codeword = data + remainder;
    cout << "Remainder: " << remainder << endl;
    cout << "Encoded Data (Data + Remainder): " << codeword << endl;
}

int main() {
    string data;
    string key;
    
    cout << "Enter data: ";
    cin >> data;
    
    cout << "Enter key: ";
    cin >> key;
    
    encodeData(data, key);
    
    return 0;
}