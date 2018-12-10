#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int text_m;
//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBlock : public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	int  GetX() { return hero_x; }
	int  GetY() { return hero_y; }
	int  CheckBlockNumber(int vec, int x, int y);

	bool ThereIsBlock(int vec);
	void HeroAction(int vec);
	void Mapchange(int mapn);
	void SetHero();

	void UnlockDoor(int vec, int num);
	void Set_Map_Num(int n) { mapnum = n; }//�}�b�v�i���o�[���Z�b�g����
private:
	int m_map[5][15][20];//�}�b�v���
	int hero_x; //��l���ʒu�iX�j
	int hero_y; //��l���ʒu�iY�j

	bool eventclockflag; //�C�x���g���̃t���O
	int  eventclocktime; //�C�x���g���̎��ԊǗ�
	int  blockmovevec;   //�u���b�N�̓�������
	int   blockx;
	int   blocky;
	bool  blockdeleteYN;
	float blockm_x;
	float blockm_y;
	int mapnum; //�}�b�v�i���o�[
	int animationtime;   //�A�j���[�V�����̂��߂̎��ԊǗ�
};