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
   .text
   
   .org 0
   .ascii "BPDZ"
   .org 0x10
   .word 0xABCDABCD
   .word FOTA_NAND_START
   .word 0
   .byte 'S'
   .word MODEL
   .org 0x3C
   .ascii "fota"
   .word 0
   .word 6
   .word 1
   .word 2
   .word 0x800
   .word 0x20000
   .org 0x40C
   .word 0
   