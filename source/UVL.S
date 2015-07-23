#include <psp2/import.S>

PSP2_IMPORT_HEAD 0x0, UVL, 0001, 1, 0


//NID from uvload.h
//see: https://github.com/yifanlu/UVLoader/blob/master/uvloader.h
PSP2_IMPORT_FUNC UVL, 0001, F00, 0xE8E92954, uvl_load