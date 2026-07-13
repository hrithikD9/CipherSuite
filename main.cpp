#include <bits/stdc++.h>
using namespace std;

void railFenceMenu();
void vigenereMenu();
void playfairMenu();

int main()
{
    int choice;

    while(true)
    {
        cout << "\n===== Choose the method =====\n";
        cout << "1. Rail Fence Cipher\n";
        cout << "2. Vigenere Cipher\n";
        cout << "3. Playfair Cipher\n";
        cout << "0. Exit\n";

        cout << "Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                railFenceMenu();
                break;

            case 2:
                vigenereMenu();
                break;

            case 3:
                playfairMenu();
                break;

            case 0:
                return 0;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}