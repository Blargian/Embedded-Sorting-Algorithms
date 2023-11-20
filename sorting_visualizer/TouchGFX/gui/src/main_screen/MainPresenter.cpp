#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>

MainPresenter::MainPresenter(MainView& v)
    : view(v)
{

}

void MainPresenter::activate()
{

}

void MainPresenter::deactivate()
{

}

void MainPresenter::storeHistogramPoint(const int p) const {
	model->addPointToHistogram(p);
}

std::vector<int>* MainPresenter::getHistogramDataPtr() const {
	return model->getHistogramDataPtr();
}

void MainPresenter::clearHistogramDataPoints() {
	model->clearHistogram();
}
