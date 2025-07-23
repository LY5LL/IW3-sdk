#pragma once

#define DotProduct(x,y)			(x[0]*y[0]+x[1]*y[1]+x[2]*y[2])
#define VectorSubtract(a,b,c)		{c[0]=a[0]-b[0];c[1]=a[1]-b[1];c[2]=a[2]-b[2];}
#define VectorAdd(a,b,c)		{c[0]=a[0]+b[0];c[1]=a[1]+b[1];c[2]=a[2]+b[2];}
#define VectorCopy(a,b)			{b[0]=a[0];b[1]=a[1];b[2]=a[2];}
#define Vector4Copy(a,b)		{b[0]=a[0];b[1]=a[1];b[2]=a[2];b[3]=a[3];}
#define	VectorScale(v, s, o)		((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define VectorClear(x)			{x[0] = x[1] = x[2] = 0;}
#define VectorNegate(x, y)		{y[0]=-x[0];y[1]=-x[1];y[2]=-x[2];}
#define	VectorMA(v, s, b, o)		((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))

#define	PITCH					0
#define YAW					1
#define	ROLL					2

#define ANGLE2SHORT(x)          ((int)((x) * 65536 / 360) & 65535)
#define SHORT2ANGLE(x)          ((x)*(360.0 / 65536))

#define	Q_PI	3.14159265358979323846

#define DEG2RAD( a ) ( ( (a) * M_PI ) / 180.0F )
#define RAD2DEG( a ) ( ( (a) * 180.0f ) / M_PI )

#ifndef M_PI
#define M_PI		3.14159265358979323846
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef unsigned char 		byte;
typedef enum { qfalse, qtrue }	qboolean;

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec5_t[5];

extern qboolean IW3_Init( void );

/* Typedef-ed because a lot of functions will need to be called with asm because some args are
 expected to be in registers. These variables will store the address in which we will call. */
typedef void* EngineCall;
typedef EngineCall ClientCall;

struct trajectory_t {
        int Type; 
        int Time; 
        int Duration; 
        vec3_t Base; 
        vec3_t Delta; 
}; //Size=0x0024

struct cpose_t {
        short LightingHandle;
        unsigned char EType; 
        unsigned char ETypeUnion; 
        char _0x0004[0x18]; 
        vec3_t Origin; 
        vec3_t Angles; 
        char _0x0034[0x30]; 
}; //Size=0x0064

typedef enum {
        TRACE_HITTYPE_NONE = 0x0,
        TRACE_HITTYPE_ENTITY = 0x1,
        TRACE_HITTYPE_DYNENT_MODEL = 0x2,
        TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
} TraceHitType;