#pragma once
#include "iw3_common.h"

#include "iw3_players.h"
#include "iw3_input.h"

namespace IW3 {

        qboolean InGame( void );

        struct clSnapshot_t
        {
                qboolean Valid;
                int SnapFlags;
                int ServerTime;
                int MessageNumber;
                int DeltaNum;
                int Ping;
                int CmdNum;
                struct playerState_t PlayerState;
                int NumberOfEntities;
                int NumberOfClients;
                int ParseEntitiesNumber;
                int ParseClientsNumber;
                int ServerCommandNumber;
        }; //Size = 0x2F94

        struct gameState_t
        {
                int StringOffsets[2442];
                char StringData[0x20000];
                int DataCount;
        }; //Size: 0x2262C

        struct ClientArchiveData
        {
                int ServerTime;
                vec3_t Origin;
                vec3_t Velocity;
                int BobCycle;
                int MovementDirection;
                vec3_t ViewAngles;
        }; //Size: 0x30

        struct outPacket_t
        {
                int CommandNumber;
                int ServerTime;
                int Realtime;
        }; //Size: 0xC

        struct clientActive_t
        {
                qboolean IsADS;
                int TimeoutCount;
                struct clSnapshot_t Snapshot;
                qboolean AlwaysFalse;
                int ServerTime;
                int OldServerTime;
                int OldFrameServerTime;
                int ServerTimeDelta;
                int OldSnapServerTime;
                qboolean ExtrapolatingSnapshot;
                qboolean NewSnapshots;
                struct gameState_t GameState;
                char MapName[64];
                int ParseEntitiesNum;
                int ParseClientsNum;
                int MouseDX[2];
                int MouseDY[2];
                int MouseIndex;
                qboolean StanceHeld;
                qboolean Stance;
                int StancePosition;
                int StanceTime;
                int CGameUserCmdWeapon;
                int CGameUserCmdOffHandIndex;
                float CGameFOVSensitivityScale;
                float CGameMaxPitchSpeed;
                float CGameMaxYawSpeed;
                vec3_t CGameKickAngles;
                vec3_t CGameOrigin;
                vec3_t CGameVelocity;
                vec3_t CGameViewAngles;
                int CGameBobCycle;
                int CGameMovementDir;
                int CGameExtraButtons;
                int CGamePredictedDataServerTime;
                vec3_t ViewAngles;
                int ServerID;
                int SkeletonTimestamp;
                int SkeletonMemoryPosition;
                char SkeletonMemory[0x40000];
                int SkeletonMemoryStart;
                qboolean AllowedAllocSkeleton;
                struct usercmd_t Commands[128];
                int CommandNumber;
                struct ClientArchiveData ClientArchive[256];
                int ClientArchiveIndex;
                struct outPacket_t OutPackets[32];
                struct clSnapshot_t Snapshots[32];
                struct entityState_t EntityBaselines[1024];
                struct entityState_t ParseEntities[2048];
                struct clientState_s ParseClients[2048];
                int CorruptedTranslationFile;
                char TranslationVersion[256];
                float VehicleViewYaw;
                float VehicleViewPitch;
        }; //Size: 0x1B1BDC

        extern struct clientActive_t* cl;
}

