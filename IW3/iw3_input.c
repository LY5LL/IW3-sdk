#include "iw3_input.h"

#include "iw3_client.h"

extern struct kbutton_t* left_mouse, right_mouse;
extern ClientCall IN_KeyUp_call, IN_KeyDown_call;

struct usercmd_t* IW3_GetUserCmd( int cmd_num )
{
	if ( cmd_num > IW3_CurrentCmdNumber() ) {
		return NULL;
	}

	return &cl->Commands[cmd_num & 0x7F];
}

int IW3_CurrentCmdNumber( void )
{
	return cl->CommandNumber;
}

void IW3_LeftMouseDown( void )
{
	__asm {
		mov esi, left_mouse
		mov eax, IN_KeyDown_call
		call eax
	}
}

void IW3_LeftMouseUp( void )
{
	__asm {
		mov esi, left_mouse
		mov eax, IN_KeyUp_call
		call eax
	}
}