
#include <locale>
#include <iostream>
#include <string>
#include <vector>
#include <array>

#include <Windows.h>
#include <conio.h>
#include "simpleSelect.hpp"


#define MAIN_CM "start zdoom.exe Wolf3D_Common.pk7 -config \"zdoom - wolf3d.ini\""

void connect() {
	std::string joinip;
	std::string cm = MAIN_CM;
	std::cout << localizeString("Ip to join:", "Ip для подключения:") << std::flush;
	std::cin >> joinip;
	if (!joinip.empty()) {
		cm.append(" -join " + joinip);
	}
	clearConsole();
	std::cout << std::endl << localizeString("Laucnhing wolfenstein 3d:", "Запускаем wolfenstein 3d:") << cm <<std::endl;
	system(cm.c_str());
}
void createServer() {
	std::string host,map,skill;
	std::string cm = MAIN_CM;
	std::cout << localizeString("Amount of players:", "Количество игроков:") << std::flush;
	std::cin >> host;
	if (!host.empty()) {
		cm.append(" -host " + host);
	}
	std::cout << localizeString("Map(code):", "Карта(код):") << std::flush;
	std::cin >> map;
	if (!map.empty()) {
		cm.append(" +map " + map);
	}
	std::cout << localizeString("Difficulty(Number):", "Сложность(число):") << std::flush;
	std::cin >> skill;
	if (!map.empty()) {
		cm.append(" -skill " + skill);
	}
	clearConsole();
	std::cout << std::endl << localizeString("Launching wolfenstein 3d:", "Запускаем wolfenstein 3d:") << cm << std::endl;
	system(cm.c_str());
}
void playOffline() {
	std::string cm = MAIN_CM;
	std::cout << std::endl << localizeString("Launching wolfenstein 3d:", "Запускаем wolfenstein 3d:") << cm << std::endl;
	system(cm.c_str());
}
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleTitle("CLIWolfCoopLauncher v1.1 by dartvader316");
	SetCurrentDirectory(".\\base");
	int selectedMode = 0;
	selectLanguage();
	clearAnswers();
	bool exitProgramm = false;
	makeAnswer("Play offline", "Играть оффлайн");
	makeAnswer("Host COOP server", "Создать Кооперативный сервер");
	makeAnswer("Connect to server", "Подключиться к серверу");
	makeAnswer("Exit", "Выход");

	while (exitProgramm == false) {
		selectedMode = question("Select by arrows what to do", "Выберите стрелками что делать",0);
		switch (selectedMode) {
			case 1:; playOffline(); break;
			case 2: createServer(); break;
			case 3: connect(); break;
			case 4:exitProgramm = true; break;
		}
	}


}