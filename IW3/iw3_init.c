#include "iw3_common.h"

#include "iw3_input.h"
#include "iw3_players.h"
#include "iw3_client.h"
#include "iw3_engine.h"

struct cg_t* cg;
struct cgs_t* cgs;
struct clientActive_t* cl;
struct centity_t* centities;
struct clientinfo_t* client_info;
struct kbutton_t* left_mouse, *right_mouse;

EngineCall CG_Trace_call;
EngineCall RegisterTag_call, GetTagPos_call;

ClientCall IN_KeyUp_call, IN_KeyDown_call;

qboolean IW3_Init( void )
{
	cg = (struct cg_t*)(0x746338);
	cgs = (struct cgs_t*)(0x742908);
	cl = (struct clientActive_t*)(0xc57930);
	centities = (struct centity_t*)(0x8472d8);
	client_info = (struct clientinfo_t*)(0x831270);

	left_mouse = (struct kbutton_t*)(0x8E9630);
	right_mouse = (struct kbutton_t*)(0x8E9720);

	IN_KeyUp_call = (ClientCall)(0x45ea80);
	IN_KeyDown_call = (ClientCall)(0x45e9e0);

	CG_Trace_call = (EngineCall)(0x40cdd0);
	RegisterTag_call = (EngineCall)(0x512da0);
	GetTagPos_call = (EngineCall)(0x403180);

	return qtrue;
}