//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"text.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjText::Init()
{
	m_key_flag = false;
	word = 0;
	time = 120;
	x = 0;
	y = 0;
}

//�A�N�V����
void CObjText::Action()
{
	time += 1;
	if (Input::GetVKey('A') == true)
	{
		if (m_key_flag == true)
		{
			if (time > 120)
			{
				word += 1;
				m_key_flag = false;
				time = 0;
			}
		}
		else
		{
			m_key_flag = true;
		}
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


	if (word == 1)
	{
		if (time < 100)
		{
			//�w�i�\��
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 590.0f - time;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 690.0f - time;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�n�@�C�@�W���[�W�B", 108, 590 - time, 16, c);
		}
		else
		{
			//�w�i�\��
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�n�@�C�@�W���[�W�B", 108, 490, 16, c);
		}
	}
	else if (word == 2)
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
			Font::StrDraw(L"�y�j�[���C�Y�F�J�v�e�e�tGX����2�������Ă�H", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F�J�v�e�e�tGX����2�������Ă�H", 108, 490, 16, c);
		}
	}
	else if (word == 3)
	{
		if (time < 100 && time > 80)
		{
			x += 1;
			//�w�i�\��
			src.m_top = 0.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f + x;
			dst.m_right = 106.0f + x;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�i��U��j", 108, 590 - time, 16, c);
		}
		else if (time <= 80 && time > 40)
		{
			x -= 1;
			src.m_top = 0.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f + x;
			dst.m_right = 106.0f + x;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�i��U��j", 108, 590 - time, 16, c);
		}
		else if (time <= 40 && time > 1)
		{
			x += 1;
			//�w�i�\��
			src.m_top = 0.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f + x;
			dst.m_right = 106.0f + x;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�i��U��j", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�W���[�W�F�i��U��j", 108, 490, 16, c);
		}
	}
	else if (word == 4)
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
			Font::StrDraw(L"�y�j�[���C�Y�F���[�@�����̂ɁH", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F���[�@�����̂ɁH", 108, 490, 16, c);
		}
	}
	else if (word == 5)
	{
		if (time < 100)
		{
			src.m_top = 0.0f;
			src.m_left = 255.0f;
			src.m_right = 319.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�����H", 108, 590 - time, 16, c);
		}
		else
		{

			src.m_top = 0.0f;
			src.m_left = 255.0f;
			src.m_right = 319.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�����H", 108, 490, 16, c);
		}
	}
	else if (word == 6)
	{
		if (time < 100)
		{
			src.m_top = 0.0f;
			src.m_left = 319.0f;
			src.m_right = 383.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�ǂ���5000�~�����ł���H", 108, 590 - time, 16, c);
		}
		else
		{

			src.m_top = 0.0f;
			src.m_left = 319.0f;
			src.m_right = 383.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�ǂ���5000�~�����ł���H", 108, 490, 16, c);
		}
	}
	else if (word == 7)
	{
		if (time < 100)
		{
			src.m_top = 0.0f;
			src.m_left = 319.0f;
			src.m_right = 383.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�x�����", 108, 590 - time, 16, c);
		}
		else
		{

			src.m_top = 0.0f;
			src.m_left = 319.0f;
			src.m_right = 383.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�x�����", 108, 490, 16, c);
		}
	}
	else if (word == 8)
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
			Font::StrDraw(L"�y�j�[���C�Y�F�m���ɍ���5000�~���邪", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F�m���ɍ���5000�~���邪", 108, 490, 16, c);
		}
	}
	else if (word == 9)
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
			Font::StrDraw(L"�y�j�[���C�Y�F11��2�������̃E���g���V���C�j�[�ōĘ^������", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F11��2�������̃E���g���V���C�j�[�ōĘ^������", 108, 490, 16, c);
		}
	}
	else if (word == 10)
	{
		if (time < 100)
		{
			src.m_top = 0.0f;
			src.m_left = 447.0f;
			src.m_right = 511.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�������I", 108, 590 - time, 16, c);
		}
		else
		{

			src.m_top = 0.0f;
			src.m_left = 447.0f;
			src.m_right = 511.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�������I", 108, 490, 16, c);
		}
	}
	else if (word == 11)
	{
		if (time < 100)
		{
			src.m_top = 64.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10 - time;
			dst.m_right = 106 - time;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F���Ⴀ�]�����Ă����", 108, 590 - time, 16, c);
		}
		else
		{
			src.m_top = 64.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 0.0f;
			dst.m_right = 0.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F���Ⴀ�]�����Ă����", 108, 490, 16, c);
		}
	}
	else if (word == 12)
	{
		if (time < 100)
		{
			float c[4] = { 1.0f,0.0f,0.0f,1.0f };
			src.m_top = 64.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = -90 + time;
			dst.m_right = 6 + time;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, d, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�҂Ă�I", 50, 200, 64, c);
		}
		else
		{
			float c[4] = { 1.0f,0.0f,0.0f,1.0f };
			src.m_top = 64.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, d, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�҂Ă�I", 50,200, 64, c);
		}

	}
	else if (word == 13)
	{
		if (time < 100)
		{
			float c[4] = { 1.0f,1.0f,1.0f,1.0f };
			src.m_top = 64.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = -90 + time;
			dst.m_right = 6 + time;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�������炱���", 108, 590 - time, 16, c);
		}
		else
		{

			src.m_top = 64.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�������炱���", 108, 490, 16, c);
		}
	}
	else if (word == 14)
	{
		if (time < 100)
		{
			src.m_top = 64.0f;
			src.m_left = 192.0f;
			src.m_right = 256.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W:���I�l�̃J�v�e�e�tGX�I", 108, 590 - time, 16, c);
		}
		else
		{

			src.m_top = 64.0f;
			src.m_left = 192.0f;
			src.m_right = 256.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W:���I�l�̃J�v�e�e�tGX�I", 108, 490, 16, c);
		}
	}
	else if (word == 15)
	{
		if (time < 100)
		{
			src.m_top = 64.0f;
			src.m_left = 64.0f;
			src.m_right =128.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�Ԃ�����ɂ����ꖇ������", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F�Ԃ�����ɂ����ꖇ������", 108, 490, 16, c);
		}
	}
	else if (word == 16)
	{
		if (time < 100)
		{
			src.m_top = 64.0f;
			src.m_left = 256.0f;
			src.m_right = 320.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�E�E�E", 108, 590 - time, 16, c);
		}
		else
		{

			src.m_top = 64.0f;
			src.m_left = 256.0f;
			src.m_right = 320.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�W���[�W�F�E�E�E", 108, 490, 16, c);
		}
	}
	else if (word == 17)
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
			Font::StrDraw(L"�y�j�[���C�Y�F�����c", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F�����c", 108, 490, 16, c);
		}
	}
	else if (word == 18)
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
			Font::StrDraw(L"�y�j�[���C�Y�F����ȂɌ��Ȋ点��ł�", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F����ȂɌ��Ȋ点��ł�", 108, 490, 16, c);
		}
	}
	else if (word == 19)
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
			Font::StrDraw(L"�y�j�[���C�Y�F������@�f�ň����Ă�", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F������@�f�ň����Ă�", 108, 490, 16, c);
		}
	}
	else if (word == 20)
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
			Font::StrDraw(L"�y�j�[���C�Y�F�����Ę^���߂��Ⴍ���ፋ�؂Ȃ񂾂�", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F�����Ę^���߂��Ⴍ���ፋ�؂Ȃ񂾂�", 108, 490, 16, c);
		}
	}
	else if (word == 21)
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
			Font::StrDraw(L"�y�j�[���C�Y�F�������͂킩���", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F�������͂킩���", 108, 490, 16, c);
		}
	}
	else if (word == 22)
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
			Font::StrDraw(L"�W���[�W�F�{���ɏo�₷���H", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�W���[�W�F�{���ɏo�₷���H", 108, 490, 16, c);
		}
	}
	else if (word == 23)
	{
		if (time < 100)
		{
			src.m_top = 128.0f;
			src.m_left = 64.0f;
			src.m_right = 128.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�����@����", 108, 590 - time, 16, c);
		}
		else
		{
			src.m_top = 128.0f;
			src.m_left = 64.0f;
			src.m_right = 128.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�����@����", 108, 490, 16, c);
		}
	}
	else if (word == 24)
	{
		if (time < 100)
		{

			src.m_top = 128.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�|�P�J�͂������@�W���[�W�B", 108, 590 - time, 16, c);
		}
		else
		{

			src.m_top = 128.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�|�P�J�͂������@�W���[�W�B", 108, 490, 16, c);
		}
	}
	else if (word == 25)
	{
		if (time < 100)
		{
			src.m_top = 128.0f;
			src.m_left = 192.0f;
			src.m_right = 256.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�[����", 108, 590 - time, 16, c);
		}
		else
		{
			src.m_top = 128.0f;
			src.m_left = 192.0f;
			src.m_right = 256.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�[����", 108, 490, 16, c);
		}
	}
	else if (word == 26)
	{
		if (time < 100)
		{
			src.m_top = 128.0f;
			src.m_left = 192.0f;
			src.m_right = 256.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�N���n�}�邩��", 108, 590 - time, 16, c);
		}
		else
		{
			src.m_top = 128.0f;
			src.m_left = 192.0f;
			src.m_right = 256.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�F�N���n�}�邩��", 108, 490, 16, c);
		}
	}
	else if (word == 27)
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
			Font::StrDraw(L"�y�j�[���C�Y�F���O�������J�|�P�J����񂾂�I�I", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"�y�j�[���C�Y�F���O�������J�|�P�J����񂾂�I�I", 108, 490, 16, c);
		}
	}
	else if (word == 28)
	{
		if (time < 95)
		{
			src.m_top = 128.0f;
			src.m_left = 320.0f;
			src.m_right = 384.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 300.0f - 3 * time;
			dst.m_left =  400- 4*time;
			dst.m_right = 464 +4*time;
			dst.m_bottom = 364.0f+3*time;
			Draw::Draw(4, &src, &dst, c, 0.0f);
		}
		else
		{

			src.m_top = 128.0f;
			src.m_left = 320.0f;
			src.m_right = 384.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 0.0f;
			dst.m_left = 0.0f;
			dst.m_right = 800.0f;
			dst.m_bottom = 600.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
		}
	}
	else if (word == 29)
	{
		if (time < 100)
		{
			src.m_top = 128.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�͎���", 108, 590 - time, 16, c);
			Font::StrDraw(L"�J�v�e�e�t��2�������Ȃ������̂�", 108, 606 - time, 16, c);
		}
		else
		{

			src.m_top = 128.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�y�j�[���C�Y�͎���", 108, 490, 16, c);
			Font::StrDraw(L"�J�v�e�e�t��2�������Ȃ������̂�", 108, 506, 16, c);
		}
	}
	else if (word == 30)
	{
		if (time < 100)
		{
			src.m_top = 128.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�ł��Ę^���f���炵��", 108, 590 - time, 16, c);
			Font::StrDraw(L"�f�b�L�K�{�p�[�c��������������Ă���", 108, 606 - time, 16, c);
		}
		else
		{

			src.m_top = 128.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"�ł��Ę^���f���炵��", 108, 490, 16, c);
			Font::StrDraw(L"�f�b�L�K�{�p�[�c��������������Ă���", 108, 506, 16, c);
		}
	}
	else if (word ==31)
	{
		if (time < 100)
		{
			src.m_top = 128.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"����ȍ��؍Ę^��R�ŐV�K�������Ă�", 108, 590 - time, 16, c);
			Font::StrDraw(L"�E���g���V���C�j�[��11��2���������I", 108, 606 - time, 16, c);
		}
		else
		{

			src.m_top = 128.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"����ȍ��؍Ę^��R�ŐV�K�������Ă�", 108, 490, 16, c);
			Font::StrDraw(L"�E���g���V���C�j�[��11��2���������I", 108, 506, 16, c);
		}
	}

}