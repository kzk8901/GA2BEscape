//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjItem.h"

void CObjItem::Init()
{
	ShowItem = 0;
	show = false;

	//�����A�C�e�����Z�b�g
	for (int i = 0; i < 8; i++)
	{
		((UserData*)Save::GetData())->item[i] = 0;
	}
}

void CObjItem::Action()
{

}

void CObjItem::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`��\���ʒu

	//�A�C�e���\��
	for (int i = 0; i < 8; i++)
	{
		if (((UserData*)Save::GetData())->item[i] != 0)
		{
			src.m_top = 0.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 32.0f + 64.0f * i;
			dst.m_left = 650.0f;
			dst.m_right = dst.m_left + 64.0f;
			dst.m_bottom = dst.m_top + 64.0f;
			Draw::Draw(0, &src, &dst, c, 0.0f);
		}
	}

	if (show == true)
	{
		//�z���C�g�E�C���h�E�\��
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;
		dst.m_top = 64.0f;
		dst.m_left = 64.0f;
		dst.m_right = 576.0f;
		dst.m_bottom = 416.0f;
		Draw::Draw(5, &src, &dst, c, 0.0f);
		//�A�C�e�����剻�\��
		/*
		src.m_top = 0.0f;
		src.m_left = 384.0f;
		src.m_right = 448.0f;
		src.m_bottom = 64.0f;
		*/
		dst.m_top = 80.0f;
		dst.m_left = 96.0f;
		dst.m_right = dst.m_left + 320.0f;
		dst.m_bottom = dst.m_top + 320.0f;
		if (ShowItem == 1)
		{
			src.m_top = 0.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 64.0f;
			Draw::Draw(0, &src, &dst, c, 0.0f);
		}
		if (ShowItem == 2)
		{
			src.m_top = 64.0f;
			src.m_left = 320.0f;
			src.m_right = 384.0f;
			src.m_bottom = 128.0f;
			Draw::Draw(0, &src, &dst, c, 0.0f);
		}
	}
}

//���̃A�C�e�������Ă��邩�m�F�̂��߂̊֐�
bool CObjItem::CheckItem(int item)
{
	//���������m�F���A���̃A�C�e�������Ă�����true��Ԃ�
	for (int i = 0; i < 8; i++)
	{
		if (((UserData*)Save::GetData())->item[i] == item)
		{
			return true;
		}
	}

	//�����Ă��Ȃ�������false��Ԃ�
	return false;
}
//�A�C�e���폜�p�֐�
//all��true�Ȃ�΂��ׂĎQ�Ƃ��A���Ă͂܂���̂��ׂď���
void CObjItem::DeleteItem(int item, bool all)
{
	//���������m�F���A���̃A�C�e�������Ă���������ĊԂ𖄂߂�
	for (int i = 0; i < 8; i++)
	{
		if (((UserData*)Save::GetData())->item[i] == item)
		{
			((UserData*)Save::GetData())->item[i] = 0;
			for (int j = i + 1; j < 8; j++)
			{
				((UserData*)Save::GetData())->item[j - 1] = ((UserData*)Save::GetData())->item[j];
			}

			if (all == false)
				break;
		}
	}
}
//�A�C�e���Q�b�g�̂��߂̊֐�
void CObjItem::GetItem(int item)
{
	//�A�C�e������Ɏ��������̃t���O
	bool igf = false;

	//�P�`�W�܂ŃA�C�e���������Ă��邩��T��
	for (int i = 0; i < 8; i++)
	{
		if (((UserData*)Save::GetData())->item[i] == 0)
		{
			((UserData*)Save::GetData())->item[i] = item;
			igf = true;
			break;
		}
	}

	if (igf == false)
	{
		//�����A�C�e���������ς��̃��b�Z�[�W�E�C���h�E���o��
		;
	}
}