#include "SceneManager.h"
#include "Title.h"

SceneManager::SceneManager():
type(SceneType::TITLE),
scene(std::make_unique<Title>())
{

}

void SceneManager::update()
{
	scene->update();
	scene->draw();
}