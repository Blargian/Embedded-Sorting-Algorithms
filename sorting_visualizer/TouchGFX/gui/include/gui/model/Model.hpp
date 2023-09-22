#ifndef MODEL_HPP
#define MODEL_HPP

#include "algorithm_types.hpp"

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

    inline AlgorithmType GetAlgorithm() const {
    	return _selected_algorithm;
    };

    void SetAlgorithm(AlgorithmType a) {
    	_selected_algorithm = a;
    };

protected:
    ModelListener* modelListener;

private:
    AlgorithmType _selected_algorithm = quicksort;
};



#endif // MODEL_HPP
