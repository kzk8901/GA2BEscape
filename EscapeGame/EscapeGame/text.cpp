//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"ObjBlock.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

bool text_move=true;
int word=0;
//�C�j�V�����C�Y
void CObjText::Init()
{
	m_key_flag = false;
	skip_flag = false;
	time = 120;

	x = 0;
	y = 0;
}
//�A�N�V����
void CObjText::Action()
{
	time += 1;
	//�I�[�v�j���O�@-1
	//�����@-3 0 3
	//�t�� -4 1 4
	//�i�� -5 2 5
    //���� 6 7
	if (Input::GetVKey('Z') == true)
		{
			if (m_key_flag == true)
			{
				if (skip_flag == false)
				{
					if (text_loop == true)
					{
						if (time > 120)
						{
							if (text_m == 0 && word < 10 || text_m == 3 && word < 22 || 
								text_m == 1 && word < 13 || text_m == 2 && word < 9  || text_m == -1 && word < 52||
								text_m == 5 && word < 19 || text_m == 4 && word < 18 || text_m ==  7 && word < 15||
								text_m == 6 && word < 6)
							{
								word += 1;
								m_key_flag = false;
								time = 0;
								skip_flag = true;
							}
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

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`��\���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 465.0f;
	src.m_bottom = 463.0f;
	dst.m_top = 490.0f;
	dst.m_left = 10.0f;
	dst.m_right = 106.0f;
	dst.m_bottom = 590.0f;
	if (text_m == -2)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
	}
	//�I�[�v�j���O
	else if (text_m == -1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�˂��t���c�J����ނ��ȁH", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�˂��t���c�J����ނ��ȁH", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:���̊������Ƃ�����ނƎv���܂���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:���̊������Ƃ�����ނƎv���܂���", 108, 490, 16, c);
			}
		}
		else if (word == 3)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"???:�����Ȃ�J�h��ł��������ȁc", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"???:�����Ȃ�J�h��ł��������ȁc", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�N!?", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�N!?", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"???:��q�������̂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"???:��q�������̂�", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"???:���̖��O�͖P����B�N�Ɠ����w�Z�̓�N��", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"???:���̖��O�͖P����B�N�Ɠ����w�Z�̓�N��", 108, 490, 16, c);
			}
		}
		else if (word == 7)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:����A�����w�Z�̃Z���p�C", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:����A�����w�Z�̃Z���p�C", 108, 490, 16, c);
			}
		}
		else if (word == 8)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�������̖��O�͑启������A�C�h������Ă܂��I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�������̖��O�͑启������A�C�h������Ă܂��I", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�^�����ʂ�J�ɍ~���}築J�h�肵�Ă��", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�^�����ʂ�J�ɍ~���}築J�h�肵�Ă��", 108, 490, 16, c);
			}
		}
		else if (word == 10)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:������", 108, 490, 16, c);
			}
		}
		else if (word == 11)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�������͎��̃}�l�[�W���[�̑t����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�������͎��̃}�l�[�W���[�̑t����", 108, 490, 16, c);
			}
		}
		else if (word== 12)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�ݖ�t���ł��B", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�ݖ�t���ł��B", 108, 490, 16, c);
			}
		}
		else if (word == 13)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�����l�̃}�l�[�W���[�����C�h�ł�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�����l�̃}�l�[�W���[�����C�h�ł�", 108, 490, 16, c);
			}
		}
		else if (word== 14)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:��q��������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:��q��������", 108, 490, 16, c);
			}
		}
		else if (word == 15)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�m�����Ȃ��́c", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�m�����Ȃ��́c", 108, 490, 16, c);
			}
		}
		else if (word == 16)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:���k��̖k��i������ł���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:���k��̖k��i������ł���", 108, 490, 16, c);
			}
		}
		else if (word == 17)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:��������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:��������", 108, 490, 16, c);
			}
		}
		else if (word == 18)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:�N�͑勴����Ƃ̃��C�h���񂾂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:�N�͑勴����Ƃ̃��C�h���񂾂�", 108, 490, 16, c);
			}
		}
		else if (word == 19)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�ݖ�t���ł�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�ݖ�t���ł�", 108, 490, 16, c);
			}
		}
		else if (word == 20)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:���A�J��ݎn�߂Ă܂���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:���A�J��ݎn�߂Ă܂���",  108, 490, 16, c);
			}
		}
		else if (word == 21)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�t��!�Ƃ��ƂƋA����I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�t��!�Ƃ��ƂƋA����I",  108, 490, 16, c);
			}
		}
		else if (word == 22)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�������܂�܂����B����ł͎��炵�܂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�������܂�܂����B����ł͎��炵�܂�", 108, 490, 16, c);
			}
		}
		else if (word == 23)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�����A�낤", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�����A�낤", 108, 490, 16, c);
			}
		}
		else if (word == 24)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:�l���A��Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:�l���A��Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word == 25)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:��H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:��H", 108, 490, 16, c);
			}
		}
		else if (word == 26)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�h�A���J���Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�h�A���J���Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word == 27)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:����Ȃ킯�Ȃ��ł���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:����Ȃ킯�Ȃ��ł���", 108, 490, 16, c);
			}
		}
		else if (word == 28)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:���炵�܂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:���炵�܂�", 108, 490, 16, c);
			}
		}
		else if (word == 29)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�J���܂����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�J���܂����", 108, 490, 16, c);
			}
		}
		else if (word == 30)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:�{�������H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:�{�������H", 108, 490, 16, c);
			}
		}
		else if (word == 31)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:���āA�ǂ��������̂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:���āA�ǂ��������̂�", 108, 490, 16, c);
			}
		}
		else if (word == 32)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�������̃h�A�͊J�����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�������̃h�A�͊J�����", 108, 490, 16, c);
			}
		}
		else if (word == 33)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�Ȃ炻������T�����邩�H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�Ȃ炻������T�����邩�H", 108, 490, 16, c);
			}
		}
		else if (word == 34)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:���܂肨���߂͂��܂����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:���܂肨���߂͂��܂����", 108, 490, 16, c);
			}
		}
		else if (word== 35)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:���Ԃ����ĂΉ䂪�Ƃ̋~���`�[�����삯�t���܂��̂�", 108, 590 - time, 16, c);
				Font::StrDraw(L"���΂����҂���������", 108, 606 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:���Ԃ����ĂΉ䂪�Ƃ̋~���`�[�����삯�t���܂��̂�", 108, 490, 16, c);
				Font::StrDraw(L"���΂����҂���������", 108, 506, 16, c);
			}
		}
		else if (word == 36)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:�ł��A����ȋ@��ő��ɂȂ����l�͒T���Ɏ^������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:�ł��A����ȋ@��ő��ɂȂ����l�͒T���Ɏ^������", 108, 490, 16, c);
			}
		}
		else if (word == 37)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�����T����������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�����T����������", 108, 490, 16, c);
			}
		}
		else if (word == 38)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�t���A�~���`�[���̎�z�͑҂��Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�t���A�~���`�[���̎�z�͑҂��Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word ==39)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�������c", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�������c", 108, 490, 16, c);
			}
		}
		else if (word == 40)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�t���I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�t���I", 108, 490, 16, c);
			}
		}
		else if (word == 41)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�������܂�܂���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�������܂�܂���", 108, 490, 16, c);
			}
		}
		else if (word == 42)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�ł����玄���܂��S�����̈��S���m���߂܂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�ł����玄���܂��S�����̈��S���m���߂܂�", 108, 490, 16, c);
			}
		}
		else if (word == 43)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:���̌�F����ɒT�����Ă��炤�Ƃ������ƂŁc", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:���̌�F����ɒT�����Ă��炤�Ƃ������ƂŁc", 108, 490, 16, c);
			}
		}
		else if (word == 44)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:����Ȃ��Ƃ������΋����Ȃ�����ˁH", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:����Ȃ��Ƃ������΋����Ȃ�����ˁH", 108, 490, 16, c);
			}
		}
		else if (word== 45)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�ł����琳�ʂ̕����̒T���Ȃ��낵���ł��傤�H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�ł����琳�ʂ̕����̒T���Ȃ��낵���ł��傤�H", 108, 490, 16, c);
			}
		}
		else if (word == 46)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:����Ȃ炢����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:����Ȃ炢����", 108, 490, 16, c);
			}
		}
		else if (word == 47)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:���ꂶ�Ⴀ�l�͂������̕�����T�������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:���ꂶ�Ⴀ�l�͂������̕�����T�������", 108, 490, 16, c);
			}
		}
		else if (word == 48)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���肢���܂��ː�y", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���肢���܂��ː�y", 108, 490, 16, c);
			}
		}
		else if (word == 49)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:��̊ق̒T���̊J�n���[�I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:��̊ق̒T���̊J�n���[�I", 108, 490, 16, c);
			}
		}
		else if (word == 50)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���[�I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���[�I", 108, 490, 16, c);
			}
		}
		else if (word == 51)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:���A���[�c", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:���A���[�c", 108, 490, 16, c);
			}
		}
		else if (word == 52)
		{
			text_move = false;
			Font::StrDraw(L"�����������ŒT�����悤", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//�����}�b�v
	//�i�����@word=0�`10
	//�����㎞�@word=10�`21
	else if (text_m == -3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
	}
	//�����}�b�v�i������b-----------------------------------------------------------------------
	else if (text_m == 0)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���A�P�N�I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���A�P�N�I", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�启�H�ǂ������񂾂���ȏ���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�启�H�ǂ������񂾂���ȏ���", 108, 490, 16, c);
			}
		}
		else if (word == 3)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���̕������낢�뒲�ׂĂ�̂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���̕������낢�뒲�ׂĂ�̂�", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�������c�������ʂ͂��������H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�������c�������ʂ͂��������H", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:����������Ȃ�������c", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:����������Ȃ�������c", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�C�ɂ����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�C�ɂ����", 108, 490, 16, c);
			}
		}
		else if (word == 7)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�����ꏏ�ɒT������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�����ꏏ�ɒT������", 108, 490, 16, c);
			}
		}
		else if (word == 8)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���肪�Ƃ�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���肪�Ƃ�", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���ꂶ�Ⴀ�Ƃ��ƂƎ�|���茩������I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���ꂶ�Ⴀ�Ƃ��ƂƎ�|���茩������I", 108, 490, 16, c);
			}
		}
		else if (word == 10)
		{
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
	}
	//����瓚�����͌�-----------------------------------------------------------------------
	else if(text_m==3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
		if (word == 10)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		if (word== 11)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�启�I������������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�启�I������������", 108, 490, 16, c);
			}
		}
		else if (word == 12)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�ق�ƁH", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�ق�ƁH", 108, 490, 16, c);
			}
		}
		else if (word == 13)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���ǎ������������Ȃ�������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���ǎ������������Ȃ�������", 108, 490, 16, c);
			}
		}
		else if (word == 14)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:����܂�C�ɂ���Ȃ�H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:����܂�C�ɂ���Ȃ�H", 108, 490, 16, c);
			}
		}
		else if (word == 15)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�S�z�Ȃ���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�S�z�Ȃ���", 108, 490, 16, c);
			}
		}
		else if (word == 16)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���x�����������߂Ă�����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���x�����������߂Ă�����", 108, 490, 16, c);
			}
		}
		else if (word == 17)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�撣��̂͂������ǖ�������Ȃ�H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�撣��̂͂������ǖ�������Ȃ�H", 108, 490, 16, c);
			}
		}
		else if (word == 18)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:���͈Ⴄ������T�����Ă����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:���͈Ⴄ������T�����Ă����", 108, 490, 16, c);
			}
		}
		else if (word == 19)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:���͂�������������T�����Ă��", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:���͂�������������T�����Ă��", 108, 490, 16, c);
			}
		}
		else if (word == 20)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"��l��:�������ǋC�������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"��l��:�������ǋC�������", 108, 490, 16, c);
			}
		}
		else if (word == 21)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�����������C�����Ȃ�����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�����������C�����Ȃ�����", 108, 490, 16, c);
			}
		}
		else if (word == 22)
		{
			text_move = false;
			Font::StrDraw(L"���̕�����T���ɍs����", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//�t���}�b�v
	//�i�����@word=0�`13
	//���擾���@word=13�`18
	else if (text_m == -4)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"�}����", 670, 532, 32, c);
	}
	//�t���}�b�v�i����-------------------------------------------------------------------------
	else if (text_m == 1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"�}����", 670, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		if (word == 1)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�₯�ɕЕt������������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�₯�ɕЕt������������", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:���A�P����B�ǂ����������܂������H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:���A�P����B�ǂ����������܂������H", 108, 490, 16, c);
			}
		}
		else if (word == 3)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�ݖ삳�񂢂���ł���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�ݖ삳�񂢂���ł���", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�����������܂�Ȃ��Ă����v�ł���B�����N�ł�����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�����������܂�Ȃ��Ă����v�ł���B�����N�ł�����", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�킩�����B�ŁA�ݖ삳��͂ǂ����Ă͂����������Ă���񂾁H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�킩�����B�ŁA�ݖ삳��͂ǂ����Ă͂����������Ă���񂾁H", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�E�Ə㉘������������ƕЕt�������Ȃ��ł�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�E�Ə㉘������������ƕЕt�������Ȃ��ł�", 108, 490, 16, c);
			}
		}
		else if (word == 7)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:���������Ⴀ��`����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:���������Ⴀ��`����", 108, 490, 16, c);
			}
		}
		else if (word == 8)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:���H������ł����H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:���H������ł����H", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�����̕ЂÂ����Ȃ���T���΂�����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�����̕ЂÂ����Ȃ���T���΂�����", 108, 490, 16, c);
			}
		}
		else if (word == 10)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�\���󂠂�܂���B�葁���I��点�܂��̂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�\���󂠂�܂���B�葁���I��点�܂��̂�", 108, 490, 16, c);
			}
		}
		else if (word == 11)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:���ꂶ�Ⴀ�n�߂悤��", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:���ꂶ�Ⴀ�n�߂悤��", 108, 490, 16, c);
			}
		}
		else if (word == 12)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�͂��I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�͂��I", 108, 490, 16, c);
			}
		}
		else if (word == 13)
		{
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
	}
    //�������-----------------------------------------------------------------------
	else if (text_m == 4)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"�}����", 670, 532, 32, c);
		if (word == 13)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		else if (word == 14)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�����̃�������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�����̃�������", 108, 490, 16, c);
			}
		}
		else if (word == 15)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�Ȃ�ł��傤��", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�Ȃ�ł��傤��", 108, 490, 16, c);
			}
		}
		else if (word == 16)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�Ƃ肠�������̕�����������ė����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�Ƃ肠�������̕�����������ė����", 108, 490, 16, c);
			}
		}
		else if (word == 17)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�킩��܂����B����l����낵�����肢���܂�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�킩��܂����B����l����낵�����肢���܂�", 108, 490, 16, c);
			}
		}
		else if (word == 18)
		{
			text_move = false;
			Font::StrDraw(L"���̕�����T���ɍs����", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//�i���}�b�v-----------------------------------------------------------------------
	//�i�����@word=0�`9
	//�����擾���@word=9�`19
	else if (text_m == -5)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"�a��", 685, 532, 32, c);
	}
	//�i���}�b�v�i����-------------------------------------------------------------------------
	else if (text_m == 2)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"�a��", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:�P�N�A�ǂ��������̂��ȁH", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:�P�N�A�ǂ��������̂��ȁH", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�k���y�ł����B���̕����ɉ�������܂����H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�k���y�ł����B���̕����ɉ�������܂����H", 108, 490, 16, c);
			}
		}
		else if (word == 3)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:�܂����ɂ��������ĂȂ���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:�܂����ɂ��������ĂȂ���", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:�������I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:�������I", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:�T���̈ꏏ�Ɏ�`���Ă�", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:�T���̈ꏏ�Ɏ�`���Ă�", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�킩��܂����B���ł悯��Ύ�`���܂���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�킩��܂����B���ł悯��Ύ�`���܂���", 108, 490, 16, c);
			}
		}
		else if (word == 7)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:���肪�Ƃ��B", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:���肪�Ƃ��B", 108, 490, 16, c);
			}
		}
		else if (word == 8)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:���ꂶ���낵���I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:���ꂶ���낵���I", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{

			text_move = false;
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
	}
	//�i���}�b�v������-------------------------------------------------------------------------
	else if (text_m == 5)
		{
			Font::StrDraw(L"1F", 700, 500, 32, c);
			Font::StrDraw(L"�a��", 685, 532, 32, c);
			if (word == 9)
			{
				text_move = true;
				Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
			}
			else if (word == 10)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�i��:����͉����̃�������?", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�i��:����͉����̃�������?", 108, 490, 16, c);
				}
			}
			else if (word == 11)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�P:�݂����ł���", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�P:�݂����ł���", 108, 490, 16, c);
				}
			}
			else if (word == 12)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�i��:�����������瑼�ɂ��������邩������Ȃ���", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�i��:�����������瑼�ɂ��������邩������Ȃ���", 108, 490, 16, c);
				}
			}
			else if (word == 13)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�P:�ł��ˁB�����Ƃ��̕������ׂĂ݂܂��傤��", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�P:�ł��ˁB�����Ƃ��̕������ׂĂ݂܂��傤��", 108, 490, 16, c);
				}
			}
			else if (word == 14)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�i��:�P�N�͑��̕����𒲂ׂɍs���Ă݂Ă�", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�i��:�P�N�͑��̕����𒲂ׂɍs���Ă݂Ă�", 108, 490, 16, c);
				}
			}
			else if (word == 15)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�P:���v�ł����H", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�P:���v�ł����H", 108, 490, 16, c);
				}
			}
			else if (word == 16)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�i��:�l�͐��k��Ȃ񂾂�?���v����", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�i��:�l�͐��k��Ȃ񂾂�?���v����", 108, 490, 16, c);
				}
			}
			else if (word == 17)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�P:�킩��܂����B��y���C��t����", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�P:�킩��܂����B��y���C��t����", 108, 490, 16, c);
				}
			}
			else if (word == 18)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"�i��:�C����", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"�i��:�C����", 108, 490, 16, c);
				}
			}
			else if (word == 19)
			{
				text_move = false;
				Font::StrDraw(L"���̕�����T���ɍs����", 50, 490, 32, c);
				text_loop = false;
			}
		}
	//����
	//�P�K�w1�`6
	//�Q�K�w6�`15
	//�P�K�w-----------------------------------------------------------------------
	else if (text_m == 6)
	{
		text_move = true;
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"����", 685, 532, 32, c);
		if (word == 0)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				
				Font::StrDraw(L"�P:3�̃�������������݂�������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:3�̃�������������݂�������", 108, 490, 16, c);
			}
		}
		else if (word == 1)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:��������", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:��������", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:����Ń����ɂ͂Ȃ�ď����Ă����ł���?", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:����Ń����ɂ͂Ȃ�ď����Ă����ł���?", 108, 490, 16, c);
			}
		}
		else if (word== 3)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�u�~�X�~�\�E�v�u�C�t�F�C�I���v�u�T�N���\�E�v����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�u�~�X�~�\�E�v�u�C�t�F�C�I���v�u�T�N���\�E�v����", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�C�t�F�C�I���H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�C�t�F�C�I���H", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�Ȃɂ悻��", 108, 590 - time, 16, c);
			}
			else 
			{
				Font::StrDraw(L"�����:�Ȃɂ悻��", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", 50, 490, 32, c);
		}
	}
	//�Q�K�w-----------------------------------------------------------------------
	else if (text_m == 7)
	{
		Font::StrDraw(L"2F", 700, 500, 32, c);
		if (word == 6)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 490, 32, c);
		}
		else if (word == 7)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:��K�ɗ����̂͂������ǂ��ꂶ��o���Ȃ����H", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:��K�ɗ����̂͂������ǂ��ꂶ��o���Ȃ����H", 108, 490, 16, c);
			}
		}
		if (word == 8)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:���̊K�ɉ�����|���肪����񂶂�Ȃ�����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:���̊K�ɉ�����|���肪����񂶂�Ȃ�����", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:���ꂶ�Ⴑ�̕�����������ĒT�������ł������ȁH", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:���ꂶ�Ⴑ�̕�����������ĒT�������ł������ȁH", 108, 490, 16, c);
			}
		}
		else if (word == 10)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�Ȃ玄�͂������ɍs����I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�Ȃ玄�͂������ɍs����I", 108, 490, 16, c);
			}
		}
		else if (word == 11)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�����:�t���͂������𒲂ׂȂ����I", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�����:�t���͂������𒲂ׂȂ����I", 108, 490, 16, c);
			}
		}
		else if (word == 12)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�t��:�������܂�܂���", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�t��:�������܂�܂���", 108, 490, 16, c);
			}
		}
		else if (word == 13)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�i��:���ꂶ�Ⴀ�l�͎c��̕����𒲂ׂ悤����", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�i��:���ꂶ�Ⴀ�l�͎c��̕����𒲂ׂ悤����", 108, 490, 16, c);
			}
		}
		if (word == 14)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"�P:�i���͒N������`���ɍs�����j", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"�P:�i���͒N������`���ɍs�����j", 108, 490, 16, c);
			}
		}
		if (word == 15)
		{
			text_move = false;
			Font::StrDraw(L"�����������ŒT�����悤", 50, 490, 32, c);
			text_loop = false;
		}
	}
}