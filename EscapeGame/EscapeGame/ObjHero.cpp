//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\Scenemanager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjBlock.h"
#include "ObjItem.h"

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

	m_ani_time = 0;
	m_ani_frame = 0;
	m_vec = 0;
	m_time = 0;
	m_savevec = 0;
	for (int i = 0; i < 20; i++)
		unlocknum[i] = 0;
	selectnum = 0;
	eventnumber = 0;
	hero_vec = 4;

	eventflag = false;
	move_flag = false;
	action_flag = false;
	numlock_flag = false;
	Key_flag = false;
	Itemcheck = false;
}

//アクション
void CObjHero::Action()
{
	//ブロックの位置取得
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//アイテム参照
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//イベント用フラグ
	if (eventflag == true)
	{
		//イベントナンバー１　左の部屋入ってからスタート
		//X = 5, Y = 13の位置まで移動(テスト用)
		if (eventnumber == 1 && move_flag == false)
		{
			//1,右 2,左 3,上 4,下
			if (block->GetX() > 5 && block->ThereIsBlock(2) == true)
			{
				SetMoveVec(2);
			}
			else if (block->GetY() < 13 && block->ThereIsBlock(4) == true)
			{
				SetMoveVec(4);
			}
			else
			{
				eventflag = false;
				eventnumber = 0;
			}
		}
		//イベント1終了

		//イベントナンバー２　右の部屋入ってからスタート
		//X = 8, Y = 2の位置まで移動
		if (eventnumber == 2 && move_flag == false)
		{
			if (block->GetY() > 2 && block->ThereIsBlock(3) == true)
			{
				SetMoveVec(3);
			}
			else if (block->GetX() < 8 && block->ThereIsBlock(1) == true)
			{
				SetMoveVec(1);
			}
			else
			{
				eventflag = false;
				eventnumber = 0;
			}
		}
		//イベント2終了
	}

	//キーの入力
	//動く行動できない状況なら入らない（ナンバーロック解いてる、アイテム確認中など）
	if (action_flag == false)
	{
		//動いている途中じゃないか
		if (move_flag == false)
		{
			//右押したとき
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				//右にブロックなければそのまま動く
				if (block->ThereIsBlock(1) == true)
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
				if (block->ThereIsBlock(2) == true)
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
			else if (Input::GetVKey(VK_UP))
			{
				//上にブロックがなければそのまま動く
				if (block->ThereIsBlock(3) == true)
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
				if (block->ThereIsBlock(4) == true)
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
			else if (Input::GetVKey('1')|| Input::GetVKey(VK_NUMPAD1))
			{
				if (Key_flag == false)
				{
					if (((UserData*)Save::GetData())->item[0] != 0)
					{
						SetShowItemNumber(1);
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
					}
				}
			}
			else
			{
				//キー制御
				Key_flag = false;
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
					block->UnlockDoor(1, u);
					for (int i = 0; i < wpiece; i++)
						unlocknum[i] = 0;
					selectnum = 0;
					wpiece = 0;
					numlock_flag = false;
					action_flag = false;
					Key_flag = true;
				}
			}
			//キーフラグ制御
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

	////マップ切り替え用
	//if (move_flag == false)
	//{
	//	block->Mapchange();
	//}
	/*
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx = +m_speed;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
    else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx = -m_speed;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	else if (Input::GetVKey(VK_UP) == true)
	{
		m_vy = -m_speed;
		m_ani_time += 1;
	}
    else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_vy = +m_speed;
		m_ani_time += 1;
	}
	else
	{
		m_ani_frame = 1;
		m_ani_time = 0;
	}

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	*/

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
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


	if (hero_vec == 1)
	{
		//切り取り位置の設定
		src.m_top = 64.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 96.0f;
	}

	else if (hero_vec == 2)
	{
		//切り取り位置の設定
		src.m_top = 32.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 64.0f;
	}

	else if (hero_vec == 3)
	{
		//切り取り位置の設定
		src.m_top = 96.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 128.0f;
	}

	else if (hero_vec == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 32.0f;
	}

	//表示位置の設定
	dst.m_top = m_py;
	dst.m_left = m_px;
	dst.m_right = m_px + 32.0f ;
	dst.m_bottom = m_py + 32.0f ;
	
	Draw::Draw(10, &src, &dst, c, 0.0f);

	//ナンバーロック表示
	if (numlock_flag)
	{
		for (int i = 0; i < wpiece; i++)
		{
			wchar_t str[256];
			swprintf_s(str, L"%d", unlocknum[i]);
			if (selectnum == i)
			{
				//選択している数は色を黄色くする
				c[2] = 0.5f;
			}
			else
			{
				//それ以外は白字にする
				c[2] = 1.0f;
			}

			Font::StrDraw(str, 30 + i * 30, 500, 30, c);
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