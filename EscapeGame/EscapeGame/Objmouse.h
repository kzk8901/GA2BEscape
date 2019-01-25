#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjMouse : public CObj
{
public:
	CObjMouse() {};
	~CObjMouse() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[

	void SetPos(float px, float py, int mapnum) { m_px = px; m_py = py; nezumap = mapnum; }
	void SetnowMap(int mapnum) { nowmap = mapnum; }
	void SetMovevec(int vec);

	int GetSavevec() { return savevec; }

	bool GetMoveflag() { return move_flag; }
private:
	float m_px; //�ʒu
	float m_py;
	float m_vx; //�ړ��x�N�g��
	float m_vy;
	float m_posture; //�p��
	float m_speed; //�������x

	int movevec; //��������
	int savevec; //�ЂƂO�̍s���Z�[�u�p
	int m_ani_time;
	int m_ani_frame;
	int nowmap;  //���݃}�b�v
	int nezumap; //�l������}�b�v�Z�[�u�p
	int m_time;  

	bool move_flag;
};