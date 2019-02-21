//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\Scenemanager.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"
#include "GameHead.h"

#include "Objmouse.h"

//イニシャライズ
void CObjMouse::Init()
{
	m_px = 192.0f; //位置ベクトル
	m_py = 224.0f;
	m_vx = 0.0f; //移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f; //右向き0.0f 左向き1.0f
	m_speed = 4.0f;

	movevec = 0;
	savevec = 4;
	m_ani_time = 0;
	m_ani_frame = 0;
	m_time = 0;

	nowmap = 0; 
	nezumap = 3;

	move_flag = false;
}

//アクション
void CObjMouse::Action()
{
	if (move_flag == true && nowmap == nezumap)
	{
		if (movevec == 1)
		{
			//右に動くプログラム
			m_px += m_speed;
			//m_posture = 0.0f;
			m_time++;            //動いている時間
			if (m_time % 8 == 0) //4フレームに一回アニメーション動かす
				m_ani_frame++;
			if (m_time == 8)    //16フレーム(32pixel)動いたら止める
			{
				m_time = 0;
				movevec = 0;
				move_flag = false;
			}
		}
		else if (movevec == 2)
		{
			//左に動くプログラム
			m_px -= m_speed;
			//m_posture = 0.0f;
			m_time++;
			if (m_time % 8 == 0)
				m_ani_frame++;
			if (m_time == 8)
			{
				m_time = 0;
				movevec = 0;
				move_flag = false;
			}
		}
		else if (movevec == 3)
		{
			//上に動くプログラム
			m_py -= m_speed;
			//m_posture = -1.0f;
			m_time++;
			if (m_time % 8 == 0)
				m_ani_frame++;
			if (m_time == 8)
			{
				m_time = 0;
				movevec = 0;
				move_flag = false;
			}
		}
		else if (movevec == 4)
		{
			//下に動くプログラム
			m_py += m_speed;
			//m_posture = -1.0f;
			m_time++;
			if (m_time % 8 == 0)
				m_ani_frame++;
			if (m_time == 8)
			{
				m_time = 0;
				movevec = 0;
				move_flag = false;
			}
		}
		else
		{
			movevec = 0;
			move_flag = false;
		}
	}

	if (m_ani_frame >= 4)
	{
		m_ani_frame = 0;
	}

	m_px += m_vx;
	m_py += m_vy;
}

//ドロー
void CObjMouse::Draw()
{
	int AniData[4] =
	{
		0,1,2,3,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	if (savevec == 1)
	{
		//切り取り位置の設定
		src.m_top = 64.0f;
		src.m_left =  AniData[m_ani_frame] * 32;
		src.m_right = AniData[m_ani_frame] * 32 + 32.0f;
		src.m_bottom = 96.0f;
	}

	else if (savevec == 2)
	{
		//切り取り位置の設定
		src.m_top = 32.0f;
		src.m_left =  AniData[m_ani_frame] * 32;
		src.m_right =  AniData[m_ani_frame] * 32 + 32.0f;
		src.m_bottom = 64.0f;
	}

	else if (savevec == 3)
	{
		//切り取り位置の設定
		src.m_top = 96.0f;
		src.m_left =  AniData[m_ani_frame] * 32;
		src.m_right =  AniData[m_ani_frame] * 32 + 32.0f;
		src.m_bottom = 128.0f;
	}

	else if (savevec == 4)
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left =  AniData[m_ani_frame] * 32;
		src.m_right =  AniData[m_ani_frame] * 32 + 32.0f;
		src.m_bottom = 32.0f;
	}

	if (nezumap == nowmap)
	{
		//表示位置の設定
		dst.m_top = m_py;
		dst.m_left = m_px;
		dst.m_right = m_px + 32.0f;
		dst.m_bottom = m_py + 32.0f;
	}

	Draw::Draw(39, &src, &dst, c, 0.0f);
}

void CObjMouse::SetMovevec(int vec)
{
	movevec = vec; 
	ssavevec = savevec;
	savevec = vec;
	move_flag = true;
}