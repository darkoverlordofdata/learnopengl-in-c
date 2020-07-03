#pragma once
/**
 * shims for corefw
 */

#include <corefw/object.h>
#include <corefw/string.h>
#include <corefw/hash.h>
#include <corefw/class.h>
#include <corefw/map.h>

/**
 * MACRO corefw
 *      generate typeinfo boilerplate for corefw
 */ 
#define corefw(CLASSNAME)                                               \
static bool ctor(void *, va_list);										\
static void dtor(void *);												\
static bool equal(void *, void *);										\
static uint32_t hash(void *);											\
static void* copy(void *);												\
const static CFWClass class = {                                         \
	.name = #CLASSNAME,                                                 \
	.size = sizeof(struct CLASSNAME),                                   \
	.ctor = ctor,                                                       \
	.dtor = dtor,                                                       \
	.equal = equal,                                                     \
	.hash = hash,                                                       \
	.copy = copy                                                        \
};                                                                      \
const CFWClass *CLASSNAME = &class


/**
 *  MACRO Min
 *      cache results of calculation in pocket scope 
 */
#define Min(a, b)                                                       \
({                                                                      \
    auto _a = a;                                                        \
    auto _b = b;                                                        \
    (_a < _b) ? _a : _b;                                                \
})

/**
 *  MACRO Max
 *      cache results of calculation in pocket scope 
 */
#define Max(a, b)                                                       \
({                                                                      \
    auto _a = a;                                                        \
    auto _b = b;                                                        \
    (_a > _b) ? _a : _b;                                                \
})

static inline struct CFWObject* asObject(void* obj) { return obj; }
