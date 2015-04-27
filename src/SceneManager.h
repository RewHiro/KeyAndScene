#pragma once
#include "Scene.h"
#include <memory>

class SceneManager
{
	SceneType type;
	std::unique_ptr<Scene>scene;
public:
	SceneManager();
	void update();
};

