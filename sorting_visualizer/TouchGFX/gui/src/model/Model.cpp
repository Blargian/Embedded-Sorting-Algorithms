#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <memory>

Model::Model() : modelListener(0)
{
	_spHistogram = std::make_shared<std::vector<int>>();
}

void Model::tick()
{

}
