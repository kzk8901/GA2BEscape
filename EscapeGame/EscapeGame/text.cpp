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
	time = 230;
	time_x = -1;
	g = 0;
	d = 0;
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
						if (time > 210)
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
				else if(time<210)
				{
					time = 210;
				}
				else if (time > 230 && time_x < 210&&time_x>0)
				{
					time_x = 0;
				}
				else if(time>230&&time_x<-20)
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
	float c_A[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`��\���ʒu
	RECT_F src_A; //�Ó]���؂���ʒu
	RECT_F dst_A; //�Ó]�`��\���ʒu
	RECT_F src_B;//�e�L�X�g�\���B��(�㕔�j�`�挳�؂���ʒu
	RECT_F dst_B;//�e�L�X�g�\���B��(�㕔�j�`��\���ʒu
	RECT_F src_C;//�e�L�X�g�\���B��(�����j�`�挳�؂���ʒu
	RECT_F dst_C;//�e�L�X�g�\���B��(�����j�`��\���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 465.0f;
	src.m_bottom = 463.0f;
	dst.m_top = 512.0f;
	dst.m_left = 10.0f;
	dst.m_right = 95.0f;
	dst.m_bottom = 592.0f;
	src_A.m_top = 0.0f;
	src_A.m_left = 0.0f;
	src_A.m_right = 32.0f;
	src_A.m_bottom = 32.0f;
	dst_A.m_top = 0.0f;
	dst_A.m_left = 0.0f;
	dst_A.m_right = 640.0f;
	dst_A.m_bottom = 480.0f;
	//d �N���b���Ă��邩�m�F
	//1 �P�@2 ����� 3 �t�� 4 �i��
	//�I�[�v�j���O
	if (text_m == -1)
	{
		if (word == 0)
		{
			text_move = true;
		}
		else if (word == 1)
		{
			Font::StrDraw(L"�启�����̓��C�h�̊ݖ�t����",120, 525, 30, c);
			Font::StrDraw(L"���Z���Ă���ƓˑR�J���~���Ă���", 120, 555, 30, c);
		}
		else if (word == 2)
		{
			Font::StrDraw(L"��l�͂��܂��܋߂��ɂ������ق�", 108, 525, 30, c);
			Font::StrDraw(L"�J�h�肷�邱�Ƃɂ����̂ł�����", 108, 555, 30, c);
		}
		else if (word == 3)
		{
			c_A[3]=1.0-time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 2;
			g = 2;
			Font::StrDraw(L"�˂��t���c�J����ނ��ȁH", 108, 520, 25, c);
		}
		else if (word == 4)
		{
			d = 3;
			Font::StrDraw(L"���̊������Ƃ�����ނƎv���܂���", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			d = 0;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???", 20, 485, 25, c);
			Font::StrDraw(L"�����Ȃ�J�h��ł��������ȁc", 108, 520, 25, c);
		}
		else if (word == 6)
		{
			d = 2;
			Font::StrDraw(L"�N!?", 108, 520, 25, c);
		}
		else if (word == 7)
		{
			d = 0;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???", 20, 485, 25, c);
			Font::StrDraw(L"��q�������̂�", 108, 520, 25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???", 20, 485, 25, c);
			Font::StrDraw(L"���̖��O�͖P����B�N�Ɠ����w�Z�̓�N��", 108, 520, 25, c);
		}
		else if (word == 9)
		{
			d = 2;
			Font::StrDraw(L"���A�Z���p�C�ł����H", 108, 520, 25, c);
		}
		else if (word == 10)
		{
			Font::StrDraw(L"���͑启������", 108, 520, 25, c);
		}
		else if (word == 11)
		{
			Font::StrDraw(L"�^�����ʂ�J�ɍ~���}築J�h�肵�Ă��", 108, 520, 25, c);
		}
		else if (word == 12)
		{
			d = 1;
			Font::StrDraw(L"���݂��Г��", 108, 520, 25, c);
		}
		else if (word == 13)
		{
			d = 2;
			Font::StrDraw(L"�������͎��̃��C�h�̊ݖ�t����", 108, 520, 25, c);
		}
		else if (word== 14)
		{
			d = 3;
			Font::StrDraw(L"�ݖ�t���ł��B", 108, 520, 25, c);
		}
		else if (word == 15)
		{
			Font::StrDraw(L"�����l�̃��C�h�ł�", 108, 520, 25, c);
		}
		else if (word== 16)
		{
			d = 0;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???", 20, 485, 25, c);
			Font::StrDraw(L"�l�������ς������", 108, 520, 25, c);
		}
		else if (word == 17)
		{
			d = 1;
			Font::StrDraw(L"�m�����Ȃ��́c", 108, 520, 25, c);
		}
		else if (word == 18)
		{
			d = 3;
			Font::StrDraw(L"���k��̖k��i������ł���", 108, 520, 25, c);
		}
		else if (word == 19)
		{
			d = 4;
			Font::StrDraw(L"��������", 108, 520, 25, c);
		}
		else if (word == 20)
		{
			d = 4;
			Font::StrDraw(L"�N�͑勴����Ƃ̃��C�h���񂾂�", 108, 520, 25, c);
		}
		else if (word == 21)
		{
			d = 3;
			Font::StrDraw(L"�ݖ�t���ł�", 108, 520, 25, c);
		}
		else if (word == 22)
		{
			d = 1;
	        Font::StrDraw(L"���A�J��ݎn�߂Ă܂���",  108, 520, 25, c);
		}
		else if (word == 23)
		{
			d = 2;
			Font::StrDraw(L"�t��!�Ƃ��ƂƋA����I",  108, 520, 25, c);
		}
		else if (word == 24)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"�������܂�܂����B����ł͎��炵�܂�", 108, 520, 25, c);
		}
		else if (word == 25)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�����A�낤", 108, 520, 25, c);
		}
		else if (word == 26)
		{
			d = 4;
			Font::StrDraw(L"�l���A��Ȃ���", 108, 520, 25, c);
		}
		else if (word == 27)
		{
			d = 1;
			Font::StrDraw(L"��H", 108, 520, 25, c);
		}
		else if (word == 28)
		{
			Font::StrDraw(L"�h�A���J���Ȃ���", 108, 520, 25, c);
		}
		else if (word == 29)
		{
			d = 2;
			Font::StrDraw(L"����Ȃ킯�Ȃ��ł���", 108, 520, 25, c);
		}
		else if (word == 30)
		{
			d = 3;
			Font::StrDraw(L"���炵�܂�", 108, 520, 25, c);
		}
		else if (word == 31)
		{
			Font::StrDraw(L"�J���܂����", 108, 520, 25, c);
		}
		else if (word == 32)
		{
			d = 4;
			Font::StrDraw(L"�{�������H", 108, 520, 25, c);
		}
		else if (word == 33)
		{
			d = 1;
			Font::StrDraw(L"���āA�ǂ��������̂�", 108, 520, 25, c);
		}
		else if (word == 34)
		{
			d = 2;
			Font::StrDraw(L"�������̃h�A�͊J�����", 108, 520, 25, c);
		}
		else if (word == 35)
		{
			d = 1;
			Font::StrDraw(L"�Ȃ炻������T�����邩�H", 108, 520, 25, c);
		}
		else if (word == 36)
		{
			d = 3;
			Font::StrDraw(L"���܂肨���߂͂��܂����", 108, 520, 25, c);
		}
		else if (word== 37)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"���Ԃ����ĂΉ䂪�Ƃ̋~���`�[�����삯�t���܂��̂�", 108, 520, 25, c);
			Font::StrDraw(L"���΂����҂���������", 108, 545, 25, c);
		}
		else if (word == 38)
		{
			d = 4;
			g = 2;
			Font::StrDraw(L"�ł��A����ȋ@��ő��ɂȂ����l�͒T���Ɏ^������", 108, 520, 25, c);
		}
		else if (word == 39)
		{
			d = 2;
			Font::StrDraw(L"�����T����������", 108, 520, 25, c);
		}
		else if (word == 40)
		{
			Font::StrDraw(L"�t���A�~���`�[���̎�z�͑҂��Ȃ���", 108, 520, 25, c);
		}
		else if (word ==41)
		{
			d = 3;
			Font::StrDraw(L"�������c", 108, 520, 25, c);
		}
		else if (word == 42)
		{
			d = 2;
			Font::StrDraw(L"�t���I", 108, 520, 25, c);
		}
		else if (word == 43)
		{
			d = 3;
			Font::StrDraw(L"�������܂�܂���", 108, 520, 25, c);
		}
		else if (word == 44)
		{
			
			Font::StrDraw(L"�ł����玄���܂��S�����̈��S���m���߂܂�", 108, 520, 25, c);
		}
		else if (word == 45)
		{
			Font::StrDraw(L"���̌�F����ɒT�����Ă��炤�Ƃ������ƂŁc", 108, 520, 25, c);
		}
		else if (word == 46)
		{
			d = 2;
			Font::StrDraw(L"����Ȃ��Ƃ������΋����Ȃ�����ˁH", 108, 520, 25, c);
		}
		else if (word== 47)
		{
			d = 3;
			Font::StrDraw(L"�ł����琳�ʂ̕����̒T���Ȃ��낵���ł��傤�H", 108, 520, 25, c);
		}
		else if (word == 48)
		{
			d = 2;
			Font::StrDraw(L"����Ȃ炢����", 108, 520, 25, c);
		}
		else if (word == 49)
		{
			d = 4;
			Font::StrDraw(L"���ꂶ�Ⴀ�l�͂������̕�����T�������", 108, 520, 25, c);
		}
		else if (word == 50)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"���肢���܂��ː�y", 108, 520, 25, c);
		}
		else if (word == 51)
		{
			d = 4;
		    Font::StrDraw(L"��̊ق̒T���̊J�n���[�I", 108, 520, 25, c);
		}
		else if (word == 52)
		{
			d = 2;
			Font::StrDraw(L"���[�I", 108, 520, 25, c);
		}
		else if (word == 53)
		{
			d = 1;
			Font::StrDraw(L"���A���[�c", 108, 520, 25, c);
		}
		else if (word == 54)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�����������ŒT�����悤", 50, 520, 32, c);
			text_loop = false;
		}
	}
	//�����}�b�v
	//�i�����@word=0�`10
	//�����㎞�@word=10�`22
	//�����}�b�v�i������b-----------------------------------------------------------------------
	else if (text_m == 0)
	{
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 520, 32, c);
		}
		else if (word == 1)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"���A�P�N�I", 108, 520, 25, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"�启�H�ǂ������񂾂���ȏ���", 108, 520, 25, c);
		}
		else if (word == 3)
		{
			d = 2;
			Font::StrDraw(L"���̕������낢�뒲�ׂĂ�̂�", 108, 520, 25, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"�������c�������ʂ͂��������H", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			d = 2;
			Font::StrDraw(L"����������Ȃ�������c", 108, 520, 25, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"�C�ɂ����", 108, 520, 25, c);
		}
		else if (word == 7)
		{
			Font::StrDraw(L"�����ꏏ�ɒT������", 108, 520,25, c);
		}
		else if (word == 8)
		{
			d = 2;
			Font::StrDraw(L"���肪�Ƃ�", 108, 520, 25, c);
		}
		else if (word == 9)
		{
			Font::StrDraw(L"���ꂶ�Ⴀ�Ƃ��ƂƎ�|���茩������I", 108, 520, 25, c);
		}
		else if (word == 10)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", 50, 520, 32, c);
		}
	}
	//����瓚�����͌�-----------------------------------------------------------------------
	else if(text_m==3)
	{
		if (word == 10)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 520, 32, c);
		}
		if (word== 11)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�启�I������������", 108, 520, 25, c);
		}
		else if (word == 12)
		{
			d = 2;
			Font::StrDraw(L"�ق�ƁH", 108, 520, 25, c);
		}
		else if (word == 13)
		{
			Font::StrDraw(L"���ǎ������������Ȃ�������", 108, 520, 25, c);
		}
		else if (word == 14)
		{
			d = 1;
			Font::StrDraw(L"����܂�C�ɂ���Ȃ�H", 108, 520, 25, c);
		}
		else if (word == 15)
		{
			d = 2;
			Font::StrDraw(L"�S�z�Ȃ���", 108, 520, 25, c);
		}
		else if (word == 16)
		{
			Font::StrDraw(L"���x�������������Ă�����", 108, 520, 25, c);
		}
		else if (word == 17)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�撣��̂͂������ǖ�������Ȃ�H", 108, 520, 25, c);
		}
		else if (word == 18)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���͈Ⴄ������T�����Ă����", 108, 520, 25, c);
		}
		else if (word == 19)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���͂�������������T�����Ă��", 108, 520, 25, c);
		}
		else if (word == 20)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�������ǋC�������", 108,520, 25, c);
		}
		else if (word == 21)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����������C�����Ȃ�����", 108, 520, 25, c);
		}
		else if (word == 22)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"���̕�����T���ɍs����", 50, 520, 32, c);
			text_loop = false;
		}
	}
	//�t���}�b�v
	//�i�����@word=0�`13
	//���擾���@word=13�`18
	//�t���}�b�v�i����-------------------------------------------------------------------------
	else if (text_m == 1)
	{
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 520, 32, c);
		}
		if (word == 1)
		{
			d = 1;
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�₯�ɕЕt������������", 108, 520, 25, c);
		}
		else if (word == 2)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���A�P����B�ǂ����������܂������H", 108, 520, 25, c);
		}
		else if (word == 3)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�ݖ삳�񂢂���ł���", 108, 520, 25, c);
		}
		else if (word == 4)
		{
			d = 3;
			
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����������܂�Ȃ��Ă����v�ł���B�����N�ł�����", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			g = 1;
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�킩�����B�ŁA�ݖ삳��͂ǂ�����", 108, 520, 25, c);
			Font::StrDraw(L"�͂����������Ă���񂾁H", 108, 545, 25, c);
		}
		else if (word == 6)
		{
			g = 2;
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�E�Ə㉘������������ƕЕt�������Ȃ��ł�", 108, 520, 25, c);
		}
		else if (word == 7)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���������Ⴀ��`����", 108, 520, 25, c);
		}
		else if (word == 8)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���H������ł����H", 108, 520, 25, c);
		}
		else if (word == 9)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����̕ЂÂ����Ȃ���T���΂�����", 108, 520, 25, c);
		}
		else if (word == 10)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�\���󂠂�܂���B�葁���I��点�܂��̂�", 108, 520, 25, c);
		}
		else if (word == 11)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���ꂶ�Ⴀ�n�߂悤��", 108, 520, 25, c);
		}
		else if (word == 12)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�͂��I", 108, 520, 25, c);
		}
		else if (word == 13)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", 50, 520, 32, c);
		}
	}
    //�������-----------------------------------------------------------------------
	else if (text_m == 4)
	{
		if (word == 13)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 520, 32, c);
		}
		else if (word == 14)
		{
			d = 1;
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�����̃�������", 108, 520, 25, c);
		}
		else if (word == 15)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�Ȃ�ł��傤��", 108, 520, 25, c);
		}
		else if (word == 16)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�Ƃ肠�������̕�����������ė����", 108, 520, 25, c);
		}
		else if (word == 17)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�킩��܂����B����l����낵�����肢���܂�", 108, 520, 25, c);
		}
		else if (word == 18)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"���̕�����T���ɍs����", 50, 520, 32, c);
			text_loop = false;
		}
	}
	//�i���}�b�v-----------------------------------------------------------------------
	//�i�����@word=0�`9
	//�����擾���@word=9�`19
	//�i���}�b�v�i����-------------------------------------------------------------------------
	else if (text_m == 2)
	{
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 520, 32, c);
		}
		else if (word == 1)
		{
			d = 4;
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�N�A�ǂ��������̂��ȁH", 108, 520, 25, c);
		}
		else if (word == 2)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�k���y�ł����B���̕����ɉ�������܂����H", 108, 520, 25, c);
		}
		else if (word == 3)
		{
			d = 4;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�܂����ɂ��������ĂȂ���", 108, 520, 25, c);
		}
		else if (word == 4)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�������I", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�T���̈ꏏ�Ɏ�`���Ă�", 108, 520, 25, c);
		}
		else if (word == 6)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�킩��܂����B���ł悯��Ύ�`���܂���", 108, 520, 25, c);
		}
		else if (word == 7)
		{
			d = 4;
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���肪�Ƃ��B", 108, 520, 25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���ꂶ���낵���I", 108, 520, 25, c);
		}
		else if (word == 9)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", 50, 520, 32, c);
		}
	}
	//�i���}�b�v������-------------------------------------------------------------------------
	else if (text_m == 5)
		{
			if (word == 9)
			{
				text_move = true;
				Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 520, 32, c);
			}
			else if (word == 10)
			{
				d = 4;
				g = 2;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"����͉����̃�������?", 108, 520, 25, c);
			}
			else if (word == 11)
			{
				d = 1;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�݂����ł���", 108, 520, 25, c);
			}
			else if (word == 12)
			{
				d = 4;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�����������瑼�ɂ��������邩������Ȃ���", 108, 520, 25, c);
			}
			else if (word == 13)
			{
				d = 1;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�ł��ˁB�����Ƃ��̕������ׂĂ݂܂��傤��", 108, 520, 25, c);
			}
			else if (word == 14)
			{
				d = 4;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�P�N�͑��̕����𒲂ׂɍs���Ă݂Ă�", 108, 520, 25, c);
			}
			else if (word == 15)
			{
				d = 1;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"���v�ł����H", 108, 520, 25, c);
			}
			else if (word == 16)
			{
				d = 4;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�l�͐��k��Ȃ񂾂�?���v����", 108, 520, 25, c);
			}
			else if (word == 17)
			{
				d = 1;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"�킩��܂����B��y���C��t����", 108, 520, 25, c);
			}
			else if (word == 18)
			{
				d = 4;
				Draw::Draw(52, &src, &dst, c, 0.0f);
			    Font::StrDraw(L"�C����", 108, 520, 25, c);
			}
			else if (word == 19)
			{
				d = 0;
				g = 3;
				text_move = false;
				Font::StrDraw(L"���̕�����T���ɍs����", 50, 520, 32, c);
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
		if (word == 0)
		{
			d = 1;
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"3�̃�������������݂�������", 108, 520, 25, c);
		}
		else if (word == 1)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"��������", 108, 520, 25, c);
		}
		else if (word == 2)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"����Ń����ɂ͂Ȃ�ď����Ă����ł���?", 108, 520, 25, c);
		}
		else if (word== 3)
		{
			g = 1;
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�u�~�X�~�\�E�v�u�C�t�F�C�I���v", 108, 520, 25, c);
			Font::StrDraw(L"�u�T�N���\�E�v����", 108, 545, 25, c);
		}
		else if (word == 4)
		{
			d = 2;
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�C�t�F�C�I���H", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�Ȃɂ悻��", 108, 520, 25, c);
		}
		else if (word == 6)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", 50, 520, 32, c);
		}
	}
	//�Q�K�w-----------------------------------------------------------------------
	else if (text_m == 7)
	{
		if (word == 6)
		{
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", 50, 520, 32, c);
		}
		else if (word == 7)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"��K�ɗ����̂͂������ǂ��ꂶ��o���Ȃ����H", 108, 520, 25, c);
		}
		if (word == 8)
		{
			g = 1;
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���̊K�ɉ�����|���肪����񂶂�Ȃ�����", 108, 520, 25, c);
			Font::StrDraw(L"����񂶂�Ȃ�����", 108, 545, 25, c);
		}
		else if (word == 9)
		{
			d = 4;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���ꂶ�Ⴑ�̕�����", 108, 520, 25, c);
			Font::StrDraw(L"������ĒT�������ł������ȁH", 108, 545, 25, c);
		}
		else if (word == 10)
		{
			d = 2;
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�Ȃ玄�͂������ɍs����I", 108, 520, 25, c);
		}
		else if (word == 11)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�t���͂������𒲂ׂȂ����I", 108, 520, 25, c);
		}
		else if (word == 12)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�������܂�܂���", 108, 520, 25, c);
		}
		else if (word == 13)
		{
			d = 4;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"���ꂶ�Ⴀ�l�͎c��̕����𒲂ׂ悤����", 108, 520, 25, c);
		}
		if (word == 14)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"(���͒N������`���ɍs�����j", 108, 520, 25, c);
		}
		if (word == 15)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�����������ŒT�����悤", 50, 520, 32, c);
			text_loop = false;
		}
	}
	if (d == 1)
	{
		Font::StrDraw(L"�P", 20, 485, 25, c);
		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (d == 2)
	{
		Font::StrDraw(L"�����", 20, 485, 25, c);
		Draw::Draw(50, &src, &dst, c, 0.0f);
	}
	else if (d == 3)
	{
		Font::StrDraw(L"�t��", 20, 485, 25, c);
		Draw::Draw(51, &src, &dst, c, 0.0f);
	}
	else if (d == 4)
	{
		Font::StrDraw(L"�i��", 20, 485, 25, c);
		Draw::Draw(52, &src, &dst, c, 0.0f);
	}
	//�e�L�X�g�ړ�
	if (time < 210&&g==0)
	{
		src_B.m_top = 30.0f;
		src_B.m_left = 110.0f + time*1.0f;
		src_B.m_right = 480.0f;
		src_B.m_bottom = 75.0f;
		dst_B.m_top = 510.0f;
		dst_B.m_left = 110.0f + time*3.0f;
		dst_B.m_right = 750.0f;
		dst_B.m_bottom =555.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
		//�e�L�X�g�\���B��(�����j�`��\���ʒu
		src_C.m_top = 75.0f;
		src_C.m_left = 0.0f ;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 555.0f;
		dst_C.m_left = 0.0f;
		dst_C.m_right = 800.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if(time==210 && g == 0)
	{
		time_x = 210;
	}
	if (time_x <= 210&&time_x>=0 && g == 0)
	{
		src_C.m_top = 75.0f;
		src_C.m_left = 110.0f + (210-time_x)*1.0f;
		src_C.m_right = 480.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 555.0f;
		dst_C.m_left = 110.0f + (210 - time_x)*3.0f;
		dst_C.m_right = 750.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if(g == 0)
	{

	}
	//�e�L�X�g�ړ�
	if (time < 180 && g == 1)
	{
		src_B.m_top = 30.0f;
		src_B.m_left = 110.0f + time*1.0f;
		src_B.m_right = 480.0f;
		src_B.m_bottom = 65.0f;
		dst_B.m_top = 510.0f;
		dst_B.m_left = 110.0f + time*3.0f;
		dst_B.m_right = 750.0f;
		dst_B.m_bottom = 545.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
		//�e�L�X�g�\���B��(�����j�`��\���ʒu
		src_C.m_top = 65.0f;
		src_C.m_left = 110.0f;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 545.0f;
		dst_C.m_left = 110.0f;
		dst_C.m_right = 800.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if (time == 180 && g == 1)
	{
		time_x = 210;
	}
	if (time_x <= 210 && time_x >= 0 && g == 1)
	{
		src_C.m_top = 65.0f;
		src_C.m_left = 105.0f + (210 - time_x)*1.0f;
		src_C.m_right = 480.0f;
		src_C.m_bottom = 120.0f;
		dst_C.m_top = 545.0f;
		dst_C.m_left = 105.0f + (210 - time_x)*3.0f;
		dst_C.m_right = 750.0f;
		dst_C.m_bottom = 600.0f;
		Draw::Draw(1, &src_C, &dst_C, c, 0.0f);
	}
	else if (g == 1)
	{

	}
	//�e�L�X�g�ړ�
	if (time < 200 && g == 2)
	{
		src_B.m_top = 30.0f;
		src_B.m_left = 70.4f + time*2.0f;
		src_B.m_right = 448.0f;
		src_B.m_bottom = 120.0f;
		dst_B.m_top = 510.0f;
		dst_B.m_left = 110.0f + time*3.0f;
		dst_B.m_right = 700.0f;
		dst_B.m_bottom = 600.0f;
		Draw::Draw(1, &src_B, &dst_B, c, 0.0f);
	}
	else if (g == 2)
	{

	}
	//���݈ʒu�\��
	if (text_m == -2 || text_m == -1||text_m==6)
	{
		Font::StrDraw(L"1F ����", 700, 493, 13, c);
	}
	else if (text_m ==-3|| text_m == 0 || text_m == 3  )
	{
		Font::StrDraw(L"1F ����", 700, 493, 13, c);
	}
	else if (text_m == -4 || text_m == 1 || text_m == 4)
	{
		Font::StrDraw(L"1F �}����", 700, 493, 13, c);
	}
	else if (text_m == -5 || text_m == 2 || text_m == 5)
	{
		Font::StrDraw(L"1F �a��", 700, 493, 13, c);
	}
	else if (text_m == 7)
	{
		Font::StrDraw(L"2F", 700, 493, 13, c);
	}
	//�Ó]
	if (text_m == -1 && word == 0 || text_m == -1 && word == 1 || text_m == -1 && word == 2)
	{
		Draw::Draw(12, &src_A, &dst_A, c, 0.0f);
	}
}