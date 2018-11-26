//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"ObjBlock.h"
//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjText::Init()
{
	m_key_flag = false;
	time = 120;
	word[0] = 0;
	word[1] = 0;
	word[2] = 0;
	word[3] = 0;
	word[4] = 0;

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
					if (text_m == 0&&word[0]<=20|| text_m == 3 && word[0] <= 27|| text_m == 4)
					{
						word[0] += 1;
						m_key_flag = false;
						time = 0;
					}
					else if (text_m == 1 && word[1] <= 12)
					{
						word[1] += 1;
						m_key_flag = false;
						time = 0;
					}
					else if (text_m == 2 && word[2] <= 8)
					{
						word[2] += 1;
						m_key_flag = false;
						time = 0;
					}
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
	//きららマップ
	//進入時　word[0]=0～20
	//鍵取得時時　word[0]=22～27
	//解除後時　word[0]=29～42
	if (text_m == -1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"玄関", 685, 532, 32, c);
	}
	//きららマップ進入時会話-----------------------------------------------------------------------
	if (text_m == 0)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"居間", 685, 532, 32, c);
		if (word[0] == 0)
		{
			Font::StrDraw(L"Aキーで会話進行", 50, 490, 32, c);
		}
	    else if (word[0] == 1)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"主人公:この部屋は何かあるかな", 108, 590 - time, 16, c);
			}
			else
			{
				//背景表示
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"主人公:この部屋は何かあるかな", 108, 490, 16, c);
			}
		}
		else if (word[0] == 2)
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
				Font::StrDraw(L"きらら:あ、主人公！", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:あ、主人公！", 108, 490, 16, c);
			}
		}
		else if (word[0] == 3)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"主人公:大星？どうしたんだこんな所で", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:大星？どうしたんだこんな所で", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:この部屋いろいろ調べてんのよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:この部屋いろいろ調べてんのよ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:そうか…何か成果はあったか？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:そうか…何か成果はあったか？", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:と…当然でしょ？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:と…当然でしょ？", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:ほんとか！？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:ほんとか！？", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:も…もちろん", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:も…もちろん", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:何を見つけたんだ？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:何を見つけたんだ？", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:……ょ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:……ょ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:悪い、聞こえなかった", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:悪い、聞こえなかった", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:何も見つからなかったって言ってるのよ!!", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:何も見つからなかったって言ってるのよ!!", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:…え？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:…え？", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:鍵も鍵穴も隠し扉も動く本棚も何にも見つからなかったわよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:鍵も鍵穴も隠し扉も動く本棚も何にも見つからなかったわよ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:お、おう…悪い", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:お、おう…悪い", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:…ごめんなさい", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:…ごめんなさい", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:あなたにあたっても仕方ないものね", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:あなたにあたっても仕方ないものね", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:気にするなよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:気にするなよ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:俺も一緒に探すから", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:俺も一緒に探すから", 108, 490, 16, c);
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
				Font::StrDraw(L"きらら:ありがとう", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:ありがとう", 108, 490, 16, c);
			}
		}
		else if (word[0] == 21)
		{
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
		}
	}
	//きらら鍵取得後----------------------------------------
	else if (text_m == 3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"居間", 685, 532, 32, c);
		if (word[0] == 21)
		{
			Font::StrDraw(L"Aキーで会話進行", 50, 490, 32, c);
		}
		else if (word[0] == 22)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:何か見つかったかしら?", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:何か見つかったかしら?", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:メモが数枚見つかったよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:メモが数枚見つかったよ", 108, 490, 16, c);
			}
		}
		else if (word[0] == 24)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top =64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:数字が書いているわね", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:数字が書いているわね", 108, 490, 16, c);
			}
		}
		else if (word[0] == 25)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:ナンバーロックとか何かかしら？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:ナンバーロックとか何かかしら？", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:ならどこか使う場所がどこかにあるな", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:ならどこか使う場所がどこかにあるな", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:まずはこの部屋を探してみよう", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:ならどこか使う場所がどこかにあるな", 108, 490, 16, c);
			}
		}
		else if (word[0] == 28)
		{
			Font::StrDraw(L"ロックドアを探そう！", 50, 490, 32, c);
		}
	}
	//きららマップ鍵解除後---------------------------------------------------------------------
	else if (text_m == 4)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"居間", 685, 532, 32, c);
	    if (word[0] == 28)
	    {
		    Font::StrDraw(L"Aキーで会話進行", 50, 490, 32, c);
	    }
		else if (word[0] == 29)
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
				Font::StrDraw(L"きらら:やったわね！", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:やったわね！", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:大星のおかげだ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:大星のおかげだ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:ありがとうな", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:ありがとうな", 108, 490, 16, c);
			}
		}
		else if (word[0] == 32)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:別に私は何もしてないわ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:別に私は何もしてないわ", 108, 490, 16, c);
			}
		}
		else if (word[0] == 33)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:メモを見つけたのもロック解除したのもあなたよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:メモを見つけたのもロック解除したのもあなたよ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:でも俺一人じゃ無理だったよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:でも俺一人じゃ無理だったよ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:だからありがとう", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:だからありがとう", 108, 490, 16, c);
			}
		}
		else if (word[0] == 36)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:…ならそのお礼ありがたく受け取っておくわ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:…ならそのお礼ありがたく受け取っておくわ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:俺は他の場所を調べに行くけどどうする？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:俺は他の場所を調べに行くけどどうする？", 108, 490, 16, c);
			}
		}
		else if (word[0] == 38)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 64.0f;
				src.m_left = 320.0f;
				src.m_right = 384.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:私はもう少しここを探索してみるわ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:私はもう少しここを探索してみるわ", 108, 490, 16, c);
			}
		}
		else if (word[0] == 39)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:今度こそ何か見つけてあげるわ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:今度こそ何か見つけてあげるわ", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:わかった", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:わかった", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:何があるかわからないから気をつけろよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:何があるかわからないから気をつけろよ", 108, 490, 16, c);
			}
		}
		else if (word[0] == 42)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 64.0f;
				src.m_left = 448.0f;
				src.m_right = 512.0f;
				src.m_bottom = 128.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"きらら:そっちこそドジやるんじゃないわよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"きらら:そっちこそドジやるんじゃないわよ", 108, 490, 16, c);
			}
		}
	}
	//奏多マップ進入時-------------------------------------------------------------------------
	if (text_m == 1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"図書室", 670, 532, 32, c);
		if (word[1] == 0)
		{
			Font::StrDraw(L"Aキーで会話進行", 50, 490, 32, c);
		}
		if (word[1] == 1)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 590.0f - time;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 690.0f - time;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"主人公:やけに片付いた部屋だな", 108, 590 - time, 16, c);
			}
			else
			{
				//背景表示
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"主人公:やけに片付いた部屋だな", 108, 490, 16, c);
			}
		}
		else if (word[1] == 2)
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
				Font::StrDraw(L"奏多:あ、主人公さん。どうかいたしましたか？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:あ、主人公さん。どうかいたしましたか？", 108, 490, 16, c);
			}
		}
		else if (word[1] == 3)
		{
			if (time < 100)
			{
				//背景表示
				src.m_top = 0.0f;
				src.m_left = 128.0f;
				src.m_right = 192.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 490.0f;
				dst.m_left = 10.0f;
				dst.m_right = 106.0f;
				dst.m_bottom = 590.0f;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"主人公:岸野さんいたんですか", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:岸野さんいたんですか", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:そうかしこまらなくても大丈夫ですよ。同い年ですから", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:そうかしこまらなくても大丈夫ですよ。同い年ですから", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:わかった。で、岸野さんはどうしてはたきを持っているんだ？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:わかった。で、岸野さんはどうしてはたきを持っているんだ？", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:職業上汚い部屋を見ると片付けたくなるんです", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:職業上汚い部屋を見ると片付けたくなるんです", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:そっかじゃあ手伝うよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:そっかじゃあ手伝うよ", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:え？いいんですか？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:え？いいんですか？", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:部屋の片づけしながら探せばいいよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:部屋の片づけしながら探せばいいよ", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:申し訳ありません。手早く終わらせますので", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:申し訳ありません。手早く終わらせますので", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:それじゃあ始めようか", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:それじゃあ始めようか", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:はい！", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:はい！", 108, 490, 16, c);
			}
		}
		else if (word[1] == 13)
		{
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
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
				Font::StrDraw(L"主人公:ここさっき見つけた鍵が使えそうだな", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:ここさっき見つけた鍵が使えそうだな", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:何か見つけたんですか？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:何か見つけたんですか？", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:鍵穴を見つけたんだ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:鍵穴を見つけたんだ", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:開けてみましょう", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:開けてみましょう", 108, 490, 16, c);
			}
		}
		else if (word[1] == 18)
		{
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
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
				Font::StrDraw(L"主人公:何かのメモだな", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:何かのメモだな", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:なんでしょうね", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:なんでしょうね", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:とりあえず他の部屋も見て回って来るよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:とりあえず他の部屋も見て回って来るよ", 108, 490, 16, c);
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
				Font::StrDraw(L"奏多:わかりました。お嬢様をよろしくお願いします", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"奏多:わかりました。お嬢様をよろしくお願いします", 108, 490, 16, c);
			}
		}

	}
	//永遠マップ進入時-------------------------------------------------------------------------
	if (text_m == 2)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"和室", 685, 532, 32, c);
		if (word[2] == 0)
		{
			Font::StrDraw(L"Aキーで会話進行", 50, 490, 32, c);
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
				Font::StrDraw(L"永遠:主人公君、どうかしたのかな？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"永遠:主人公君、どうかしたのかな？", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:北上先輩ですか。この部屋に何かありました？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:北上先輩ですか。この部屋に何かありました？", 108, 490, 16, c);
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
				Font::StrDraw(L"永遠:永遠でいいよ。金庫があったんだけど、", 108, 590 - time, 16, c);
				Font::StrDraw(L"鍵がかかってるみたいなんだ", 108, 606 - time, 16, c);
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
				Font::StrDraw(L"永遠:永遠でいいよ。金庫があったんだけど、", 108, 490, 16, c);
				Font::StrDraw(L"鍵がかかってるみたいなんだ", 108, 506, 16, c);
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
				Font::StrDraw(L"主人公:金庫の鍵ですか…この部屋にありますかね？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:金庫の鍵ですか…この部屋にありますかね？", 108, 490, 16, c);
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
				Font::StrDraw(L"永遠:まだしっかり探してないから何とも言えないな～", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"永遠:まだしっかり探してないから何とも言えないな～", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:わかりました。俺も一緒に探しますよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:わかりました。俺も一緒に探しますよ", 108, 490, 16, c);
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
				Font::StrDraw(L"永遠:ありがとう。何かそれっぽいもの見つけたら教えてね", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"永遠:ありがとう。何かそれっぽいもの見つけたら教えてね", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:はい", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:はい", 108, 490, 16, c);
			}
		}
		else if (word[2] == 9)
		{
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
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
				Font::StrDraw(L"主人公:鍵見つかりましたよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:鍵見つかりましたよ", 108, 490, 16, c);
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
				Font::StrDraw(L"永遠:ありがとう。開けてみよっか", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"永遠:ありがとう。開けてみよっか", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:開かないですね", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:開かないですね", 108, 490, 16, c);
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
				Font::StrDraw(L"永遠:他にもないか探してみよう", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"永遠:他にもないか探してみよう", 108, 490, 16, c);
			}
		}
		else if (word[2] == 12)
		{
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
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
				Font::StrDraw(L"主人公:先輩それっぽい鍵見つけましたよ", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:先輩それっぽい鍵見つけましたよ", 108, 490, 16, c);
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
				Font::StrDraw(L"永遠:ありがとう。それじゃあ開けてみようか。", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"永遠:ありがとう。それじゃあ開けてみようか。", 108, 490, 16, c);
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
				Font::StrDraw(L"永遠:これは、何かのメモかな？", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"永遠:これは、何かのメモかな？", 108, 490, 16, c);
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
				Font::StrDraw(L"主人公:みたいですね。メモの内容的には本棚に何かあるみたいですが…", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"主人公:みたいですね。メモの内容的には本棚に何かあるみたいですが…", 108, 490, 16, c);
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
				Font::StrDraw(L"永遠:もしかしたら他にもメモがあるかもしれないね", 108, 590 - time, 16, c);
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
				Font::StrDraw(L"永遠:もしかしたら他にもメモがあるかもしれないね", 108, 490, 16, c);
			}
		}
	}
}