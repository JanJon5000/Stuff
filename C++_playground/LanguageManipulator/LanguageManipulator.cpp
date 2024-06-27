#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

//////////////////
//global variables and macros
typedef string* funPointer(string words);
#define PREFIX '-'
#define READINNES_SIGN ">>"
#define RESULT_SIGN "==  "
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
enum IDS{
	GEN_ID, //0
	ASPI_ID, //1
	SANE_ID, //2
	LOW_ID, //3
	UP_ID, //4
	PTOB_ID, //5
	UTO00_ID, //6
	TTOD_ID, //7
 	SITOZY_ID, //8
	GENSEQ_ID, //9
	HELP_ID, //10
	CLEAR_ID, //11
 	ERROR_ID //12
};
string NAMES[] = {
	"gen",
	"aspi",
	"sane",
	"low",
	"up",
	"ptob",
	"uto00",
	"ttod",
	"sitozy",
	"genseq",
	"help",
	"clear"
};
//////////////////

//functions that change the text
string gen(string words) {
	string answer = "";
	int num = 0;
	for (int i = 0; i < words.size(); i++) {
		while ( words[i] < 59 && words[i] > 47 ) {
			num *= 10;
			num += words[i] - 48;
			i++;
		}
		if (num != 0) {
			answer.resize(answer.size() + num, words[i]);
			num = 0;
		}
		else {
			answer += words[i];
		}
	}
	return answer;
}
string aspi(string words) {
	for (int i = 0; i < words.size(); i++)
		words[i] = (i + 1) % 2 == 0 ? toupper(words[i]) : words[i];
	return words;
}
string sane(string words) {
	return aspi(" " + words).erase(0, 1);
}
string low(string words) {
	for (int i = 0; i < words.size(); i++)
		words[i] = tolower(words[i]);
	return words;
}
string up(string words) {
	for (int i = 0; i < words.size(); i++)
		words[i] = toupper(words[i]);
	return words;
}
string ptob(string words) {
	for (int i = 0; i < words.size(); i++) {
		words[i] = words[i] == 'p' ? 'b' : words[i];
		words[i] = words[i] == 'P' ? 'B' : words[i];
	}
	return words;
}
string uto00(string words) {
	size_t pos; char tab[] = { 'u', 'U' };
	for (int i = 0; i < (sizeof(tab) / sizeof(char)); i++)
		while ((pos = words.find(tab[i])) != string::npos)
			words.replace(pos, 1, "00");
	return words;
}
string ttod(string words) {
	for (int i = 0; i < words.size(); i++) {
		words[i] = words[i] == 't' ? 'd' : words[i];
		words[i] = words[i] == 'T' ? 'D' : words[i];
	}
	return words;
}
string sitozy(string words) {
	size_t pos;
	string sylablesToBeReplaced[4] = { "Si", "si", "sI", "SI" };
	string sylablesToReplace[4] = { "Zy", "zy", "zY", "ZY" };
	for (int i = 0; i < 4; i++)
		while ((pos = words.find(sylablesToBeReplaced[i])) != string::npos)
			words.replace(pos, 2, sylablesToReplace[i]);
	return words;
}
string genseq(string words) {
	string answer = "";
	int num = 0;
	for (int i = 0; i < words.size(); i++) {
		while (words[i] < 59 && words[i] > 47) {
			num *= 10;
			num += words[i] - 48;
			i++;
		}
		if (num != 0) {
			string sub = words.substr(words.find('\"'), words.find('\"', words.find('\"') + 1));
			sub.erase(0, 1); sub.erase(sub.size() - 1, 1);
			for (int i = 0; i < num; i++) answer += sub;
			num = 0;
			i += sub.size() + 1;
		}
		else {
			answer += words[i];
		}
	}
	return answer;
}
void clear() {
	system("cls");
}
void help() {
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << string(READINNES_SIGN) << "Skladnia: prefix + polecenie, prefix to: " << PREFIX << " \n";
	cout << string(READINNES_SIGN) << "Polecenia:\n";
	cout << "  gen - powiela wybrany znak o wybrana liczbe razy\n";
	cout << "  aspi - zamienia co druga litere w zdaniu na duza\n";
	cout << "  sane - zamienia co druga litere w zdaniu na duza zaczynajac od pierwszej\n";
	cout << "  low - zamienia wszystkie litery na male\n";
	cout << "  up - zamienia wszystkie litery na duze\n";
	cout << "  ptob - zamienia wszystkie miekkie spolgloski na twarde\n";
	cout << "  uto00 - zamienia wszystkie u na 00\n";
	cout << "  sitozy - zamienia wszystkie \"si\" na \"zy\"\n";
	cout << "  genseq - powiela wybraną grupę znaków w \"\" o wybrana liczbe razy\n";
	cout << string(READINNES_SIGN) << "powyzsze wyrazenia mozna laczyc - uzywac kilku polecen do jednego zdania\n";
	cout << "  clear - wyczyszcza historie czatu\n";
	cout << "  help - ta wiadomosc\n";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

// table of pointers to those functions
string(*functions[])(string) = {
	gen, aspi, sane, low, up, ptob, uto00, ttod, sitozy, genseq
};
//functions which are organising the program
IDS word_to_enum(string word) {
	word = low(word);
	for (int i = 0; i < (sizeof(NAMES) / sizeof(NAMES[0])); i++)
		if (word == (PREFIX + NAMES[i]))
			return static_cast<IDS>(i);
	return ERROR_ID;
}
void error(string message){
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	const char* str = message.c_str();
	(message.substr(0, 2) == string(READINNES_SIGN)) ? printf("%s\n", str) : printf("\t%s\n", str);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void executeConversions(vector<int> funcIds, string message) {
	if (funcIds[0] == CLEAR_ID)
		clear();
	else if (funcIds[0] == HELP_ID)
		help();
	else {
		for (int i = 0; i < funcIds.size(); i++)
			message = functions[funcIds[i]](message);
		cout << RESULT_SIGN << message << endl;
	}
}
void commands(string words) {
	int forbiddenIds[] = { HELP_ID, CLEAR_ID };
	stringstream s(words);
	vector<int> func;
	vector<string> errorMessages;
	string actualMessage;
	string indivWord;
	bool flag = 1;
	// analisys of nonexistent keywords
	while (s >> indivWord) {
		if (indivWord[0] == PREFIX && flag) {
			int id = word_to_enum(indivWord);
			if (id != ERROR_ID)
				func.push_back(id);
			else
				errorMessages.push_back("Nieznane polecenie: \"" + indivWord + "\"");
		} else {
			flag = 0;
			actualMessage += " " + indivWord;
		}
	}
	// analisys if the user provided any keywords
	if (func.size() == 0 && errorMessages.size() == 0 && actualMessage != "")
		errorMessages.push_back("Brak polecen!");
	// analisys if the use wrote anything
	else if (actualMessage == "" && func.size() == 0 && errorMessages.size() == 0){
		throw runtime_error("Brak wiadomosci");
	}
	// analisys if the user did use the keywords with no arguments, with arguments
	for (int i = 0; i < (sizeof(forbiddenIds) / sizeof(forbiddenIds[0])); i++)
		if (func.size() > 1 && find(func.begin(), func.end(), forbiddenIds[i]) != func.end())
			errorMessages.push_back("Funkcja " + string(NAMES[forbiddenIds[i]]) + " nie występuje w konfiguracjach!");

	if (errorMessages.size() == 0)
		executeConversions(func, actualMessage);
	else {
		error(string(READINNES_SIGN) + "Liczba bledow : " + to_string(errorMessages.size()));
		for (int i = 0; i < errorMessages.size(); i++)
			error(errorMessages[i]);
	}
}

int main() {
	string ans;
	help();
	do{
		try {
			cout << READINNES_SIGN;
			getline(cin, ans);
			commands(ans);
		}
		catch (const exception& e) {
			//nothing happens when there is no text entered
		}
	}while (true);
	return 0;//k00pa
}