#pragma once
#include "cfw.h"
#include "ecs.h"
#include "world.h"

/**
 * The primary instance for the framework. It contains all the managers.
 * 
 * You must use this to create, delete and retrieve entities.
 * 
 * It is also important to set the delta each game loop iteration, and initialize before game loop.
 * 
 * @author Arni Arent
 * 
 */
struct ECSWorld
{
    CFWObject obj;
    CFWObject* override;
    ECSEntityManager* Em;
    ECSComponentManager* Cm;
    float Delta;
    CFWArray* Added;
    CFWArray* Changed;
    CFWArray* Deleted;
    CFWArray* Enable;
    CFWArray* Disable;
    CFWMap* Managers;
    CFWArray* ManagersBag;
    CFWMap* Systems;
    CFWArray* SystemsBag;
    // Map* ECSEntityTemplates;
};
