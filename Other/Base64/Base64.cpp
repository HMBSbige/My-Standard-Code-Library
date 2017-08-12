#include "Base64.h"

static const char *g_pCodes =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

static const unsigned char g_pMap[256] =
{
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255,  62, 255, 255, 255,  63,
	52,  53,  54,  55,  56,  57,  58,  59,  60,  61, 255, 255,
	255, 254, 255, 255, 255,   0,   1,   2,   3,   4,   5,   6,
	7,   8,   9,  10,  11,  12,  13,  14,  15,  16,  17,  18,
	19,  20,  21,  22,  23,  24,  25, 255, 255, 255, 255, 255,
	255,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,
	37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,
	49,  50,  51, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255
};

Base64::Base64()
{
}

Base64::~Base64()
{
}
string Base64::Encode(string strIn)
{
	size_t len = strIn.length();
	unsigned long i;
	string strOut = "";
	unsigned long leven = 3 * (len / 3);
	for (i = 0; i < leven; i += 3)
	{
		strOut += g_pCodes[strIn[0] >> 2];
		strOut += g_pCodes[((strIn[0] & 3) << 4) + (strIn[1] >> 4)];
		strOut += g_pCodes[((strIn[1] & 0xf) << 2) + (strIn[2] >> 6)];
		strOut += g_pCodes[strIn[2] & 0x3f];
		strIn.erase(0, 3);
	}

	if (i < len)
	{
		unsigned char a = strIn[0];
		unsigned char b = ((i + 1) < len) ? strIn[1] : 0;
		unsigned char c = 0;

		strOut += g_pCodes[a >> 2];
		strOut += g_pCodes[((a & 3) << 4) + (b >> 4)];
		strOut += ((i + 1) < len) ? g_pCodes[((b & 0xf) << 2) + (c >> 6)] : '=';
		strOut += '=';
	}
	return strOut;
}

string Base64::Decode(const string& strIn)
{
	unsigned long t, y;
	unsigned long g = 3;
	string strOut = "";

	for (unsigned long x = y = t = 0; x < strIn.length(); ++x)
	{
		unsigned char c = g_pMap[strIn[x]];
		if (c == 255) continue;
		if (c == 254)
		{
			c = 0; 
			--g;
		}

		t = (t << 6) | c;

		if (++y == 4)
		{
			strOut += static_cast<unsigned char>((t >> 16) & 255);
			if (g > 1) 
				strOut += static_cast<unsigned char>((t >> 8) & 255);
			if (g > 2) 
				strOut += static_cast<unsigned char>(t & 255);
			y = t = 0;
		}
	}
	return strOut;
}