#ifndef MODEL_HPP
#define MODEL_HPP

#include "algorithm_types.hpp"
#include <stdint.h>
#include <vector>
#include <memory>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();


    AlgorithmType getAlgorithm() const {
    	return _selected_algorithm;
    };

    void setAlgorithm(AlgorithmType a) {
    	_selected_algorithm = a;
    };

    void setCurrentPageNumber(uint8_t pageNumber) {
    	_currentPageNumber = pageNumber;
    }

    uint8_t getCurrentPageNumber() const {
    	return _currentPageNumber;
    }

    std::vector<int>* getHistogramDataPtr() const {
    	return _spHistogram.get();
    }

    void addPointToHistogram(const int p) {
    	auto pHistogram = getHistogramDataPtr();
    	pHistogram->push_back(p);
    }

    void clearHistogram() {
    	auto pHistogram = getHistogramDataPtr();
    	pHistogram->clear();
    }

protected:
    ModelListener* modelListener;

private:
    AlgorithmType _selected_algorithm = quicksort;
    uint8_t _currentPageNumber = 0;
    std::shared_ptr<std::vector<int>> _spHistogram = std::make_shared<std::vector<int>>();
};



#endif // MODEL_HPP
