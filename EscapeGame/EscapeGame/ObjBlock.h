#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int text_m;//�e�L�X�g�̎�ފǗ�
extern bool text_loop;//�e�L�X�g���[�v�΍�
extern bool room_c[3];
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
	int  HeroGetX() { return hero_x; }
	int  HeroGetY() { return hero_y; }
	int  KiraraGetX() { return kirara_x; }
	int  KiraraGetY() { return kirara_y; }
	int  TowaGetX() { return towa_x; }
	int  TowaGetY() { return towa_y; }
	int  KanataGetX() { return kanata_x; }
	int  KanataGetY() { return kanata_y; }

	bool ThereIsBlock(int vec ,int Characternum);//�����Ɠ������L����
	void HeroAction(int vec);
	void Mapchange(int mapn);
	void SetHero();
	void SetKirara();
	void SetTowa();
	void SetKanata();

	void UnlockDoor(int vec, int num);
	void Set_Map_Num(int n) { mapnum = n; }//�}�b�v�i���o�[���Z�b�g����
private:
	int m_map[5][15][20];//�}�b�v���
	int hero_x;   //��l���ʒu�iX�j
	int hero_y;   //��l���ʒu�iY�j
	int kirara_x; //�����ʒu�iX�j
	int kirara_y; //�����ʒu�iY�j
	int towa_x;   //�i���ʒu�iX�j
	int towa_y;   //�i���ʒu�iY�j
	int kanata_x; //�t���ʒu�iX�j
	int kanata_y; //�t���ʒu�iY�j

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