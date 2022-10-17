#pragma once
#include"Player.h"
#include"Viewer.h"
#include"Chess.h"
#include<vector>
using namespace std;
class GameManager {
public:
	GameManager() {
		current_player = 1;
		chess.clear();
	}
	//bool keepPlay();	//���Ѫ��a��ܬO�_�b���@��
	int showMenu();	//��ܥD���
	void showBoard();	//�N�ѽL��ܥX��
	//vector<pos> showPath(Board board,int current_player, struct pos p);	//�ˬd�i���ʸ��|
	//void update();	//��s�ѽL
	//void setBoard();	//�إߴѽL
	int isOver();	//�ˬd�C���O�_���� //3 �ճQ�N�x 2�³Q�N�x 1�M�� 0������
	void setChess();	//�N�X�l��m��l��
	int findWhichChess(pos p);	//���J��m���X�l�O����
	int findWhichChess(pos p, int a);
	int moveChess();	//�ʺX�l
	void whichNeedPromote();	//�䦳�S���X�l�ݭnpromote
	bool isNumber(string input);
	int getCurrent_player() { return current_player; }
	int  getCheck() { return check; }
	void setCheck(int _check) { check = _check; }
	int findOtherChess(pos p);
	void setCurrent_player(int current_player) { this->current_player = current_player; }


private:
	Player* player[2];
	int current_player;
	Viewer viewer;
	vector<Piece*> chess;
	int check = 0;	//1 �ճQ�N�x -1�³Q�N�x
	vector<vector<pos>>allChessWalk;
};
