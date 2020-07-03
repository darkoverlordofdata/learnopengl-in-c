#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSPlayerManager;
extern const CFWClass *ECSPlayerManager;


extern void* ECSPlayerManager_New(ECSPlayerManager* this);

extern void ECSPlayerManager_Initialize(ECSPlayerManager* this);

extern void ECSPlayerManager_SetWorld(ECSPlayerManager* this, ECSWorld* world);

extern ECSWorld* ECSPlayerManager_GetWorld(ECSPlayerManager* this);

extern void ECSPlayerManager_Added(ECSPlayerManager* this, ECSEntity* entity);

extern void ECSPlayerManager_Changed(ECSPlayerManager* this, ECSEntity* entity);

extern void ECSPlayerManager_Deleted(ECSPlayerManager* this, ECSEntity* entity); 

extern void ECSPlayerManager_Disabled(ECSPlayerManager* this, ECSEntity* entity);

extern void ECSPlayerManager_Enabled(ECSPlayerManager* this, ECSEntity* entity);

extern void ECSPlayerManager_SetPlayer(ECSPlayerManager* this, ECSEntity* e, char* player);

extern CFWArray* ECSPlayerManager_GetEntitiesOfPlayer(ECSPlayerManager* this, char* player);

extern void ECSPlayerManager_RemoveFromPlayer(ECSPlayerManager* this, ECSEntity* e);

extern char* ECSPlayerManager_GetPlayer(ECSPlayerManager* this, ECSEntity* e);

