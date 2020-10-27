#pragma once


#include <ostream>
#include <vector>
#include <array>
#include <string>
#include <iostream>

#include "localization.hpp"

std::vector <int> answers;

	void clearConsole() {
		
		/* FIXME */
		// Bad clear
		system("CLS");
	}
	void drawQuestion(const std::string& question, int selected) {
		std::cout << question << std::endl;
		for (size_t s = 0; s < answers.size(); s++) {
			if (s == selected - 1) std::cout << ">" << localizedString(answers[s]) << std::endl;

			else std::cout << " " << localizedString(answers[s]) << std::endl;
			
		}

	}

	void makeAnswer(int code) {
		answers.push_back(code);
	}
	void clearAnswers() {
		answers.clear();
	}

	
	int questionS(const std::string& questionEng,const std::string& questionRus, int selectDynamicLanguageFlag) {
		unsigned int selectedAnswer = 1;
		
		switch (language) {
			case 0:	drawQuestion(questionEng, selectedAnswer); break;
			case 1: drawQuestion(questionRus, selectedAnswer); break;
		}
		bool stop = false;
		bool update;

		while (stop == false) {
			update = true;
			switch (_getch()) {
				case 72:selectedAnswer--; break;
				case 80:selectedAnswer++; break;
				case '\r': stop = true; break;
			}
			
			if (selectedAnswer > answers.size()) selectedAnswer = answers.size();
			else if (selectedAnswer < 1) selectedAnswer = 1;
			

			if (selectDynamicLanguageFlag == 1) language = selectedAnswer - 1;
			
				clearConsole();
				switch (language) {
					case 0: drawQuestion(questionEng, selectedAnswer); break;
					case 1: drawQuestion(questionRus, selectedAnswer); break;
				}

		}
		clearConsole();

		return selectedAnswer;
	}
	
	int question(int code, int selectDynamicLanguageFlag) {
		/*FIXME*/
		// Direct usage of localization in questionS makes unstable behavior
		return questionS(std::string(locale[code][0]),std::string(locale[code][0]),selectDynamicLanguageFlag);
	}

	int question(int code) {
		return question(code, 0);
	}

	void selectLanguage() {
		makeAnswer(LTEXT_ENGLISH);
		makeAnswer(LTEXT_RUSSIAN);
		language = question(LTEXT_SELECT_LANGUAGE, 1) - 1;
	}
