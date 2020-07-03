#pragma once
#include <assert.h>
#include <corefw/class.h>

struct ECSComponent;
extern const CFWClass *ECSComponent;

extern void* ECSComponent_New(ECSComponent* this)
