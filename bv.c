# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include "bv.h"

bitV *newVec(uint64_t len)
{
	bitV *t;
	t = (bitV *)malloc(sizeof(bitV));
	t->vector = (uint8_t *)calloc(len, sizeof(uint8_t));
	t->length = len;
	return t;
}

void delVec(bitV *bv)
{
	free(bv->vector); // Frees the vector of the bit vector
	bv->vector = NULL;
	free(bv); // Frees bit vector itself.
	bv = NULL;
}

void one(bitV *bv)
{
	int count;
	uint64_t arrayLength = (bv->length)/8; // Finds the length of the bit vector array.
	for(uint64_t index = 0; index <= arrayLength; index++) // Goes to every array of the bit vector and sets it to 11111111.
	{
		bv->vector[index] = 255; 
		++count;
	}
}

void setBit(bitV *bv, uint64_t len)
{
	uint8_t orProperty = 1;
	uint64_t tableIndex = len / 8; // Finds the array index the bit is in.
	uint64_t index = len % 8; // Finds the specific bit of the specifc byte of the array.
	orProperty = orProperty << index; // Shifts the 1 bit to the left as many times as where the specified bit is
	bv->vector[tableIndex] |= orProperty; // Does an OR bitwise operation to the array for that specific bit.
}

void clrBit(bitV *bv, uint64_t len)
{
	uint8_t andProperty;
	uint64_t tableIndex = len / 8;
	uint64_t index = len % 8;
	andProperty = (uint8_t)(255 - pow(2,index)); // Basically is the same thing as setBit but reversed.		
	bv->vector[tableIndex] &= andProperty; // Goes the specifc bit and has it & with a 0, while the other bits of the andProperty are 1's.
}
uint8_t valBit(bitV *bv, uint64_t len)
{
	uint64_t tableIndex = len / 8;
	uint64_t index = len % 8;
	return (bv->vector[tableIndex] >> index)%2; // Finds the value of that bit by shifting that bit to the left and checking if the
						    // bit is divisible by 2 or not. The Remainder of that is returned.
}

uint64_t lenVec(bitV *bv)
{
	return bv->length; // Returns the length of the bit vector.
}

void appendCode(bitV *bv, uint64_t indexByte, code *c)
{
	bv->vector[indexByte] = c->l; // Not sure if this is correct.
	return;
}
