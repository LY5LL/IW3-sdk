#include "iw3_input.h"

#include "iw3_client.h"

namespace IW3 {

	extern kbutton_t* left_mouse, right_mouse;
	extern ClientCall IN_KeyUp_call, IN_KeyDown_call;
}

IW3::usercmd_t* GetUserCmd( int cmd_num )
{
	if ( cmd_num > IW3::CurrentCmdNumber() ) {
		return nullptr;
	}

	return reinterpret_cast<IW3::usercmd_t*>(&IW3::cl->Commands[cmd_num & 0x7F]);
}

int IW3::CurrentCmdNumber( void )
{
	return cl->CommandNumber;
}

void IW3::LeftMouseDown( void )
{
	__asm {
		mov esi, left_mouse
		mov eax, IN_KeyDown_call
		call eax
	}
}

void IW3::LeftMouseUp( void )
{
	__asm {
		mov esi, left_mouse
		mov eax, IN_KeyUp_call
		call eax
	}
}