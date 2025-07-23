#include "iw3_engine.h"

#include "iw3_qlib.h"

void CG_Trace( struct trace_t* result, vec3_t start, vec3_t mins, vec3_t maxs, vec3_t end, int skip_num, int mask )
{
	extern EngineCall CG_Trace_call;

	__asm {
		mov esi, 0x0078C49C
		push mask
		push skip_num
		push end
		push maxs
		push mins
		push start
		push result
		call CG_Trace_call

		add esp, 0x1c
	}
}

tag_t IW3_RegisterTag( const char* tag )
{
	int tag_len = Q_strlen( tag ) + 1;
	extern EngineCall RegisterTag_call;

	__asm {
		push tag_len
		push 1
		push tag
		call RegisterTag_call 

		add esp, 0xC
	}
}

qboolean IW3_GetTagPos( tag_t tag, int client_num, vec_t* out )
{
	extern EngineCall GetTagPos_call;
	struct centity_t* centity;
	int tag32;

	centity = IW3_GetCentity( client_num );
	tag32 = tag;

	__asm {
		push out
		mov esi, tag32
		mov ecx, centity
		call GetTagPos_call

		add esp, 0x4
	}
}

qboolean IW3_IsVisible( vec3_t vec )
{
	struct trace_t t;
	vec3_t start, end, null_vec;

	VectorClear( null_vec );
	VectorCopy( cg->Refdef.ViewOffset, start );
	VectorCopy( vec, end );

	CG_Trace( &t, start, null_vec, null_vec, end, cg->ClientNum, 0x803003 );

	return (!(t.Fraction < 1.0f));
}