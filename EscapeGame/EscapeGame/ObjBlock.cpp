//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBlock::Init()
{
	//マップ情報
	int block_data[15][20] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, },
	};

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[i][j] == 3)
			{
				hero_x = j;
				hero_y = i;
			}
		}
	}

	//マップデータをコピー
	memcpy(m_map, block_data, sizeof(int)*(15 * 20));
}

//アクション
void CObjBlock::Action()
{
	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		//hero_x + 1;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		//hero_x - 1;
	}
	else if (Input::GetVKey(VK_UP) == true)
	{
		//hero_y - 1;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		//hero_y + 1;
	}
	else
	{
		;
	}
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画表示位置

	//背景表示
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 400.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left =0.0f;
	dst.m_right =640.0f;
	dst.m_bottom = 512.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//テキストウィンドウ1（横向き)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 234.0f;
	dst.m_top = 480.0f;
	dst.m_left =0.0f;
	dst.m_right =640.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//テキストウィンドウ2（縦向き）
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 234.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left =640.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 480.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);


	//マップチップによるblock設置
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 320.5f;
	src.m_right =src.m_left+64.0f;
	src.m_bottom = 64.0f;

	for(int i=0;i<15;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(m_map[i][j]>0)
			{
				//表示位置の設定
	            dst.m_top = i*32.0f;
	            dst.m_left = j*32.0f;
	            dst.m_right = dst.m_left+32.0f;
	            dst.m_bottom = dst.m_top+32.0f;

	            //描画
	            Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
	
}