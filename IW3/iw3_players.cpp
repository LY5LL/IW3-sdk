#include "iw3_players.h"

#include "iw3_engine.h"
#include "iw3_client.h"
#include "iw3_qlib.h"

IW3::centity_t* IW3::GetCentity( int client_num )
{
	if ( client_num > cgs->MaxClients ) {
		return nullptr;
	}

	return &centities[client_num];
}

IW3::clientState_s* IW3::GetClientState( int client_num )
{
	if ( client_num > IW3::cgs->MaxClients ) {
		return nullptr;
	}

	return &IW3::cg->CurrentSnap->Clients[client_num];
}

// Not 100% sure this even works lol
IW3::entityState_t* IW3::GetClientEntityState( int client_num )
{ 
	if ( client_num > IW3::cgs->MaxClients ) {
		return nullptr;
	} 
	return &IW3::GetCentity( client_num )->NextState;
}

IW3::clientinfo_t* IW3::GetClientInfo( int client_num )
{
	if ( client_num > IW3::cgs->MaxClients ) {
		return nullptr;
	}

	return &IW3::client_info[client_num];
}

qboolean IW3::IsEnemy( int client_num )
{
	struct centity_t* local, *target;

	local = IW3::GetCentity( cg->ClientNum );
	target = IW3::GetCentity( client_num );

	if ( Q_stricmp( cgs->GameMode, "dm" ) == 0 ) {
		return true;
	}

	else {
		return (cg->CurrentSnap->Clients[cg->ClientNum].Team != cg->CurrentSnap->Clients[client_num].Team);
	}
}

qboolean IW3::IsDead( int client_num )
{
	return (IW3::GetCentity( client_num )->CurrentState.EntityFlags & IW3::EF_DEAD);
}

qboolean IW3::IsValid( int client_num )
{
	IW3::clientState_s* cs;
	IW3::clientinfo_t* ci;

	ci = IW3::GetClientInfo( client_num );

	if ( Q_stricmp( IW3::cgs->GameMode, "dm" ) != 0 ) {

		cs = IW3::GetClientState( client_num );

		if ( cs->Team != IW3::TEAM_AXIS && cs->Team != IW3::TEAM_ALLIES ) {
			return false;
		}
	}

	if ( !ci->IsValid || !ci->NextValid ) {
		return false;
	}

	return true;
}