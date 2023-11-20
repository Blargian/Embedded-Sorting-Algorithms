#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void forceButtonState(bool b){};
    virtual void invalidateSelectButton(){};
    virtual uint8_t getCurrentPageNumber() const{};

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
