//abstract_player.h
#pragma once

using namespace std;

namespace a5 {
	class Player
	{
	public:
		virtual ~Player() { }
		virtual void input(Game& B) = 0;
	};
}