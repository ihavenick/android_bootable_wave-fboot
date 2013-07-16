/*
 ; This file is part of Badadroid project.
 ;
 ; Copyright (C) 2013 Rebellos, mijoma, b_kubica, ihavenick
 ;
 ;
 ; Badadroid is free software: you can redistribute it and/or modify
 ; it under the terms of the GNU General Public License as published by
 ; the Free Software Foundation, either version 3 of the License, or
 ; (at your option) any later version.
 ;
 ; Badadroid is distributed in the hope that it will be useful,
 ; but WITHOUT ANY WARRANTY; without even the implied warranty of
 ; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ; GNU General Public License for more details.
 ;
 ; You should have received a copy of the GNU General Public License
 ; along with Badadroid.  If not, see <http://www.gnu.org/licenses/>.
 ;
 ;
*/
#include "string.h"
#include "BL3.h"
#include "atag.h"

int main(runMode_t mode)
{
   void* firefoxImage = L"/e/firefox";
   void* androidImage = L"/e/android"; // TODO : find what letter for /boot
   void* recoveryImage = L"/e/recovery";
   char* cmdlnRM = "bootmode=2 loglevel=0";
   char* cmdln = "loglevel=0";
   
   unsigned char ATAG_buf[512]={0};
   t_stat filestat;
   fun_t kernel;
   int fd;
   unsigned long kernelSize=0;
   
   int mmuctrl = MemMMUCacheEnable(gMMUL1PageTable, 1);
   disp_FOTA_Init();
   disp_FOTA_Printf("*----------------------------*");
   disp_FOTA_Printf("|           Booting          |");
   disp_FOTA_Printf("*----------------------------*");
   disp_FOTA_Printf("");
   

   __PfsNandInit();
   __PfsMassInit();
   MemoryCardMount();
   
 if(mode == rm_FOTA_Firefox)
{
disp_FOTA_Printf("   FireFox");
tfs4_stat(firefoxImage, &filestat);
kernelSize = filestat.st_size;
if ((fd=tfs4_open(firefoxImage, 4)) >= 0)
{
    tfs4_read(fd, &KERNEL_BUF, kernelSize);
    tfs4_close(fd);
}
}
else
{ 
   disp_FOTA_Printf("   Android");
   tfs4_stat(androidImage, &filestat);
   kernelSize = filestat.st_size;
   if ((fd=tfs4_open(androidImage, 4)) >= 0)
   {
      tfs4_read(fd, &KERNEL_BUF, kernelSize);
      tfs4_close(fd);
   }
}   
   if (kernelSize <= 0)
   {
   disp_FOTA_Printf("Kernel Not Found in /boot");
   disp_FOTA_Printf("Starting Recovery");
   
   
   tfs4_stat(recoveryImage, &filestat);
   kernelSize = filestat.st_size;
   if ((fd=tfs4_open(recoveryImage, 4)) >= 0)
   {
      tfs4_read(fd, &KERNEL_BUF, kernelSize);
      tfs4_close(fd);
   }   
   setup_cmdline_tag(cmdlnRM);
   }

   
   
   DisableMmuCache(mmuctrl);
   _CoDisableMmu();
   
   setup_core_tag(ATAG_buf);
   setup_serial_tag(0x123, 0x456);
   setup_rev_tag('0');


if(mode == rm_FOTA_RECOVERY)
   {
       setup_cmdline_tag(cmdlnRM);
       disp_FOTA_Printf("   Recovery Mode");
}
else
   {
       setup_cmdline_tag(cmdln);
	   disp_FOTA_Printf("   Normal");
	   DRV_Modem_BootingStart();
   }	

   setup_end_tag();
   
   memcpy(&KERNEL_START, &KERNEL_BUF, kernelSize);
   *((unsigned int*)SYSCON_NORMAL_CFG) = 0xFFFFFFFF; 
   _CoDisableDCache();
   _System_DisableVIC();
   _System_DisableIRQ();
   _System_DisableFIQ();
   kernel = (fun_t)&KERNEL_START;
   kernel(0, 8500, ATAG_buf);

   
   //loop forever
   while(1);
   return 0;

}
