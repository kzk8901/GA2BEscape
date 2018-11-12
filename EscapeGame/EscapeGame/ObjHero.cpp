//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\Scenemanager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 32.0f; //�ʒu�x�N�g��
	m_py = 0.0f;
	m_vx = 0.0f; //�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f; //�E����0.0f ������1.0f
	m_speed = 2.0f;

	m_ani_time = 0;
	m_ani_frame = 1;
	m_vec = 0;
	m_time = 0;
	m_savevec = 0;
	for (int i = 0; i < 5; i++)
		unlocknum[i] = 0;
	selectnum = 0;


	move_flag = false;
	action_flag = false;
	numlock_flag = false;
	Key_flag = false;
}

//�A�N�V����
void CObjHero::Action()
{
	//�u���b�N�̈ʒu�擾
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�L�[�̓��͕���
	if (action_flag == false)
	{
		if (move_flag == false)
		{
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				if (block->ThereIsBlock(1) == true)
				{
					m_vec = 1;
					m_savevec = 1;
					move_flag = true;
				}
				else
				{
					m_savevec = 1;
				}
			}
			else if (Input::GetVKey(VK_LEFT) == true)
			{
				if (block->ThereIsBlock(2) == true)
				{
					m_vec = 2;
					m_savevec = 2;
					move_flag = true;
				}
				else
				{
					m_savevec = 2;
				}
			}
			else if (Input::GetVKey(VK_UP))
			{
				if (block->ThereIsBlock(3) == true)
				{
					m_vec = 3;
					m_savevec = 3;
					move_flag = true;
				}
				else
				{
					m_savevec = 3;
				}
			}
			else if (Input::GetVKey(VK_DOWN) == true)
			{
				if (block->ThereIsBlock(4) == true)
				{
					m_vec = 4;
					m_savevec = 4;
					move_flag = true;
				}
				else
				{
					m_savevec = 4;
				}
			}
			else if ((Input::GetVKey('Z') == true))
			{
				if (Key_flag == false)
				{
					block->HeroAction(m_savevec);
					Key_flag = true;
				}
			}
			else
			{
				Key_flag = false;
			}
		}
		else
		{
			if (m_vec == 1)
			{
				//�E�ɓ����v���O����
				m_vx = +m_speed;
				m_posture = 1.0f;
				m_time++;            //�����Ă��鎞��
				if (m_time % 4 == 0) //4�t���[���Ɉ��A�j���[�V����������
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
				m_posture = 0.0f;
				m_time++;
				if (m_time % 4 == 0)
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
				//m_posture = -1.0f;
				m_time++;
				if (m_time % 4 == 0)
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
				//m_posture = -1.0f;
				m_time++;
				if (m_time % 4 == 0)
					m_ani_frame++;
				if (m_time == 16)
				{
					m_time = 0;
					m_vec = 0;
					move_flag = false;
				}
			}
		}
	}
	else
	{
		if (numlock_flag == true)
		{
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				if (Key_flag == false)
				{
					selectnum++;
					if (selectnum == wpiece)
					{
						selectnum = 0;
					}
					Key_flag = true;
				}
			}
			else if (Input::GetVKey(VK_LEFT) == true)
			{
				if (Key_flag == false)
				{
					selectnum--;
					if (selectnum == -1)
					{
						selectnum = wpiece - 1;
					}
					Key_flag = true;
				}
			}
			else if (Input::GetVKey(VK_UP) == true)
			{
				if (Key_flag == false)
				{
					unlocknum[selectnum]++;
					if (unlocknum[selectnum] >= 10)
					{
						unlocknum[selectnum] = 0;
					}
					Key_flag = true;
				}
			}
			else if (Input::GetVKey(VK_DOWN) == true)
			{
				if (Key_flag == false)
				{
					unlocknum[selectnum]--;
					if (unlocknum[selectnum] <= -1)
					{
						unlocknum[selectnum] = 9;
					}
					Key_flag = true;
				}
			}
			else if (Input::GetVKey('Z') == true)
			{
				if (Key_flag == false)
				{
					int u = 0;
					int j = 1;
					for (int i = wpiece - 1; i >= 0; i--)
					{
						u += unlocknum[i] * j;
						j *= 10;
					}
					block->UnlockDoor(1, u);
					for (int i = 0; i < wpiece; i++)
						unlocknum[i] = 0;
					selectnum = 0;
					wpiece = 0;
					numlock_flag = false;
					action_flag = false;
					Key_flag = true;
				}
			}
			else
			{
				Key_flag = false;
			}
		}
	}

	//�}�b�v�؂�ւ��p
	if (move_flag == false)
	{
		block->Mapchange();
	}
	/*
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx = +m_speed;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
    else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx = -m_speed;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_UP) == true)
	{
		m_vy = -m_speed;
		m_ani_time += 1;
	}
    else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy = +m_speed;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;
		m_ani_time = 0;
	}

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	*/

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f +m_py;
	dst.m_left = m_px + (32.0f * m_posture);
	dst.m_right = m_px + 32.0f + (- 32.0f * m_posture);
	dst.m_bottom = 32.0f + m_py;
	
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�i���o�[���b�N�\��
	if (numlock_flag)
	{
		for (int i = 0; i < wpiece; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%d", unlocknum[i]);
			if (selectnum == i)
			{
				c[2] = 0.5f;
			}
			else
			{
				c[2] = 1.0f;
			}

			Font::StrDraw(str, 30 + i * 30, 500, 30, c);
		}
	}
}
//�i���o�[���b�N����
bool CObjHero::locknumber()
{
	action_flag = true;

	while (1)
	{
		if (Input::GetVKey(VK_UP) == true)
		{

		}
		else if (Input::GetVKey(VK_DOWN) == true)
		{

		}

		if (Input::GetVKey('Z') == true)
		{
			break;
		}
	}

	return false;
}