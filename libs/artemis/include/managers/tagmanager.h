#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSTagManager;
extern const CFWClass *ECSTagManager;

extern void* ECSTagManager_New(ECSTagManager* this);

extern void ECSTagManager_Initialize(ECSTagManager* this);

extern void ECSTagManager_SetWorld(ECSTagManager* this, ECSWorld* world);

extern ECSWorld* ECSTagManager_GetWorld(ECSTagManager* this);

extern void ECSTagManager_Added(ECSTagManager* this, ECSEntity* entity);

extern void ECSTagManager_Changed(ECSTagManager* this, ECSEntity* entity);

extern void ECSTagManager_Deleted(ECSTagManager* this, ECSEntity* entity); 

extern void ECSTagManager_Disabled(ECSTagManager* this, ECSEntity* entity);

extern void ECSTagManager_Enabled(ECSTagManager* this, ECSEntity* entity);

extern void ECSTagManager_Register(ECSTagManager* this, char* tag, ECSEntity* e);

extern void ECSTagManager_Unregister(ECSTagManager* this, char* tag);

extern bool ECSTagManager_IsRegistered(ECSTagManager* this, char* tag);

extern ECSEntity* ECSTagManager_GetEntity(ECSTagManager* this, char* tag);

extern CFWArray* ECSTagManager_GetRegisteredTags(ECSTagManager* this);

