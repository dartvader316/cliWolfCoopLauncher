
#include <clocale>
#include <locale>
#include <iostream>
#include <string>

#if defined  __GNUC__ ||  defined __GNUG__
#include <windows.h>
#else
#include <Windows.h>
#endif

#include <conio.h>

#include "localization.hpp"
#include "simpleSelect.hpp"


#define MAIN_CM "start zdoom.exe Wolf3D_Common.pk7 -config \"zdoom - wolf3d.ini\""

std::string input(const std::string& helpText,bool important){
	std::string ret;
	std::string printText = helpText + ( (!important)? localizedString(LTEXT_SKIP) : "") + ":";
	
	std::cout << printText << std::flush;
	std::getline(std::cin,ret);
	
	if(ret[0]<32){

		if(important){
			while(ret[0]<32){
				std::cout << localizedString(LTEXT_IMPORTANT_PARAMETER) << std::endl;
				std::cout << printText << std::flush;
				std::getline(std::cin,ret);
			}

		}else{
			return std::string();
		}
	}

	return ret;
}

void connect() {
	std::string joinip;
	std::string cm = MAIN_CM;

	cm.append(" -join " + input(localizedString(LTEXT_IP_TO_JOIN),true));

	clearConsole();
	
	std::cout << std::endl << localizedString(LTEXT_LAUNCH_WOLF) << cm << std::endl;
	system(cm.c_str());
}
void createServer() {
	std::string host,map,skill;
	std::string cm = MAIN_CM;
	
	cm.append(" -host " + input(localizedString(LTEXT_AMOUNT_OF_PLAYERS),true));
	
	cm.append(" +map " + input(localizedString(LTEXT_MAP_CODE),true));

	cm.append(" -skill " + input(localizedString(LTEXT_DIFFICULTY_NUMBER),true));
	
	cm.append(" " + input(localizedString(LTEXT_CUSTOM_PARAMETERS),false));

	clearConsole();
	std::cout << std::endl << localizedString(LTEXT_LAUNCH_WOLF) << cm << std::endl;
	system(cm.c_str());
}
void playOffline() {
	std::string cm = MAIN_CM;
	cm.append(" " + input(localizedString(LTEXT_CUSTOM_PARAMETERS),false));
	
	std::cout << std::endl << localizedString(LTEXT_LAUNCH_WOLF) << cm << std::endl;
	system(cm.c_str());
}


int main() {

	setlocale(LC_ALL,"Russian");

	SetConsoleTitle("TUIWolfCoopLauncher v1.2 by dartvader316");
	SetCurrentDirectory(".\\base");

	int selectedMode = 0;
	selectLanguage();
	clearAnswers();
	bool quit = false;
	makeAnswer(LTEXT_PLAY_OFFLINE);
	makeAnswer(LTEXT_HOST_COOP_SERVER);
	makeAnswer(LTEXT_CONNECT_TO_SERVER);
	makeAnswer(LTEXT_EXIT);

	while (!quit) {
		selectedMode = question(LTEXT_SELECT_WHAT_TO_TO,0);
		switch (selectedMode) {
			case 1: playOffline(); break;
			case 2: createServer(); break;
			case 3: connect(); break;
			case 4: quit = true; break;
		}
	}


}
