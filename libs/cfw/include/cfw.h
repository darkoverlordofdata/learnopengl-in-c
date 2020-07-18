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
#define corefw(CLASSNAME)               \
    typedef struct CLASSNAME CLASSNAME; \
    static bool ctor(void*, va_list);   \
    static void dtor(void*);            \
    static bool equal(void*, void*);    \
    static uint32_t hash(void*);        \
    static void* copy(void*);           \
    const static CFWClass class = {     \
        .name = #CLASSNAME,             \
        .size = sizeof(CLASSNAME),      \
        .ctor = ctor,                   \
        .dtor = dtor,                   \
        .equal = equal,                 \
        .hash = hash,                   \
        .copy = copy                    \
    };                                  \
    const CFWClass* CLASSNAME##Class = &class

/**
 *  MACRO Min
 *      cache results of calculation in pocket scope 
 */
#define Min(a, b)            \
    ({                       \
        __auto_type _a = a;  \
        __auto_type _b = b;  \
        (_a < _b) ? _a : _b; \
    })

/**
 *  MACRO Max
 *      cache results of calculation in pocket scope 
 */
#define Max(a, b)            \
    ({                       \
        __auto_type _a = a;  \
        __auto_type _b = b;  \
        (_a > _b) ? _a : _b; \
    })

#define new(T, args...) New((T*)cfw_new((CFWClass*)T##Class), ## args)
#define create(T, args...) New((T*)cfw_create((CFWClass*)T##Class), ## args)

// #define override(super, class, method) (void(*)(super* this))((void(*)(class* this))method)

#define abstract(class, method) (void(*)(void* this))((void(*)(class* this))method)

// typedef CFWArray Array;
// typedef CFWBool Bool;
// typedef CFWDouble Double;
// typedef CFWFile File;
// typedef CFWInt Int;
// typedef CFWMap Map;
// typedef CFWRefPool RefPool;
// typedef CFWStream Stream;
// typedef CFWString String;

// #define ArrayClass cfw_array
// #define BoolClass cfw_bool
// #define DoubleClass cfw_double
// #define FileClass cfw_file
// #define CFWIntClass cfw_int
// #define MapClass cfw_map
// #define RefPoolClass cfw_refpool
// #define StreamClass cfw_stream
// #define StringClass cfw_string

#include "cfwfs.h"
#include "bitvector.h"
#include "random.h"
#include "uuid.h"
extern method void* Get(CFWArray* this, int i);
extern method void* Get(CFWMap* this, char* key);
extern method void Add(CFWArray* this, void* item);
extern method bool Remove(CFWArray* this, int i);
extern method bool Remove(CFWMap* this, char* key);
extern method void Put(CFWMap* this, char* key, void* object);
extern method void Put(CFWArray* this, int index, void* object);
extern method void ForEach(CFWMap* this, void(^func)(void* key, void* item));
extern method void ForEach(CFWMap* this, void(*func)(void* key, void* item));
extern method int Length(CFWArray* this);
extern method int Length(CFWString* this);
extern method char* cstr(CFWString* this);
extern method void* New(CFWString* this);
extern method void* New(CFWString* this, char* value);

