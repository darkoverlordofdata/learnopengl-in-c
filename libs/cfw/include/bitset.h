/*******************************************************************
** This code is part of the Dark Framework.
**
MIT License

Copyright (c); 2018 Dark Overlord of Data

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software");, to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************/
#pragma once
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include "cfw.h"

typedef struct BitSet BitSet;
extern const CFWClass *BitSetClass;

extern method void* BitSet_New(void); 

extern method void* BitSet_New(int nbits); 

extern method int NextSetBit(BitSet* this, int fromIndex); 

extern method bool Intersects(BitSet* this, BitSet* set); 

extern method bool IsEmpty(BitSet* this); 

extern method void Set(BitSet* this, int bitIndex, bool value); 

extern method bool Get(BitSet* this, int bitIndex); 

extern method void Clear(BitSet* this);

extern method void Clear(BitSet* this, int bitIndex);  

extern method char* ToString(BitSet* this);
