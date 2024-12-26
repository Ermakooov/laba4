#include "modAlphaCipher.h"
#include "modAlphaCipher.cpp"
#include <iostream>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = towlower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout << L"Ключ=" << key << endl;
        wcout << Text << endl;
        wcout << cipherText << endl;
        wcout << decryptedText << endl;
    } catch(const cipher_error& e) {
        wcerr << L"Ошибка: " << e.what() << endl;
    }
}
int main(int argc, char** argv)
{
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    check(L"НИКИТАЕРМАКОВДВАДЦАТЬТРИПТОДИН",L"Я");
    wcout <<L" "<< endl;
    check(L"ЕРМАКОВ",L"");
    wcout <<L" "<< endl;
    check(L"ПРИВЕТМЕНЯЗОВУТНИКИТА",L"НИКИТА");
    wcout <<L" "<< endl;
    check(L"Привет МЕНЯ зову НИКИТА",L"никита");
    wcout <<L" "<< endl;
    check(L"4567",L"привет");
    return 0;
}
