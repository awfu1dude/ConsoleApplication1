#include <iostream>
#include <vector>

void security_in_club() {
	int age;
	std::cin >> age;

	if (age < 18) {
		std::cout << "entrance denied";
	}
	else {
		std::cout << "you're welcome";
	}
}

void guess_number() {
	srand(0);
	int a, b;
	a = rand() % 10;
	std::cout << "Guess number from 0 to 10 (correct: " << a << "):\n";
	std::cin >> b;
	if (a == b) {
		std::cout << "you win";
	}
	else {
		std::cout << "you lose";
	}
}

struct location {
	std::string name;
	std::string description;
	std::vector<int> doors;
};

void move_through_locations() {
	location locations[10];
	for (int i = 0; i < 10; i++) {
		locations[i].name = "Location " + i;
		locations[i].description = "Description " + i;
		locations[i].doors.push_back(i);
		locations[i].doors.push_back(i / 2);
	}

	int locationIndex = 0;
	std::string userInput;
	std::cout << "Enter location name: ";
	std::cin >> userInput;
	for (int i = 0; i < 10; i++) {
		if (locations[i].name == userInput) {
			locationIndex = i;
			break;
		}
	}
	if (locationIndex == -1) {
		std::cout << "Error";
	}
	else {
		for (int i = 0; i < locations[locationIndex].doors.size(); i++) {

		}
		std::cout << "You on location:\n";
		std::cout << locations[locationIndex].name;
		std::cout << locations[locationIndex].description << std::endl;
	}
}

int main()
{
	move_through_locations();
}