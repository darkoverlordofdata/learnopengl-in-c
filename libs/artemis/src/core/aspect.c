/**
 * An Aspects is used by systems as a matcher against entities, to check if a system is
 * interested in an entity. Aspects define what sort of component types an entity must
 * possess, or not possess.
 *
 * This creates an aspect where an entity must possess A and B and C:
 * Aspect.getAspectForAll(A.class, B.class, C.class)
 *
 * This creates an aspect where an entity must possess A and B and C, but must not possess U or V.
 * Aspect.getAspectForAll(A.class, B.class, C.class).exclude(U.class, V.class)
 *
 * This creates an aspect where an entity must possess A and B and C, but must not possess U or V, but must possess one of X or Y or Z.
 * Aspect.getAspectForAll(A.class, B.class, C.class).exclude(U.class, V.class).one(X.class, Y.class, Z.class)
 *
 * You can create and compose aspects in many ways:
 * Aspect.getEmpty().one(X.class, Y.class, Z.class).all(A.class, B.class, C.class).exclude(U.class, V.class)
 * is the same as:
 * Aspect.getAspectForAll(A.class, B.class, C.class).exclude(U.class, V.class).one(X.class, Y.class, Z.class)
 *
 * @author Arni Arent
 *
 */
#include "core/aspect.h"
#include "object.h"
#include "ecs.h"

struct ECSAspect {
	CFWObject obj;
    BitSet* AllSet;
    BitSet* ExclusionSet;
    BitSet* OneSet;
    struct ECSWorld* World;

};

void SetWorld(ECSAspect* self, ECSWorld* world);
BitSet* GetAllSet(ECSAspect* self);
BitSet* GetExclusionSet(ECSAspect* self);
BitSet* GetOneSet(ECSAspect* self);
ECSAspect* All(ECSAspect* self, int count, va_list _args);
ECSAspect* Exclude(ECSAspect* self, int count, va_list _args);
ECSAspect* One(ECSAspect* self, int count, va_list _args);


class (ECSAspect)
{
    ECSComponentTypeFactory* TypeFactory;
};


delegate (ECSAspect, SetWorld, void, (ECSAspect* self, ECSWorld* world));
delegate (ECSAspect, GetAllSet, BitSet*, (ECSAspect* self));
delegate (ECSAspect, GetExclusionSet, BitSet*, (ECSAspect* self));
delegate (ECSAspect, GetOneSet, BitSet*, (ECSAspect* self));
delegate (ECSAspect, All, ECSAspect*, (ECSAspect* self, int count, va_list _args));
delegate (ECSAspect, Exclude, ECSAspect*, (ECSAspect* self, int count, va_list _args));
delegate (ECSAspect, One, ECSAspect*, (ECSAspect* self, int count, va_list _args));


/**
 * ECSAspect Vtable
 */
vtable (ECSAspect) 
{
    const ObjectToString        ToString;
    const ObjectEquals          Equals;
    const ObjectGetHashCode     GetHashCode;
    const ObjectDispose         Dispose;
    const ECSAspectSetWorld     SetWorld;
    const ECSAspectGetAllSet    GetAllSet;
    const ECSAspectGetExclusionSet       GetExclusionSet;
    const ECSAspectGetOneSet    GetOneSet;
    const ECSAspectAll          All;
    const ECSAspectExclude      Exclude;
    const ECSAspectOne          One;

};

static inline vptr(ECSAspect);
/**
 * Create the class loader
 */
static inline Class ClassLoadECSAspect(Class base) 
{
    Class cls = createClass(base, ECSAspect);
    addMethod(cls, Object, ToString);
    addMethod(cls, Object, Equals);
    addMethod(cls, Object, GetHashCode);
    addMethod(cls, Object, Dispose);
    addMethod(cls, ECSAspect, SetWorld);
    addMethod(cls, ECSAspect, GetAllSet);
    addMethod(cls, ECSAspect, GetExclusionSet);
    addMethod(cls, ECSAspect, GetOneSet);
    addMethod(cls, ECSAspect, All);
    addMethod(cls, ECSAspect, Exclude);
    addMethod(cls, ECSAspect, One);
    return cls; 
}



void SetTypeFactory(ECSComponentTypeFactory* typeFactory)
{
    $ECSAspect.TypeFactory = typeFactory;
}

ECSAspect* New(ECSAspect* self)
{
    self->base = extends(Object);
    self->isa = isa(ECSAspect);
    self->AllSet = new(BitSet);
    self->ExclusionSet = new(BitSet);
    self->OneSet = new(BitSet);
    return self;
}

void SetWorld(ECSAspect* self, ECSWorld* world)
{
    self->World = world;
}

BitSet* GetAllSet(ECSAspect* self)
{
    return self->AllSet;
}

BitSet* GetExclusionSet(ECSAspect* self)
{
    return self->ExclusionSet;
}

BitSet* GetOneSet(ECSAspect* self)
{
    return self->OneSet;
}


/**
 * Returns an aspect where an entity must possess all of the specified component types.
 * @param {Type} type a required component type
 * @param {Array<Type>} types a required component type
 * @return {artemis.Aspect} an aspect that can be matched against entities
 */
ECSAspect* All(ECSAspect* self, int count, va_list _args)
{
    va_list args;
    va_copy(args, _args);
    for (int i = 0; i < count; ++i) 
    {
        ECSComponent* t = va_arg(args, ECSComponent*);
        auto index = GetIndexFor($ECSAspect.TypeFactory, t);
        Set(self->AllSet, index, true);
    }
    va_end(args);
    return self;
}

/**
 * Excludes all of the specified component types from the aspect. A system will not be
 * interested in an entity that possesses one of the specified exclusion component types.
 *
 * @param {Type} type component type to exclude
 * @param {Array<Type>} types component type to exclude
 * @return {artemis.Aspect} an aspect that can be matched against entities
 */
ECSAspect* Exclude(ECSAspect* self, int count, va_list _args)
{
    va_list args;
    va_copy(args, _args);
    for (int i = 0; i < count; ++i) 
    {
        ECSComponent* t = va_arg(args, ECSComponent*);
        auto index = GetIndexFor($ECSAspect.TypeFactory, t);
        Set(self->ExclusionSet, index, true);
    }
    va_end(args);
    return self;
}

/**
 * Returns an aspect where an entity must possess one of the specified component types.
 * @param {Type} type one of the types the entity must possess
 * @param {Array<Type>} types one of the types the entity must possess
 * @return {artemis.Aspect} an aspect that can be matched against entities
 */
ECSAspect* One(ECSAspect* self, int count, va_list _args)
{
    va_list args;
    va_copy(args, _args);
    for (int i = 0; i < count; ++i) 
    {
        ECSComponent* t = va_arg(args, Object*);
        auto index = GetIndexFor($ECSAspect.TypeFactory, t);
        Set(self->OneSet, index, true);
    }
    va_end(args);
    return self;
}


/**
 * Creates an aspect where an entity must possess all of the specified component types.
 *
 * @param {Type} type a required component type
 * @param {Array<Type>} types a required component type
 * @return {artemis.Aspect} an aspect that can be matched against entities
 */
#define GetAspectForAll(...) _GetAspectForAll(PP_NARG(__VA_ARGS__), __VA_ARGS__)
ECSAspect* _GetAspectForAll(int count, ...) 
{
    auto aspect = new(ECSAspect);

    va_list args;
    va_start(args, count);
    All(aspect, count, args);
    va_end(args);

    return aspect;
}

/**
 * Creates an aspect where an entity must possess one of the specified component types.
 *
 * @param {Type} type one of the types the entity must possess
 * @param {Array<Type>} types one of the types the entity must possess
 * @return {artemis.Aspect} an aspect that can be matched against entities
 */
#define GetAspectForOne(...) _GetAspectForOne(PP_NARG(__VA_ARGS__), __VA_ARGS__)
ECSAspect* _GetAspectForOne(int count, ...) 
{
    auto aspect = new(ECSAspect);

    va_list args;
    va_start(args, count);
    One(aspect, count, args);
    va_end(args);

    return aspect;
}

/**
 * Creates and returns an empty aspect. This can be used if you want a system that processes no entities, but
 * still gets invoked. Typical usages is when you need to create special purpose systems for debug rendering,
 * like rendering FPS, how many entities are active in the world, etc.
 *
 * You can also use the all, one and exclude methods on this aspect, so if you wanted to create a system that
 * processes only entities possessing just one of the components A or B or C, then you can do:
 * Aspect.getEmpty().one(A,B,C);
 *
 * @return {artemis.Aspect} an empty Aspect that will reject all entities.
 */
ECSAspect* GetAspectForNone(void)
{
    return new(ECSAspect);
} 
