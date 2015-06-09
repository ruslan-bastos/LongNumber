#include "LongNumberClass.h"

LongNumberClass::LongNumberClass()
{ 
    this->num.pointer = (unsigned int*)malloc(sizeof(unsigned int)*(1));
	this->num.pointer[0] = 0;
    this->num.size = 1;
}

LongNumberClass::LongNumberClass(const LongNumber &right)
{
	num = copy(right);
}

LongNumberClass::LongNumberClass(const char* string)
{
	this->num = ReadString(string);
}

LongNumberClass::LongNumberClass(const LongNumberClass &right)
{
	this->num = copy(right.num);
}

LongNumberClass::LongNumberClass(const unsigned long long int value)
{
	this->num = ReadNumber(value);
}

LongNumberClass::~LongNumberClass()
{
	if (this->num.size) 
		delete[] this->num.pointer;
}

/////////////////////////////////////////////////////////////////////////////

char* LongNumberClass::__str__()
{
	LongNumberClass RoRoRo = copy(this->num);
	return PrintNumber(RoRoRo.num);
}

char* LongNumberClass::__repr__()
{
	LongNumberClass RoRoRo = copy(this->num);
	return PrintNumber(RoRoRo.num);
}

/////////////////////////////////////////////////////////////////////////////

LongNumberClass LongNumberClass::operator=(const LongNumberClass &right)
{
	this->num = copy(right.num);
	return *this;
}

LongNumberClass LongNumberClass::operator+(const LongNumberClass &right) 
{
	return ADD(this->num, right.num);
}

LongNumberClass LongNumberClass::operator-(const LongNumberClass &right) 
{
	return SUB(this->num, right.num);
}

LongNumberClass LongNumberClass::operator*(const LongNumberClass &right) 
{
	return MUL(this->num, right.num);
}

LongNumberClass LongNumberClass::operator/(const LongNumberClass &right) 
{
	return DIV(this->num, right.num, 1);
}

LongNumberClass LongNumberClass::operator%(const LongNumberClass &right) 
{
	return DIV(this->num, right.num, 2);
}

/////////////////////////////////////////////////////////////////////////////

LongNumberClass LongNumberClass::operator+(unsigned long long int value) 
{
	return ADD(this->num, ReadNumber(value));
}

LongNumberClass LongNumberClass::operator-(unsigned long long int value) 
{
	return SUB(this->num, ReadNumber(value));
}

LongNumberClass LongNumberClass::operator*(unsigned long long int value) 
{
	return MUL(this->num, ReadNumber(value));
}

LongNumberClass LongNumberClass::operator/(unsigned long long int value) 
{
	return DIV(this->num, ReadNumber(value), 1);
}

LongNumberClass LongNumberClass::operator%(unsigned long long int value) 
{
	return DIV(this->num, ReadNumber(value), 2);
}

/////////////////////////////////////////////////////////////////////////////

void LongNumberClass::ReadText(const char* filename)
{
	*this = ReadTextFile(filename);
}

void LongNumberClass::ReadBin(const char* filename)
{
	*this = ReadBinFile(filename);
}

void LongNumberClass::WriteText(const char* filename)
{
	LongNumberClass RoRoRo = copy(this->num);
	WriteTextFile(filename, RoRoRo.num);
}

void LongNumberClass::WriteBin(const char* filename)
{
	LongNumberClass RoRoRo = copy(this->num);
	WriteBinFile(filename, RoRoRo.num);
}

/////////////////////////////////////////////////////////////////////////////

LongNumberClass PowMod(LongNumberClass &base, LongNumberClass &exp, LongNumberClass &mod)
{
	return DEGREE(base.num, exp.num, mod.num);
}

LongNumberClass PowMod(LongNumberClass &base, LongNumberClass &exp, unsigned long long int mod)
{
	return DEGREE(base.num, exp.num, ReadNumber(mod));
}

LongNumberClass PowMod(LongNumberClass &base, unsigned long long int exp, LongNumberClass &mod)
{
	return DEGREE(base.num, ReadNumber(exp), mod.num);
}

LongNumberClass PowMod(unsigned long long int base, LongNumberClass &exp, LongNumberClass &mod)
{
	return DEGREE(ReadNumber(base), exp.num, mod.num);
}

LongNumberClass PowMod(LongNumberClass &base, unsigned long long int exp, unsigned long long int mod)
{
	return DEGREE(base.num, ReadNumber(exp), ReadNumber(mod));
}

LongNumberClass PowMod(unsigned long long int base, LongNumberClass &exp, unsigned long long int mod)
{
	return DEGREE(ReadNumber(base), exp.num, ReadNumber(mod));
}

LongNumberClass PowMod(unsigned long long int base, unsigned long long int exp, LongNumberClass &mod)
{
	return DEGREE(ReadNumber(base), ReadNumber(exp), mod.num);
}
