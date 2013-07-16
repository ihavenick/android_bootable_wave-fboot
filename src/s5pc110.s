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
   .global _CoDisableMmu
   .type _CoDisableMmu, %function
   .global _CoDisableDCache
   .type _CoDisableDCache, %function
   .global _System_DisableVIC
   .type _System_DisableVIC, %function
   .global _System_DisableIRQ
   .type _System_DisableIRQ, %function
   .global _System_DisableFIQ
   .type _System_DisableFIQ, %function
   .global DisableMmuCache
   .type DisableMmuCache, %function

DisableMmuCache:
   MCR	p15, 0, R0,c1,c0
	MOV	PC, LR
   
_CoDisableMmu:
	MRC	p15, 0, R0,c1,c0
	BIC	R0, R0, #1
	MCR	p15, 0, R0,c1,c0
	MOV	PC, LR
   
_CoDisableDCache:
	MRC	p15, 0, R0,c1,c0
	BIC	R0, R0, #4
	MCR	p15, 0, R0,c1,c0
	MOV	PC, LR

_System_DisableVIC:
	MRC	p15, 0, R0,c1,c0
	BIC	R0, R0, #0x1000000
	MCR	p15, 0, R0,c1,c0
	BX	LR

_System_DisableIRQ:
	MRS	R0, CPSR
	ORR	R0, R0, #0x80
	MSR	CPSR_cxsf, R0
	BX	LR

_System_DisableFIQ:
	MRS	R0, CPSR
	ORR	R0, R0, #0x40
	MSR	CPSR_cxsf, R0
	BX	LR
   
