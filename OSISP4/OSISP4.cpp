#include <iostream>
#include <vector>
#include <fstream>
#include "TaskHandler.h"

constexpr auto PATH = "C:\\Users\\Veronika\\Documents\\work\\5 сем\\ОСиСП\\OSISP4\\input.txt";

void ReadFile(std::string filePath, std::vector<std::string>& words);

int main()
{
	std::vector<std::string> strings;
	std::vector<std::string> sortedStrings;

	ReadFile(PATH, strings);
	TaskHandler taskHandler;
	taskHandler.Sort(&strings, &sortedStrings, 5);

	for (int i = 0; i < sortedStrings.size(); i++) {
		std::cout << sortedStrings[i] << std::endl;
	}

	//std::cin.get();
	return 0;
}

void ReadFile(std::string filePath, std::vector<std::string>& words) {
	std::ifstream file(filePath);
	std::string word;
	while (file >> word) {
		words.push_back(word);
	}
}

