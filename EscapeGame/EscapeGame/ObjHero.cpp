//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\Scenemanager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjBlock.h"

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
	m_ani_frame = 1;
	m_vec = 0;
	m_time = 0;
	m_savevec = 0;


	move_flag = false;
}

//アクション
void CObjHero::Action()
{
	//ブロックの位置取得
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//キーの入力方向
	if (move_flag == false)
	{
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			if (block->ThereIsBlock(1) == true)
			{
				m_vec = 1;
				m_savevec = 1;
				move_flag = true;
			}
			else
			{
				m_savevec = 1;
			}
		}
		else if (Input::GetVKey(VK_LEFT) == true)
		{
			if (block->ThereIsBlock(2) == true)
			{
				m_vec = 2;
				m_savevec = 2;
				move_flag = true;
			}
			else
			{
				m_savevec = 2;
			}
		}
		else if (Input::GetVKey(VK_UP))
		{
			if (block->ThereIsBlock(3) == true)
			{
				m_vec = 3;
				m_savevec = 3;
				move_flag = true;
			}
			else
			{
				m_savevec = 3;
			}
		}
		else if (Input::GetVKey(VK_DOWN) == true)
		{
			if (block->ThereIsBlock(4) == true)
			{
				m_vec = 4;
				m_savevec = 4;
				move_flag = true;
			}
			else
			{
				m_savevec = 4;
			}
		}
		else if ((Input::GetVKey('Z') == true))
		{
			block->HeroAction(m_savevec);
		}
	}
	else
	{
		if (m_vec == 1)
		{
			//右に動くプログラム
			m_vx = +m_speed;     
			m_posture = 1.0f;
			m_time++;            //動いている時間
			if (m_time % 4 == 0) //4フレームに一回アニメーション動かす
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
			m_posture = 0.0f;
			m_time++;
			if (m_time % 4 == 0)
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
			if (m_time % 4 == 0)
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
			if (m_time % 4 == 0)
				m_ani_frame++;
			if (m_time == 16)
			{
				m_time = 0;
				m_vec = 0;
				move_flag = false;
			}
		}
	}

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
		1,0,2,0,
	};
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置


	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f +m_py;
	dst.m_left = m_px + (32.0f * m_posture);
	dst.m_right = m_px + 32.0f + (- 32.0f * m_posture);
	dst.m_bottom = 32.0f + m_py;
	
	Draw::Draw(0, &src, &dst, c, 0.0f);
}