#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSEntityObserver;
extern const CFWClass *ECSEntityObserver;

extern void* ECSEntityObserver_New(ECSEntityObserver* this);

extern void ECSEntityObserver_Added(ECSEntityObserver* this, ECSEntity* entity);

extern void ECSEntityObserver_Changed(ECSEntityObserver* this, ECSEntity* entity);

extern void ECSEntityObserver_Deleted(ECSEntityObserver* this, ECSEntity* entity);

extern void ECSEntityObserver_Disabled(ECSEntityObserver* this, ECSEntity* entity);

extern void ECSEntityObserver_Enabled(ECSEntityObserver* this, ECSEntity* entity);

