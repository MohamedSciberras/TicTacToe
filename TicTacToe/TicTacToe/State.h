#pragma once
class State
{
public:
	
	enum GAMESTATE
	{
		START,
		NEWGAME,
		RUNNING,
		WIN,
		LOSE,
		DRAW,
		GAMEOVER
	};


	static int ChangeState(int nextState);

private:
};

