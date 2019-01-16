#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjKirara : public CObj
{
public:
	CObjKirara() {};
	~CObjKirara() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
	bool GetMoveFlag() { return move_flag; }

	void SetPX(float x) { m_px = x; }
	void SetPY(float y) { m_py = y; }
	void SetActionflag(bool a) { action_flag = a; }
	void SetNumlock(bool n) { numlock_flag = n; }
	void SetLockpiece(int p) { wpiece = p; }
	void SetKiraraEventFlag(bool e, int number) { eventflag = e; eventnumber = number; }
	void SetMoveVec(int v) { m_vec = v;  m_savevec = v;  kirara_vec = v;  move_flag = true; }
	void SetKiraraIn(bool in) { kirara_in = in; }
	void SetVec(int vec) { kirara_vec = vec; }

private:
	float m_px; //�ʒu
	float m_py;
	float m_vx; //�ړ��x�N�g��
	float m_vy;
	float m_posture; //�p��
	float m_speed; //�������x

	int m_ani_time;
	int m_ani_frame;
	int m_vec;      //�������������߂�ϐ�
	int m_time;     //�����Ă鎞�̎��ԊǗ�
	int m_savevec;  //��O�̈ړ�������ۑ�����ϐ�
	int wpiece;     //�������̕ϐ�
	int unlocknum[20];  //��ǒ��̃i���o�[
	int selectnum;  //�����牽�Ԗڂ̐��𓮂����̂�
	int word;   //�e�L�X�g�E�B���h�E����
	int eventnumber; //�ǂ̃C�x���g�𓮂�����
	int kirara_vec;   //�����Ă������

	bool eventflag; //�C�x���g�t���O
	bool move_flag; //�������߂̃t���O
	bool key_flag;//�������h�~
	bool action_flag; //�����Ă�������
	bool numlock_flag; //�i���o�[���b�N�������Ă��邩
	bool Key_flag;     //�L�[����t���O
	bool Itemcheck;    //�A�C�e���ڍ׊m�F���t���O
	bool kirara_in;    //������\�����邩�ǂ���
};