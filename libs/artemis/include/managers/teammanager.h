#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSTeamManager;
extern const CFWClass *ECSTeamManager;

extern void* ECSTeamManager_New(ECSTeamManager* this);

extern void ECSTeamManager_Initialize(ECSTeamManager* this);

extern void ECSTeamManager_SetWorld(ECSTeamManager* this, ECSWorld* world);

extern ECSWorld* ECSTeamManager_GetWorld(ECSTeamManager* this);

extern void ECSTeamManager_Added(ECSTeamManager* this, ECSEntity* entity);

extern void ECSTeamManager_Changed(ECSTeamManager* this, ECSEntity* entity);

extern void ECSTeamManager_Deleted(ECSTeamManager* this, ECSEntity* entity);

extern void ECSTeamManager_Disabled(ECSTeamManager* this, ECSEntity* entity);

extern void ECSTeamManager_Enabled(ECSTeamManager* this, ECSEntity* entity);

extern char* ECSTeamManager_GetTeam(ECSTeamManager* this, char* player);

extern void ECSTeamManager_SetTeam(ECSTeamManager* this, char* player, char* team);

extern CFWArray* ECSTeamManager_GetPlayers(ECSTeamManager* this, char* team);

extern void ECSTeamManager_RemoveFromTeam(ECSTeamManager* this, char* player);
