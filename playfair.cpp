#include <bits/stdc++.h>
using namespace std;

void toLowerCase(string &text)
{
    transform(text.begin(), text.end(), text.begin(), ::tolower);
}

void removeSpaces(string &text)
{
    text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
}

void generateKeyTable(string &key, vector<vector<char>> &keyTable)
{
    keyTable.resize(5, vector<char>(5));

    vector<int> hash(26, 0);

    for (int i = 0; i < key.length(); i++)
    {
        if (key[i] != 'j')
            hash[key[i] - 'a'] = 2;
    }

    hash['j' - 'a'] = 1;

    int row = 0;
    int col = 0;

    for (int i = 0; i < key.length(); i++)
    {
        if (hash[key[i] - 'a'] == 2)
        {
            hash[key[i] - 'a']--;

            keyTable[row][col] = key[i];
            col++;

            if (col == 5)
            {
                row++;
                col = 0;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (hash[i] == 0)
        {
            keyTable[row][col] = char(i + 'a');

            col++;

            if (col == 5)
            {
                row++;
                col = 0;
            }
        }
    }
}

void searchPosition(vector<vector<char>> &keyTable, char a, char b, vector<int> &position)
{
    if (a == 'j')
        a = 'i';

    if (b == 'j')
        b = 'i';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyTable[i][j] == a)
            {
                position[0] = i;
                position[1] = j;
            }

            else if (keyTable[i][j] == b)
            {
                position[2] = i;
                position[3] = j;
            }
        }
    }
}

void prepareText(string &text)
{
    if (text.length() % 2 != 0)
        text += 'z';
}

string playfairEncryption(string text, string key)
{
    removeSpaces(text);
    removeSpaces(key);

    toLowerCase(text);
    toLowerCase(key);

    prepareText(text);

    vector<vector<char>> keyTable;
    generateKeyTable(key, keyTable);

    vector<int> position(4);

    for (int i = 0; i < text.length(); i += 2)
    {
        searchPosition(keyTable, text[i], text[i + 1], position);

        if (position[0] == position[2])
        {
            text[i] = keyTable[position[0]][(position[1] + 1) % 5];
            text[i + 1] = keyTable[position[2]][(position[3] + 1) % 5];
        }

        else if (position[1] == position[3])
        {
            text[i] = keyTable[(position[0] + 1) % 5][position[1]];
            text[i + 1] = keyTable[(position[2] + 1) % 5][position[3]];
        }

        else
        {
            text[i] = keyTable[position[0]][position[3]];
            text[i + 1] = keyTable[position[2]][position[1]];
        }
    }

    return text;
}

string playfairDecryption(string cipherText, string key)
{
    removeSpaces(cipherText);
    removeSpaces(key);

    toLowerCase(cipherText);
    toLowerCase(key);

    vector<vector<char>> keyTable;
    generateKeyTable(key, keyTable);

    vector<int> position(4);

    for (int i = 0; i < cipherText.length(); i += 2)
    {
        searchPosition(keyTable, cipherText[i], cipherText[i + 1], position);

        if (position[0] == position[2])
        {
            cipherText[i] = keyTable[position[0]][(position[1] - 1 + 5) % 5];
            cipherText[i + 1] = keyTable[position[2]][(position[3] - 1 + 5) % 5];
        }

        else if (position[1] == position[3])
        {
            cipherText[i] = keyTable[(position[0] - 1 + 5) % 5][position[1]];
            cipherText[i + 1] = keyTable[(position[2] - 1 + 5) % 5][position[3]];
        }

        else
        {
            cipherText[i] = keyTable[position[0]][position[3]];
            cipherText[i + 1] = keyTable[position[2]][position[1]];
        }
    }

    return cipherText;
}

void playfairMenu()
{
    int choice;

    cout << "===== Playfair Cipher =====\n";
    cout << "1. Encryption\n";
    cout << "2. Decryption\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
    {
        string text, key;

        cout << "Enter Plain Text: ";
        getline(cin, text);

        cout << "Enter Key: ";
        cin >> key;

        string cipherText = playfairEncryption(text, key);

        cout << "Encrypted Text: " << cipherText << "\n";

        break;
    }

    case 2:
    {
        string cipherText, key;

        cout << "Enter Cipher Text: ";
        getline(cin, cipherText);

        cout << "Enter Key: ";
        cin >> key;

        string originalText = playfairDecryption(cipherText, key);

        cout << "Decrypted Text: " << originalText << "\n";

        break;
    }

    default:
    {
        cout << "Invalid Choice!\n";
        break;
    }
    }
}