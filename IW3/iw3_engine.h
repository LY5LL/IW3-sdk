#pragma once
#include "iw3_common.h"
#include "iw3_players.h"

namespace IW3 {

        typedef unsigned short tag_t;

        // !!! WILL CRASH WHEN CALLED OUTSIDE OF ENGINE THREAD !!!
        void     CG_Trace( struct trace_t* result, vec3_t start, vec3_t mins, vec3_t maxs, vec3_t end, int skip_num, int mask );
        tag_t    RegisterTag( const char* tag );
        qboolean GetTagPos( tag_t tag, int client_num, vec_t* out );

        // !!! WILL CRASH WHEN CALLED OUTSIDE OF ENGINE THREAD !!!
        qboolean IsVisible( vec3_t vec );

        struct refdef_t
        {
                int ScreenX;
                int ScreenY;
                int ScreenWidth;
                int ScreenHeight;
                vec2_t FOV;
                vec3_t Origin;
                vec3_t ViewAxis[3];
                vec3_t ViewOffset;
        }; //Size=0x54

        struct cg_t
        {
                int ClientNum;
                char _0x0004[0x1C];
                struct snapshot_t* CurrentSnap;
                struct snapshot_t* NextSnap;
                char _0x0028[0x460FC];
                int FrameTime;
                int Time;
                int OldTime;
                int PhysicsTime;
                int MapRestart;
                int RenderingThirdPerson;
                struct playerState_t PredictedPlayerState;
                char _0x490A0[0x228];
                struct refdef_t Refdef;
        }; //Size=0xFE7F0

        struct cgs_t
        {
                int ScreenX;
                int ScreenY;
                int ScreenWidth;
                int ScreenHeight;
                float AspectRatio;
                char _0x0014[0x8];
                int LocalServer;
                char GameMode[32];
                char ServerName[256];
                int MaxClients;
                char MapName[64];
                int GameEndTime;
                int VoteTime;
                int VoteYes;
                int VoteNo;
                char _0x0194[0x3890];
        }; //Size=0x3A24

        enum TraceHitType {
                TRACE_HITTYPE_NONE = 0x0,
                TRACE_HITTYPE_ENTITY = 0x1,
                TRACE_HITTYPE_DYNENT_MODEL = 0x2,
                TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
        };

#pragma pack(push, 2)
        struct trace_t {
                float Fraction; //0x0000
                vec3_t Normal; //0x0004
                int SurfaceFlags; //0x0010
                int Contents; //0x0014
                const char* Material; //0x0018
                TraceHitType HitType; //0x001C
                unsigned short HitId; //0x0020
                unsigned short ModelIndex; //0x0022
                unsigned short PartName; //0x0024
                unsigned short PartGroup; //0x0026
                byte AllSolid; //0x0028
                byte StartSolid; //0x0029
                byte Walkable; //0x002A
        };
#pragma pack(pop)

        extern struct cg_t* cg;
        extern struct cgs_t* cgs;
}