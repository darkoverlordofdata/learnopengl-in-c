#pragma once
/**
 * shims for corefw
 */
#include <corefw/corefw.h>
static inline struct CFWObject* asObject(void* obj) { return obj; }

#define var __auto_type
/**
 * enable multi-methods
 */
#define method __attribute__((overloadable)) 
/**
 * MACRO corefw
 *      generate typeinfo boilerplate for corefw
 */ 
#define corefw(CLASSNAME)                                               \
typedef struct CLASSNAME CLASSNAME;										\
static bool ctor(void *, va_list);										\
static void dtor(void *);												\
static bool equal(void *, void *);										\
static uint32_t hash(void *);											\
static void* copy(void *);												\
const static CFWClass class = {                                         \
	.name = #CLASSNAME,                                                 \
	.size = sizeof(CLASSNAME),                                   		\
	.ctor = ctor,                                                       \
	.dtor = dtor,                                                       \
	.equal = equal,                                                     \
	.hash = hash,                                                       \
	.copy = copy                                                        \
};                                                                      \
const CFWClass *CLASSNAME##Class = &class


/**
 *  MACRO Min
 *      cache results of calculation in pocket scope 
 */
#define Min(a, b)                                                       \
({                                                                      \
    __auto_type _a = a;                                                 \
    __auto_type _b = b;                                                 \
    (_a < _b) ? _a : _b;                                                \
})

/**
 *  MACRO Max
 *      cache results of calculation in pocket scope 
 */
#define Max(a, b)                                                       \
({                                                                      \
    __auto_type _a = a;                                                 \
    __auto_type _b = b;                                                 \
    (_a > _b) ? _a : _b;                                                \
})

