#pragma once

enum class SceneType
{
	TITLE,
	STAGE,
	RESULT
};

class Scene
{
	SceneType type;
protected:
	SceneType getSceneType()const{ return type; }
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual SceneType update() = 0;
	virtual void draw() = 0;

	void loadScene(const SceneType type){ this->type = type; }
};

