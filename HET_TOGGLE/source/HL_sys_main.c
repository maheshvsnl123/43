/** @file HL_sys_main.c 
*   @brief Application main file
*   @date 28.Aug.2015
*   @version 04.05.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2015 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
#include "HL_het.h"
/* USER CODE END */

/* Include Files */

#include "HL_sys_common.h"

/* USER CODE BEGIN (1) */
	uint32_t i;															// Create a 32 bit integer variable for counting cycles
	uint32_t hetp1DIR;													// Create a 32 bit integer variable for HET PORT1 direction
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

void main(void)
{
/* USER CODE BEGIN (3) */
	hetp1DIR = 0xFFFFFFFF;
	gioSetDirection(hetPORT1, hetp1DIR);								// Set hetPORT1 direction to all output
	while(1){															// Start an infinite loop
		gioSetBit(hetPORT1, 1, 1);										// Set the HET1_1 pin
		gioSetBit(hetPORT1, 2, 0);										// Clear the HET1_2 pin
		for (i=0; i<27272727; i++);										// The For loop takes 11 MC, hence 300M/11 = 27272727 MC for 1 sec
		gioSetBit(hetPORT1, 1, 0);										// Clear the HET1_1 pin
		gioSetBit(hetPORT1, 2, 1);										// Set the HET1_2 pin
		for (i=0; i<27272727; i++);
	}
/* USER CODE END */
}

/* USER CODE BEGIN (4) */
	void gioNotification(int bit){
		return;															// Declared just to avoid compilation errors (required for HET)
	}
	void esmGroup1Notification(int bit){
		return;															// Declared just to avoid compilation errors (required for HET)
	}
	void esmGroup2Notification(int bit){
		return;															// Declared just to avoid compilation errors (required for HET)
	}
/* USER CODE END */