#include <iostream>
#include <string>

using namespace std;

int main() {
	char choice = '1';
	int a = 25;
	int b = 25;
	string message;

	while (!isalpha(choice)) {
		cout << "Would you like to encrypt or decrypt? (e/d/q to quit): ";
		cin >> choice;
		if (!isalpha(choice) || (choice != 'd' && choice != 'e')) {
			cout << "Please enter a valid choice" << endl;
			continue;
		}
		else if (choice == 'q'){
			return 0;
		}
		switch (choice) {
		case 'e':
			cin.ignore();
			cout << "Enter a message to encrypt: ";
			getline(cin, message);
			for (int i = 0; i < message.length(); ++i) {
				if (isspace(message[i])) continue;
				message[i] = tolower(message[i]);
				message[i] = ((a * (message[i] - 'a') + b) % 26) + 'a';
			}
			cout << "Encrypted message is: " << message << endl;
			break;
		}
		
	}
	return 0;
}