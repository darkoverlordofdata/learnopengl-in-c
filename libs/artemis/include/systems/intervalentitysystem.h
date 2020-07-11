#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSIntervalEntitySystem;
extern const CFWClass *ECSIntervalEntitySystem;

extern void* ECSIntervalEntitySystem_New(ECSIntervalEntitySystem* this, ECSAspect* aspect, float interval);

extern method void Begin(ECSIntervalEntitySystem* this);virtual(ECSIntervalEntitySystem);

extern method void Process(ECSIntervalEntitySystem* this);

extern method void End(ECSIntervalEntitySystem* this);virtual(ECSIntervalEntitySystem);

extern method void ProcessEntities(ECSIntervalEntitySystem* this, Array* entities);

extern method bool CheckProcessing(ECSIntervalEntitySystem* this);

extern method void Initialize(ECSIntervalEntitySystem* this);

extern method void Inserted(ECSIntervalEntitySystem* this, ECSEntity* e);

extern method void Removed(ECSIntervalEntitySystem* this, ECSEntity* e);

extern method void Check(ECSIntervalEntitySystem* this, ECSEntity* e);

extern method void RemoveFromSystem(ECSIntervalEntitySystem* this, ECSEntity* e); 

extern method void InsertToSystem(ECSIntervalEntitySystem* this, ECSEntity* e); 

extern method void Added(ECSIntervalEntitySystem* this, ECSEntity* entity);

extern method void Changed(ECSIntervalEntitySystem* this, ECSEntity* e);

extern method void Deleted(ECSIntervalEntitySystem* this, ECSEntity* e);

extern method void Disabled(ECSIntervalEntitySystem* this, ECSEntity* e);

extern method void Enabled(ECSIntervalEntitySystem* this, ECSEntity* e);

extern method void SetWorld(ECSIntervalEntitySystem* this, ECSWorld* world);

extern method bool IsPassive(ECSIntervalEntitySystem* this);

extern method void SetPassive(ECSIntervalEntitySystem* this, bool passive);

extern method CFWArray* GetActive(ECSIntervalEntitySystem* this);
