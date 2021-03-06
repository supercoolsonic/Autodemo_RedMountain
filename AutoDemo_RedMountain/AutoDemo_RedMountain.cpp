// AutoDemo_RedMountain.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <cmath>

//LandTables
#include "LandTable\Act1.h"
#include "LandTable\Act2.h"
#include "LandTable\Act3.h"
#include "LandTable\Skybox_Models.h"

//Objects
#include "ObjModels\Bridge_Objects.h"
#include "ObjModels\Cloud_Objects.h"
#include "ObjModels\Fence_Objects.h"
#include "ObjModels\Machine_Objects.h"
#include "ObjModels\Misc_Objects.h"
#include "ObjModels\Plant_Objects.h"
#include "ObjModels\Rock_Objects.h"
#include "ObjModels\Spooky_Objects.h"

//Misc
#include "MiscFiles\PathInfo.h"
#include "MiscFiles\StartPos.h"
#include "MiscFiles\Texlists.h"
#include "IniFile.hpp"

//Replacement Functions
#define ReplaceBINFile(a, b) helperFunctions.ReplaceFile("system\\" a ".BIN", "system\\" b ".BIN");
#define ReplacePVMFile(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

//Config Variables
static bool ADSetFile = true;
static bool ADCamFile = true;
static bool KnucklesTutorial = true;

static bool AlwaysGreenLight = true;
static bool AlwaysCloudLayer = true;
static bool AlwaysFloorLight = true;
static bool AlwaysFence = true;

//Structs
struct ObjectThing
{
	ObjectFuncPtr func;
	int16_t list;
	int16_t field_A;
	Rotation3 Rotation;
	NJS_VECTOR Position;
	NJS_OBJECT* object;
};

//Additional SADX Variables
DataArray(CollisionData, stru_C67750, 0xC67750, 1);
DataArray(CollisionData, stru_C673B8, 0xC673B8, 7);


DataArray(NJS_VECTOR, SkyboxScale_RedMountain2, 0x02240628, 3);
DataArray(FogData, RedMountain1Fog, 0x02240700, 3);
DataArray(FogData, RedMountain2Fog, 0x02240730, 3);
DataArray(FogData, RedMountain3Fog, 0x02240760, 3);


DataPointer(float, CurrentDrawDistance, 0x03ABDC74);
FunctionPointer(void, sub_600BF0, (ObjectMaster *a1, NJS_OBJECT *a2), 0x600BF0);
FunctionPointer(void, sub_409E70, (NJS_MODEL_SADX *a1, int a2, float a3), 0x409E70);
FunctionPointer(double, sub_789320, (float a2), 0x789320);

FunctionPointer(void, sub_407A00, (NJS_MODEL_SADX *model, float scale), 0x407A00);
FunctionPointer(void, sub_405450, (NJS_ACTION *a1, float frame, float scale), 0x405450);
FunctionPointer(void, sub_5BBB60, (int a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8), 0x5BBB60);
FunctionPointer(void, sub_49D5F0, (EntityData1 *a1), 0x49D5F0);
FunctionPointer(void, InitCollision, (ObjectMaster *obj, CollisionData *collisionArray, int count, unsigned __int8 list), 0x41CAF0);

//bridge
DataPointer(NJS_OBJECT, stru_2466594, 0x2466594);
DataPointer(NJS_OBJECT, stru_24666EC, 0x24666EC);
DataPointer(NJS_OBJECT, stru_2466844, 0x2466844);

DataPointer(NJS_OBJECT, stru_242A820, 0x242A820);
DataPointer(NJS_OBJECT, stru_C06A94, 0xC06A94);
DataPointer(NJS_ACTION, stru_2445DEC, 0x2445DEC);
DataPointer(NJS_ACTION, stru_242A464, 0x242A464);
DataPointer(NJS_ACTION, stru_2454D8C, 0x2454D8C);
DataPointer(NJS_ACTION, stru_247D8AC, 0x247D8AC);
DataPointer(NJS_ACTION, stru_2465E8C, 0x2465E8C);
DataPointer(NJS_ACTION, stru_247E644, 0x247E644);
DataPointer(NJS_ACTION, stru_246501C, 0x246501C);
DataPointer(float, CurrentFogDist, 0x03ABDC64);
DataPointer(float, CurrentFogLayer, 0x03ABDC60);
DataPointer(NJS_VECTOR, CurrentSkybox, 0x03ABDC94);
DataPointer(NJS_BGRA, CurrentFogColorX, 0x03ABDC68);
DataArray(CollisionData, stru_24C8F90, 0x24C8F90, 1);\

DataArray(NJS_TEX, stru_3C80F00, 0x3C80F00, 33);
DataArray(NJS_TEX, stru_3C80E80, 0x3C80E80, 1);
DataPointer(NJS_OBJECT, stru_246CAA8, 0x246CAA8);

//tutorial stuff
DataPointer(NJS_TEXANIM, stru_1C46CA4, 0x1C46CA4);
DataPointer(int, dword_1C46CC0, 0x1C46CC0);
DataPointer(char, byte_1E74AC9, 0x1E74AC9);
DataPointer(float, flt_1C46CF0, 0x1C46CF0);
DataPointer(NJS_POINT2, stru_1C46CE4, 0x1C46CE4);
DataPointer(NJS_POINT2, stru_1C46CC4, 0x1C46CC4);
DataPointer(float, flt_1C46CD0, 0x1C46CD0);
DataPointer(Uint8, byte_1C46CD8, 0x1C46CD8);
DataPointer(Uint8, byte_1C46CB8, 0x1C46CB8);
FunctionPointer(void, sub_427BB0, (Uint8 *a1), 0x00427BB0);



FunctionPointer(void, SetStatus, (ObjectMaster *a1), 0x0049CD60);
FunctionPointer(void, DynCol_LoadObject, (ObjectMaster *a1), 0x0049E170);
FunctionPointer(void, sub_446AF0, (ObjectMaster *a1, int a2), 0x446AF0);

DataPointer(int, DroppedFrames, 0x03B1117C);

//Additional SADX Functions
FunctionPointer(NJS_OBJECT *, DynamicCollision, (NJS_OBJECT *a1, ObjectMaster *a2, ColFlags surfaceFlags), 0x49D6C0);
FunctionPointer(int, rand1, (), 0x6443BF);
DataPointer(int, FramerateSetting, 0x0389D7DC);


static int UVShift1 = 0;
static int UVShift2 = 0;
static int UVShift3 = 0;
static double cloudcoloroffset = 0.0f;
int fireballanimation = 2;
bool greenlightcheat = false;
bool floorlightcheat = false;
bool greenfencecheat = true;
bool thirdcloudlayercheat = false;
SETObjData GlideTutorial = {};

bool HasloadedTutorial = false;
static int TutorialTimer = 80;


//Null Code (Used for debugging purposes)
void __cdecl NullFunction(ObjectMaster *a1)
{
	return;
}

//Standard Display
void __cdecl Basic_Display(ObjectMaster *a2)
{
	EntityData1 *v1; // esi@1
	Angle v2; // eax@2
	Angle v3; // eax@4
	Angle v4; // eax@6

	v1 = a2->Data1;
	if (!MissedFrames)
	{
		SetTextureToLevelObj();
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		v2 = v1->Rotation.z;
		if (v2)
		{
			njRotateZ(0, (unsigned __int16)v2);
		}
		v3 = v1->Rotation.x;
		if (v3)
		{
			njRotateX(0, (unsigned __int16)v3);
		}
		v4 = v1->Rotation.y;
		if (v4)
		{
			njRotateY(0, (unsigned __int16)v4);
		}
		ProcessModelNode_AB_Wrapper(v1->Object, 1.0);
		njPopMatrix(1u);
	}
}

//Standard Main
void __cdecl Basic_Main(ObjectMaster *a1)
{
	EntityData1 *v1; // edi@1

	v1 = a1->Data1;
	if (!ClipSetObject_Min(a1))
	{
		if (!ObjectSelectedDebug(a1))
		{
			AddToCollisionList(v1);
		}
		Basic_Display(a1);
	}
}

//Standard Delete Dynamic
void deleteSub_Global(ObjectMaster *a1) {
	if (a1->Data1->Object)
	{
		DynamicCOL_Remove(a1, a1->Data1->Object);
		ObjectArray_Remove(a1->Data1->Object);
	}
	DeleteObject_(a1);
}

void AddToCollision(ObjectMaster *a1, uint8_t col) {
	/*  0 is static
	1 is moving (refresh the colision every frame)
	2 is static, scalable
	3 is moving, scalable   */

	EntityData1 * original = a1->Data1;
	NJS_OBJECT *colobject;

	colobject = ObjectArray_GetFreeObject(); //The collision is a separate object, we add it to the list of object

	//if scalable
	if (col == 2 || col == 3) {
		colobject->evalflags = NJD_EVAL_BREAK | NJD_EVAL_SKIP | NJD_EVAL_HIDE;
		colobject->scl[0] = original->Scale.x;
		colobject->scl[1] = original->Scale.y;
		colobject->scl[2] = original->Scale.z;
	}
	else if (col == 4) {
		colobject->evalflags = NJD_EVAL_BREAK | NJD_EVAL_SKIP | NJD_EVAL_HIDE;
		colobject->scl[0] = 1.0f + original->Scale.x;
		colobject->scl[1] = 1.0f + original->Scale.x;
		colobject->scl[2] = 1.0f + original->Scale.x;
	}
	else if (col == 5) {
		colobject->evalflags = NJD_EVAL_BREAK | NJD_EVAL_SKIP | NJD_EVAL_HIDE;
		colobject->scl[0] = 1.0f + original->Scale.z;
		colobject->scl[1] = 1.0f + original->Scale.z;
		colobject->scl[2] = 1.0f + original->Scale.z;
	}
	else {
		colobject->evalflags = NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK | NJD_EVAL_SKIP | NJD_EVAL_HIDE; //ignore scale
		colobject->scl[0] = 1.0;
		colobject->scl[1] = 1.0;
		colobject->scl[2] = 1.0;
	}

	//add the rest
	if (col == 4 || col == 1 || col == 5)
	{
		colobject->ang[0] = 0;
		colobject->ang[1] = original->Rotation.y;
		colobject->ang[2] = 0;
	}
	else {
		colobject->ang[0] = original->Rotation.x;
		colobject->ang[1] = original->Rotation.y;
		colobject->ang[2] = original->Rotation.z;
	}
	colobject->pos[0] = original->Position.x;
	colobject->pos[1] = original->Position.y;
	colobject->pos[2] = original->Position.z;

	colobject->basicdxmodel = a1->Data1->Object->basicdxmodel; //object it will use as a collision
	a1->Data1->Object = colobject; //pointer to the collision object into our original object

	if (col == 0 || col == 2) DynamicCOL_Add((ColFlags)1, a1, colobject); //Solid
	else if (col == 1 || col == 3 || col == 4 || col == 5) DynamicCOL_Add((ColFlags)0x8000000, a1, colobject); //Dynamic, solid
}

//Basic drawing call
void DrawObjModel(ObjectMaster *a1, NJS_MODEL_SADX *m, bool scalable) {
	if (!MissedFrames) {
		njSetTexture((NJS_TEXLIST*)&BEACH01_TEXLIST); //Current heroes level texlist is always onto Emerald Coast
		njPushMatrix(0);
		njTranslateV(0, &a1->Data1->Position);
		njRotateXYZ(nullptr, a1->Data1->Rotation.x, a1->Data1->Rotation.y, a1->Data1->Rotation.z);
		if (scalable) njScale(nullptr, a1->Data1->Scale.x, a1->Data1->Scale.y, a1->Data1->Scale.z);
		else njScale(nullptr, 1, 1, 1);
		DrawQueueDepthBias = -6000.0f;
		DrawModel(m);
		DrawQueueDepthBias = 0;
		njPopMatrix(1u);
	}
}

//borrowing from PkR !(modified)!:
void RenderRMSky1(ObjectMaster *a1, NJS_OBJECT *a2)
{
	int v2_3 = (unsigned __int8)CurrentAct;

	switch (v2_3)
	{
	case 0:
		if (Camera_Data1->Position.y < 280)
		{
			if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 200;
			else DrawQueueDepthBias = 6000.0f;
		}
		else
		{
			if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 600;
			else DrawQueueDepthBias = 10000.0f;
		}
		break;
	case 1:
		if (Camera_Data1->Position.y < 680)
		{
			if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 200;
			else DrawQueueDepthBias = 6000.0f;
		}
		else
		{
			if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 600;
			else DrawQueueDepthBias = 10000.0f;
		}
		break;
	case 2:
		if (Camera_Data1->Position.y < -50)
		{
			if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 200;
			else DrawQueueDepthBias = 6000.0f;
		}
		else
		{
			if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 600;
			else DrawQueueDepthBias = 10000.0f;
		}
		break;
	default:
		break;
	}
	sub_600BF0(a1, &object_CloudLayer_AD);
	DrawQueueDepthBias = 0.0f;
}

void RenderRMSky2(ObjectMaster *a1, NJS_OBJECT *a2)
{
	int v2_2 = (unsigned __int8)CurrentAct;

		if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 400;
		else DrawQueueDepthBias = 8000.0f;
		sub_600BF0(a1, &object_CloudLayer_AD_2);
		DrawQueueDepthBias = 0.0f;

		if (GetCurrentCharacterID() == 3)
		{
			a1->Data1->Position.y = -100.0;
		}
		else
		{
			a1->Data1->Position.y = 230.0;
		}
		if (v2_2 == 1)
		{
			a1->Data1->Position.y = 660.0;
		}


		if (thirdcloudlayercheat == true || AlwaysCloudLayer)
		{
			switch (v2_2)
			{
			case 0:
				if (Camera_Data1->Position.y < 280)
				{
					if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 600;
					else DrawQueueDepthBias = 10000.0f;
				}
				else
				{
					if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 200;
					else DrawQueueDepthBias = 6000.0f;
				}
				break;
			case 1:
				if (Camera_Data1->Position.y < 680)
				{
					if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 600;
					else DrawQueueDepthBias = 10000.0f;
				}
				else
				{
					if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 200;
					else DrawQueueDepthBias = 6000.0f;
				}
				break;
			case 2:
				if (Camera_Data1->Position.y < -50)
				{
					if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 600;
					else DrawQueueDepthBias = 10000.0f;
				}
				else
				{
					if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 200;
					else DrawQueueDepthBias = 6000.0f;
				}
				break;
			default:
				break;
			}

			//if (EV_MainThread_ptr != nullptr) DrawQueueDepthBias = 600;
			//else DrawQueueDepthBias = 10000.0f;
			sub_600BF0(a1, &object_CloudLayer2_AD);
			DrawQueueDepthBias = 0.0f;
		}
}

void SetCloudColor(NJS_ARGB *a)
{
	SetMaterialAndSpriteColor_Float(0.2f + a->a, 0.2f + a->r, 0.2f + a->g, 0.2f + a->b);
}




void KnucklesTutorialDisplay(ObjectMaster *a1)
{
	EntityData1 *v1;


	v1 = a1->Data1;

	Tutorial0Texanim.sx = 256 * HorizontalStretch;
	Tutorial0Texanim.sy = 64 * HorizontalStretch;
	Tutorial1Texanim.sx = 256 * HorizontalStretch;
	Tutorial1Texanim.sy = 64 * HorizontalStretch;
	Tutorial2Texanim.sx = 256 * HorizontalStretch;
	Tutorial2Texanim.sy = 64 * HorizontalStretch;

	if (BETAMOUNTAIN_texlist.textures->texaddr)
	{
		njColorBlendingMode(0, NJD_COLOR_BLENDING_SRCALPHA);
		njColorBlendingMode(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_INVSRCALPHA);
		njSetTexture(&BETAMOUNTAIN_texlist);
		SetMaterialAndSpriteColor_Float(1.0f, 1.0f, 1.0f, 1.0f);

		switch (TextLanguage)
		{
		case 0:
			if (TutorialTimer == 0)
			{
				_TutIntro.p.x = HorizontalStretch * *(float *)&v1->LoopData;
				_TutFail.p.x = HorizontalStretch * *(float *)&v1->Object;
				_TutControl.p.x = HorizontalStretch * *(float *)&v1->Object;
			}
			else
			{
				TutorialTimer--;
			}

			if ((EntityData1Ptrs[0]->Status & Status_Ground || GetCharObj2(0)->JumpTime <= 60) && v1->InvulnerableTime == 0)
			{
				njDrawSprite2D_ForcePriority(&_TutControl, 0, 22046.498f, NJD_SPRITE_ALPHA);

			}
			else if (GetCharObj2(0)->JumpTime > 60 && v1->InvulnerableTime == 0)
			{
				njDrawSprite2D_ForcePriority(&_TutFail, 0, 22046.498f, NJD_SPRITE_ALPHA);
				v1->InvulnerableTime = 180;
			}
			else
			{
				njDrawSprite2D_ForcePriority(&_TutFail, 0, 22046.498f, NJD_SPRITE_ALPHA);
			}
			njDrawSprite2D_ForcePriority(&_TutIntro, 0, 22046.498f, NJD_SPRITE_ALPHA);
			break;
		case 1:
			if (TutorialTimer == 0)
			{
				_TutIntroE.p.x = HorizontalStretch * *(float *)&v1->LoopData;
				_TutFailE.p.x = HorizontalStretch * *(float *)&v1->Object;
				_TutControlE.p.x = HorizontalStretch * *(float *)&v1->Object;
			}
			else
			{
				TutorialTimer--;
			}

			if ((EntityData1Ptrs[0]->Status & Status_Ground || GetCharObj2(0)->JumpTime <= 60) && v1->InvulnerableTime == 0)
			{
				njDrawSprite2D_ForcePriority(&_TutControlE, 0, 22046.498f, NJD_SPRITE_ALPHA);
				
			}
			else if (GetCharObj2(0)->JumpTime > 60 && v1->InvulnerableTime == 0)
			{
				njDrawSprite2D_ForcePriority(&_TutFailE, 0, 22046.498f, NJD_SPRITE_ALPHA);
				v1->InvulnerableTime = 180;
			}
			else
			{
				njDrawSprite2D_ForcePriority(&_TutFailE, 0, 22046.498f, NJD_SPRITE_ALPHA);
			}
			njDrawSprite2D_ForcePriority(&_TutIntroE, 0, 22046.498f, NJD_SPRITE_ALPHA);
			break;
		default:
			if (TutorialTimer == 0)
			{
				_TutIntroE.p.x = HorizontalStretch * *(float *)&v1->LoopData;
				_TutFailE.p.x = HorizontalStretch * *(float *)&v1->Object;
				_TutControlE.p.x = HorizontalStretch * *(float *)&v1->Object;
			}
			else
			{
				TutorialTimer--;
			}

			if ((EntityData1Ptrs[0]->Status & Status_Ground || GetCharObj2(0)->JumpTime <= 60) && v1->InvulnerableTime == 0)
			{
				njDrawSprite2D_ForcePriority(&_TutControlE, 0, 22046.498f, NJD_SPRITE_ALPHA);

			}
			else if (GetCharObj2(0)->JumpTime > 60 && v1->InvulnerableTime == 0)
			{
				njDrawSprite2D_ForcePriority(&_TutFailE, 0, 22046.498f, NJD_SPRITE_ALPHA);
				v1->InvulnerableTime = 180;
			}
			else
			{
				njDrawSprite2D_ForcePriority(&_TutFailE, 0, 22046.498f, NJD_SPRITE_ALPHA);
			}
			break;
		}
		ClampGlobalColorThing_Thing();
	}
}

static void Tutorial_Main(ObjectMaster *a1)
{
	EntityData1 *v2;


	v2 = a1->Data1;

	///Action states: 1 = sliding in from sides, 2 = waiting for player to glide (normal mode), 3 = leaving after player glides
	if (GetCharObj2(0))
	{
		while (EntityData1Ptrs[0]->Position.x < -3180) //boxing the player in, like it's done in the actual AD
		{
			EntityData1Ptrs[0]->Position.x++;
		}
		while (EntityData1Ptrs[0]->Position.x > -3090)
		{
			EntityData1Ptrs[0]->Position.x--;
		}
		if (EntityData1Ptrs[0]->Position.y < 723)
		{
			EntityData1Ptrs[0]->Position.y = 760;
		}
		while (EntityData1Ptrs[0]->Position.z > -1371)
		{
			EntityData1Ptrs[0]->Position.z--;
		}
		while (EntityData1Ptrs[0]->Position.z < -1427)
		{
			EntityData1Ptrs[0]->Position.z++;
		}

		if ((*(float *)&v2->CharIndex >= 70 && v2->InvulnerableTime == 0) || CurrentCharacter != 3)
		{
			if (GetCharacterID(0) != 3)
			{
				DeleteObjectMaster(a1);
				EnablePause();
			}

			else if (a1->Data1->Action == 3) //moving out
			{
				*(float *)&v2->LoopData += 20;
				*(float *)&v2->Object -= 20;

				if (*(float *)&v2->LoopData >= 1240) //done moving out
				{
					DeleteObjectMaster(a1);
					EnablePause();
				}
				else
				{
					KnucklesTutorialDisplay(a1); //display
				}
			}
		}
		else if (GetCharacterID(0) == 3)
		{
			if (PauseEnabled) //setting up
			{
				DisablePause();
				*(float *)&v2->LoopData = 840;
				*(float *)&v2->Object = -420;
			}
			else
			{
				if (TutorialTimer == 0 && a1->Data1->Action == 0)
				{
					a1->Data1->Action = 1;
				}
			}

			if (a1->Data1->Action == 1) //moving in
			{
				*(float *)&v2->LoopData -= 40;
				*(float *)&v2->Object += 40;

				if (*(float *)&v2->LoopData <= (320 / HorizontalStretch) + 30 * (HorizontalStretch - 1))//(1152 / HorizontalResolution)) //&& *(float *)&v2->Object >= 210)
				{
					*(float *)&v2->LoopData = (320 / HorizontalStretch) + 30 * (HorizontalStretch - 1);//(1152 / HorizontalResolution);
					*(float *)&v2->Object = (320 / HorizontalStretch) + 30 * (HorizontalStretch - 1);//(1152 / HorizontalResolution);
					a1->Data1->Action = 2; //Done moving in
				}
			}
			
			if (v2->InvulnerableTime > 0) //if you failed, timer counts down
			{
				v2->InvulnerableTime -= 1;
			}

			else if (v2->InvulnerableTime < 0)
			{
				v2->InvulnerableTime = 0;
			}

			if (GetCharObj2(0)->AnimationThing.Index == 51 && v2->InvulnerableTime == 0 && a1->Data1->Action >= 2) //check if gliding
			{
				*(float *)&v2->CharIndex += 1;

				if (*(float *)&v2->CharIndex >= 70)
				{
					a1->Data1->Action = 3; //Player has successfully glided
					PlaySound(12, 0, 0, 0);
				}
			}
			else
			{
				*(float *)&v2->CharIndex = 0;
			}
			KnucklesTutorialDisplay(a1); //display
		}
	}
}

void Tutorial_Load(ObjectMaster *a1)
{
	a1->Data1->InvulnerableTime = 0;
	a1->Data1->Action = 0;
	a1->MainSub = (void(__cdecl *)(ObjectMaster *))Tutorial_Main;
	a1->DisplaySub = (void(__cdecl *)(ObjectMaster *))KnucklesTutorialDisplay;
	a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
}

void PropellorFanPosFix()
{
	njPushMatrix(0);
	njTranslate(0, 0, -0.7f, 0);
}

void __cdecl OMtKusa_Display_NEW(ObjectMaster *obj)
{
	EntityData1 *v1; // edi
	Angle v2; // eax
	double v3; // st7
	double v4; // st6

	v1 = obj->Data1;
	if (IsVisible(&v1->Position, 5.0))
	{
		njSetTexture(&OBJ_MOUNTAIN_TEXLIST);
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);
		v2 = v1->Rotation.y;
		if (v2)
		{
			njRotateY(0, (unsigned __int16)v2);
		}
		v3 = Camera_Data1->Position.z - v1->Position.z;
		v4 = Camera_Data1->Position.x - v1->Position.x;
		if (v4 * v4 + v3 * v3 >= 8400.0)
		{
			sub_407A00(&attach_0019D024, 1.0);
		}
		else
		{
			sub_405450(&stru_2465E8C, *(float *)&v1->CharIndex, 1.0);
		}
		njPopMatrix(1u);
	}
}

void __cdecl OMtKusa_Main_NEW(ObjectMaster *a1)
{
	EntityData1 *v1; // edi MAPDST

	v1 = a1->Data1;
	if (!ClipSetObject(a1))
	{
		if (v1->Action)
		{
			if (v1->Action == 1)
			{
				OMtKusa_Thing(a1);
				OMtKusa_Display_NEW(a1);
			}
			else if (v1->Action != 2)
			{
				v1->Action = 0;
			}
		}
		else
		{
			v1 = a1->Data1;
			v1->CharIndex = 0;
			a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
			a1->DisplaySub = OMtKusa_Display_NEW;
			v1->Action = 1;
		}
	}
}

void __cdecl Ghost_Turntofaceyou(ObjectMaster *a2)
{
	NJS_VECTOR direction;
	EntityData1 *v8;
	int v12;
	Sint16 v16;
	signed int v18;
	signed int v15;
	Sint16 v17;
	signed int v19;
	float v14;
	float v13;
	float v11;


	if (EntityData1Ptrs[0])
	{
		v8 = a2->Data1;

		if (v8->NextAction != 1)
		{
			direction.x = EntityData1Ptrs[0]->Position.x;
			direction.y = EntityData1Ptrs[0]->Position.y;
			direction.z = EntityData1Ptrs[0]->Position.z;
		}
		else
		{
			direction.x = v8->Scale.x;
			direction.y = v8->Scale.y;
			direction.z = v8->Scale.z;
		}
		direction.y = direction.y + GetCharObj2(0)->PhysicsData.CameraY;
		njSubVector(&direction, &a2->Data1->Position);
		v11 = direction.y;
		v12 = (unsigned __int64)(atan2(direction.x, direction.z) * 65536.0 * 0.1591549762031479);
		v13 = direction.z * direction.z + direction.x * direction.x + direction.y * direction.y;
		v14 = 1.0 / squareroot(v13);
		v15 = (unsigned __int64)(acos(v14 * 3.3499999) * 65536.0 * 0.1591549762031479) - (unsigned __int64)(acos(-(v14 * v11)) * 65536.0 * 0.1591549762031479);
		if (v15 <= 6144)
		{
			if (v15 < -6144)
			{
				v15 = -6144;
			}
		}
		else
		{
			v15 = 6144;
		}
		v16 = a2->Data1->Rotation.y;
		v17 = a2->Data1->Rotation.x;
		v18 = (signed __int16)(v12 - v16);
		v19 = (signed __int16)(v15 - v17);
		if (v18 <= 500)
		{
			if (v18 >= -500)
			{
				a2->Data1->Rotation.y = (Angle)v12;
			}
			else
			{
				a2->Data1->Rotation.y = (Angle)(v16 - 600);
			}
		}
		else
		{
			a2->Data1->Rotation.y = (Angle)(v16 + 600);
		}
		if (v19 <= 300)
		{
			if (v19 >= -300)
			{
				a2->Data1->Rotation.x = (Angle)v15;
			}
			else
			{
				a2->Data1->Rotation.x = (Angle)(v17 - 600);
			}
			AddToCollisionList(v8);
		}
		else
		{
			a2->Data1->Rotation.x = (Angle)(v17 + 600);
			AddToCollisionList(v8);
		}
	}
}

void __cdecl Ghost_Display_Fade_Alt(ObjectMaster *a2)
{
	EntityData1 *v1; // esi@1
	ObjectMaster *a3; // ST08_4@1
	Angle v3; // eax@3
	Angle v6;
	Angle v7;

	v1 = a2->Data1;
	a3 = a2;
	if (!ClipSetObject(a3) && !MissedFrames)
	{
		SetTextureToLevelObj();
		njPushMatrix(0);
		object_GreenGhost_AD.basicdxmodel->normals = normal_SomethingOther;
		njTranslate(0, v1->Position.x, v1->Position.y, v1->Position.z);
		v3 = v1->Rotation.y;
		if (v3)
		{
			njRotateY(0, (unsigned __int16)v3);
		}
		njAction(&BetaGhost_Anim, *(float *)&v1->CharIndex);
		njPopMatrix(1u);
		object_GreenGhost_AD.basicdxmodel->normals = normal_0014F7BC;
	}
}

void __cdecl Ghost_Main_Alt(ObjectMaster *a1)
{
	EntityData1 *v1;

	v1 = a1->Data1;

	if (!ClipSetObject(a1))
	{
		Ghost_Turntofaceyou(a1);
		if (!ObjectSelectedDebug(a1) && !IsGamePaused())
		{
			*(float*)&v1->CharIndex = 0.5f + *(float*)&v1->CharIndex;
			v1->Position.y += 2;
		}

		Ghost_Display_Fade_Alt(a1);

		if (*(float*)&v1->CharIndex >= 30.0)
		{
			*(float*)&v1->CharIndex = 0.0;
		}
		if (v1->Position.y >= 770)//(a1->SETData.SETData->SETEntry->Position.y + 800))
		{
			v1->Position.y = a1->SETData.SETData->SETEntry->Position.y;
		}
	}
}

void __cdecl Ghost_Display_Fade(ObjectMaster *a2)
{
	EntityData1 *v1; // esi@1
	ObjectMaster *a3; // ST08_4@1
	Angle v3; // eax@3
	Angle v6;
	Angle v7;

	v1 = a2->Data1;
	a3 = a2;
	if (!ClipSetObject(a3) && !MissedFrames)
	{
		SetTextureToLevelObj();
		njPushMatrix(0);
		object_GreenGhost_AD.basicdxmodel->mats = matlist_0014EFE8_vanish;
		object_GreenGhost_AD.basicdxmodel->mats[0].diffuse.argb.a = *(Uint8*)&v1->LoopData;
		object_GreenGhost_AD.basicdxmodel->mats[1].diffuse.argb.a = *(Uint8*)&v1->LoopData;
		object_GreenGhost_AD.basicdxmodel->normals = normal_SomethingOther;
		njTranslate(0, v1->Position.x, v1->Position.y, v1->Position.z);
		v3 = v1->Rotation.y;
		if (v3)
		{
			njRotateY(0, (unsigned __int16)v3);
		}
		njAction(&BetaGhost_Anim, *(float *)&v1->CharIndex);
		njPopMatrix(1u);
		object_GreenGhost_AD.basicdxmodel->mats[0].diffuse.argb.a = 255;
		object_GreenGhost_AD.basicdxmodel->mats[1].diffuse.argb.a = 255;
		object_GreenGhost_AD.basicdxmodel->mats = matlist_0014EFE8;
		object_GreenGhost_AD.basicdxmodel->normals = normal_0014F7BC;
	}
}

void __cdecl Ghost_Display(ObjectMaster *a2)
{
	EntityData1 *v1; // esi@1
	ObjectMaster *a3; // ST08_4@1
	Angle v3; // eax@3
	Angle v6;
	Angle v7;

	v1 = a2->Data1;
	a3 = a2;
	if (!ClipSetObject(a3) && !MissedFrames)
	{
		SetTextureToLevelObj();
		njPushMatrix(0);
		if (*(Uint8*)&v1->LoopData < 128)
		{
			object_GreenGhost_AD.basicdxmodel->mats = matlist_0014EFE8_vanish;
			object_GreenGhost_AD.basicdxmodel->mats[0].diffuse.argb.a = *(Uint8*)&v1->LoopData;
			object_GreenGhost_AD.basicdxmodel->mats[1].diffuse.argb.a = *(Uint8*)&v1->LoopData;
		}
		njTranslate(0, v1->Position.x, v1->Position.y, v1->Position.z);
		v3 = v1->Rotation.y;
		if (v3)
		{
			njRotateY(0, (unsigned __int16)v3);
		}
		v6 = v1->Rotation.x;
		if (v6)
		{
			njRotateX(0, (unsigned __int16)v6);
		}
		sub_409E70((NJS_MODEL_SADX*)object_GreenGhost_AD.model, 0, 1.0);
		njPopMatrix(1u);
		if (*(Uint8*)&v1->LoopData < 128)
		{
			//object_GreenGhost_AD.basicdxmodel->mats[0].diffuse.argb.a = 255;
			//object_GreenGhost_AD.basicdxmodel->mats[1].diffuse.argb.a = 255;
			object_GreenGhost_AD.basicdxmodel->mats = matlist_0014EFE8;
		}
	}
}

void __cdecl Ghost_Display_Attack(ObjectMaster *a2)
{
	EntityData1 *v1; // esi@1
	ObjectMaster *a3; // ST08_4@1
	Angle v3; // eax@3
	Angle v6;
	Angle v7;

	v1 = a2->Data1;
	a3 = a2;
	if (!ClipSetObject(a3) && !MissedFrames)
	{
		SetTextureToLevelObj();
		njPushMatrix(0);
		object_GreenGhost_AD.basicdxmodel->points = vertex_Lunging;
		object_GreenGhost_AD.basicdxmodel->normals = normal_Something;
		njTranslate(0, v1->Position.x, v1->Position.y, v1->Position.z);
		v3 = v1->Rotation.y;
		if (v3)
		{
			njRotateY(0, (unsigned __int16)v3);
		}
		sub_409E70((NJS_MODEL_SADX*)object_GreenGhost_AD.model, 0, 1.0);
		njPopMatrix(1u);
		object_GreenGhost_AD.basicdxmodel->points = vertex_0014F450;
		object_GreenGhost_AD.basicdxmodel->normals = normal_0014F7BC;
	}
}

void __cdecl Ghost_Main(ObjectMaster *a1)
{
	EntityData1 *v1;
	float movespeed = 0;
	float floatingspeed = 0;
	float posit = a1->Data1->Position.y;
	float spawnpos = a1->SETData.SETData->SETEntry->Position.y;
	float destin = spawnpos - 2.0f;
	double dist = 0;

	//NextAction states:
	//0 = neutral, floating, watching
	//1 = attacking
	//2 = fading/stretching (After attacking)

	v1 = a1->Data1;

	switch ((int)v1->NextAction)
	{
	case 0:
		Ghost_Turntofaceyou(a1);

		if (*(Uint8*)&v1->LoopData < 128)
		{
			*(Uint8*)&v1->LoopData += 4;
		}
		//sub_5BBB60((int)a1, v7, v6, v5, v4, v3, v2, v8);

		//floating code:
		for (double i = (double)spawnpos; i > (double)destin; i -= 0.01)
		{
			dist += 0.01;
		}

		floatingspeed = njSin(0x7D) * a1->Data1->Rotation.z;

		if (floatingspeed < 0)
		{
			floatingspeed = floatingspeed * -1;
		}

		while (floatingspeed > 1)
		{
			floatingspeed -= 0.1;
		}

		if (!ClipSetObject(a1))
		{
			if (v1->InvulnerableTime == 0)
			{
				if (posit < spawnpos)
				{
					a1->Data1->Position.y += floatingspeed;
					a1->Data1->Scale.x += floatingspeed;
					if (a1->Data1->Scale.z == 0)
					{
						a1->Data1->Rotation.z++;
					}
					else
					{
						a1->Data1->Rotation.z--;
					}
				}
				else
				{
					a1->Data1->Position.y = spawnpos;
					a1->Data1->InvulnerableTime = 1; //state (Moving up or down?)
					a1->Data1->Rotation.z = 0;
					a1->Data1->Scale.x = 0;
					a1->Data1->Scale.z = 0;
				}
			}
			else
			{
				if (posit > destin)
				{
					a1->Data1->Position.y -= floatingspeed;
					a1->Data1->Scale.x += floatingspeed;
					if (a1->Data1->Scale.z == 0)
					{
						a1->Data1->Rotation.z++;
					}
					else
					{
						a1->Data1->Rotation.z--;
					}
				}
				else
				{
					a1->Data1->Position.y = destin;
					a1->Data1->InvulnerableTime = 0; //state
					a1->Data1->Rotation.z = 0;
					a1->Data1->Scale.x = 0;
					a1->Data1->Scale.z = 0;
				}
			}

			if (a1->Data1->Scale.x >= (dist / 2.0) && a1->Data1->Scale.z != 1)
			{
				a1->Data1->Scale.z = 1;
				a1->Data1->Scale.x = (dist / 2.0);
				a1->Data1->Rotation.z--;
				a1->Data1->Position.y = (spawnpos - (dist / 2.0));
			}
		}
		Ghost_Display(a1);
		if (IsVisible(&a1->Data1->Position, 4.643425f) && IsPlayerInsideSphere(&a1->Data1->Position, 500.0f) && (EntityData1Ptrs[0]->Position.y - a1->Data1->Position.y < 30.0f) && (EntityData1Ptrs[0]->Position.y - a1->Data1->Position.y > -60.0f))
		{
			*(float*)&v1->CharIndex += 2.0f;
		}
		else
		{
			if (*(float*)&v1->CharIndex > 0.0f)
			{
				*(float*)&v1->CharIndex -= 1.0f;
			}
		}

		if (*(float*)&v1->CharIndex >= 600.0f)
		{
			v1->NextAction = 1;
			a1->DisplaySub = Ghost_Display_Attack;
			*(float*)&v1->CharIndex = 0.0;
			a1->Data1->Scale.x = (int)EntityData1Ptrs[0]->Position.x;
			a1->Data1->Scale.y = (int)EntityData1Ptrs[0]->Position.y + 12;
			a1->Data1->Scale.z = (int)EntityData1Ptrs[0]->Position.z;
			if (a1->Data1->Scale.x == 0)
			{
				a1->Data1->Scale.x = 1;
			}
			if (a1->Data1->Scale.z == 0)
			{
				a1->Data1->Scale.z = 1;
			}
			if (a1->Data1->Scale.z == 0)
			{
				a1->Data1->Scale.z = 1;
			}
		}
		if (IsPlayerInsideSphere(&a1->Data1->Position, 8.4f))
		{
			v1->NextAction = 2;
			*(float*)&v1->CharIndex = 0.0;
			*(Uint8*)&v1->LoopData = 128;
			a1->DisplaySub = Ghost_Display_Fade;
		}
		break;
	case 1:
		movespeed = njSin(0x7D) * 85;

		//moving ghost to recorded player position
		if ((int)a1->Data1->Position.x < a1->Data1->Scale.x)
		{
			a1->Data1->Position.x += movespeed;
		}
		else if ((int)a1->Data1->Position.x > a1->Data1->Scale.x)
		{
			a1->Data1->Position.x -= movespeed;
		}

		if ((int)a1->Data1->Position.y < a1->Data1->Scale.y)
		{
			a1->Data1->Position.y += (movespeed / 2.0f);
		}
		else if ((int)a1->Data1->Position.y > a1->Data1->Scale.y)
		{
			a1->Data1->Position.y -= (movespeed / 2.0f);
		}

		if ((int)a1->Data1->Position.z < a1->Data1->Scale.z)
		{
			a1->Data1->Position.z += movespeed;
		}
		else if ((int)a1->Data1->Position.z > a1->Data1->Scale.z)
		{
			a1->Data1->Position.z -= movespeed;
		}

		if (sqrt((a1->Data1->Position.x - a1->Data1->Scale.x) * (a1->Data1->Position.x - a1->Data1->Scale.x) + (a1->Data1->Position.y - a1->Data1->Scale.y) * (a1->Data1->Position.y - a1->Data1->Scale.y) + (a1->Data1->Position.z - a1->Data1->Scale.z) * (a1->Data1->Position.z - a1->Data1->Scale.z)) <= 60)
		{
			a1->Data1->Scale.x = (int)EntityData1Ptrs[0]->Position.x;
			a1->Data1->Scale.y = (int)EntityData1Ptrs[0]->Position.y + 12;
			a1->Data1->Scale.z = (int)EntityData1Ptrs[0]->Position.z;

			if (a1->Data1->Scale.x == 0)
			{
				a1->Data1->Scale.x = 1;
			}

			if (a1->Data1->Scale.z == 0)
			{
				a1->Data1->Scale.z = 1;
			}

			if (a1->Data1->Scale.z == 0)
			{
				a1->Data1->Scale.z = 1;
			}
		}
		Ghost_Turntofaceyou(a1);
		Ghost_Display_Attack(a1);
		if (IsPlayerInsideSphere(&a1->Data1->Position, 8.4f))
		{
			v1->NextAction = 2;
			*(float*)&v1->CharIndex = 0.0;
			*(Uint8*)&v1->LoopData = 128;
			a1->DisplaySub = Ghost_Display_Fade;
		}
		break;
	case 2:
		if (!ClipSetObject(a1))
		{
			if (!ObjectSelectedDebug(a1) && !IsGamePaused())
			{
				Ghost_Turntofaceyou(a1);
				*(float*)&v1->CharIndex = 1.0f + *(float*)&v1->CharIndex;
				if ((*(Uint8*)&v1->LoopData - 4) > -1)
				{
					*(Uint8*)&v1->LoopData -= 4;
				}
			}
			Ghost_Display_Fade(a1);
			if (*(float*)&v1->CharIndex >= 30.0)
			{
				*(float*)&v1->CharIndex = 0.0;
				DeleteObjectMaster(a1);
			}
		}
		break;
	case 3:
		*(Uint8*)&v1->LoopData = v1->Scale.z;
		v1->NextAction = 0;
		break;
	default:
		break;
	}
}

void __cdecl Load_Ghost(ObjectMaster *a1)
{
	EntityData1 *v1;

	v1 = a1->Data1;

	v1->Object = &object_GreenGhost_AD;
	a1->Data1->Rotation.x = 0;
	a1->Data1->Rotation.z = 0;
	v1->CharIndex = 0;
	if (a1->Data1->Scale.x == 1)
	{
		a1->MainSub = Ghost_Main_Alt;
		a1->DisplaySub = Ghost_Display_Fade_Alt;
		a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
	}
	else
	{
		InitCollision(a1, (CollisionData*)&Ghost_Collision, 1, 4u);
		a1->Data1->Scale.x = 0;
		a1->Data1->Scale.y = 0;
		a1->Data1->Scale.z = 0;
		v1->NextAction = 3;
		v1->InvulnerableTime = 0;

		a1->MainSub = Ghost_Main;
		a1->DisplaySub = Ghost_Display;
		a1->DeleteSub = (void(__cdecl *)(ObjectMaster *))nullsub;
	}
}

void __cdecl GreenFenceCollision(ObjectMaster *a2, CollisionData *c1, int b1, unsigned __int8 list)
{
	if (GetCurrentCharacterID() == Characters_Sonic && (greenfencecheat == true && !AlwaysFence))
	{
		*(Sint32 *)&a2->Data1->CharIndex = (Sint32)&object_OSaku_AD;
		InitCollision(a2, stru_24C8F90, 1, 4u);
		a2->Data1->CollisionInfo->CollisionArray->scale.x = 85.0f;
		a2->Data1->CollisionInfo->CollisionArray->scale.y = 12.0f;
		a2->Data1->CollisionInfo->CollisionArray->scale.z = 2.5f;
	}

	else
	{
		InitCollision(a2, stru_24C8F90, 1, 4u);
	}
}

void __cdecl OHanamaSmaller_Display(ObjectMaster *a2)
{
	EntityData1 *v1; // esi@1
	Angle v2;
	Angle v3;
	Angle v4; // eax@6
	Angle v5; // eax@7

	v1 = a2->Data1;
	if (!MissedFrames)
	{
		SetTextureToLevelObj();
		njPushMatrix(0);
		njTranslateV(0, &v1->Position);

		v2 = v1->Rotation.z;
		//if (v2)
		//{
		//	njRotateZ(0, (unsigned __int16)v2);
		//}

		//v3 = v1->Rotation.x;
		//if (v3)
		//{
		//	njRotateX(0, (unsigned __int16)v3);
		//}
		v4 = v1->Rotation.y;
		if (v4)
		{
			njRotateY(0, (unsigned __int16)v4);
		}
		njScale(0, object_SmallHammer_AD.scl[0], object_SmallHammer_AD.scl[1], object_SmallHammer_AD.scl[2]);
		sub_409E70((NJS_MODEL_SADX*)object_SmallHammer_AD.model, 0, 1.0);
		njPushMatrix(0);
		njTranslate(0, object_0016667C.pos[0], object_0016667C.pos[1], 0);
		v5 = v1->Rotation.x;
		if (v5)
		{
			njRotateX(0, (unsigned __int16)v5);
		}
		njScale(0, object_0016667C.scl[0], object_0016667C.scl[1], object_0016667C.scl[2]);
		sub_409E70((NJS_MODEL_SADX*)object_0016667C.model, 0, 1.0);
		njPopMatrix(1u);
		if (a2->Data1->Scale.y >= 2)
		{
			njPushMatrix(0);
			njTranslate(0, object_0016667C.pos[0], object_0016667C.pos[1], 0);
			v5 = v1->Rotation.x;
			if (v5)
			{
				njRotateX(0, (unsigned __int16)v5 + 0x8000);
			}
			njScale(0, object_0016667C.scl[0], object_0016667C.scl[1], object_0016667C.scl[2]);
			sub_409E70((NJS_MODEL_SADX*)object_0016667C.model, 0, 1.0);
			njPopMatrix(1u);
			if (a2->Data1->Scale.y >= 3)
			{
				njPushMatrix(0);
				njTranslate(0, object_0016667C.pos[0], object_0016667C.pos[1], 0);
				v5 = v1->Rotation.x;
				if (v5)
				{
					njRotateX(0, (unsigned __int16)v5 + 0x4000);
				}
				njScale(0, object_0016667C.scl[0], object_0016667C.scl[1], object_0016667C.scl[2]);
				sub_409E70((NJS_MODEL_SADX*)object_0016667C.model, 0, 1.0);
				njPopMatrix(1u);
				if (a2->Data1->Scale.y >= 4)
				{
					njPushMatrix(0);
					njTranslate(0, object_0016667C.pos[0], object_0016667C.pos[1], 0);
					v5 = v1->Rotation.x;
					if (v5)
					{
						njRotateX(0, (unsigned __int16)v5 + 0xC000);
					}
					njScale(0, object_0016667C.scl[0], object_0016667C.scl[1], object_0016667C.scl[2]);
					sub_409E70((NJS_MODEL_SADX*)object_0016667C.model, 0, 1.0);
					njPopMatrix(1u);
				}
			}
		}
		njPopMatrix(1u);
	}
}

void __cdecl OHanamaSmaller_Main(ObjectMaster *a1)
{
	EntityData1 *v1; // esi@1

	v1 = a1->Data1;
	v1->Rotation.x = 0;
	v1->Rotation.z = 0;

	if (!ClipSetObject(a1))
	{
		if (v1->Action)
		{
			if (v1->Action == 1)
			{
				if (v1->Scale.x != 0)
				{
					*(float*)&v1->CharIndex = v1->Scale.x + *(float*)&v1->CharIndex;
					a1->Data1->Rotation.x = *(float*)&v1->CharIndex * 65536.0 * 0.002777777777777778;
				}
				else
				{
					*(float*)&v1->CharIndex = -3.7f + *(float*)&v1->CharIndex;
					a1->Data1->Rotation.x = *(float*)&v1->CharIndex * 65536.0 * 0.002777777777777778;
				}
				AddToCollisionList(v1);
				OHanamaSmaller_Display(a1);
			}
		}
		else
		{
			v1->Action = 1;
			a1->Data1->Rotation.y = 0;
			a1->DisplaySub = OHanamaSmaller_Display;
			if (a1->Data1->Scale.y <= 1)
			{
				InitCollision(a1, SmallHam1_Collision, 2, 4u);
			}
			else if (a1->Data1->Scale.y == 2)
			{
				InitCollision(a1, SmallHam2_Collision, 4, 4u);
			}
			else if (a1->Data1->Scale.y == 3)
			{
				InitCollision(a1, SmallHam3_Collision, 6, 4u);
			}
			else
			{
				InitCollision(a1, SmallHam4_Collision, 8, 4u);
			}
		}
	}
}

ObjectListEntry	RedMountainObjectList_list[] = { //increasing draw distance for some static objects
	{ 2, 3, 0, 0, 0, Ring_Main, "RING" },
	{ 2, 2, 0, 0, 0, Spring_Main, "SPRING" },
	{ 2, 2, 0, 0, 0, SpringB_Main, "SPRINGB" },
	{ 3, 3, 0, 0, 0, DashPanel_Main, "O AXPNL" },
	{ 6, 3, 0, 0, 0, SwingSpikeBall_Load, "O IRONB" },
	{ 2, 3, 0, 0, 0, FallingSpikeBall_Load, "O FeBJG" },
	{ 2, 3, 0, 0, 0, Spikes_Main, "O TOGE" },
	{ 3, 3, 0, 0, 0, EmeraldPiece_Load, "O EME P" },
	{ 2, 3, 0, 0, 0, Capsule_Load, "O RELEASE" },
	{ 6, 3, 0, 0, 0, Switch_Main, "O SWITCH" },
	{ 10, 3, 0, 0, 0, Weed_Main, "CMN KUSA" },
	{ 14, 3, 0, 0, 0, DashHoop_Main, "CMN_DRING" },
	{ 2, 3, 0, 0, 0, Balloon_Main, "O BALOON" },
	{ 2, 3, 0, 0, 0, ItemBox_Main, "O ITEMBOX" },
	{ 14, 2, 0, 0, 0, RocketH_Main, "Rocket H" },
	{ 14, 2, 0, 0, 0, RocketHS_Main, "Rocket HS" },
	{ 14, 2, 0, 0, 0, RocketV_Main, "Rocket V" } ,
	{ 14, 2, 0, 0, 0, RocketVS_Main, "Rocket VS" },
	{ 2, 2, 1, 4000000, 0, JumpPanel_Load, "O JPanel" },
	{ 15, 6, 0, 0, 0, CheckPoint_Main, "O Save Point" },
	{ 2, 3, 0, 0, 0, Wall_Main, "WALL" },
	{ 2, 3, 1, 1000000, 0, (ObjectFuncPtr)0x004CBDE0, "O DYNAMITE" },
	{ 6, 3, 0, 0, 0, (ObjectFuncPtr)0x0060EE00, "o_honoo" },
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x0060EA70, "o_komokosu" },
	{ 6, 3, 1, 2.5E+07, 0, (ObjectFuncPtr)0x00602670, "o_yougan" },
	{ 2, 3, 1, 998001, 0, (ObjectFuncPtr)0x0060E8B0, "o_untei1" }, //draw increase
	{ 2, 3, 1, 998001, 0, (ObjectFuncPtr)0x0060E8F0, "o_untei2" }, //draw increase
	{ 2, 3, 1, 998001, 0, (ObjectFuncPtr)0x0060E930, "o_untei3" }, //draw increase
	{ 2, 3, 1, 998001, 0, (ObjectFuncPtr)0x0060E980, "o_untei6" }, //draw increase
	{ 2, 3, 1, 598001, 0, (ObjectFuncPtr)0x0060DD50, "O HAKA" }, //draw increase
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x0060DD80, "O CHAIR" },
	{ 2, 3, 1, 498001, 0, (ObjectFuncPtr)0x0060E410, "O BONEHEAD" }, //draw increase
	{ 2, 3, 1, 498001, 0, (ObjectFuncPtr)0x0060E4D0, "O BONESTICK" }, //draw increase
	{ 6, 3, 1, 438401, 0, (ObjectFuncPtr)0x0060E150, "O MASIBA" },
	{ 2, 3, 1, 598001, 0, (ObjectFuncPtr)0x0060D810, "O GRAVE" }, //draw increase
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x0060CB20, "O LIGHT" },
	{ 2, 3, 1, 598001, 0, (ObjectFuncPtr)0x0060D570, "O PIPEI" }, //draw increase
	{ 2, 3, 1, 598001, 0, (ObjectFuncPtr)0x0060D5F0, "O PIPEL" }, //draw increase
	{ 2, 3, 1, 598001, 0, (ObjectFuncPtr)0x0060D5B0, "O PIPEBOX" }, //draw increase
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x0060D4F0, "O VENT" },
	{ 3, 3, 1, 998001, 0, (ObjectFuncPtr)0x0060D260, "O HANMA" },
	{ 2, 3, 1, 249001, 0, (ObjectFuncPtr)0x00605DF0, "O SAKU" },
	{ 2, 6, 1, 249001, 0, (ObjectFuncPtr)0x00605E40, "O SAKU2" },
	{ 2, 3, 1, 360000, 0, (ObjectFuncPtr)0x00605E90, "O ROUYA" },
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x0060CAF0, "O LIGHTB" },
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x0060C820, "OGL" },
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x00601EB0, "Ex Rock" },
	{ 7, 3, 0, 0, 0, (ObjectFuncPtr)0x0060C640, "O Erupt" },
	{ 2, 3, 1, 1000000, 0, (ObjectFuncPtr)0x0060B390, "O GEAR" },
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x0060B1E0, "O RELAY P" },
	{ 2, 3, 1, 558001, 0, (ObjectFuncPtr)0x0060B080, "O SIGNBOARD" }, //draw increase
	{ 6, 3, 1, 998001, 0, (ObjectFuncPtr)0x0060AFC0, "O PROPELLER" },
	{ 2, 3, 1, 638401, 0, (ObjectFuncPtr)0x0060A9F0, "O BREAKSTEP" },
	{ 2, 3, 1, 638401, 0, (ObjectFuncPtr)0x00609F00, "O BREAKSTEP2" },
	{ 10, 3, 0, 0, 0, (ObjectFuncPtr)0x00609360, "Mtn SpiderA" },
	{ 3, 3, 0, 0, 0, (ObjectFuncPtr)0x00609560, "Mtn SpiderB" },
	{ 2, 3, 1, 698001, 0, (ObjectFuncPtr)0x00607BA0, "O TREE1" }, //draw increase
	{ 6, 3, 0, 0, 0, (ObjectFuncPtr)0x006089B0, "O Futa" },
	{ 6, 3, 0, 0, 0, (ObjectFuncPtr)0x00608730, "MagmaCnt" },
	{ 6, 3, 1, 62500, 0, (ObjectFuncPtr)0x006085B0, "Syuujin b" },
	{ 6, 3, 1, 62500, 0, (ObjectFuncPtr)0x00608630, "Syuujin r" },
	{ 6, 3, 1, 62500, 0, (ObjectFuncPtr)0x006086B0, "Syuujin g" },
	{ 3, 3, 1, 898001, 0, OMtKusa_Main_NEW, "O MT KUSA" }, //increased draw distance
	{ 6, 3, 1, 640000, 0, (ObjectFuncPtr)0x006080D0, "O TURI1" },
	{ 6, 3, 1, 640000, 0, (ObjectFuncPtr)0x006080F0, "O TURI2" },
	{ 6, 3, 1, 640000, 0, (ObjectFuncPtr)0x00608110, "O TURI3" },
	{ 6, 3, 1, 640000, 0, (ObjectFuncPtr)0x00608130, "O TURI4" },
	{ 6, 3, 1, 998001, 0, (ObjectFuncPtr)0x00607F60, "O ASIBA1" }, //draw increase
	{ 2, 3, 1, 698001, 0, (ObjectFuncPtr)0x00607CB0, "O TREE2" }, //draw increase
	{ 15, 3, 1, 40000, 0, (ObjectFuncPtr)0x006077D0, "O Bat" },
	{ 2, 3, 1, 998001, 0, (ObjectFuncPtr)0x00605EE0, "MT_SOTO" }, //draw increase
	{ 2, 3, 1, 498001, 0, (ObjectFuncPtr)0x00605F00, "MT_TBOX" }, //draw increase
	{ 6, 3, 0, 0, 0, (ObjectFuncPtr)0x00606F20, "O HAGO" },
	{ 6, 3, 1, 638401, 0, (ObjectFuncPtr)0x00603F80, "O ZAKO" },
	{ 6, 3, 1, 638401, 0, (ObjectFuncPtr)0x00603FF0, "O ZAKO_B" },
	{ 6, 3, 1, 810000, 0, (ObjectFuncPtr)0x00606B20, "O DEKA" },
	{ 2, 3, 1, 558001, 0, (ObjectFuncPtr)0x00606820, "O LAMP1" }, //draw increase
	{ 2, 3, 1, 558001, 0, (ObjectFuncPtr)0x00606840, "O LAMP2" }, //draw increase
	{ 3, 3, 1, 1000000, 0, (ObjectFuncPtr)0x006063B0, "O HATAKI" },
	{ 6, 3, 1, 998001, 0, (ObjectFuncPtr)0x00602960, "O MYOUGAN" },
	{ 2, 3, 1, 998001, 0, (ObjectFuncPtr)0x00605F50, "MT_TSAKU" }, //draw increase
	{ 2, 3, 1, 10000, 0, (ObjectFuncPtr)0x00605C50, "O BLOW" },
	{ 2, 3, 1, 10000, 0, (ObjectFuncPtr)0x00605D40, "O BLOW2" },
	{ 2, 3, 5, 250000, 0, (ObjectFuncPtr)0x004AD140, "E SARU" },
	{ 2, 3, 4, 0, 0, (ObjectFuncPtr)0x004B0DF0, "SPINA A" },
	{ 2, 3, 4, 0, 0, (ObjectFuncPtr)0x004B0F40, "SPINA B" },
	{ 2, 3, 5, 250000, 0, (ObjectFuncPtr)0x004AF860, "E UNI C" },
	{ 2, 3, 0, 0, 0, (ObjectFuncPtr)0x007A9140, "O KN HINT" },
	{ 2, 3, 1, 2.5E+07, 0, (ObjectFuncPtr)0x006028B0, "O YE102" },
	{ 2, 3, 1, 4000000, 0, (ObjectFuncPtr)0x00605B40, "E E_104" },
	{ 2, 2, 0, 0, 0, (ObjectFuncPtr)0x004D4700, "C SPHERE" },
	{ 2, 2, 0, 0, 0, (ObjectFuncPtr)0x004D4770, "C CYLINDER" },
	{ 2, 2, 0, 0, 0, (ObjectFuncPtr)0x004D47E0, "C CUBE" },
	{ 2, 2, 0, 0, 0, (ObjectFuncPtr)0x004D4B70, "OTTOTTO" },
	{ 2, 2, 0, 0, 0, (ObjectFuncPtr)0x007A1AA0, "O TIKAL" }, //where the AD object list cuts off
	{ 15, 3, 0, 0, 0, (ObjectFuncPtr)0x004C07D0, "O ItemBoxAir" },
	{ 6, 3, 1, 650000, 0, (ObjectFuncPtr)0x006042A0, "O BPOLE" }, //draw increased further
	{ 2, 3, 1, 1000000, 0, Load_Ghost, "O GHOST" }, //custom object based on the ghost model and its animation data in the AD
	{ 2, 3, 1, 998001, 0, OHanamaSmaller_Main, "O SPINHANMA" } //custom object using model of a unused smaller hammer from the AD that is unusable due to how it's set up, so I repurposed it here
};

ObjectList RedMountainObjectList = { arraylengthandptrT(RedMountainObjectList_list, int) };

PointerInfo pointers[] = {

	ptrdecl(0x90EB7C, &RedMountainObjectTextures),

	ptrdecl(0x974B98, &RedMountainObjectList),
	ptrdecl(0x974B9C, &RedMountainObjectList),
	ptrdecl(0x974BA0, &RedMountainObjectList),
};

//PathDataPtr RM1PathList = { levelact(LevelIDs_RedMountain, 0), PathList_RedMountain0 };
//PathDataPtr RM3PathList = { levelact(LevelIDs_RedMountain, 2), PathList_RedMountain2 };


void Init(const char *path, const HelperFunctions &helperFunctions)
{
	//Replacing PVM Files
	ReplacePVMFile("OBJ_MOUNTAIN", "OBJ_MOUNTAIN_AD");
	ReplacePVMFile("MOUNTAIN_E104", "MOUNTAIN_E104_AD");
	ReplacePVMFile("MOUNTAIN_MEXPLOSION", "MOUNTAIN_MEXPLOSION_AD");
	ReplacePVMFile("MOUNTAIN_STEAM", "MOUNTAIN_STEAM_AD");
	ReplacePVMFile("MOUNTAIN01", "MOUNTAIN01_AD");
	ReplacePVMFile("MOUNTAIN02", "MOUNTAIN02_AD");
	ReplacePVMFile("MOUNTAIN03", "MOUNTAIN03_AD");
	ReplacePVMFile("YOUGAN_ANIM", "YOUGAN_ANIM_AD");

	//Replacing BIN Files
	ReplaceBINFile("SET0500S", "SET0500S_AD");
	ReplaceBINFile("SET0501S", "SET0501S_AD");
	ReplaceBINFile("SET0501E", "SET0501E_AD");
	ReplaceBINFile("SET0502K", "SET0502K_AD");
	ReplaceBINFile("CAM0500S", "CAM0500S_AD");

	const IniFile *config = new IniFile(std::string(path) + "\\config.ini");
	ADSetFile = config->getBool("Options", "ADSetFile", false);
	if (ADSetFile)
	{
		ReplaceBINFile("SET0500S", "SET0500S_Orig");
		ReplaceBINFile("SET0501S", "SET0501S_Orig");
		ReplaceBINFile("SET0501E", "SET0501E_Orig");
		ReplaceBINFile("SET0502K", "SET0502K_Orig");
	}
	ADCamFile = config->getBool("Options", "ADCamFile", false);
	if (ADCamFile)
	{
		ReplaceBINFile("CAM0500S", "CAM0500S_Orig");
		ReplaceBINFile("CAM0501S", "CAM0501S_Orig");
		ReplaceBINFile("CAM0501E", "CAM0501E_Orig");
		//ReplaceOrigFile("CAM0502K", "CAM0502K_Orig"); //Doesn't work right. Just gets stuck inside of Knuckles. There really isn't much difference between the AD's CAM and the final's CAM anyway...
	}
	KnucklesTutorial = config->getBool("Options", "KnucklesTutorial", false);
	AlwaysGreenLight = config->getBool("Options", "AlwaysGreenLight", false);
	AlwaysCloudLayer = config->getBool("Options", "AlwaysCloudLayer", false);
	AlwaysFloorLight = config->getBool("Options", "AlwaysFloorLight", false);
	AlwaysFence = config->getBool("Options", "AlwaysFence", false);
	delete config;

	WriteData((LandTable**)0x97DAA8, &landtable_00019038); //Act 1
	WriteData((LandTable**)0x97DAAC, &landtable_0001AC80);
	WriteData((LandTable**)0x97DAB0, &landtable_0001E6E0);


	WriteData((LoopHead*)0x024C31A8, PathList_RedMountain0); //Act 1 //Getting the splines to work. This is needed to restore Gamma's splines (Some of them don't work right in the final, or at all, but do in the AD)
	WriteData((LoopHead*)0x024C31B4, PathList_RedMountain1); //Act 2

	//from PkR:
	WriteCall((void*)0x006011D8, RenderRMSky1);
	WriteCall((void*)0x0060121C, RenderRMSky2);
	WriteData<1>((void*)0x0060C981, 0x03); //Light thing blending mode
	//WriteData((float*)0x006011ED, 30.0f); //Cloud height (Knuckles)
	//WriteData((float*)0x006011A9, 60.0f); //Cloud height (Knuckles) //Don't need these. DX's cloud heights are the AD's!
	WriteData((double**)0x600C8F, &cloudcoloroffset);

	WriteCall((void*)0x0060AC6F, PropellorFanPosFix);

	WriteCall((void*)0x00605E1E, GreenFenceCollision);


	ResizeTextureList(&OBJ_MOUNTAIN_TEXLIST, 100);
	//ResizeTextureList(&MOUNTAIN01_TEXLIST, 45);
	//ResizeTextureList(&MOUNTAIN02_TEXLIST, 46);
	//ResizeTextureList(&MOUNTAIN03_TEXLIST, 27);


	for (unsigned int i = 0; i < 3; i++)
	{
		RedMountain1Fog[i].Color = 0xFFFFFFFF;
		RedMountain1Fog[i].Layer = 2000.0f;
		RedMountain1Fog[i].Distance = 16000.0f;
		RedMountain1Fog[i].Toggle = 1;
		RedMountain2Fog[i].Layer = 1000.0f;
		RedMountain2Fog[i].Color = 0xFF000000;
		RedMountain2Fog[i].Distance = 2400.0f;
		RedMountain2Fog[i].Toggle = 1;
		RedMountain3Fog[i].Color = 0xFFFFFFFF;
		RedMountain3Fog[i].Layer = 2000.0f;
		RedMountain3Fog[i].Distance = 16000.0f;
		RedMountain3Fog[i].Toggle = 1;
		DrawDist_RedMountain1[i].Maximum = -16000.0;
		DrawDist_RedMountain3[i].Maximum = -16000.0;
		SkyboxScale_RedMountain2[i].x = 1.0f;
		SkyboxScale_RedMountain2[i].y = 1.0f;
		SkyboxScale_RedMountain2[i].z = 1.0f;
	}

	// registering start locations
	helperFunctions.RegisterStartPosition(Characters_Sonic, sonicRedMountain0);
	helperFunctions.RegisterStartPosition(Characters_Sonic, sonicRedMountain1);
	helperFunctions.RegisterStartPosition(Characters_Gamma, gammaRedMountain1);
	helperFunctions.RegisterStartPosition(Characters_Knuckles, knucklesRedMountain2);
	
	//registering paths
	//helperFunctions.RegisterPathList(RM1PathList); //Not using these...
	//helperFunctions.RegisterPathList(RM3PathList);
}

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer, &Init, NULL, 0, NULL, 0, NULL, 0, arrayptrandlength(pointers) };

	__declspec(dllexport) void cdecl Init()
	{
		*(NJS_OBJECT*)0x243F2D4 = object_MT_TSAKU_AD; //brown fence, multi-segmented
		*(NJS_OBJECT*)0x248042C = object_OTree1_AD; //vertical dead tree
		*(NJS_OBJECT*)0x24813B4 = object_OTree2_AD; //horizontal dead tree
		*(NJS_OBJECT*)0x246B81C = object_OAsiba1_AD; //green metal platform

		//*(NJS_OBJECT*)0x246CAA8 = object_CloudLayer_AD; //Cloud Layer1 DON'T USE THIS. CAUSES UV SHIFTING SPEED PROBLEMS

		*(NJS_OBJECT*)0x243D1B4 = object_OSaku2_AD; //machine fence thing with a light

		*(NJS_MODEL_SADX*)0x2483D48 = attach_001BA318; //Giant unused catapult
		*(NJS_MODEL_SADX*)0x2483F50 = attach_OHataki_AD;

		stru_2445DEC = BetaZipline_Anim; //Zipline machine
		//stru_2445DEC.object = &object_Ogl_AD; 
		//*(NJS_OBJECT*)0x24459FC = object_Ogl_AD;

		*(NJS_OBJECT*)0x2439964 = object_00162618; //small yellow box light
		*(NJS_OBJECT*)0x24394F8 = object_00162A1C;
		*(NJS_OBJECT*)0x24392F0 = object_0016280C;
		*(NJS_MODEL_SADX*)0x24390BC = attach_OLight_AD;

		stru_242A464.object = &object_O_honoo_AD; //fire-breathing skull
		*(NJS_OBJECT*)0x246D904 = object_OSakuReal_AD; //green fence

		*(NJS_OBJECT*)0x246DD0C = object_OHago_AD; //tilting platform
		*(NJS_MODEL_SADX*)0x246DCE0 = attach_001A3F78;
		*(NJS_MODEL_SADX*)0x246E100 = attach_001A4388;

		*(NJS_OBJECT*)0x24508E4 = object_00180110; //giant hammer
		*(NJS_MODEL_SADX*)0x2450DE0 = attach_OHanama_AD;

		*(NJS_OBJECT*)0x246CC9C = object_Mt_tbox_AD; //metal crate
		*(NJS_OBJECT*)0x243B0B4 = object_OPipebox_AD; //yellow box

		//stru_2454D8C.object = &object_ORelayP_AD; //unused zipline piece
		stru_2454D8C = UnusedBetaZipline_Anim;

		*(NJS_MODEL_SADX*)0x243BAA8 = attach_OVent_AD; //vent

		*(NJS_OBJECT*)0x242FA04 = object_o_untei2_AD; //monkey bars
		*(NJS_OBJECT*)0x2432404 = object_o_untei1_AD;
		*(NJS_OBJECT*)0x242B5FC = object_o_untei3_AD;
		*(NJS_OBJECT*)0x242D004 = object_o_untei6_AD;

		stru_247D8AC.object = &object_OGear_AD; //giant gear mechanism

		*(NJS_MODEL_SADX*)0x2456DF8 = attach_Prop_Bottom_Low_AD; //floating propellor
		*(NJS_MODEL_SADX*)0x24570B0 = attach_Prop_Fans_Low_AD;
		*(NJS_MODEL_SADX*)0x2455DDC = attach_Prop_Bottom_Hi_AD;
		*(NJS_MODEL_SADX*)0x24568A0 = attach_Prop_Fans_Hi_AD;

		*(NJS_OBJECT*)0x2446FCC = object_Zako_1_AD; //Zako rocks
		*(NJS_OBJECT*)0x2447244 = object_Zako_2_AD;
		*(NJS_OBJECT*)0x24474CC = object_Zako_3_AD;
		*(NJS_OBJECT*)0x2447708 = object_Zako_4_AD;
		*(NJS_OBJECT*)0x2447920 = object_Zako_5_AD;
		*(NJS_OBJECT*)0x2447AF0 = object_Zako_6_AD;

		*(NJS_OBJECT*)0x243AB6C = object_PipeL_AD; //Curved pipe
		*(NJS_OBJECT*)0x243B6FC = object_PipeI_AD; //straight pipe

		*(NJS_OBJECT*)0x2465B38 = object_MTKusa_Hi_AD; //mountain grass

		*(NJS_MODEL_SADX*)0x2466568 = attach_Turi_Plank_AD; //bridge
		*(NJS_MODEL_SADX*)0x2466818 = attach_Turi_Horz_AD;
		//*(NJS_MODEL_SADX*)0x24666C0 = attach_Turi_Vert_AD;
		stru_24666EC.basicdxmodel->mats[0].attr_texId = 32;

		*(NJS_OBJECT*)0x244FD8C = object_Erupt_Fireball_AD; //fireball

		*(NJS_OBJECT*)0x245BF5C = object_OFuta_P2_AD; //Act 1->2 hatch
		*(NJS_OBJECT*)0x245C54C = object_OFuta_P1_AD;

		*(NJS_MODEL_SADX*)0x2421F64 = attach_001421C8; //crumbling bridge
		*(NJS_MODEL_SADX*)0x2421C64 = attach_00141EE8;
		*(NJS_MODEL_SADX*)0x2421964 = attach_00141C08;
		*(NJS_MODEL_SADX*)0x2421664 = attach_00141928;
		*(NJS_MODEL_SADX*)0x2421364 = attach_00141648;
		*(NJS_MODEL_SADX*)0x2421064 = attach_00141368;

		*(NJS_MODEL_SADX*)0x2423164 = attach_00143308;
		*(NJS_MODEL_SADX*)0x2422E64 = attach_00143028;
		*(NJS_MODEL_SADX*)0x2422B64 = attach_00142D48;
		*(NJS_MODEL_SADX*)0x2422864 = attach_00142A68;
		*(NJS_MODEL_SADX*)0x2422564 = attach_00142788;
		*(NJS_MODEL_SADX*)0x2422264 = attach_001424A8;
		//*(NJS_OBJECT*)0x2423190 = object_O_Breakstep2_AD;
		//*(NJS_OBJECT*)0x2421F90 = object_O_Breakstep2_AD;

		*(NJS_MODEL_SADX*)0x24364C0 = attach_Bonehead_AD; //wall/stick skull
		*(NJS_MODEL_SADX*)0x24368A0 = attach_OBonestick_AD; //stick for bonestick

		//*(NJS_MODEL_SADX*)0x242A824 = attach_O_komokosu_AD; //unused spiderweb
		stru_242A820.basicdxmodel->mats[0].attr_texId = 23;

		*(NJS_OBJECT*)0x2459814 = object_Spider_AD; //spider
		*(NJS_OBJECT*)0x243A220 = object_OLightb_AD; //floor light
		*(NJS_MODEL_SADX*)0x243762C = attach_OMasiba_AD; //lava platform
		//*(NJS_OBJECT*)0x247E4D4 = object_Bat_AD; //bat
		stru_247E644 = BetaBat_Anim;

		*(NJS_OBJECT*)0x243526C = object_OChair_AD; //torture chair
		*(NJS_OBJECT*)0x248213C = object_Lamp1_AD; //green lamp
		*(NJS_OBJECT*)0x2482D94 = object_Lamp2_AD; //red lamp
		*(NJS_OBJECT*)0x243E554 = object_Rouya_AD; //jail bars

		//*(NJS_OBJECT*)0x24633B8 = object_Dancing_Ghost_AD; //jailed ghost
		stru_246501C = JailedGhost_Anim;

		*(NJS_OBJECT*)0x2432C44 = object_Haka_AD; //small tombstone

		*(NJS_OBJECT*)0x2425C00 = object_ODeka_AD; //massive rocks that fall over

		//*(NJS_OBJECT*)0x2445F34 = object_ZipRope_AD; //zipline rope
		*(NJS_MODEL_SADX*)0x2445F08 = attach_ZipRope_AD;

		*(NJS_MODEL_SADX*)0x2440738 = attach_0016BCEC;
		*(NJS_MODEL_SADX*)0x2440498 = attach_0016BA58;
		*(NJS_MODEL_SADX*)0x243FF60 = attach_0016B534;
		*(NJS_MODEL_SADX*)0x243FCB8 = attach_0016B29C;
		*(NJS_MODEL_SADX*)0x243FA70 = attach_0016B064;
		*(NJS_MODEL_SADX*)0x243F550 = attach_0016AB54;
		//*(NJS_OBJECT*)0x2440764 = object_ZipHook_AD; //zipline hook

		*(NJS_MODEL_SADX*)0x2438C04 = attach_00162304; //waving skull tombstone
		*(NJS_OBJECT*)0x2438934 = object_00162044;
		*(NJS_OBJECT*)0x24379AC = object_001610CC;
		*(NJS_OBJECT*)0x2437804 = object_00160F2C;

		*(NJS_OBJECT*)0x24461D4 = object_00175C68; //unused rocks that are used in the AD, but (I can't find them in the level in the AD!!!) are unreferenced in the final
		*(NJS_OBJECT*)0x244644C = object_00175ED0;
		*(NJS_OBJECT*)0x24466D4 = object_00176144;
		*(NJS_OBJECT*)0x24468F0 = object_0017634C;
		*(NJS_OBJECT*)0x2446B08 = object_00176554;
		*(NJS_OBJECT*)0x2446CD8 = object_00176714;

		*(NJS_OBJECT*)0x245CBAC = object_EntrancePillar_AD; //unused pillar that was used in the AD

		*(NJS_OBJECT*)0x246C898 = object_Skybox1_AD; //skybox
		*(NJS_OBJECT*)0x246C460 = object_Skybox2_AD;
		*(NJS_OBJECT*)0x246C048 = object_Skybox3_AD;
		*(NJS_OBJECT*)0x246BC30 = object_Skybox4_AD;

		*(NJS_OBJECT*)0x246A624 = object_00181CE0; //bridge poles (didn't exist in the AD)
		*(NJS_OBJECT*)0x246AB24 = object_001821C0;
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		if (CurrentLevel == 5)
		{
			if (CurrentAct == 2 && EntityData1Ptrs[0] && HasloadedTutorial == false && KnucklesTutorial == true)
			{
				ObjectMaster *obj;
				EntityData1 *ent;

				ObjectFunc(OF2, Tutorial_Load);
				GlideTutorial.Distance = 612800.0f;
				obj = LoadObject((LoadObj)2, 3, OF2);
				obj->SETData.SETData = &GlideTutorial;
				if (obj)
				{
					ent = obj->Data1;
					ent->Position.x = 64;
					ent->Position.y = 64;
					ent->Scale.x = 1.0f;
					ent->Scale.y = 1.0f;
					ent->Scale.z = 1.0f;
				}
				HasloadedTutorial = true;
			}

			/*if (CurrentAct == 1 && EntityData1Ptrs[0])
			{
				RedMountainAct2Pillar_Load();

				if (GameState == 3 || GameState == 4 || GameState == 7 || GameState == 21 || !EntityData1Ptrs[0])
				{
					loadedPillar = false;
				}



			}*/

			if (CurrentLevel == 5 && CurrentAct == 1)
			{
				SetTextureToLevelObj();
				njPushMatrix(0);
				njTranslate(0, -48, 978, 1972);
				njRotateZ(0, (unsigned __int16)0);
				njRotateX(0, (unsigned __int16)0);
				njRotateY(0, (unsigned __int16)0);
				ProcessModelNode_AB_Wrapper((NJS_OBJECT *)0x245CBAC, 1.0);
				njPopMatrix(1u);
			}

			if (GameState != 16) //borrowing from PkR, modified!
			{
				UVShift3 = (UVShift1 - 2 * FramerateSetting) % 255;
				UVShift1 = (UVShift1 - 1 * FramerateSetting) % 255;
				UVShift2 = (UVShift2 - 2 * FramerateSetting) % 255;

				for (unsigned int q = 0; q < LengthOfArray(uv_001A2CC8); q++)
				{
					uv_001A2CC8[q].u = uv_001A2CC8_0[q].u + UVShift1;
					uv_001A2CC8_2[q].u = uv_001A2CC8_0[q].u + UVShift2;
				}
				for (unsigned int p = 0; p < LengthOfArray(uv_001A2BC8); p++)
				{
					uv_001A2BC8[p].u = uv_001A2BC8_1[p].u + (UVShift3 * 2);
				}

				if (CurrentAct == 1 && Camera_Data1 != nullptr)
				{
					if (Camera_Data1->Position.y > 900)
					{
						CurrentDrawDistance = -9000.0f;
					}
				}

				if (!EntityData1Ptrs[0] && (ControllerPointers[0]->HeldButtons & Buttons_X) && !AlwaysGreenLight) //green box-light color cheat code
				{
					greenlightcheat = true;
				}

				if ((greenlightcheat || AlwaysGreenLight) && attach_OLight_AD.mats[1].attr_texId != 106)
				{
					attach_OLight_AD.mats[1].attr_texId = 106;
				}

				else if (!greenlightcheat && !AlwaysGreenLight && attach_OLight_AD.mats[1].attr_texId == 106)
				{
					attach_OLight_AD.mats[1].attr_texId = 99;
				}

				if (!EntityData1Ptrs[0] && (ControllerPointers[0]->HeldButtons & Buttons_Y) && !AlwaysFloorLight) //floor light ignore light cheat code
				{
					floorlightcheat = true;
				}

				if ((floorlightcheat || AlwaysFloorLight) && !EntityData1Ptrs[0])
				{
					object_OLightb_AD.basicdxmodel->mats[1].attrflags &= ~NJD_FLAG_IGNORE_LIGHT;
					object_OLightb_AD.basicdxmodel->mats[2].attrflags &= ~NJD_FLAG_IGNORE_LIGHT;
					object_OLightb_AD.basicdxmodel->mats[3].attrflags &= ~NJD_FLAG_IGNORE_LIGHT;
				}

				else if (!EntityData1Ptrs[0])
				{
					object_OLightb_AD.basicdxmodel->mats[1].attrflags |= NJD_FLAG_IGNORE_LIGHT;
					object_OLightb_AD.basicdxmodel->mats[2].attrflags |= NJD_FLAG_IGNORE_LIGHT;
					object_OLightb_AD.basicdxmodel->mats[3].attrflags |= NJD_FLAG_IGNORE_LIGHT;
				}

				if ((!EntityData1Ptrs[0] && (ControllerPointers[0]->HeldButtons & Buttons_L)) || (AlwaysFence && greenfencecheat == true)) //Larger fence cheat code
				{
					greenfencecheat = false;
				}

				if (!EntityData1Ptrs[0] && (ControllerPointers[0]->HeldButtons & Buttons_R) && !AlwaysCloudLayer) //3rd cloud layer cheat code
				{
					thirdcloudlayercheat = true;
				}
			}

			switch (fireballanimation)
			{
			case 0:
				object_Erupt_Fireball_AD.basicdxmodel->mats[0].attr_texId = 96;
				break;
			case 4:
				object_Erupt_Fireball_AD.basicdxmodel->mats[0].attr_texId = 86;
				break;
			case 8:
				object_Erupt_Fireball_AD.basicdxmodel->mats[0].attr_texId = 55;
				break;
			case 12:
				object_Erupt_Fireball_AD.basicdxmodel->mats[0].attr_texId = 87;
				break;
			case 16:
				object_Erupt_Fireball_AD.basicdxmodel->mats[0].attr_texId = 97;
				break;
			default:
				break;
			}

			fireballanimation++;

			if (FramerateSetting >= 2)
			{
				fireballanimation++;
			}

			if (fireballanimation > 16)
			{
				fireballanimation = 0;
			}
		}

		if (CurrentLevel != 5 && (greenlightcheat == true || floorlightcheat == true || greenfencecheat == false || thirdcloudlayercheat == true || HasloadedTutorial == true))
		{
			if (!AlwaysGreenLight)
			{
				greenlightcheat = false;
			}

			if (!AlwaysFloorLight)
			{
				floorlightcheat = false;
			}

			if (!AlwaysFence)
			{
				greenfencecheat = true;
			}

			if (!AlwaysCloudLayer)
			{
				thirdcloudlayercheat = false;
			}

			HasloadedTutorial = false;
			TutorialTimer = 80;
		}
	}
}