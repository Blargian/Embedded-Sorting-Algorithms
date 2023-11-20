/*
 * RNGSingleton.cpp
 *
 *  Created on: Sep 19, 2023
 *      Author: shaun
 */

#include "RNGSingleton.h"

RNGSingleton* RNGSingleton::_instance = nullptr;

result RNGSingleton::impl_init(){
	if(_rngInitState){
		return OK;
	};

	__HAL_RCC_RNG_CLK_ENABLE();
	__HAL_RCC_RNG_FORCE_RESET();
	__HAL_RCC_RNG_RELEASE_RESET();

	_rngHandle.Instance = RNG;
	if(HAL_RNG_Init(&_rngHandle) != HAL_OK) {
		__HAL_RCC_RNG_CLK_DISABLE();
		return FAIL;
	};

	_rngInitState = Initialized;

	return OK;
};

void RNGSingleton::impl_deinit(){
	if (!_rngInitState)
	  	return;

	//Deinitialize RNG Peripheral
	HAL_RNG_DeInit(&_rngHandle);

	//Disable RNG Peripheral Clock
	__HAL_RCC_RNG_CLK_DISABLE();

	_rngInitState = NotInitialized;
};

uint32_t RNGSingleton::impl_getValue() {
	if(!_rngInitState)
		return 0;

	uint32_t value = 0;
	HAL_RNG_GenerateRandomNumber(&_rngHandle, &value);
	return value;
}

