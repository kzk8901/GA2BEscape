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
#include "ObjItem.h"

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
	m_ani_frame = 0;
	m_vec = 0;
	m_time = 0;
	m_savevec = 0;
	for (int i = 0; i < 20; i++)
		unlocknum[i] = 0;
	selectnum = 0;
	eventnumber = 0;
	hero_vec = 4;

	eventflag = false;
	move_flag = false;
	action_flag = false;
	numlock_flag = false;
	Key_flag = false;
	Itemcheck = false;
}

//�A�N�V����
void CObjHero::Action()
{
	//�u���b�N�̈ʒu�擾
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//�A�C�e���Q��
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�C�x���g�p�t���O
	if (eventflag == true)
	{
		//�C�x���g�i���o�[�P�@���̕��������Ă���X�^�[�g
		//X = 5, Y = 13�̈ʒu�܂ňړ�(�e�X�g�p)
		if (eventnumber == 1 && move_flag == false)
		{
			//1,�E 2,�� 3,�� 4,��
			if (block->GetX() > 5 && block->ThereIsBlock(2) == true)
			{
				SetMoveVec(2);
			}
			else if (block->GetY() < 13 && block->ThereIsBlock(4) == true)
			{
				SetMoveVec(4);
			}
			else
			{
				eventflag = false;
				eventnumber = 0;
			}
		}
		//�C�x���g1�I��

		//�C�x���g�i���o�[�Q�@�E�̕��������Ă���X�^�[�g
		//X = 8, Y = 2�̈ʒu�܂ňړ�
		if (eventnumber == 2 && move_flag == false)
		{
			if (block->GetY() > 2 && block->ThereIsBlock(3) == true)
			{
				SetMoveVec(3);
			}
			else if (block->GetX() < 8 && block->ThereIsBlock(1) == true)
			{
				SetMoveVec(1);
			}
			else
			{
				eventflag = false;
				eventnumber = 0;
			}
		}
		//�C�x���g2�I��
	}

	//�L�[�̓���
	//�����s���ł��Ȃ��󋵂Ȃ����Ȃ��i�i���o�[���b�N�����Ă�A�A�C�e���m�F���Ȃǁj
	if (action_flag == false)
	{
		//�����Ă���r������Ȃ���
		if (move_flag == false)
		{
			//�E�������Ƃ�
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				//�E�Ƀu���b�N�Ȃ���΂��̂܂ܓ���
				if (block->ThereIsBlock(1) == true)
				{
					SetMoveVec(1);
				}
				//�u���b�N������΂��̕�����������
				else
				{
					m_savevec = 1;
					hero_vec = 1;
				}
			}
			//���������Ƃ�
			else if (Input::GetVKey(VK_LEFT) == true)
			{
				//���Ƀu���b�N���Ȃ���΂��̂܂ܓ���
				if (block->ThereIsBlock(2) == true)
				{
					SetMoveVec(2);
				}
				//�u���b�N������΂��̕�����������
				else
				{
					m_savevec = 2;
					hero_vec = 2;
				}
			}
			//�㉟�����Ƃ�
			else if (Input::GetVKey(VK_UP))
			{
				//��Ƀu���b�N���Ȃ���΂��̂܂ܓ���
				if (block->ThereIsBlock(3) == true)
				{
					SetMoveVec(3);
				}
				//�u���b�N������΂��̕�����������
				else
				{
					m_savevec = 3;
					hero_vec = 3;
				}
			}
			//���������Ƃ�
			else if (Input::GetVKey(VK_DOWN) == true)
			{
				//���Ƀu���b�N���Ȃ���΂��̂܂ܓ���
				if (block->ThereIsBlock(4) == true)
				{
					SetMoveVec(4);
				}
				//�u���b�N������΂��̕�����������
				else
				{
					m_savevec = 4;
					hero_vec = 4;
				}
			}
			//�A�N�V�����{�^���������Ƃ�
			//�e����̓u���b�N�ɏ����Ă���
			else if ((Input::GetVKey('Z') == true))
			{
				if (Key_flag == false)
				{
					block->HeroAction(m_savevec);
					Key_flag = true;
				}
			}
			//�����������͂��ꂼ��̔ԍ��ɓo�^���Ă���A�C�e���̎Q�ƃv���O����
			//SetshowItemNumber(num)��num�̏��ɎQ�Ƃ������A�C�e���̔ԍ�������
			else if (Input::GetVKey('1')|| Input::GetVKey(VK_NUMPAD1))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[0] != 0)
					{
						SetShowItemNumber(1);
					}
				}
			}
			else if (Input::GetVKey('2') || Input::GetVKey(VK_NUMPAD2))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[1] != 0)
					{
						SetShowItemNumber(2);
					}
				}
			}
			else if (Input::GetVKey('3') || Input::GetVKey(VK_NUMPAD3))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[2] != 0)
					{
						SetShowItemNumber(3);
					}
				}
			}
			else if (Input::GetVKey('4') || Input::GetVKey(VK_NUMPAD4))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[3] != 0)
					{
						SetShowItemNumber(4);
					}
				}
			}
			else if (Input::GetVKey('5') || Input::GetVKey(VK_NUMPAD5))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[4] != 0)
					{
						SetShowItemNumber(5);
					}
				}
			}
			else if (Input::GetVKey('6') || Input::GetVKey(VK_NUMPAD6))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[5] != 0)
					{
						SetShowItemNumber(6);
					}
				}
			}
			else if (Input::GetVKey('7') || Input::GetVKey(VK_NUMPAD7))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[6] != 0)
					{
						SetShowItemNumber(7);
					}
				}
			}
			else if (Input::GetVKey('8') || Input::GetVKey(VK_NUMPAD8))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[7] != 0)
					{
						SetShowItemNumber(8);
					}
				}
			}
			else
			{
				//�L�[����
				Key_flag = false;
			}
		}
		else
		{
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
				//m_posture = -1.0f;
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
				//m_posture = -1.0f;
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
		}
	}
	else
	{
		//�i���o�[���b�N�����Ă���Ȃ����
		if (numlock_flag == true)
		{
			//�E�Ɉړ�
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				if (Key_flag == false)
				{
					//�E�ɂ����
					selectnum++;
					if (selectnum == wpiece)
					{
						//������E�ɍs�������ԍ��ɖ߂�
						selectnum = 0;
					}
					//�L�[����
					Key_flag = true;
				}
			}
			//���Ɉړ�
			else if (Input::GetVKey(VK_LEFT) == true)
			{
				if (Key_flag == false)
				{
					//���ɂ����
					selectnum--;
					if (selectnum == -1)
					{
						//��ԍ���荶�ɍs���ƈ�ԉE�ɖ߂�
						selectnum = wpiece - 1;
					}
					//�L�[����
					Key_flag = true;
				}
			}
			//������グ��
			else if (Input::GetVKey(VK_UP) == true)
			{
				if (Key_flag == false)
				{
					//
					unlocknum[selectnum]++;
					if (unlocknum[selectnum] >= 10)
					{
						unlocknum[selectnum] = 0;
					}
					Key_flag = true;
				}
			}
			//�����������
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
			//����
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
			//�L�[�t���O����
			else
			{
				Key_flag = false;
			}
		}
		if (Itemcheck == true)
		{
			if (Input::GetVKey('X') == true)
			{
				itm->SetShow(false);
				Itemcheck = false;
				action_flag = false;
			}
		}
	}

	////�}�b�v�؂�ւ��p
	//if (move_flag == false)
	//{
	//	block->Mapchange();
	//}
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
		0,1,0,-1,
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu


	if (hero_vec == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 64.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 96.0f;
	}

	else if (hero_vec == 2)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 32.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 64.0f;
	}

	else if (hero_vec == 3)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 96.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 128.0f;
	}

	else if (hero_vec == 4)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 32.0f;
	}

	//�\���ʒu�̐ݒ�
	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = m_px + 32.0f ;
	dst.m_bottom = m_py + 32.0f ;
	
	Draw::Draw(10, &src, &dst, c, 0.0f);

	//�i���o�[���b�N�\��
	if (numlock_flag)
	{
		for (int i = 0; i < wpiece; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%d", unlocknum[i]);
			if (selectnum == i)
			{
				//�I�����Ă��鐔�͐F�����F������
				c[2] = 0.5f;
			}
			else
			{
				//����ȊO�͔����ɂ���
				c[2] = 1.0f;
			}

			Font::StrDraw(str, 30 + i * 30, 500, 30, c);
		}
	}
}
//�A�C�e���\���p�֐�
void CObjHero::SetShowItemNumber(int i)
{
	//�A�C�e���Q��
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	//�n���ꂽ�i���o�[�̔ԍ��ɓ����Ă���A�C�e�����Q�Ɓ@�@�@�����̂��߂�-1
	itm->SetShowItem(((UserData*)Save::GetData())->item[i - 1]);
	Itemcheck = true;
	Key_flag = true;
	action_flag = true;
}