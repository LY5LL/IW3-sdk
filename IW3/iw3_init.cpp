#include "iw3_common.h"

#include "iw3_input.h"
#include "iw3_players.h"
#include "iw3_client.h"
#include "iw3_engine.h"

namespace IW3 {
	cg_t* cg;
	cgs_t* cgs;
	clientActive_t* cl;
	centity_t* centities;
	clientinfo_t* client_info;
	kbutton_t* left_mouse, * right_mouse;

	EngineCall CG_Trace_call;
	EngineCall RegisterTag_call, GetTagPos_call;

	ClientCall IN_KeyUp_call, IN_KeyDown_call;
}

qboolean IW3::Init( void )
{
	IW3::cg = (IW3::cg_t*)(0x746338);
	IW3::cgs = (IW3::cgs_t*)(0x742908);
	IW3::cl = (IW3::clientActive_t*)(0xc57930);
	IW3::centities = (IW3::centity_t*)(0x8472d8);
	IW3::client_info = (IW3::clientinfo_t*)(0x831270);

	IW3::left_mouse = (IW3::kbutton_t*)(0x8E9630);
	IW3::right_mouse = (IW3::kbutton_t*)(0x8E9720);

	IW3::IN_KeyUp_call = (IW3::ClientCall)(0x45ea80);
	IW3::IN_KeyDown_call = (IW3::ClientCall)(0x45e9e0);

	IW3::CG_Trace_call = (IW3::EngineCall)(0x40cdd0);
	IW3::RegisterTag_call = (IW3::EngineCall)(0x512da0);
	IW3::GetTagPos_call = (IW3::EngineCall)(0x403180);

	return true;
}