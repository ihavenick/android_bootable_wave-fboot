/*
 ; This file is part of Badadroid project.
 ;
 ; Copyright (C) 2012 Rebellos, mijoma, b_kubica
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
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(main)
MODEL = 0x30333538;
FOTA_NAND_START = 0x09500000;
BL3_DRAM_START = 0x42080000;
KERNEL_BUF = 0x44400000;
KERNEL_START = 0x22000000;
MEMORY 
{
    fota (i)  : ORIGIN = 0x43200000, LENGTH = 0x280010
}
SECTIONS
{
  .header 0x43200000: { obj/header.o (.text) } > fota
  .footer 0x43480000: {obj/footer.o (.text)}
   __fota_start = ADDR(.header);
  
  
  . = __fota_start + 0x300;
  .text : 
  { 
   *(.text) 
  }
  .data : { *(.data) } 
  .bss 0x44000000:  { *(.bss) } 

  
} 