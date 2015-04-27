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
	auto& itr = key_press.find(button);

	if (itr == key_press.end())return false;
	return true;
}

bool Key::isPush(int button)
{
	auto& itr = key_push.find(button);

	if (itr == key_push.end())return false;
	key_push.erase(key_push.find(button));
	return true;
}

bool Key::isPull(int button)
{
	auto& itr = key_pull.find(button);
	if (itr == key_pull.end())return false;
	key_pull.erase(key_pull.find(button));
	return true;
}