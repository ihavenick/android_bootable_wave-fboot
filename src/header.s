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
   .arch armv5te
   .fpu softvfp 
   .org 0x00
   .text
   .global FOTA_start
   .type FOTA_start, %function

FOTA_start:   
   STMFD   SP!, {R0-R12,LR}
   BL      checkFBOOT
   cmp     r0, #0
   beq     BL3_return
   str     r0, a_mode
   BL      getBL3ptrs
   cmp     r0, #0
   beq     BL3_shadow
   b       run_FBOOT
   
   ;BL3_shadow: 
   ;BL      BL3_Shadowing
   ;LDMFD   SP!, {R0-R12,LR}
   ;ldr     pc, a_bl3
   
   BL3_return: 
   LDMFD   SP!, {R0-R12,PC}
   
   run_FBOOT:
   LDMFD   SP!, {R0-R12,LR}
   ldr     r0, a_mode
   ldr     pc, a_jump

   
   
   .org 0x100
   .asciz "FOTA_ENGINE_VER_INFO_2.0"
   .org 0x200
   .word __fota_start
   a_jump: .word main
   a_bl3:  .word BL3_DRAM_START
   a_mode: .word 0
   