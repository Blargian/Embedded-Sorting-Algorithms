#include <gui/selector_screen/SelectorView.hpp>
#include "algorithm_types.hpp"

SelectorView::SelectorView()
{

}

void SelectorView::setupScreen()
{
    SelectorViewBase::setupScreen();

    //Retrieve state of the selected algorithm and set the corresponding page
    AlgorithmType current_algo = presenter->getCurrentSelectedAlgorithm();
    swipeContainer1.setSelectedPage(static_cast<uint8_t>(current_algo));
}

void SelectorView::tearDownScreen()
{
    SelectorViewBase::tearDownScreen();
}

void SelectorView::selectAlgorithm(){
	AlgorithmType algo = static_cast<AlgorithmType>(swipeContainer1.getSelectedPage());
	presenter->userSetAlgorithm(algo);
}
