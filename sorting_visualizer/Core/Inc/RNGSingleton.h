#ifndef INC_RNGSINGLETON_HPP_
#define INC_RNGSINGLETON_HPP_

#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"

enum result : uint8_t {
	OK = 0, 				 //Function has succeeded
	FAIL,   			     //Function has failed
	ERR_PeriphBusy,          //Function was unable to init the peripheral as it is busy
	ERR_PeriphNotSupported   //Function was unable to init the peripheral as it is not supported
};

enum initState : uint8_t { NotInitialized = 0,Initialized };
enum activeState : uint8_t { Inactive = 0, Active };

class RNGSingleton {
	private:
		RNG_HandleTypeDef _rngHandle;
		initState _rngInitState;
		static RNGSingleton* _instance;

		RNGSingleton() :
			_rngHandle({0}),
			_rngInitState(NotInitialized)
		{};

		//RNGSingleton() = default;

		//delete copy constructor and copy assignment operator
		RNGSingleton(const RNGSingleton& rhs) = delete;
		RNGSingleton& operator=(const RNGSingleton& rhs) = delete;

		//implementation declarations
		result impl_init();
		void impl_deinit();
		uint32_t impl_getValue();

	public:

		static RNGSingleton& Instance() {
			if(_instance==nullptr){
				_instance = new RNGSingleton();
				return *_instance;
			};
			return *_instance;
		};

		~RNGSingleton(){
			delete _instance;
			_instance = nullptr;
		};

		static result InitRNG(){
			return Instance().impl_init();
		};

		static void DeinitRNG(){
			Instance().impl_deinit();
		};

		static initState GetInitState(){
			return Instance()._rngInitState;
		};

		static uint32_t GetValue(){
			return Instance().impl_getValue();
		};

};

#endif /* INC_RNG_HPP_ */
