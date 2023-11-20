#include <gui/selector_screen/SelectorView.hpp>
#include <gui/selector_screen/SelectorPresenter.hpp>

SelectorPresenter::SelectorPresenter(SelectorView& v)
    : view(v)
{

}

void SelectorPresenter::activate()
{

}

void SelectorPresenter::deactivate()
{

}

void SelectorPresenter::userSetAlgorithm(AlgorithmType algo)
{
	model->setAlgorithm(algo);
}

AlgorithmType SelectorPresenter::getCurrentSelectedAlgorithm() const {
	return model->getAlgorithm();
}

uint8_t SelectorPresenter::getCurrentPageNumber() const{
	return view.getCurrentPageNumber();
}

