#pragma once
#include <vector>
#include <string>

using  namespace std;

class clsString {
private:

	string _Value;

	static vector <string> ReverserVector(vector <string> vS1) {
		vector <string> vReverseS1;

		for (short i = (short)vS1.size() - 1; i >= 0; i--)
			vReverseS1.push_back(vS1[i]);

		return vReverseS1;
	}

public:

	clsString() {
		_Value = "";
	}

	clsString(string Value) {
		_Value = Value;
	}

	void SetValue(string Value) {
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static int Length(string S1) {
		return (int)S1.length();
	}

	int Length() {
		return (int)_Value.length();
	}

	static vector <char> GetFirstLetters(string Text, string Delim = " ") {
		vector <char> vFirstLetters;
		vector <string> vWrds = GetAllWords(Text);

		for (string w : vWrds)
			vFirstLetters.push_back(w[0]);

		return vFirstLetters;
	}

	vector <char> GetFirstLetters() {
		return GetFirstLetters(_Value);
	}

	static string UpperFirstLetter(string Text, string Delim = " ") {
		vector <string> vWrds = GetAllWords(Text);

		for (string& w : vWrds) {
			if (short(w[0]) >= 97 && short(w[0]) <= 122)
				w[0] = short(w[0]) - 32;
		}

		return VectorToString(vWrds);
	}

	void UpperFirstLetter() {
		_Value = UpperFirstLetter(_Value);
	}

	static string LowerFirstLetter(string Text, string Delim = " ") {
		vector <string> vWrds = GetAllWords(Text);

		for (string& w : vWrds) {
			if (short(w[0]) >= 60 && short(w[0]) <= 90)
				w[0] = short(w[0]) + 32;
		}

		return VectorToString(vWrds);
	}

	void LowerFirstLetter() {
		_Value = LowerFirstLetter(_Value);
	}

	static string UpperAllLetter(string Text) {
		for (short i = 0; i < Text.length(); i++)
			Text[i] = toupper(Text[i]);

		return Text;
	}

	void UpperAllLetter() {
		_Value = UpperAllLetter(_Value);
	}

	static string LowerAllLetter(string Text) {
		for (short i = 0; i < Text.length(); i++)
			Text[i] = tolower(Text[i]);

		return Text;
	}

	void LowerAllLetter() {
		_Value = LowerAllLetter(_Value);
	}

	static char InvertChar(char Char) {
		if ((short(Char) >= 60 && short(Char) <= 90))
			return short(Char) + 32;
		else if ((short(Char) >= 97 && short(Char) <= 122))
			return short(Char) - 32;
		else
			return Char;
	}

	static string InvertString(string Text) {
		for (short i = 0; i < Text.length(); i++)
			Text[i] = InvertChar(Text[i]);

		return Text;
	}

	void InvertString() {
		_Value = InvertString(_Value);
	}

	static int CountCapitalLetters(string Text) {
		int Count = 0;

		for (short i = 0; i < Text.length(); i++)
			if (_IsCapital(Text[i]))
				Count++;

		return Count;
	}

	int CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}

	static int CountSmallLetters(string Text) {
		int Count = 0;

		for (short i = 0; i < Text.length(); i++)
			if (_IsSmall(Text[i]))
				Count++;

		return Count;
	}

	int CountSmallLetters() {
		return CountSmallLetters(_Value);
	}

	static bool IsLetter(char C1) {
		if ((short(C1) >= 97 && short(C1) <= 122) || (short(C1) >= 60 && short(C1) <= 90))
			return true;
		return false;
	}

	static bool _IsNumber(char C1) {
		if ((short(C1) >= 48 && short(C1) <= 58))
			return true;
		return false;
	}

	static int LetterCounterCapitalOrSmall(string Text, char Char) {
		return  CountSpecificLetter(Text, Char) + CountSpecificLetter(Text, InvertChar(Char));
	}

	int LetterCounterCapitalOrSmall(char Char) {
		return LetterCounterCapitalOrSmall(_Value, Char);
	}

	static int CountSpecificLetter(string Text, char Char) {
		int Count = 0;

		for (int i = 0; i < Text.length(); i++) {
			if (Char == Text[i])
				Count++;
		}
		return Count;
	}

	int CountSpecificLetter(char Char) {
		return CountSpecificLetter(_Value, Char);
	}

	static bool IsVowel(char Letter) {
		Letter = toupper(Letter);
		return ((Letter == 'A') || (Letter == 'E') || (Letter == 'I') || (Letter == 'O') || (Letter == 'U'));
	}

	static bool _IsCapital(char Char) {
		return (short(Char) >= 60 && short(Char) <= 90);
	}

	static bool _IsSmall(char Char) {
		return (short(Char) >= 97 && short(Char) <= 122);
	}

	static int CountVowels(string Text) {
		int Counter = 0;
		for (int i = 0; i <= Text.length(); i++)
			if (IsVowel(Text[i]))
				Counter++;

		return Counter;
	}

	int CountVowels() {
		return CountVowels(_Value);
	}

	static vector <char> GetVowels(string Text) {
		vector <char> vContainer;

		for (short i = 0; i <= Text.length(); i++)
			if (IsVowel(Text[i]))
				vContainer.push_back(Text[i]);

		return vContainer;
	}

	vector <char> GetVowels() {
		return GetVowels(_Value);
	}

	static vector <string> GetAllWords(string Text, string Delim = " ") {
		vector <string> vWords;
		string sWord;
		int pos = 0;

		while ((pos = (int)Text.find(Delim)) != std::string::npos) {
			sWord = Text.substr(0, pos);
			if (sWord != "")
				vWords.push_back(sWord);
			Text.erase(0, pos + Delim.length());
		}

		if (Text != "")
			vWords.push_back(Text);

		return vWords;
	}

	vector <string> GetAllWords() {
		return GetAllWords(_Value);
	}

	static int CountWords(string Text, string Delim = " ") {
		vector <string> vWords = GetAllWords(Text, Delim);

		return (int)vWords.size();
	}

	int CountWords() {
		return CountWords(_Value);
	}

	static string TrimRight(string S1) {
		for (int i = (int)S1.length() - 1; i >= 0; i--)
			if (S1[i] != ' ')
				return S1.substr(0, i + 1);

		return"";
	}

	string TrimRight() {
		return TrimRight(_Value);
	}

	static string TrimLeft(string S1) {
		for (short i = 0; i < S1.length(); i++)
			if (S1[i] != ' ')
				return S1.substr(i, S1.length() - i);

		return"";
	}

	string TrimLeft() {
		return TrimLeft(_Value);
	}

	static string Trim(string S1) {
		S1 = TrimLeft(S1);
		return TrimRight(S1);
	}

	string Trim() {
		return Trim(_Value);
	}

	static string VectorToString(vector <string> vString, string Delim = " ") {
		string S1 = "";
		for (string& s : vString)
			S1 = S1 + s + Delim;

		return S1.substr(0, S1.length() - Delim.length());
	}

	static void FillArrayWithString(string arrS1[], string S1, short& NumWords, string Separators = " ") {
		string sWord;
		int pos = 0;
		short Counter = 0;
		NumWords = 0;

		while ((pos = (int)S1.find(Separators)) != std::string::npos && Counter <= 100) {
			sWord = S1.substr(0, pos);
			if (sWord != "")
				arrS1[Counter] = sWord;
			S1.erase(0, pos + Separators.length());
			Counter++;
			NumWords++;
		}

		if (S1 != "") {
			arrS1[Counter] = S1;
			NumWords++;
		}
	}

	void FillArrayWithString(string arrS1[], short& NumWords, string Separators = " ") {
		FillArrayWithString(arrS1, _Value, NumWords, Separators);
	}

	static string ReverserWords(string S1) {
		return VectorToString(ReverserVector(GetAllWords(S1)), " ");
	}

	void ReverserWords() {
		_Value = ReverserWords(_Value);
	}

	static string ReverserString(string S1) {
		string Revers;

		for (int i = (int)S1.length(); i >= 0; i--)
			Revers += S1[i];

		return Revers;
	}

	string ReverserString() {
		return ReverserString(_Value);
	}

	static string Replace(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true) {
		vector<string> vString = GetAllWords(S1, " ");

		if (MatchCase) {
			for (string& s : vString) {
				if (s == StringToReplace)
					s = sRepalceTo;
			}
		}
		else {
			for (string& s : vString)
				if (LowerAllLetter(s) == LowerAllLetter(StringToReplace))
					s = sRepalceTo;
		}

		return VectorToString(vString, " ");
	}

	string Replace(string OriginalWords, string ReplaceWord, bool MatchCase = true) {
		return Replace(_Value, OriginalWords, ReplaceWord, MatchCase);
	}

	static string RemovePunctuations(string S1) {
		short i = 0;

		while (true) {
			if (!(IsLetter(S1[i]) || S1[i] == ' ' || _IsNumber(S1[i]))) {
				S1.erase(S1.find(S1[i]), 1);
				i--;
			}
			i++;
			if (i == S1.length())
				break;
		}

		return S1;
	}

	string RemovePunctuations() {
		return RemovePunctuations(_Value);
	}

	static void Clear(string& Value) {
		Value = "";
	}

	static vector <string> Split(string S1, string Delim){

		vector <string> vString;

		short pos = 0;
		string sWord;

		while ((pos = (short)S1.find(Delim)) != std::string::npos){
			sWord = S1.substr(0, pos);
			vString.push_back(sWord);

			S1.erase(0, pos + Delim.length());
		}

		if (S1 != ""){
			vString.push_back(S1);
		}

		return vString;

	}

	vector <string> Split(string Delim){
		return Split(_Value, Delim);
	}

	void Clear() {
		Clear(_Value);
	}

};