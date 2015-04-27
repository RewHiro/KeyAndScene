#include "Title.h"
#include "cinder\gl\gl.h"

using namespace cinder;

Title::Title()
{
}


SceneType Title::update()
{
	return getSceneType();
}
void Title::draw()
{
	gl::color(Color::white());
	auto rect = Rectf(0, 0, 125, 125);
	gl::drawSolidRect(rect);
}