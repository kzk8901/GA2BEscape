//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\\Audio.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include "ObjBGMusic.h"
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
int kirara_word=0;
int kanata_word=0;
int towa_word=0;
bool kirara_flag=false;
bool kanata_flag = false;
bool towa_flag = false;
bool gate_flag=false;
int kirara_num = 0;
int kanata_num = 0;
int towa_num = 0;
bool kirara_anger = false;
bool kanata_anger = false;
bool towa_anger = false;
void CObjText::Init()
{
	m_key_flag = false;
	time = 230;
	time_x = -1;
	anime_flag = false;
	skip_flag = false;
	g = 1;
	d = 0;
	f = false;
	ending = false;
	end_time = 0;
	kirara_count = 0;
	kanata_count = 0;
	towa_count = 0;
	onceSE = false;
	twiceSE = false;
}
//アクション
void CObjText::Action()
{
	time += 1;
	time_x -= 1;
	end_time += 1;
	//オープニング　-1
	//きらら　-3 0 3
	//奏多 -4 1 4
	//永遠 -5 2 5
    //幕間 6 7
	if (Input::GetVKey('Z') == true)
		{
		 if (Input::GetVKey(VK_RIGHT) == false&& Input::GetVKey(VK_LEFT) == false && Input::GetVKey(VK_UP) == false && Input::GetVKey(VK_DOWN) == false )
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
								if (text_m == 0  && word <10|| text_m == 3  && word <23|| text_m == 1  && word <13||
									text_m == 2  && word <9 || text_m == -1 && word <54|| text_m == 5  && word <20||
									text_m == 4  && word <19|| text_m == 7  && word <9 || text_m == 6  && word <7 ||
									text_m == 8  && word <11|| text_m == 9  && word <9 || text_m == 10 && word <11||
									text_m == 11 && word <9 || text_m == 12 && word <11|| text_m == 13 && word <9 ||
									text_m == 14 && word <18|| text_m == 15 && word <19|| text_m == 16 && word <16)
								{
									word += 1;
									m_key_flag = false;
									time = 0;
									skip_flag = true;
								}
								if (kirara_flag == true)
								{
									kirara_word += 1;
									m_key_flag = false;
									time = 0;
									skip_flag = true;
									if (kirara_count == 2)
									{
										kirara_anger = true;
									}
									if (kirara_word == 1)
									{
										kirara_count += 1;
									}
								}
								else if (kanata_flag == true)
								{
									kanata_word += 1;
									m_key_flag = false;
									time = 0;
									skip_flag = true;
									if (kanata_count == 2)
									{
										kanata_anger = true;
									}
									if (kanata_word == 1)
									{
										kanata_count += 1;
									}
								}
								else if (towa_flag == true)
								{
									towa_word += 1;
									m_key_flag = false;
									time = 0;
									skip_flag = true;
									if (towa_count == 2)
									{
										towa_anger = true;
									}
									if (towa_word == 1)
									{
										towa_count += 1;
									}
								}
							}
						}
					}
				}
				else if (time < 210)
				{
					time = 210;
				}
				else if (time > 230 && time_x < 210 && time_x>0)
				{
					time_x = 0;
				}
				else if (time > 230 && time_x < -20)
				{
					skip_flag = false;
				}
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
	//BGM切り替え用情報取得
	CObjBGMusic* bgm = (CObjBGMusic*)Objs::GetObj(OBJ_AUDIO);

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
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 490.0f;
	dst.m_left = 10.0f;
	dst.m_right = 95.0f;
	dst.m_bottom = 570.0f;
	src_A.m_top = 0.0f;
	src_A.m_left = 0.0f;
	src_A.m_right = 32.0f;
	src_A.m_bottom = 32.0f;
	dst_A.m_top = 0.0f;
	dst_A.m_left = 0.0f;
	dst_A.m_right = 640.0f;
	dst_A.m_bottom = 480.0f;
	if (text_m == 10)
	{
		Font::StrDraw(L"Rキー：リセット", 650, 310, 15, c_C);
	}
	Font::StrDraw(L"十字キー:", 650, 330, 15, c_C);
	Font::StrDraw(L"移動", 650, 350, 15, c_C);
	Font::StrDraw(L"Zキー:", 650, 370, 15, c_C);
	Font::StrDraw(L"決定・話しかける", 650, 390, 15, c_C);
	Font::StrDraw(L"会話進行・調べる", 650, 410, 15, c_C); 
	Font::StrDraw(L"テンキー:", 650, 430, 15, c_C);
	Font::StrDraw(L"入手アイテム詳細", 650, 450, 15, c_C);
	Font::StrDraw(L"1", 645, 30, 15, c_C);
	Font::StrDraw(L"2", 645, 94, 15, c_C);
	Font::StrDraw(L"3", 645, 158, 15, c_C);
	Font::StrDraw(L"4", 645, 222, 15, c_C);
	Font::StrDraw(L"5", 785, 30, 15, c_C);
	Font::StrDraw(L"6", 785, 94, 15, c_C);
	Font::StrDraw(L"7", 785, 158, 15, c_C);
	Font::StrDraw(L"8", 785, 222, 15, c_C);
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
			skip_anime = true;
			anime_move = 1;
			d = 1;
			if (onceSE == false)
			{
				Audio::Start(10);
				onceSE = true;
			}
			Font::StrDraw(L"ここなら雨宿りできそうだな…", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 2;
			onceSE = false;
			Font::StrDraw(L"誰!?", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 1;
			Font::StrDraw(L"先客がいたのか", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			Font::StrDraw(L"俺の名前は鳳一樹、君と同じ学校の二年だ", x, y_a, m_z, c);
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
			Font::StrDraw(L"岸野奏多です", x, y_a, m_z, c);
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
			if (onceSE == false)
			{
				Audio::Start(10);
				onceSE = true;
			}
			Font::StrDraw(L"人がいっぱいいるよ", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			f = false;
			d = 1;
			onceSE = false;
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
			Font::StrDraw(L"かしこまりました", x, y_a, m_z, c);
			Font::StrDraw(L"それでは失礼します", x, y_b, m_z, c);
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
			bgm->ChangeBGM(99);
			if (onceSE == false)
			{
				Audio::Start(18);
				onceSE = true;
			}
			Font::StrDraw(L"ん？", x, y_a, m_z, c);
		}
		else if (word == 28)
		{
			if (twiceSE == false)
			{
				Audio::Start(18);
				twiceSE = true;
			}
			Font::StrDraw(L"ドアが開かないぞ", x, y_a, m_z, c);
		}
		else if (word == 29)
		{
			d = 2;
			bgm->ChangeBGM(1);
			onceSE = false;
			twiceSE = false;
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
		else if (word == 54 && item_word == 0 && kirara_word==0&& kanata_word == 0 && towa_word== 0)
		{
			hero_move = true;
			anime_move = 8;
			d = 0;
			g = 3;
			text_move = false;
			if (onceSE == false)
			{
				Audio::Start(10);
				onceSE = true;
			}
			bgm->ChangeBGM(2);
			Font::StrDraw(L"部屋をえらんで探索しよう", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//きららマップ
	//進入時　word=0〜10
	//解除後時　word=10〜22
	//きららマップ進入時会話-----------------------------------------------------------------------
	else if (text_m == 0)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			onceSE = false;
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
		else if (word == 10 && text_hide == false && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"色々な場所を調べよう！", x, y_a, 32, c);
		}
	}
	//きらら答え入力後-----------------------------------------------------------------------
	else if (text_m == 3)
	{
		if (word == 11)
		{
			item_word = 0;
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
		else if (word == 23 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
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
	//進入時　word=0〜13
	//鍵取得時　word=13〜18
	//奏多マップ進入時-------------------------------------------------------------------------
	else if (text_m == 1)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			onceSE = false;
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
		else if (word == 13&&item_word==0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			d = 0;
			g = 3;
			hero_move = true;
			text_move = false;
			Font::StrDraw(L"本棚を見てみよう！", x, y_a, 32, c);
		}
	}
	//鍵入手後-----------------------------------------------------------------------
	else if (text_m == 4)
	{
		if (word == 14)
		{
			item_word = 0;
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
		else if (word == 19 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
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
	//進入時　word=0〜9
	//メモ取得時　word=9〜19
	//永遠マップ進入時-------------------------------------------------------------------------
	else if (text_m == 2)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			onceSE = false;
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
		else if (word == 9 && text_hide == false && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"隅まで調べよう！", x, y_a, 32, c);
		}
	}
	//永遠マップ解除時-------------------------------------------------------------------------
	else if (text_m == 5)
	{
		if (word == 10)
		{
			item_word = 0;
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
		else if (word == 20 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
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
			item_word = 0;
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 1;
			g = 2;
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
			Font::StrDraw(L"なによそれ!", x, y_a, m_z, c);
		}
		else if (word == 7 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"本棚を探そう！", x, y_a, 32, c);
		}
	}
	//２階層-----------------------------------------------------------------------
	else if (text_m == 7)
	{
		if (word == 0)
		{
			item_word = 0;
			anime_move = 0;
			hero_move = false;
			text_move = true;
			f = false;
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
			if (f == false)
			{
				skip_anime = true;
				f = true;
			}
			d = 2;
			g = 2;
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
			if (onceSE == false)
			{
				Audio::Start(10);
				onceSE = true;
			}
			Font::StrDraw(L"(俺は誰かを手伝いに行こう）", x, y_a, m_z, c);
		}
		else if (word ==9 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			onceSE = false;
			Font::StrDraw(L"部屋をえらんで探索しよう", x, y_a, 32, c);
			text_loop = false;
		}
	}
	//2階層きらら部屋-------------------------------------------------
	else if (text_m == 8)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			bgm->ChangeBGM(4);
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"大星手伝うぞ", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 2;
			Font::StrDraw(L"鳳君いいところに来たわ", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			Font::StrDraw(L"ちょっと手伝いなさい", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"急にどうしたんだ?", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 2;
			g = 1;
			Font::StrDraw(L"さっき何か落ちているのを見つけたんだけど", x, y_a, m_z, c);
			Font::StrDraw(L"ネズミが持って行っちゃったのよ", x, y_b, m_z, c);
		}
		else if (word == 6)
		{
			Font::StrDraw(L"私の勘があっていれば", x, y_a, m_z, c);
			Font::StrDraw(L"あれが館の入り口の鍵だと思うの", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			g = 2;
			Font::StrDraw(L"ってわけだから早く捕まえに行くわよ", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 1;
			Font::StrDraw(L"状況は分かったから一回落ち着け", x, y_a, m_z, c);
		}	
		else if (word == 9)
		{
			d = 2;
			Font::StrDraw(L"別に落ち着いてるわよ", x, y_a, m_z, c);
		}
		else if (word == 10)
		{
			d = 1;
			Font::StrDraw(L"それじゃ行くか", x, y_a, m_z, c);
		}
		else if (word == 11 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"ネズミを捕まえよう！", x, y_a, 32, c);
		}
	}
	//ネズミ捕まえた後
	else if (text_m == 9)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			bgm->ChangeBGM(7);
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 2;
			g = 2;
			Font::StrDraw(L"捕まえたわ!!", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"やったな大星", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 2;
			Font::StrDraw(L"…", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"どうした?", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 2;
			Font::StrDraw(L"…何でもないわ", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			g = 1;
			Font::StrDraw(L"それよりもこの鍵で", x, y_a, m_z, c);
			Font::StrDraw(L"入り口が開くか見てきてよ", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			g = 2;
			Font::StrDraw(L"私はみんなを集めておくわ", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 1;
			Font::StrDraw(L"わかった", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			gate_flag=true;
		}
		
	}

	//2階層奏多部屋-------------------------------------------------
	else if (text_m == 10)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			bgm->ChangeBGM(3);
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
		else if (word == 11 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{

			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"整理しよう！", x, y_a, 32, c);
		}
	}
	//ここから倉庫番-----------------------------------------------
	//倉庫番終了後-------------------------------------------------
	if (text_m == 11)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			bgm->ChangeBGM(6);
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
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
		else if (word == 9 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			gate_flag = true;
		}
	}
	//2階層永遠部屋-------------------------------------------------
	if (text_m == 12)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			bgm->ChangeBGM(5);
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"北上先輩の部屋の探索を手伝いますよ", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 4;
			Font::StrDraw(L"鳳君", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			Font::StrDraw(L"ありがとう助かるよ", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			g = 1;
			Font::StrDraw(L"それにしても", x, y_a, m_z, c);
			Font::StrDraw(L"あの矢印ってなんなんですか?", x, y_b, m_z, c);
		}
		else if (word == 5)
		{
			g = 2;
			d = 4;
			Font::StrDraw(L"足元に気を付けてね", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			Font::StrDraw(L"めちゃくちゃ運ばれるから", x, y_a, m_z, c);
		}
		else if (word == 7)
		{
			d = 1;
			Font::StrDraw(L"いや流石に命知らずすぎませんか!?", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 4;
			Font::StrDraw(L"だとしたらこんな部屋に", x, y_a, m_z, c);
			Font::StrDraw(L"鍵なんてあるのかな?", x, y_b, m_z, c);
		}
		else if (word == 9)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"さすがにないかもしれないですね", x, y_a, m_z, c);
		}
		else if (word == 10)
		{
			d = 4;
			g = 1;
			Font::StrDraw(L"まあ探してみないことにはわからないし", x, y_a, m_z, c);
			Font::StrDraw(L"やるだけやってみようか", x, y_b, m_z, c);
		}
		else if (word == 11 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			Font::StrDraw(L"滑ってみよう！", x, y_a, 32, c);
		}
	}
	//鍵入手後
	if (text_m == 13)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			bgm->ChangeBGM(8);
			Font::StrDraw(L"Zキーで会話進行", x, y_a, m_z, c);
		}
		else if (word == 1)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 4;
			g = 2;
			Font::StrDraw(L"…鍵あったね", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 1;
			Font::StrDraw(L"…ありましたね", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 4;
			g = 1;
			Font::StrDraw(L"まあこの鍵が本物である保証もないし", x, y_a, m_z, c);
			Font::StrDraw(L"入り口に確かめに行こう", x, y_b, m_z, c);
		}
		else if (word == 4)
		{
			Font::StrDraw(L"僕はみんなを呼んでおくから鳳君は", x, y_a, m_z, c);
			Font::StrDraw(L"入口の鍵か見てきてもらってもいいかな", x, y_b, m_z, c);
		}
		else if (word == 5)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"分かりました", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			d = 4;
			g = 1;
			Font::StrDraw(L"脱出出来たら少し話があるんだけど", x, y_a, m_z, c);
			Font::StrDraw(L"いいかな?", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			d = 1;
			g = 2;
			Font::StrDraw(L"俺は構いませんけど", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 4;
			Font::StrDraw(L"それじゃあよろしく頼むよ", x, y_a, m_z, c);
		}
		else if (word == 9 && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
		{
			hero_move = true;
			d = 0;
			g = 3;
			text_move = false;
			gate_flag = true;
		}
	}

	//エンディング　きらら-------------------------------------------
	if (text_m == 14)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, m_z, c);
		}
		else if (word == 1)
		{
			gate_flag = false;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 4;
			g = 2;
			Font::StrDraw(L"無事脱出できるねぇ", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 3;
			Font::StrDraw(L"流石お嬢様です", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 2;
			Font::StrDraw(L"鳳君ちょっと話があるんだけど", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 1;
			Font::StrDraw(L"どうかしたのか?", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			d = 2;
			Font::StrDraw(L"どうして私にネズミを捕まえさせたの？", x, y_a, m_z, c);
		}
		else if (word == 6)
		{
			g = 1;
			Font::StrDraw(L"きっとあなた一人でも", x, y_a, m_z, c);
			Font::StrDraw(L"ネズミを捕まえれたはずよね", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			g = 2;
			Font::StrDraw(L"なのにどうして私につかまえさせたの", x, y_a, m_z, c);
		}
		else if(word==8)
		{
			d = 1;
			Font::StrDraw(L"そんなことないぞ?", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			Font::StrDraw(L"俺が追い込んで大星が捕まえた", x, y_a, m_z, c);
		}
		else if (word == 10)
		{
			Font::StrDraw(L"それでいいじゃないのか?", x, y_a, m_z, c);
		}
		else if (word == 11)
		{
			d = 2;
			Font::StrDraw(L"…あなたはいいの？", x, y_a, m_z, c);
		}
		else if (word == 12)
		{
			d = 1;
			Font::StrDraw(L"俺は別に構わないよ", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			d = 2;
			Font::StrDraw(L"そっか", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			Font::StrDraw(L"ありがとう", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			d = 1;
			Font::StrDraw(L"それじゃあ帰ろうか", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 2;
			Font::StrDraw(L"今度行きたいところがあるのよ", x, y_a, m_z, c);
		}
		else if (word == 17)
		{
			Font::StrDraw(L"君の付き合いなさいよね", x, y_a, m_z, c);
		}
		else if (word == 18)
		{
			d = 0;
			g = 0;
			end_time = 0;
			ending = true;
			word = 300;
		}
	}
	//エンディング　奏多---------------------------------------------
	if (text_m == 15)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			gate_flag = false;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
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
		else if (word == 19)
		{
			d = 0;
			g = 0;
			end_time = 0;
			ending = true;
			word = 300;
		}
	}
	//エンディング　永遠---------------------------------------------
	if (text_m == 16)
	{
		if (word == 0)
		{
			item_word = 0;
			hero_move = false;
			text_move = true;
			Font::StrDraw(L"Zキーで会話進行", x, y_a, 32, c);
		}
		else if (word == 1)
		{
			gate_flag = false;
			c_A[3] = 1.0 - time*0.005;
			Draw::Draw(12, &src_A, &dst_A, c_A, 0.0f);
			d = 1;
			g = 2;
			Font::StrDraw(L"それで話って何ですか?", x, y_a, m_z, c);
		}
		else if (word == 2)
		{
			d = 4;
			Font::StrDraw(L"鳳君って昔隣町に住んでなかった?", x, y_a, m_z, c);
		}
		else if (word == 3)
		{
			d = 1;
			Font::StrDraw(L"隣町ですか?", x, y_a, m_z, c);
		}
		else if (word == 4)
		{
			d = 4;
			Font::StrDraw(L"君が昔の知り合いに似ているんだ", x, y_a, m_z, c);
		}
		else if (word == 5)
		{
			g = 1;
			Font::StrDraw(L"転校するまではトワ姉って", x, y_a, m_z, c);
			Font::StrDraw(L"慕われていたんだよ", x, y_b, m_z, c);
		}
		else if (word == 6)
		{
			d = 1;
			Font::StrDraw(L"確か小学生の頃は隣町に", x, y_a, m_z, c);
			Font::StrDraw(L"住んでたと思いますけど…", x, y_b, m_z, c);
		}
		else if (word == 7)
		{
			d = 4;
			g = 2;
            Font::StrDraw(L"もしかして君がカズ君かな?", x, y_a, m_z, c);
		}
		else if (word == 8)
		{
			d = 1;
			Font::StrDraw(L"もしかして永遠先輩がトワ姉なのか?", x, y_a, m_z, c);
		}
		else if (word == 9)
		{
			d = 4;
			Font::StrDraw(L"ようやく気づいてくれた…", x, y_a, m_z, c);
		}
		else if (word == 10)
		{
			d = 1;
			Font::StrDraw(L"ごめんほんとに気づかなくて", x, y_a, m_z, c);
		}
		else if (word == 11)
		{
			d = 4;
			g = 1;
			Font::StrDraw(L"僕も最初見たとき君がカズ君なんて", x, y_a, m_z, c);
			Font::StrDraw(L"気づかなかったしお互い様だね", x, y_b, m_z, c);
		}
		else if (word == 12)
		{
			d = 2;
			g = 2;
			Font::StrDraw(L"二人とも早く帰るわよ", x, y_a, m_z, c);
		}
		else if (word == 13)
		{
			d = 1;
			Font::StrDraw(L"それじゃあ帰りましょうか", x, y_a, m_z, c);
		}
		else if (word == 14)
		{
			d = 4;
			Font::StrDraw(L"昔みたいにトワって呼んでもいいんだよ?", x, y_a, m_z, c);
		}
		else if (word == 15)
		{
			d = 1;
			Font::StrDraw(L"それはやめときますよ永遠先輩", x, y_a, m_z, c);
		}
		else if (word == 16)
		{
			d = 0;
			g = 0;
			end_time = 0;
			ending = true;
			word = 300;
		}

	}
	//エンドロール---------------------------------------------------
	if (ending == true)
	{
		m_key_flag = false;
		dst_A.m_top = 0.0f;
		dst_A.m_left = 0.0f;
		dst_A.m_right = 800.0f;
		dst_A.m_bottom = 600.0f;
		Draw::Draw(12, &src_A, &dst_A, c, 0.0f);
		
		Font::StrDraw(L"スタッフ", 50, 650-end_time, 40, c_C);
		Font::StrDraw(L"総合ディレクター：田中　和樹", 50, 700 - end_time, 40, c_C);
		Font::StrDraw(L"プランナー・シナリオライター", 50, 750 - end_time, 40, c_C);
		Font::StrDraw(L"山�ｱ　勇輝", 50, 800 - end_time, 40, c_C);
		Font::StrDraw(L"プログラマー・サウンドディレクター", 50, 850 - end_time, 40, c_C);
		Font::StrDraw(L"橋本　正", 50, 900 - end_time, 40, c_C);
		Font::StrDraw(L"プログラマー（主にテキスト)", 50, 950 - end_time, 40, c_C);
		Font::StrDraw(L"野山　陸", 50, 1000 - end_time, 40, c_C);
		Font::StrDraw(L"Thank you for Playing!", 50, 1050 - end_time, 50, c_C);
		if (end_time == 1200)
		{
			exit(0);
		}
	}
	//---------------------------------------------------------------
	//玄関テキスト表示
	if (gate_flag == true && item_word == 0 && kirara_word == 0 && kanata_word == 0 && towa_word == 0)
	{
		Font::StrDraw(L"1階玄関に向かおう！", x, y_a, 32, c);
	}
	//通常時キャラ会話
	//きらら　1F部屋
	if (kirara_word == 1 && kirara_anger == true&&kirara_num==0)
	{
		hero_move = false;
		item_word = 0;
		d = 2;
		g = 2;
		Font::StrDraw(L"なんなのよ!", x, y_a, m_z, c);
	}
	else if (kirara_word == 1 && kirara_num == 0)
	{
		hero_move = false;
		item_word = 0;
		d = 2;
		g = 2;
		Font::StrDraw(L"なにかあった？", x, y_a, m_z, c);
	}
	 else if (kirara_word == 2 && kirara_num == 0)
	 {
		 kirara_flag = false;
		 kirara_word = 0;
	 }
	//きらら　1F集合後
	else if (kirara_word == 1 && kirara_anger == true && kirara_num == 1)
	{
		hero_move = false;
		item_word = 0;
		d = 2;
		g = 1;
		Font::StrDraw(L"そういえば私の部屋にあったような", x, y_a, m_z, c);
	}
	else if (kirara_word == 1 && kirara_num == 1)
	{
		hero_move = false;
		item_word = 0;
		d = 2;
		g = 2;
		Font::StrDraw(L"本なんてあった？", x, y_a, m_z, c);
	}
	//きらら　2F部屋
	else if (kirara_word == 1 && kirara_anger == true && kirara_num == 2)
	{
		hero_move = false;
		item_word = 0;
		d = 2;
		g = 1;
		Font::StrDraw(L"早く行きなさいよ！", x, y_a, m_z, c);
	}
	else if (kirara_word == 1 && kirara_num == 2)
	{
		hero_move = false;
		item_word = 0;
		d = 2;
		g = 2;
		Font::StrDraw(L"ほら！ねずみ捕まえるわよ！", x, y_a, m_z, c);
	}
	//きらら　2F終了後
	else if (kirara_word == 1 && kirara_anger == true && kirara_num == 3)
	{
		hero_move = false;
		item_word = 0;
		d = 2;
		g = 1;
		Font::StrDraw(L"玄関確認しに行きなさいよ！", x, y_a, m_z, c);
	}
	else if (kirara_word == 1 && kirara_num == 3)
	{
		hero_move = false;
		item_word = 0;
		d = 2;
		g = 2;
		Font::StrDraw(L"みんなを呼んでくるわ！", x, y_a, m_z, c);
	}
	else if (kirara_word == 2)
	{
		kirara_flag = false;
		kirara_word = 0;
	}
	//奏多　1F会話
	else if (kanata_word == 1 && kanata_anger == true && kanata_num == 0)
	{
		hero_move = false;
		item_word = 0;
		d = 3;
		g = 2;
		Font::StrDraw(L"どうしたんですか?", x, y_a, m_z, c);
	}
	else if (kanata_word == 1 &&kanata_num == 0)
	{
		hero_move = false;
		item_word = 0;
		d = 3;
		g = 2;
		Font::StrDraw(L"なにかございましたか?", x, y_a, m_z, c);
	}
	//奏多　1F集合後
	else if (kanata_word == 1 && kanata_anger == true && kanata_num == 1)
	{
		hero_move = false;
		item_word = 0;
		d = 3;
		g = 2;
		Font::StrDraw(L"でも花の本はなかった気がします", x, y_a, m_z, c);
	}
	else if (kanata_word == 1 && kanata_num == 1)
	{
		hero_move = false;
		item_word = 0;
		d = 3;
		g = 2;
		Font::StrDraw(L"確か本棚がありましたね", x, y_a, m_z, c);
	}
	//奏多　2F部屋
	else if (kanata_word == 1 && kanata_anger == true && kanata_num == 2)
	{
		hero_move = false;
		item_word = 0;
		d = 3;
		g = 2;
		Font::StrDraw(L"ちゃんと片付くのでしょうか", x, y_a, m_z, c);
	}
	else if (kanata_word == 1 && kanata_num == 2)
	{
		hero_move = false;
		item_word = 0;
		d = 3;
		g = 2;
		Font::StrDraw(L"すごい量の箱ですね", x, y_a, m_z, c);
	}
	//奏多　2F終了後
	else if (kanata_word == 1 && kanata_anger == true && kanata_num == 3)
	{
		hero_move = false;
		item_word = 0;
		d = 3;
		g = 2;
		Font::StrDraw(L"どうかしましたか？", x, y_a, m_z, c);
	}
	else if (kanata_word == 1 && kanata_num == 3)
	{
		hero_move = false;
		item_word = 0;
		d = 3;
		g = 2;
		Font::StrDraw(L"皆さんを呼んできます", x, y_a, m_z, c);
	}
	else if (kanata_word == 2)
	{
		kanata_flag = false;
		kanata_word = 0;
	}
	//永遠　1F会話
	else if (towa_word == 1 && towa_anger == true&& towa_num == 0)
	{
		hero_move = false;
		item_word = 0;
		d = 4;
		g = 2;
		Font::StrDraw(L"どうかしたのかい?", x, y_a, m_z, c);
	}
	else if (towa_word == 1 && towa_num == 0)
	{
		hero_move = false;
		item_word = 0;
		d = 4;
		g = 2;
		Font::StrDraw(L"なにかあったかい?", x, y_a, m_z, c);
	}
	//永遠　1F集合後
	else if (towa_word == 1 && towa_anger == true && towa_num == 1)
	{
		hero_move = false;
		item_word = 0;
		d = 4;
		g = 2;
		Font::StrDraw(L"僕のいた部屋には本がなかったよ", x, y_a, m_z, c);
	}
	else if (towa_word == 1 && towa_num == 1)
	{
		hero_move = false;
		item_word = 0;
		d = 4;
		g = 2;
		Font::StrDraw(L"花の本かー", x, y_a, m_z, c);
	}
	//永遠　2F部屋
	else if (towa_word == 1 && towa_anger == true && towa_num == 2)
	{
		hero_move = false;
		item_word = 0;
		d = 4;
		g = 2;
		Font::StrDraw(L"矢印の向きに動くのかな", x, y_a, m_z, c);
	}
	else if (towa_word == 1 && towa_num == 2)
	{
		hero_move = false;
		item_word = 0;
		d = 4;
		g = 2;
		Font::StrDraw(L"矢印の床だね", x, y_a, m_z, c);
	}
	//永遠　2F終了後
	else if (towa_word == 1 && towa_anger == true && towa_num == 3)
	{
		hero_move = false;
		item_word = 0;
		d = 4;
		g = 2;
		Font::StrDraw(L"早く玄関に向かってね!", x, y_a, m_z, c);
	}
	else if (towa_word == 1 && towa_num == 3)
	{
		hero_move = false;
		item_word = 0;
		d = 4;
		g = 2;
		Font::StrDraw(L"みんなを呼んでくるよ", x, y_a, m_z, c);
	}
	else if (towa_word == 2 )
	{
		towa_flag = false;
		towa_word = 0;
	}
	//名前欄---------------------------------------------------------
	if (d == 1)
	{
		if (text_m == -1 && word == 5 || text_m == -1 && word == 7 || text_m == -1 && word == 8)
		{
			Font::StrDraw(L"???", 30, 572, 25, c);
		}
		else
		{
			Font::StrDraw(L"鳳", 39, 575, 20, c);
		}
		Draw::Draw(4, &src, &dst, c_C, 0.0f);
	}
	else if (d == 2)
	{
		Font::StrDraw(L"きらら", 20, 575, 20, c);
		Draw::Draw(50, &src, &dst, c_C, 0.0f);
	}
	else if (d == 3)
	{
		Font::StrDraw(L"奏多", 30, 575, 20, c);
		Draw::Draw(51, &src, &dst, c_C, 0.0f);
	}
	else if (d == 4)
	{
		if (text_m == -1 && word == 16)
		{
			Font::StrDraw(L"???", 30, 572, 25, c);
		}
		else
		{
			Font::StrDraw(L"永遠", 30, 575, 20, c);
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
	//ベッド
	else if (item_word == 7)
	{
		Font::StrDraw(L"2人用のベッドのようだ", x, y_a, m_z, c);
	}
	else if (item_word == 8)
	{
		Font::StrDraw(L"何かありそうなベッドだ", x, y_a, m_z, c);
	}
	//机
	else if (item_word == 9)
	{
		Font::StrDraw(L"小さい机のようだ", x, y_a, m_z, c);
	}
	//本棚
	else if (item_word == 10)
	{
		Font::StrDraw(L"横から見ているから", x, y_a, m_z, c);
		Font::StrDraw(L"何が入っているかわからない", x, y_b, m_z, c);
	}
	//動く本棚
	else if (item_word == 11)
	{
		Font::StrDraw(L"何か動いた跡がある", x, y_a, m_z, c);
	}
	else if (item_word == 12)
	{
		Font::StrDraw(L"たくさんの本が詰まっているが", x, y_a, m_z, c);
		Font::StrDraw(L"一冊分開いているようだ", x, y_b, m_z, c);
	}
	//大きい机
	else if (item_word == 13)
	{
		Font::StrDraw(L"大きい机のようだ", x, y_a, m_z, c);
		Font::StrDraw(L"一体何人住んでいるんだ", x, y_b, m_z, c);
	}
	//空の棚
	else if (item_word == 14)
	{
		Font::StrDraw(L"とても背の高い本棚のようだ", x, y_a, m_z, c);
	}
	//金庫
	else if (item_word == 15)
	{
		Font::StrDraw(L"鍵がかかっていて開かないようだ", x, y_a, m_z, c);
	}
	//左中段本棚
	else if (item_word == 16)
	{
		Font::StrDraw(L"魚にまつわる本が入っている", x, y_a, m_z, c);
	}
	//メモ挟まり本棚の隣
	else if (item_word == 17)
	{
		Font::StrDraw(L"横の本棚から何かはみ出ているようだ", x, y_a, m_z, c);
	}
	//左下段本棚
	else if (item_word == 18)
	{
		Font::StrDraw(L"宇宙にまつわる本が入っている", x, y_a, m_z, c);
	}
	//右下段本棚
	else if (item_word == 19)
	{
		Font::StrDraw(L"小説が沢山入っている", x, y_a, m_z, c);
	}
	//右中段本棚
	else if (item_word == 20)
	{
		Font::StrDraw(L"歴史についてが沢山入っている", x, y_a, m_z, c);
	}
	//右上段本棚
	else if (item_word == 21)
	{
		Font::StrDraw(L"絵本が沢山入っている", x, y_a, m_z, c);
	}
	else if (item_word == 22)
	{
		Font::StrDraw(L"→小説", x, y_a, m_z, c);
		Font::StrDraw(L"←歴史", x, y_b, m_z, c);
	}
	else if (item_word == 23)
	{
		Font::StrDraw(L"→歴史", x, y_a, m_z, c);
		Font::StrDraw(L"←絵本", x, y_b, m_z, c);
	}
	else if (item_word == 24)
	{
		Font::StrDraw(L"→絵本", x, y_a, m_z, c);
	}
	else if (item_word == 25)
	{
		Font::StrDraw(L"→自然", x, y_a, m_z, c);
		Font::StrDraw(L"←魚", x, y_b, m_z, c);
	}
	else if (item_word == 26)
	{
		Font::StrDraw(L"→魚", x, y_a, m_z, c);
		Font::StrDraw(L"←宇宙", x, y_b, m_z, c);
	}
	else if (item_word == 27)
	{
		Font::StrDraw(L"何か逆側から飛び出ている", x, y_a, m_z, c);
	}
	else if (item_word == 28)
	{
		Font::StrDraw(L"火がついている", x, y_a, m_z, c);
	}
	else if (item_word == 29)
	{
		Font::StrDraw(L"窓がある、だが閉まっている", x, y_a, m_z, c);
	}
	else if (item_word == 30)
	{
		Font::StrDraw(L"横から見てもわかるくらいに火がついている", x, y_a, m_z, c);
	}
	//テキスト移動2行用
	if (time < 210 && g == 1)
	{
		src_B.m_top = 30.0f;
		src_B.m_left = 200.0f + time*0.5f;
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
		src_C.m_left = 110.0f + (210 - time_x)*0.5f;
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
	if (time <= 210 && g == 2)
	{
		src_B.m_top = 30.0f;
		src_B.m_left = 200.0f + time*1.0f;
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
		Font::StrDraw(L"寝室", 700, 553, 30, c);
	}
	else if (text_m == 7|| text_m == 9|| text_m == 11||text_m == 13 || text_m == -7)
	{
		Font::StrDraw(L"2F", 730, 503, 30, c);
		Font::StrDraw(L"ロビー", 700, 553, 30, c);
	}
	else if (text_m == 8)
	{
		Font::StrDraw(L"2F", 730, 503, 30, c);
		Font::StrDraw(L"応接室", 700, 553, 30, c);
	}
	else if (text_m == 10)
	{
		Font::StrDraw(L"2F", 730, 503, 30, c);
		Font::StrDraw(L"倉庫", 700, 553, 30, c);
	}
	else if (text_m == 12)
	{
		Font::StrDraw(L"2F", 730, 503, 30, c);
		Font::StrDraw(L"実験室", 700, 553, 30, c);
	}
	//暗転
	if (text_m == -1 && word == 0 || text_m == -1 && word == 1 || text_m == -1 && word == 2||
		text_m == 6 && word == 0 || text_m == 7 && word == 0|| text_m == 9 && word == 0||
		text_m == 11 && word == 0 || text_m == 13 && word == 0 || text_m == 14 && word == 0 || 
		text_m == 15 && word == 0 || text_m == 16 && word == 0  )
	{
		Draw::Draw(12, &src_A, &dst_A, c, 0.0f);
	}

}