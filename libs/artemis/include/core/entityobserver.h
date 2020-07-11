#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSEntityObserver;
extern const CFWClass *ECSEntityObserver;

extern void* ECSEntityObserver_New(ECSEntityObserver* this);

extern method void Added(ECSEntityObserver* this, ECSEntity* entity);

extern method void Changed(ECSEntityObserver* this, ECSEntity* entity);

extern method void Deleted(ECSEntityObserver* this, ECSEntity* entity);

extern method void Disabled(ECSEntityObserver* this, ECSEntity* entity);

extern method void Enabled(ECSEntityObserver* this, ECSEntity* entity);

