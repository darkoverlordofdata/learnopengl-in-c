#include "filesystem.h"

typedef CFWString* (*Builder) (const char* path);
static Builder getPathBuilder();
static CFWString* getPath(const char* path);
static char* const getRoot();
static CFWString* getPathRelativeRoot(const char* path);
static CFWString* getPathRelativeBinary(const char* path);

static char * logl_root = "/home/darkoverlordofdata/GitHub/learnopengl-in-c";

/**
 * getPath
 * 
 * @param path
 * @returns the path
 */
static CFWString* getPath(const char* path)
{
  Builder pathBuilder = getPathBuilder();
  return (*pathBuilder)(path);
}

/**
 * getRoot
 * 
 * @returns this path root
 */
static char* const getRoot()
{
  static char buf[2048];
  return getcwd(buf, sizeof(buf));
}

/**
 * getPathBuilder
 * 
 * @returns path builder function
 */
static Builder getPathBuilder()
{
  if (strcmp(getRoot(), "") != 0)
    return getPathRelativeRoot;
  else
    return getPathRelativeBinary;
}

/**
 * getPathRelativeRoot
 * 
 * @param path
 */
static CFWString* getPathRelativeRoot(const char* path)
{
  CFWString* res = cfw_create(cfw_string, getRoot());
  cfw_string_append_c(res, "/");
  cfw_string_append_c(res, path);
  return res;
}

/**
 * getPathRelativeBinary
 * 
 * @param path
 */
static CFWString* getPathRelativeBinary(const char* path)
{
  CFWString* res = cfw_create(cfw_string, "../../../");
  cfw_string_append_c(res, path);
  return res;
}

/**
 * DNA_FileSystem object
 */
struct DNAFileSystem DNA_FileSystem =
{
  .getPath = getPath,
  .getRoot = getRoot,
  .getPathRelativeRoot = getPathRelativeRoot,
  .getPathRelativeBinary = getPathRelativeBinary
};

