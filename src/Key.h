#pragma once
#include "cinder\app\KeyEvent.h"
#include <set>
#include <array>

//�@set��map�ɂ���
//�@�F��
//�@set -> �ǂ�ȐF�����邩
//�@map -> �ǂ̉�f�̏ꏊ�ɐF�����邩�A�F�̌�

class Key : private boost::noncopyable
{
	std::set<int>key_press;
	std::set<int>key_pull;
	std::set<int>key_push;
	Key();
public:
	static Key& GetInstance();
	void setKeyPress(int button);
	void popKeyPress(int button);

	void setKeyPull(int button);
	void popKeyPull(int button);

	bool isPress(int button);
	bool isPush(int button);
	bool isPull(int button);
};

