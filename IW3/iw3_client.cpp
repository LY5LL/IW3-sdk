#include "iw3_client.h"

#include "iw3_qlib.h"

qboolean IW3_InGame( void )
{
	return (Q_strlen( cl->MapName ) != 0);
}
