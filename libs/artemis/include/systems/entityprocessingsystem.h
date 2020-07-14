#pragma once
#include "cfw.h"
#include "core/world.h"
#include "core/entity.h"
#include "core/aspect.h"

typedef struct ECSEntityProcessingSystem ECSEntityProcessingSystem;
extern const CFWClass* ECSEntityProcessingSystemClass;

typedef struct ECSEntity ECSEntity;
typedef struct ECSWorld ECSWorld;

extern method void* New(ECSEntityProcessingSystem* this, ECSAspect* aspect);

extern method void Begin(ECSEntityProcessingSystem* this);

extern method void Process(ECSEntityProcessingSystem* this);

extern method void End(ECSEntityProcessingSystem* this);

extern method void ProcessEntities(ECSEntityProcessingSystem* this, CFWArray* entities);

extern method bool CheckProcessing(ECSEntityProcessingSystem* this);

extern method void Initialize(ECSEntityProcessingSystem* this);

extern method void Inserted(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void Removed(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void Check(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void RemoveFromSystem(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void InsertToSystem(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void Added(ECSEntityProcessingSystem* this, ECSEntity* entity);

extern method void Changed(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void Deleted(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void Disabled(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void Enabled(ECSEntityProcessingSystem* this, ECSEntity* e);

extern method void SetWorld(ECSEntityProcessingSystem* this, ECSWorld* world);

extern method bool IsPassive(ECSEntityProcessingSystem* this);

extern method void SetPassive(ECSEntityProcessingSystem* this, bool passive);

extern method CFWArray* GetActive(ECSEntityProcessingSystem* this);

extern method void ProcessEach(ECSEntityProcessingSystem* this, ECSEntity* e);

