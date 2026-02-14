echo "# AVS_lab1" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/feride200/AVS_lab1.git
git push -u origin main

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int hexCharToDecimal(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return 10 + (c - 'A');
    } else if (c >= 'a' && c <= 'f') {
        return 10 + (c - 'a');
    }
    return 0; 
}

int hexToDecimal(string hex) {
    int decimal = 0;
    int power = 0;
    
    // Обрабатываем строку справа налево (от младшего разряда к старшему)
    for (int i = hex.length() - 1; i >= 0; i--) {
        int digitValue = hexCharToDecimal(hex[i]);
        if (digitValue == -1) {
            cout << "Ошибка: некорректный символ в шестнадцатеричном числе!" << endl;
            return 0;
        }
        decimal += digitValue * pow(16, power);
        power++;
    }
    
    return decimal;
}

int main() {
    string hexNumber;
    
    cout << "Введите шестнадцатеричное число: ";
    cin >> hexNumber;
    
    int decimalNumber = hexToDecimal(hexNumber);
    
    if (decimalNumber != -1) {
        cout << "Шестнадцатеричное число " << hexNumber 
             << " в десятичной системе: " << decimalNumber << endl;
    }
    
    return 0;
}
