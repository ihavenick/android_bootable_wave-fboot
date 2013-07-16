#ifndef _FB_BL3_H_
#define _FB_BL3_H_

#include <stdarg.h>
#include "s5pc110.h"

#define fptr(...) __VA_ARGS__
typedef int (*fun_t)(fptr()) ;

typedef enum 
{
   rm_BL3,
   rm_FOTA_RUN,
   rm_FOTA_RECOVERY,
   rm_FOTA_BIGMEM,
   rm_FOTA_FPFK,
   rm_FOTA_DLOAD,
   rm_FOTA_donothing,
   
} runMode_t;


typedef struct
{
   unsigned int st_mode; /* file mode */
   unsigned int st_ino; /* file serial number */
   unsigned short st_dev; /* ID of device containing this file */
   unsigned short  st_dummy; /* dummy entry */
   unsigned int st_size; /* the file size in bytes */
   unsigned int st_atime; /* time of last access */
   unsigned int st_mtime; /* time of last data modification */
   unsigned int st_ctime; /* time of last status change */
   unsigned int d1; //added some dummy spaces just to protect for potential BOF
   unsigned int d2;
   unsigned int d3;
   unsigned int d4;
   unsigned int d5;   
   unsigned int d6;
} t_stat;

enum {
   i_MemMMUCacheEnable,
   i_disp_FOTA_Init,
   i_disp_FOTA_Printf,
   i_OemSysGetSystemInfo,
   i___PfsNandInit,
   i___PfsMassInit,
   i_MemoryCardMount,
   i_DRV_Modem_BootingStart,
   i_tfs4_stat,
   i_tfs4_open,
   i_tfs4_read,
   i_tfs4_close,
   
   
   //do not add below this line
   i_endMarker
};

extern fun_t ptr_table[i_endMarker];
extern unsigned long *fun_crc[i_endMarker];
extern unsigned char gMMUL1PageTable[0x4000];

unsigned char BL3_DRAM_START;
unsigned char KERNEL_BUF;
unsigned char KERNEL_START;
extern fun_t kernel;

extern unsigned char* RAW_BL3;


#define MemMMUCacheEnable           ptr_table[i_MemMMUCacheEnable]
#define __PfsNandInit               ptr_table[i___PfsNandInit]
#define __PfsMassInit               ptr_table[i___PfsMassInit]
#define MemoryCardMount             ptr_table[i_MemoryCardMount]
#define tfs4_stat                   ptr_table[i_tfs4_stat]
#define tfs4_open                   ptr_table[i_tfs4_open]
#define tfs4_read                   ptr_table[i_tfs4_read]
#define tfs4_close                  ptr_table[i_tfs4_close]
#define disp_FOTA_Init              ptr_table[i_disp_FOTA_Init]
#define disp_FOTA_Printf            ptr_table[i_disp_FOTA_Printf]
#define OemSysGetSystemInfo         ptr_table[i_OemSysGetSystemInfo]
#define DRV_Modem_BootingStart             ptr_table[i_DRV_Modem_BootingStart]




#define KEY_CALL 2
#define KEY_CAM1 3
#define KEY_CAM2 6
#define KEY_LOCK 8
#define KEY_MENU 0
#define KEY_VOLD 4
#define KEY_VOLU 7

int getBL3ptrs( void );
runMode_t checkFBOOT( void );

#endif//_FB_BL3_H_
