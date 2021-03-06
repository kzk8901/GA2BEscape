//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\Scenemanager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include"GameL\\Audio.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjBlock.h"
#include "ObjItem.h"
#include "text.h"
//使用するネームスペース
using namespace GameL;
//イニシャライズ
void CObjHero::Init()
{
	m_px = 32.0f; //位置ベクトル
	m_py = 0.0f;
	m_vx = 0.0f; //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0f 左向き1.0f
	m_speed = 2.0f;

	locknum = 0;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_vec = 0;
	m_time = 0;
	m_savevec = 0;
	for (int i = 0; i < 20; i++)
		unlocknum[i] = 0;
	selectnum = 0;
	hero_vec = 4;
	eventnumber = 0;

	eventflag = false;
	move_flag = false;
	action_flag = false;
	numlock_flag = false;
	Key_flag = false;
	Itemcheck = false;
	hero_in = false;
	iceflag = false;
	hintmemo_flag = false;
}

//アクション
void CObjHero::Action()
{
	//ブロック参照
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//アイテム参照
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	if (text_m == -1 && word == 5)
	{
		eventflag = true;
		eventnumber = 1;
	}
	else if (text_m == -1 && word == 25)
	{
		eventflag = true;
		eventnumber = 2;
	}

	//イベント用フラグ
	if (eventflag == true)
	{
		//オープニング開始-----------------------------------------------------
		//イベントナンバー１
		if (eventnumber == 1 && move_flag == false)
		{
			if (anime_move == 1)
			{
				hero_in = true;
				//1,右 2,左 3,上 4,下
				if (block->HeroGetY() > 8 && block->ThereIsBlock(3, 1) == true)
				{
					SetMoveVec(3);
				}
				else if (block->HeroGetX() > 6 && block->ThereIsBlock(2, 1) == true)
				{
					SetMoveVec(2);
				}
				else
				{
					hero_vec = 1;
					eventnumber = 0;
					eventflag = false;
					block->SetEventNum(2);
					skip_anime = false;
				}
			}
		}
		//イベント1終了

		//イベントナンバー２
		if (eventnumber == 2 && move_flag == false)
		{
			if (anime_move == 3 )
			{
				//1,右 2,左 3,上 4,下
				if (block->HeroGetX() < 9 && block->ThereIsBlock(1, 1) == true)
				{
					SetMoveVec(1);
				}
				else if (block->HeroGetY() < 13 && block->ThereIsBlock(4, 1) == true)
				{
					SetMoveVec(4);
				}
				else
				{
					hero_vec = 4;
					eventnumber = 0;
					eventflag = false;
					block->SetEventNum(4);
					skip_anime = false;
				}
			}
		}
		//イベント2終了

		//オープニング終了-----------------------------------------------------

		//奏多F1イベント開始-----------------------------------------------------
		// イベントナンバー3
		if (eventnumber == 3 && move_flag == false)
		{
				//1,右 2,左 3,上 4,下
			if (block->HeroGetY() > 10 && block->ThereIsBlock(3, 1) == true)
			{
				SetMoveVec(3);
			}
			else if (block->HeroGetX() > 7 && block->ThereIsBlock(2, 1) == true)
			{
				SetMoveVec(2);
			}
			else
			{
				hero_vec = 2;
				eventnumber = 0;
				eventflag = false;
				block->SetEventNum(11);
				skip_anime = false;
			}
		}
		// イベントナンバー4
		if (eventnumber == 4 && move_flag == false)
		{
			//1,右 2,左 3,上 4,下
			if (block->HeroGetX() > 7 && block->ThereIsBlock(2, 1) == true)
			{
				SetMoveVec(2);
			}
			else if (block->HeroGetY() > 10 && block->ThereIsBlock(3, 1) == true)
			{
				SetMoveVec(3);
			}
			else
			{
				hero_vec = 2;
				eventnumber = 0;
				eventflag = false;
				block->SetEventNum(14);
				skip_anime = false;
			}
		}
		//イベント4終了

		//奏多F1イベント終了-----------------------------------------------------

		//永遠F1イベント開始-----------------------------------------------------
		// イベントナンバー5
		if (eventnumber == 5 && move_flag == false)
		{
			//1,右 2,左 3,上 4,下
			if (block->HeroGetX() < 8 && block->ThereIsBlock(1, 1) == true)
			{
				SetMoveVec(1);
			}
			else if (block->HeroGetY() > 4 && block->ThereIsBlock(3, 1) == true)
			{
				SetMoveVec(3);
			}
			else
			{
				hero_vec = 1;
				eventnumber = 0;
				eventflag = false;
				block->SetEventNum(17);
				skip_anime = false;
			}
		}
		//イベント5終了

		// イベントナンバー6
		if (eventnumber == 6 && move_flag == false)
		{
			//1,右 2,左 3,上 4,下
			if (block->HeroGetY() < 4 && block->ThereIsBlock(4, 1) == true)
			{
				SetMoveVec(4);
			}
			else if (block->HeroGetX() > 8 && block->ThereIsBlock(2, 1) == true)
			{
				SetMoveVec(2);
			}
			else
			{
				hero_vec = 1;
				eventnumber = 0;
				eventflag = false;
				block->SetEventNum(20);
				skip_anime = false;
			}
		}
		//イベント6終了
		//永遠F1イベント終了-----------------------------------------------------

		//きららF1イベント開始-----------------------------------------------------
		// イベントナンバー7
		if (eventnumber== 7 && move_flag == false)
		{
			//1,右 2,左 3,上 4,下
			if (block->HeroGetX() > 17 && block->ThereIsBlock(2, 1) == true)
			{
				SetMoveVec(2);
			}
			else if (block->HeroGetY() > 6 && block->ThereIsBlock(3, 1) == true)
			{
				SetMoveVec(3);
			}
			else
			{
				hero_vec = 3;
				eventnumber= 0;
				eventflag = false;
				block->SetEventNum(23);
				skip_anime = false;
			}
		}
		//イベント7終了
		//きららF1イベント終了-----------------------------------------------------

		//氷を滑るイベント---------------------------------------------------------
		if (eventnumber == 100 && move_flag == false)
		{
			iceflag = true;
			//1,右 2,左 3,上 4,下
			if (block->CheckIceBlock()== 2 && block->ThereIsBlock(1, 1) == true)
			{
				SetMoveVec(1);
			}
			else if (block->CheckIceBlock() == 1 && block->ThereIsBlock(2, 1) == true)
			{
				SetMoveVec(2);
			}
			else if (block->CheckIceBlock() == 3 && block->ThereIsBlock(3, 1) == true)
			{
				SetMoveVec(3);
			}
			else if (block->CheckIceBlock() == 4 && block->ThereIsBlock(4, 1) == true)
			{
				SetMoveVec(4);
			}
			else
			{
				eventnumber = 0;
				eventflag = false;
				iceflag = false;
			}
		}

	}
	


	//キーの入力
	//動く行動できない状況なら入らない（ナンバーロック解いてる、アイテム確認中など）
	if (action_flag == false)
	{
		//動いている途中じゃないか
		if (move_flag == false)
		{
			if (hero_move == true)
			{
				//右押したとき
				if (Input::GetVKey(VK_RIGHT) == true)
				{
					//右にブロックなければそのまま動く
					if (block->ThereIsBlock(1, 1) == true)
					{
						SetMoveVec(1);
					}
					//ブロックがあればその方向だけ向く
					else
					{
						m_savevec = 1;
						hero_vec = 1;
					}
				}
				//左押したとき
				else if (Input::GetVKey(VK_LEFT) == true)
				{
					//左にブロックがなければそのまま動く
					if (block->ThereIsBlock(2, 1) == true)
					{
						SetMoveVec(2);
					}
					//ブロックがあればその方向だけ向く
					else
					{
						m_savevec = 2;
						hero_vec = 2;
					}
				}
				//上押したとき
				else if (Input::GetVKey(VK_UP) == true)
				{
					//上にブロックがなければそのまま動く
					if (block->ThereIsBlock(3, 1) == true)
					{
						SetMoveVec(3);
					}
					//ブロックがあればその方向だけ向く
					else
					{
						m_savevec = 3;
						hero_vec = 3;
					}
				}
				//下押したとき
				else if (Input::GetVKey(VK_DOWN) == true)
				{
					//下にブロックがなければそのまま動く
					if (block->ThereIsBlock(4, 1) == true)
					{
						SetMoveVec(4);
					}
					//ブロックがあればその方向だけ向く
					else
					{
						m_savevec = 4;
						hero_vec = 4;
					}
				}
				//アクションボタン押したとき
				//各動作はブロックに書いている
				else if ((Input::GetVKey('Z') == true))
				{
					if (Key_flag == false)
					{
						block->HeroAction(m_savevec);
						Key_flag = true;
					}
				}
				//↓こっから先はそれぞれの番号に登録しているアイテムの参照プログラム
				//SetshowItemNumber(num)←numの所に参照したいアイテムの番号を入れる
				else if (Input::GetVKey('1') || Input::GetVKey(VK_NUMPAD1))
				{
					if (Key_flag == false)
					{
						if (((UserData*)Save::GetData())->item[0] != 0)
						{
							SetShowItemNumber(1);
							Audio::Start(17);
						}
					}
				}
				else if (Input::GetVKey('2') || Input::GetVKey(VK_NUMPAD2))
				{
					if (Key_flag == false)
					{
						if (((UserData*)Save::GetData())->item[1] != 0)
						{
							SetShowItemNumber(2);
							Audio::Start(17);
						}
					}
				}
				else if (Input::GetVKey('3') || Input::GetVKey(VK_NUMPAD3))
				{
					if (Key_flag == false)
					{
						if (((UserData*)Save::GetData())->item[2] != 0)
						{
							SetShowItemNumber(3);
							Audio::Start(17);
						}
					}
				}
				else if (Input::GetVKey('4') || Input::GetVKey(VK_NUMPAD4))
				{
					if (Key_flag == false)
					{
						if (((UserData*)Save::GetData())->item[3] != 0)
						{
							SetShowItemNumber(4);
							Audio::Start(17);
						}
					}
				}
				else if (Input::GetVKey('5') || Input::GetVKey(VK_NUMPAD5))
				{
					if (Key_flag == false)
					{
						if (((UserData*)Save::GetData())->item[4] != 0)
						{
							SetShowItemNumber(5);
							Audio::Start(17);
						}
					}
				}
				else if (Input::GetVKey('6') || Input::GetVKey(VK_NUMPAD6))
				{
					if (Key_flag == false)
					{
						if (((UserData*)Save::GetData())->item[5] != 0)
						{
							SetShowItemNumber(6);
							Audio::Start(17);
						}
					}
				}
				else if (Input::GetVKey('7') || Input::GetVKey(VK_NUMPAD7))
				{
					if (Key_flag == false)
					{
						if (((UserData*)Save::GetData())->item[6] != 0)
						{
							SetShowItemNumber(7);
							Audio::Start(17);
						}
					}
				}
				else if (Input::GetVKey('8') || Input::GetVKey(VK_NUMPAD8))
				{
					if (Key_flag == false)
					{
						if (((UserData*)Save::GetData())->item[7] != 0)
						{
							SetShowItemNumber(8);
							Audio::Start(17);
						}
					}
				}
				else
				{
					//キー制御
					Key_flag = false;
				}
			}
		}
		else
		{
			if (m_vec == 1)
			{
				//右に動くプログラム
				m_vx = +m_speed;
				//m_posture = 0.0f;
				m_time++;            //動いている時間
				if (m_time % 8 == 0) //4フレームに一回アニメーション動かす
					m_ani_frame++;
				if (m_time == 16)    //16フレーム(32pixel)動いたら止める
				{
					m_time = 0;
					m_vec = 0;
					move_flag = false;
				}
			}
			if (m_vec == 2)
			{
				//左に動くプログラム
				m_vx = -m_speed;
				//m_posture = 0.0f;
				m_time++;
				if (m_time % 8 == 0)
					m_ani_frame++;
				if (m_time == 16)
				{
					m_time = 0;
					m_vec = 0;
					move_flag = false;
				}
			}
			if (m_vec == 3)
			{
				//上に動くプログラム
				m_vy = -m_speed;
				//m_posture = -1.0f;
				m_time++;
				if (m_time % 8 == 0)
					m_ani_frame++;
				if (m_time == 16)
				{
					m_time = 0;
					m_vec = 0;
					move_flag = false;
				}
			}
			if (m_vec == 4)
			{
				//下に動くプログラム
				m_vy = +m_speed;
				//m_posture = -1.0f;
				m_time++;
				if (m_time % 8 == 0)
					m_ani_frame++;
				if (m_time == 16)
				{
					m_time = 0;
					m_vec = 0;
					move_flag = false;
				}
			}
		}
	}
	else
	{
		//ナンバーロック解いているなら入る
		if (numlock_flag == true)
		{
			item_word = 0;
			//右に移動
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				if (Key_flag == false)
				{
					//右にずれる
					selectnum++;
					if (selectnum == wpiece)
					{
						//上限より右に行ったら一番左に戻る
						selectnum = 0;
					}
					//キー制御
					Key_flag = true;
				}
			}
			//左に移動
			else if (Input::GetVKey(VK_LEFT) == true)
			{
				if (Key_flag == false)
				{
					//左にずれる
					selectnum--;
					if (selectnum == -1)
					{
						//一番左より左に行くと一番右に戻る
						selectnum = wpiece - 1;
					}
					//キー制御
					Key_flag = true;
				}
			}
			//数を一つ上げる
			else if (Input::GetVKey(VK_UP) == true)
			{
				if (Key_flag == false)
				{
					//
					unlocknum[selectnum]++;
					if (unlocknum[selectnum] >= 10)
					{
						unlocknum[selectnum] = 0;
					}
					Key_flag = true;
					//ナンバーロック用のSEを鳴らす
					Audio::Start(13);
				}
			}
			//数を一つ下げる
			else if (Input::GetVKey(VK_DOWN) == true)
			{
				if (Key_flag == false)
				{
					unlocknum[selectnum]--;
					if (unlocknum[selectnum] <= -1)
					{
						unlocknum[selectnum] = 9;
					}
					Key_flag = true;
					//ナンバーロック用のSEを鳴らす
					Audio::Start(13);
				}
			}
			//決定
			else if (Input::GetVKey('Z') == true)
			{
				if (Key_flag == false)
				{
					int u = 0;
					int j = 1;
					for (int i = wpiece - 1; i >= 0; i--)
					{
						u += unlocknum[i] * j;
						j *= 10;
					}
					block->UnlockDoor(1, u , locknum);
					for (int i = 0; i < wpiece; i++)
						unlocknum[i] = 0;
					selectnum = 0;
					wpiece = 0;
					locknum = 0;
					numlock_flag = false;
					action_flag = false;
					Key_flag = true;
					text_hide = false;
				}
			}
			//キーフラグ制御
			else
			{
				Key_flag = false;
			}
		}
		else if (hintmemo_flag == true)
		{
			if (Input::GetVKey('X') == true)
			{
				if (Key_flag == false)
				{
					action_flag = false;
					Key_flag = true;
					hintmemo_flag = false;
					block->Set_Pasu_Num(0);
				}
			}
			else
			{
				Key_flag = false;
			}
		}
		if (Itemcheck == true)
		{
			if (Input::GetVKey('X') == true)
			{
				itm->SetShow(false);
				Itemcheck = false;
				action_flag = false;
			}
		}
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

}

//ドロー
void CObjHero::Draw()
{
	int AniData[4] =
	{
		0,1,0,-1,
	};
	int AniIceData[4] =
	{
		0,0,0,0,
	};
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float f[4] = { 0.0f,0.0f,0.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


	if (hero_vec == 1)
	{
		if (iceflag == false)
		{
			//切り取り位置の設定
			src.m_top = 96.0f;
			src.m_left = 48.0f + AniData[m_ani_frame] * 48;
			src.m_right = 96.0f + AniData[m_ani_frame] * 48;
			src.m_bottom = 144.0f;
		}
		else
		{
			//切り取り位置の設定
			src.m_top = 96.0f;
			src.m_left = 48.0f + AniIceData[m_ani_frame] * 48;
			src.m_right = 96.0f + AniIceData[m_ani_frame] * 48;
			src.m_bottom = 144.0f;
		}
	}
	else if (hero_vec == 2)
	{
		if (iceflag == false)
		{
			//切り取り位置の設定
			src.m_top = 48.0f;
			src.m_left = 48.0f + AniData[m_ani_frame] * 48;
			src.m_right = 96.0f + AniData[m_ani_frame] * 48;
			src.m_bottom = 96.0f; 
		}
		else
		{
			//切り取り位置の設定
			src.m_top = 48.0f;
			src.m_left = 96.0f + AniIceData[m_ani_frame] * 48;
			src.m_right = 144.0f + AniIceData[m_ani_frame] * 48;
			src.m_bottom = 96.0f;
		}
	}
	else if (hero_vec == 3)
	{
		if (iceflag == false)
		{
			//切り取り位置の設定
			src.m_top = 144.0f;
			src.m_left = 48.0f + AniData[m_ani_frame] * 48;
			src.m_right = 96.0f + AniData[m_ani_frame] * 48;
			src.m_bottom = 192.0f;
		}
		else
		{
			//切り取り位置の設定
			src.m_top = 144.0f;
			src.m_left = 48.0f + AniIceData[m_ani_frame] * 48;
			src.m_right = 96.0f + AniIceData[m_ani_frame] * 48;
			src.m_bottom = 192.0f;
		}
	}
	else if (hero_vec == 4)
	{
		if (iceflag == false)
		{
			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 48.0f + AniData[m_ani_frame] * 48;
			src.m_right = 96.0f + AniData[m_ani_frame] * 48;
			src.m_bottom = 46.0f;
		}
		else
		{
			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 48.0f + AniIceData[m_ani_frame] * 48;
			src.m_right = 96.0f + AniIceData[m_ani_frame] * 48;
			src.m_bottom = 48.0f;
		}
	}

	if (hero_in == true)
	{
		//表示位置の設定
		dst.m_top = m_py;
		dst.m_left = m_px;
		dst.m_right = m_px + 32.0f;
		dst.m_bottom = m_py + 32.0f;
	}
	
	Draw::Draw(53, &src, &dst, c, 0.0f);
	

	//ナンバーロック表示
	if (numlock_flag)
	{
		for (int i = 0; i < wpiece; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%d", unlocknum[i]);
			if (selectnum == i)
			{
				//選択している数は色を緑にする
				f[1] = 1.0f;
			}
			else
			{
				//それ以外は黒字にする
				f[1] = 0.0f;
			}

			Font::StrDraw(str, 200 + i * 30, 500, 30, f);
		}
	}
}
//アイテム表示用関数
void CObjHero::SetShowItemNumber(int i)
{
	//アイテム参照
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	//渡されたナンバーの番号に入っているアイテムを参照　　　↓そのための-1
	itm->SetShowItem(((UserData*)Save::GetData())->item[i - 1]);
	Itemcheck = true;
	Key_flag = true;
	action_flag = true;
}