#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSIdentifierPool;
extern const CFWClass *ECSIdentifierPool;


extern void* ECSIdentifierPool_New();

extern void ECSIdentifierPool_CheckIn(ECSIdentifierPool* this, int id);

extern int ECSIdentifierPool_CheckOut(ECSIdentifierPool* this);

struct ECSEntityManager;
extern const CFWClass *ECSEntityManager;

extern void* ECSEntityManager_New();

extern void ECSEntityManager_SetWorld(ECSEntityManager* this, ECSWorld* world);

extern ECSWorld* ECSEntityManager_GetWorld(ECSEntityManager* this);

extern ECSEntity* ECSEntityManager_CreateEntityInstance(ECSEntityManager* this, char* name);

extern void ECSEntityManager_Added(ECSEntityManager* this, ECSEntity* entity);

extern void ECSEntityManager_Changed(ECSEntityManager* this, ECSEntity* entity);

extern void ECSEntityManager_Enabled(ECSEntityManager* this, ECSEntity* entity);

extern void ECSEntityManager_Disabled(ECSEntityManager* this, ECSEntity* entity);

extern void ECSEntityManager_Deleted(ECSEntityManager* this, ECSEntity* entity);

extern bool ECSEntityManager_IsActive(ECSEntityManager* this, int entityId);

extern bool ECSEntityManager_IsEnabled(ECSEntityManager* this, int entityId);

extern ECSEntity* ECSEntityManager_GetEntity(ECSEntityManager* this, int entityId);

extern int ECSEntityManager_GetActiveEntityCount(ECSEntityManager* this);

extern int ECSEntityManager_GetTotalCreated(ECSEntityManager* this);

extern int ECSEntityManager_GetTotalAdded(ECSEntityManager* this);

extern int ECSEntityManager_GetTotalDeleted(ECSEntityManager* this);


