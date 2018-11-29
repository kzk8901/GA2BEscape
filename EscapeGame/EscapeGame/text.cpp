//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"ObjBlock.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjText::Init()
{
	m_key_flag = false;
	skip_flag = false;
	time = 120;
	word[0] = 0;
	word[1] = 0;
	word[2] = 0;
	word[3] = 0;
	word[4] = 0;

	x = 0;
	y = 0;
}
//�A�N�V����
void CObjText::Action()
{
	time += 1;
	if (Input::GetVKey('Z') == true)
		{
			if (m_key_flag == true)
			{
				if (skip_flag == false)
				{
					if (time > 120)
					{
				        if (text_m == 0 && word[0] <= 20 || text_m == 3 && word[0] <= 27 || text_m == 4)
						{
							word[0] += 1;
							m_key_flag = false;
							time = 0;
							skip_flag = true;
						}
						else if (text_m == 1 && word[1] <= 12)
						{
							word[1] += 1;
							m_key_flag = false;
							time = 0;
							skip_flag = true;
						}
						else if (text_m == 2 && word[2] <= 8)
						{
							word[2] += 1;
							m_key_flag = false;
							time = 0;
							skip_flag = true;
						}
						else if (text_m == -1&&word[3]<=52)
						{
							word[3] += 1;
							m_key_flag = false;
							time = 0;
							skip_flag = true;

						}
					}
				}
				else if(time<100)
				{
					time = 100;
				}
				else if(time>120)
				{
					skip_flag = false;
				}


			}
		}
	else
	{
		m_key_flag = true;
	}
}
//�h���[
void CObjText::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`��\���ʒu
	//�I�[�v�j���O
	if (text_m == -1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
		if (word[3] == 0)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�˂��t���c�J����ނ��ȁH", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�˂��t���c�J����ނ��ȁH", 108, 490, 16, c);
			}
		}
		else if (word[3] == 1)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���̊������Ƃ�����ނƎv���܂���", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���̊������Ƃ�����ނƎv���܂���", 108, 490, 16, c);
			}
		}
		else if (word[3] == 2)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"???:�����Ȃ�J�h��ł��������ȁc", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"???:�����Ȃ�J�h��ł��������ȁc", 108, 490, 16, c);
			}
		}
		else if (word[3] == 3)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�N!?", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�N!?", 108, 490, 16, c);
			}
		}
		else if (word[3] == 4)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"???:��q�������̂�", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"???:��q�������̂�", 108, 490, 16, c);
			}
		}
		else if (word[3] == 5)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"???:���̖��O��syamu�B�I�t��0�l�w���̓�N��", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"???:���̖��O��syamu�B�I�t��0�l�w���̓�N��", 108, 490, 16, c);
			}
		}
		else if (word[3] == 6)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����A�����w�Z�̃Z���p�C", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����A�����w�Z�̃Z���p�C", 108, 490, 16, c);
			}
		}
		else if (word[3] == 7)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������̖��O�͑启������A�C�h������Ă܂��I", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������̖��O�͑启������A�C�h������Ă܂��I", 108, 490, 16, c);
			}
		}
		else if (word[3] == 8)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�^�����ʂ�J�ɍ~���}築J�h�肵�Ă��", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�^�����ʂ�J�ɍ~���}築J�h�肵�Ă��", 108, 490, 16, c);
			}
		}
		else if (word[3] == 9)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:������", 108, 490, 16, c);
			}
		}
		else if (word[3] == 10)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������͎��̃}�l�[�W���[�̑t����", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������͎��̃}�l�[�W���[�̑t����", 108, 490, 16, c);
			}
		}
		else if (word[3] == 11)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�ݖ�t���ł��B", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�ݖ�t���ł��B", 108, 490, 16, c);
			}
		}
		else if (word[3] == 12)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�����l�̃}�l�[�W���[�����C�h�ł�", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�����l�̃}�l�[�W���[�����C�h�ł�", 108, 490, 16, c);
			}
		}
		else if (word[3] == 13)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:��q��������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:��q��������", 108, 490, 16, c);
			}
		}
		else if (word[3] == 14)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�m�����Ȃ��́c", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�m�����Ȃ��́c", 108, 490, 16, c);
			}
		}
		else if (word[3] == 15)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���k��̖k��i������ł���", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���k��̖k��i������ł���", 108, 490, 16, c);
			}
		}
		else if (word[3] == 16)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:��������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:��������", 108, 490, 16, c);
			}
		}
		else if (word[3] == 17)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�N�͑勴����Ƃ̃��C�h���񂾂�", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�N�͑勴����Ƃ̃��C�h���񂾂�", 108, 490, 16, c);
			}
		}
		else if (word[3] == 18)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�ݖ�t���ł�", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�ݖ�t���ł�", 108, 490, 16, c);
			}
		}
		else if (word[3] == 19)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���A�J��ݎn�߂Ă܂���", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���A�J��ݎn�߂Ă܂���",  108, 490, 16, c);
			}
		}
		else if (word[3] == 20)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�t��!�Ƃ��ƂƋA����I", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�t��!�Ƃ��ƂƋA����I",  108, 490, 16, c);
			}
		}
		else if (word[3] == 21)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�������܂�܂����B����ł͎��炵�܂�", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�������܂�܂����B����ł͎��炵�܂�", 108, 490, 16, c);
			}
		}
		else if (word[3] == 22)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����A�낤", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����A�낤", 108, 490, 16, c);
			}
		}
		else if (word[3] == 23)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�l���A��Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�l���A��Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word[3] == 24)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��H", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��H", 108, 490, 16, c);
			}
		}
		else if (word[3] == 25)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�h�A���J���Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�h�A���J���Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word[3] == 26)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����Ȃ킯�Ȃ��ł���", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����Ȃ킯�Ȃ��ł���", 108, 490, 16, c);
			}
		}
		else if (word[3] == 27)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���炵�܂�", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���炵�܂�", 108, 490, 16, c);
			}
		}
		else if (word[3] == 28)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�J���܂����", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�J���܂����", 108, 490, 16, c);
			}
		}
		else if (word[3] == 29)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�{�������H", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�{�������H", 108, 490, 16, c);
			}
		}
		else if (word[3] == 30)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���āA�ǂ��������̂�", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���āA�ǂ��������̂�", 108, 490, 16, c);
			}
		}
		else if (word[3] == 31)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������̃h�A�͊J�����", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������̃h�A�͊J�����", 108, 490, 16, c);
			}
		}
		else if (word[3] == 32)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�Ȃ炻������T�����邩�H", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�Ȃ炻������T�����邩�H", 108, 490, 16, c);
			}
		}
		else if (word[3] == 33)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���܂肨���߂͂��܂����", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���܂肨���߂͂��܂����", 108, 490, 16, c);
			}
		}
		else if (word[3] == 34)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���Ԃ����ĂΉ䂪�Ƃ̋~���`�[�����삯�t���܂��̂ł��΂����҂���������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���Ԃ����ĂΉ䂪�Ƃ̋~���`�[�����삯�t���܂��̂ł��΂����҂���������", 108, 490, 16, c);
			}
		}
		else if (word[3] == 35)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���Ԃ����ĂΉ䂪�Ƃ̋~���`�[�����삯�t���܂��̂ł��΂����҂���������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���Ԃ����ĂΉ䂪�Ƃ̋~���`�[�����삯�t���܂��̂ł��΂����҂���������", 108, 490, 16, c);
			}
		}
		else if (word[3] == 36)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�ł��A����ȋ@��ő��ɂȂ����l�͒T���Ɏ^������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�ł��A����ȋ@��ő��ɂȂ����l�͒T���Ɏ^������", 108, 490, 16, c);
			}
		}
		else if (word[3] == 37)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�����T����������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�����T����������", 108, 490, 16, c);
			}
		}
		else if (word[3] == 38)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�t���A�~���`�[���̎�z�͑҂��Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�t���A�~���`�[���̎�z�͑҂��Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word[3] == 39)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�������c", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�������c", 108, 490, 16, c);
			}
		}
		else if (word[3] == 40)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�t���I", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�t���I", 108, 490, 16, c);
			}
		}
		else if (word[3] == 41)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�������܂�܂���", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�������܂�܂���", 108, 490, 16, c);
			}
		}
		else if (word[3] == 42)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�ł����玄���܂��S�����̈��S���m���߂܂�", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�ł����玄���܂��S�����̈��S���m���߂܂�", 108, 490, 16, c);
			}
		}
		else if (word[3] == 43)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���̌�F����ɒT�����Ă��炤�Ƃ������ƂŁc", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���̌�F����ɒT�����Ă��炤�Ƃ������ƂŁc", 108, 490, 16, c);
			}
		}
		else if (word[3] == 44)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����Ȃ��Ƃ������΋����Ȃ�����ˁH", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����Ȃ��Ƃ������΋����Ȃ�����ˁH", 108, 490, 16, c);
			}
		}
		else if (word[3] == 45)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�ł����琳�ʂ̕����̒T���Ȃ��낵���ł��傤�H", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�ł����琳�ʂ̕����̒T���Ȃ��낵���ł��傤�H", 108, 490, 16, c);
			}
		}
		else if (word[3] == 46)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����Ȃ炢����", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����Ȃ炢����", 108, 490, 16, c);
			}
		}
		else if (word[3] == 47)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���ꂶ�Ⴀ�l�͂������̕�����T�������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���ꂶ�Ⴀ�l�͂������̕�����T�������", 108, 490, 16, c);
			}
		}
		else if (word[3] == 48)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���肢���܂��ː�y", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���肢���܂��ː�y", 108, 490, 16, c);
			}
		}
		else if (word[3] == 49)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:��̊ق̒T���̊J�n���[�I", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:��̊ق̒T���̊J�n���[�I", 108, 490, 16, c);
			}
		}
		else if (word[3] == 50)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���[�I", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���[�I", 108, 490, 16, c);
			}
		}
		else if (word[3] == 51)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���A���[�c", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���A���[�c", 108, 490, 16, c);
			}
		}
		else if (word[3] == 52)
		{
			Font::StrDraw(L"�����������ŒT�����悤", 50, 490, 32, c);
		}
	}
	//�����}�b�v
	//�i�����@word[0]=0�`20
	//���擾�����@word[0]=22�`27
	//�����㎞�@word[0]=29�`42
	//�����}�b�v�i������b-----------------------------------------------------------------------
	if (text_m == 0)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
		if (word[0] == 0)
		{
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
	    else if (word[0] == 1)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���̕����͉������邩��", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���̕����͉������邩��", 108, 490, 16, c);
			}
		}
		else if (word[0] == 2)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = 128.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���A��l���I", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = 128.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���A��l���I", 108, 490, 16, c);
			}
		}
		else if (word[0] == 3)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�启�H�ǂ������񂾂���ȏ���", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�启�H�ǂ������񂾂���ȏ���", 108, 490, 16, c);
			}
		}
		else if (word[0] == 4)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 192.0f;
				src.m_right = 255.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���̕������낢�뒲�ׂĂ�̂�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 192.0f;
				src.m_right = 255.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���̕������낢�뒲�ׂĂ�̂�", 108, 490, 16, c);
			}
		}
		else if (word[0] == 5)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�������c�������ʂ͂��������H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�������c�������ʂ͂��������H", 108, 490, 16, c);
			}
		}
		else if (word[0] == 6)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�Ɓc���R�ł���H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�Ɓc���R�ł���H", 108, 490, 16, c);
			}
		}
		else if (word[0] == 7)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�ق�Ƃ��I�H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�ق�Ƃ��I�H", 108, 490, 16, c);
			}
		}
		else if (word[0] == 8)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 383.0f;
				src.m_right = 447.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���c�������", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 383.0f;
				src.m_right = 447.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���c�������", 108, 490, 16, c);
			}
		}
		else if (word[0] == 9)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����������񂾁H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����������񂾁H", 108, 490, 16, c);
			}
		}
		else if (word[0] == 10)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�c�c��", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�c�c��", 108, 490, 16, c);
			}
		}
		else if (word[0] == 11)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����A�������Ȃ�����", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����A�������Ȃ�����", 108, 490, 16, c);
			}
		}
		else if (word[0] == 12)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����������Ȃ��������Č����Ă�̂�!!", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:����������Ȃ��������Č����Ă�̂�!!", 108, 490, 16, c);
			}

		}
		else if (word[0] == 13)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�c���H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�c���H", 108, 490, 16, c);
			}
		}
		else if (word[0] == 14)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�����������B�����������{�I�����ɂ�������Ȃ��������", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�����������B�����������{�I�����ɂ�������Ȃ��������", 108, 490, 16, c);
			}
		}
		else if (word[0] == 15)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���A�����c����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���A�����c����", 108, 490, 16, c);
			}
		}
		else if (word[0] == 16)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 64.0f;
				src.m_right = 128.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�c���߂�Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 64.0f;
				src.m_right = 128.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�c���߂�Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word[0] == 17)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���Ȃ��ɂ������Ă��d���Ȃ����̂�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���Ȃ��ɂ������Ă��d���Ȃ����̂�", 108, 490, 16, c);
			}
		}
		else if (word[0] == 18)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�C�ɂ���Ȃ�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�C�ɂ���Ȃ�", 108, 490, 16, c);
			}
		}
		else if (word[0] == 19)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����ꏏ�ɒT������", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����ꏏ�ɒT������", 108, 490, 16, c);
			}
		}
		else if (word[0] == 20)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���肪�Ƃ�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���肪�Ƃ�", 108, 490, 16, c);
			}
		}
		else if (word[0] == 21)
		{
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
	}
	//����献�擾��----------------------------------------
	else if (text_m == 3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
		if (word[0] == 21)
		{
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		else if (word[0] == 22)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:������������������?", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:������������������?", 108, 490, 16, c);
			}
		}
		else if (word[0] == 23)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom =192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��������������������", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��������������������", 108, 490, 16, c);
			}
		}
		else if (word[0] == 24)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top =64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�����������Ă�����", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�����������Ă�����", 108, 490, 16, c);
			}
		}
		else if (word[0] == 25)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�i���o�[���b�N�Ƃ�����������H", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�i���o�[���b�N�Ƃ�����������H", 108, 490, 16, c);
			}
		}
		else if (word[0] == 26)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�Ȃ�ǂ����g���ꏊ���ǂ����ɂ����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�Ȃ�ǂ����g���ꏊ���ǂ����ɂ����", 108, 490, 16, c);
			}
		}
		else if (word[0] == 27)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�܂��͂��̕�����T���Ă݂悤", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�Ȃ�ǂ����g���ꏊ���ǂ����ɂ����", 108, 490, 16, c);
			}
		}
		else if (word[0] == 28)
		{
			Font::StrDraw(L"���b�N�h�A��T�����I", 50, 490, 32, c);
		}
	}
	//�����}�b�v��������---------------------------------------------------------------------
	else if (text_m == 4)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
	    if (word[0] == 28)
	    {
		    Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
	    }
		else if (word[0] == 29)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = 128.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������ˁI", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = 128.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������ˁI", 108, 490, 16, c);
			}
		}
		else if(word[0] == 30)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�启�̂�������", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�启�̂�������", 108, 490, 16, c);
			}
		}
		else if (word[0] == 31)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���肪�Ƃ���", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���肪�Ƃ���", 108, 490, 16, c);
			}
		}
		else if (word[0] == 32)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�ʂɎ��͉������ĂȂ���", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�ʂɎ��͉������ĂȂ���", 108, 490, 16, c);
			}
		}
		else if (word[0] == 33)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������������̂����b�N���������̂����Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������������̂����b�N���������̂����Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word[0] == 34)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�ł�����l���ᖳ����������", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�ł�����l���ᖳ����������", 108, 490, 16, c);
			}
		}
		else if (word[0] == 35)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����炠�肪�Ƃ�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����炠�肪�Ƃ�", 108, 490, 16, c);
			}
		}
		else if (word[0] == 36)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�c�Ȃ炻�̂��炠�肪�����󂯎���Ă�����", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�c�Ȃ炻�̂��炠�肪�����󂯎���Ă�����", 108, 490, 16, c);
			}
		}
		else if (word[0] == 37)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���͑��̏ꏊ�𒲂ׂɍs�����ǂǂ�����H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���͑��̏ꏊ�𒲂ׂɍs�����ǂǂ�����H", 108, 490, 16, c);
			}
		}
		else if (word[0] == 38)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���͂�������������T�����Ă݂��", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���͂�������������T�����Ă݂��", 108, 490, 16, c);
			}
		}
		else if (word[0] == 39)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���x�������������Ă������", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:���x�������������Ă������", 108, 490, 16, c);
			}
		}
		else if (word[0] == 40)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�킩����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�킩����", 108, 490, 16, c);
			}
		}
		else if (word[0] ==41)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�������邩�킩��Ȃ�����C�������", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�������邩�킩��Ȃ�����C�������", 108, 490, 16, c);
			}
		}
		else if (word[0] == 42)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�����������h�W���񂶂�Ȃ����", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�����������h�W���񂶂�Ȃ����", 108, 490, 16, c);
			}
		}
	}
	//�t���}�b�v�i����-------------------------------------------------------------------------
	if (text_m == 1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"�}����", 670, 532, 32, c);
		if (word[1] == 0)
		{
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		if (word[1] == 1)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�₯�ɕЕt������������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�₯�ɕЕt������������", 108, 490, 16, c);
			}
		}
		else if (word[1] == 2)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = 128.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���A��l������B�ǂ����������܂������H", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = 128.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���A��l������B�ǂ����������܂������H", 108, 490, 16, c);
			}
		}
		else if (word[1] == 3)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�ݖ삳�񂢂���ł���", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�ݖ삳�񂢂���ł���", 108, 490, 16, c);
			}
		}
		else if (word[1] == 4)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 192.0f;
				src.m_right = 255.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�����������܂�Ȃ��Ă����v�ł���B�����N�ł�����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 192.0f;
				src.m_right = 255.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�����������܂�Ȃ��Ă����v�ł���B�����N�ł�����", 108, 490, 16, c);
			}
		}
		else if (word[1] == 5)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�킩�����B�ŁA�ݖ삳��͂ǂ����Ă͂����������Ă���񂾁H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�킩�����B�ŁA�ݖ삳��͂ǂ����Ă͂����������Ă���񂾁H", 108, 490, 16, c);
			}
		}
		else if (word[1] == 6)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�E�Ə㉘������������ƕЕt�������Ȃ��ł�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�E�Ə㉘������������ƕЕt�������Ȃ��ł�", 108, 490, 16, c);
			}
		}
		else if (word[1] == 7)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���������Ⴀ��`����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���������Ⴀ��`����", 108, 490, 16, c);
			}
		}
		else if (word[1] == 8)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 383.0f;
				src.m_right = 447.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���H������ł����H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 383.0f;
				src.m_right = 447.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:���H������ł����H", 108, 490, 16, c);
			}
		}
		else if (word[1] == 9)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����̕ЂÂ����Ȃ���T���΂�����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����̕ЂÂ����Ȃ���T���΂�����", 108, 490, 16, c);
			}
		}
		else if (word[1] == 10)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�\���󂠂�܂���B�葁���I��点�܂��̂�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�\���󂠂�܂���B�葁���I��点�܂��̂�", 108, 490, 16, c);
			}
		}
		else if (word[1] == 11)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���ꂶ�Ⴀ�n�߂悤��", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���ꂶ�Ⴀ�n�߂悤��", 108, 490, 16, c);
			}
		}
		else if (word[1] == 12)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�͂��I", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�͂��I", 108, 490, 16, c);
			}
		}
		else if (word[1] == 13)
		{
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
		else if (word[1] == 14)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���������������������g����������", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���������������������g����������", 108, 490, 16, c);
			}
		}
		else if (word[1] == 15)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:������������ł����H", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:������������ł����H", 108, 490, 16, c);
			}
		}
		else if (word[1] == 16)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��������������", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��������������", 108, 490, 16, c);
			}
		}
		else if (word[1] == 17)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�J���Ă݂܂��傤", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�J���Ă݂܂��傤", 108, 490, 16, c);
			}
		}
		else if (word[1] == 18)
		{
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
		else if (word[1] == 19)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����̃�������", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�����̃�������", 108, 490, 16, c);
			}
		}
		else if (word[1] == 20)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�Ȃ�ł��傤��", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�Ȃ�ł��傤��", 108, 490, 16, c);
			}
		}
		else if (word[1] == 21)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�Ƃ肠�������̕��������ĉ���ė����", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�Ƃ肠�������̕��������ĉ���ė����", 108, 490, 16, c);
			}
		}
		else if (word[1] == 22)
		{
			if (time < 100)
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�킩��܂����B����l����낵�����肢���܂�", 108, 590 - time, 16, c);
			}
			else
			{
				src.m_top = 128.0f;
				src.m_left = 256.0f;
				src.m_right = 320.0f;
				src.m_bottom = 192.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:�킩��܂����B����l����낵�����肢���܂�", 108, 490, 16, c);
			}
		}

	}
	//�i���}�b�v�i����-------------------------------------------------------------------------
	if (text_m == 2)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"�a��", 685, 532, 32, c);
		if (word[2] == 0)
		{
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		else if (word[2] == 1)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:��l���N�A�ǂ��������̂��ȁH", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:��l���N�A�ǂ��������̂��ȁH", 108, 490, 16, c);
			}
		}
		else if (word[2] == 2)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�k���y�ł����B���̕����ɉ�������܂����H", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�k���y�ł����B���̕����ɉ�������܂����H", 108, 490, 16, c);
			}
		}
		else if (word[2] == 3)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�i���ł�����B���ɂ��������񂾂��ǁA", 108, 590 - time, 16, c);
				Font::StrDraw(L"�����������Ă�݂����Ȃ�", 108, 606 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�i���ł�����B���ɂ��������񂾂��ǁA", 108, 490, 16, c);
				Font::StrDraw(L"�����������Ă�݂����Ȃ�", 108, 506, 16, c);
			}
		}
		else if (word[2] == 4)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���ɂ̌��ł����c���̕����ɂ���܂����ˁH", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:���ɂ̌��ł����c���̕����ɂ���܂����ˁH", 108, 490, 16, c);
			}
		}
		else if (word[2] == 5)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�܂���������T���ĂȂ����牽�Ƃ������Ȃ��ȁ`", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�܂���������T���ĂȂ����牽�Ƃ������Ȃ��ȁ`", 108, 490, 16, c);
			}
		}
		else if (word[2] == 6)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�킩��܂����B�����ꏏ�ɒT���܂���", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�킩��܂����B�����ꏏ�ɒT���܂���", 108, 490, 16, c);
			}
		}
		else if (word[2] == 7)
		{
			if (time < 100)
			{
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���肪�Ƃ��B����������ۂ����̌������狳���Ă�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���肪�Ƃ��B����������ۂ����̌������狳���Ă�", 108, 490, 16, c);
			}
		}
		else if (word[2] == 8)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�͂�", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�͂�", 108, 490, 16, c);
			}
		}
		else if (word[2] == 9)
		{
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
		else if (word[2] == 10)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��������܂�����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��������܂�����", 108, 490, 16, c);
			}
		}
		else if (word[2] == 11)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���肪�Ƃ��B�J���Ă݂����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���肪�Ƃ��B�J���Ă݂����", 108, 490, 16, c);
			}
		}
		else if (word[2] == 12)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�J���Ȃ��ł���", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�J���Ȃ��ł���", 108, 490, 16, c);
			}
		}
		else if (word[2] == 12)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���ɂ��Ȃ����T���Ă݂悤", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���ɂ��Ȃ����T���Ă݂悤", 108, 490, 16, c);
			}
		}
		else if (word[2] == 12)
		{
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
		else if (word[2] == 13)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��y������ۂ��������܂�����", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:��y������ۂ��������܂�����", 108, 490, 16, c);
			}
		}
		else if (word[2] == 14)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���肪�Ƃ��B���ꂶ�Ⴀ�J���Ă݂悤���B", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:���肪�Ƃ��B���ꂶ�Ⴀ�J���Ă݂悤���B", 108, 490, 16, c);
			}
		}
		else if (word[2] == 15)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:����́A�����̃������ȁH", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:����́A�����̃������ȁH", 108, 490, 16, c);
			}
		}
		else if (word[2] == 16)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�݂����ł��ˁB�����̓��e�I�ɂ͖{�I�ɉ�������݂����ł����c", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�݂����ł��ˁB�����̓��e�I�ɂ͖{�I�ɉ�������݂����ł����c", 108, 490, 16, c);
			}
		}
		else if (word[2] == 17)
		{
			if (time < 100)
			{
				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�����������瑼�ɂ����������邩������Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{

				src.m_top = 0.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�����������瑼�ɂ����������邩������Ȃ���", 108, 490, 16, c);
			}
		}
	}
	if (text_m == 3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
		if (word[4] == 0)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:3�̃�������������݂�������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:3�̃�������������݂�������", 108, 490, 16, c);
			}
		}
		else if (word[4] == 1)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�������", 108, 490, 16, c);
			}
		}
		else if (word[4] == 2)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�E�o�Q�[�����ۂ��Ȃ��Ă�����I", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����:�E�o�Q�[�����ۂ��Ȃ��Ă�����I", 108, 490, 16, c);
			}
		}
		else if (word[4] == 3)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:����Ń����ɂȂ�ď����Ă����ł����H", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�t��:����Ń����ɂȂ�ď����Ă����ł����H", 108, 490, 16, c);
			}
		}
		else if (word[4] == 4)
		{
			if (time < 100)
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�u�~�X�~�\�E�v�u�C�t�F�C�I���v�u�T�N���\�E�v��", 108, 590 - time, 16, c);
			}
			else
			{
				//�w�i�\��
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"��l��:�u�~�X�~�\�E�v�u�C�t�F�C�I���v�u�T�N���\�E�v��", 108, 490, 16, c);
			}
		}
	}
}