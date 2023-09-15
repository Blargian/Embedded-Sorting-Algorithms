/*
 * RNG.cpp
 *
 *  Created on: Sep 12, 2023
 *      Author: shaun
 */

#include <RNG.hpp>

Result RandomNumberGenerator::imp_init(void) {

	if(m_eInitState)
		return OK;

	__HAL_RCC_RNG_CLK_ENABLE();
	__HAL_RCC_RNG_FORCE_RESET();
	__HAL_RCC_RNG_RELEASE_RESET();

	m_sHandle.Instance = RNG;
	if (HAL_RNG_Init(&m_sHandle) != HAL_OK) {
		__HAL_RCC_RNG_CLK_DISABLE();
		return Fail;
	}

	m_eInitState = Initialized;

	return OK;
};

void RandomNumberGenerator::imp_deinit(void) {
	if (!m_eInitState)
		return;

	HAL_RNG_DeInit(&m_sHandle);

	__HAL_RCC_RNG_CLK_DISABLE();

	m_eInitState = NotInitialized;
};

uint32_t RandomNumberGenerator::imp_getValue(void) {
	if(!m_eInitState)
		return 0;

	uint32_t rand_val = 0;
	HAL_RNG_GenerateRandomNumber(&m_sHandle, &rand_val);
	return rand_val;
}

//takes in a vector of size n and fills it with n random 8 bit numbers
void RandomNumberGenerator::imp_fillVectorWithRand(std::vector<uint8_t>& vector){
	uint32_t number32bit;
	uint8_t number8bit;

	for(size_t i=0; i < vector.size(); i++) {
		number32bit = imp_getValue();
		number8bit = number32bit & 0x007F; //keep only the lowest 8 of the 32 bits
		vector.push_back(number8bit);
	};
};


