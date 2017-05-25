#pragma once
#include <Windows.h>
#include <string>
using namespace std;
class CharacterEncodingConversion
{
public:
	CharacterEncodingConversion();
	virtual~ CharacterEncodingConversion();
	char* WcharToChar(const wchar_t* wp);
	static char* StringToChar(const string& s);
	char* WstringToChar(const wstring& ws);
	wchar_t* CharToWchar(const char* c);
	static wchar_t* WstringToWchar(const wstring& ws);
	wchar_t* StringToWchar(const string& s);
	wstring StringToWstring(const string& s);
	string WstringToString(const wstring& ws);
	void Release();
private:
	char* m_char;
	wchar_t* m_wchar;
};