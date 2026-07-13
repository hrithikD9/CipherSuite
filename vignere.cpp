#include<bits/stdc++.h>
using namespace std;

string vigenereEncryption(string text , string key){
    // E(i) = t(i) + k(i) % 26
    string e = "";
    for(int i = 0; i < text.length(); i++){
    int t = text[i] - 'a';
    int k = key[i] - 'a';

    char x = (t + k) % 26;
    x += 'a';       

    e.push_back(x);
    }
    return e;
}

string vigenereDecryption(string cipherText , string key){
     // t(i) = E(i) - k(i) % 26
    string d = "";
    for(int i = 0; i < cipherText.length(); i++){
    int ct = cipherText[i] - 'a';
    int k = key[i] - 'a';

    char x = (ct - k + 26) % 26;
    x += 'a';       

    d.push_back(x);
    }
    return d;
}

string generateKey(string key , int len){
    string gKey = "";

    for (int i = 0; i < len; i++)
    {
        gKey += key[i % key.length()];
    }
    key += gKey;
    return key;
}

void vigenereMenu(){
    int choice;

    cout << "===== Vigenère Cipher Cipher =====\n";
    cout << "1. Encryption\n";
    cout << "2. Decryption\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case 1:{
            string text , key;

            cout << "Enter your Plain Text : ";
            getline(cin , text);

            cout << "Enter the key : ";
            cin >> key;

            text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
            transform(text.begin(), text.end(), text.begin(), ::tolower);

            key = generateKey(key , (text.length() - key.length()));

            string cipherText = vigenereEncryption(text , key);
            cout << "Your encrypted text : " << cipherText << "\n";

            break;
        }

        case 2:{
            string cipherText , key;

            cout << "Enter your Cipher Text : ";
            getline(cin , cipherText); 
            
            cout << "Enter the key : ";
            cin >> key;
            
            cipherText.erase(remove_if(cipherText.begin(), cipherText.end(), ::isspace), cipherText.end());
            transform(cipherText.begin(), cipherText.end(), cipherText.begin(), ::tolower);

            key = generateKey(key , (cipherText.length() - key.length()));

            string originalText = vigenereDecryption(cipherText , key);

            cout << "Your decrypted text : " << originalText << "\n";

            break;
        }

        default:{
            cout << "Invalid Choice!" << "\n";

            break;
        }
    }
}