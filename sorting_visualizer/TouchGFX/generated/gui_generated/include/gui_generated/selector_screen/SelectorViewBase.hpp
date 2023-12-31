/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SELECTORVIEWBASE_HPP
#define SELECTORVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/selector_screen/SelectorPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/SwipeContainer.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>

class SelectorViewBase : public touchgfx::View<SelectorPresenter>
{
public:
    SelectorViewBase();
    virtual ~SelectorViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box bg;
    touchgfx::SwipeContainer swipeContainer1;
    touchgfx::Container QuickSort;
    touchgfx::Image QuickSortIcon;
    touchgfx::Container BubbleSort;
    touchgfx::Image BubbleSortIcon;
    touchgfx::Container MergeSort;
    touchgfx::Image MergeSortIcon;
    touchgfx::Button back_to_main;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<SelectorViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SELECTORVIEWBASE_HPP
