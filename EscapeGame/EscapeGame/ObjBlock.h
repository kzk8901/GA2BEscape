#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int text_m;//�e�L�X�g�̎�ފǗ�
extern bool text_loop;//�e�L�X�g���[�v�΍�
extern bool room_c[3];
extern bool event_skip;//�C�x���g��΂��p
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
	int  MouseGetX() { return mouse_x; }
	int  MouseGetY() { return mouse_y; }

	bool ThereIsBlock(int vec ,int Characternum);//�����Ɠ������L����
	void HeroAction(int vec);
	void Mapchange(int mapn);
	void SetHero();
	void SetKirara();
	void SetTowa();
	void SetKanata();

	void SetEventNum(int e) { event_num = e; }//�N���������ŏ��̃C�x���g������

	void UnlockDoor(int vec, int num, int locknum);
	void Set_Map_Num(int n) { mapnum = n; }//�}�b�v�i���o�[���Z�b�g����
	float GetMoveshelf() { return moveshelf; }
private:
	int m_map[5][15][20];//�}�b�v���
	int notonblock[99];  //�����蔻�肠��u���b�N�̃i���o�[�͂����ɓ����
	int hero_x;   //��l���ʒu�iX�j
	int hero_y;   //��l���ʒu�iY�j
	int kirara_x; //�����ʒu�iX�j
	int kirara_y; //�����ʒu�iY�j
	int towa_x;   //�i���ʒu�iX�j
	int towa_y;   //�i���ʒu�iY�j
	int kanata_x; //�t���ʒu�iX�j
	int kanata_y; //�t���ʒu�iY�j
	int mouse_x;  //�l�ʒu(X)
	int mouse_y;  //�l�ʒu(Y)

	bool eventclockflag; //�C�x���g���̃t���O
	int  eventclocktime; //�C�x���g���̎��ԊǗ�
	int  blockmovevec;   //�u���b�N�̓�������
	int   blockx;
	int   blocky;
	bool  blockdeleteYN;
	float blockm_x;
	float blockm_y;
	float moveshelf;
	int mapnum; //�}�b�v�i���o�[
	int animationtime;   //�A�j���[�V�����̂��߂̎��ԊǗ�

	int event_num;//�C�x���g�i���o�[ 0�C�x���g�Ȃ�
	bool event_clock[8];//1�񂵂��N�����Ȃ��C�x���g�`�F�b�N
	int lockpasu;  //�i���o�[���b�N�̃q���g�\���p

	int tiherovec;//�l�p��l���ʒu�ۑ��p�ϐ�
	int acvec;    //�l�p���ړ������ۑ��p
	int mousemtime;//�l�p�s���񐔕ۑ��p

};