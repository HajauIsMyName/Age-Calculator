#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int birthYear, birthMonth, birthDate;

	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	int currentDate = aTime->tm_mday;
	int currentMonth = aTime->tm_mon + 1;
	int currentYear = aTime->tm_year + 1900;

	cout << "Enter your date of birth: " << endl;

	cout << "Year: ";
	cin >> birthYear;

	cout << "Month: ";
	cin >> birthMonth;

	if (birthMonth >= 13 || birthMonth <= 0) {
		cout << "You can only enter between 1 and 12" << endl;
		exit(0);
	}

	cout << "Day: ";
	cin >> birthDate;

	if (birthDate <= 0 || birthDate >= 32) {
		cout << "You can only enter between 1 and 31" << endl;
		exit(0);
	}

	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (birthDate > currentDate) {
		currentDate += months[birthMonth - 1];
		currentMonth--;
	}

	if (birthMonth > currentMonth) {
		currentYear--;
		currentMonth += 12;
	}
	
	cout << "\nYou are now " << currentYear - birthYear << " years " << currentMonth - birthMonth << " months " << currentDate - birthDate << " day old" << endl;
}