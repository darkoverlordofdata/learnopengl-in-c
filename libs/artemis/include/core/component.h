#pragma once
#include "cfw.h"

typedef struct ECSComponent ECSComponent;
extern const CFWClass* ECSComponentClass;

extern method void* New(ECSComponent* this);
