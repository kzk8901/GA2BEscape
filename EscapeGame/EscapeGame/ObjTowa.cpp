//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\Scenemanager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"

#include "ObjTowa.h"
#include "GameHead.h"
#include "ObjBlock.h"
#include "ObjItem.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTowa::Init()
{
	m_px = 0.0f; //�ʒu�x�N�g��
	m_py = 0.0f;
	m_vx = 0.0f; //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0f ������1.0f
	m_speed = 2.0f;

	m_ani_time = 0;
	m_ani_frame = 0;
	m_vec = 0;
	m_time = 0;
	m_savevec = 0;
	for (int i = 0; i < 20; i++)
		unlocknum[i] = 0;
	selectnum = 0;
	eventnumber = 0;
	towa_vec = 4;

	eventflag = false;
	move_flag = false;
	action_flag = false;
	numlock_flag = false;
	Key_flag = false;
	Itemcheck = false;
	towa_in = false;

}

//�A�N�V����
void CObjTowa::Action()
{

	//�u���b�N�̈ʒu�擾
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//��l���Q��
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;
	if (text_m == -1 && word == 16)
	{
		eventflag = true;
		eventnumber = 1;
	}
	else if (text_m == -1 && word == 49)
	{
		eventflag = true;
		eventnumber = 2;
	}
	else if (text_m == -1 && word == 54)
	{
		eventflag = true;
		eventnumber = 3;
	}

	//�C�x���g�p�t���O
	if (eventflag == true)
	{
		//�I�[�v�j���O�J�n-----------------------------------------------------
		//�C�x���g�i���o�[�P
		if (eventnumber == 1 && move_flag == false)
		{
			if (anime_move == 2|| event_skip == true)
			{
				towa_in = true;
				//1,�E 2,�� 3,�� 4,��
				if (block->TowaGetY() > 8 && block->ThereIsBlock(3, 3) == true)
				{
					SetMoveVec(3);
				}
				else if (block->TowaGetX() < 13 && block->ThereIsBlock(1, 3) == true)
				{
					SetMoveVec(1);
				}
				else
				{
					towa_vec = 2;
					eventflag = false;
					eventnumber = 0;
					block->SetEventNum(3);
					skip_anime = false;
				}
			}
		}
		//�C�x���g1�I��

		//�C�x���g�i���o�[2
		if (eventnumber == 2 && move_flag == false)
		{
			if (anime_move == 7|| event_skip == true)
			{
				//1,�E 2,�� 3,�� 4,��
				if (block->TowaGetY() > 7 && block->ThereIsBlock(3, 3) == true)
				{
					SetMoveVec(3);
				}
				else if (block->TowaGetX() < 18 && block->ThereIsBlock(1, 3) == true)
				{
					SetMoveVec(1);
				}
				else
				{
					towa_vec = 2;
					eventflag = false;
					eventnumber = 0;
					block->SetEventNum(9);
					skip_anime = false;
				}
			}
		}
		//�C�x���g2�I��

		//�C�x���g�i���o�[3
		if (eventnumber == 3 && move_flag == false)
		{
			if (anime_move == 8 || event_skip == true)
			{
				//1,�E 2,�� 3,�� 4,��
				if (block->TowaGetX() < 19 && block->ThereIsBlock(1, 3) == true)
				{
					SetMoveVec(1);
				}
				else
				{
					eventflag = false;
					eventnumber = 0;
					towa_in = false;
					towa_vec = 4;
					skip_anime = false;
				}
			}
		}
		//�C�x���g3�I��
		//�I�[�v�j���O�I��-----------------------------------------------------
	}

	if (m_vec == 1)
	{
		//�E�ɓ����v���O����
		m_vx = +m_speed;
		//m_posture = 0.0f;
		m_time++;            //�����Ă��鎞��
		if (m_time % 8 == 0) //4�t���[���Ɉ��A�j���[�V����������
			m_ani_frame++;
		if (m_time == 16)    //16�t���[��(32pixel)��������~�߂�
		{
			m_time = 0;
			m_vec = 0;
			move_flag = false;
		}
	}
	if (m_vec == 2)
	{
		//���ɓ����v���O����
		m_vx = -m_speed;
		//m_posture = 0.0f;
		m_time++;
		if (m_time % 8 == 0)
			m_ani_frame++;
		if (m_time == 16)
		{
			m_time = 0;
			m_vec = 0;
			move_flag = false;
		}
	}
	if (m_vec == 3)
	{
		//��ɓ����v���O����
		m_vy = -m_speed;
		m_time++;
		if (m_time % 8 == 0)
			m_ani_frame++;
		if (m_time == 16)
		{
			m_time = 0;
			m_vec = 0;
			move_flag = false;
		}
	}
	if (m_vec == 4)
	{
		//���ɓ����v���O����
		m_vy = +m_speed;
		m_time++;
		if (m_time % 8 == 0)
			m_ani_frame++;
		if (m_time == 16)
		{
			m_time = 0;
			m_vec = 0;
			move_flag = false;
		}
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

}

//�h���[
void CObjTowa::Draw()
{
	int AniData[4] =
	{
		0,1,0,-1,
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


	if (towa_vec == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 96.0f;
	}

	else if (towa_vec == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 64.0f;
	}

	else if (towa_vec == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 96.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 128.0f;
	}

	else if (towa_vec == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 32.0f;
	}

	if (towa_in == true)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = m_py;
		dst.m_left = m_px;
		dst.m_right = m_px + 32.0f;
		dst.m_bottom = m_py + 32.0f;
	}

	Draw::Draw(62, &src, &dst, c, 0.0f);

}