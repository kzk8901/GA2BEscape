//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\Scenemanager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"

#include "ObjKanata.h"
#include "GameHead.h"
#include "ObjBlock.h"
#include "ObjItem.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjKanata::Init()
{
	m_px = 0.0f; //位置ベクトル
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
	kanata_vec = 2;

	eventflag = false;
	move_flag = false;
	action_flag = false;
	numlock_flag = false;
	Key_flag = false;
	Itemcheck = false;
	kanata_in = true;

}

//アクション
void CObjKanata::Action()
{

	//ブロックの位置取得
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//主人公参照
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//イベント用フラグ
	if (eventflag == true)
	{
		//オープニング開始-----------------------------------------------------
		//イベントナンバー１　
		if (eventnumber == 1 && move_flag == false)
		{
			//1,右 2,左 3,上 4,下
			if (block->KanataGetX() > 10 && block->ThereIsBlock(2, 4) == true)
			{
				SetMoveVec(2);
			}
			else if (block->KanataGetY() < 13 && block->ThereIsBlock(4, 4) == true)
			{
				SetMoveVec(4);
			}
			else
			{
				kanata_vec = 4;
				block->SetEventNum(5);
				eventflag = false;
				eventnumber = 0;
			}
		}
		//イベント1終了

		//イベントナンバー2
		if (eventnumber == 2 && move_flag == false)
		{
			//1,右 2,左 3,上 4,下

			if (block->KanataGetY() > 5 && block->ThereIsBlock(3, 4) == true)
			{
				SetMoveVec(3);
			}
			else if (block->KanataGetX() > 9 && block->ThereIsBlock(2, 4) == true)
			{
				SetMoveVec(2);
			}
			else if (block->KanataGetY() > 1 && block->ThereIsBlock(3, 4) == true)
			{
				SetMoveVec(3);
			}
			else
			{
				kanata_vec = 4;
				block->SetEventNum(8);
				eventflag = false;
				eventnumber = 0;
			}
		}
		//イベント2終了

		//イベントナンバー3
		if (eventnumber == 3 && move_flag == false)
		{
			//1,右 2,左 3,上 4,下
			 if (block->KanataGetY() > 0 && block->ThereIsBlock(3, 4) == true)
			{
				SetMoveVec(3);
			}
			else
			{
				eventflag = false;
				eventnumber = 0;
				kanata_in = false;
				kanata_vec = 4;
			}
		}
		//イベント3終了
		//オープニング終了-----------------------------------------------------
		
	}

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

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

}

//ドロー
void CObjKanata::Draw()
{
	int AniData[4] =
	{
		0,1,0,-1,
	};
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


	if (kanata_vec == 1)
	{
		//切り取り位置の設定
		src.m_top = 64.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 96.0f;
	}

	else if (kanata_vec == 2)
	{
		//切り取り位置の設定
		src.m_top = 32.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 64.0f;
	}

	else if (kanata_vec == 3)
	{
		//切り取り位置の設定
		src.m_top = 96.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 128.0f;
	}

	else if (kanata_vec == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 32.0f + AniData[m_ani_frame] * 32;
		src.m_right = 64.0f + AniData[m_ani_frame] * 32;
		src.m_bottom = 32.0f;
	}

	if (kanata_in == true)
	{
		//表示位置の設定
		dst.m_top = m_py;
		dst.m_left = m_px;
		dst.m_right = m_px + 32.0f;
		dst.m_bottom = m_py + 32.0f;
	}

	Draw::Draw(61, &src, &dst, c, 0.0f);

}