#include<bits/stdc++.h>
using namespace std;

string railFenceEncryption(string text , int row , int k , bool is_down){

    char box[row][text.length()];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < text.length(); j++){
            box[i][j] = '\0';
        }
    }

    string encryptedText = "";

    // core logic
    for(int i = 0; i < text.length(); i++){
        if(is_down){
            k++;
            box[k][i] = text[i];
            (k == (row - 1) ? is_down = false : is_down = true);
        } else {
            k--;
            box[k][i] = text[i];
            ((k == 0 ) ? is_down = true : is_down = false);
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < text.length(); j++){
            if(box[i][j] != '\0')
                encryptedText += box[i][j];
        }
    }

    return encryptedText;
}

string railFenceDecryption(int row , int k , bool is_down , string the_encryptedText){

    char box2[row][the_encryptedText.length()];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < the_encryptedText.length(); j++){
            box2[i][j] = '\0';
        }
    }

    for(int i = 0; i < the_encryptedText.length(); i++){
        if(is_down){
            k++;
            box2[k][i] = '*';
            (k == (row - 1) ? is_down = false : is_down = true);
        } else {
            k--;
            box2[k][i] = '*';
            ((k == 0 ) ? is_down = true : is_down = false);
        }
    }

    int l = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < the_encryptedText.length(); j++){
            if(box2[i][j] == '*'){
                box2[i][j] = the_encryptedText[l];
                l++;
            } else {
                box2[i][j] = '\0';
            }
        }
    }

    k = -1; is_down = true;
    string decryptedText = "";

    for(int i = 0; i < the_encryptedText.length(); i++){
        if(is_down){
            k++;
            decryptedText += box2[k][i];
            (k == (row - 1) ? is_down = false : is_down = true);
        } else {
            k--;
            decryptedText += box2[k][i];
            ((k == 0 ) ? is_down = true : is_down = false);
        }
    }

    return decryptedText;
}

void railFenceMenu(){

    int choice;

    cout << "===== Rail Fence Cipher =====\n";
    cout << "1. Encryption\n";
    cout << "2. Decryption\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch(choice){
    case 1:{
        string text;
        int row;

        cout << "Enter Plain Text: ";
        getline(cin , text);

        cout << "Enter Key: ";
        cin >> row;

        text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
        transform(text.begin(), text.end(), text.begin(), ::tolower);

        int k = -1; bool is_down = true;

        string encrypted = railFenceEncryption(text, row, k, is_down);

        cout << "Encrypted Text: " << encrypted << endl;
        break;
    }

    case 2:{
        string encryptedText;
        int row;

        cout << "Enter Encrypted Text: ";
        getline(cin , encryptedText);
        
        cout << "Enter Key: ";
        cin >> row;
        
        encryptedText.erase(remove_if(encryptedText.begin(), encryptedText.end(), ::isspace), encryptedText.end());
        transform(encryptedText.begin(), encryptedText.end(), encryptedText.begin(), ::tolower);

        int k = -1; bool is_down = true;
        string decrypted = railFenceDecryption(row, k, is_down, encryptedText);

        cout << "Decrypted Text: " << decrypted << endl;
        break;
    }

    default:
        cout << "Invalid Choice!" << endl;
}
}