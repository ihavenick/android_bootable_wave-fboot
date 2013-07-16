/*
 * s5pc110.h
 *
 *  Created on: 07-02-2012
 *      Author: Rebell
 */

#ifndef S5PC110_H_
#define S5PC110_H_

#define KEYPAD_BASE_ADDR	0xE1600000
#define KEYIFCON   			(*(volatile unsigned long *)(KEYPAD_BASE_ADDR + 0x00))
#define KEYIFSTSCLR   		(*(volatile unsigned long *)(KEYPAD_BASE_ADDR + 0x04))
#define KEYIFCOL   			(*(volatile unsigned long *)(KEYPAD_BASE_ADDR + 0x08))
#define KEYIFROW   			(*(volatile unsigned long *)(KEYPAD_BASE_ADDR + 0x0C))
#define KEYIFFC  			(*(volatile unsigned long *)(KEYPAD_BASE_ADDR + 0x10))

#define SYSCON_NORMAL_CFG  0xE010C010

void DisableMmuCache(int desc);
void _CoDisableMmu(void);
void _CoDisableDCache(void);
void _System_DisableVIC(void);
void _System_DisableIRQ(void);
void _System_DisableFIQ(void);


#endif /* S5PC110_H_ */
