#ifndef SELECTORVIEW_HPP
#define SELECTORVIEW_HPP

#include <gui_generated/selector_screen/SelectorViewBase.hpp>
#include <gui/selector_screen/SelectorPresenter.hpp>

class SelectorView : public SelectorViewBase
{
public:
    SelectorView();
    virtual ~SelectorView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void selectAlgorithm();
protected:
};

#endif // SELECTORVIEW_HPP
