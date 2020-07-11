#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSPlayerManager;
extern const CFWClass *ECSPlayerManager;


extern void* ECSPlayerManager_New(ECSPlayerManager* this);

extern method void Initialize(ECSPlayerManager* this);

extern method void SetWorld(ECSPlayerManager* this, ECSWorld* world);

extern method ECSWorld* GetWorld(ECSPlayerManager* this);

extern method void Added(ECSPlayerManager* this, ECSEntity* entity);

extern method void Changed(ECSPlayerManager* this, ECSEntity* entity);

extern method void Deleted(ECSPlayerManager* this, ECSEntity* entity); 

extern method void Disabled(ECSPlayerManager* this, ECSEntity* entity);

extern method void Enabled(ECSPlayerManager* this, ECSEntity* entity);

extern method void SetPlayer(ECSPlayerManager* this, ECSEntity* e, char* player);

extern method CFWArray* GetEntitiesOfPlayer(ECSPlayerManager* this, char* player);

extern method void RemoveFromPlayer(ECSPlayerManager* this, ECSEntity* e);

extern method char* GetPlayer(ECSPlayerManager* this, ECSEntity* e);

