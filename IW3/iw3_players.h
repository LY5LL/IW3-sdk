#pragma once
#include "iw3_common.h"

struct centity_t*       IW3_GetCentity( int client_num );
struct clientState_s*   IW3_GetClientState( int client_num );
struct entityState_t*   IW3_GetClientEntityState( int client_num );
struct clientinfo_t*    IW3_GetClientInfo( int client_num );

qboolean IW3_IsEnemy( int client_num );
qboolean IW3_IsDead( int client_num );
qboolean IW3_IsValid( int client_num );

typedef enum {
        TEAM_FREE = 0x0,
        TEAM_AXIS = 0x1,
        TEAM_ALLIES = 0x2,
        TEAM_SPECTATOR = 0x3,
        TEAM_NUM_TEAMS = 0x4,
} team_t;

typedef enum {
        ET_GENERAL,
        ET_PLAYER,
        ET_PLAYER_CORPSE,
        ET_ITEM,
        ET_MISSILE,
        ET_INVISIBLE,
        ET_SCRIPTMOVER,
        ET_SOUND_BLEND,
        ET_FX,
        ET_LOOP_FX,
        ET_PRIMARY_LIGHT,
        ET_MG42,
        ET_HELICOPTER,
        ET_PLANE,
        ET_VEHICLE,
        ET_VEHICLE_COLLMAP,
        ET_VEHICLE_CORPSE,
        ET_EVENTS
} entityType_t;

typedef enum {
        EF_CROUCHING = (1U << 2),
        EF_PRONE = (1U << 3),
        EF_FIRING = (1U << 6),
        EF_ADS = (1U << 12),
        EF_ISPLAYING = (1U << 21),
        EF_DEAD = (1U << 17)
} entityFlags_t;

typedef enum {
        PERK_JAMRADAR = 0x0,
        PERK_ACCURACY = 0x1,
        PERK_FASTRELOAD = 0x2,
        PERK_RATEOFFIRE = 0x3,
        PERK_EXTRABREATH = 0x4,
        PERK_EXTRABP = 0x5,
        PERK_GRENADEDEATH = 0x6,
        PERK_PISTOLDEATH = 0x7,
        PERK_QUIETMOVE = 0x8,
        PERK_PARABOLIC = 0x9,
        PERK_LONGERSPRINT = 0xA,
        PERK_DETECTEXPLOSIVE = 0xB,
        PERK_EXPLOSIVEDMG = 0xC,
        PERK_EXPOSEENEMY = 0xD,
        PERK_BULLETDMG = 0xE,
        PERK_EXTRAAMMO = 0xF,
        PERK_TWOPRIMARIES = 0x10,
        PERK_ARMORVEST = 0x11,
        PERK_FRAGGRENADE = 0x12,
        PERK_SPECIALGRENADE = 0x13,
        PERK_COUNT = 0x14,
        PERK_UNKNOWN = 0x14,
} perksEnum;

typedef enum {
        STAT_HEALTH = 0x0,
        STAT_DEAD_YAW = 0x1,
        STAT_MAX_HEALTH = 0x2,
        STAT_IDENT_CLIENT_NUM = 0x3,
        STAT_SPAWN_COUNT = 0x4,
        MAX_STATS = 0x5,
} statIndex_t;

struct LerpEntityState {
        unsigned int EntityFlags; 
        struct trajectory_t Postion; 
        struct trajectory_t APostion; 
        char _0x004C[0x1C]; 
}; //Size=0x0068

struct entityState_t {
        int Number;
        int EType; 
        struct LerpEntityState Lerp; 
        int Time2; 
        int OtherEntityNum;
        int AttackerEntityNum; 
        int GroundEntityNum; 
        int LoopSound; 
        int SurfaceType;
        int Index; 
        int ClientNum; 
        int IHeadIcon; 
        int IHeadIconTeam; 
        int Solid; 
        int EventParam; 
        int EventSequence; 
        int Events[4]; 
        int EventParams[4]; 
        int Weapon; 
        int WeaponModel;
        int LegsAnim; 
        int TorsoAnim; 
        int Union1; 
        int Union2; 
        float TorsoPitch; 
        float WaistPitch; 
        int PartBits[4]; 
}; //Size=0x00F4

struct centity_t {
        struct cpose_t Pose;
        struct LerpEntityState CurrentState; 
        struct entityState_t NextState; 
        int Tree;
        char _0x01C4[0x18]; //0x01C4
}; //Size=0x01DC

struct SprintState
{
        int SprintButtonUpRequired; 
        int SprintDelay; 
        int LastSprintStart; 
        int LastSprintEnd; 
        int SprintStartMaxLength; 
}; //Size=0x0014

struct MantleState
{
        float Yaw; 
        int Timer; 
        int TransIndex; 
        int Flags; 
}; //Size=0x0010

struct playerState_t
{
        int CommandTime;
        int PM_Type;
        int BobCycle; 
        int PM_Flags; 
        int WeaponFlags; 
        int OtherFlags; 
        int PM_Time; 
        vec3_t Origin; 
        vec3_t Velocity; 
        vec2_t OldVelocity;
        int WeaponTime; 
        int WeaponDelay;
        int GrenadeTimeLeft; 
        int ThrowbackGrenadeOwner; 
        int ThrowbackGrenadeTimeLeft; 
        int WeaponRestrictKickTime; 
        int FoliageSoundTime; 
        int Gravity; 
        float Lean; 
        int Speed;
        vec3_t DeltaAngles; 
        int GroundEntityNum;
        vec3_t LadderVec; 
        int JumpTime; 
        float JumpOriginZ; 
        int LegsTimer; 
        int LegsAnim;
        int TorsoTimer; 
        int TorsoAnim; 
        int LegsAnimDuration;
        int TorsoAnimDuration; 
        int DamageTimer; 
        int DamageDuration; 
        int FlinchYawAnim;
        int MovementDir; 
        int EFlags; 
        int EventSequence; 
        int Events[4]; 
        int EventParams[4]; 
        int OldEventSequence; 
        int ClientNum; 
        int OffHandIndex;
        int OffhandSecondary; 
        int Weapon; 
        int WeaponState; 
        int WeaponShotCount; 
        float WeaponPosFraction; 
        int ADSDelayTime;
        int SpreadOverride; 
        int SpreadOverrideState; 
        int ViewModelIndex;
        vec3_t ViewAngles; 
        int ViewHeightTarget;
        float ViewHeightCurrent;
        int ViewHeightLerpTime; 
        int ViewHeightLerpTarget; 
        int ViewHeightLerpDown; 
        vec2_t ViewAngleClampBase; 
        vec2_t ViewAngleClampRange; 
        int DamageEvent; 
        int DamageYaw;
        int DamagePitch;
        int DamageCount; 
        int Stats[5]; 
        int Ammo[128];
        int AmmoInClip[128]; 
        int Weapons[4];
        int WeaponsOld[4]; 
        int WeaponRechamber[4]; 
        float ProneDirection; 
        float ProneDirectionPitch; 
        float ProneTorsoPitch; 
        int ViewLocked; 
        int ViewLockedEntNum; 
        int CursorHint; 
        int CursorHintString; 
        int CursorHintEntIndex; 
        int ICompassPlayerInfo;
        int RadarEnabled; 
        int LocationSelectionInfo; 
        struct SprintState SprintState; 
        float TorsoPitch; 
        float WaistPitch;
        float HoldBreathScale;
        int HoldBreathTimer; 
        float MoveSpeedScaleMultiplier; 
        struct MantleState MantleState; 
        float MeleeChargeYaw; 
        int MeleeChargeDistance; 
        int MeleeChargeTime; 
        int Perks; 
        int ActionSlotType[4];
        int ActionSlotParam[4];
        int EntityEventSequence; 
        int WeaponAnim; 
        float AimSpreadScale; 
        int ShellShockIndex; 
        int ShellShockTime; 
        int ShellShockDuration; 
        float DOFNearStart; 
        float DOFNearEnd;
        float DOFFarStart; 
        float DOFFarEnd; 
        float DOFNearBlur; 
        float DOFFarBlur; 
        float DOFViewModelStart; 
        float DOFViewModelEnd; 
        char _0x0658[0x1C4]; 
        char WeaponModels[128];
        int DeltaTime;
        int KillCamEntity;
        char _0x08A4[0x26C0]; 
}; //Size=0x2F64



struct clientState_s
{
        int ClientIndex; 
        enum team_t Team; 
        int Modelindex; 
        int AttachModelIndex[6]; 
        int AttachTagIndex[6]; 
        char Name[16]; 
        float MaxSprintTimeMultiplier; 
        int Rank; 
        int Prestige; 
        int Perks;
        int AttachedVehEntNum; 
        int AttachedVehSlotIndex; 
}; //Size: 0x64

struct snapshot_t
{
        int Flags; 
        int Ping; 
        int ServerTime; 
        struct playerState_t PlayerState; 
        int  NumEntities; 
        int  NumClients; 
        struct entityState_t Entities[512]; 
        struct clientState_s Clients[64]; 
        int ServerCommandSequence; 
}; //Size=0x2307C

struct clientControllers_t {
        vec3_t Angles[6]; 
        vec3_t TagOriginAngles;
        vec3_t TagOriginOffset; 
}; //Size=0x60

struct lerpFrame_t
{
        float YawAngle; 
        int Yawing; 
        float PitchAngle; 
        int Pitching; 
        int AnimationNumber; 
        void* Animation; 
        int AnimationTime; 
        vec3_t OldFramePosition; 
        float AnimSpeedScale; 
        int OldFrameSnapshotTime;
}; //Size=0x30

#pragma pack(push, 4)
struct clientinfo_t
{
        int IsValid;
        int NextValid; 
        int ClientNumber; 
        char Name[16];
        team_t Team; 
        team_t OldTeam; 
        int Rank; 
        int Prestige; 
        unsigned int Perks; 
        int Score; 
        int Location;
        int Health; 
        char BodyModel[64]; 
        char AttachedModels[6][64]; 
        char AttachedTags[6][64]; 
        struct lerpFrame_t Legs; 
        struct lerpFrame_t Torso;
        float LerpMoveDirection; 
        float LerpLean;
        vec3_t ViewAngles;
        qboolean LeftHandGun;
        qboolean DObjDirty; 
        struct clientControllers_t Control; 
        char _0x0458[0x50];
        void* AnimationTree; 
        int DObjWeapon;
        int WeaponModel; 
        int StanceTransitionTime; 
        int TurnAnimationTime;
        qboolean TurnAnimationType; 
        int AttachedVehicleEntityNumber; 
        int AttachedVehicleSlotIndex; 
        byte HideWeapon; 
        byte UsingKnife; 
}; //Size=0x04CC
#pragma pack(pop)

extern struct centity_t* centities;
extern struct clientinfo_t* client_info;