//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"text.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjText::Init()
{
	m_key_flag = false;
	word = 0;
	time = 120;
	x = 0;
	y = 0;
}

//アクション
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
//ドロー
void CObjText::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画表示位置


	if (word == 1)
	{
		if (time < 100)
		{
			//背景表示
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 590.0f - time;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 690.0f - time;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"ペニーワイズ：ハァイ　ジョージィ", 108, 590 - time, 16, c);
		}
		else
		{
			//背景表示
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"ペニーワイズ：ハァイ　ジョージィ", 108, 490, 16, c);
		}
	}
	else if (word == 2)
	{
		if (time < 100)
		{
			//背景表示
			src.m_top = 0.0f;
			src.m_left = 64.0f;
			src.m_right = 128.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f;
			dst.m_right = 106.0f;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"ペニーワイズ：カプテテフGXって2枚持ってる？", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：カプテテフGXって2枚持ってる？", 108, 490, 16, c);
		}
	}
	else if (word == 3)
	{
		if (time < 100 && time > 80)
		{
			x += 1;
			//背景表示
			src.m_top = 0.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f + x;
			dst.m_right = 106.0f + x;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"ジョージ：（首振り）", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ：（首振り）", 108, 590 - time, 16, c);
		}
		else if (time <= 40 && time > 1)
		{
			x += 1;
			//背景表示
			src.m_top = 0.0f;
			src.m_left = 128.0f;
			src.m_right = 192.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 490.0f;
			dst.m_left = 10.0f + x;
			dst.m_right = 106.0f + x;
			dst.m_bottom = 590.0f;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"ジョージ：（首振り）", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ：（首振り）", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：えー　強いのに？", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：えー　強いのに？", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：売るよ？", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：売るよ？", 108, 490, 16, c);
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
			Font::StrDraw(L"ジョージ：どうせ5000円するんでしょ？", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ：どうせ5000円するんでしょ？", 108, 490, 16, c);
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
			Font::StrDraw(L"ジョージ：騙されんぞ", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ：騙されんぞ", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：確かに今は5000円するが", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：確かに今は5000円するが", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：11月2日発売のウルトラシャイニーで再録されるんだ", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：11月2日発売のウルトラシャイニーで再録されるんだ", 108, 490, 16, c);
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
			Font::StrDraw(L"ジョージ：安そう！", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ：安そう！", 108, 490, 16, c);
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
			Font::StrDraw(L"ジョージ：じゃあ転売してくるわ", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ：じゃあ転売してくるわ", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：待てや！", 50, 200, 64, c);
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
			Font::StrDraw(L"ペニーワイズ：待てや！", 50,200, 64, c);
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
			Font::StrDraw(L"ペニーワイズ：いいからこれを", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：いいからこれを", 108, 490, 16, c);
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
			Font::StrDraw(L"ジョージ:あ！僕のカプテテフGX！", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ:あ！僕のカプテテフGX！", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：返す代わりにもう一枚買うんだ", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：返す代わりにもう一枚買うんだ", 108, 490, 16, c);
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
			Font::StrDraw(L"ジョージ：・・・", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ：・・・", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：おう…", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：おう…", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：そんなに嫌な顔せんでも", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：そんなに嫌な顔せんでも", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：うわっ　素で引いてる", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：うわっ　素で引いてる", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：だが再録がめちゃくちゃ豪華なんだぜ", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：だが再録がめちゃくちゃ豪華なんだぜ", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：封入率はわからんが", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：封入率はわからんが", 108, 490, 16, c);
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
			Font::StrDraw(L"ジョージ：本当に出やすい？", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ジョージ：本当に出やすい？", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：えっ　うん", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：えっ　うん", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：ポケカはいいぞ　ジョージィ", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：ポケカはいいぞ　ジョージィ", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：深いぞ", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：深いぞ", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：君もハマるから", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：君もハマるから", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：お前もヤルカポケカするんだよ！！", 108, 590 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズ：お前もヤルカポケカするんだよ！！", 108, 490, 16, c);
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
			Font::StrDraw(L"ペニーワイズは死んだ", 108, 590 - time, 16, c);
			Font::StrDraw(L"カプテテフが2枚引けなかったのだ", 108, 606 - time, 16, c);
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
			Font::StrDraw(L"ペニーワイズは死んだ", 108, 490, 16, c);
			Font::StrDraw(L"カプテテフが2枚引けなかったのだ", 108, 506, 16, c);
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
			Font::StrDraw(L"でも再録が素晴らしく", 108, 590 - time, 16, c);
			Font::StrDraw(L"デッキ必須パーツがたくさん入っている", 108, 606 - time, 16, c);
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
			Font::StrDraw(L"でも再録が素晴らしく", 108, 490, 16, c);
			Font::StrDraw(L"デッキ必須パーツがたくさん入っている", 108, 506, 16, c);
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
			Font::StrDraw(L"そんな豪華再録沢山で新規も入ってる", 108, 590 - time, 16, c);
			Font::StrDraw(L"ウルトラシャイニーは11月2日発売だ！", 108, 606 - time, 16, c);
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
			Font::StrDraw(L"そんな豪華再録沢山で新規も入ってる", 108, 490, 16, c);
			Font::StrDraw(L"ウルトラシャイニーは11月2日発売だ！", 108, 506, 16, c);
		}
	}

}