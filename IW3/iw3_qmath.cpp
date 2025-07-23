#include "iw3_qmath.h"

#include <cmath>

#include "iw3_common.h"

void AngleVectors( const vec3_t angles, vec3_t forward, vec3_t right, vec3_t up )
{
	float		angle;
	static float		sr, sp, sy, cr, cp, cy;
	// static to help MS compiler fp bugs

	angle = angles[YAW] * (M_PI * 2 / 360);
	sy = sin( angle );
	cy = cos( angle );
	angle = angles[PITCH] * (M_PI * 2 / 360);
	sp = sin( angle );
	cp = cos( angle );
	angle = angles[ROLL] * (M_PI * 2 / 360);
	sr = sin( angle );
	cr = cos( angle );

	if ( forward )
	{
		forward[0] = cp * cy;
		forward[1] = cp * sy;
		forward[2] = -sp;
	}
	if ( right )
	{
		right[0] = (-1 * sr * sp * cy + -1 * cr * -sy);
		right[1] = (-1 * sr * sp * sy + -1 * cr * cy);
		right[2] = -1 * sr * cp;
	}
	if ( up )
	{
		up[0] = (cr * sp * cy + -sr * -sy);
		up[1] = (cr * sp * sy + -sr * cy);
		up[2] = cr * cp;
	}
}

vec_t VectorNormalize( vec3_t v )
{
	float	length, ilength;

	length = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	length = sqrt( length );

	if ( length ) {
		ilength = 1 / length;
		v[0] *= ilength;
		v[1] *= ilength;
		v[2] *= ilength;
	}

	return length;
}