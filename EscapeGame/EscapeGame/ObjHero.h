#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHero : public CObj
{
   public:
	   CObjHero() {};
	   ~CObjHero() {};
	   void Init();    //�C�j�V�����C�Y
	   void Action();  //�A�N�V����
	   void Draw();    //�h���[

	   void SetPX(float x) { m_px = x; }
	   void SetPY(float y) { m_py = y; }
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

	  bool move_flag; //�������߂̃t���O
};