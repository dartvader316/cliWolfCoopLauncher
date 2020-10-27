#ifndef LOCALIZATION_HPP
#define LOCALIZATION_HPP

#include <string>

#define SUPPORTED_LANGUAGES 2
#define LANGUAGE_ENG 0
#define LANGUAGE_RUS 1

int language = 0;

enum{
	LTEXT_ENGLISH,
	LTEXT_RUSSIAN,
	LTEXT_SELECT_LANGUAGE,
	LTEXT_SELECT_WHAT_TO_TO,

	// Common
	LTEXT_LAUNCH_WOLF,
	LTEXT_SKIP,
	LTEXT_IMPORTANT_PARAMETER,
	LTEXT_CUSTOM_PARAMETERS,
	// Main menu
	LTEXT_PLAY_OFFLINE,
	LTEXT_HOST_COOP_SERVER,
	LTEXT_CONNECT_TO_SERVER,
	LTEXT_EXIT,
	// Join server
	LTEXT_IP_TO_JOIN,

	// Host server
	LTEXT_AMOUNT_OF_PLAYERS,
	LTEXT_MAP_CODE,
	LTEXT_DIFFICULTY_NUMBER,

};


// FUCK windows for bad working with utf-8

const char* locale[][SUPPORTED_LANGUAGES] = {
	{"English", "Английский"},
	{"Russian", "Русский"},     	
	{"Select Language", "Выберите язык"},
	{"Select by arrows what to do", "Выберите стрелками что делать"},

	{"Launching wolfenstein 3d", "Запускаем wolfenstein 3d"},
	{"(press enter to skip)","(enter для пропуска)"},
	{"This parameter is important", "Этот параметр важен."},
	{"Custom additional parameters","Дополнительные параметры"},
	
	{"Play offline","Играть оффлайн"},
	{"Host COOP server","Создать кооп сервер"},
	{"Connect to server","Подключится к серверу"},
	{"Exit", "Выйти"},
	
	{"Ip to join", "Ip для подключения"},
	
	{"Amount of players", "Количество игроков"},
	{"Map(code)", "Карта(код)"},
	{"Difficulty(Number)", "Сложность(число)"},
};

std::string localizedString(int code) {
	return std::string(locale[code][language]);
}

#endif
