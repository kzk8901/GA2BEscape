//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�b�v���
int block_data_neutral[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,99, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
};

int block_data_new[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{98,2,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
};

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	//��l���̈ʒu��ݒ�
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�}�b�v���
	int block_data[15][20] =
	{
		{ 1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1, },
		{ 1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, },
	};

	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data_neutral, sizeof(int)*(15 * 20));

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[i][j] == 2)
			{
				hero_x = j; hero_y = i;
				hero->SetPX(32.0f * j);
				hero->SetPY(32.0f * i);
			}
		}
	}

	((UserData*)Save::GetData())->item1 = false;
}

//�A�N�V����
void CObjBlock::Action()
{
	if (Input::GetVKey('C') == true)
	{
		//�}�b�v�f�[�^���R�s�[
		memcpy(m_map, block_data_new, sizeof(int)*(15 * 20));
	}
}

//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`��\���ʒu

	//�w�i�\��
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left =0.0f;
	dst.m_right =640.0f;
	dst.m_bottom = 512.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�e�L�X�g�E�B���h�E1�i������)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 234.0f;
	dst.m_top = 480.0f;
	dst.m_left =0.0f;
	dst.m_right =640.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//�e�L�X�g�E�B���h�E2�i�c�����j
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 234.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left =640.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 480.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);


	//�}�b�v�`�b�v�ɂ��block�ݒu
	//�؂���ʒu�̐ݒ�
	/*
	src.m_top = 0.0f;
	src.m_left = 320.5f;
	src.m_right =src.m_left+64.0f;
	src.m_bottom = 64.0f;
	*/

	for(int i=0;i<15;i++)
	{
		for(int j=0;j<20;j++)
		{
			//�u���b�N�\��
			if(m_map[i][j] == 1)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//�\���ʒu�̐ݒ�
	            dst.m_top = i*32.0f;
	            dst.m_left = j*32.0f;
	            dst.m_right = dst.m_left+32.0f;
	            dst.m_bottom = dst.m_top+32.0f;

	            //�`��
	            Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//���t�����\��
			if (m_map[i][j] == 3)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}
			//���\��
			if (m_map[i][j] == 4)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
			if (m_map[i][j] == 99)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*0.0f;
				dst.m_left = j*0.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
	
	//�A�C�e���\��
	if (((UserData*)Save::GetData())->item1 == true)
	{
		src.m_top = 0.0f;
		src.m_left = 384.0f;
		src.m_right = 448.0f;
		src.m_bottom = 64.0f;
		dst.m_top = 32.0f;
		dst.m_left = 650.0f;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
}
//���������Ƀu���b�N�����邩�ǂ����̔���
bool CObjBlock::ThereIsBlock(int vec)
{
	//�E�������̓���
	if (vec == 1)
	{
		if (m_map[hero_y][hero_x + 1] != 1 && m_map[hero_y][hero_x + 1] != 3)
		{
			hero_x = hero_x + 1;
			return true;
		}
		else
		{
			return false;
		}
	}
	//���������̓���
	if (vec == 2)
	{
		if (m_map[hero_y][hero_x - 1] != 1 && m_map[hero_y][hero_x - 1] != 3)
		{
			hero_x = hero_x - 1;
			return true;
		}
		else
		{
			return false;
		}
	}
	//�㓮�����̓���
	if (vec == 3)
	{
		if (m_map[hero_y - 1][hero_x] != 1 && m_map[hero_y - 1][hero_x] != 3)
		{
			hero_y = hero_y - 1;
			return true;
		}
		else
		{
			return false;
		}
	}
	//�������Ƃ��̓���
	if (vec == 4)
	{
		if (m_map[hero_y + 1][hero_x] != 1 && m_map[hero_y + 1][hero_x] != 3)
		{
			hero_y = hero_y + 1;
			return true;
		}
		else
		{
			return false;
		}
	}
}
//��l���A�N�V����
void CObjBlock::HeroAction(int vec)
{
	//������
	if (m_map[hero_y][hero_x] == 4)
	{
		m_map[hero_y][hero_x] = 0;
		((UserData*)Save::GetData())->item1 = true;
	}

	//�E
	if (vec == 1)
	{
		if (m_map[hero_y][hero_x + 1] == 3)
		{
			;
		}
	}
	//��
	if (vec == 2)
	{
		if (m_map[hero_y][hero_x - 1] == 3)
		{
			;
		}
	}
	//��
	if (vec == 3)
	{
		if (m_map[hero_y - 1][hero_x] == 3 && ((UserData*)Save::GetData())->item1 == true)
		{
			((UserData*)Save::GetData())->item1 = false;
			m_map[hero_y - 1][hero_x] = 0;
		}
	}
	if (vec == 4)
	{
		if (m_map[hero_y - 1][hero_x] == 3 && ((UserData*)Save::GetData())->item1 == true)
		{
			m_map[hero_y - 1][hero_x] = 0;
		}
	}
}