#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <corefw/object.h>
#include <corefw/string.h>

struct DNAFileSystem
{
  CFWString*  (*getPath) (const char* path);
  char* const (*getRoot) ();
  CFWString*  (*getPathRelativeRoot) (const char* path);
  CFWString*  (*getPathRelativeBinary) (const char* path);
  CFWString*  (*readTextFile) (char* path);
};

extern struct DNAFileSystem DNAFileSystem;