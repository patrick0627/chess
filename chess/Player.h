#pragma once
#include"Chess.h"
#include<ctime>
#include"Viewer.h"
class Player {
public:
	// p���ؼЦ�m
	bool onMove(vector<Piece*>& chesses, const vector<pos>& possible, pos p, Piece* chess) {

		for (int i = 0; i < possible.size(); i++) {
			if (p.x == possible[i].x && p.y == possible[i].y) {

				clock_t start, now;	//�p�ɥ�
				//���Z�ʵe
				if (chess->getType() == 2) {
					if (p.x == chess->getPos().x) {
						if (p.y < chess->getPos().y) {
							for (int i = chess->getPos().y - 1; i > p.y; i--) {
								chess->setPos(pos{ p.x,i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = chess->getPos().y + 1; i < p.y; i++) {
								chess->setPos(pos{ p.x,i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
					}
					else if (p.y == chess->getPos().y) {
						if (p.x < chess->getPos().x) {
							for (int i = chess->getPos().x - 1; i > p.x; i--) {
								chess->setPos(pos{ i,p.y });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = chess->getPos().x + 1; i < p.x; i++) {
								chess->setPos(pos{ i,p.y });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
					}
					else if (p.x < chess->getPos().x) {
						if (p.y < chess->getPos().y) {
							for (int i = 1; i < chess->getPos().y - p.y; i++) {
								chess->setPos(pos{ chess->getPos().x - i, chess->getPos().y - i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = 1; i < p.y - chess->getPos().y; i++) {
								chess->setPos(pos{ chess->getPos().x - i, chess->getPos().y + i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}

						}
					}
					else {
						if (p.y < chess->getPos().y) {
							for (int i = 1; i < chess->getPos().y - p.y; i++) {
								chess->setPos(pos{ chess->getPos().x + i, chess->getPos().y - i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = 1; i < p.y - chess->getPos().y; i++) {
								chess->setPos(pos{ chess->getPos().x + i, chess->getPos().y + i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
					}
					start = clock();
					now = clock();
					while (now - start < 1000) {
						now = clock();
					}
				}
				//�D�аʵe
				else if (chess->getType() == 3) {
					if (p.x < chess->getPos().x) {
						if (p.y < chess->getPos().y) {
							for (int i = 1;i < chess->getPos().y - p.y; i++) {
								chess->setPos(pos{ chess->getPos().x - i, chess->getPos().y - i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = 1; i < p.y - chess->getPos().y; i++) {
								chess->setPos(pos{ chess->getPos().x - i, chess->getPos().y + i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}

						}
					}
					else {
						if (p.y < chess->getPos().y) {
							for (int i = 1; i < chess->getPos().y - p.y; i++) {
								chess->setPos(pos{ chess->getPos().x + i, chess->getPos().y - i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = 1; i < p.y - chess->getPos().y; i++) {
								chess->setPos(pos{ chess->getPos().x + i, chess->getPos().y + i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
					}
					start = clock();
					now = clock();
					while (now - start < 1000) {
						now = clock();
					}
				}
				//�����ʵe
				else if (chess->getType() == 4) {
					if (p.x == chess->getPos().x) {
						if (p.y < chess->getPos().y) {
							for (int i = chess->getPos().y - 1; i > p.y; i--) {
								chess->setPos(pos{ p.x,i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = chess->getPos().y + 1; i < p.y; i++) {
								chess->setPos(pos{ p.x,i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
					}
					else if (p.y == chess->getPos().y) {
						if (p.x < chess->getPos().x) {
							for (int i = chess->getPos().x - 1; i > p.x; i--) {
								chess->setPos(pos{ i,p.y });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = chess->getPos().x + 1; i < p.x; i++) {
								chess->setPos(pos{ i,p.y });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
					}
					start = clock();
					now = clock();
					while (now - start < 1000) {
						now = clock();
					}
				}
				//�M�h�ʵe
				else if (chess->getType() == 5) {
					if (p.y == chess->getPos().y - 2) {
						chess->setPos(pos{ chess->getPos().x,p.y + 1 });
						start = clock();
						now = clock();
						while (now - start < 1000) {
							now = clock();
						}
						viewer.showBoard(chesses, -1);
					}
					else if (p.y == chess->getPos().y + 2) {
						chess->setPos(pos{ chess->getPos().x,p.y - 1 });
						start = clock();
						now = clock();
						while (now - start < 1000) {
							now = clock();
						}
						viewer.showBoard(chesses, -1);
					}
					else if (p.x == chess->getPos().x + 2) {
						chess->setPos(pos{ p.x - 1,chess->getPos().y });
						start = clock();
						now = clock();
						while (now - start < 1000) {
							now = clock();
						}
						viewer.showBoard(chesses, -1);
					}
					else if (p.x == chess->getPos().x - 2) {
						chess->setPos(pos{ p.x + 1,chess->getPos().y });
						start = clock();
						now = clock();
						while (now - start < 1000) {
							now = clock();
						}
						viewer.showBoard(chesses, -1);
					}
					start = clock();
					now = clock();
					while (now - start < 1000) {
						now = clock();
					}
				}
				//�p�L�ʵe
				else if (chess->getType() == 6) {
					if (p.x == chess->getPos().x) {
						if (p.y < chess->getPos().y) {
							for (int i = chess->getPos().y - 1; i > p.y; i--) {
								chess->setPos(pos{ p.x,i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						else {
							for (int i = chess->getPos().y + 1; i < p.y; i++) {
								chess->setPos(pos{ p.x,i });
								start = clock();
								now = clock();
								while (now - start < 1000) {
									now = clock();
								}
								viewer.showBoard(chesses, -1);
							}
						}
						start = clock();
						now = clock();
						while (now - start < 1000) {
							now = clock();
						}
					}
				}


				//�Y�n���ʨ쪺��m���Ѥl �h�Y��
				for (auto& it : chesses)
				{
					if (it->getPos().x == p.x && it->getPos().y == p.y)
					{
						chesses.erase(find(chesses.begin(), chesses.end(), it));
						break;
					}
				}
				chess->setPos(p);
				return true;
			}
		}

		return false; //�D�k����
	}
	void onPromote(vector<Piece*>& chess, int index, int option)
	{
		pos _pos = chess[index]->getPos();
		chess.erase(chess.begin() + index);
		Piece* tmp;
		switch (option)
		{
		case Type::bishop - 1:
			//�D�Ъ��غc��

			tmp = new Bishop(_pos, chess[index]->getFirstMove());
			chess.push_back(tmp);
			break;
		case Type::rook - 1:
			tmp = new Rook(_pos, chess[index]->getFirstMove());
			chess.push_back(tmp);
			break;
		case Type::queen - 1:
			tmp = new Queen(_pos, chess[index]->getFirstMove());
			chess.push_back(tmp);
			break;
		case Type::knight - 1:
			tmp = new Knight(_pos, chess[index]->getFirstMove());
			chess.push_back(tmp);
			break;
		}
	}
private:
	Viewer viewer;
};