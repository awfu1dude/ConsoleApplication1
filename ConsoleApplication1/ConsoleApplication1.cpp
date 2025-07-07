#include <iostream>
#include <vector>

struct location {
	std::string name;
	std::string description;
	std::vector<int> doors;
	std::vector<std::string> items;
};

void print_locations_list(location locations[], int count) {
	for (int i = 0; i < count; i++) {
		std::cout << (i + 1) << ". " << locations[i].name << ": " << locations[i].description << std::endl;
	}
}


void text_adventure() {
	const int locationsCount = 4;
	location locations[locationsCount] = { 
		{
			"Hallway", 
			"Hallway description", 
			{1, 2, 3,},
			{"Key", "Paper",},
		},
		{
			"Bathroom", 
			"Bathroom description", 
			{0, 2,},
			{"Soap"},
		},
		{
			"Bedroom", 
			"Bedroom description", 
			{0, 1,},
			{},
		},
		{
			"Livingroom", 
			"Livingroom description", 
			{0}, 
			{"Smartphone", "Laptop",},
		},
	};

	std::cout << "# Text Adventure #\n\nAvailabe locations for move:\n";
	print_locations_list(locations, locationsCount);

	int locationIndex = 0;
	std::vector<std::string> backpack = {"Pizza"};
	std::string userInput, item;

	std::cout << "\nYou on location: " << locations[locationIndex].name << std::endl;
	while (true) {
		std::cout << "\nEnter location name or command: ";
		std::cin >> userInput;
		if (std::cin.peek() != '\n' && std::cin >> item) {
			// Pick item from location
			if (userInput == "Pick") {
				if (item.empty()) {
					std::cout << "\nYou must print item name.\n";
				}
				else if (locations[locationIndex].items.empty()) {
					std::cout << "\nNo more items on location.\n";
				}
				else {
					for (int i = 0; i < locations[locationIndex].items.size(); i++) {
						if (i == locations[locationIndex].items.size()) {
							std::cout << "\nItem not finded.\n";
							break;
						}
						else if (locations[locationIndex].items[i] == item) {
							backpack.push_back(item);
							auto iter = locations[locationIndex].items.cbegin();
							locations[locationIndex].items.erase(iter + i);
							break;
						}
					}
				}
			}
			// Drop item from backpack
			else if (userInput == "Drop") {
				if (item.empty()) {
					std::cout << "\nYou must print item name.\n";
				}
				else if (backpack.empty()) {
					std::cout << "\nYou don't have items in your backpack.\n";
				}
				else {
					for (int i = 0; i < backpack.size() + 1; i++) {
						if (i == backpack.size()) {
							std::cout << "\nItem not finded.\n";
							break;
						}
						else if (backpack[i] == item) {
							locations[locationIndex].items.push_back(item);
							auto iter = backpack.cbegin();
							backpack.erase(iter + i);
							break;
						}
					}
				}
			}
		}
		else {
			// List items on location
			if (userInput == "List") {
				std::cout << "\nItems on location " << locations[locationIndex].name << ":\n";
				if (locations[locationIndex].items.empty()) {
					std::cout << "Items not finded.\n";
				}
				else {
					for (int i = 0; i < locations[locationIndex].items.size(); i++) {
						std::cout << (i + 1) << ". " << locations[locationIndex].items[i] << std::endl;
					}
				}
			}
			// List items in your backpack
			else if (userInput == "Trunk") {
				std::cout << "\nItems in your backpack:\n";
				if (backpack.empty()) {
					std::cout << "Your backpack is empty.\n";
				}
				else {
					for (int i = 0; i < backpack.size(); i++) {
						std::cout << (i + 1) << ". " << backpack[i] << std::endl;
					}
				}
			}
			// Go to location
			else {
				for (int i = 0; i < locations[locationIndex].doors.size() + 1; i++) {
					if (i == locations[locationIndex].doors.size()) {
						std::cout << "Location not finded.\n\n";
						break;
					}
					int doorIndex = locations[locationIndex].doors[i];
					if (locations[doorIndex].name == userInput) {
						locationIndex = doorIndex;
						break;
					}
				}
				std::cout << "You on location: " << locations[locationIndex].name << std::endl;
			}
		}
	}
}

int main()
{
	text_adventure();
	return 0;
}