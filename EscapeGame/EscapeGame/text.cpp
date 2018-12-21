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
	time = 230;
	time_x = -1;
	g = 0;
	d = 0;
}
//アクション
void CObjText::Action()
{
	time += 1;
	time_x -= 1;
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
//ドロー
void CObjText::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c_A[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画表示位置
	RECT_F src_A; //暗転元切り取り位置
	RECT_F dst_A; //暗転描画表示位置
	RECT_F src_B;//テキスト表示隠し(上部）描画元切り取り位置
	RECT_F dst_B;//テキスト表示隠し(上部）描画表示位置
	RECT_F src_C;//テキスト表示隠し(下部）描画元切り取り位置
	RECT_F dst_C;//テキスト表示隠し(下部）描画表示位置
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
	//d 誰が話しているか確認
	//1 鳳　2 きらら 3 奏多 4 永遠
	//オープニング
	if (text_m == -1)
	{
		if (word == 0)
		{
			text_move = true;
		}
		else if (word == 1)
		{
			Font::StrDraw(L"大星きららはメイドの岸野奏多と",120, 525, 30, c);
			Font::StrDraw(L"下校していると突然雨が降ってきた", 120, 555, 30, c);
		}
		else if (word == 2)
		{
			Font::StrDraw(L"二人はたまたま近くにあった館で", 108, 525, 30, c);
			Font::StrDraw(L"雨宿りすることにしたのであった", 108, 555, 30, c);
		}
		else if (word == 3)
		{
			c_A[3]=1.0-time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 2;
			g = 2;
			Font::StrDraw(L"ねえ奏多…雨いつやむかな？", 108, 520, 25, c);
		}
		else if (word == 4)
		{
			d = 3;
			Font::StrDraw(L"この感じだとすぐやむと思いますが", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			d = 0;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???", 20, 485, 25, c);
			Font::StrDraw(L"ここなら雨宿りできそうだな…", 108, 520, 25, c);
		}
		else if (word == 6)
		{
			d = 2;
			Font::StrDraw(L"誰!?", 108, 520, 25, c);
		}
		else if (word == 7)
		{
			d = 0;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???", 20, 485, 25, c);
			Font::StrDraw(L"先客がいたのか", 108, 520, 25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???", 20, 485, 25, c);
			Font::StrDraw(L"俺の名前は鳳一樹。君と同じ学校の二年だ", 108, 520, 25, c);
		}
		else if (word == 9)
		{
			d = 2;
			Font::StrDraw(L"あ、センパイですか？", 108, 520, 25, c);
		}
		else if (word == 10)
		{
			Font::StrDraw(L"私は大星きららよ", 108, 520, 25, c);
		}
		else if (word == 11)
		{
			Font::StrDraw(L"運悪く通り雨に降られ急遽雨宿りしてるの", 108, 520, 25, c);
		}
		else if (word == 12)
		{
			d = 1;
			Font::StrDraw(L"お互い災難だな", 108, 520, 25, c);
		}
		else if (word == 13)
		{
			d = 2;
			Font::StrDraw(L"こっちは私のメイドの岸野奏多よ", 108, 520, 25, c);
		}
		else if (word== 14)
		{
			d = 3;
			Font::StrDraw(L"岸野奏多です。", 108, 520, 25, c);
		}
		else if (word == 15)
		{
			Font::StrDraw(L"きらら様のメイドです", 108, 520, 25, c);
		}
		else if (word== 16)
		{
			d = 0;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"???", 20, 485, 25, c);
			Font::StrDraw(L"人がいっぱいいるよ", 108, 520, 25, c);
		}
		else if (word == 17)
		{
			d = 1;
			Font::StrDraw(L"確かあなたは…", 108, 520, 25, c);
		}
		else if (word == 18)
		{
			d = 3;
			Font::StrDraw(L"生徒会長の北上永遠さんですね", 108, 520, 25, c);
		}
		else if (word == 19)
		{
			d = 4;
			Font::StrDraw(L"そうだよ", 108, 520, 25, c);
		}
		else if (word == 20)
		{
			d = 4;
			Font::StrDraw(L"君は大橋さん家のメイドさんだね", 108, 520, 25, c);
		}
		else if (word == 21)
		{
			d = 3;
			Font::StrDraw(L"岸野奏多です", 108, 520, 25, c);
		}
		else if (word == 22)
		{
			d = 1;
	        Font::StrDraw(L"あ、雨やみ始めてますね",  108, 520, 25, c);
		}
		else if (word == 23)
		{
			d = 2;
			Font::StrDraw(L"奏多!とっとと帰るわよ！",  108, 520, 25, c);
		}
		else if (word == 24)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"かしこまりました。それでは失礼します", 108, 520, 25, c);
		}
		else if (word == 25)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"俺も帰ろう", 108, 520, 25, c);
		}
		else if (word == 26)
		{
			d = 4;
			Font::StrDraw(L"僕も帰らなきゃ", 108, 520, 25, c);
		}
		else if (word == 27)
		{
			d = 1;
			Font::StrDraw(L"ん？", 108, 520, 25, c);
		}
		else if (word == 28)
		{
			Font::StrDraw(L"ドアが開かないぞ", 108, 520, 25, c);
		}
		else if (word == 29)
		{
			d = 2;
			Font::StrDraw(L"そんなわけないでしょ", 108, 520, 25, c);
		}
		else if (word == 30)
		{
			d = 3;
			Font::StrDraw(L"失礼します", 108, 520, 25, c);
		}
		else if (word == 31)
		{
			Font::StrDraw(L"開きませんね", 108, 520, 25, c);
		}
		else if (word == 32)
		{
			d = 4;
			Font::StrDraw(L"本当かい？", 108, 520, 25, c);
		}
		else if (word == 33)
		{
			d = 1;
			Font::StrDraw(L"さて、どうしたものか", 108, 520, 25, c);
		}
		else if (word == 34)
		{
			d = 2;
			Font::StrDraw(L"こっちのドアは開くわよ", 108, 520, 25, c);
		}
		else if (word == 35)
		{
			d = 1;
			Font::StrDraw(L"ならそっちを探索するか？", 108, 520, 25, c);
		}
		else if (word == 36)
		{
			d = 3;
			Font::StrDraw(L"あまりお勧めはしませんね", 108, 520, 25, c);
		}
		else if (word== 37)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"時間がたてば我が家の救助チームが駆け付けますので", 108, 520, 25, c);
			Font::StrDraw(L"しばしお待ちください", 108, 545, 25, c);
		}
		else if (word == 38)
		{
			d = 4;
			g = 2;
			Font::StrDraw(L"でも、こんな機会滅多にないし僕は探索に賛成かな", 108, 520, 25, c);
		}
		else if (word == 39)
		{
			d = 2;
			Font::StrDraw(L"私も探索したいわ", 108, 520, 25, c);
		}
		else if (word == 40)
		{
			Font::StrDraw(L"奏多、救助チームの手配は待ちなさい", 108, 520, 25, c);
		}
		else if (word ==41)
		{
			d = 3;
			Font::StrDraw(L"しかし…", 108, 520, 25, c);
		}
		else if (word == 42)
		{
			d = 2;
			Font::StrDraw(L"奏多！", 108, 520, 25, c);
		}
		else if (word == 43)
		{
			d = 3;
			Font::StrDraw(L"かしこまりました", 108, 520, 25, c);
		}
		else if (word == 44)
		{
			
			Font::StrDraw(L"でしたら私がまず全部屋の安全を確かめます", 108, 520, 25, c);
		}
		else if (word == 45)
		{
			Font::StrDraw(L"その後皆さんに探索してもらうということで…", 108, 520, 25, c);
		}
		else if (word == 46)
		{
			d = 2;
			Font::StrDraw(L"そんなことしたら絶対許さないからね？", 108, 520, 25, c);
		}
		else if (word== 47)
		{
			d = 3;
			Font::StrDraw(L"でしたら正面の部屋の探索ならよろしいでしょう？", 108, 520, 25, c);
		}
		else if (word == 48)
		{
			d = 2;
			Font::StrDraw(L"それならいいわ", 108, 520, 25, c);
		}
		else if (word == 49)
		{
			d = 4;
			Font::StrDraw(L"それじゃあ僕はあっちの部屋を探索するよ", 108, 520, 25, c);
		}
		else if (word == 50)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"お願いしますね先輩", 108, 520, 25, c);
		}
		else if (word == 51)
		{
			d = 4;
		    Font::StrDraw(L"謎の館の探索の開始だー！", 108, 520, 25, c);
		}
		else if (word == 52)
		{
			d = 2;
			Font::StrDraw(L"おー！", 108, 520, 25, c);
		}
		else if (word == 53)
		{
			d = 1;
			Font::StrDraw(L"お、おー…", 108, 520, 25, c);
		}
		else if (word == 54)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"部屋をえらんで探索しよう", 50, 520, 32, c);
			text_loop = false;
		}
	}
	//きららマップ
	//進入時　word=0～10
	//解除後時　word=10～22
	//きららマップ進入時会話-----------------------------------------------------------------------
	else if (text_m == 0)
	{
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 520, 32, c);
		}
		else if (word == 1)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"あ、鳳君！", 108, 520, 25, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"大星？どうしたんだこんな所で", 108, 520, 25, c);
		}
		else if (word == 3)
		{
			d = 2;
			Font::StrDraw(L"この部屋いろいろ調べてんのよ", 108, 520, 25, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"そうか…何か成果はあったか？", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			d = 2;
			Font::StrDraw(L"何も見つからなかったわ…", 108, 520, 25, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"気にするな", 108, 520, 25, c);
		}
		else if (word == 7)
		{
			Font::StrDraw(L"俺も一緒に探すから", 108, 520,25, c);
		}
		else if (word == 8)
		{
			d = 2;
			Font::StrDraw(L"ありがとう", 108, 520, 25, c);
		}
		else if (word == 9)
		{
			Font::StrDraw(L"それじゃあとっとと手掛かり見つけるわよ！", 108, 520, 25, c);
		}
		else if (word == 10)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"探索しよう！", 50, 520, 32, c);
		}
	}
	//きらら答え入力後-----------------------------------------------------------------------
	else if(text_m==3)
	{
		if (word == 10)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 520, 32, c);
		}
		if (word== 11)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"大星！メモ見つけたぞ", 108, 520, 25, c);
		}
		else if (word == 12)
		{
			d = 2;
			Font::StrDraw(L"ほんと？", 108, 520, 25, c);
		}
		else if (word == 13)
		{
			Font::StrDraw(L"結局私何も見つけられなかったわ", 108, 520, 25, c);
		}
		else if (word == 14)
		{
			d = 1;
			Font::StrDraw(L"あんまり気にするなよ？", 108, 520, 25, c);
		}
		else if (word == 15)
		{
			d = 2;
			Font::StrDraw(L"心配ないわ", 108, 520, 25, c);
		}
		else if (word == 16)
		{
			Font::StrDraw(L"今度こそ何か見つけてあげる", 108, 520, 25, c);
		}
		else if (word == 17)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"頑張るのはいいけど無茶するなよ？", 108, 520, 25, c);
		}
		else if (word == 18)
		{
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"俺は違う部屋を探索してくるよ", 108, 520, 25, c);
		}
		else if (word == 19)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"私はもう少しここを探索してるわ", 108, 520, 25, c);
		}
		else if (word == 20)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"いいけど気をつけろよ", 108,520, 25, c);
		}
		else if (word == 21)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"そっちこそ気をつけなさいよ", 108, 520, 25, c);
		}
		else if (word == 22)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"他の部屋を探しに行こう", 50, 520, 32, c);
			text_loop = false;
		}
	}
	//奏多マップ
	//進入時　word=0～13
	//鍵取得時　word=13～18
	//奏多マップ進入時-------------------------------------------------------------------------
	else if (text_m == 1)
	{
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 520, 32, c);
		}
		if (word == 1)
		{
			d = 1;
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"やけに片付いた部屋だな", 108, 520, 25, c);
		}
		else if (word == 2)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"あ、鳳さん。どうかいたしましたか？", 108, 520, 25, c);
		}
		else if (word == 3)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"岸野さんいたんですか", 108, 520, 25, c);
		}
		else if (word == 4)
		{
			d = 3;
			
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"そうかしこまらなくても大丈夫ですよ。同い年ですから", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			g = 1;
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"わかった。で、岸野さんはどうして", 108, 520, 25, c);
			Font::StrDraw(L"はたきを持っているんだ？", 108, 545, 25, c);
		}
		else if (word == 6)
		{
			g = 2;
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"職業上汚い部屋を見ると片付けたくなるんです", 108, 520, 25, c);
		}
		else if (word == 7)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"そっかじゃあ手伝うよ", 108, 520, 25, c);
		}
		else if (word == 8)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"え？いいんですか？", 108, 520, 25, c);
		}
		else if (word == 9)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"部屋の片づけしながら探せばいいよ", 108, 520, 25, c);
		}
		else if (word == 10)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"申し訳ありません。手早く終わらせますので", 108, 520, 25, c);
		}
		else if (word == 11)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"それじゃあ始めようか", 108, 520, 25, c);
		}
		else if (word == 12)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"はい！", 108, 520, 25, c);
		}
		else if (word == 13)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"探索しよう！", 50, 520, 32, c);
		}
	}
    //鍵入手後-----------------------------------------------------------------------
	else if (text_m == 4)
	{
		if (word == 13)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 520, 32, c);
		}
		else if (word == 14)
		{
			d = 1;
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"何かのメモだな", 108, 520, 25, c);
		}
		else if (word == 15)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"なんでしょうね", 108, 520, 25, c);
		}
		else if (word == 16)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"とりあえず他の部屋も見回って来るよ", 108, 520, 25, c);
		}
		else if (word == 17)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"わかりました。お嬢様をよろしくお願いします", 108, 520, 25, c);
		}
		else if (word == 18)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"他の部屋を探しに行こう", 50, 520, 32, c);
			text_loop = false;
		}
	}
	//永遠マップ-----------------------------------------------------------------------
	//進入時　word=0～9
	//メモ取得時　word=9～19
	//永遠マップ進入時-------------------------------------------------------------------------
	else if (text_m == 2)
	{
		if (word == 0)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 520, 32, c);
		}
		else if (word == 1)
		{
			d = 4;
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"君、どうかしたのかな？", 108, 520, 25, c);
		}
		else if (word == 2)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"北上先輩ですか。この部屋に何かありました？", 108, 520, 25, c);
		}
		else if (word == 3)
		{
			d = 4;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"まだ何にも見つかってないんだ", 108, 520, 25, c);
		}
		else if (word == 4)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"そうだ！", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"探すの一緒に手伝ってよ", 108, 520, 25, c);
		}
		else if (word == 6)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"わかりました。俺でよければ手伝いますよ", 108, 520, 25, c);
		}
		else if (word == 7)
		{
			d = 4;
			g = 2;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"ありがとう。", 108, 520, 25, c);
		}
		else if (word == 8)
		{
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"それじゃよろしく！", 108, 520, 25, c);
		}
		else if (word == 9)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"探索しよう！", 50, 520, 32, c);
		}
	}
	//永遠マップ解除時-------------------------------------------------------------------------
	else if (text_m == 5)
		{
			if (word == 9)
			{
				text_move = true;
				Font::StrDraw(L"Zキーで会話進行", 50, 520, 32, c);
			}
			else if (word == 10)
			{
				d = 4;
				g = 2;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"これは何かのメモかな?", 108, 520, 25, c);
			}
			else if (word == 11)
			{
				d = 1;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"みたいですね", 108, 520, 25, c);
			}
			else if (word == 12)
			{
				d = 4;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"もしかしたら他にも何かあるかもしれないね", 108, 520, 25, c);
			}
			else if (word == 13)
			{
				d = 1;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"ですね。もっとこの部屋調べてみましょうか", 108, 520, 25, c);
			}
			else if (word == 14)
			{
				d = 4;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"鳳君は他の部屋を調べに行ってみてよ", 108, 520, 25, c);
			}
			else if (word == 15)
			{
				d = 1;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"大丈夫ですか？", 108, 520, 25, c);
			}
			else if (word == 16)
			{
				d = 4;
				Draw::Draw(52, &src, &dst, c, 0.0f);
				Font::StrDraw(L"僕は生徒会長なんだよ?大丈夫だよ", 108, 520, 25, c);
			}
			else if (word == 17)
			{
				d = 1;
				Draw::Draw(4, &src, &dst, c, 0.0f);
				Font::StrDraw(L"わかりました。先輩も気を付けて", 108, 520, 25, c);
			}
			else if (word == 18)
			{
				d = 4;
				Draw::Draw(52, &src, &dst, c, 0.0f);
			    Font::StrDraw(L"任せて", 108, 520, 25, c);
			}
			else if (word == 19)
			{
				d = 0;
				g = 3;
				text_move = false;
				Font::StrDraw(L"他の部屋を探しに行こう", 50, 520, 32, c);
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
		if (word == 0)
		{
			d = 1;
			g = 2;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"3つのメモがそろったみたいだな", 108, 520, 25, c);
		}
		else if (word == 1)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"やったわね", 108, 520, 25, c);
		}
		else if (word == 2)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"それでメモにはなんて書いているんですか?", 108, 520, 25, c);
		}
		else if (word== 3)
		{
			g = 1;
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"「ミスミソウ」「イフェイオン」", 108, 520, 25, c);
			Font::StrDraw(L"「サクラソウ」だな", 108, 545, 25, c);
		}
		else if (word == 4)
		{
			d = 2;
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"イフェイオン？", 108, 520, 25, c);
		}
		else if (word == 5)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"なによそれ", 108, 520, 25, c);
		}
		else if (word == 6)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"探索しよう！", 50, 520, 32, c);
		}
	}
	//２階層-----------------------------------------------------------------------
	else if (text_m == 7)
	{
		if (word == 6)
		{
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", 50, 520, 32, c);
		}
		else if (word == 7)
		{
			d = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"二階に来たのはいいけどこれじゃ出られないわよ？", 108, 520, 25, c);
		}
		if (word == 8)
		{
			g = 1;
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"この階に何か手掛かりがあるんじゃないかな", 108, 520, 25, c);
			Font::StrDraw(L"あるんじゃないかな", 108, 545, 25, c);
		}
		else if (word == 9)
		{
			d = 4;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"それじゃこの部屋も", 108, 520, 25, c);
			Font::StrDraw(L"分かれて探す感じでいいかな？", 108, 545, 25, c);
		}
		else if (word == 10)
		{
			d = 2;
			g = 2;
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"なら私はこっちに行くわ！", 108, 520, 25, c);
		}
		else if (word == 11)
		{
			Draw::Draw(50, &src, &dst, c, 0.0f);
			Font::StrDraw(L"奏多はあっちを調べなさい！", 108, 520, 25, c);
		}
		else if (word == 12)
		{
			d = 3;
			Draw::Draw(51, &src, &dst, c, 0.0f);
			Font::StrDraw(L"かしこまりました", 108, 520, 25, c);
		}
		else if (word == 13)
		{
			d = 4;
			Draw::Draw(52, &src, &dst, c, 0.0f);
			Font::StrDraw(L"それじゃあ僕は残りの部屋を調べようかな", 108, 520, 25, c);
		}
		if (word == 14)
		{
			d = 1;
			Draw::Draw(4, &src, &dst, c, 0.0f);
			Font::StrDraw(L"(俺は誰かを手伝いに行こう）", 108, 520, 25, c);
		}
		if (word == 15)
		{
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"部屋をえらんで探索しよう", 50, 520, 32, c);
			text_loop = false;
		}
	}
	if (d == 1)
	{
		Font::StrDraw(L"鳳", 20, 485, 25, c);
		Draw::Draw(4, &src, &dst, c, 0.0f);
	}
	else if (d == 2)
	{
		Font::StrDraw(L"きらら", 20, 485, 25, c);
		Draw::Draw(50, &src, &dst, c, 0.0f);
	}
	else if (d == 3)
	{
		Font::StrDraw(L"奏多", 20, 485, 25, c);
		Draw::Draw(51, &src, &dst, c, 0.0f);
	}
	else if (d == 4)
	{
		Font::StrDraw(L"永遠", 20, 485, 25, c);
		Draw::Draw(52, &src, &dst, c, 0.0f);
	}
	//テキスト移動
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
		//テキスト表示隠し(下部）描画表示位置
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
	//テキスト移動
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
		//テキスト表示隠し(下部）描画表示位置
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
	//テキスト移動
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
	//現在位置表示
	if (text_m == -2 || text_m == -1||text_m==6)
	{
		Font::StrDraw(L"1F 玄関", 700, 493, 13, c);
	}
	else if (text_m ==-3|| text_m == 0 || text_m == 3  )
	{
		Font::StrDraw(L"1F 居間", 700, 493, 13, c);
	}
	else if (text_m == -4 || text_m == 1 || text_m == 4)
	{
		Font::StrDraw(L"1F 図書室", 700, 493, 13, c);
	}
	else if (text_m == -5 || text_m == 2 || text_m == 5)
	{
		Font::StrDraw(L"1F 和室", 700, 493, 13, c);
	}
	else if (text_m == 7)
	{
		Font::StrDraw(L"2F", 700, 493, 13, c);
	}
	//暗転
	if (text_m == -1 && word == 0 || text_m == -1 && word == 1 || text_m == -1 && word == 2)
	{
		Draw::Draw(12, &src_A, &dst_A, c, 0.0f);
	}
}