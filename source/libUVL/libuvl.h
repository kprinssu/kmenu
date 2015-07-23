#ifndef LIBUVL_UVLOADER
#define LIBUVL_UVLOADER


//UVL functions
void *uvl_alloc_code_mem(unsigned int *pointer_len);
void uvl_unlock_mem();
void uvl_lock_mem();
void uvl_flush_icache(void *address, unsigned int mem_len);
int uvl_debug_log(const char * debug_line);
int uvl_load(const char * hombrew_path);
void uvl_exit(int value);

#endif


