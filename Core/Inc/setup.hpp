/*
 * setup.h
 *
 *  Created on: Sep 12, 2023
 *      Author: shaun
 */

#ifndef INC_SETUP_HPP_
#define INC_SETUP_HPP_

#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"

enum Result : uint8_t {
	OK = 0, 				 //Function has succeeded
	Fail,   			     //Function has failed
	Error_PeriphBusy,        //Function was unable to init the peripheral as it is busy
	Error_PeriphNotSupported //Function was unable to init the peripheral as it is not supported
};

enum InitState : uint8_t { NotInitialized = 0,Initialized };

enum ActiveState : uint8_t { Inactive = 0, Active };


#endif /* INC_SETUP_HPP_ */
