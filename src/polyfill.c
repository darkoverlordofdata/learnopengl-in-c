/*******************************************************************
** This code is part of the Dark Framework.
**
MIT License

Copyright (c) 2018 Dark Overlord of Data

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
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
#include "polyfill.h"

//  some string related functions that should be in the stdlib

/**
 * strrstr - Returns a pointer to the first occurrence of str2 
 * in str1, or a null pointer if str2 is not part of str1.
 * 
 * @param str string to search in
 * @param str2 string to search for
 * @return ptr to the substring
 */
char * strrstr(char *str1, char *str2)
{
  size_t slen = strlen(str1);
  size_t flen = strlen(str2);
  if (flen > slen) return NULL;

  for (char* result = str1 + slen - flen; result >= str1; result--)
  {
    if (strncmp(result, str2, flen) == 0)
        return result;
  }
  return NULL;
}

/**
 * strndup - Returns a pointer to a null-terminated byte string, which 
 * is a duplicate of the string pointed to by str1. The returned pointer 
 * must be passed to free to avoid a memory leak.
 * 
 * @param str string to duplicate
 * @param size of the new string
 * @return ptr to the new string
 */
#ifndef strdup
char* strdup(const char* s) {
    size_t len = strlen(s)+1;
    void* new = malloc(len);
    if (new == NULL) return NULL;
    return (char*)memcpy(new, s, len);
}
#endif

/**
 * strndup - Returns a pointer to a null-terminated byte string, which 
 * is a duplicate of the string pointed to by str1. The returned pointer 
 * must be passed to free to avoid a memory leak.
 * 
 * @param str string to duplicate
 * @param size of the new string
 * @return ptr to the new string
 */
char * strndup (const char *str, size_t size)
{
  size_t len = strlen(str);
  len = size < len ? size : len;
  char *result = (char*)calloc(len + 1, sizeof(char));
  return strncpy(result, str, len);
}


// #ifndef _WIN64
// int strcmpi (const char *s1, const char *s2)
// {
//   const unsigned char *p1 = (const unsigned char *) s1;
//   const unsigned char *p2 = (const unsigned char *) s2;
//   unsigned char c1, c2;

//   if (p1 == p2)
//     return 0;

//   do
//     {
//       c1 = tolower (*p1++);
//       c2 = tolower (*p2++);
//       if (c1 == '\0')
// 	break;
//     }
//   while (c1 == c2);
  
//   return c1 - c2;
// }
// #endif


// #ifndef _WIN64
// char* strlwr(char *str)
// {
//   char *s;

//   for(s = str; *s; s++)
//     *s = tolower((unsigned char)*s);
//   return str;
// }
// #endif

// #ifndef _WIN64
// char* strupr(char *str)
// {
//   char *s;

//   for(s = str; *s; s++)
//     *s = toupper((unsigned char)*s);
//   return str;
// }
// #endif
