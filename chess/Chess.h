#pragma once
#include<iostream>
#include<vector>

using namespace std;

struct pos {
	int x;
	int y;
};

enum Type {
	none = 0,
	king = 1,
	queen = 2,
	bishop = 3,
	rook = 4,
	knight = 5,
	pawn = 6
};

class Piece
{
public:
	Piece() { type = Type::none; position = { -1,-1 }; firstMove = false; }
	Piece(pos _pos, bool _firstmove) { position = _pos; firstMove = _firstmove; }

	//set
	void setType(int _type) { type = _type; }
	void setPos(pos _pos) { position = _pos; }
	void setFirstMove(bool _firstMove) { firstMove = _firstMove; }

	//get
	int getType() { return type; }
	pos getPos() { return position; }
	bool getFirstMove() { return firstMove; }

	/**********************************************************************************/
	//�����ѽL�W�Y���� �Ҧ��i�첾��position   index��ܬ����@�ӺX�l
	virtual vector<pos> collectWalk(vector<Piece*> allChess, int index) { vector<pos>a; return a; }

	//�P�_�O�_����ɩΤW�����X�l  �L��2 ���Ѭ��v���0 ���Ѭ��Ĥ��1
	int posCouldWalk(vector<Piece*>allChess, pos checkPos, bool firstmove)
	{
		for (auto it : allChess)
		{
			pos tmp = it->getPos();
			//����m���Ѥl
			if (tmp.x == checkPos.x && tmp.y == checkPos.y)
			{
				//���v���
				if (firstmove == it->getFirstMove())
				{
					return 0;
				}
				//���Ĥ��
				else
				{
					return 1;
				}
			}
		}
		//�L�Ѥl
		return 2;
	}
	/***************************************************************************************/
	//~Piece();
private:
	int type = Type::none;
	pos position;
	bool firstMove;
};

class Bishop :public Piece
{
public:
	Bishop() : Piece()
	{
	}
	Bishop(pos _pos, bool _firstmove) : Piece(_pos, _firstmove)
	{
		this->setType(Type::bishop);
	}
	vector<pos> collectWalk(vector<Piece*> allChess, int index) override
	{
		vector<pos>validPos;
		pos _pos = allChess[index]->getPos();

		// lu ld ru rd
		vector<pair<int, int>> dirBase;
		pair<int, int> dir = { -1,-1 };
		dirBase.push_back(dir);
		dir = { -1, 1 };
		dirBase.push_back(dir);
		dir = { 1, -1 };
		dirBase.push_back(dir);
		dir = { 1, 1 };
		dirBase.push_back(dir);

		//collect all possible walk
		for (int i = 0; i < 8; i++)
		{
			bool yetDone = false;
			for (int j = 0; j < dirBase.size(); j++)
			{
				pos tmp;
				tmp.x = _pos.x + (i + 1) * dirBase[j].first;
				tmp.y = _pos.y + (i + 1) * dirBase[j].second;

				//��a�Ϥ�
				if (tmp.x > -1 && tmp.x < 8 && tmp.y > -1 && tmp.y < 8)
				{
					// ���Ѭ��v���0 ���Ѭ��Ĥ��1 �L��2
					int infoPos = posCouldWalk(allChess, tmp, allChess[index]->getFirstMove());

					//�L��2
					if (infoPos == 2)
					{
						validPos.push_back(tmp);
						yetDone = true;
						continue;
					}
					//���Ѭ��Ĥ��1
					else if (infoPos == 1)
					{
						validPos.push_back(tmp);
						yetDone = true;
					}
				}
				dirBase.erase(dirBase.begin() + j);
				j--;
			}
			if (!yetDone)
			{
				break;
			}
		}
		return validPos;
	}

private:

};

class Rook :public Piece
{
public:
	Rook() : Piece()
	{
	}
	Rook(pos _pos, bool _firstmove) : Piece(_pos, _firstmove)
	{
		this->setType(Type::rook);
	}
	vector<pos> collectWalk(vector<Piece*> allChess, int index) override
	{
		vector<pos>validPos;
		pos _pos = allChess[index]->getPos();

		// l r u d
		vector<pair<int, int>> dirBase;
		pair<int, int> dir = { -1,0 };
		dirBase.push_back(dir);
		dir = { 1, 0 };
		dirBase.push_back(dir);
		dir = { 0, -1 };
		dirBase.push_back(dir);
		dir = { 0, 1 };
		dirBase.push_back(dir);


		//collect all possible walk
		for (int i = 0; i < 8; i++)
		{
			bool yetDone = false;
			for (int j = 0; j < dirBase.size(); j++)
			{
				pos tmp;
				tmp.x = _pos.x + (i + 1) * dirBase[j].first;
				tmp.y = _pos.y + (i + 1) * dirBase[j].second;

				//��a�Ϥ�
				if (tmp.x > -1 && tmp.x < 8 && tmp.y > -1 && tmp.y < 8)
				{
					// ���Ѭ��v���0 ���Ѭ��Ĥ��1 �L��2
					int infoPos = posCouldWalk(allChess, tmp, allChess[index]->getFirstMove());

					//�L��2
					if (infoPos == 2)
					{
						validPos.push_back(tmp);
						yetDone = true;
						continue;
					}
					//���Ѭ��Ĥ��1
					else if (infoPos == 1)
					{
						validPos.push_back(tmp);
						yetDone = true;
					}
				}
				dirBase.erase(dirBase.begin() + j);
				j--;
			}
			if (!yetDone)
			{
				break;
			}
		}
		return validPos;
	}


private:

};

class Knight :public Piece
{
private:
public:
	Knight(pos _pos, bool _firstmove) : Piece(_pos, _firstmove)
	{
		this->setType(Type::knight);
	}

	vector<pos> collectWalk(vector<Piece*> allChess, int index) override
	{
		vector<pos> validPos;
		pos position = this->getPos(); //�ثe�X�l��m
		//�K�ӥi�઺��m
		pair<int, int> Base[8] = { {1,2 }, { 1,-2 },{-1,-2 },{-1,2},{2,1},{2,-1},{-2,1},{-2,-1} };

		for (int i = 0; i < 8; i++)
		{
			pos tmp;
			tmp.x = position.x + Base[i].first;
			tmp.y = position.y + Base[i].second;

			//��a�Ϥ�
			if (tmp.x > -1 && tmp.x < 8 && tmp.y > -1 && tmp.y < 8)
			{
				//�B���a���� �� ���Ѧ��D�v��� 
				if (posCouldWalk(allChess, tmp, allChess[index]->getFirstMove()))
				{
					validPos.push_back(tmp);
				}
			}
		}
		return validPos; //�̫�N�e���^�Ǧ^�h
	}

};

class Queen :public Piece
{
public:
	Queen() : Piece()
	{
	}
	Queen(pos _pos, bool _firstmove) : Piece(_pos, _firstmove)
	{
		this->setType(Type::queen);
	}
	vector<pos> collectWalk(vector<Piece*> allChess, int index) override
	{
		vector<pos>validPos;
		pos _pos = allChess[index]->getPos();

		//lu ld ru rd   l r u d
		vector<pair<int, int>> dirBase;
		pair<int, int> dir = { -1,-1 };
		dirBase.push_back(dir);
		dir = { -1, 1 };
		dirBase.push_back(dir);
		dir = { 1, -1 };
		dirBase.push_back(dir);
		dir = { 1, 1 };
		dirBase.push_back(dir);

		dir = { -1,0 };
		dirBase.push_back(dir);
		dir = { 1, 0 };
		dirBase.push_back(dir);
		dir = { 0, -1 };
		dirBase.push_back(dir);
		dir = { 0, 1 };
		dirBase.push_back(dir);


		//collect all possible walk
		for (int i = 0; i < 8; i++)
		{
			bool yetDone = false;
			for (int j = 0; j < dirBase.size(); j++)
			{
				pos tmp;
				tmp.x = _pos.x + (i + 1) * dirBase[j].first;
				tmp.y = _pos.y + (i + 1) * dirBase[j].second;

				//��a�Ϥ�
				if (tmp.x > -1 && tmp.x < 8 && tmp.y > -1 && tmp.y < 8)
				{
					// ���Ѭ��v���0 ���Ѭ��Ĥ��1 �L��2
					int infoPos = posCouldWalk(allChess, tmp, allChess[index]->getFirstMove());

					//�L��2
					if (infoPos == 2)
					{
						validPos.push_back(tmp);
						yetDone = true;
						continue;
					}
					//���Ѭ��Ĥ��1
					else if (infoPos == 1)
					{
						validPos.push_back(tmp);
						yetDone = true;
					}
				}
				dirBase.erase(dirBase.begin() + j);
				j--;
			}
			if (!yetDone)
			{
				break;
			}
		}
		return validPos;
	}

private:

};

//���]�t�Y�L���L  ���Y�L���L�O��ܩʪ��A�Y�n�i��A�N�n�b��訫�ѫ᪺�U�@�B���W�i��A�_�h�N���h���|�C
//�u��Y�ת� ���o����Q��
class Pawn :public Piece
{
private:
	/*bool En_passant = 0;
	pos eatPass;*/
public:

	Pawn(pos _pos, bool _firstmove) : Piece(_pos, _firstmove)
	{
		this->setType(Type::pawn);
	}

	/*bool get_En()
	{
	 return this->En_passant;
	}*/

	/*void set_En(bool a)
	{
	 this->En_passant = a;
	}

	void set_eatPass(pos a)
	{
	 this->eatPass = a;
	}*/

	vector<pos> collectWalk(vector<Piece*> allChess, int index) override
	{
		vector<pos> validPos;
		pos position = this->getPos(); //�ثe�X�l��m

		vector<pair<int, int>> base;
		base.push_back({ 1,-1 });
		base.push_back({ -1,-1 });
		base.push_back({ 0,-1 });
		//�L�����B�� �Ҷq�i���G�B
		if ((position.y == 1 && !this->getFirstMove()) || (position.y == 6 && this->getFirstMove()))
		{
			base.push_back({ 0,-2 });
		}
		//�Y���¤� �h�אּ���U��
		if (!this->getFirstMove())
		{
			for (auto& it : base)
			{
				it.second *= -1;
			}
		}

		pos checkPos;
		//���� �Y��
		for (int i = 0; i < 2; i++)
		{
			checkPos.x = position.x + base[i].first;
			checkPos.y = position.y + base[i].second;
			//�b�a�Ϥ�
			if (checkPos.x > -1 && checkPos.x < 8 && checkPos.y > -1 && checkPos.y < 8)
			{
				//�Y�L���L

				//�d��Ҧ��Ѥl
				for (auto it : allChess)
				{
					pos tmp = it->getPos();
					//�O�_����m���Ѥl�B���Ĥ�ѥi�Y�� �N��i��
					if (tmp.x == checkPos.x && tmp.y == checkPos.y && it->getFirstMove() != this->getFirstMove())
					{
						validPos.push_back(checkPos);
						break;
					}
				}
			}
		}
		// ���e
		bool flag = 0; //�ˬd�e��O�_���Ѥl����
		for (int i = 2; i < base.size(); i++)
		{
			checkPos.x = position.x + base[i].first;
			checkPos.y = position.y + base[i].second;
			//�b�a�Ϥ�
			if (checkPos.x > -1 && checkPos.x < 8 && checkPos.y > -1 && checkPos.y < 8)
			{
				//�B���a���� �� ���Ĥ�ѥi�Y 
				if (posCouldWalk(allChess, checkPos, allChess[index]->getFirstMove()) == 2)
				{
					validPos.push_back(checkPos);
				}
				else if (posCouldWalk(allChess, checkPos, allChess[index]->getFirstMove()) == 1)
				{
					if (i == 2)
					{
						flag = 1; //�e���ɴѤl
					}
					break;
				}
			}
			//if (this->En_passant == 1 && flag == 0)
			//{
			// if (this->getFirstMove()) //��
			// {
			//  pos temp = this->eatPass; //�W�Ӥp�L����m
			//  temp.y - 1;
			//  validPos.push_back(temp);
			// }
			// else if(!this->getFirstMove()) //��
			// {
			//  pos temp = this->eatPass;
			//  temp.y + 1;
			//  validPos.push_back(temp);
			// }
			//}
		}



		return validPos; //�̫�N�e���^�Ǧ^�h
	}






};
class King :public Piece
{
private:

public:
	King() : Piece()
	{
	}
	King(pos _pos, bool _firstmove) : Piece(_pos, _firstmove)
	{
		this->setType(Type::king);
	}

	vector<pos> collectWalk(vector<Piece*> allChess, int index) override
	{
		vector<pos>validPos;
		pos _pos = allChess[index]->getPos();

		//lu ld ru rd l r u d
		pair<int, int> dirBase[8] = { {-1,-1 }, {-1, 1}, {1, -1}, {1, 1},{-1,0 }, {1, 0}, {0, -1}, {0, 1} };
		//collect all possible walk

		for (int i = 0; i < 8; i++)
		{
			pos tmp;
			tmp.x = _pos.x + dirBase[i].first;
			tmp.y = _pos.y + dirBase[i].second;
			//��a�Ϥ�
			if (tmp.x > -1 && tmp.x < 8 && tmp.y > -1 && tmp.y < 8)
			{
				//�B���a���� �� ���Ѧ��D�v��� 
				if (posCouldWalk(allChess, tmp, allChess[index]->getFirstMove()))
				{
					validPos.push_back(tmp);
				}
			}
		}
		return validPos;
	}
	void Castling_Right(class Rook a)
	{
		if (this->getFirstMove() == 0 && a.getFirstMove() == 0) //�p�G��ӳ��S���ʹL
		{

		}
	}
};