#pragma once
#include <Windows.h>
#include "Utils/ProcessManager.hpp"

// From: https://github.com/a2x/cs2-dumper/blob/main/generated/client.dll.hpp
namespace Offset
{
	inline DWORD EntityList = 0x18C2D58; //offset.hpp + client.dll + dwEntityList
	inline DWORD Matrix = 0x19241A0;                 //offset.hpp + client.dll + dwViewMatrix
	inline DWORD ViewAngle = 0x19309B0;              //offset.hpp + client.dll + dwViewAngles
	inline DWORD LocalPlayerController = 0x1912578;  //offset.hpp + client.dll + dwLocalPlayerController
	inline DWORD LocalPlayerPawn = 0x17371A8;        //offset.hpp + client.dll + dwLocalPlayerPawn
	inline DWORD ForceJump = 0x1730530;				//offset.hpp + client.dll + dwForceJump
	inline DWORD GlobalVars = 0x172ABA0;			//offset.hpp + client.dll + dwGlobalVars

	struct
	{
		DWORD Health = 0x334;			//client.dll.hpp + C_BaseEntity + m_iHealth
		DWORD TeamID = 0x3CB;			//client.dll.hpp + C_BaseEntity + m_iTeamNum
		DWORD IsAlive = 0x7EC;			//client.dll.hpp + CCSPlayerController + m_bPawnIsAlive
		DWORD PlayerPawn = 0x7E4;		//client.dll.hpp + CCSPlayerController + m_hPlayerPawn
		DWORD iszPlayerName = 0x638;	//client.dll.hpp + CBasePlayerController + m_iszPlayerName
	}Entity;

	struct
	{
		DWORD Pos = 0x127C;						//client.dll.hpp + C_BasePlayerPawn + m_vOldOrigin
		DWORD MaxHealth = 0x330;				//client.dll.hpp + C_BaseEntity + m_iMaxHealth
		DWORD CurrentHealth = 0x334;			//client.dll.hpp + C_BaseEntity + m_iHealth
		DWORD GameSceneNode = 0x318;			//client.dll.hpp + C_BaseEntity + m_pGameSceneNode
		DWORD BoneArray = 0x1E0;				//client.dll.hpp + CPlayer_CameraServices + m_fOverrideFogEnd
		DWORD angEyeAngles = 0x1578;			//client.dll.hpp + C_CSPlayerPawnBase + m_angEyeAngles
		DWORD vecLastClipCameraPos = 0x12EC;	//client.dll.hpp + C_CSPlayerPawnBase + m_vecLastClipCameraPos
		DWORD pClippingWeapon = 0x1308;			//client.dll.hpp + C_CSPlayerPawnBase + m_pClippingWeapon
		DWORD iShotsFired = 0x147C;				//client.dll.hpp + C_CSPlayerPawnBase + m_iShotsFired
		DWORD flFlashDuration = 0x14CC;			//client.dll.hpp + C_CSPlayerPawnBase + m_flFlashDuration
		DWORD aimPunchAngle = 0x177C;			//client.dll.hpp + C_CSPlayerPawn + m_aimPunchAngle
		DWORD aimPunchCache = 0x17A0;			//client.dll.hpp + C_CSPlayerPawn + m_aimPunchCache
		DWORD iIDEntIndex = 0x15A4;				//client.dll.hpp + C_CSPlayerPawnBase + m_iIDEntIndex
		DWORD iTeamNum = 0x3CB;					//client.dll.hpp + C_BaseEntity + m_iTeamNum
		DWORD CameraServices = 0x1138;			//client.dll.hpp + C_BasePlayerPawn + m_pCameraServices
		DWORD iFovStart = 0x214;				//client.dll.hpp + CCSPlayerBase_CameraServices + m_iFOVStart
		DWORD fFlags = 0x3D4;					//client.dll.hpp + C_BaseEntity + m_fFlags
		DWORD m_vecAbsVelocity = 0x3D8;	//client.dll.hpp + CBasePlayerController + m_vecAbsVelocity
		DWORD m_entitySpottedState = 0x1698;	//client.dll.hpp + C_CSPlayerPawnBase + m_entitySpottedState
		DWORD m_bSpottedByMask = 0xC;			//client.dll.hpp + EntitySpottedState_t + m_bSpottedByMask
		DWORD bSpottedByMask = m_entitySpottedState + m_bSpottedByMask; // entitySpottedState + bSpottedByMask	
	}Pawn;

	struct
	{
		DWORD RealTime = 0x00;
		DWORD FrameCount = 0x04;
		DWORD MaxClients = 0x10;
		DWORD IntervalPerTick = 0x14;
		DWORD CurrentTime = 0x2C;
		DWORD CurrentTime2 = 0x30;
		DWORD TickCount = 0x40;
		DWORD IntervalPerTick2 = 0x44;
		DWORD CurrentNetchan = 0x0048;
		DWORD CurrentMap = 0x0180;
		DWORD CurrentMapName = 0x0188;
	} GlobalVar;

	namespace Signatures
	{
		const std::string GlobalVars = "48 89 0D ?? ?? ?? ?? 48 89 41";
		const std::string ViewMatrix = "48 8D 0D ?? ?? ?? ?? 48 C1 E0 06";
		const std::string ViewAngles = "48 8B 0D ?? ?? ?? ?? E9 ?? ?? ?? ?? CC CC CC CC 40 55";
		const std::string EntityList = "48 8B 0D ?? ?? ?? ?? 48 89 7C 24 ?? 8B FA C1";
		const std::string LocalPlayerController = "48 8B 05 ?? ?? ?? ?? 48 85 C0 74 4F";
		const std::string ForceJump = "48 8B 05 ?? ?? ?? ?? 48 8D 1D ?? ?? ?? ?? 48 89 45";
		const std::string LocalPlayerPawn = "48 8D 05 ?? ?? ?? ?? C3 CC CC CC CC CC CC CC CC 48 83 EC ?? 8B 0D";
	}

	bool UpdateOffsets();
}
