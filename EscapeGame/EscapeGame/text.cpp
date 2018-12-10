//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"ObjBlock.h"
//使用するネームスペース
using namespace GameL;

bool text_move=true;
int word=0;
//イニシャライズ
void CObjText::Init()
{
	m_key_flag = false;
	skip_flag = false;
	time = 120;

	x = 0;
	y = 0;
}
//アクション
void CObjText::Action()
{
	time += 1;
	//オープニング　-1
	//きらら　-3 0 3
	//奏多 -4 1 4
	//永遠 -5 2 5
    //幕間 6 7
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
//ドロー
void CObjText::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画表示位置
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
		Font::StrDraw(L"玄関", 685, 532, 32, c);
	}
	//オープニング
	else if (text_m == -1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"玄関", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:ねえ奏多…雨いつやむかな？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:ねえ奏多…雨いつやむかな？", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:この感じだとすぐやむと思いますが", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:この感じだとすぐやむと思いますが", 108, 490, 16, c);
			}
		}
		else if (word == 3)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"???:ここなら雨宿りできそうだな…", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"???:ここなら雨宿りできそうだな…", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:誰!?", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:誰!?", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"???:先客がいたのか", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"???:先客がいたのか", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"???:俺の名前は鳳一樹。君と同じ学校の二年だ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"???:俺の名前は鳳一樹。君と同じ学校の二年だ", 108, 490, 16, c);
			}
		}
		else if (word == 7)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:あら、同じ学校のセンパイ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:あら、同じ学校のセンパイ", 108, 490, 16, c);
			}
		}
		else if (word == 8)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:あたしの名前は大星きらら♪アイドルやってます！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:あたしの名前は大星きらら♪アイドルやってます！", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:運悪く通り雨に降られ急遽雨宿りしてるの", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:運悪く通り雨に降られ急遽雨宿りしてるの", 108, 490, 16, c);
			}
		}
		else if (word == 10)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:そっか", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:そっか", 108, 490, 16, c);
			}
		}
		else if (word == 11)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:こっちは私のマネージャーの奏多よ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:こっちは私のマネージャーの奏多よ", 108, 490, 16, c);
			}
		}
		else if (word== 12)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:岸野奏多です。", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:岸野奏多です。", 108, 490, 16, c);
			}
		}
		else if (word == 13)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:きらら様のマネージャー兼メイドです", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:きらら様のマネージャー兼メイドです", 108, 490, 16, c);
			}
		}
		else if (word== 14)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:先客が多いね", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:先客が多いね", 108, 490, 16, c);
			}
		}
		else if (word == 15)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:確かあなたは…", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:確かあなたは…", 108, 490, 16, c);
			}
		}
		else if (word == 16)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:生徒会長の北上永遠さんですね", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:生徒会長の北上永遠さんですね", 108, 490, 16, c);
			}
		}
		else if (word == 17)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:そうだよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:そうだよ", 108, 490, 16, c);
			}
		}
		else if (word == 18)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:君は大橋さん家のメイドさんだね", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:君は大橋さん家のメイドさんだね", 108, 490, 16, c);
			}
		}
		else if (word == 19)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:岸野奏多です", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:岸野奏多です", 108, 490, 16, c);
			}
		}
		else if (word == 20)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:あ、雨やみ始めてますね", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:あ、雨やみ始めてますね",  108, 490, 16, c);
			}
		}
		else if (word == 21)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:奏多!とっとと帰るわよ！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:奏多!とっとと帰るわよ！",  108, 490, 16, c);
			}
		}
		else if (word == 22)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:かしこまりました。それでは失礼します", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:かしこまりました。それでは失礼します", 108, 490, 16, c);
			}
		}
		else if (word == 23)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:俺も帰ろう", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:俺も帰ろう", 108, 490, 16, c);
			}
		}
		else if (word == 24)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:僕も帰らなきゃ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:僕も帰らなきゃ", 108, 490, 16, c);
			}
		}
		else if (word == 25)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:ん？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:ん？", 108, 490, 16, c);
			}
		}
		else if (word == 26)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:ドアが開かないぞ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:ドアが開かないぞ", 108, 490, 16, c);
			}
		}
		else if (word == 27)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:そんなわけないでしょ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:そんなわけないでしょ", 108, 490, 16, c);
			}
		}
		else if (word == 28)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:失礼します", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:失礼します", 108, 490, 16, c);
			}
		}
		else if (word == 29)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:開きませんね", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:開きませんね", 108, 490, 16, c);
			}
		}
		else if (word == 30)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:本当かい？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:本当かい？", 108, 490, 16, c);
			}
		}
		else if (word == 31)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:さて、どうしたものか", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:さて、どうしたものか", 108, 490, 16, c);
			}
		}
		else if (word == 32)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:こっちのドアは開くわよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:こっちのドアは開くわよ", 108, 490, 16, c);
			}
		}
		else if (word == 33)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:ならそっちを探索するか？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:ならそっちを探索するか？", 108, 490, 16, c);
			}
		}
		else if (word == 34)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:あまりお勧めはしませんね", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:あまりお勧めはしませんね", 108, 490, 16, c);
			}
		}
		else if (word== 35)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:時間がたてば我が家の救助チームが駆け付けますので", 108, 590 - time, 16, c);
				Font::StrDraw(L"しばしお待ちください", 108, 606 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:時間がたてば我が家の救助チームが駆け付けますので", 108, 490, 16, c);
				Font::StrDraw(L"しばしお待ちください", 108, 506, 16, c);
			}
		}
		else if (word == 36)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:でも、こんな機会滅多にないし僕は探索に賛成かな", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:でも、こんな機会滅多にないし僕は探索に賛成かな", 108, 490, 16, c);
			}
		}
		else if (word == 37)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:私も探索したいわ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:私も探索したいわ", 108, 490, 16, c);
			}
		}
		else if (word == 38)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:奏多、救助チームの手配は待ちなさい", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:奏多、救助チームの手配は待ちなさい", 108, 490, 16, c);
			}
		}
		else if (word ==39)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:しかし…", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:しかし…", 108, 490, 16, c);
			}
		}
		else if (word == 40)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:奏多！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:奏多！", 108, 490, 16, c);
			}
		}
		else if (word == 41)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:かしこまりました", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:かしこまりました", 108, 490, 16, c);
			}
		}
		else if (word == 42)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:でしたら私がまず全部屋の安全を確かめます", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:でしたら私がまず全部屋の安全を確かめます", 108, 490, 16, c);
			}
		}
		else if (word == 43)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:その後皆さんに探索してもらうということで…", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:その後皆さんに探索してもらうということで…", 108, 490, 16, c);
			}
		}
		else if (word == 44)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:そんなことしたら絶対許さないからね？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:そんなことしたら絶対許さないからね？", 108, 490, 16, c);
			}
		}
		else if (word== 45)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:でしたら正面の部屋の探索ならよろしいでしょう？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:でしたら正面の部屋の探索ならよろしいでしょう？", 108, 490, 16, c);
			}
		}
		else if (word == 46)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:それならいいわ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:それならいいわ", 108, 490, 16, c);
			}
		}
		else if (word == 47)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:それじゃあ僕はあっちの部屋を探索するよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:それじゃあ僕はあっちの部屋を探索するよ", 108, 490, 16, c);
			}
		}
		else if (word == 48)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:お願いしますね先輩", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:お願いしますね先輩", 108, 490, 16, c);
			}
		}
		else if (word == 49)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:謎の館の探索の開始だー！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:謎の館の探索の開始だー！", 108, 490, 16, c);
			}
		}
		else if (word == 50)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:おー！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:おー！", 108, 490, 16, c);
			}
		}
		else if (word == 51)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:お、おー…", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:お、おー…", 108, 490, 16, c);
			}
		}
		else if (word == 52)
		{
			text_move = false;
			Font::StrDraw(L"部屋をえらんで探索しよう", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//きららマップ
	//進入時　word=0～10
	//解除後時　word=10～21
	else if (text_m == -3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"居間", 685, 532, 32, c);
	}
	//きららマップ進入時会話-----------------------------------------------------------------------
	else if (text_m == 0)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"居間", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:あ、鳳君！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:あ、鳳君！", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:大星？どうしたんだこんな所で", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:大星？どうしたんだこんな所で", 108, 490, 16, c);
			}
		}
		else if (word == 3)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:この部屋いろいろ調べてんのよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:この部屋いろいろ調べてんのよ", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:そうか…何か成果はあったか？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:そうか…何か成果はあったか？", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:何も見つからなかったわ…", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:何も見つからなかったわ…", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:気にするな", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:気にするな", 108, 490, 16, c);
			}
		}
		else if (word == 7)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:俺も一緒に探すから", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:俺も一緒に探すから", 108, 490, 16, c);
			}
		}
		else if (word == 8)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:ありがとう", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:ありがとう", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:それじゃあとっとと手掛かり見つけるわよ！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:それじゃあとっとと手掛かり見つけるわよ！", 108, 490, 16, c);
			}
		}
		else if (word == 10)
		{
			text_move = false;
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
		}
	}
	//きらら答え入力後-----------------------------------------------------------------------
	else if(text_m==3)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"居間", 685, 532, 32, c);
		if (word == 10)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 490, 32, c);
		}
		if (word== 11)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:大星！メモ見つけたぞ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:大星！メモ見つけたぞ", 108, 490, 16, c);
			}
		}
		else if (word == 12)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:ほんと？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:ほんと？", 108, 490, 16, c);
			}
		}
		else if (word == 13)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:結局私何も見つけられなかったわ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:結局私何も見つけられなかったわ", 108, 490, 16, c);
			}
		}
		else if (word == 14)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:あんまり気にするなよ？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:あんまり気にするなよ？", 108, 490, 16, c);
			}
		}
		else if (word == 15)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:心配ないわ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:心配ないわ", 108, 490, 16, c);
			}
		}
		else if (word == 16)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:今度こそ何か見つめてあげる", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:今度こそ何か見つめてあげる", 108, 490, 16, c);
			}
		}
		else if (word == 17)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:頑張るのはいいけど無茶するなよ？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:頑張るのはいいけど無茶するなよ？", 108, 490, 16, c);
			}
		}
		else if (word == 18)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:俺は違う部屋を探索してくるよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:俺は違う部屋を探索してくるよ", 108, 490, 16, c);
			}
		}
		else if (word == 19)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:私はもう少しここを探索してるわ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:私はもう少しここを探索してるわ", 108, 490, 16, c);
			}
		}
		else if (word == 20)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"主人公:いいけど気をつけろよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"主人公:いいけど気をつけろよ", 108, 490, 16, c);
			}
		}
		else if (word == 21)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:そっちこそ気をつけなさいよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:そっちこそ気をつけなさいよ", 108, 490, 16, c);
			}
		}
		else if (word == 22)
		{
			text_move = false;
			Font::StrDraw(L"他の部屋を探しに行こう", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//奏多マップ
	//進入時　word=0～13
	//鍵取得時　word=13～18
	else if (text_m == -4)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"図書室", 670, 532, 32, c);
	}
	//奏多マップ進入時-------------------------------------------------------------------------
	else if (text_m == 1)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"図書室", 670, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 490, 32, c);
		}
		if (word == 1)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:やけに片付いた部屋だな", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:やけに片付いた部屋だな", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:あ、鳳さん。どうかいたしましたか？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:あ、鳳さん。どうかいたしましたか？", 108, 490, 16, c);
			}
		}
		else if (word == 3)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:岸野さんいたんですか", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:岸野さんいたんですか", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:そうかしこまらなくても大丈夫ですよ。同い年ですから", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:そうかしこまらなくても大丈夫ですよ。同い年ですから", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:わかった。で、岸野さんはどうしてはたきを持っているんだ？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:わかった。で、岸野さんはどうしてはたきを持っているんだ？", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:職業上汚い部屋を見ると片付けたくなるんです", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:職業上汚い部屋を見ると片付けたくなるんです", 108, 490, 16, c);
			}
		}
		else if (word == 7)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:そっかじゃあ手伝うよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:そっかじゃあ手伝うよ", 108, 490, 16, c);
			}
		}
		else if (word == 8)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:え？いいんですか？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:え？いいんですか？", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:部屋の片づけしながら探せばいいよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:部屋の片づけしながら探せばいいよ", 108, 490, 16, c);
			}
		}
		else if (word == 10)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:申し訳ありません。手早く終わらせますので", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:申し訳ありません。手早く終わらせますので", 108, 490, 16, c);
			}
		}
		else if (word == 11)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:それじゃあ始めようか", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:それじゃあ始めようか", 108, 490, 16, c);
			}
		}
		else if (word == 12)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:はい！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:はい！", 108, 490, 16, c);
			}
		}
		else if (word == 13)
		{
			text_move = false;
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
		}
	}
    //鍵入手後-----------------------------------------------------------------------
	else if (text_m == 4)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"図書室", 670, 532, 32, c);
		if (word == 13)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 490, 32, c);
		}
		else if (word == 14)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:何かのメモだな", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:何かのメモだな", 108, 490, 16, c);
			}
		}
		else if (word == 15)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:なんでしょうね", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:なんでしょうね", 108, 490, 16, c);
			}
		}
		else if (word == 16)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:とりあえず他の部屋も見回って来るよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:とりあえず他の部屋も見回って来るよ", 108, 490, 16, c);
			}
		}
		else if (word == 17)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:わかりました。お嬢様をよろしくお願いします", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:わかりました。お嬢様をよろしくお願いします", 108, 490, 16, c);
			}
		}
		else if (word == 18)
		{
			text_move = false;
			Font::StrDraw(L"他の部屋を探しに行こう", 50, 490, 32, c);
			text_loop = false;
		}
	}
	//永遠マップ-----------------------------------------------------------------------
	//進入時　word=0～9
	//メモ取得時　word=9～19
	else if (text_m == -5)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"和室", 685, 532, 32, c);
	}
	//永遠マップ進入時-------------------------------------------------------------------------
	else if (text_m == 2)
	{
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"和室", 685, 532, 32, c);
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 490, 32, c);
		}
		else if (word == 1)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:鳳君、どうかしたのかな？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:鳳君、どうかしたのかな？", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:北上先輩ですか。この部屋に何かありました？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:北上先輩ですか。この部屋に何かありました？", 108, 490, 16, c);
			}
		}
		else if (word == 3)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:まだ何にも見つかってないんだ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:まだ何にも見つかってないんだ", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:そうだ！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:そうだ！", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:探すの一緒に手伝ってよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:探すの一緒に手伝ってよ", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:わかりました。俺でよければ手伝いますよ", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:わかりました。俺でよければ手伝いますよ", 108, 490, 16, c);
			}
		}
		else if (word == 7)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:ありがとう。", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:ありがとう。", 108, 490, 16, c);
			}
		}
		else if (word == 8)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:それじゃよろしく！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:それじゃよろしく！", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{

			text_move = false;
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
		}
	}
	//永遠マップ解除時-------------------------------------------------------------------------
	else if (text_m == 5)
		{
			Font::StrDraw(L"1F", 700, 500, 32, c);
			Font::StrDraw(L"和室", 685, 532, 32, c);
			if (word == 9)
			{
				text_move = true;
				Font::StrDraw(L"Zキーで会話進行", 50, 490, 32, c);
			}
			else if (word == 10)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"永遠:これは何かのメモかな?", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"永遠:これは何かのメモかな?", 108, 490, 16, c);
				}
			}
			else if (word == 11)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"鳳:みたいですね", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"鳳:みたいですね", 108, 490, 16, c);
				}
			}
			else if (word == 12)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"永遠:もしかしたら他にも何かあるかもしれないね", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"永遠:もしかしたら他にも何かあるかもしれないね", 108, 490, 16, c);
				}
			}
			else if (word == 13)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"鳳:ですね。もっとこの部屋調べてみましょうか", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"鳳:ですね。もっとこの部屋調べてみましょうか", 108, 490, 16, c);
				}
			}
			else if (word == 14)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"永遠:鳳君は他の部屋を調べに行ってみてよ", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"永遠:鳳君は他の部屋を調べに行ってみてよ", 108, 490, 16, c);
				}
			}
			else if (word == 15)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"鳳:大丈夫ですか？", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"鳳:大丈夫ですか？", 108, 490, 16, c);
				}
			}
			else if (word == 16)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"永遠:僕は生徒会長なんだよ?大丈夫だよ", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"永遠:僕は生徒会長なんだよ?大丈夫だよ", 108, 490, 16, c);
				}
			}
			else if (word == 17)
			{
				Draw::Draw(4, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"鳳:わかりました。先輩も気を付けて", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"鳳:わかりました。先輩も気を付けて", 108, 490, 16, c);
				}
			}
			else if (word == 18)
			{
				Draw::Draw(8, &src, &dst, c, 0.0f);
				if (time < 100)
				{
					Font::StrDraw(L"永遠:任せて", 108, 590 - time, 16, c);
				}
				else
				{
					Font::StrDraw(L"永遠:任せて", 108, 490, 16, c);
				}
			}
			else if (word == 19)
			{
				text_move = false;
				Font::StrDraw(L"他の部屋を探しに行こう", 50, 490, 32, c);
				text_loop = false;
			}
		}
	//幕間
	//１階層1～6
	//２階層6～15
	//１階層-----------------------------------------------------------------------
	else if (text_m == 6)
	{
		text_move = true;
		Font::StrDraw(L"1F", 700, 500, 32, c);
		Font::StrDraw(L"玄関", 685, 532, 32, c);
		if (word == 0)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				
				Font::StrDraw(L"鳳:3つのメモがそろったみたいだな", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:3つのメモがそろったみたいだな", 108, 490, 16, c);
			}
		}
		else if (word == 1)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:やったわね", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:やったわね", 108, 490, 16, c);
			}
		}
		else if (word == 2)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:それでメモにはなんて書いているんですか?", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:それでメモにはなんて書いているんですか?", 108, 490, 16, c);
			}
		}
		else if (word== 3)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:「ミスミソウ」「イフェイオン」「サクラソウ」だな", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:「ミスミソウ」「イフェイオン」「サクラソウ」だな", 108, 490, 16, c);
			}
		}
		else if (word == 4)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:イフェイオン？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:イフェイオン？", 108, 490, 16, c);
			}
		}
		else if (word == 5)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:なによそれ", 108, 590 - time, 16, c);
			}
			else 
			{
				Font::StrDraw(L"きらら:なによそれ", 108, 490, 16, c);
			}
		}
		else if (word == 6)
		{
			text_move = false;
			Font::StrDraw(L"探索しよう！", 50, 490, 32, c);
		}
	}
	//２階層-----------------------------------------------------------------------
	else if (text_m == 7)
	{
		Font::StrDraw(L"2F", 700, 500, 32, c);
		if (word == 6)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 490, 32, c);
		}
		else if (word == 7)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:二階に来たのはいいけどこれじゃ出られないわよ？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:二階に来たのはいいけどこれじゃ出られないわよ？", 108, 490, 16, c);
			}
		}
		if (word == 8)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:この階に何か手掛かりがあるんじゃないかな", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:この階に何か手掛かりがあるんじゃないかな", 108, 490, 16, c);
			}
		}
		else if (word == 9)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:それじゃこの部屋も分かれて探す感じでいいかな？", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:それじゃこの部屋も分かれて探す感じでいいかな？", 108, 490, 16, c);
			}
		}
		else if (word == 10)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:なら私はこっちに行くわ！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:なら私はこっちに行くわ！", 108, 490, 16, c);
			}
		}
		else if (word == 11)
		{
			Draw::Draw(6, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"きらら:奏多はあっちを調べなさい！", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"きらら:奏多はあっちを調べなさい！", 108, 490, 16, c);
			}
		}
		else if (word == 12)
		{
			Draw::Draw(7, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"奏多:かしこまりました", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"奏多:かしこまりました", 108, 490, 16, c);
			}
		}
		else if (word == 13)
		{
			Draw::Draw(8, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"永遠:それじゃあ僕は残りの部屋を調べようかな", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"永遠:それじゃあ僕は残りの部屋を調べようかな", 108, 490, 16, c);
			}
		}
		if (word == 14)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			if (time < 100)
			{
				Font::StrDraw(L"鳳:（俺は誰かを手伝いに行こう）", 108, 590 - time, 16, c);
			}
			else
			{
				Font::StrDraw(L"鳳:（俺は誰かを手伝いに行こう）", 108, 490, 16, c);
			}
		}
		if (word == 15)
		{
			text_move = false;
			Font::StrDraw(L"部屋をえらんで探索しよう", 50, 490, 32, c);
			text_loop = false;
		}
	}
}