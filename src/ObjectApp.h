#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneManager.h"
#include "Key.h"

using namespace ci;
using namespace ci::app;

class ObjectApp : public AppNative {
	SceneManager scene_manager;

  public:
	void setup();
	void mouseDown( MouseEvent event );
	void prepareSetting(Settings* settings);
	void update();
	void draw();
	void keyDown(KeyEvent event)
	{
		Key::GetInstance().setKeyPress(event.getCode());
	}
	void keyUp(KeyEvent event)
	{
		Key::GetInstance().popKeyPress(event.getCode());
		Key::GetInstance().setKeyPull(event.getCode());
	}
};

void ObjectApp::setup()
{
	Key::GetInstance();
}

void ObjectApp::mouseDown( MouseEvent event )
{
}

void ObjectApp::update()
{
}

void ObjectApp::draw()
{
	// clear out the window with black
	gl::clear(); 
	gl::pushMatrices();
	gl::translate(getWindowCenter());
	scene_manager.update();
	gl::popMatrices();


	Key& key = Key::GetInstance();

	if(key.isPush(KeyEvent::KEY_w))
	{
		console() << "W" << std::endl;
	}
	if (key.isPush(KeyEvent::KEY_s))
	{
		console() << "S" << std::endl;
	}
	if(key.isPress(KeyEvent::KEY_a))
	{
		console() << "A" << std::endl;
	}
	if (key.isPress(KeyEvent::KEY_d))
	{
		console() << "D" << std::endl;
	}
	if(key.isPull(KeyEvent::KEY_f))
	{
		console() << "F" << std::endl;
	}
	if (key.isPull(KeyEvent::KEY_g))
	{
		console() << "G" << std::endl;
	}


}

CINDER_APP_NATIVE( ObjectApp, RendererGl )
