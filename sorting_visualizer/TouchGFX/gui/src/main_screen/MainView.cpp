#include <gui/main_screen/MainView.hpp>
#include "RNGSingleton.h"

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::randomizeGraph(){

	const int graph_size = histogram.getMaxCapacity();
	int value = 0;

	histogram.clear();
	if(RNGSingleton::InitRNG()==OK){
		for(int i =0; i < graph_size; i++) {
			value = RNGSingleton::GetValue() & 0x00F0; // bitwise & to make 32bit number an 8 bit number
			histogram.addDataPoint(i, value);
		}
	} else {

	}

	touchgfx_printf("buttonUpClicked\n");
}
