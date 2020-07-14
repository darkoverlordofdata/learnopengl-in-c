#pragma once
#include "cfw.h"

typedef struct ECSEntitySystem ECSEntitySystem;
extern const CFWClass* ECSEntitySystemClass;

typedef struct ECSAspect ECSAspect;
typedef struct ECSEntity ECSEntity;

typedef void (*ECSEntityProc0)(void* this);
typedef void (*ECSEntityProc1)(void* this, CFWArray* entities);
typedef void (*ECSEntityProc2)(void* this, ECSEntity e);

struct ECSEntitySystemVtbl {
    void (*Begin)(void* this);
    void (*End)(void* this);
    void (*ProcessEntities)(void* this, CFWArray* entities);
    void (*Initialize)(void* this);
    void (*Inserted)(void* this, ECSEntity e);
    void (*Removed)(void* this, ECSEntity e);
};


typedef struct ECSSystemIndexManager ECSSystemIndexManager;
extern method int GetIndexFor(char* es);

extern method void* New(ECSEntitySystem* this, ECSAspect* aspect);

extern method void Begin(ECSEntitySystem* this);

extern method void Process(ECSEntitySystem* this);

extern method void End(ECSEntitySystem* this);

extern method void ProcessEntities(ECSEntitySystem* this, CFWArray* entities);

extern method bool CheckProcessing(ECSEntitySystem* this);

extern method void Initialize(ECSEntitySystem* this);

extern method void Inserted(ECSEntitySystem* this, ECSEntity* e);

extern method void Removed(ECSEntitySystem* this, ECSEntity* e);

extern method void Check(ECSEntitySystem* this, ECSEntity* e); 

extern method void RemoveFromSystem(ECSEntitySystem* this, ECSEntity* e);

extern method void InsertToSystem(ECSEntitySystem* this, ECSEntity* e);

extern method void Added(ECSEntitySystem* this, ECSEntity* entity);

extern method void Changed(ECSEntitySystem* this, ECSEntity* e);

extern method void Deleted(ECSEntitySystem* this, ECSEntity* e);

extern method void Disabled(ECSEntitySystem* this, ECSEntity* e);

extern method void Enabled(ECSEntitySystem* this, ECSEntity* e);

extern method void SetWorld(ECSEntitySystem* this, ECSWorld* world);

extern method bool IsPassive(ECSEntitySystem* this);

extern method void SetPassive(ECSEntitySystem* this, bool passive);

extern method CFWArray* GetActive(ECSEntitySystem* this);
