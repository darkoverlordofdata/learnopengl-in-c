/*******************************************************************
**
MIT License

Copyright (c) 2019 Dark Overlord of Data

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************/
#pragma once
/**
 * Artemis inspired ECS library
 * 
 */
typedef struct ECSComponent ECSComponent;
typedef struct ECSAspect ECSAspect;
typedef struct ECSEntityObserver ECSEntityObserver;
typedef struct ECSManager ECSManager;
typedef struct ECSComponentManager ECSComponentManager;
typedef struct ECSComponentType ECSComponentType;
typedef struct ECSComponentTypeFactory ECSComponentTypeFactory;
typedef struct ECSEntity ECSEntity;
typedef struct ECSEntityManager ECSEntityManager;
typedef struct ECSEntitySystem ECSEntitySystem;
typedef struct ECSWorld ECSWorld;

typedef struct ECSGroupManager;
typedef struct ECSPlayerManager;
typedef struct ECSTagManager;
typedef struct ECSTeamManager;

typedef struct ECSDelayedEntityProcessingSystem;
typedef struct ECSEntityProcessingSystem;
typedef struct ECSIntervalEntityProcessingSystem;
typedef struct ECSIntervalEntitySystem;
typedef struct ECSVoidEntitySystem;


extern bool Remove(Array* this, Object* e)
{
    for (auto i=0; i<this->length; i++)
    {
        auto e2 = this->data[i];
        if (e == e2) {
            Remove(this, i);
            return true;
        }
    }
    return false;
}

#include "blackboard/blackboard.h"
#include "blackboard/blackboard.h"
#include "blackboard/trigger.h"
#include "blackboard/triggermulticondition.h"
#include "blackboard/triggerstatetype.h"
#include "core/component.h"
#include "core/aspect.h"
#include "core/entityobserver.h"
#include "core/manager.h"
#include "core/componenttype.h"
#include "core/componenttypefactory.h"
#include "core/componentmanager.h"
#include "core/entity.h"
#include "core/entitymanager.h"
#include "core/entitysystem.h"
#include "core/world.h"
#include "managers/groupmanager.h"
#include "managers/playermanager.h"
#include "managers/tagmanager.h"
#include "managers/teammanager.h"
#include "systems/delayedentityprocessingsystem.h"
#include "systems/entityprocessingsystem.h"
#include "systems/intervalentitysystem.h"
#include "systems/voidentitysystem.h"
#include "systems/intervalentityprocessingsystem.h"

void __attribute__((constructor(102))) ECSLoader() 
{

    Class ObjectClass = GetClass("Object");
    RegisterClass(CreateComponent(ECSComponent));
    RegisterClass(CreateComponent(ECSEntity));

    Class ECSWorld = ClassLoadECSWorld(ObjectClass);
    RegisterClass(ECSWorld);

    Class ECSAspect = ClassLoadECSAspect(ObjectClass);
    RegisterClass(ECSAspect);

    Class ECSComponentType = ClassLoadECSComponentType(ObjectClass);
    RegisterClass(ECSComponentType);

    Class ECSComponentTypeFactory = ClassLoadECSComponentTypeFactory(ObjectClass);
    RegisterClass(ECSComponentTypeFactory);

    Class ECSEntityObserverClass = ClassLoadECSEntityObserver(ObjectClass);
    RegisterClass(ECSEntityObserverClass);

    Class ECSEntitySystemClass = ClassLoadECSEntitySystem(ECSEntityObserverClass);
    RegisterClass(ECSEntitySystemClass);

    Class ECSManagerClass = ClassLoadECSManager(ECSEntityObserverClass);
    RegisterClass(ECSManagerClass);
 
    Class ECSComponentManagerClass = ClassLoadECSComponentManager(ECSManagerClass);
    RegisterClass(ECSComponentManagerClass);
    
    Class ECSEntityManagerClass = ClassLoadECSEntityManager(ECSManagerClass);
    RegisterClass(ECSEntityManagerClass);

    Class ECSGroupManagerClass = ClassLoadECSGroupManager(ECSManagerClass);
    RegisterClass(ECSGroupManagerClass);
 
    Class ECSPlayerManagerClass = ClassLoadECSPlayerManager(ECSManagerClass);
    RegisterClass(ECSPlayerManagerClass);
 
    Class ECSTagManagerClass = ClassLoadECSTagManager(ECSManagerClass);
    RegisterClass(ECSTagManagerClass);
 
    Class ECSTeamManagerClass = ClassLoadECSTeamManager(ECSManagerClass);
    RegisterClass(ECSTeamManagerClass);
 
    Class ECSEntityProcessingSystemClass = ClassLoadECSEntityProcessingSystem(ECSEntitySystemClass);
    RegisterClass(ECSEntityProcessingSystemClass);

    Class ECSDelayedEntityProcessingSystemClass = ClassLoadECSDelayedEntityProcessingSystem(ECSEntitySystemClass);
    RegisterClass(ECSDelayedEntityProcessingSystemClass);

    Class ECSIntervalEntitySystemClass = ClassLoadECSIntervalEntitySystem(ECSEntitySystemClass);
    RegisterClass(ECSIntervalEntitySystemClass);

    Class ECSVoidEntitySystemClass = ClassLoadECSVoidEntitySystem(ECSEntitySystemClass);
    RegisterClass(ECSVoidEntitySystemClass);

    Class ECSIntervalEntityProcessingSystemClass = ClassLoadECSIntervalEntityProcessingSystem(ECSIntervalEntitySystemClass);
    RegisterClass(ECSIntervalEntityProcessingSystemClass);
}
