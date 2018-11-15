//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

int text_m = 0;
//マップ情報--------------------------------------------
//1 = 壁, 2 = 主人公初期位置, 3 = 鍵付き壁(特定のカギ持っていれば開く)
//4 = 鍵おいてます, 5 = ナンバーロックドア

//保存マップ
int block_data_save[15][20] =
{
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, },
};

//スタートマップ1F
int block_data_neutral_1F[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
};

//奏多マップ1F
int block_data_up_1F[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0, 2,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,98,1,1,1,1,1,1,1,1,1, 1, },
};

//永遠マップ1F
int block_data_right_1F[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{96,2,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
};

//きららマップ1F
int block_data_left_1F[15][20] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,2,94, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 1, },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1, },
};
//マップ情報-------------------------------------------------
//イニシャライズ
void CObjBlock::Init()
{

	//主人公の位置を設定
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//マップデータをコピー
	memcpy(m_map, block_data_neutral_1F, sizeof(int)*(15 * 20));

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[i][j] == 2)
			{
				hero_x = j; hero_y = i;
				hero->SetPX(32.0f * j);
				hero->SetPY(32.0f * i);
				m_map[i][j] = 0;
			}
		}
	}

	((UserData*)Save::GetData())->item1 = false;
	((UserData*)Save::GetData())->number1 = 1145141919810;
}

//アクション
void CObjBlock::Action()
{
	
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
	src.m_right = 230.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left =640.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 480.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);

	//テキストウィンドウ3（右下）
	src.m_top = 136.0f;
	src.m_left = 0.0f;
	src.m_right = 160.0f;
	src.m_bottom = 256.0f;
	dst.m_top = 480.0f;
	dst.m_left = 640.0f;
	dst.m_right = 800.0f;
	dst.m_bottom =600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);


	//マップチップによるblock設置
	//切り取り位置の設定
	/*
	src.m_top = 0.0f;
	src.m_left = 320.5f;
	src.m_right =src.m_left+64.0f;
	src.m_bottom = 64.0f;
	*/

	for(int i=0;i<15;i++)
	{
		for(int j=0;j<20;j++)
		{
			//ブロック表示
			if(m_map[i][j] == 1)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
	            dst.m_top = i*32.0f;
	            dst.m_left = j*32.0f;
	            dst.m_right = dst.m_left+32.0f;
	            dst.m_bottom = dst.m_top+32.0f;

	            //描画
	            Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//鍵付き扉表示
			if (m_map[i][j] == 3)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}
			//鍵表示
			if (m_map[i][j] == 4)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//ナンバーロックドア
			if (m_map[i][j] == 5)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}

			if (m_map[i][j] == 99)
			{
				//表示位置の設定
				dst.m_top = i*0.0f;
				dst.m_left = j*0.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
	//アイテム表示
	if (((UserData*)Save::GetData())->item1 == true)
	{
		src.m_top = 0.0f;
		src.m_left = 384.0f;
		src.m_right = 448.0f;
		src.m_bottom = 64.0f;
		dst.m_top = 32.0f;
		dst.m_left = 650.0f;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
}
//動く方向にブロックがあるかどうかの判定
bool CObjBlock::ThereIsBlock(int vec)
{


	//右動く時の動作
	if (vec == 1)
	{
		if (m_map[hero_y][hero_x + 1] != 1 && m_map[hero_y][hero_x + 1] != 3 && m_map[hero_y][hero_x + 1] != 5)
		{
			hero_x = hero_x + 1;
			return true;
		}
		else
		{
			return false;
		}
	}
	//左動く時の動作
	if (vec == 2)
	{
		if (m_map[hero_y][hero_x - 1] != 1 && m_map[hero_y][hero_x - 1] != 3 && m_map[hero_y][hero_x - 1] != 5)
		{
			hero_x = hero_x - 1;
			return true;
		}
		else
		{
			return false;
		}
	}
	//上動く時の動作
	if (vec == 3)
	{
		if (m_map[hero_y - 1][hero_x] != 1 && m_map[hero_y - 1][hero_x] != 3 && m_map[hero_y - 1][hero_x] != 5)
		{
			hero_y = hero_y - 1;
			return true;
		}
		else
		{
			return false;
		}
	}
	//下動くときの動作
	if (vec == 4)
	{
		if (m_map[hero_y + 1][hero_x] != 1 && m_map[hero_y + 1][hero_x] != 3 && m_map[hero_y + 1][hero_x] != 5)
		{
			hero_y = hero_y + 1;
			return true;
		}
		else
		{
			return false;
		}
	}
}
//主人公アクション
void CObjBlock::HeroAction(int vec)
{
	//主人公の位置を設定
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//鍵判定
	if (m_map[hero_y][hero_x] == 4)
	{
		m_map[hero_y][hero_x] = 0;
		((UserData*)Save::GetData())->item1 = true;
	}

	//右
	if (vec == 1)
	{
		if (m_map[hero_y][hero_x + 1] == 3)
		{
			;
		}
	}
	//左
	if (vec == 2)
	{
		if (m_map[hero_y][hero_x - 1] == 3)
		{
			;
		}
	}
	//上
	if (vec == 3)
	{
		if (m_map[hero_y - 1][hero_x] == 3 && ((UserData*)Save::GetData())->item1 == true)
		{
			((UserData*)Save::GetData())->item1 = false;
			m_map[hero_y - 1][hero_x] = 99;
		}
		if (m_map[hero_y - 1][hero_x] == 5)
		{
			hero->SetActionflag(true);
			hero->SetLockpiece(13);
			hero->SetNumlock(true);
		}
	}
	if (vec == 4)
	{
		if (m_map[hero_y - 1][hero_x] == 3 && ((UserData*)Save::GetData())->item1 == true)
		{
			m_map[hero_y - 1][hero_x] = 0;
		}
	}
}
//マップ切り替え用関数
void CObjBlock::Mapchange()
{
	//主人公の位置を設定
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//マップ切り替え判定
	if (m_map[hero_y][hero_x] == 99 || m_map[hero_y][hero_x] == 97 || m_map[hero_y][hero_x] == 95)
	{
		//スタートマップデータをコピー
		if (m_map[hero_y][hero_x] == 99)
		{
			text_m = 2;
			m_map[hero_y + 1][hero_x] = 2;
			memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
			memcpy(m_map, block_data_up_1F, sizeof(int)*(15 * 20));
			memcpy(block_data_neutral_1F, block_data_save, sizeof(int)*(15 * 20));
		}
		//スタートマップデータをコピー
		if (m_map[hero_y][hero_x] == 97)
		{
			text_m = 1;
			m_map[hero_y][hero_x - 1] = 2;
			memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
			memcpy(m_map, block_data_right_1F, sizeof(int)*(15 * 20));
			memcpy(block_data_neutral_1F, block_data_save, sizeof(int)*(15 * 20));
		}
		//スタートマップデータをコピー
		if (m_map[hero_y][hero_x] == 95)
		{
			m_map[hero_y][hero_x + 1] = 2;
			memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
			memcpy(m_map, block_data_left_1F, sizeof(int)*(15 * 20));
			memcpy(block_data_neutral_1F, block_data_save, sizeof(int)*(15 * 20));
		}
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (m_map[i][j] == 2)
				{
					hero_x = j; hero_y = i;
					hero->SetPX(32.0f * j);
					hero->SetPY(32.0f * i);
					m_map[i][j] = 0;
				}
			}
		}
	}

	//奏多マップ1F切り替え判定
	if (m_map[hero_y][hero_x] == 98)
	{
		text_m = 0;
		//マップデータをコピー
		m_map[hero_y - 1][hero_x] = 2;
		memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
		memcpy(m_map, block_data_neutral_1F, sizeof(int)*(15 * 20));
		memcpy(block_data_up_1F, block_data_save, sizeof(int)*(15 * 20));
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (m_map[i][j] == 2)
				{
					hero_x = j; hero_y = i;
					hero->SetPX(32.0f * j);
					hero->SetPY(32.0f * i);
					m_map[i][j] = 0;
				}
			}
		}
	}

	//永遠マップ1F切り替え判定
	if (m_map[hero_y][hero_x] == 96)
	{
		text_m = 0;
		//マップデータをコピー
		m_map[hero_y][hero_x + 1] = 2;
		memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
		memcpy(m_map, block_data_neutral_1F, sizeof(int)*(15 * 20));
		memcpy(block_data_right_1F, block_data_save, sizeof(int)*(15 * 20));
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (m_map[i][j] == 2)
				{
					hero_x = j; hero_y = i;
					hero->SetPX(32.0f * j);
					hero->SetPY(32.0f * i);
					m_map[i][j] = 0;
				}
			}
		}
	}

	//きららマップ1F切り替え判定
	if (m_map[hero_y][hero_x] == 94)
	{
		//マップデータをコピー
		m_map[hero_y][hero_x - 1] = 2;
		memcpy(block_data_save, m_map, sizeof(int)*(15 * 20));
		memcpy(m_map, block_data_neutral_1F, sizeof(int)*(15 * 20));
		memcpy(block_data_left_1F, block_data_save, sizeof(int)*(15 * 20));
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (m_map[i][j] == 2)
				{
					hero_x = j; hero_y = i;
					hero->SetPX(32.0f * j);
					hero->SetPY(32.0f * i);
					m_map[i][j] = 0;
				}
			}
		}
	}
}
void CObjBlock::UnlockDoor(int vec, int num)
{
	if (((UserData*)Save::GetData())->number1 == num)
	{
		m_map[hero_y - 1][hero_x] = 0;
		text_m = 4;
	}
}