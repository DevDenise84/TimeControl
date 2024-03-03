//Chada Tech Clocks
//Name:    Denise English
//Date:    1/28/2024
//Project: 12 and 24 hour format clock




#include <iostream>
#include <iomanip>
#include <string>

// Global variables to store the simulated time
int hour12 = 12;
int hour24 = 0;
int minute = 0;
int second = 0;

// Function to get the current hour in 12-hour format
int getHour12() {
    return (hour12 == 0) ? 12 : hour12;
}

// Function to set the hour in 12-hour format
void setHour12(int h) {
    hour12 = (h % 12 == 0) ? 12 : h % 12;
}

// Function to get the current hour in 24-hour format
int getHour() {
    return hour24;
}

// Function to set the hour in 24-hour format
void setHour(int h) {
    hour24 = h % 24;
}

// Function to get the current minute
int getMinute() {
    return minute;
}

// Function to set the minute
void setMinute(int m) {
    minute = m % 60;
}

// Function to get the current second
int getSecond() {
    return second;
}

// Function to set the second
void setSecond(int s) {
    second = s % 60;
}

// Function to add one hour to both clocks
void addOneHour() {
    hour12 = (hour12 % 12) + 1;
    hour24 = (hour24 + 1) % 24;
}

// Function to add one minute to both clocks
void addOneMinute() {
    minute = (minute + 1) % 60;
}

// Function to add one second to both clocks
void addOneSecond() {
    second = (second + 1) % 60;
}

// Function to format time in 12-hour format (hh:mm:ss)
std::string formatTime12(int h, int m, int s) {
    std::string amPm = (h >= 12) ? "P M" : "A M";
    h = (h % 12 == 0) ? 12 : h % 12;
    return std::to_string(h) + ":" + std::to_string(m) + ":" + std::to_string(s) + " " + amPm;
}

// Function to format time in 24-hour format (hh:mm:ss)
std::string formatTime24(int h, int m, int s) {
    return std::to_string(h) + ":" + std::to_string(m) + ":" + std::to_string(s);
}

// Function to print both clocks
void displayClocks() {
    std::cout << " ********************    ********************" << std::endl;
    std::cout << "*   12-Hour Clock    *  *   24-Hour Clock    *" << std::endl;
    std::cout << "*   " << std::setw(11) << formatTime12(getHour12(), getMinute(), getSecond()) << "      *  * "
              << std::setw(15) << formatTime24(getHour(), getMinute(), getSecond()) << "    *" << std::endl;
    std::cout << " ********************    ********************" << std::endl;
}

// Function to print the menu
void printMenu() {
    std::cout << " ********************" << std::endl;
    std::cout << "* 1 - Add One Hour   *" << std::endl;
    std::cout << "* 2 - Add One Minute *" << std::endl;
    std::cout << "* 3 - Add One Second *" << std::endl;
    std::cout << "* 4 - Exit Program   *" << std::endl;
    std::cout << " ********************" << std::endl;
}

// Function to get user choice from the menu
int getMenuChoice() {
    int choice;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;
    return choice;
}

int main() {
    int choice;

    do {
        displayClocks();
        printMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                addOneHour();
                break;
            case 2:
                addOneMinute();
                break;
            case 3:
                addOneSecond();
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
    } while (choice != 4);

    return 0;
}