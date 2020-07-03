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
#include <corefw/class.h>

struct UtilBitSet
extern CFWClass *UtilBitSet;

extern void* UtilBitSet_New(struct UtilBitSet* self, int nbits); 

extern int UtilBitSet_NextSetBit(struct UtilBitSet* self, int fromIndex); 

extern bool UtilBitSet_Intersects(struct UtilBitSet* self, struct UtilBitSet* set); 

extern bool UtilBitSet_IsEmpty(struct UtilBitSet* self); 

extern void UtilBitSet_Set(struct UtilBitSet* self, int bitIndex, bool value); 

extern bool UtilBitSet_Get(struct UtilBitSet* self, int bitIndex); 

extern void UtilBitSet_Clear(struct UtilBitSet* self, int bitIndex);  

extern CFWString* UtilBitSet_ToString(struct UtilBitSet* self);
