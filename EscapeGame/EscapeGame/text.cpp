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
int word=7;
//�C�j�V�����C�Y
void CObjText::Init()
{
	m_key_flag = false;
	skip_flag = false;
	time = 220;
	time_x = -1;
	g = 0;
}
//�A�N�V����
void CObjText::Action()
{
	time += 1;
	time_x -= 1;
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
						if (time > 220)
						{
							if (text_m == 0 && word < 10 || text_m == 3 && word < 22 || 
								text_m == 1 && word < 13 || text_m == 2 && word < 9  || text_m == -1 && word < 54||
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
				else if(time<200)
				{
					time = 200;
				}
				else if (time > 220 && time_x < 200&&time_x>0)
				{
					time_x = 0;
				}
				else if(time>220&&time_x<-20)
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
	RECT_F src_B;//�e�L�X�g�\���B��(�㕔�j�`�挳�؂���ʒu
	RECT_F dst_B;//�e�L�X�g�\���B��(�㕔�j�`��\���ʒu
	RECT_F src_C;//�e�L�X�g�\���B��(�����j�`�挳�؂���ʒu
	RECT_F dst_C;//�e�L�X�g�\���B��(�����j�`��\���ʒu
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
			Font::StrDraw(L"�启�����̓��C�h�̊ݖ�t����",108, 510, 30, c);
			Font::StrDraw(L"���Z���Ă���ƓˑR�J���~���Ă���", 108, 540, 30, c);
		}
		else if (word == 2)
		{
			Font::StrDraw(L"��l�͂��܂��܋߂��ɂ������ق�", 108, 510, 30, c);
			Font::StrDraw(L"�J�h�肷�邱�Ƃɂ����̂ł�����", 108, 540, 30, c);
		}
		else if (word == 3)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�˂��t���c�J����ނ��ȁH", 108, 490, 25, c);
		}
		else if (word == 4)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:���̊������Ƃ�����ނƎv���܂���", 108, 490, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???:�����Ȃ�J�h��ł��������ȁc", 108, 490, 25, c);
		}
		else if (word == 6)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�N!?", 108, 490, 25, c);
		}
		else if (word == 7)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???:��q�������̂�", 108, 490, 25, c);
		}
		else if (word == 8)
		{
			g = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???:���̖��O�͖P����B", 108, 490, 25, c);
			Font::StrDraw(L"�N�Ɠ����w�Z�̓�N��", 108, 515, 25, c);
		}
		else if (word == 9)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���A�Z���p�C�ł����H", 108, 490, 25, c);
		}
		else if (word == 10)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���͑启������", 108, 490, 25, c);
		}
		else if (word == 11)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�^�����ʂ�J�ɍ~���", 108, 490, 25, c);
			Font::StrDraw(L"�}築J�h�肵�Ă��", 108, 515, 25, c);
		}
		else if (word == 12)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:���݂��Г��", 108, 490, 25, c);
		}
		else if (word == 13)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�������͎��̃��C�h�̊ݖ�t����", 108, 490, 25, c);
		}
		else if (word== 14)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�ݖ�t���ł��B", 108, 490, 25, c);
		}
		else if (word == 15)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�����l�̃��C�h�ł�", 108, 490, 25, c);
		}
		else if (word== 16)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???:�l�������ς������", 108, 490, 25, c);
		}
		else if (word == 17)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�m�����Ȃ��́c", 108, 490, 25, c);
		}
		else if (word == 18)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:���k��̖k��i������ł���", 108, 490, 25, c);
		}
		else if (word == 19)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:��������", 108, 490, 25, c);
		}
		else if (word == 20)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:�N�͑勴����Ƃ̃��C�h���񂾂�", 108, 490, 25, c);
		}
		else if (word == 21)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�ݖ�t���ł�", 108, 490, 25, c);
		}
		else if (word == 22)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
	        Font::StrDraw(L"�P:���A�J��ݎn�߂Ă܂���",  108, 490, 25, c);
		}
		else if (word == 23)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�t��!�Ƃ��ƂƋA����I",  108, 490, 25, c);
		}
		else if (word == 24)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�������܂�܂����B", 108, 490, 25, c);
			Font::StrDraw(L"����ł͎��炵�܂�", 108, 515, 25, c);
		}
		else if (word == 25)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�����A�낤", 108, 490, 25, c);
		}
		else if (word == 26)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:�l���A��Ȃ���", 108, 490, 25, c);
		}
		else if (word == 27)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:��H", 108, 490, 25, c);
		}
		else if (word == 28)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�h�A���J���Ȃ���", 108, 490, 25, c);
		}
		else if (word == 29)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:����Ȃ킯�Ȃ��ł���", 108, 490, 25, c);
		}
		else if (word == 30)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:���炵�܂�", 108, 490, 25, c);
		}
		else if (word == 31)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�J���܂����", 108, 490, 25, c);
		}
		else if (word == 32)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:�{�������H", 108, 490, 25, c);
		}
		else if (word == 33)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
		    Font::StrDraw(L"�P:���āA�ǂ��������̂�", 108, 490, 25, c);
		}
		else if (word == 34)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�������̃h�A�͊J�����", 108, 490, 25, c);
		}
		else if (word == 35)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�Ȃ炻������T�����邩�H", 108, 490, 25, c);
		}
		else if (word == 36)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:���܂肨���߂͂��܂����", 108, 490, 25, c);
		}
		else if (word== 37)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:���Ԃ����ĂΉ䂪�Ƃ̋~���`�[����", 108, 490, 25, c);
			Font::StrDraw(L"�삯�t���܂��̂ł��΂����҂���������", 108, 515, 25, c);
		}
		else if (word == 38)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:�ł��A����ȋ@��ő��ɂȂ���", 108, 490, 25, c);
			Font::StrDraw(L"�l�͒T���Ɏ^������", 108, 515, 25, c);
		}
		else if (word == 39)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�����T����������", 108, 490, 25, c);
		}
		else if (word == 40)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�t���A�~���`�[���̎�z�͑҂��Ȃ���", 108, 490, 25, c);
		}
		else if (word ==41)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�������c", 108, 490, 25, c);
		}
		else if (word == 42)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�t���I", 108, 490, 25, c);
		}
		else if (word == 43)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�������܂�܂���", 108, 490, 25, c);
		}
		else if (word == 44)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�ł����玄��", 108, 490, 25, c);
			Font::StrDraw(L"�܂��S�����̈��S���m���߂܂�", 108, 515, 25, c);
		}
		else if (word == 45)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:���̌�F�����", 108, 490, 25, c);
			Font::StrDraw(L"�T�����Ă��炤�Ƃ������ƂŁc", 108, 515, 25, c);
		}
		else if (word == 46)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:����Ȃ��Ƃ�����", 108, 490, 25, c);
			Font::StrDraw(L"��΋����Ȃ�����ˁH", 108, 515, 25, c);
		}
		else if (word== 47)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�ł����琳�ʂ̕�����", 108, 490, 25, c);
			Font::StrDraw(L"�T���Ȃ��낵���ł��傤�H", 108, 515, 25, c);
		}
		else if (word == 48)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:����Ȃ炢����", 108, 490, 25, c);
		}
		else if (word == 49)
		{
			g = 1;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:���ꂶ�Ⴀ�l��", 108, 490, 25, c);
			Font::StrDraw(L"�������̕�����T�������", 108, 515, 25, c);
		}
		else if (word == 50)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���肢���܂��ː�y", 108, 490, 25, c);
		}
		else if (word == 51)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:��̊ق̒T���̊J�n���[�I", 108, 490, 25, c);
		}
		else if (word == 52)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���[�I", 108, 490, 25, c);
		}
		else if (word == 53)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:���A���[�c", 108, 490, 25, c);
		}
		else if (word == 54)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"�����������ŒT�����悤", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//�����}�b�v
	//�i�����@word=0�`10
	//�����㎞�@word=10�`21
	if (text_m == -3)
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
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���A�P�N�I", 108, 490, 25, c);
		}
		else if (word == 2)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�启�H�ǂ������񂾂���ȏ���", 108, 490, 25, c);
		}
		else if (word == 3)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���̕������낢�뒲�ׂĂ�̂�", 108, 490, 25, c);
		}
		else if (word == 4)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�������c�������ʂ͂��������H", 108, 490, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:����������Ȃ�������c", 108, 490, 25, c);
		}
		else if (word == 6)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�C�ɂ����", 108, 490, 25, c);
		}
		else if (word == 7)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�����ꏏ�ɒT������", 108, 490,25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���肪�Ƃ�", 108, 490, 25, c);
		}
		else if (word == 9)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���ꂶ�Ⴀ�Ƃ��Ƃ�", 108, 490, 25, c);
			Font::StrDraw(L"��|���茩������I", 108, 515, 25, c);
		}
		else if (word == 10)
		{
			g = 3;
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
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�启�I������������", 108, 490, 25, c);
		}
		else if (word == 12)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�ق�ƁH", 108, 490, 25, c);
		}
		else if (word == 13)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���ǎ�����", 108, 490, 25, c);
			Font::StrDraw(L"�������Ȃ�������", 108, 515, 25, c);
		}
		else if (word == 14)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:����܂�C�ɂ���Ȃ�H", 108, 490, 25, c);
		}
		else if (word == 15)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�S�z�Ȃ���", 108, 490, 25, c);
		}
		else if (word == 16)
		{
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���x�������������Ă�����", 108, 490, 25, c);
			Font::StrDraw(L"�����Ă�����", 108, 515, 25, c);
		}
		else if (word == 17)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�撣��̂͂������ǖ�������Ȃ�H", 108, 490, 25, c);
		}
		else if (word == 18)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:���͈Ⴄ������T�����Ă����", 108, 490, 25, c);
		}
		else if (word == 19)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:���͂�������������T�����Ă��", 108, 490, 25, c);
		}
		else if (word == 20)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"��l��:�������ǋC�������", 108, 490, 25, c);
		}
		else if (word == 21)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�����������C�����Ȃ�����", 108, 490, 25, c);
		}
		else if (word == 22)
		{
			g = 3;
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
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�₯�ɕЕt������������", 108, 490, 25, c);
		}
		else if (word == 2)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:���A�P����B", 108, 490, 25, c);
			Font::StrDraw(L"�ǂ����������܂������H", 108, 515, 25, c);
		}
		else if (word == 3)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�ݖ삳�񂢂���ł���", 108, 490, 25, c);
		}
		else if (word == 4)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�����������܂�Ȃ��Ă����v�ł���B", 108, 490, 25, c);
			Font::StrDraw(L"�����N�ł�����", 108, 515, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�킩�����B�ŁA�ݖ삳��͂ǂ�����", 108, 490, 25, c);
			Font::StrDraw(L"�͂����������Ă���񂾁H", 108, 515, 25, c);
		}
		else if (word == 6)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�E�Ə㉘������������ƕЕt�������Ȃ��ł�", 108, 490, 25, c);
			Font::StrDraw(L"�Еt�������Ȃ��ł�", 108, 515, 25, c);
		}
		else if (word == 7)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:���������Ⴀ��`����", 108, 490, 25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:���H������ł����H", 108, 490, 25, c);
		}
		else if (word == 9)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�����̕ЂÂ����Ȃ���T���΂�����", 108, 490, 25, c);
		}
		else if (word == 10)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�\���󂠂�܂���B�葁���I��点�܂��̂�", 108, 490, 25, c);
			Font::StrDraw(L"�葁���I��点�܂��̂�", 108, 515, 25, c);
		}
		else if (word == 11)
		{
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:���ꂶ�Ⴀ�n�߂悤��", 108, 490, 25, c);
		}
		else if (word == 12)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�͂��I", 108, 490, 25, c);
		}
		else if (word == 13)
		{
			g = 3;
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
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�����̃�������", 108, 490, 25, c);
		}
		else if (word == 15)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�Ȃ�ł��傤��", 108, 490, 25, c);
		}
		else if (word == 16)
		{
			g = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�Ƃ肠�������̕�����", 108, 490, 25, c);
			Font::StrDraw(L"������ė����", 108, 515, 25, c);
		}
		else if (word == 17)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�킩��܂����B", 108, 490, 25, c);
			Font::StrDraw(L"����l����낵�����肢���܂�", 108, 515, 25, c);
		}
		else if (word == 18)
		{
			g = 3;
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
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:�P�N�A�ǂ��������̂��ȁH", 108, 490, 25, c);
		}
		else if (word == 2)
		{
			g = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�k���y�ł����B", 108, 490, 25, c);
			Font::StrDraw(L"�P:���̕����ɉ�������܂����H", 108, 515, 25, c);
		}
		else if (word == 3)
		{
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:�܂����ɂ��������ĂȂ���", 108, 490, 25, c);
		}
		else if (word == 4)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:�������I", 108, 490, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:�T���̈ꏏ�Ɏ�`���Ă�", 108, 490, 25, c);
		}
		else if (word == 6)
		{
			g = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�킩��܂����B", 108, 490, 25, c);
			Font::StrDraw(L"���ł悯��Ύ�`���܂���", 108, 515, 25, c);
		}
		else if (word == 7)
		{
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:���肪�Ƃ��B", 108, 490, 25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:���ꂶ���낵���I", 108, 490, 25, c);
		}
		else if (word == 9)
		{
			g = 3;
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
				g = 2;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:����͉����̃�������?", 108, 490, 25, c);
			}
			else if (word == 11)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�P:�݂����ł���", 108, 490, 25, c);
			}
			else if (word == 12)
			{
				g = 1;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�����������瑼�ɂ�", 108, 490, 25, c);
				Font::StrDraw(L"�������邩������Ȃ���", 108, 515, 25, c);
			}
			else if (word == 13)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�P:�ł��ˁB", 108, 490, 25, c);
				Font::StrDraw(L"�����Ƃ��̕������ׂĂ݂܂��傤��", 108, 515, 25, c);
			}
			else if (word == 14)
			{
				g = 2;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�P�N�͑��̕����𒲂ׂɍs���Ă݂Ă�", 108, 490, 25, c);
			}
			else if (word == 15)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�P:���v�ł����H", 108, 490, 25, c);
			}
			else if (word == 16)
			{
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�i��:�l�͐��k��Ȃ񂾂�?���v����", 108, 490, 25, c);
			}
			else if (word == 17)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�P:�킩��܂����B��y���C��t����", 108, 490, 25, c);
			}
			else if (word == 18)
			{
				Draw::Draw(52, &src, &dst, c, 0.0f);
			    Font::StrDraw(L"�i��:�C����", 108, 490, 25, c);
			}
			else if (word == 19)
			{
				g = 3;
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
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:3�̃�������������݂�������", 108, 490, 25, c);
		}
		else if (word == 1)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:��������", 108, 490, 25, c);
		}
		else if (word == 2)
		{
			g = 1;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:����Ń����ɂ�", 108, 490, 25, c);
			Font::StrDraw(L"�Ȃ�ď����Ă����ł���?", 108, 515, 25, c);
		}
		else if (word== 3)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�u�~�X�~�\�E�v", 108, 490, 25, c);
			Font::StrDraw(L"�u�C�t�F�C�I���v", 108, 515, 25, c);
			Font::StrDraw(L"�u�T�N���\�E�v����", 108, 540, 25, c);
		}
		else if (word == 4)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�C�t�F�C�I���H", 108, 490, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�Ȃɂ悻��", 108, 490, 25, c);
		}
		else if (word == 6)
		{
			g = 3;
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
			g = 1;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:��K�ɗ����̂͂�������", 108, 490, 25, c);
			Font::StrDraw(L"���ꂶ��o���Ȃ����H", 108, 490, 25, c);
		}
		if (word == 8)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:���̊K�ɉ�����|���肪����񂶂�Ȃ�����", 108, 490, 25, c);
			Font::StrDraw(L"����񂶂�Ȃ�����", 108, 515, 25, c);
		}
		else if (word == 9)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:���ꂶ�Ⴑ�̕�����", 108, 490, 25, c);
			Font::StrDraw(L"�i��:������ĒT�������ł������ȁH", 108, 515, 25, c);
		}
		else if (word == 10)
		{
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�Ȃ玄�͂������ɍs����I", 108, 490, 25, c);
		}
		else if (word == 11)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����:�t���͂������𒲂ׂȂ����I", 108, 490, 25, c);
		}
		else if (word == 12)
		{
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t��:�������܂�܂���", 108, 490, 25, c);
		}
		else if (word == 13)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�i��:���ꂶ�Ⴀ�l�͎c��̕����𒲂ׂ悤����", 108, 490, 25, c);
		}
		if (word == 14)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�P:�i���͒N������`���ɍs�����j", 108, 490, 25, c);
		}
		if (word == 15)
		{
			g = 3;
			text_move = false;
			Font::StrDraw(L"�����������ŒT�����悤", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//�e�L�X�g�ړ�
	if (time < 200&&g==0)
	{
		src_B.m_top = 0.0f;
		src_B.m_left = 110.0f + time*1.655f;
		src_B.m_right = 512.0f;
		src_B.m_bottom = 60.0f;
		dst_B.m_top = 480.0f;
		dst_B.m_left = 110.0f + time*2.2f;
		dst_B.m_right = 640.0f;
		dst_B.m_bottom =540.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
		//�e�L�X�g�\���B��(�����j�`��\���ʒu
		src_C.m_top = 60.0f;
		src_C.m_left = 110.0f ;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 540.0f;
		dst_C.m_left = 110.0f;
		dst_C.m_right = 640.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if(time==200 && g == 0)
	{
		time_x = 200;
	}
	if (time_x <= 200&&time_x>=0 && g == 0)
	{
		src_C.m_top = 60.0f;
		src_C.m_left = 110.0f + (200-time_x)*1.655f;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 540.0f;
		dst_C.m_left = 110.0f + (200 - time_x)*2.2f;
		dst_C.m_right = 640.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if(g == 0)
	{

	}
	//�e�L�X�g�ړ�
	if (time < 200 && g == 1)
	{
		src_B.m_top = 0.0f;
		src_B.m_left = 110.0f + time*1.655f;
		src_B.m_right = 512.0f;
		src_B.m_bottom = 35.0f;
		dst_B.m_top = 480.0f;
		dst_B.m_left = 110.0f + time*2.2f;
		dst_B.m_right = 640.0f;
		dst_B.m_bottom = 515.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
		//�e�L�X�g�\���B��(�����j�`��\���ʒu
		src_C.m_top = 35.0f;
		src_C.m_left = 110.0f;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 515.0f;
		dst_C.m_left = 110.0f;
		dst_C.m_right = 640.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if (time == 200 && g == 1)
	{
		time_x = 200;
	}
	if (time_x <= 200 && time_x >= 0 && g == 1)
	{
		src_C.m_top = 35.0f;
		src_C.m_left = 110.0f + (200 - time_x)*1.655f;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 515.0f;
		dst_C.m_left = 110.0f + (200 - time_x)*2.2f;
		dst_C.m_right = 640.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if (g == 1)
	{

	}
	//�e�L�X�g�ړ�
	if (time < 200 && g == 2)
	{
		src_B.m_top = 0.0f;
		src_B.m_left = 110.0f + time*1.655f;
		src_B.m_right = 512.0f;
		src_B.m_bottom = 120.0f;
		dst_B.m_top = 480.0f;
		dst_B.m_left = 110.0f + time*2.2f;
		dst_B.m_right = 640.0f;
		dst_B.m_bottom = 600.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
	}
	else if (g == 2)
	{

	}

}