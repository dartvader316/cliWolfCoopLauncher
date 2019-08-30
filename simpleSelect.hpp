#pragma once

#define LANGUAGE_ENG 0
#define LANGUAGE_RUS 1

	std::vector <std::array<std::string,2>> answers;

	int language = 0;
	void clearConsole() {
		system("CLS");
	}
	void drawQuestion(std::string question, int selected) {
		std::cout << question << std::endl;
		for (size_t s = 0; s < answers.size(); s++) {
			if (s == selected - 1) std::cout << ">" << answers[s][language] << std::endl;

			else std::cout << " " << answers[s][language] << std::endl;
			
		}

	}

	void makeAnswer(std::string textEng, std::string textRus) {
		std::array <std::string, 2> buff{ textEng,textRus };

		answers.push_back(buff);
	}
	void clearAnswers() {
		answers.clear();
	}

	int question(std::string questionEng,std::string questionRus, int selectDynamicLanguageFlag) {
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
					case 0:	drawQuestion(questionEng, selectedAnswer); break;
					case 1: drawQuestion(questionRus, selectedAnswer); break;
				}

		}
		clearConsole();

		return selectedAnswer;
	}
	int question(std::string questionEng, std::string questionRus) {
		return question(questionEng, questionRus, 0);
	}
	void selectLanguage() {
		makeAnswer("English", "Английский");
		makeAnswer("Russian", "Русский");
		language = question("Select Language", "Выберите язык", 1) - 1;
	}

	std::string localizeString(std::string eng, std::string ru) {
		switch (language) {
		case 0: return eng;
		case 1: return ru;
		}
		return NULL;
	}