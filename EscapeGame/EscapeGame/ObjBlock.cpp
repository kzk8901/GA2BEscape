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

int text_m = 0;
//�}�b�v���--------------------------------------------
//1 = ��, 2 = ��l�������ʒu, 3 = ���t����(����̃J�M�����Ă���ΊJ��)
//4 = �������Ă܂�, 5 = �i���o�[���b�N�h�A

//�ۑ��}�b�v
int block_data_save[15][20] =
{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
};

//�X�^�[�g�}�b�v1F
int block_data_neutral_1F[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
};

//�t���}�b�v1F
int block_data_up_1F[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 2,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,98,1,1,1,1,1,1,1,1,1, 1, },
};

//�i���}�b�v1F
int block_data_right_1F[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{96,2,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
};

//�����}�b�v1F
int block_data_left_1F[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,2,94, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
};
//�}�b�v���-------------------------------------------------
//�C�j�V�����C�Y
void CObjBlock::Init()
{

	//��l���̈ʒu��ݒ�
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, block_data_neutral_1F, sizeof(int)*(15 * 20));

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[i][j] == 2)
			{
				hero_x = j; hero_y = i;
				hero->SetPX(32.0f * j);
				hero->SetPY(32.0f * i);
				m_map[i][j] = 0;
			}
		}
	}

	((UserData*)Save::GetData())->item1 = false;
	((UserData*)Save::GetData())->number1 = 1145141919810;
}

//�A�N�V����
void CObjBlock::Action()
{
	
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
	src.m_right = 230.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left =640.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 480.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//�e�L�X�g�E�B���h�E3�i�E���j
	src.m_top = 136.0f;
	src.m_left = 0.0f;
	src.m_right = 160.0f;
	src.m_bottom = 256.0f;
	dst.m_top = 480.0f;
	dst.m_left = 640.0f;
	dst.m_right = 800.0f;
	dst.m_bottom =600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);


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
			//�i���o�[���b�N�h�A
			if (m_map[i][j] == 5)
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
		if (m_map[hero_y][hero_x + 1] != 1 && m_map[hero_y][hero_x + 1] != 3 && m_map[hero_y][hero_x + 1] != 5)
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
		if (m_map[hero_y][hero_x - 1] != 1 && m_map[hero_y][hero_x - 1] != 3 && m_map[hero_y][hero_x - 1] != 5)
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
		if (m_map[hero_y - 1][hero_x] != 1 && m_map[hero_y - 1][hero_x] != 3 && m_map[hero_y - 1][hero_x] != 5)
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
		if (m_map[hero_y + 1][hero_x] != 1 && m_map[hero_y + 1][hero_x] != 3 && m_map[hero_y + 1][hero_x] != 5)
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
	//��l���̈ʒu��ݒ�
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

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
			m_map[hero_y - 1][hero_x] = 99;
		}
		if (m_map[hero_y - 1][hero_x] == 5)
		{
			hero->SetActionflag(true);
			hero->SetLockpiece(13);
			hero->SetNumlock(true);
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
//�}�b�v�؂�ւ��p�֐�
void CObjBlock::Mapchange()
{
	//��l���̈ʒu��ݒ�
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�}�b�v�؂�ւ�����
	if (m_map[hero_y][hero_x] == 99 || m_map[hero_y][hero_x] == 97 || m_map[hero_y][hero_x] == 95)
	{
		//�X�^�[�g�}�b�v�f�[�^���R�s�[
		if (m_map[hero_y][hero_x] == 99)
		{
			text_m = 2;
			m_map[hero_y + 1][hero_x] = 2;
			memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
			memcpy(m_map, block_data_up_1F, sizeof(int)*(15 * 20));
			memcpy(block_data_neutral_1F, block_data_save, sizeof(int)*(15 * 20));
		}
		//�X�^�[�g�}�b�v�f�[�^���R�s�[
		if (m_map[hero_y][hero_x] == 97)
		{
			text_m = 1;
			m_map[hero_y][hero_x - 1] = 2;
			memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
			memcpy(m_map, block_data_right_1F, sizeof(int)*(15 * 20));
			memcpy(block_data_neutral_1F, block_data_save, sizeof(int)*(15 * 20));
		}
		//�X�^�[�g�}�b�v�f�[�^���R�s�[
		if (m_map[hero_y][hero_x] == 95)
		{
			m_map[hero_y][hero_x + 1] = 2;
			memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
			memcpy(m_map, block_data_left_1F, sizeof(int)*(15 * 20));
			memcpy(block_data_neutral_1F, block_data_save, sizeof(int)*(15 * 20));
		}
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (m_map[i][j] == 2)
				{
					hero_x = j; hero_y = i;
					hero->SetPX(32.0f * j);
					hero->SetPY(32.0f * i);
					m_map[i][j] = 0;
				}
			}
		}
	}

	//�t���}�b�v1F�؂�ւ�����
	if (m_map[hero_y][hero_x] == 98)
	{
		text_m = 0;
		//�}�b�v�f�[�^���R�s�[
		m_map[hero_y - 1][hero_x] = 2;
		memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
		memcpy(m_map, block_data_neutral_1F, sizeof(int)*(15 * 20));
		memcpy(block_data_up_1F, block_data_save, sizeof(int)*(15 * 20));
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (m_map[i][j] == 2)
				{
					hero_x = j; hero_y = i;
					hero->SetPX(32.0f * j);
					hero->SetPY(32.0f * i);
					m_map[i][j] = 0;
				}
			}
		}
	}

	//�i���}�b�v1F�؂�ւ�����
	if (m_map[hero_y][hero_x] == 96)
	{
		text_m = 0;
		//�}�b�v�f�[�^���R�s�[
		m_map[hero_y][hero_x + 1] = 2;
		memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
		memcpy(m_map, block_data_neutral_1F, sizeof(int)*(15 * 20));
		memcpy(block_data_right_1F, block_data_save, sizeof(int)*(15 * 20));
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (m_map[i][j] == 2)
				{
					hero_x = j; hero_y = i;
					hero->SetPX(32.0f * j);
					hero->SetPY(32.0f * i);
					m_map[i][j] = 0;
				}
			}
		}
	}

	//�����}�b�v1F�؂�ւ�����
	if (m_map[hero_y][hero_x] == 94)
	{
		//�}�b�v�f�[�^���R�s�[
		m_map[hero_y][hero_x - 1] = 2;
		memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
		memcpy(m_map, block_data_neutral_1F, sizeof(int)*(15 * 20));
		memcpy(block_data_left_1F, block_data_save, sizeof(int)*(15 * 20));
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (m_map[i][j] == 2)
				{
					hero_x = j; hero_y = i;
					hero->SetPX(32.0f * j);
					hero->SetPY(32.0f * i);
					m_map[i][j] = 0;
				}
			}
		}
	}
}
void CObjBlock::UnlockDoor(int vec, int num)
{
	if (((UserData*)Save::GetData())->number1 == num)
	{
		m_map[hero_y - 1][hero_x] = 0;
		text_m = 4;
	}
}