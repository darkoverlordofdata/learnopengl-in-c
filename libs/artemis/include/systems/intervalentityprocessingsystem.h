#pragma once
#include "cfw.h"
#include "core/world.h"
#include "core/entity.h"
#include "core/aspect.h"
#include "systems/entityprocessingsystem.h"

typedef struct ECSIntervalEntityProcessingSystem ECSIntervalEntityProcessingSystem;
extern const CFWClass* ECSIntervalEntityProcessingSystemClass;

extern method void* New(ECSIntervalEntityProcessingSystem* this, ECSAspect* aspect, float interval);

extern method void Begin(ECSIntervalEntityProcessingSystem* this);

extern method void Process(ECSIntervalEntityProcessingSystem* this);

extern method void End(ECSIntervalEntityProcessingSystem* this);

extern method void ProcessEntities(ECSIntervalEntityProcessingSystem* this, CFWArray* entities);

extern method bool CheckProcessing(ECSIntervalEntityProcessingSystem* this);

extern method void Initialize(ECSIntervalEntityProcessingSystem* this);

extern method void Inserted(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern method void Removed(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern method void Check(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern method void RemoveFromSystem(ECSIntervalEntityProcessingSystem* this, ECSEntity* e); 

extern method void InsertToSystem(ECSIntervalEntityProcessingSystem* this, ECSEntity* e); 

extern method void Added(ECSIntervalEntityProcessingSystem* this, ECSEntity* entity);

extern method void Changed(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern method void Deleted(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern method void Disabled(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern method void Enabled(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);

extern method void SetWorld(ECSIntervalEntityProcessingSystem* this, ECSWorld* world);

extern method bool IsPassive(ECSIntervalEntityProcessingSystem* this);

extern method void SetPassive(ECSIntervalEntityProcessingSystem* this, bool passive);

extern method CFWArray* GetActive(ECSIntervalEntityProcessingSystem* this);

extern method void ProcessEach(ECSIntervalEntityProcessingSystem* this, ECSEntity* e);
