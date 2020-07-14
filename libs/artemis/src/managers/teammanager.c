#include "managers/teammanager.h"
#include "cfw.h"
#include "core/entity.h"
#include "core/world.h"
#include "ecs.h"
#include "managers/teammanager-private.h"

method void* New(ECSTeamManager* this)
{
    this->PlayersByTeam = cfw_new(cfw_map, NULL);
    this->TeamByPlayer = cfw_new(cfw_map, NULL);
    return this;
}

method void Initialize(ECSTeamManager* this) { this->overload->Initialize(this); }

method void SetWorld(ECSTeamManager* this, ECSWorld* world)
{
    SetWorld(this->overload, world);
}

method ECSWorld* GetWorld(ECSTeamManager* this)
{
    return GetWorld(this->overload);
}

method void Added(ECSTeamManager* this, ECSEntity* entity) { this->overload->Added(this, entity); }

method void Changed(ECSTeamManager* this, ECSEntity* entity) { this->overload->Changed(this, entity); }

method void Deleted(ECSTeamManager* this, ECSEntity* entity) { this->overload->Deleted(this, entity); }

method void Disabled(ECSTeamManager* this, ECSEntity* entity) { this->overload->Disabled(this, entity); }

method void Enabled(ECSTeamManager* this, ECSEntity* entity) { this->overload->Enabled(this, entity); }

method char* GetTeam(ECSTeamManager* this, char* player) {
    return Get(this->TeamByPlayer, player);
}

method void SetTeam(ECSTeamManager* this, char* player, char* team) {
    RemoveFromTeam(this, player);

    Put(this->TeamByPlayer, player, team);

    CFWArray* players = Get(this->PlayersByTeam, team);
    if(players == NULL) {
        players = cfw_new(cfw_array, NULL);
        Put(this->PlayersByTeam, team, players);
    }
    Add(players, player);
}

method CFWArray* GetPlayers(ECSTeamManager* this, char* team)  {
    return Get(this->PlayersByTeam, team);
}

method void RemoveFromTeam(ECSTeamManager* this, char* player) {
    char* team = Get(this->TeamByPlayer, player);
    if (Remove(this->TeamByPlayer, player)) {
        CFWArray* players = Get(this->PlayersByTeam, team);
        if (players != NULL) {
            Remove(players, (void*)player);
        }
    }
}
