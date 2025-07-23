#pragma once
#include "iw3_common.h"

#define CMD_FLG_SHOOT   0x1
#define CMD_FLG_SPRINT  0x2
#define CMD_FLG_MELEE   0x4
#define CMD_FLG_JUMP    0x400
#define CMD_FLG_ADS     0x800

namespace IW3 {

        struct usercmd_t*       GetUserCmd( int cmd_num );
        int                     CurrentCmdNumber( void );

        void                    LeftMouseDown( void );
        void                    LeftMouseUp( void );

        struct kbutton_t {
                int	        HeldKey[2];	        // key nums holding it down
                unsigned int	Downtime;		// msec timestamp. time since key was last held.
                unsigned int	TimeHeld;		// msec down this frame if both a down and up happened
                qboolean	Active;			// current state
                qboolean        WasPressed;             // Unused
        }; //Size=0x18

#pragma pack(push, 4)
        struct usercmd_t {
                int   ServerTime;
                int   Buttons;
                int   ViewAngles[3]; // usercmd_t::ViewAngles[PITCH] = ANGLE2SHORT(cl.ViewAngles[PITCH]);
                char  Weapon;
                char  OffHandIndex;
                char  ForwardMove;
                char  SideMove;
                float MeleeChargeYaw;
                char  MeleeChargeDist;
        }; //Size=0x20
#pragma pack(pop)
}