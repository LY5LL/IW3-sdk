#include "iw3_players.h"

#include "iw3_engine.h"
#include "iw3_client.h"
#include "iw3_qlib.h"

struct centity_t* IW3_GetCentity( int client_num )
{
	if ( client_num > cgs->MaxClients ) {
		return NULL;
	}

	return &centities[client_num];
}

struct clientState_s* IW3_GetClientState( int client_num )
{
	if ( client_num > cgs->MaxClients ) {
		return NULL;
	}

	return &cg->CurrentSnap->Clients[client_num];
}

// Not 100% sure this even works lol
struct entityState_t* IW3_GetClientEntityState( int client_num )
{ 
	if ( client_num > cgs->MaxClients ) {
		return NULL;
	} 
	return &IW3_GetCentity( client_num )->NextState;
}

struct clientinfo_t* IW3_GetClientInfo( int client_num )
{
	if ( client_num > cgs->MaxClients ) {
		return NULL;
	}

	return &client_info[client_num];
}

qboolean IW3_IsEnemy( int client_num )
{
	struct centity_t* local, *target;

	local = IW3_GetCentity( cg->ClientNum );
	target = IW3_GetCentity( client_num );

	if ( Q_stricmp( cgs->GameMode, "dm" ) == 0 ) {
		return qtrue;
	}

	else {
		return (cg->CurrentSnap->Clients[cg->ClientNum].Team != cg->CurrentSnap->Clients[client_num].Team);
	}
}

qboolean IW3_IsDead( int client_num )
{
	return (IW3_GetCentity( client_num )->CurrentState.EntityFlags & EF_DEAD);
}

qboolean IW3_IsValid( int client_num )
{
	struct clientState_s* cs;
	struct clientinfo_t* ci;

	ci = IW3_GetClientInfo( client_num );

	if ( Q_stricmp( cgs->GameMode, "dm" ) != 0 ) {

		cs = IW3_GetClientState( client_num );

		if ( cs->Team != TEAM_AXIS && cs->Team != TEAM_ALLIES ) {
			return qfalse;
		}
	}

	if ( !ci->IsValid || !ci->NextValid ) {
		return qfalse;
	}

	return qtrue;
}