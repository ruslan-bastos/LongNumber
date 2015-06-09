#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 4294967296

struct LongNumber
{
	unsigned int size;
	unsigned int* pointer;
};

struct LongNumber ReadNumber(const unsigned long long int value);

struct LongNumber ReadString(const char* num);
char* PrintNumber(struct LongNumber number);

struct LongNumber ReadBinFile(const char* file);
void WriteBinFile(const char* file, const struct LongNumber number);

struct LongNumber ReadTextFile(const char* file);
void WriteTextFile(const char* file, struct LongNumber number);

struct LongNumber ADD(const struct LongNumber a, const struct LongNumber b);
struct LongNumber SUB(const struct LongNumber a, const struct LongNumber b);
struct LongNumber MUL(const struct LongNumber a, const struct LongNumber b);

struct LongNumber DIV(const struct LongNumber a, const struct LongNumber b, int sumbols);
struct LongNumber SmallMul(const struct LongNumber a, const unsigned long long int b);
struct LongNumber shiftLeft(const struct LongNumber a, const unsigned int s);

struct LongNumber DEGREE(const struct LongNumber a, const struct LongNumber b, const struct LongNumber c);
struct LongNumber SmallDIV(const struct LongNumber a, const unsigned long long int b);

struct LongNumber clear(const struct LongNumber number);
struct LongNumber* allocate(const unsigned int size);
void zero(const struct LongNumber *number);

int compare(const struct LongNumber a, const struct LongNumber b);
struct LongNumber copy(const struct LongNumber from);
struct LongNumber Normalize(struct LongNumber a);
