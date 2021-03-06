#include "SADXModLoader.h"

//Skybox:
NJS_MATERIAL matlist_001A2790[] = {
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 92, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 93, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 94, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 91, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_001A27E0[] = {
	0x8000u | 5, 14, 19, 0, 4, 20,
	3, 0, 14, 9
};

Sint16 poly_001A27F4[] = {
	4, 2, 13, 20, 4,
	0x8000u | 8, 9, 7, 14, 12, 19, 17, 4, 13
};

Sint16 poly_001A2810[] = {
	4, 1, 8, 2, 13,
	0x8000u | 8, 7, 6, 12, 11, 17, 16, 13, 8
};

Sint16 poly_001A282C[] = {
	4, 3, 18, 1, 8,
	0x8000u | 8, 6, 5, 11, 10, 16, 15, 8, 18
};

NJS_TEX uv_001A2848[] = {
	{ 372, -118 },
	{ 97, -532 },
	{ 1275, -1020 },
	{ 0, -1020 },
	{ 97, -1506 },
	{ 1275, -1020 },
	{ 372, -118 },
	{ 787, 157 }
};

NJS_TEX uv_001A2868[] = {
	{ 2868, 255 },
	{ 3060, 255 },
	{ 2869, 0 },
	{ 3060, 0 },
	{ 570, 0 },
	{ 573, 255 },
	{ 378, 0 },
	{ 382, 255 },
	{ 189, 0 },
	{ 191, 255 },
	{ 4, 0 },
	{ 6, 254 }
};

NJS_TEX uv_001A2898[] = {
	{ 2868, 255 },
	{ 3060, 255 },
	{ 2868, 0 },
	{ 3060, 0 },
	{ 573, 0 },
	{ 573, 255 },
	{ 382, 0 },
	{ 382, 255 },
	{ 191, 0 },
	{ 191, 255 },
	{ 0 },
	{ 0, 254 }
};

NJS_TEX uv_001A28C8[] = {
	{ 191, 252 },
	{ 23, 253 },
	{ 191, 4 },
	{ 23, 4 },
	{ 2486, 3 },
	{ 2486, 252 },
	{ 2677, 4 },
	{ 2689, 252 },
	{ 2868, 3 },
	{ 2868, 251 },
	{ 3012, 3 },
	{ 3012, 251 }
};

NJS_MESHSET_SADX meshlist_001A28F8[] = {
	{ NJD_MESHSET_TRIMESH | 0, 2, poly_001A27E0, NULL, NULL, NULL, uv_001A2848, NULL },
	{ NJD_MESHSET_TRIMESH | 1, 2, poly_001A27F4, NULL, NULL, NULL, uv_001A2868, NULL },
	{ NJD_MESHSET_TRIMESH | 2, 2, poly_001A2810, NULL, NULL, NULL, uv_001A2898, NULL },
	{ NJD_MESHSET_TRIMESH | 3, 2, poly_001A282C, NULL, NULL, NULL, uv_001A28C8, NULL }
};

NJS_VECTOR vertex_001A2958[] = {
	{ -2550, 4040, -1350 },
	{ 2763.209f, -443.5482f, -990.9766f },
	{ 2314.605f, 2243.851f, -1018.793f },
	{ 2745.953f, -607.9998f, -992.1426f },
	{ 855.0989f, 3947.348f, 201.7901f },
	{ -2550.373f, -607.9998f, 3612.592f },
	{ -2550.374f, -443.5482f, 3628.762f },
	{ -2547.677f, 2243.851f, 3203.583f },
	{ 2358.622f, -443.5482f, 886.9843f },
	{ -2520.083f, 3947.348f, 2037.542f },
	{ -523.6701f, -607.9998f, 3371.784f },
	{ -517.0676f, -443.5482f, 3387.169f },
	{ -686.2505f, 2243.851f, 2983.71f },
	{ 1945.195f, 2243.851f, 698.5748f },
	{ -1116.665f, 3947.348f, 1885.484f },
	{ 1194.541f, -607.9998f, 2412.126f },
	{ 1206.742f, -443.5482f, 2424.384f },
	{ 891.4382f, 2243.851f, 2104.069f },
	{ 2342.679f, -607.9998f, 879.7186f },
	{ 68.54204f, 3947.348f, 1240.855f },
	{ 1123.261f, 3947.348f, -1073.52f }
};

NJS_VECTOR normal_001A2A54[] = {
	{ -0.014646f, -0.999728f, -0.018164f },
	{ -0.977156f, -0.029671f, -0.21044f },
	{ -0.909686f, -0.366696f, -0.194951f },
	{ -0.9723189f, 0.103515f, -0.209476f },
	{ -0.470716f, -0.8557799f, -0.214633f },
	{ -0.11743f, 0.097172f, -0.988316f },
	{ -0.117777f, -0.02863f, -0.992627f },
	{ -0.108052f, -0.357314f, -0.927713f },
	{ -0.909547f, -0.030163f, -0.414506f },
	{ -0.057432f, -0.861294f, -0.50485f },
	{ -0.306009f, 0.10085f, -0.946672f },
	{ -0.309694f, -0.029296f, -0.950385f },
	{ -0.286327f, -0.362767f, -0.886802f },
	{ -0.845062f, -0.370788f, -0.38521f },
	{ -0.155342f, -0.8548599f, -0.495059f },
	{ -0.654034f, 0.104378f, -0.74923f },
	{ -0.65872f, -0.029842f, -0.7517959f },
	{ -0.611383f, -0.367659f, -0.700741f },
	{ -0.9048409f, 0.10594f, -0.412359f },
	{ -0.338311f, -0.8551f, -0.392873f },
	{ -0.496657f, -0.861478f, -0.105774f }
};

NJS_MODEL_SADX attach_001A2B50 = { vertex_001A2958, normal_001A2A54, LengthOfArray<Sint32>(vertex_001A2958), meshlist_001A28F8, matlist_001A2790, LengthOfArray<Uint16>(meshlist_001A28F8), LengthOfArray<Uint16>(matlist_001A2790), { 106.4177f, 1716, 1139.381f }, 9999.818f, NULL };

NJS_OBJECT object_Skybox1_AD = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_001A2B50, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };
//skybox piece 1

NJS_MATERIAL matlist_001A239C[] = {
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 92, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 93, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 94, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 91, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_001A23EC[] = {
	0x8000u | 5, 19, 1, 0, 17, 10,
	3, 0, 19, 20
};

Sint16 poly_001A2400[] = {
	0x8000u | 10, 20, 4, 19, 14, 1, 13, 17, 11, 10, 3
};

Sint16 poly_001A2416[] = {
	0x8000u | 10, 9, 3, 8, 11, 18, 13, 15, 14, 2, 4
};

Sint16 poly_001A242C[] = {
	0x8000u | 10, 12, 9, 5, 8, 7, 18, 16, 15, 6, 2
};

NJS_TEX uv_001A2444[] = {
	{ 372, -1920 },
	{ 787, -2197 },
	{ 1275, -1020 },
	{ 1275, -2295 },
	{ 1761, -2197 },
	{ 1275, -1020 },
	{ 372, -1920 },
	{ 97, -1506 }
};

NJS_TEX uv_001A2464[] = {
	{ 2869, 0 },
	{ 2868, 255 },
	{ 2679, 0 },
	{ 2677, 255 },
	{ 2487, 0 },
	{ 2486, 255 },
	{ 2295, 0 },
	{ 2295, 255 },
	{ 2101, 0 },
	{ 2103, 255 }
};

NJS_TEX uv_001A248C[] = {
	{ 2103, 255 },
	{ 2103, 0 },
	{ 2295, 255 },
	{ 2295, 0 },
	{ 2486, 255 },
	{ 2486, 0 },
	{ 2677, 255 },
	{ 2677, 0 },
	{ 2868, 255 },
	{ 2868, 0 }
};

NJS_TEX uv_001A24B4[] = {
	{ 956, 252 },
	{ 956, 4 },
	{ 765, 251 },
	{ 765, 4 },
	{ 573, 252 },
	{ 573, 4 },
	{ 394, 252 },
	{ 394, 4 },
	{ 191, 252 },
	{ 191, 4 }
};

NJS_MESHSET_SADX meshlist_001A24DC[] = {
	{ NJD_MESHSET_TRIMESH | 0, 2, poly_001A23EC, NULL, NULL, NULL, uv_001A2444, NULL },
	{ NJD_MESHSET_TRIMESH | 1, 1, poly_001A2400, NULL, NULL, NULL, uv_001A2464, NULL },
	{ NJD_MESHSET_TRIMESH | 2, 1, poly_001A2416, NULL, NULL, NULL, uv_001A248C, NULL },
	{ NJD_MESHSET_TRIMESH | 3, 1, poly_001A242C, NULL, NULL, NULL, uv_001A24B4, NULL }
};

NJS_VECTOR vertex_001A253C[] = {
	{ -2550, 4040, -1350 },
	{ 26.23204f, 3947.348f, -3549.853f },
	{ 2763.209f, -443.5482f, -990.9766f },
	{ -2552.323f, 2243.851f, -5903.582f },
	{ 2314.605f, 2243.851f, -1018.793f },
	{ -522.9844f, -607.9998f, -5797.889f },
	{ 2745.953f, -607.9998f, -992.1426f },
	{ 1195.066f, -607.9998f, -4606.04f },
	{ -516.3789f, -443.5482f, -5812.384f },
	{ -2549.628f, -443.5482f, -6328.762f },
	{ -2579.918f, 3947.348f, -4737.54f },
	{ -690.5417f, 2243.851f, -5430.218f },
	{ -2549.629f, -607.9998f, -6312.592f },
	{ 888.1509f, 2243.851f, -4335.67f },
	{ 1943.419f, 2243.851f, -2786.586f },
	{ 2358.908f, -443.5482f, -2923.595f },
	{ 2342.965f, -607.9998f, -2918.485f },
	{ -1171.944f, 3947.348f, -4373.876f },
	{ 1207.269f, -443.5482f, -4616.649f },
	{ 832.2001f, 3947.348f, -2390.921f },
	{ 1123.261f, 3947.348f, -1073.52f }
};

NJS_VECTOR normal_001A2638[] = {
	{ -0.017452f, -0.999676f, 0.018527f },
	{ -0.364367f, -0.8564259f, 0.365747f },
	{ -0.978361f, -0.029073f, 0.204851f },
	{ -0.231316f, -0.350827f, 0.907421f },
	{ -0.913108f, -0.358968f, 0.193329f },
	{ -0.412761f, 0.09640399f, 0.905723f },
	{ -0.973832f, 0.100739f, 0.203724f },
	{ -0.706422f, 0.097651f, 0.701023f },
	{ -0.41452f, -0.028776f, 0.909585f },
	{ -0.246117f, -0.028143f, 0.9688309f },
	{ -0.134338f, -0.840648f, 0.524656f },
	{ -0.387003f, -0.358919f, 0.849356f },
	{ -0.245043f, 0.09487499f, 0.9648589f },
	{ -0.661603f, -0.361487f, 0.656969f },
	{ -0.8559999f, -0.365881f, 0.365232f },
	{ -0.920434f, -0.029548f, 0.389778f },
	{ -0.915222f, 0.100852f, 0.390126f },
	{ -0.214446f, -0.855811f, 0.470745f },
	{ -0.710587f, -0.029041f, 0.70301f },
	{ -0.472744f, -0.856701f, 0.206341f },
	{ -0.52987f, -0.840407f, 0.113815f }
};

NJS_MODEL_SADX attach_001A2734 = { vertex_001A253C, normal_001A2638, LengthOfArray<Sint32>(vertex_001A253C), meshlist_001A24DC, matlist_001A239C, LengthOfArray<Uint16>(meshlist_001A24DC), LengthOfArray<Uint16>(matlist_001A239C), { 91.64575f, 1716, -3659.869f }, 9999.273f, NULL };

NJS_OBJECT object_Skybox2_AD = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_001A2734, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };
//skybox piece 2

NJS_MATERIAL matlist_001A1FA8[] = {
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 92, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 93, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 94, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 91, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_001A1FF8[] = {
	0x8000u | 5, 8, 12, 0, 16, 20,
	3, 0, 8, 4
};

Sint16 poly_001A200C[] = {
	0x8000u | 10, 19, 20, 15, 16, 11, 12, 7, 8, 3, 4
};

Sint16 poly_001A2022[] = {
	0x8000u | 10, 18, 19, 14, 15, 10, 11, 6, 7, 2, 3
};

Sint16 poly_001A2038[] = {
	0x8000u | 10, 2, 1, 6, 5, 10, 9, 14, 13, 18, 17
};

NJS_TEX uv_001A2050[] = {
	{ 2176, -118 },
	{ 1761, 157 },
	{ 1275, -1020 },
	{ 1275, 254 },
	{ 787, 157 },
	{ 1275, -1020 },
	{ 2176, -118 },
	{ 2452, -532 }
};

NJS_TEX uv_001A2070[] = {
	{ 573, 255 },
	{ 570, 0 },
	{ 765, 255 },
	{ 765, 0 },
	{ 956, 255 },
	{ 957, 0 },
	{ 1147, 255 },
	{ 1149, 0 },
	{ 1338, 255 },
	{ 1339, 0 }
};

NJS_TEX uv_001A2098[] = {
	{ 573, 255 },
	{ 573, 0 },
	{ 765, 255 },
	{ 765, 0 },
	{ 956, 255 },
	{ 956, 0 },
	{ 1147, 255 },
	{ 1147, 0 },
	{ 1338, 255 },
	{ 1338, 0 }
};

NJS_TEX uv_001A20C0[] = {
	{ 1721, 3 },
	{ 1721, 252 },
	{ 1912, 4 },
	{ 1912, 252 },
	{ 2103, 3 },
	{ 2103, 252 },
	{ 2295, 3 },
	{ 2295, 252 },
	{ 2486, 3 },
	{ 2486, 252 }
};

NJS_MESHSET_SADX meshlist_001A20E8[] = {
	{ NJD_MESHSET_TRIMESH | 0, 2, poly_001A1FF8, NULL, NULL, NULL, uv_001A2050, NULL },
	{ NJD_MESHSET_TRIMESH | 1, 1, poly_001A200C, NULL, NULL, NULL, uv_001A2070, NULL },
	{ NJD_MESHSET_TRIMESH | 2, 1, poly_001A2022, NULL, NULL, NULL, uv_001A2098, NULL },
	{ NJD_MESHSET_TRIMESH | 3, 1, poly_001A2038, NULL, NULL, NULL, uv_001A20C0, NULL }
};

NJS_VECTOR vertex_001A2148[] = {
	{ -2550, 4040, -1350 },
	{ -7845.953f, -607.9998f, -1707.859f },
	{ -7863.209f, -443.5482f, -1709.025f },
	{ -7414.605f, 2243.851f, -1681.208f },
	{ -6223.261f, 3947.348f, -1626.481f },
	{ -7442.965f, -607.9998f, 218.4836f },
	{ -7458.908f, -443.5482f, 223.5942f },
	{ -7043.42f, 2243.851f, 86.5847f },
	{ -5932.201f, 3947.348f, -309.0797f },
	{ -6295.067f, -607.9998f, 1906.038f },
	{ -6307.271f, -443.5482f, 1916.648f },
	{ -5988.151f, 2243.851f, 1635.67f },
	{ -5126.234f, 3947.348f, 849.8524f },
	{ -4577.017f, -607.9998f, 3097.889f },
	{ -4583.623f, -443.5482f, 3112.384f },
	{ -4409.459f, 2243.851f, 2730.218f },
	{ -3928.057f, 3947.348f, 1673.876f },
	{ -2550.373f, -607.9998f, 3612.592f },
	{ -2550.374f, -443.5482f, 3628.762f },
	{ -2547.677f, 2243.851f, 3203.583f },
	{ -2520.083f, 3947.348f, 2037.542f }
};

NJS_VECTOR normal_001A2244[] = {
	{ 0.017452f, -0.999676f, -0.018527f },
	{ 0.973832f, 0.10074f, -0.203724f },
	{ 0.978361f, -0.029073f, -0.204851f },
	{ 0.913108f, -0.358967f, -0.193328f },
	{ 0.52987f, -0.840407f, -0.113815f },
	{ 0.915222f, 0.100852f, -0.390126f },
	{ 0.920435f, -0.029548f, -0.389778f },
	{ 0.856001f, -0.365881f, -0.365232f },
	{ 0.472744f, -0.856701f, -0.206341f },
	{ 0.706422f, 0.097651f, -0.701022f },
	{ 0.710587f, -0.029041f, -0.70301f },
	{ 0.661603f, -0.361487f, -0.656969f },
	{ 0.364367f, -0.8564259f, -0.365747f },
	{ 0.412761f, 0.096402f, -0.905723f },
	{ 0.41452f, -0.028777f, -0.909585f },
	{ 0.387004f, -0.358919f, -0.849356f },
	{ 0.214446f, -0.855811f, -0.470744f },
	{ 0.245043f, 0.094871f, -0.9648589f },
	{ 0.246117f, -0.028145f, -0.9688309f },
	{ 0.231316f, -0.350827f, -0.907421f },
	{ 0.134338f, -0.840648f, -0.524656f }
};

NJS_MODEL_SADX attach_001A2340 = { vertex_001A2148, normal_001A2244, LengthOfArray<Sint32>(vertex_001A2148), meshlist_001A20E8, matlist_001A1FA8, LengthOfArray<Uint16>(meshlist_001A20E8), LengthOfArray<Uint16>(matlist_001A1FA8), { -5191.646f, 1716, 959.8685f }, 9999.273f, NULL };

NJS_OBJECT object_Skybox3_AD = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_001A2340, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };
//skybox piece 3

NJS_MATERIAL matlist_001A1BB4[] = {
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 92, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 93, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 94, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 91, NJD_D_100 | NJD_FILTER_BILINEAR | NJD_FLAG_CLAMP_V | NJD_FLAG_USE_TEXTURE | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC }
};

Sint16 poly_001A1C04[] = {
	0x8000u | 5, 10, 14, 0, 4, 9,
	3, 0, 10, 13
};

Sint16 poly_001A1C18[] = {
	0x8000u | 10, 8, 9, 3, 4, 20, 14, 11, 10, 5, 13
};

Sint16 poly_001A1C2E[] = {
	0x8000u | 10, 5, 12, 11, 18, 20, 19, 3, 2, 8, 7
};

Sint16 poly_001A1C44[] = {
	0x8000u | 10, 12, 15, 18, 16, 19, 17, 2, 1, 7, 6
};

NJS_TEX uv_001A1C5C[] = {
	{ 2176, -1920 },
	{ 2452, -1506 },
	{ 1275, -1020 },
	{ 2550, -1020 },
	{ 2452, -532 },
	{ 1275, -1020 },
	{ 2176, -1920 },
	{ 1761, -2197 }
};

NJS_TEX uv_001A1C7C[] = {
	{ 1338, 255 },
	{ 1339, 0 },
	{ 1530, 255 },
	{ 1530, 0 },
	{ 1721, 255 },
	{ 1719, 0 },
	{ 1912, 255 },
	{ 1909, 0 },
	{ 2103, 255 },
	{ 2101, 0 }
};

NJS_TEX uv_001A1CA4[] = {
	{ 2103, 0 },
	{ 2103, 255 },
	{ 1912, 0 },
	{ 1912, 255 },
	{ 1721, 0 },
	{ 1721, 255 },
	{ 1530, 0 },
	{ 1530, 255 },
	{ 1338, 0 },
	{ 1338, 255 }
};

NJS_TEX uv_001A1CCC[] = {
	{ 956, 4 },
	{ 956, 252 },
	{ 1147, 3 },
	{ 1147, 252 },
	{ 1338, 3 },
	{ 1338, 252 },
	{ 1529, 4 },
	{ 1529, 252 },
	{ 1721, 3 },
	{ 1721, 252 }
};

NJS_MESHSET_SADX meshlist_001A1CF4[] = {
	{ NJD_MESHSET_TRIMESH | 0, 2, poly_001A1C04, NULL, NULL, NULL, uv_001A1C5C, NULL },
	{ NJD_MESHSET_TRIMESH | 1, 1, poly_001A1C18, NULL, NULL, NULL, uv_001A1C7C, NULL },
	{ NJD_MESHSET_TRIMESH | 2, 1, poly_001A1C2E, NULL, NULL, NULL, uv_001A1CA4, NULL },
	{ NJD_MESHSET_TRIMESH | 3, 1, poly_001A1C44, NULL, NULL, NULL, uv_001A1CCC, NULL }
};

NJS_VECTOR vertex_001A1D54[] = {
	{ -2550, 4040, -1350 },
	{ -7442.679f, -607.9998f, -3579.72f },
	{ -7458.622f, -443.5482f, -3586.986f },
	{ -7045.196f, 2243.851f, -3398.577f },
	{ -5955.098f, 3947.348f, -2901.792f },
	{ -2552.323f, 2243.851f, -5903.582f },
	{ -7845.953f, -607.9998f, -1707.859f },
	{ -7863.209f, -443.5482f, -1709.025f },
	{ -7414.605f, 2243.851f, -1681.208f },
	{ -6223.261f, 3947.348f, -1626.481f },
	{ -3983.335f, 3947.348f, -4585.482f },
	{ -4413.75f, 2243.851f, -5683.709f },
	{ -2549.628f, -443.5482f, -6328.762f },
	{ -2579.918f, 3947.348f, -4737.54f },
	{ -5168.542f, 3947.348f, -3940.854f },
	{ -2549.629f, -607.9998f, -6312.592f },
	{ -4576.33f, -607.9998f, -6071.783f },
	{ -6294.542f, -607.9998f, -5112.125f },
	{ -4582.933f, -443.5482f, -6087.168f },
	{ -6306.743f, -443.5482f, -5124.383f },
	{ -5991.438f, 2243.851f, -4804.067f }
};

NJS_VECTOR normal_001A1E50[] = {
	{ 0.014646f, -0.999728f, 0.018164f },
	{ 0.9048409f, 0.105937f, 0.412359f },
	{ 0.909546f, -0.030164f, 0.414506f },
	{ 0.8450609f, -0.370788f, 0.385211f },
	{ 0.470715f, -0.8557799f, 0.214634f },
	{ 0.108052f, -0.357314f, 0.927713f },
	{ 0.9723189f, 0.103514f, 0.209476f },
	{ 0.977156f, -0.029671f, 0.21044f },
	{ 0.909686f, -0.366696f, 0.19495f },
	{ 0.496657f, -0.861478f, 0.105774f },
	{ 0.155342f, -0.8548599f, 0.495059f },
	{ 0.286327f, -0.362767f, 0.886802f },
	{ 0.117778f, -0.028629f, 0.992627f },
	{ 0.057432f, -0.861294f, 0.50485f },
	{ 0.338311f, -0.8551f, 0.392873f },
	{ 0.11743f, 0.097173f, 0.988316f },
	{ 0.306009f, 0.100852f, 0.946672f },
	{ 0.654034f, 0.104376f, 0.74923f },
	{ 0.309694f, -0.029296f, 0.950385f },
	{ 0.65872f, -0.029843f, 0.7517959f },
	{ 0.611383f, -0.367659f, 0.700741f }
};

NJS_MODEL_SADX attach_001A1F4C = { vertex_001A1D54, normal_001A1E50, LengthOfArray<Sint32>(vertex_001A1D54), meshlist_001A1CF4, matlist_001A1BB4, LengthOfArray<Uint16>(meshlist_001A1CF4), LengthOfArray<Uint16>(matlist_001A1BB4), { -5206.418f, 1716, -3839.381f }, 9999.817f, NULL };

NJS_OBJECT object_Skybox4_AD = { NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK, &attach_001A1F4C, 0, 0, 0, 0, 0, 0, 1, 1, 1, NULL, NULL };
//skybox piece 4