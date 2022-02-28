/*Jessica Ramirez
Professor Pollack
January 21st, 2022
CS-210 */

#include<iostream>

using namespace std;

class hourTime24; // declaration of class hourTime24

enum AMPM {   // declartion of enum for AM or PM for 12 hour clock
	AM, PM
}ampm;

class Time {   // abstract class Time with variables hour, mintue, seconds
public:
	int hour;
	int minute;
	int second;
	void addHour();
	void addMinute();
	void addSecond();
};

class hourTime12 : public Time {  // hourTime12 which inherits the Time class
public:    // methods
	hourTime12(int hr, int min, int sec) {
		hour = hr;
		minute = min;
		second = sec;
		ampm = PM;
	}

	// if-else statement to set hours to 0 or to add one hour
	void addHour() {
		if (hour == 11) {
			hour = 0;
			ampm = ampm == AM ? PM : AM;
		}
		else {
			hour += 1;
		}
	}

	// if-else statement to set mintues to 0 or to add one mintue
	void addMinute() {
		if (minute == 59) {
			minute = 0;
			addHour();
		}
		else {
			minute += 1;
		}
	}

	// if-else statement to set seconds to 0 or to add one second
	void addSecond() {
		if (second == 59) {
			second = 0;
			addMinute();
		}
		else {
			second += 1;
		}
	}

	friend void displayTime(const hourTime12&, const hourTime24&);  // Set friend function
};

class hourTime24 : public Time {  // hourTime124 which inherits the Time class
public:     // methods
	hourTime24(int hr, int min, int sec) {
		hour = hr;
		minute = min;
		second = sec;
	}

	// if-else statement to set hours to 0 or to add one hour
	void addHour() {
		if (hour == 23) {
			hour = 0;
		}
		else {
			hour += 1;
		}
	}

	// if-else statement to set mintues to 0 or to add one mintue
	void addMinute() {
		if (minute == 59) {
			minute = 0;
			addHour();
		}
		else {
			minute += 1;
		}
	}

	// if-else statement to set seconds to 0 or to add one second
	void addSecond() {
		if (second == 59) {
			second = 0;
			addMinute();
		}
		else {
			second += 1;
		}
	}

	friend void displayTime(const hourTime12&, const hourTime24&);   // declaring friend
};

void displayTime(const hourTime12& times12, const hourTime24& times24) {
	//This function is made into friend so it can access private members of the class

	cout << "\n";
	cout << "************************** **************************\n";
	cout << "*    12-Hour Clock      *  *      24-Hour Clock     *\n";
	cout << "*    "; if (times12.hour < 10) cout << "0"; cout << times12.hour << ":";
	if (times12.minute < 10) cout << "0"; cout << times12.minute << ":";
	if (times12.second < 10) cout << "0"; cout << times12.second;
	if (ampm == AM) cout << " AM"; else cout << " PM";
	cout << "\t*  *\t   ";
	if (times24.hour < 10) cout << "0"; cout << times24.hour << ":";
	if (times24.minute < 10) cout << "0"; cout << times24.minute << ":";
	if (times24.second < 10) cout << "0"; cout << times24.second;
	cout << "         *\n";
	cout << "*************************  **************************\n";
	cout << endl;
}

int main() {  // main class
	hourTime12 time_12_Clock(11, 59, 59);
	hourTime24 time_24_Clock(23, 59, 59);
	displayTime(time_12_Clock, time_24_Clock);
	
	while (true) {  // shows menu
		cout << "**************************\n";
		cout << "* 1 - Add One Hour       *\n";
		cout << "* 2 - Add One Minute     *\n";
		cout << "* 3 - Add One Second     *\n";
		cout << "* 4 - Exit Program       *\n";
		cout << "**************************\n";
		cout << endl;

		int choice;

		cin >> choice;

		switch (choice) { // switch statement used to take user input
		case 1:
			time_12_Clock.addHour();
			time_24_Clock.addHour();
			displayTime(time_12_Clock, time_24_Clock);
			break;

		case 2:
			time_12_Clock.addMinute();
			time_24_Clock.addMinute();
			displayTime(time_12_Clock, time_24_Clock);
			break;

		case 3:
			time_12_Clock.addSecond();
			time_24_Clock.addSecond();
			displayTime(time_12_Clock, time_24_Clock);
			break;

		case 4:
			cout << "Exit Program!";
			exit(1);
			break;

		default:
			cout << "Error! Invalid number!\n";
			break;
		}
	}
}