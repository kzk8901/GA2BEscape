//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjItem.h"
#include "ObjBackGround.h"
#include "ObjBlock.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBackGround::Init()
{
	mapnum = 0;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			m_map[mapnum][i][j] = 0;
		}
	}
}

//�A�N�V����
void CObjBackGround::Action()
{

}

//�h���[
void CObjBackGround::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`��\���ʒu

	//�u���b�N�̈ʒu�擾
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�e�L�X�g�E�B���h�E1�i������)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 162.0f;
	dst.m_top = 480.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int i = -1; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//�w�i�p�u���b�N�z�u
			// �؂���ʒu�̐ݒ�
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = src.m_left + 64.0f;
			src.m_bottom = src.m_top + 64.0f;
			//�\���ʒu�̐ݒ�
			dst.m_top = i*32.0f;
			dst.m_left = j*32.0f;
			dst.m_right = dst.m_left + 32.0f;
			dst.m_bottom = dst.m_top + 32.0f;

			//�`��
			Draw::Draw(10, &src, &dst, c, 0.0f);

			//�ړ��}�b�v
			if (m_map[mapnum][i][j] == 83||
				m_map[mapnum][i][j] == 84||
				m_map[mapnum][i][j] == 85||
				m_map[mapnum][i][j] == 61)
			{
				if (m_map[mapnum][i][j] == 83)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 64.0f;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
				}
				else if (m_map[mapnum][i][j] == 84)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 64.0f;
					src.m_left = 64.0f;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
				}
				else if (m_map[mapnum][i][j] == 85)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 64.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
				}
				else if (m_map[mapnum][i][j] == 61)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
				}

				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(63, &src, &dst, c, 0.0f);
			}
		}
	}

	//�F�t����
	if (mapnum == 1)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = src.m_left + 64.0f;
		src.m_bottom = src.m_top + 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 48.0f;
		dst.m_left = 256.0f;
		dst.m_right = dst.m_left + 32.0f;
		dst.m_bottom = dst.m_top + 32.0f;

		//�`��
		Draw::Draw(19, &src, &dst, c, 0.0f);
	}

	for(int i = 0; i < 15; i++)
	{ 
		for (int j = 0; j < 20; j++)
		{
			//�M�~�b�N����l���֘A-------------------
			//�Ǖ\��
			if (m_map[mapnum][i][j] == 1|| m_map[mapnum][i][j] == 82)
			{
				if (i != 14)
				{
					if (block->CheckBlockNumber(6, j, i) != 1)
					{
						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;
						//�\���ʒu�̐ݒ�
						dst.m_top = i*32.0f + 16.0f;
						dst.m_left = j*32.0f;
						dst.m_right = dst.m_left + 32.0f;
						dst.m_bottom = dst.m_top + 32.0f;

						//�`��
						Draw::Draw(11, &src, &dst, c, 0.0f);

						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;
						//�\���ʒu�̐ݒ�
						dst.m_top = i*32.0f;
						dst.m_left = j*32.0f;
						dst.m_right = dst.m_left + 32.0f;
						dst.m_bottom = dst.m_top + 16.0f;

						//�`��
						Draw::Draw(12, &src, &dst, c, 0.0f);
					}
					else
					{
						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;
						//�\���ʒu�̐ݒ�
						dst.m_top = i*32.0f;
						dst.m_left = j*32.0f;
						dst.m_right = dst.m_left + 32.0f;
						dst.m_bottom = dst.m_top + 32.0f;

						//�`��
						Draw::Draw(12, &src, &dst, c, 0.0f);
					}
				}
				else
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
					//�\���ʒu�̐ݒ�
					dst.m_top = i*32.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//�`��
					Draw::Draw(12, &src, &dst, c, 0.0f);
				}
			}
		    //�ǁi���t���j
			if (m_map[mapnum][i][j] == 54)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f + 16.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(46, &src, &dst, c, 0.0f);

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 16.0f;

				//�`��
				Draw::Draw(12, &src, &dst, c, 0.0f);
			}
			//�{�I�\��
			if (m_map[mapnum][i][j] == 35 || m_map[mapnum][i][j] == 36 || m_map[mapnum][i][j] == 37 || m_map[mapnum][i][j] == 38
				|| m_map[mapnum][i][j] == 70 || m_map[mapnum][i][j] == 71 || m_map[mapnum][i][j] == 72 || m_map[mapnum][i][j] == 73
				|| m_map[mapnum][i][j] == 74 || m_map[mapnum][i][j] == 75)
			{
				if (m_map[mapnum][i + 1][j] == 35 || m_map[mapnum][i + 1][j] == 36 || m_map[mapnum][i + 1][j] == 37 || m_map[mapnum][i + 1][j] == 38
					|| m_map[mapnum][i + 1][j] == 70 || m_map[mapnum][i + 1][j] == 71 || m_map[mapnum][i + 1][j] == 72 || m_map[mapnum][i + 1][j] == 73
					|| m_map[mapnum][i + 1][j] == 74 || m_map[mapnum][i + 1][j] == 75)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 32.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 32.0f;

					//�\���ʒu�̐ݒ�
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//�`��
					Draw::Draw(21, &src, &dst, c, 0.0f);
				}
				else if (m_map[mapnum][i - 1][j] == 35 || m_map[mapnum][i - 1][j] == 36 || m_map[mapnum][i - 1][j] == 37 || m_map[mapnum][i - 1][j] == 38
					|| m_map[mapnum][i - 1][j] == 70 || m_map[mapnum][i - 1][j] == 71 || m_map[mapnum][i - 1][j] == 72 || m_map[mapnum][i - 1][j] == 73
					|| m_map[mapnum][i - 1][j] == 74 || m_map[mapnum][i - 1][j] == 75)
				{
					//�؂���ʒu�̐ݒ�
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 64.0f;

					//�\���ʒu�̐ݒ�
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 48.0f;

					//�`��
					Draw::Draw(21, &src, &dst, c, 0.0f);
				}
				else
				{
					int skipcountx = 0;
					int overcount = 0;

					for (int s = 1; m_map[mapnum][i][j + s] == 35 || m_map[mapnum][i][j + s] == 36 || m_map[mapnum][i][j + s] == 37 || m_map[mapnum][i][j + s] == 38
						|| m_map[mapnum][i][j + s] == 70 || m_map[mapnum][i][j + s] == 71 || m_map[mapnum][i][j + s] == 72 || m_map[mapnum][i][j + s] == 73
						|| m_map[mapnum][i][j + s] == 74 || m_map[mapnum][i][j + s] == 75; s++)
					{
						skipcountx++;
						if (skipcountx == 5)
						{
							skipcountx = 1;
							overcount += 1;
						}
					}

					for (int x = 0; x <= skipcountx;)
					{
						if (overcount > 0)
						{
							//�؂���ʒu�̐ݒ�
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 64.0f;
							src.m_bottom = src.m_top + 64.0f;

							//�\���ʒu�̐ݒ�
							dst.m_top = i*32.0f - 16.0f;
							dst.m_left = j*32.0f;
							dst.m_right = dst.m_left + 128.0f;
							dst.m_bottom = dst.m_top + 64.0f;

							x += 4;
							overcount -= 1;
						}
						else
						{
							//�؂���ʒu�̐ݒ�
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 16.0f * (skipcountx + 1);
							src.m_bottom = src.m_top + 64.0f;

							//�\���ʒu�̐ݒ�
							dst.m_top = i*32.0f - 16.0f;
							dst.m_left = j*32.0f;
							dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
							dst.m_bottom = dst.m_top + 64.0f;

							x += skipcountx;
							if (skipcountx == 0)
								x++;
						}
					}

					//�`��
					Draw::Draw(16, &src, &dst, c, 0.0f);

					j += skipcountx;
				}
			}
			//�����{�I�\��
			if (m_map[mapnum][i][j] == 39)
			{
				int skipcountx = 0;
				int overcount = 0;
				for (int s = 1; m_map[mapnum][i][j + s] == 39; s++)
				{
					skipcountx++;
					if (skipcountx == 5)
					{
						skipcountx = 1;
						overcount += 1;
					}
				}
				for (int x = 0; x <= skipcountx;)
				{
					if (overcount > 0)
					{
						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;

						//�\���ʒu�̐ݒ�
						dst.m_top = i*32.0f - 16.0f;
						dst.m_left = j*32.0f + block->GetMoveshelf();
						dst.m_right = dst.m_left + 128.0f;
						dst.m_bottom = dst.m_top + 32.0f * 2;

						x += 4;
						overcount -= 1;
					}
					else
					{
						//�؂���ʒu�̐ݒ�
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 16.0f * (skipcountx + 1);
						src.m_bottom = src.m_top + 64.0f;

						//�\���ʒu�̐ݒ�
						dst.m_top = i *32.0f - 16.0f;
						dst.m_left = j*32.0f + block->GetMoveshelf();
						dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
						dst.m_bottom = dst.m_top + 32.0f * 2;

						x += skipcountx;
					}
				}

				//�`��
				Draw::Draw(16, &src, &dst, c, 0.0f);

				j += skipcountx;
			}
			//�O�~
			if (m_map[mapnum][i][j] == 45)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 384.0f;
				src.m_bottom = src.m_top + 288.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 384.0f;
				dst.m_bottom = dst.m_top + 288.0f;

				//�`��
				Draw::Draw(9, &src, &dst, c, 0.0f);
			}
			//���������O�~
			if (m_map[mapnum][i][j] == 46)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 96.0f;
				src.m_right = src.m_left + 32.0f;
				src.m_bottom = src.m_top + 32.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			//�֎q
			if (m_map[mapnum][i][j] == 48)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 16.0f;
				src.m_bottom = src.m_top + 16.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0 + 16.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(34, &src, &dst, c, 0.0f);
			}
			//�K�i�i���j
			if (m_map[mapnum][i][j] == 93)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 128.0f;
				src.m_bottom = src.m_top + 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f + 16.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(35, &src, &dst, c, 0.0f);

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 16.0f;

				//�`��
				Draw::Draw(12, &src, &dst, c, 0.0f);
			}
			//�K�i
			if (m_map[mapnum][i][j] == 92)
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 128.0f;
				src.m_bottom = src.m_top + 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f + 16.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(43, &src, &dst, c, 0.0f);

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 16.0f;

				//�`��
				Draw::Draw(12, &src, &dst, c, 0.0f);
			}
			//��
			if (m_map[mapnum][i][j] == 99 && (block->HeroGetX() != j || block->HeroGetY() != i))
			{
				//�؂���ʒu�̐ݒ�
				src.m_top = 5.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 30.0f;
				src.m_bottom = src.m_top + 58.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 48.0f;

				//�`��
				Draw::Draw(36, &src, &dst, c, 0.0f);
			}

			//�g�F
			if (m_map[mapnum][i][j] == 53 && m_map[mapnum][i][j + 1] == 53)
			{

				//�؂���ʒu�̐ݒ�
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 106.0f;
				src.m_bottom = src.m_top + 96.0f;
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f - 16.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 48.0f;

				//�`��
				Draw::Draw(45, &src, &dst, c, 0.0f);
			}

		}
	}
}