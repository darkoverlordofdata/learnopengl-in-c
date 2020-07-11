#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSVoidEntitySystem;
extern const CFWClass *ECSVoidEntitySystem;

extern void* ECSVoidEntitySystem_New(ECSVoidEntitySystem* this);

extern method void Begin(ECSVoidEntitySystem* this);

extern method void Process(ECSVoidEntitySystem* this);

extern method void End(ECSVoidEntitySystem* this);

extern method void ProcessEntities(ECSVoidEntitySystem* this, Array* entities);

extern method bool CheckProcessing(ECSVoidEntitySystem* this);

extern method void Initialize(ECSVoidEntitySystem* this);

extern method void Inserted(ECSVoidEntitySystem* this, ECSEntity* e);

extern method void Removed(ECSVoidEntitySystem* this, ECSEntity* e);

extern method void Check(ECSVoidEntitySystem* this, ECSEntity* e);

extern method void RemoveFromSystem(ECSVoidEntitySystem* this, ECSEntity* e); 

extern method void InsertToSystem(ECSVoidEntitySystem* this, ECSEntity* e); 

extern method void Added(ECSVoidEntitySystem* this, ECSEntity* entity);

extern method void Changed(ECSVoidEntitySystem* this, ECSEntity* e);

extern method void Deleted(ECSVoidEntitySystem* this, ECSEntity* e);

extern method void Disabled(ECSVoidEntitySystem* this, ECSEntity* e);

extern method void Enabled(ECSVoidEntitySystem* this, ECSEntity* e);

extern method void SetWorld(ECSVoidEntitySystem* this, ECSWorld* world);

extern method bool IsPassive(ECSVoidEntitySystem* this);

extern method void SetPassive(ECSVoidEntitySystem* this, bool passive);

extern method CFWArray* GetActive(ECSVoidEntitySystem* this);

extern method void ProcessSystem(ECSVoidEntitySystem* this);

