#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class clsUtil {
	static string GetTextDigit(int Number) {
		string arrNumbers[]{ "", "One",	"Two",	"Three",	"Four",
			"Five",	"Six",	"Seven",	"Eight",	"Nine",	"Ten",
			"Eleven",	"Twelve",	"Thirteen",	"Fourteen",	"Fifteen",
			"Sixteen",	"Seventeen",	"Eighteen",	"Nineteen"
		};

		return (Number < 20) ? arrNumbers[Number] : "";
	}

	static string GetTextTens(int Number) {
		string Text[]{ "", "", "Twenty", "Thirty", "Forty",
			"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
		};

		return (Number >= 20 && Number <= 90 && Number % 10 == 0) ? Text[Number / 10] : "";
	}

	static string AddS(string word, short Digit) {
		return (Digit == 1) ? word : word + 's';
	}

public:

	static void Print(string String) {
		cout << "\n" << String << endl;
	}

	static string GetFullName(string FirstName, string LastName) {
		return FirstName + " " + LastName;
	}

	static float Sum(float Number[], short Lingth) {
		float Sum = 0;

		for (short i = 0; i < Lingth; i++)
			Sum += Number[i];

		return Sum;
	}

	static float Sum(vector <float> Number) {
		float Sum = 0;

		for (short i = 0; i < Number.size(); i++)
			Sum += Number[i];

		return Sum;
	}

	static int Sum(int Array[], int arrLength) {
		int Sum = 0;
		for (int i = 0; i < arrLength; i++)
			Sum += Array[i];

		return Sum;
	}

	static int Sum(vector <int> vVec) {
		int Sum = 0;
		for (int i = 0; i < vVec.size(); i++)
			Sum += vVec[i];

		return Sum;
	}

	static void Sum(int arrSum[], int arrSource1[], int arrSource2[], int arrLength) {
		for (int i = 0; i < arrLength; i++)
			arrSum[i] = arrSource1[i] + arrSource2[i];
	}

	static vector <int> Sum(vector <int> vNums1, vector <int> vNums2) {
		vector <int> Sum;

		if (vNums1.size() != vNums2.size())
			return Sum;

		for (int i = 0; i < vNums1.size(); i++)
			Sum[i] = vNums1[i] + vNums2[i];

		return Sum;
	}

	static int Avg(int Array[], int arrLength) {
		return Sum(Array, arrLength) / arrLength;
	}

	static int Avg(vector <int> vVec) {
		return Sum(vVec) / vVec.size();
	}

	static float Avg(float Number[], short Lingth) {
		return Sum(Number, Lingth) / Lingth;
	}

	static float Avg(vector <float> Number) {
		return Sum(Number) / Number.size();
	}

	static int TimesRepeated(int Number, int arr[], int arrLength) {
		int count = 0;

		for (int i = 0; i < arrLength; i++)
			if (Number == arr[i])
				count++;

		return count;
	}

	static int TimesRepeated(int Number, vector <int> Vec) {
		int count = 0;

		for (int i = 0; i < Vec.size(); i++)
			if (Number == Vec[i])
				count++;

		return count;
	}

	static int MaxNumber(int Array[], short arrLength) {
		int Max = Array[0];
		for (short i = 1; i < arrLength; i++)
			if (Array[i] > Max)
				Max = Array[i];

		return Max;
	}

	static int MaxNumber(vector <int> vVec) {
		int Max = vVec[0];
		for (short i = 1; i < vVec.size(); i++)
			if (vVec[i] > Max)
				Max = vVec[i];

		return Max;
	}

	static int MinNumber(int Array[], short arrLength) {
		int Min = Array[0];
		for (short i = 1; i < arrLength; i++)
			if (Array[i] < Min)
				Min = Array[i];

		return Min;
	}

	static int MinNumber(vector <int> vVec) {
		int Min = vVec[0];
		for (short i = 1; i < vVec.size(); i++)
			if (vVec[i] < Min)
				Min = vVec[i];

		return Min;
	}

	static void Copy(int arrSource[], int arrDestination[], int arrLength) {
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];

	}

	static vector <int> Copy(vector <int> vVec) {
		vector <int> vCopy;

		for (int i = 0; i < vVec.size(); i++)
			vCopy[i] = vVec[i];

		return vCopy;
	}

	static void GetPrimeNumbers(int arrSource[], int arrLength, int arrDestination[], int& arrDestinationLength) {
		arrDestinationLength = 0;

		for (int i = 0; i < arrLength; i++)
			if (IsPrimeNumber(arrSource[i])) {
				arrDestination[arrDestinationLength] = arrSource[i];
				arrDestinationLength++;
			}
	}

	static vector <int> GetPrimeNumbers(vector <int> vNum) {
		vector <int> vPrim;
		int arrDestinationLength = 0;

		for (int i = 0; i < vNum.size(); i++)
			if (IsPrimeNumber(vNum[i])) {
				vPrim[arrDestinationLength] = vNum[i];
				arrDestinationLength++;
			}
	}

	static void Shuffle(int arr[], int arrLength) {
		for (int i = 0; i < arrLength; i++) {
			int RandomIndex1 = RandomNumber(0, arrLength - 1);
			int RandomIndex2 = RandomNumber(0, arrLength - 1);

			Swap(arr[RandomIndex1], arr[RandomIndex2]);
		}
	}

	static void Shuffle(string arr[], int arrLength) {
		for (int i = 0; i < arrLength; i++) {
			int RandomIndex1 = RandomNumber(0, arrLength - 1);
			int RandomIndex2 = RandomNumber(0, arrLength - 1);

			Swap(arr[RandomIndex1], arr[RandomIndex2]);
		}
	}

	static void Shuffle(vector <int> vNum) {
		for (int i = 0; i < vNum.size(); i++) {
			int RandomIndex1 = RandomNumber(0, vNum.size() - 1);
			int RandomIndex2 = RandomNumber(0, vNum.size() - 1);

			Swap(vNum[RandomIndex1], vNum[RandomIndex2]);
		}
	}

	static void Shuffle(vector <string> vNum) {
		for (int i = 0; i < vNum.size(); i++) {
			int RandomIndex1 = RandomNumber(0, vNum.size() - 1);
			int RandomIndex2 = RandomNumber(0, vNum.size() - 1);

			Swap(vNum[RandomIndex1], vNum[RandomIndex2]);
		}
	}

	static void CopyInReverseOrder(int arrSource[], int arrDestination[], int arrLength) {
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[arrLength - 1 - i];
	}

	static vector <int> CopyInReverseOrder(vector <int> vVec) {
		vector <int> vCopy;

		for (int i = 0; i < vVec.size(); i++)
			vCopy[i] = vVec[vVec.size() - 1 - i];

		return vCopy;
	}

	static int FindNumberPosition(int arr[], int Num, int arrLength) {
		for (int i = 0; i < arrLength; i++)
			if (arr[i] == Num)
				return i;

		return -1;
	}

	static int FindNumberPosition(vector <int> vNum, int Num) {
		for (int i = 0; i < vNum.size(); i++)
			if (vNum[i] == Num)
				return i;

		return -1;
	}

	static bool IsNumberInArray(int arr[], int Num, int arrLength) {
		return (FindNumberPosition(arr, Num, arrLength) != -1);
	}

	static int IsNumberInVector(vector <int> vNum, int Num) {
		return FindNumberPosition(vNum, Num) != -1;
	}

	static void GetOddNumbers(int arrOdd[], int& arrOddLength, int arr[], int arrLength) {
		arrOddLength = 0;

		for (int i = 0; i < arrLength; i++)
			if (arr[i] % 2 != 0) {
				arrOdd[arrOddLength] = arr[i];
				arrOddLength++;
			}
	}

	static vector <int> GetOddNumbers(vector <int> vNum) {
		vector <int> vOddNum;

		for (int i = 0; i < vNum.size(); i++)
			if (vNum[i] % 2 != 0)
				vOddNum.push_back(vNum[i]);

		return vOddNum;
	}

	static void GetPrimeNumberInArray(int arr2[], int& arrLength2, int arr[], int arrLength) {
		arrLength2 = 0;

		for (int i = 0; i < arrLength; i++)
			if (IsPrimeNumber(arr[i])) {
				arr2[arrLength2] = arr[i];
				arrLength2++;
			}
	}

	static  vector <int> GetPrimeNumberInArray(vector <int> vNum) {
		vector <int> vPrime;

		for (int i = 0; i < vNum.size(); i++)
			if (IsPrimeNumber(vNum[i]))
				vPrime.push_back(vNum[i]);

		return vPrime;
	}

	static bool IsPalindrome(int arr1[], int arr2[], int arrLength) {
		for (int i = 0; i < arrLength; i++)
			if (arr1[i] != arr2[i - arrLength - 1])
				return false;

		return true;
	}

	static bool IsPalindrome(vector <int> vNum1, vector <int> vNum2) {
		if (vNum1.size() != vNum2.size())
			return false;

		for (int i = 0; i < vNum1.size(); i++)
			if (vNum1[i] != vNum2[i])
				return false;

		return true;
	}

	static int GetOddCount(int arr[], int arrLength) {
		int Count = 0;

		for (int i = 0; i < arrLength; i++)
			if (arr[i] % 2 != 0)
				Count++;

		return Count;
	}

	static int GetOddCount(vector <int> vNum) {
		int Count = 0;

		for (int n : vNum)
			if (n % 2 != 0)
				Count++;

		return Count;
	}

	static int GetEvenCount(int arr[], int arrLength) {
		int Count = 0;

		for (int i = 0; i < arrLength; i++)
			if (arr[i] % 2 == 0)
				Count++;

		return Count;
	}

	static int GetEvenCount(vector <int> vNum) {
		int Count = 0;

		for (int n : vNum)
			if (n % 2 == 0)
				Count++;

		return Count;
	}

	static int GetPositiveCount(int arr[], int arrLength) {
		int Count = 0;

		for (int i = 0; i < arrLength; i++)
			if (arr[i] > 0)
				Count++;

		return Count;
	}

	static int GetPositiveCount(vector <int> vNum) {
		int Count = 0;

		for (int n : vNum)
			if (n > 0)
				Count++;

		return Count;
	}

	static int GetrNegativeCount(int arr[], int arrLength) {
		int Count = 0;

		for (int i = 0; i < arrLength; i++)
			if (arr[i] < 0)
				Count++;

		return Count;
	}

	static int GetrNegativeCount(vector <int> vNum) {
		int Count = 0;

		for (int n : vNum)
			if (n < 0)
				Count++;

		return Count;
	}

	static void FibonacciSeries(int Array[], short Length) {
		for (short i = 0; i < Length; i++) {
			if (i > 1)
				Array[i] = Array[i - 1] + Array[i - 2];
			else
				Array[i] = 1;
		}
	}

	static vector <int> FibonacciSeries(short Length = 10) {
		vector <int> vNum;

		for (short i = 0; i < Length; i++) {
			if (i > 1)
				vNum[i] = vNum[i - 1] + vNum[i - 2];
			else
				vNum[i] = 1;
		}

		return vNum;
	}

	static string NumberToText(int Number) {
		if (Number < 0)
			return "";
		if (Number == 0)
			return "Zero";

		if (Number < 20)
			return GetTextDigit(Number);
		if (Number < 100) {
			string tens = GetTextTens(Number - (Number % 10));
			string ones = GetTextDigit(Number % 10);
			return (!ones.empty()) ? tens + " " + ones : tens;
		}
		if (Number < 1000) {
			string hundredPart = GetTextDigit(Number / 100) + " " + AddS("Hundred", Number / 100);
			string remainder = NumberToText(Number % 100);
			return (!remainder.empty()) ? hundredPart + " and " + remainder : hundredPart;
		}
		if (Number < 1000000)
			return NumberToText(Number / 1000) + " " + AddS("Thousand", Number / 1000) + " " + NumberToText(Number % 1000);
		if (Number < 1000000000)
			return NumberToText(Number / 1000000) + " " + AddS("Million", Number / 1000000) + " " + NumberToText(Number % 1000000);
		if (Number <= 2147483647)
			return NumberToText(Number / 1000000000) + " " + AddS("Billion", Number / 1000000000) + " " + NumberToText(Number % 1000000000);

		return "";
	}

	static float GetHalfNumber(float Num)
	{
		return (float)Num / 2;
	}

	static bool IsEven(int Num) {
		short Result = Num % 2;

		return (Result == 0);
	}

	static bool IsOdd(int Num) {
		return !IsEven(Num);
	}

	static void Swap(int& Num1, int& Num2) {
		int Temp;

		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static void Swap(string& Num1, string& Num2) {
		string Temp;

		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static int SumOdd(int Num[], short Lingth) {
		int Sum = 0;

		for (short i = 1; i < Lingth; i++)
			if (IsOdd(Num[i]))
				Sum += Num[i];

		return Sum;
	}

	static int SumOdd(vector <int> Num) {
		int Sum = 0;

		for (short i = 1; i < Num.size(); i++)
			if (IsOdd(Num[i]))
				Sum += Num[i];

		return Sum;
	}

	static int SumEven(int Num[], short Lingth) {
		int Sum = 0;

		for (short i = 1; i < Lingth; i++)
			if (IsEven(Num[i]))
				Sum += Num[i];

		return Sum;
	}

	static int SumEven(vector <int> Num) {
		int Sum = 0;

		for (short i = 1; i < Num.size(); i++)
			if (IsEven(Num[i]))
				Sum += Num[i];

		return Sum;
	}

	static bool IsPrimeNumber(int Number)
	{
		if (Number <= 1)
			return false;

		for (int i = 2; i <= round(sqrt(Number)); i++)
			if (Number % i == 0)
				return false;

		return true;
	}

	static bool IsPerfectNumber(int Number)
	{
		int Sum = 0;

		for (int Counter = Number / 2; Counter >= 1; Counter--)
			if (Number % Counter == 0)
				Sum += Counter;

		return (Number == Sum);
	}

	static int ReverseNumber(int Number) {
		int Remainder;
		int ReversedNumber = 0;

		while (Number > 0) {
			Remainder = Number % 10;
			Number /= 10;

			ReversedNumber = ReversedNumber * 10 + Remainder;
		}

		return ReversedNumber;
	}

	static bool IsPalindromeNumber(int Number) {
		return Number == ReverseNumber(Number);
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
			Text[i] = char((int)Text[i] + EncryptionKey);

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
			Text[i] = char((int)Text[i] - EncryptionKey);

		return Text;
	}

	static string EncryptDecrypt_XOR(const string& text, const string& key)
	{
		string output = text;
		int keyLen = key.length();
		int k = 0;

		for (int i = 0; i < output.length(); i++)
		{
			// XOR with key + shifting key index dynamically
			output[i] = output[i] ^ key[k] ^ (i % 7);

			// move key index
			k = (k + 1) % keyLen;
		}
		return output;
	}

	static void SRAND() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From = 0, int To = 1000) {
		if (From > To)
			return 0;

		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static enum enCharType { eSmallLetter = 1, eCapitalLetter = 2, eSpecialCharacter = 3, eDigit = 4, eMix = 5 };

	static char GetRandomCharacter(enCharType CharType = enCharType::eSmallLetter)
	{
		switch (CharType)
		{
		case enCharType::eSmallLetter:
			return char(RandomNumber(97, 122));
		case enCharType::eCapitalLetter:
			return char(RandomNumber(65, 90));
		case enCharType::eSpecialCharacter:
			return char(RandomNumber(33, 47));
		case enCharType::eDigit:
			return char(RandomNumber(48, 57));
		case enCharType::eMix:
			return GetRandomCharacter((enCharType)RandomNumber(1, 4));
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
			Word = Word + GetRandomCharacter(CharType);

		return Word;
	}

	static string GenerateKey(enCharType eCharType, short LingthWord, short NumberOfWords, string Spirater = "") {
		string Key = "";

		for (short i = 1; i <= NumberOfWords; i++)
			Key = Key + GenerateWord(eCharType, LingthWord) + Spirater;

		Key.pop_back();
		return Key;
	}

	static vector <string> GenerateKeys(short NumberOfKeys, enCharType eCharType = enCharType::eMix, short LingthWord = 4, short NumberOfWords = 1, string Spirater = "") {
		vector <string> vKeys;

		for (int i = 1; i <= NumberOfKeys; i++)
			vKeys.push_back(GenerateKey(eCharType, LingthWord, NumberOfWords, Spirater));

		return vKeys;
	}
};