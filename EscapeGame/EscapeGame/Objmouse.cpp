//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\Scenemanager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include "GameHead.h"

#include "Objmouse.h"

//�C�j�V�����C�Y
void CObjMouse::Init()
{
	m_px = 192.0f; //�ʒu�x�N�g��
	m_py = 224.0f;
	m_vx = 0.0f; //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0f ������1.0f
	m_speed = 4.0f;

	movevec = 0;
	savevec = 4;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_time = 0;

	nowmap = 0; 
	nezumap = 3;

	move_flag = false;
}

//�A�N�V����
void CObjMouse::Action()
{
	if (move_flag == true && nowmap == nezumap)
	{
		if (movevec == 1)
		{
			//�E�ɓ����v���O����
			m_px += m_speed;
			//m_posture = 0.0f;
			m_time++;            //�����Ă��鎞��
			if (m_time % 8 == 0) //4�t���[���Ɉ��A�j���[�V����������
				m_ani_frame++;
			if (m_time == 8)    //16�t���[��(32pixel)��������~�߂�
			{
				m_time = 0;
				movevec = 0;
				move_flag = false;
			}
		}
		else if (movevec == 2)
		{
			//���ɓ����v���O����
			m_px -= m_speed;
			//m_posture = 0.0f;
			m_time++;
			if (m_time % 8 == 0)
				m_ani_frame++;
			if (m_time == 8)
			{
				m_time = 0;
				movevec = 0;
				move_flag = false;
			}
		}
		else if (movevec == 3)
		{
			//��ɓ����v���O����
			m_py -= m_speed;
			//m_posture = -1.0f;
			m_time++;
			if (m_time % 8 == 0)
				m_ani_frame++;
			if (m_time == 8)
			{
				m_time = 0;
				movevec = 0;
				move_flag = false;
			}
		}
		else if (movevec == 4)
		{
			//���ɓ����v���O����
			m_py += m_speed;
			//m_posture = -1.0f;
			m_time++;
			if (m_time % 8 == 0)
				m_ani_frame++;
			if (m_time == 8)
			{
				m_time = 0;
				movevec = 0;
				move_flag = false;
			}
		}
		else
		{
			movevec = 0;
			move_flag = false;
		}
	}

	if (m_ani_frame >= 4)
	{
		m_ani_frame = 0;
	}

	m_px += m_vx;
	m_py += m_vy;
}

//�h���[
void CObjMouse::Draw()
{
	int AniData[4] =
	{
		0,1,2,3,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	if (savevec == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;
		src.m_left =  AniData[m_ani_frame] * 32;
		src.m_right = AniData[m_ani_frame] * 32 + 32.0f;
		src.m_bottom = 96.0f;
	}

	else if (savevec == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;
		src.m_left =  AniData[m_ani_frame] * 32;
		src.m_right =  AniData[m_ani_frame] * 32 + 32.0f;
		src.m_bottom = 64.0f;
	}

	else if (savevec == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 96.0f;
		src.m_left =  AniData[m_ani_frame] * 32;
		src.m_right =  AniData[m_ani_frame] * 32 + 32.0f;
		src.m_bottom = 128.0f;
	}

	else if (savevec == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left =  AniData[m_ani_frame] * 32;
		src.m_right =  AniData[m_ani_frame] * 32 + 32.0f;
		src.m_bottom = 32.0f;
	}

	if (nezumap == nowmap)
	{
		//�\���ʒu�̐ݒ�
		dst.m_top = m_py;
		dst.m_left = m_px;
		dst.m_right = m_px + 32.0f;
		dst.m_bottom = m_py + 32.0f;
	}

	Draw::Draw(39, &src, &dst, c, 0.0f);
}

void CObjMouse::SetMovevec(int vec)
{
	movevec = vec; 
	ssavevec = savevec;
	savevec = vec;
	move_flag = true;
}