#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSIdentifierPool;
extern const CFWClass *ECSIdentifierPool;


extern void* ECSIdentifierPool_New();

extern method void CheckIn(ECSIdentifierPool* this, int id);

extern method int CheckOut(ECSIdentifierPool* this);

struct ECSEntityManager;
extern const CFWClass *ECSEntityManager;

extern void* ECSEntityManager_New();

extern method void SetWorld(ECSEntityManager* this, ECSWorld* world);

extern method ECSWorld* GetWorld(ECSEntityManager* this);

extern method ECSEntity* CreateEntityInstance(ECSEntityManager* this, char* name);

extern method void Added(ECSEntityManager* this, ECSEntity* entity);

extern method void Changed(ECSEntityManager* this, ECSEntity* entity);

extern method void Enabled(ECSEntityManager* this, ECSEntity* entity);

extern method void Disabled(ECSEntityManager* this, ECSEntity* entity);

extern method void Deleted(ECSEntityManager* this, ECSEntity* entity);

extern method bool IsActive(ECSEntityManager* this, int entityId);

extern method bool IsEnabled(ECSEntityManager* this, int entityId);

extern method ECSEntity* GetEntity(ECSEntityManager* this, int entityId);

extern method int GetActiveEntityCount(ECSEntityManager* this);

extern method int GetTotalCreated(ECSEntityManager* this);

extern method int GetTotalAdded(ECSEntityManager* this);

extern method int GetTotalDeleted(ECSEntityManager* this);


