#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSTagManager;
extern const CFWClass *ECSTagManager;

extern void* New(ECSTagManager* this);

extern method void Initialize(ECSTagManager* this);

extern method void SetWorld(ECSTagManager* this, ECSWorld* world);

extern method ECSWorld* GetWorld(ECSTagManager* this);

extern method void Added(ECSTagManager* this, ECSEntity* entity);

extern method void Changed(ECSTagManager* this, ECSEntity* entity);

extern method void Deleted(ECSTagManager* this, ECSEntity* entity); 

extern method void Disabled(ECSTagManager* this, ECSEntity* entity);

extern method void Enabled(ECSTagManager* this, ECSEntity* entity);

extern method void Register(ECSTagManager* this, char* tag, ECSEntity* e);

extern method void Unregister(ECSTagManager* this, char* tag);

extern method bool IsRegistered(ECSTagManager* this, char* tag);

extern method ECSEntity* GetEntity(ECSTagManager* this, char* tag);

extern method CFWArray* GetRegisteredTags(ECSTagManager* this);

