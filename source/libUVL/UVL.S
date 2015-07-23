#include <psp2/import.S>

PSP2_IMPORT_HEAD 0x0, UVL, 0001, 1, 0


//NID from uvload.h
//see: https://github.com/yifanlu/UVLoader/blob/master/uvloader.h


PSP2_IMPORT_FUNC UVL, 0001, F00, 0xBCEAB831, uvl_alloc_code_mem
PSP2_IMPORT_FUNC UVL, 0001, F00, 0x98D1C91D, uvl_unlock_mem
PSP2_IMPORT_FUNC UVL, 0001, F00, 0xEEC99826, uvl_lock_mem
PSP2_IMPORT_FUNC UVL, 0001, F00, 0xC85B400C, uvl_flush_icache
PSP2_IMPORT_FUNC UVL, 0001, F00, 0xD4F59028, uvl_debug_log
PSP2_IMPORT_FUNC UVL, 0001, F00, 0xE8E92954, uvl_load