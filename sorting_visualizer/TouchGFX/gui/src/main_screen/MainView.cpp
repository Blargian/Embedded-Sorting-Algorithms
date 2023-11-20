#include <gui/main_screen/MainView.hpp>
#include "RNGSingleton.h"

MainView::MainView()
{

}

//load histogram data into the touchgfx histogram element
void MainView::setupScreen()
{
	auto pHistogramData = presenter->getHistogramDataPtr();
	if(pHistogramData->size()!=0){
		histogram.clear();
		for (auto it = pHistogramData->begin(); it < pHistogramData->end(); it++) {
			histogram.addDataPoint(std::distance(pHistogramData->begin(),it), *it);
		}
	} else {
		histogram.clear();
		presenter->clearHistogramDataPoints();
		randomizeGraph();
	}
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
	presenter->clearHistogramDataPoints();

	if(RNGSingleton::InitRNG()==OK){
		for(int i =0; i < graph_size; i++) {
			value = RNGSingleton::GetValue() & 0x00F0; // bitwise & to make 32bit number an 8 bit number
			presenter->storeHistogramPoint(value);
			histogram.addDataPoint(i, value);
		}
	} else {

	}

	touchgfx_printf("buttonUpClicked\n");
}
