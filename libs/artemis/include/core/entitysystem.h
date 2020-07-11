#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSEntitySystem;
extern const CFWClass *ECSEntitySystem;

struct ECSSystemIndexManager;
extern method int GetIndexFor(char* es);

extern void* ECSEntitySystem_New(ECSEntitySystem* this, ECSAspect* aspect);

extern method void Begin(ECSEntitySystem* this);

extern method void Process(ECSEntitySystem* this);

extern method void End(ECSEntitySystem* this);

extern method void ProcessEntities(ECSEntitySystem* this, Array* entities);

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
