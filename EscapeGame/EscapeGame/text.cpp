//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "stdio.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include"text.h"
//使用するネームスペース
using namespace GameL;

bool text_hide = false;//テキスト隠し表示確認用
bool hero_move=false;//ヒーローの動作確認用
bool text_move=true;//テキストの動作確認用
int anime_move = 0;//アニメ―ション番号
int word=0;//テキスト番号
bool skip_anime = false;//アニメーション中テキストを進めなくするフラグ
int item_word = 0;
//イニシャライズ
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
//ドロー
void CObjText::Draw()
{
	//描画カラー情報
	float c[4] = { 0.3f,0.3f,0.3f,1.0f };
	float c_C[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c_A[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c_D[4] = { 1.0f,1.0f,1.0f,1.0f };
	int x = 180;//テキスト用x軸
	int y_a = 500;//テキスト上部用y軸
	int y_b = 550;//テキスト下部用y軸
	int m_z = 25;//テキスト大きさ
	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画表示位置
	RECT_F src_A; //暗転元切り取り位置
	RECT_F dst_A; //暗転描画表示位置
	RECT_F src_B;//テキスト表示隠し(上部）描画元切り取り位置
	RECT_F dst_B;//テキスト表示隠し(上部）描画表示位置
	RECT_F src_C;//テキスト表示隠し(下部）描画元切り取り位置
	RECT_F dst_C;//テキスト表示隠し(下部）描画表示位置
	RECT_F src_D;//下暗転描画元切り取り位置
	RECT_F dst_D;//下暗転描画表示位置
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
	Font::StrDraw(L"十字キー：移動", 650, 370, 15, c_C);
	Font::StrDraw(L"Zキー：", 650, 390, 15, c_C);
	Font::StrDraw(L"決定・会話進行", 650, 410, 15, c_C);
	Font::StrDraw(L"テンキー：", 650, 430, 15, c_C);
	Font::StrDraw(L"入手アイテム詳細", 650, 450, 15, c_C);

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
			m_z = 30;
			Font::StrDraw(L"大星きららはメイドの岸野奏多と", x, y_a, m_z, c);
			Font::StrDraw(L"下校していると突然雨が降ってきた", x, y_b, m_z, c);
		}
		else if (word == 2)
		{
			m_z = 30;
			Font::StrDraw(L"二人はたまたま近くにあった館で", x, y_a, m_z, c);
			Font::StrDraw(L"雨宿りすることにしたのであった", x, y_b, m_z, c);
		}
		else if (word == 3)
		{
			m_z = 25;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 2;
			g = 2;
			Font::StrDraw(L"ねえ奏多…雨いつやむかな？", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			c_A[3] = 1.0f;
			d = 3;
			Font::StrDraw(L"この感じだとすぐやむと思いますが", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			c_D[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_D, &dst_D, c_D, 0.0f);
			skip_anime = true;
			anime_move = 1;
			d = 1;
			Font::StrDraw(L"ここなら雨宿りできそうだな…", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 2;
			Font::StrDraw(L"誰!?", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 1;
			Font::StrDraw(L"先客がいたのか", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			Font::StrDraw(L"俺の名前は鳳一樹。君と同じ学校の二年だ", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			d = 2;
			Font::StrDraw(L"あ、センパイですか？", x, y_a, m_z, c);
		}
		else if (word == 10)
		{
			Font::StrDraw(L"私は大星きららよ", x, y_a, m_z, c);
		}
		else if (word == 11)
		{
			Font::StrDraw(L"運悪く通り雨に降られ急遽雨宿りしてるの", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			d = 1;
			Font::StrDraw(L"お互い災難だな", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			d = 2;
			Font::StrDraw(L"こっちは私のメイドの岸野奏多よ", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			d = 3;
			Font::StrDraw(L"岸野奏多です。", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			Font::StrDraw(L"きらら様のメイドです", x, y_a, m_z, c);
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
			Font::StrDraw(L"人がいっぱいいるよ", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			f = false;
			d = 1;
			Font::StrDraw(L"確かあなたは…", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 3;
			Font::StrDraw(L"生徒会長の北上永遠さんですね", x, y_a, m_z, c);
		}
		else if (word == 19)
		{
			d = 4;
			Font::StrDraw(L"そうだよ", x, y_a, m_z, c);
		}
		else if (word == 20)
		{
			d = 4;
			Font::StrDraw(L"君は大橋さん家のメイドさんだね", x, y_a, m_z, c);
		}
		else if (word == 21)
		{
			d = 3;
			Font::StrDraw(L"岸野奏多です", x, y_a, m_z, c);
		}
		else if (word == 22)
		{
			d = 1;
			Font::StrDraw(L"あ、雨やみ始めてますね", x, y_a, m_z, c);
		}
		else if (word == 23)
		{
			d = 2;
			Font::StrDraw(L"奏多!とっとと帰るわよ！", x, y_a, m_z, c);
		}
		else if (word == 24)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"かしこまりました。それでは失礼します", x, y_a, m_z, c);
		}
		else if (word == 25)
		{
			skip_anime = true;
			anime_move = 3;
			d = 1;
			g = 2;
			Font::StrDraw(L"俺も帰ろう", x, y_a, m_z, c);
		}
		else if (word == 26)
		{
			d = 4;
			Font::StrDraw(L"僕も帰らなきゃ", x, y_a, m_z, c);
		}
		else if (word == 27)
		{
			d = 1;
			Font::StrDraw(L"ん？", x, y_a, m_z, c);
		}
		else if (word == 28)
		{
			Font::StrDraw(L"ドアが開かないぞ", x, y_a, m_z, c);
		}
		else if (word == 29)
		{
			d = 2;
			Font::StrDraw(L"そんなわけないでしょ", x, y_a, m_z, c);
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
			Font::StrDraw(L"失礼します", x, y_a, m_z, c);
		}
		else if (word == 31)
		{
			f = false;
			Font::StrDraw(L"開きませんね", x, y_a, m_z, c);
		}
		else if (word == 32)
		{
			d = 4;
			Font::StrDraw(L"本当かい？", x, y_a, m_z, c);
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
			Font::StrDraw(L"さて、どうしたものか", x, y_a, m_z, c);
		}
		else if (word == 34)
		{
			f = false;
			d = 2;
			Font::StrDraw(L"こっちのドアは開くわよ", x, y_a, m_z, c);
		}
		else if (word == 35)
		{
			d = 1;
			Font::StrDraw(L"ならそっちを探索するか？", x, y_a, m_z, c);
		}
		else if (word == 36)
		{
			d = 3;
			Font::StrDraw(L"あまりお勧めはしませんね", x, y_a, m_z, c);
		}
		else if (word == 37)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"時間がたてば我が家の救助チームが", x, y_a, m_z, c);
			Font::StrDraw(L"駆け付けますのでしばしお待ちください", x, y_b, m_z, c);
		}
		else if (word == 38)
		{
			d = 4;
			Font::StrDraw(L"でも、こんな機会滅多にないし", x, y_a, m_z, c);
			Font::StrDraw(L"僕は探索に賛成かな", x, y_b, m_z, c);
		}
		else if (word == 39)
		{
			g = 2;
			d = 2;
			Font::StrDraw(L"私も探索したいわ", x, y_a, m_z, c);
		}
		else if (word == 40)
		{
			Font::StrDraw(L"奏多、救助チームの手配は待ちなさい", x, y_a, m_z, c);
		}
		else if (word == 41)
		{
			d = 3;
			Font::StrDraw(L"しかし…", x, y_a, m_z, c);
		}
		else if (word == 42)
		{
			d = 2;
			Font::StrDraw(L"奏多！", x, y_a, m_z, c);
		}
		else if (word == 43)
		{
			d = 3;
			Font::StrDraw(L"かしこまりました", x, y_a, m_z, c);
		}
		else if (word == 44)
		{
			g = 1;
			Font::StrDraw(L"でしたら私がまず", x, y_a, m_z, c);
			Font::StrDraw(L"全部屋の安全を確かめます", x, y_b, m_z, c);
		}
		else if (word == 45)
		{
			Font::StrDraw(L"その後皆さんに", x, y_a, m_z, c);
			Font::StrDraw(L"探索してもらうということで…", x, y_b, m_z, c);
		}
		else if (word == 46)
		{
			g = 2;
			d = 2;
			Font::StrDraw(L"そんなことしたら絶対許さないからね？", x, y_a, m_z, c);
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
			Font::StrDraw(L"でしたら正面の部屋の", x, y_a, m_z, c);
			Font::StrDraw(L"探索ならよろしいでしょう？", x, y_b, m_z, c);
		}
		else if (word == 48)
		{
			g = 2;
			f = false;
			d = 2;
			Font::StrDraw(L"それならいいわ", x, y_a, m_z, c);
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
			Font::StrDraw(L"それじゃあ僕はあっちの部屋を探索するよ", x, y_a, m_z, c);
		}
		else if (word == 50)
		{
			f = false;
			d = 2;
			g = 2;
			Font::StrDraw(L"お願いしますね先輩", x, y_a, m_z, c);
		}
		else if (word == 51)
		{
			d = 4;
			Font::StrDraw(L"謎の館の探索の開始だー！", x, y_a, m_z, c);
		}
		else if (word == 52)
		{
			d = 2;
			Font::StrDraw(L"おー！", x, y_a, m_z, c);
		}
		else if (word == 53)
		{
			d = 1;
			Font::StrDraw(L"お、おー…", x, y_a, m_z, c);
		}
		else if (word == 54 && item_word == 0)
		{
			hero_move = true;
			anime_move = 8;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"部屋をえらんで探索しよう", x, y_a, 32, c);
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
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"あ、鳳君！", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"大星？どうしたんだこんな所で", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 2;
			Font::StrDraw(L"この部屋いろいろ調べてんのよ", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"そうか…何か成果はあったか？", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 2;
			Font::StrDraw(L"何も見つからなかったわ…", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"気にするな", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			Font::StrDraw(L"俺も一緒に探すから", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 2;
			Font::StrDraw(L"ありがとう", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			Font::StrDraw(L"それじゃあとっとと手掛かり見つけるわよ！", x, y_a, m_z, c);
		}
		else if (word == 10 && text_hide == false && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"探索しよう！", x, y_a, 32, c);
		}
	}
	//きらら答え入力後-----------------------------------------------------------------------
	else if (text_m == 3)
	{
		if (word == 11)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		if (word == 12)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"大星！メモ見つけたぞ", x, y_a, m_z, c);
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
			Font::StrDraw(L"ほんと？", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			f - false;
			Font::StrDraw(L"結局私何も見つけられなかったわ", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			d = 1;
			Font::StrDraw(L"あんまり気にするなよ？", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 2;
			Font::StrDraw(L"心配ないわ", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			Font::StrDraw(L"今度こそ何か見つけてあげる", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 1;
			Font::StrDraw(L"頑張るのはいいけど無茶するなよ？", x, y_a, m_z, c);
		}
		else if (word == 19)
		{
			Font::StrDraw(L"俺は違う部屋を探索してくるよ", x, y_a, m_z, c);
		}
		else if (word == 20)
		{
			d = 2;
			Font::StrDraw(L"私はもう少しここを探索してるわ", x, y_a, m_z, c);
		}
		else if (word == 21)
		{
			d = 1;
			Font::StrDraw(L"いいけど気をつけろよ", x, y_a, m_z, c);
		}
		else if (word == 22)
		{
			d = 2;
			Font::StrDraw(L"そっちこそ気をつけなさいよ", x, y_a, m_z, c);
		}
		else if (word == 23 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"他の部屋を探しに行こう", x, y_a, 32, c);
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
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		if (word == 1)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"やけに片付いた部屋だな", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 3;
			Font::StrDraw(L"あ、鳳さん。どうかいたしましたか？", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 1;
			Font::StrDraw(L"岸野さんいたんですか", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"そうかしこまらなくても大丈夫ですよ。", x, y_a, m_z, c);
			Font::StrDraw(L"同い年ですから", x, y_b, m_z, c);
		}
		else if (word == 5)
		{
			d = 1;
			Font::StrDraw(L"わかった。で、岸野さんはどうして", x, y_a, m_z, c);
			Font::StrDraw(L"はたきを持っているんだ？", x, y_b, m_z, c);
		}
		else if (word == 6)
		{
			g = 2;
			d = 3;
			Font::StrDraw(L"職業上汚い部屋を見ると片付けたくなるんです", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 1;
			Font::StrDraw(L"そっかじゃあ手伝うよ", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 3;
			Font::StrDraw(L"え？いいんですか？", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			d = 1;
			Font::StrDraw(L"部屋の片づけしながら探せばいいよ", x, y_a, m_z, c);
		}
		else if (word == 10)
		{
			d = 3;
			Font::StrDraw(L"申し訳ありません。手早く終わらせますので", x, y_a, m_z, c);
		}
		else if (word == 11)
		{
			d = 1;
			Font::StrDraw(L"それじゃあ始めようか", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			d = 3;
			Font::StrDraw(L"はい！", x, y_a, m_z, c);
		}
		else if (word == 13&&item_word==0)
		{
			d = 0;
			g = 3;
			hero_move = true;
			text_move = false;
			Font::StrDraw(L"探索しよう！", x, y_a, 32, c);
		}
	}
	//鍵入手後-----------------------------------------------------------------------
	else if (text_m == 4)
	{
		if (word == 14)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 15)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"何かのメモだな", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 3;
			Font::StrDraw(L"なんでしょうね", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			d = 1;
			Font::StrDraw(L"とりあえず他の部屋も見回って来るよ", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 3;
			Font::StrDraw(L"わかりました。お嬢様をよろしくお願いします", x, y_a, m_z, c);
		}
		else if (word == 19 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"他の部屋を探しに行こう", x, y_a, 32, c);
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
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 4;
			g = 2;
			Font::StrDraw(L"君、どうかしたのかな？", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"北上先輩ですか。この部屋に何かありました？", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 4;
			Font::StrDraw(L"まだ何にも見つかってないんだ", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			Font::StrDraw(L"そうだ！", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			Font::StrDraw(L"探すの一緒に手伝ってよ", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"わかりました。俺でよければ手伝いますよ", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 4;
			g = 2;
			Font::StrDraw(L"ありがとう。", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			Font::StrDraw(L"それじゃよろしく！", x, y_a, m_z, c);
		}
		else if (word == 9 && text_hide == false && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"探索しよう！", x, y_a, 32, c);
		}
	}
	//永遠マップ解除時-------------------------------------------------------------------------
	else if (text_m == 5)
	{
		if (word == 10)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 11)
		{
			d = 4;
			g = 2;
			Font::StrDraw(L"これは何かのメモかな?", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			d = 1;
			Font::StrDraw(L"みたいですね", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			d = 4;
			Font::StrDraw(L"もしかしたら他にも何かあるかもしれないね", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			d = 1;
			Font::StrDraw(L"ですね。もっとこの部屋調べてみましょうか", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			d = 4;
			Font::StrDraw(L"鳳君は他の部屋を調べに行ってみてよ", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 1;
			Font::StrDraw(L"大丈夫ですか？", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			d = 4;
			Font::StrDraw(L"僕は生徒会長なんだよ?大丈夫だよ", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 1;
			Font::StrDraw(L"わかりました。先輩も気を付けて", x, y_a, m_z, c);
		}
		else if (word == 19)
		{
			d = 4;
			Font::StrDraw(L"任せて", x, y_a, m_z, c);
		}
		else if (word == 20 && item_word == 0)
		{
			d = 0;
			g = 3;
			text_move = false;
			hero_move = true;
			Font::StrDraw(L"他の部屋を探しに行こう", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//幕間
	//１階層-----------------------------------------------------------------------
	else if (text_m == 6)
	{
		if (word == 0)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 1;
			g = 2;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			Font::StrDraw(L"3つのメモがそろったみたいだな", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			c_A[3] = 1.0;
			d = 2;
			Font::StrDraw(L"やったわね", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 3;
			Font::StrDraw(L"それでメモにはなんて書いているんですか?", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			g = 1;
			d = 1;
			Font::StrDraw(L"「ミスミソウ」「イフェイオン」", x, y_a, m_z, c);
			Font::StrDraw(L"「サクラソウ」だな", x, y_b, m_z, c);
		}
		else if (word == 5)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"イフェイオン？", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 2;
			Font::StrDraw(L"なによそれ", x, y_a, m_z, c);
		}
		else if (word == 7 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"探そう！", x, y_a, 32, c);
		}
	}
	//２階層-----------------------------------------------------------------------
	else if (text_m == 7)
	{
		if (word == 0)
		{
			anime_move = 0;
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			g = 1;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 2;
			Font::StrDraw(L"二階に来たのはいいけど", x, y_a, m_z, c);
			Font::StrDraw(L"これじゃ出られないわよ？", x, y_b, m_z, c);
		}
		if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"この階に何か手掛かりが", x, y_a, m_z, c);
			Font::StrDraw(L"あるんじゃないかな", x, y_b, m_z, c);
		}
		else if (word == 3)
		{
			d = 4;
			Font::StrDraw(L"それじゃこの部屋も", x, y_a, m_z, c);
			Font::StrDraw(L"分かれて探す感じでいいかな？", x, y_b, m_z, c);
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
			Font::StrDraw(L"なら私はこっちに行くわ！", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			f = false;
			Font::StrDraw(L"奏多はあっちを調べなさい！", x, y_a, m_z, c);
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
			Font::StrDraw(L"かしこまりました", x, y_a, m_z, c);
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
			Font::StrDraw(L"それじゃあ僕は残りの部屋を調べようかな", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			f = false;
			anime_move = 4;
			d = 1;
			Font::StrDraw(L"(俺は誰かを手伝いに行こう）", x, y_a, m_z, c);
		}
		else if (word ==9 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"部屋をえらんで探索しよう", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//2階層きらら部屋-------------------------------------------------

	//

	//2階層奏多部屋-------------------------------------------------
	else if (text_m == 10)
	{
		if (word == 0)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 3;
			g = 2;
			Font::StrDraw(L"ここの部屋も片付けがいがありますね", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"岸野さん俺も手伝うよ", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 3;
			Font::StrDraw(L"鳳君どうしてここに？", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"岸野さんを手伝おうと思って", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"私としてはありがたいのですが", x, y_a, m_z, c);
			Font::StrDraw(L"いいのですか？", x, y_b, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"別に部屋は三つしかなかったんだから", x, y_a, m_z, c);
			Font::StrDraw(L"誰かの手伝いは確定だったんだ", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			Font::StrDraw(L"なら片付けを始めそうな", x, y_a, m_z, c);
			Font::StrDraw(L"岸野さんを手伝うことにしただけだよ", x, y_b, m_z, c);
		}
		else if (word == 8)
		{
			d = 3;
			g = 2;
			Font::StrDraw(L"ありがとうございます", x, y_a, m_z, c);
		}
		else if(word==9)
		{
			g = 1;
			Font::StrDraw(L"それならお嬢様を待たせてもいけませんし", x, y_a, m_z, c);
			Font::StrDraw(L"手早くやってしまいましょう", x, y_b, m_z, c);
		}
		else if (word == 10)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"わかった", x, y_a, m_z, c);
		}
		else if (word == 11 && item_word == 0)
		{

			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"整理しよう！", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//ここから倉庫番-----------------------------------------------
	//倉庫番終了後-------------------------------------------------
	if (text_m == 11)
	{
		if (word == 0)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"部屋の整理完了だな", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"物がやけに多いと思ったら", x, y_a, m_z, c);
			Font::StrDraw(L"ここ物置部屋みたいですね", x, y_b, m_z, c);
		}
		else if (word == 3)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"ところで奥のほうで鍵を見つけたぞ", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 3;
			Font::StrDraw(L"本当ですか？", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			g = 1;
			Font::StrDraw(L"それならお嬢様たちを", x, y_a, m_z, c);
			Font::StrDraw(L"集めて早く帰りましょう", x, y_b, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"なら俺が先に本物か調べてくるから", x, y_a, m_z, c);
			Font::StrDraw(L"岸野さんはみんなを呼んでおいてくれないか?", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			d = 3;
			g = 2;
			Font::StrDraw(L"わかりました", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			Font::StrDraw(L"入口の方はお願いしますね", x, y_a, m_z, c);
		}
		else if (word == 9 && item_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"1階玄関に向かおう！", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//2階層永遠部屋-------------------------------------------------
	
	//

	//エンディング　きらら-------------------------------------------

	//エンディング　奏多---------------------------------------------
	if (text_m == 15)
	{
		if (word == 0)
		{
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 3;
			g = 2;
			Font::StrDraw(L"鳳君", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"どうしたんだ?", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 3;
			Font::StrDraw(L"将来うちの執事になりませんか?", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"どうかした?", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 3;
			Font::StrDraw(L"将来うちの執事になりませんか?", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"急にどうしたんだ?", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 3;
			g = 1;
			Font::StrDraw(L"今うちに執事がいないのと", x, y_a, m_z, c);
			Font::StrDraw(L"鳳君の手際の良さを考慮した結果ですね", x, y_b, m_z, c);
		}
		else if (word == 8)
		{
			d = 2;
			Font::StrDraw(L"まあ今回鍵を見つけたのは鳳君らしいし", x, y_a, m_z, c);
			Font::StrDraw(L"奏多が選んだのなら別に構わないわ", x, y_b, m_z, c);
		}
		else if (word == 9)
		{
			d = 3;
			Font::StrDraw(L"…一緒にお仕事できるなら", x, y_a, m_z, c);
			Font::StrDraw(L"私もうれしいですしね", x, y_b, m_z, c);
		}
		else if (word == 10)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"岸野さんどうかした?", x, y_a, m_z, c);
		}
		else if (word == 11)
		{
			d = 3;
			Font::StrDraw(L"いえ何でもありません", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			Font::StrDraw(L"返事は後日で結構です", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			Font::StrDraw(L"いい返事を期待しています", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			Font::StrDraw(L"それではお嬢様帰りましょう", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			d = 2;
			Font::StrDraw(L"奏多の機嫌がいいけど何かあったの?", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 1;
			Font::StrDraw(L"さあ?", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			d = 2;
			Font::StrDraw(L"帰りましょうか", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 1;
			Font::StrDraw(L"そうだな", x, y_a, m_z, c);
		}
	}
	//エンディング　永遠---------------------------------------------

	//エンドロール---------------------------------------------------

	//名前欄---------------------------------------------------------
	if (d == 1)
	{
		if (text_m == -1 && word == 5 || text_m == -1 && word == 7 || text_m == -1 && word == 8)
		{
			Font::StrDraw(L"???", 30, 560, 25, c);
		}
		else
		{
			Font::StrDraw(L"鳳", 39, 560, 20, c);
		}
		Draw::Draw(4, &src, &dst, c_C, 0.0f);
	}
	else if (d == 2)
	{
		Font::StrDraw(L"きらら", 20, 560, 20, c);
		Draw::Draw(50, &src, &dst, c_C, 0.0f);
	}
	else if (d == 3)
	{
		Font::StrDraw(L"奏多", 30, 560, 20, c);
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
			Font::StrDraw(L"永遠", 30, 560, 20, c);
		}
		Draw::Draw(52, &src, &dst, c_C, 0.0f);
	}
	//物調べた時集
	//空の棚
	if (item_word == 1)
	{
		Font::StrDraw(L"たくさんの本が収納されている", x, y_a, m_z, c);
	}
	//花の本が入っている本棚
	else if (item_word == 2)
	{
		Font::StrDraw(L"花の本が収納されている", x, y_a, m_z, c);
	}
	//壺
	else if (item_word == 3)
	{
		Font::StrDraw(L"高そうな壺がある", x, y_a, m_z, c);
	}
	//観葉植物
	else if (item_word == 4)
	{
		Font::StrDraw(L"観葉植物が置いてある", x, y_a, m_z, c);
	}
	//空のタンス
	else if (item_word == 5)
	{
		Font::StrDraw(L"中に何も入ってないようだ", x, y_a, m_z, c);
	}
	else if (item_word == 6)
	{
		Font::StrDraw(L"2段のタンスのようだ", x, y_a, m_z, c);
	}

	//テキスト移動2行用
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
		//テキスト表示隠し(下部）描画表示位置
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
	//テキスト移動1行用
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
	//現在位置表示
	if (text_m == -2 || text_m == -1 || text_m == 6)
	{
		Font::StrDraw(L"1F", 730, 503, 30, c);
		Font::StrDraw(L"玄関", 700, 553, 30, c);
	}
	else if (text_m == -3 || text_m == 0 || text_m == 3)
	{
		Font::StrDraw(L"1F", 730, 503, 30, c);
		Font::StrDraw(L"居間", 700, 553, 30, c);
	}
	else if (text_m == -4 || text_m == 1 || text_m == 4)
	{
		Font::StrDraw(L"1F", 730, 503, 30, c);
		Font::StrDraw(L"図書室", 700, 553, 30, c);
	}
	else if (text_m == -5 || text_m == 2 || text_m == 5)
	{
		Font::StrDraw(L"1F", 730, 503, 30, c);
		Font::StrDraw(L"和室", 700, 553, 30, c);
	}
	else if (text_m == 7)
	{
		Font::StrDraw(L"2F", 730, 503, 30, c);
	}
	//暗転
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