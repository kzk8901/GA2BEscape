//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include"text.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

bool text_hide = false;//�e�L�X�g�B���\���m�F�p
bool hero_move=false;//�q�[���[�̓���m�F�p
bool text_move=true;//�e�L�X�g�̓���m�F�p
int anime_move = 0;//�A�j���\�V�����ԍ�
int word=0;//�e�L�X�g�ԍ�
bool skip_anime = false;//�A�j���[�V�������e�L�X�g��i�߂Ȃ�����t���O
int item_word = 0;
//�C�j�V�����C�Y
void CObjText::Init()
{
	m_key_flag = false;
	skip_flag = false;
	time = 230;
	time_x = -1;
	anime_flag = false;
	g = 1;
	d = 0;
	f = false;
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
						if (skip_anime == false)
						{
							if (time > 210)
							{
								if (text_m == 0 && word < 10 || text_m == 3 && word < 23 ||
									text_m == 1 && word < 13 || text_m == 2 && word < 9  || text_m == -1 && word < 54 ||
									text_m == 5 && word < 20 || text_m == 4 && word < 19 || text_m == 7 && word < 9 ||
									text_m == 6 && word < 7)
								{
									word += 1;
									m_key_flag = false;
									time = 0;
									skip_flag = true;
								}
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
	float c[4] = { 0.3f,0.3f,0.3f,1.0f };
	float c_C[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c_A[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c_D[4] = { 1.0f,1.0f,1.0f,1.0f };
	int x = 180;//�e�L�X�g�px��
	int y_a = 500;//�e�L�X�g�㕔�py��
	int y_b = 550;//�e�L�X�g�����py��
	int m_z = 25;//�e�L�X�g�傫��
	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`��\���ʒu
	RECT_F src_A; //�Ó]���؂���ʒu
	RECT_F dst_A; //�Ó]�`��\���ʒu
	RECT_F src_B;//�e�L�X�g�\���B��(�㕔�j�`�挳�؂���ʒu
	RECT_F dst_B;//�e�L�X�g�\���B��(�㕔�j�`��\���ʒu
	RECT_F src_C;//�e�L�X�g�\���B��(�����j�`�挳�؂���ʒu
	RECT_F dst_C;//�e�L�X�g�\���B��(�����j�`��\���ʒu
	RECT_F src_D;//���Ó]�`�挳�؂���ʒu
	RECT_F dst_D;//���Ó]�`��\���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 465.0f;
	src.m_bottom = 463.0f;
	dst.m_top = 490.0f;
	dst.m_left = 10.0f;
	dst.m_right = 95.0f;
	dst.m_bottom = 560.0f;
	src_A.m_top = 0.0f;
	src_A.m_left = 0.0f;
	src_A.m_right = 32.0f;
	src_A.m_bottom = 32.0f;
	dst_A.m_top = 0.0f;
	dst_A.m_left = 0.0f;
	dst_A.m_right = 640.0f;
	dst_A.m_bottom = 480.0f;
	src_D.m_top = 0.0f;
	src_D.m_left = 0.0f;
	src_D.m_right = 32.0f;
	src_D.m_bottom = 32.0f;
	dst_D.m_top = 384.0f;
	dst_D.m_left = 192.0f;
	dst_D.m_right = 448.0f;
	dst_D.m_bottom = 480.0f;
	Font::StrDraw(L"�\���L�[�F�ړ�", 650, 370, 15, c_C);
	Font::StrDraw(L"Z�L�[�F", 650, 390, 15, c_C);
	Font::StrDraw(L"����E��b�i�s", 650, 410, 15, c_C);
	Font::StrDraw(L"�e���L�[�F", 650, 430, 15, c_C);
	Font::StrDraw(L"����A�C�e���ڍ�", 650, 450, 15, c_C);

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
			m_z = 30;
			Font::StrDraw(L"�启�����̓��C�h�̊ݖ�t����", x, y_a, m_z, c);
			Font::StrDraw(L"���Z���Ă���ƓˑR�J���~���Ă���", x, y_b, m_z, c);
		}
		else if (word == 2)
		{
			m_z = 30;
			Font::StrDraw(L"��l�͂��܂��܋߂��ɂ������ق�", x, y_a, m_z, c);
			Font::StrDraw(L"�J�h�肷�邱�Ƃɂ����̂ł�����", x, y_b, m_z, c);
		}
		else if (word == 3)
		{
			m_z = 25;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 2;
			g = 2;
			Font::StrDraw(L"�˂��t���c�J����ނ��ȁH", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			c_A[3] = 1.0f;
			d = 3;
			Font::StrDraw(L"���̊������Ƃ�����ނƎv���܂���", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			c_D[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_D, &dst_D, c_D, 0.0f);
			skip_anime = true;
			anime_move = 1;
			d = 1;
			Font::StrDraw(L"�����Ȃ�J�h��ł��������ȁc", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 2;
			Font::StrDraw(L"�N!?", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 1;
			Font::StrDraw(L"��q�������̂�", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			Font::StrDraw(L"���̖��O�͖P����B�N�Ɠ����w�Z�̓�N��", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			d = 2;
			Font::StrDraw(L"���A�Z���p�C�ł����H", x, y_a, m_z, c);
		}
		else if (word == 10)
		{
			Font::StrDraw(L"���͑启������", x, y_a, m_z, c);
		}
		else if (word == 11)
		{
			Font::StrDraw(L"�^�����ʂ�J�ɍ~���}築J�h�肵�Ă��", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			d = 1;
			Font::StrDraw(L"���݂��Г��", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			d = 2;
			Font::StrDraw(L"�������͎��̃��C�h�̊ݖ�t����", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			d = 3;
			Font::StrDraw(L"�ݖ�t���ł��B", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			Font::StrDraw(L"�����l�̃��C�h�ł�", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			anime_move = 2;
			d = 4;
			Font::StrDraw(L"�l�������ς������", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			f = false;
			d = 1;
			Font::StrDraw(L"�m�����Ȃ��́c", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 3;
			Font::StrDraw(L"���k��̖k��i������ł���", x, y_a, m_z, c);
		}
		else if (word == 19)
		{
			d = 4;
			Font::StrDraw(L"��������", x, y_a, m_z, c);
		}
		else if (word == 20)
		{
			d = 4;
			Font::StrDraw(L"�N�͑勴����Ƃ̃��C�h���񂾂�", x, y_a, m_z, c);
		}
		else if (word == 21)
		{
			d = 3;
			Font::StrDraw(L"�ݖ�t���ł�", x, y_a, m_z, c);
		}
		else if (word == 22)
		{
			d = 1;
			Font::StrDraw(L"���A�J��ݎn�߂Ă܂���", x, y_a, m_z, c);
		}
		else if (word == 23)
		{
			d = 2;
			Font::StrDraw(L"�t��!�Ƃ��ƂƋA����I", x, y_a, m_z, c);
		}
		else if (word == 24)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"�������܂�܂����B����ł͎��炵�܂�", x, y_a, m_z, c);
		}
		else if (word == 25)
		{
			skip_anime = true;
			anime_move = 3;
			d = 1;
			g = 2;
			Font::StrDraw(L"�����A�낤", x, y_a, m_z, c);
		}
		else if (word == 26)
		{
			d = 4;
			Font::StrDraw(L"�l���A��Ȃ���", x, y_a, m_z, c);
		}
		else if (word == 27)
		{
			d = 1;
			Font::StrDraw(L"��H", x, y_a, m_z, c);
		}
		else if (word == 28)
		{
			Font::StrDraw(L"�h�A���J���Ȃ���", x, y_a, m_z, c);
		}
		else if (word == 29)
		{
			d = 2;
			Font::StrDraw(L"����Ȃ킯�Ȃ��ł���", x, y_a, m_z, c);
		}
		else if (word == 30)
		{
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			anime_move = 4;
			d = 3;
			Font::StrDraw(L"���炵�܂�", x, y_a, m_z, c);
		}
		else if (word == 31)
		{
			f = false;
			Font::StrDraw(L"�J���܂����", x, y_a, m_z, c);
		}
		else if (word == 32)
		{
			d = 4;
			Font::StrDraw(L"�{�������H", x, y_a, m_z, c);
		}
		else if (word == 33)
		{
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			anime_move = 5;
			d = 1;
			Font::StrDraw(L"���āA�ǂ��������̂�", x, y_a, m_z, c);
		}
		else if (word == 34)
		{
			f = false;
			d = 2;
			Font::StrDraw(L"�������̃h�A�͊J�����", x, y_a, m_z, c);
		}
		else if (word == 35)
		{
			d = 1;
			Font::StrDraw(L"�Ȃ炻������T�����邩�H", x, y_a, m_z, c);
		}
		else if (word == 36)
		{
			d = 3;
			Font::StrDraw(L"���܂肨���߂͂��܂����", x, y_a, m_z, c);
		}
		else if (word == 37)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"���Ԃ����ĂΉ䂪�Ƃ̋~���`�[����", x, y_a, m_z, c);
			Font::StrDraw(L"�삯�t���܂��̂ł��΂����҂���������", x, y_b, m_z, c);
		}
		else if (word == 38)
		{
			d = 4;
			Font::StrDraw(L"�ł��A����ȋ@��ő��ɂȂ���", x, y_a, m_z, c);
			Font::StrDraw(L"�l�͒T���Ɏ^������", x, y_b, m_z, c);
		}
		else if (word == 39)
		{
			g = 2;
			d = 2;
			Font::StrDraw(L"�����T����������", x, y_a, m_z, c);
		}
		else if (word == 40)
		{
			Font::StrDraw(L"�t���A�~���`�[���̎�z�͑҂��Ȃ���", x, y_a, m_z, c);
		}
		else if (word == 41)
		{
			d = 3;
			Font::StrDraw(L"�������c", x, y_a, m_z, c);
		}
		else if (word == 42)
		{
			d = 2;
			Font::StrDraw(L"�t���I", x, y_a, m_z, c);
		}
		else if (word == 43)
		{
			d = 3;
			Font::StrDraw(L"�������܂�܂���", x, y_a, m_z, c);
		}
		else if (word == 44)
		{
			g = 1;
			Font::StrDraw(L"�ł����玄���܂�", x, y_a, m_z, c);
			Font::StrDraw(L"�S�����̈��S���m���߂܂�", x, y_b, m_z, c);
		}
		else if (word == 45)
		{
			Font::StrDraw(L"���̌�F�����", x, y_a, m_z, c);
			Font::StrDraw(L"�T�����Ă��炤�Ƃ������ƂŁc", x, y_b, m_z, c);
		}
		else if (word == 46)
		{
			g = 2;
			d = 2;
			Font::StrDraw(L"����Ȃ��Ƃ������΋����Ȃ�����ˁH", x, y_a, m_z, c);
		}
		else if (word == 47)
		{
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			anime_move = 6;
			g = 1;
			d = 3;
			Font::StrDraw(L"�ł����琳�ʂ̕�����", x, y_a, m_z, c);
			Font::StrDraw(L"�T���Ȃ��낵���ł��傤�H", x, y_b, m_z, c);
		}
		else if (word == 48)
		{
			g = 2;
			f = false;
			d = 2;
			Font::StrDraw(L"����Ȃ炢����", x, y_a, m_z, c);
		}
		else if (word == 49)
		{
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			anime_move = 7;
			d = 4;
			Font::StrDraw(L"���ꂶ�Ⴀ�l�͂������̕�����T�������", x, y_a, m_z, c);
		}
		else if (word == 50)
		{
			f = false;
			d = 2;
			g = 2;
			Font::StrDraw(L"���肢���܂��ː�y", x, y_a, m_z, c);
		}
		else if (word == 51)
		{
			d = 4;
			Font::StrDraw(L"��̊ق̒T���̊J�n���[�I", x, y_a, m_z, c);
		}
		else if (word == 52)
		{
			d = 2;
			Font::StrDraw(L"���[�I", x, y_a, m_z, c);
		}
		else if (word == 53)
		{
			d = 1;
			Font::StrDraw(L"���A���[�c", x, y_a, m_z, c);
		}
		else if (word == 54 && item_word == 0)
		{
			hero_move = true;
			anime_move = 8;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�����������ŒT�����悤", x, y_a, 32, c);
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
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"���A�P�N�I", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"�启�H�ǂ������񂾂���ȏ���", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 2;
			Font::StrDraw(L"���̕������낢�뒲�ׂĂ�̂�", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"�������c�������ʂ͂��������H", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 2;
			Font::StrDraw(L"����������Ȃ�������c", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"�C�ɂ����", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			Font::StrDraw(L"�����ꏏ�ɒT������", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 2;
			Font::StrDraw(L"���肪�Ƃ�", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			Font::StrDraw(L"���ꂶ�Ⴀ�Ƃ��ƂƎ�|���茩������I", x, y_a, m_z, c);
		}
		else if (word == 10 && text_hide == false && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", x, y_a, 32, c);
		}
	}
	//����瓚�����͌�-----------------------------------------------------------------------
	else if (text_m == 3)
	{
		if (word == 11)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		if (word == 12)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�启�I������������", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			anime_move = 9;
			d = 2;
			Font::StrDraw(L"�ق�ƁH", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			f - false;
			Font::StrDraw(L"���ǎ������������Ȃ�������", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			d = 1;
			Font::StrDraw(L"����܂�C�ɂ���Ȃ�H", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 2;
			Font::StrDraw(L"�S�z�Ȃ���", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			Font::StrDraw(L"���x�������������Ă�����", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 1;
			Font::StrDraw(L"�撣��̂͂������ǖ�������Ȃ�H", x, y_a, m_z, c);
		}
		else if (word == 19)
		{
			Font::StrDraw(L"���͈Ⴄ������T�����Ă����", x, y_a, m_z, c);
		}
		else if (word == 20)
		{
			d = 2;
			Font::StrDraw(L"���͂�������������T�����Ă��", x, y_a, m_z, c);
		}
		else if (word == 21)
		{
			d = 1;
			Font::StrDraw(L"�������ǋC�������", x, y_a, m_z, c);
		}
		else if (word == 22)
		{
			d = 2;
			Font::StrDraw(L"�����������C�����Ȃ�����", x, y_a, m_z, c);
		}
		else if (word == 23 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"���̕�����T���ɍs����", x, y_a, 32, c);
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
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		if (word == 1)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�₯�ɕЕt������������", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 3;
			Font::StrDraw(L"���A�P����B�ǂ����������܂������H", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 1;
			Font::StrDraw(L"�ݖ삳�񂢂���ł���", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"�����������܂�Ȃ��Ă����v�ł���B", x, y_a, m_z, c);
			Font::StrDraw(L"�����N�ł�����", x, y_b, m_z, c);
		}
		else if (word == 5)
		{
			d = 1;
			Font::StrDraw(L"�킩�����B�ŁA�ݖ삳��͂ǂ�����", x, y_a, m_z, c);
			Font::StrDraw(L"�͂����������Ă���񂾁H", x, y_b, m_z, c);
		}
		else if (word == 6)
		{
			g = 2;
			d = 3;
			Font::StrDraw(L"�E�Ə㉘������������ƕЕt�������Ȃ��ł�", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 1;
			Font::StrDraw(L"���������Ⴀ��`����", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 3;
			Font::StrDraw(L"���H������ł����H", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			d = 1;
			Font::StrDraw(L"�����̕ЂÂ����Ȃ���T���΂�����", x, y_a, m_z, c);
		}
		else if (word == 10)
		{
			d = 3;
			Font::StrDraw(L"�\���󂠂�܂���B�葁���I��点�܂��̂�", x, y_a, m_z, c);
		}
		else if (word == 11)
		{
			d = 1;
			Font::StrDraw(L"���ꂶ�Ⴀ�n�߂悤��", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			d = 3;
			Font::StrDraw(L"�͂��I", x, y_a, m_z, c);
		}
		else if (word == 13&&item_word==0)
		{
			d = 0;
			g = 3;
			hero_move = true;
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", x, y_a, 32, c);
		}
	}
	//�������-----------------------------------------------------------------------
	else if (text_m == 4)
	{
		if (word == 14)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 15)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�����̃�������", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 3;
			Font::StrDraw(L"�Ȃ�ł��傤��", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			d = 1;
			Font::StrDraw(L"�Ƃ肠�������̕�����������ė����", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 3;
			Font::StrDraw(L"�킩��܂����B����l����낵�����肢���܂�", x, y_a, m_z, c);
		}
		else if (word == 19 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"���̕�����T���ɍs����", x, y_a, 32, c);
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
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 4;
			g = 2;
			Font::StrDraw(L"�N�A�ǂ��������̂��ȁH", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"�k���y�ł����B���̕����ɉ�������܂����H", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 4;
			Font::StrDraw(L"�܂����ɂ��������ĂȂ���", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			Font::StrDraw(L"�������I", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			Font::StrDraw(L"�T���̈ꏏ�Ɏ�`���Ă�", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"�킩��܂����B���ł悯��Ύ�`���܂���", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 4;
			g = 2;
			Font::StrDraw(L"���肪�Ƃ��B", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			Font::StrDraw(L"���ꂶ���낵���I", x, y_a, m_z, c);
		}
		else if (word == 9 && text_hide == false && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�T�����悤�I", x, y_a, 32, c);
		}
	}
	//�i���}�b�v������-------------------------------------------------------------------------
	else if (text_m == 5)
	{
		if (word == 10)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 11)
		{
			d = 4;
			g = 2;
			Font::StrDraw(L"����͉����̃�������?", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			d = 1;
			Font::StrDraw(L"�݂����ł���", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			d = 4;
			Font::StrDraw(L"�����������瑼�ɂ��������邩������Ȃ���", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			d = 1;
			Font::StrDraw(L"�ł��ˁB�����Ƃ��̕������ׂĂ݂܂��傤��", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			d = 4;
			Font::StrDraw(L"�P�N�͑��̕����𒲂ׂɍs���Ă݂Ă�", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 1;
			Font::StrDraw(L"���v�ł����H", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			d = 4;
			Font::StrDraw(L"�l�͐��k��Ȃ񂾂�?���v����", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 1;
			Font::StrDraw(L"�킩��܂����B��y���C��t����", x, y_a, m_z, c);
		}
		else if (word == 19)
		{
			d = 4;
			Font::StrDraw(L"�C����", x, y_a, m_z, c);
		}
		else if (word == 20 && item_word == 0)
		{
			d = 0;
			g = 3;
			text_move = false;
			hero_move = true;
			Font::StrDraw(L"���̕�����T���ɍs����", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//����
	//�P�K�w-----------------------------------------------------------------------
	else if (text_m == 6)
	{
		if (word == 0)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 1;
			g = 2;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			Font::StrDraw(L"3�̃�������������݂�������", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			c_A[3] = 1.0;
			d = 2;
			Font::StrDraw(L"��������", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 3;
			Font::StrDraw(L"����Ń����ɂ͂Ȃ�ď����Ă����ł���?", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			g = 1;
			d = 1;
			Font::StrDraw(L"�u�~�X�~�\�E�v�u�C�t�F�C�I���v", x, y_a, m_z, c);
			Font::StrDraw(L"�u�T�N���\�E�v����", x, y_b, m_z, c);
		}
		else if (word == 5)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"�C�t�F�C�I���H", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 2;
			Font::StrDraw(L"�Ȃɂ悻��", x, y_a, m_z, c);
		}
		else if (word == 7 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�T�����I", x, y_a, 32, c);
		}
	}
	//�Q�K�w-----------------------------------------------------------------------
	else if (text_m == 7)
	{
		if (word == 0)
		{
			anime_move = 0;
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			g = 1;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 2;
			Font::StrDraw(L"��K�ɗ����̂͂�������", x, y_a, m_z, c);
			Font::StrDraw(L"���ꂶ��o���Ȃ����H", x, y_b, m_z, c);
		}
		if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"���̊K�ɉ�����|���肪", x, y_a, m_z, c);
			Font::StrDraw(L"����񂶂�Ȃ�����", x, y_b, m_z, c);
		}
		else if (word == 3)
		{
			d = 4;
			Font::StrDraw(L"���ꂶ�Ⴑ�̕�����", x, y_a, m_z, c);
			Font::StrDraw(L"������ĒT�������ł������ȁH", x, y_b, m_z, c);
		}
		else if (word == 4)
		{
			anime_move = 1;
			d = 2;
			g = 2;
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			Font::StrDraw(L"�Ȃ玄�͂������ɍs����I", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			f = false;
			Font::StrDraw(L"�t���͂������𒲂ׂȂ����I", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			anime_move = 2;
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			d = 3;
			Font::StrDraw(L"�������܂�܂���", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			if (anime_flag == false)
			{
				f = false;
				anime_flag = true;
			}
			anime_move = 3;
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			d = 4;
			Font::StrDraw(L"���ꂶ�Ⴀ�l�͎c��̕����𒲂ׂ悤����", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			f = false;
			anime_move = 4;
			d = 1;
			Font::StrDraw(L"(���͒N������`���ɍs�����j", x, y_a, m_z, c);
		}
		else if (word ==9 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�����������ŒT�����悤", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//2�K�w����畔��-------------------------------------------------

	//

	//2�K�w�t������-------------------------------------------------
	else if (text_m == 10)
	{
		if (word == 0)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 3;
			g = 2;
			Font::StrDraw(L"�����̕������Еt������������܂���", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"�ݖ삳�񉴂���`����", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 3;
			Font::StrDraw(L"�P�N�ǂ����Ă����ɁH", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"�ݖ삳�����`�����Ǝv����", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"���Ƃ��Ă͂��肪�����̂ł���", x, y_a, m_z, c);
			Font::StrDraw(L"�����̂ł����H", x, y_b, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"�ʂɕ����͎O�����Ȃ������񂾂���", x, y_a, m_z, c);
			Font::StrDraw(L"�N���̎�`���͊m�肾������", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			Font::StrDraw(L"�Ȃ�Еt�����n�߂�����", x, y_a, m_z, c);
			Font::StrDraw(L"�ݖ삳�����`�����Ƃɂ�����������", x, y_b, m_z, c);
		}
		else if (word == 8)
		{
			d = 3;
			g = 2;
			Font::StrDraw(L"���肪�Ƃ��������܂�", x, y_a, m_z, c);
		}
		else if(word==9)
		{
			g = 1;
			Font::StrDraw(L"����Ȃ炨��l��҂����Ă������܂���", x, y_a, m_z, c);
			Font::StrDraw(L"�葁������Ă��܂��܂��傤", x, y_b, m_z, c);
		}
		else if (word == 10)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�킩����", x, y_a, m_z, c);
		}
		else if (word == 11 && item_word == 0)
		{

			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"�������悤�I", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//��������q�ɔ�-----------------------------------------------
	//�q�ɔԏI����-------------------------------------------------
	if (text_m == 11)
	{
		if (word == 0)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�����̐�����������", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"�����₯�ɑ����Ǝv������", x, y_a, m_z, c);
			Font::StrDraw(L"�������u�����݂����ł���", x, y_b, m_z, c);
		}
		else if (word == 3)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�Ƃ���ŉ��̂ق��Ō�����������", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 3;
			Font::StrDraw(L"�{���ł����H", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			g = 1;
			Font::StrDraw(L"����Ȃ炨��l������", x, y_a, m_z, c);
			Font::StrDraw(L"�W�߂đ����A��܂��傤", x, y_b, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"�Ȃ牴����ɖ{�������ׂĂ��邩��", x, y_a, m_z, c);
			Font::StrDraw(L"�ݖ삳��݂͂�Ȃ��Ă�ł����Ă���Ȃ���?", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			d = 3;
			g = 2;
			Font::StrDraw(L"�킩��܂���", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			Font::StrDraw(L"�����̕��͂��肢���܂���", x, y_a, m_z, c);
		}
		else if (word == 9 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"1�K���ւɌ��������I", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//2�K�w�i������-------------------------------------------------
	
	//

	//�G���f�B���O�@�����-------------------------------------------

	//�G���f�B���O�@�t��---------------------------------------------
	if (text_m == 15)
	{
		if (word == 0)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Z�L�[�ŉ�b�i�s", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 3;
			g = 2;
			Font::StrDraw(L"�P�N", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"�ǂ�������?", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 3;
			Font::StrDraw(L"���������̎����ɂȂ�܂���?", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"�ǂ�������?", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 3;
			Font::StrDraw(L"���������̎����ɂȂ�܂���?", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"�}�ɂǂ�������?", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"�������Ɏ��������Ȃ��̂�", x, y_a, m_z, c);
			Font::StrDraw(L"�P�N�̎�ۂ̗ǂ����l���������ʂł���", x, y_b, m_z, c);
		}
		else if (word == 8)
		{
			d = 2;
			Font::StrDraw(L"�܂����񌮂��������͖̂P�N�炵����", x, y_a, m_z, c);
			Font::StrDraw(L"�t�����I�񂾂̂Ȃ�ʂɍ\��Ȃ���", x, y_b, m_z, c);
		}
		else if (word == 9)
		{
			d = 3;
			Font::StrDraw(L"�c�ꏏ�ɂ��d���ł���Ȃ�", x, y_a, m_z, c);
			Font::StrDraw(L"�������ꂵ���ł�����", x, y_b, m_z, c);
		}
		else if (word == 10)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"�ݖ삳��ǂ�������?", x, y_a, m_z, c);
		}
		else if (word == 11)
		{
			d = 3;
			Font::StrDraw(L"�������ł�����܂���", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			Font::StrDraw(L"�Ԏ��͌���Ō��\�ł�", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			Font::StrDraw(L"�����Ԏ������҂��Ă��܂�", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			Font::StrDraw(L"����ł͂���l�A��܂��傤", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			d = 2;
			Font::StrDraw(L"�t���̋@�����������ǉ�����������?", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 1;
			Font::StrDraw(L"����?", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			d = 2;
			Font::StrDraw(L"�A��܂��傤��", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 1;
			Font::StrDraw(L"��������", x, y_a, m_z, c);
		}
	}
	//�G���f�B���O�@�i��---------------------------------------------

	//�G���h���[��---------------------------------------------------

	//���O��---------------------------------------------------------
	if (d == 1)
	{
		if (text_m == -1 && word == 5 || text_m == -1 && word == 7 || text_m == -1 && word == 8)
		{
			Font::StrDraw(L"???", 30, 560, 25, c);
		}
		else
		{
			Font::StrDraw(L"�P", 39, 560, 20, c);
		}
		Draw::Draw(4, &src, &dst, c_C, 0.0f);
	}
	else if (d == 2)
	{
		Font::StrDraw(L"�����", 20, 560, 20, c);
		Draw::Draw(50, &src, &dst, c_C, 0.0f);
	}
	else if (d == 3)
	{
		Font::StrDraw(L"�t��", 30, 560, 20, c);
		Draw::Draw(51, &src, &dst, c_C, 0.0f);
	}
	else if (d == 4)
	{
		if (text_m == -1 && word == 16)
		{
			Font::StrDraw(L"???", 30, 560, 25, c);
		}
		else
		{
			Font::StrDraw(L"�i��", 30, 560, 20, c);
		}
		Draw::Draw(52, &src, &dst, c_C, 0.0f);
	}
	//�����ׂ����W
	//��̒I
	if (item_word == 1)
	{
		Font::StrDraw(L"��������̖{�����[����Ă���", x, y_a, m_z, c);
	}
	//�Ԃ̖{�������Ă���{�I
	else if (item_word == 2)
	{
		Font::StrDraw(L"�Ԃ̖{�����[����Ă���", x, y_a, m_z, c);
	}
	//��
	else if (item_word == 3)
	{
		Font::StrDraw(L"�������Ț₪����", x, y_a, m_z, c);
	}
	//�ϗt�A��
	else if (item_word == 4)
	{
		Font::StrDraw(L"�ϗt�A�����u���Ă���", x, y_a, m_z, c);
	}
	//��̃^���X
	else if (item_word == 5)
	{
		Font::StrDraw(L"���ɉ��������ĂȂ��悤��", x, y_a, m_z, c);
	}
	else if (item_word == 6)
	{
		Font::StrDraw(L"2�i�̃^���X�̂悤��", x, y_a, m_z, c);
	}

	//�e�L�X�g�ړ�2�s�p
	if (time < 210 && g == 1)
	{
		src_B.m_top = 30.0f;
		src_B.m_left = 200.0f + time*1.0f;
		src_B.m_right = 480.0f;
		src_B.m_bottom = 80.0f;
		dst_B.m_top = 490.0f;
		dst_B.m_left = 170.0f + time*3.0f;
		dst_B.m_right = 750.0f;
		dst_B.m_bottom = 540.0f;
		Draw::Draw(1, &src_B, &dst_B, c_C, 0.0f);
		//�e�L�X�g�\���B��(�����j�`��\���ʒu
		src_C.m_top = 80.0f;
		src_C.m_left = 200.0f;
		src_C.m_right = 512.0f;
		src_C.m_bottom = 130.0f;
		dst_C.m_top = 540.0f;
		dst_C.m_left = 170.0f;
		dst_C.m_right = 800.0f;
		dst_C.m_bottom = 590.0f;
		Draw::Draw(1, &src_C, &dst_C, c_C, 0.0f);
	}
	else if (time == 210 && g == 1)
	{
		time_x = 210;
	}
	if (time_x <= 210 && time_x >= 0 && g == 1)
	{
		src_C.m_top = 80.0f;
		src_C.m_left = 110.0f + (210 - time_x)*1.0f;
		src_C.m_right = 480.0f;
		src_C.m_bottom = 130.0f;
		dst_C.m_top = 540.0f;
		dst_C.m_left = 170.0f + (210 - time_x)*3.0f;
		dst_C.m_right = 750.0f;
		dst_C.m_bottom = 590.0f;
		Draw::Draw(1, &src_C, &dst_C, c_C, 0.0f);
	}
	else if (g == 1)
	{

	}
	//�e�L�X�g�ړ�1�s�p
	if (time < 200 && g == 2)
	{
		src_B.m_top = 30.0f;
		src_B.m_left = 200.0f + time*2.0f;
		src_B.m_right = 480.0f;
		src_B.m_bottom = 130.0f;
		dst_B.m_top = 490.0f;
		dst_B.m_left = 170.0f + time*3.0f;
		dst_B.m_right = 750.0f;
		dst_B.m_bottom = 590.0f;
		Draw::Draw(1, &src_B, &dst_B, c_C, 0.0f);
	}
	else if (g == 2)
	{

	}
	//���݈ʒu�\��
	if (text_m == -2 || text_m == -1 || text_m == 6)
	{
		Font::StrDraw(L"1F", 730, 503, 30, c);
		Font::StrDraw(L"����", 700, 553, 30, c);
	}
	else if (text_m == -3 || text_m == 0 || text_m == 3)
	{
		Font::StrDraw(L"1F", 730, 503, 30, c);
		Font::StrDraw(L"����", 700, 553, 30, c);
	}
	else if (text_m == -4 || text_m == 1 || text_m == 4)
	{
		Font::StrDraw(L"1F", 730, 503, 30, c);
		Font::StrDraw(L"�}����", 700, 553, 30, c);
	}
	else if (text_m == -5 || text_m == 2 || text_m == 5)
	{
		Font::StrDraw(L"1F", 730, 503, 30, c);
		Font::StrDraw(L"�a��", 700, 553, 30, c);
	}
	else if (text_m == 7)
	{
		Font::StrDraw(L"2F", 730, 503, 30, c);
	}
	//�Ó]
	if (text_m == -1 && word == 0 || text_m == -1 && word == 1 || text_m == -1 && word == 2||text_m == 6 && word == 0 || text_m == 7 && word == 0)
	{
		Draw::Draw(12, &src_A, &dst_A, c, 0.0f);
		Draw::Draw(12, &src_D, &dst_D, c, 0.0f);
	}
	else if (text_m == -1 && word == 3 || text_m == -1 && word == 4)
	{
		Draw::Draw(12, &src_D, &dst_D, c, 0.0f);
	}

}