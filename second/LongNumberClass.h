#include "DefinitionOfOperation.h"

class LongNumberClass
{
	LongNumber num;

public:

	LongNumberClass();
	LongNumberClass(const char *string);
	LongNumberClass(const LongNumberClass &right);
	LongNumberClass(const LongNumber &right);
	LongNumberClass(const unsigned long long int value);
	~LongNumberClass();

	char* __str__();
	char* __repr__();

	LongNumberClass operator=(const LongNumberClass &right);
	LongNumberClass operator+(const LongNumberClass &right);
	LongNumberClass operator-(const LongNumberClass &right);
	LongNumberClass operator*(const LongNumberClass &right);
	LongNumberClass operator/(const LongNumberClass &right);
	LongNumberClass operator%(const LongNumberClass &right);

	LongNumberClass operator+(unsigned long long int value);
	LongNumberClass operator-(unsigned long long int value);
	LongNumberClass operator*(unsigned long long int value);
	LongNumberClass operator/(unsigned long long int value);
	LongNumberClass operator%(unsigned long long int value);

	void ReadText(const char *filename);
	void WriteText(const char *filename);
	void ReadBin(const char *filename);
	void WriteBin(const char *filename);

	friend LongNumberClass PowMod(LongNumberClass &base, LongNumberClass &exp, LongNumberClass &mod); // res = LongNumberClass.PowMod(a,b,c)
	friend LongNumberClass PowMod(LongNumberClass &base, LongNumberClass &exp, unsigned long long int mod);
	friend LongNumberClass PowMod(LongNumberClass &base, unsigned long long int exp, LongNumberClass &mod);
	friend LongNumberClass PowMod(unsigned long long int base, LongNumberClass &exp, LongNumberClass &mod);
	friend LongNumberClass PowMod(LongNumberClass &base, unsigned long long int exp, unsigned long long int mod);
	friend LongNumberClass PowMod(unsigned long long int base, LongNumberClass &exp, unsigned long long int mod);
	friend LongNumberClass PowMod(unsigned long long int base, unsigned long long int exp, LongNumberClass &mod);
};
