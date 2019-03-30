#pragma once
#include "SADXModLoader.h"


NJS_TEXNAME GLIDETUT_texnames[3];

NJS_TEXLIST BETAMOUNTAIN_texlist = { arrayptrandlength(GLIDETUT_texnames) };

NJS_TEXNAME GLIDETUTE_texnames[3];

NJS_TEXLIST BETAMOUNTAINE_texlist = { arrayptrandlength(GLIDETUTE_texnames) };


PVMEntry RedMountainObjectTextures[] = {
	{ "OBJ_MOUNTAIN_AD", (TexList *)0x24208A8 },
	{ "MOUNTAIN_E104_AD", (TexList *)0x2499328 },
	{ "OUM", (TexList *)0x9334EC },
	{ "YOUGAN_ANIM_AD", (TexList *)0x2486018 },
	{ "SUPI_SUPI", (TexList *)0x96F518 },
	{ "MOUNTAIN_MEXPLOSION_AD", (TexList *)0x2498810 },
	{ "MOUNTAIN_STEAM_AD", (TexList *)0x24986A0 },
	{ "TUBA", (TexList *)0x92F2BC },
	{ "E_SARU", (TexList *)0x962560 },
	{ "LION", (TexList *)0x944094 },
	{ "MOGU", (TexList *)0x93ECEC },
	{ "ZOU", (TexList *)0x94160C },
	{ "MOUNTAIN_CARRIER", (TexList *)0x24984D4 },
	{ "CHAOS_LIFEGAUGE", (TexList *)0x974000 },
	{ "UNI_C_UNIBODY", (TexList *)0x96DC48 },
	{ "GORI", (TexList *)0x945964 },
	{ "TOGEBALL_TOGEBALL", (TexList *)0x96BC54 },
	{ "E_BOMB", (TexList *)0x96B464 },
	{ "K_TUTORIAL_AD", &BETAMOUNTAIN_texlist },
	{ "K_TUTORIAL_USA_AD", &BETAMOUNTAINE_texlist },
	{ NULL, (TexList *)0x973FB0 }, //this is the boss display text that appears for E-104's boss intro
	{ 0 }
};

extern NJS_TEXANIM Tutorial0Texanim = { 256, 64, 128, 32, 0, 0, 0xFF, 0xFF, 0, 0 };
extern NJS_TEXANIM Tutorial1Texanim = { 256, 64, 128, 32, 0, 0, 0xFF, 0xFF, 1, 0 };
extern NJS_TEXANIM Tutorial2Texanim = { 256, 64, 128, 32, 0, 0, 0xFF, 0xFF, 2, 0 };

//Japanese variant
extern NJS_SPRITE _TutIntro = { { HorizontalStretch * 1240, VerticalStretch * 78, 0.0f }, 2.0f, 2.0f, 0, &BETAMOUNTAIN_texlist, &Tutorial0Texanim }; // [esp+0h] [ebp-20h]
extern NJS_SPRITE _TutFail = { { HorizontalStretch * -840, VerticalStretch * 356, 0.0f }, 2.0f, 2.0f, 0, &BETAMOUNTAIN_texlist, &Tutorial1Texanim }; // [esp+0h] [ebp-20h]
extern NJS_SPRITE _TutControl = { { HorizontalStretch * -840, VerticalStretch * 348, 0.0f }, 2.0f, 2.0f, 0, &BETAMOUNTAIN_texlist, &Tutorial2Texanim }; // [esp+0h] [ebp-20h]

//English variant
extern NJS_SPRITE _TutIntroE = { { HorizontalStretch * 1240, VerticalStretch * 78, 0.0f }, 2.0f, 2.0f, 0, &BETAMOUNTAINE_texlist, &Tutorial0Texanim }; // [esp+0h] [ebp-20h]
extern NJS_SPRITE _TutFailE = { { HorizontalStretch * -840, VerticalStretch * 356, 0.0f }, 2.0f, 2.0f, 0, &BETAMOUNTAINE_texlist, &Tutorial1Texanim }; // [esp+0h] [ebp-20h]
extern NJS_SPRITE _TutControlE = { { HorizontalStretch * -840, VerticalStretch * 348, 0.0f }, 2.0f, 2.0f, 0, &BETAMOUNTAINE_texlist, &Tutorial2Texanim }; // [esp+0h] [ebp-20h]


//210 is about the middle. Do HorizontalStretch * 210 (840 is offscreen)