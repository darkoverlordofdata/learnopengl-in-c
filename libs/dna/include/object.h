#pragma once
/**
 * shims for corefw
 */

#include <corefw/object.h>
#include <corefw/string.h>
#include <corefw/hash.h>
#include <corefw/class.h>
#include <corefw/map.h>

static bool ctor(void *self, va_list args);
static void dtor(void *self);
static bool equal(void *ptr1, void *ptr2);
static uint32_t hash(void *self);
static void* copy(void *self);

typedef CFWClass Class;
typedef CFWObject Object;
