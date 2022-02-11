#include <iostream>
#include <string>

using namespace std;

int encrypt(string plainText, string sneakyText, string key) {


	int k = 0;


	string computerPrank;
	getline(cin, computerPrank);
	
	cout << "Plaintext: ";
	getline(cin, plainText);

	cout << "Key: ";
	cin >> key;

	for (int i = 0; i < plainText.length(); i++) {
		if (plainText[i] == 32) {
			sneakyText[i] = '\x84';
		}
		else {
			sneakyText[i] = (((plainText[i] - 97) + (key[k] - 97)) % 26)+97;
			k++;
			if (k == key.length()) {
				k = 0;
			}
		}
	}

	cout << "ciphertext: ";


	for (int i = 0; i < plainText.length(); i++) {
		cout << sneakyText[i];
	}

	cout << endl;

	return 0;
}


int decrypt(string plainText, string sneakyText, string key) {

	int k = 0;

	string computerPrank;
	getline(cin, computerPrank);

	cout << "Ciphertext: ";
	getline(cin, plainText);

	cout << "Key: ";
	cin >> key;

	for (int i = 0; i < plainText.length(); i++) {
		if (plainText[i] == '\x84') {
			sneakyText[i] = 32;
		}
		else {
			sneakyText[i] = (((plainText[i] - 122) - (key[k] - 97)) % 26) + 122;
			k++;
			if (k == key.length()) {
				k = 0;
			}
		}
	}


	cout << "Plaintext: ";


	for (int i = 0; i < plainText.length(); i++) {
		cout << sneakyText[i];
	}

	cout << endl;


	return 0;
}

int main() {
	
	string plainText;
	string sneakyText = "H";
	string key;

	cout << "Giai ma(P)" << endl;

	int input;
    cout<<"Moi ban nhap lua chon: ";
	cin >> input;

	switch (input) {
	case 1: 
		encrypt(plainText, sneakyText, key);
		break;
	case 2:
		decrypt(plainText, sneakyText, key);
		break;
	default:
		cout << "Lua chon" << endl;
		break;
	}

	system("pause");
	return 0;
}






