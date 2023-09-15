/*
 * RNG.h
 *
 *  Created on: Sep 12, 2023
 *      Author: shaun
 */

#ifndef INC_RNG_HPP_
#define INC_RNG_HPP_

#include <setup.hpp>
#include <vector>

//Setup the class as a singleton as there is only one RNG peripheral

class RandomNumberGenerator {
private:
	InitState m_eInitState;

	RNG_HandleTypeDef m_sHandle;

	// constructor
	RandomNumberGenerator() :
			m_eInitState(NotInitialized),
			m_sHandle({0})
			{};
public:

	//Deleted copy constructor and assignment operator
	RandomNumberGenerator(const RandomNumberGenerator& other) = delete;
	RandomNumberGenerator& operator=(const RandomNumberGenerator& other) = delete;

	// -----------------
	// Singleton Methods

	static RandomNumberGenerator& getInstance(void) {
		static RandomNumberGenerator instance;
		return instance;
	};

	// ----------------------
	// Initialization Methods

	//Initializes the RNG peripheral
	//Returns QA_OK if the init is successful or QA_FAIL if it is unsuccessful
	static Result init(void) {
		return getInstance().imp_init();
	};

	//Used to deinitialize the RNG peripheral
	static void deinit(void) {
		getInstance().imp_deinit();
	};

	// ------------
	// Data Methods

	static InitState getInitState(void) {
		return getInstance().m_eInitState;
	};

	static uint32_t getValue(void) {
		return getInstance().imp_getValue();
	};

	//takes in a vector of size n and fills it with n random 8 bit numbers
	static void fillVectorWithRand(std::vector<uint8_t>& vector) {
		getInstance().imp_fillVectorWithRand(vector);
	};


private:

	Result imp_init(void);
	void imp_deinit(void);
	uint32_t imp_getValue(void);
	void imp_fillVectorWithRand(std::vector<uint8_t>& vector);

};



#endif /* INC_RNG_HPP_ */
