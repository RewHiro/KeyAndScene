#include "Key.h"


Key::Key()
{

}

Key& Key::GetInstance()
{
	static Key key;
	return key;
}

void Key::setKeyPress(int button)
{
	if (key_press.find(button) == key_press.end()){
		key_push.emplace(button);
	}
	key_press.emplace(button);
}

void Key::popKeyPress(int button)
{
	key_press.erase(key_press.find(button));
}

void Key::setKeyPull(int button)
{
	key_pull.emplace(button);
}

void Key::popKeyPull(int button)
{
	key_pull.erase(key_pull.find(button));
}

bool Key::isPress(int button)
{
	return key_press.find(button) != key_press.end();
}

bool Key::isPush(int button)
{
	if (key_push.find(button) == key_push.end())return false;
	key_push.erase(key_push.find(button));
	return true;
}

bool Key::isPull(int button)
{
	if (key_pull.find(button) == key_pull.end())return false;
	key_pull.erase(key_pull.find(button));
	return true;
}