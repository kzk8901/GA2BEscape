//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjItem.h"
#include "ObjBackGround.h"
#include "ObjBlock.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBackGround::Init()
{
	mapnum = 0;

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			m_map[mapnum][i][j] = 0;
		}
	}
}

//アクション
void CObjBackGround::Action()
{

}

//ドロー
void CObjBackGround::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画表示位置

	//ブロックの位置取得
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//テキストウィンドウ1（横向き)
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 120.0f;
	dst.m_top = 480.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int i = -1; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//背景用ブロック配置
			// 切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = src.m_left + 64.0f;
			src.m_bottom = src.m_top + 64.0f;
			//表示位置の設定
			dst.m_top = i*32.0f;
			dst.m_left = j*32.0f;
			dst.m_right = dst.m_left + 32.0f;
			dst.m_bottom = dst.m_top + 32.0f;

			//描画
			Draw::Draw(10, &src, &dst, c, 0.0f);

			//色付き床
			if (m_map[mapnum][i][j] == 47)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0 + 16.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(19, &src, &dst, c, 0.0f);
			}
		}
	}

	for(int i = 0; i < 15; i++)
	{ 
		for (int j = 0; j < 20; j++)
		{
			//ギミック等主人公関連-------------------
			//壁表示
			if (m_map[mapnum][i][j] == 1)
			{
				if (i != 14)
				{
					if (block->CheckBlockNumber(6, j, i) != 1)
					{
						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;
						//表示位置の設定
						dst.m_top = i*32.0f + 16.0f;
						dst.m_left = j*32.0f;
						dst.m_right = dst.m_left + 32.0f;
						dst.m_bottom = dst.m_top + 32.0f;

						//描画
						Draw::Draw(11, &src, &dst, c, 0.0f);

						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;
						//表示位置の設定
						dst.m_top = i*32.0f;
						dst.m_left = j*32.0f;
						dst.m_right = dst.m_left + 32.0f;
						dst.m_bottom = dst.m_top + 16.0f;

						//描画
						Draw::Draw(12, &src, &dst, c, 0.0f);
					}
					else
					{
						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;
						//表示位置の設定
						dst.m_top = i*32.0f;
						dst.m_left = j*32.0f;
						dst.m_right = dst.m_left + 32.0f;
						dst.m_bottom = dst.m_top + 32.0f;

						//描画
						Draw::Draw(12, &src, &dst, c, 0.0f);
					}
				}
				else
				{
					//切り取り位置の設定
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 64.0f;
					src.m_bottom = src.m_top + 64.0f;
					//表示位置の設定
					dst.m_top = i*32.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//描画
					Draw::Draw(12, &src, &dst, c, 0.0f);
				}
			}
			//本棚表示
			if (m_map[mapnum][i][j] == 35 || m_map[mapnum][i][j] == 36 || m_map[mapnum][i][j] == 37 || m_map[mapnum][i][j] == 38)
			{
				if (m_map[mapnum][i + 1][j] == 35 || m_map[mapnum][i + 1][j] == 36 || m_map[mapnum][i + 1][j] == 37 || m_map[mapnum][i + 1][j] == 38)
				{
					//切り取り位置の設定
					src.m_top = 0.0f;
					src.m_left = 32.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 32.0f;

					//表示位置の設定
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//描画
					Draw::Draw(21, &src, &dst, c, 0.0f);
				}
				else if (m_map[mapnum][i - 1][j] == 35 || m_map[mapnum][i - 1][j] == 36 || m_map[mapnum][i - 1][j] == 37 || m_map[mapnum][i - 1][j] == 38)
				{
					//切り取り位置の設定
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 64.0f;

					//表示位置の設定
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//描画
					Draw::Draw(21, &src, &dst, c, 0.0f);
				}
				else
				{
					int skipcountx = 0;
					int overcount = 0;

					for (int s = 1; m_map[mapnum][i][j + s] == 35 || m_map[mapnum][i][j + s] == 36 || m_map[mapnum][i][j + s] == 37 || m_map[mapnum][i][j + s] == 38; s++)
					{
						skipcountx++;
						if (skipcountx == 5)
						{
							skipcountx = 1;
							overcount += 1;
						}
					}

					for (int x = 0; x <= skipcountx;)
					{
						if (overcount > 0)
						{
							//切り取り位置の設定
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 64.0f;
							src.m_bottom = src.m_top + 64.0f;

							//表示位置の設定
							dst.m_top = i*32.0f - 16.0f;
							dst.m_left = j*32.0f;
							dst.m_right = dst.m_left + 128.0f;
							dst.m_bottom = dst.m_top + 64.0f;

							x += 4;
							overcount -= 1;
						}
						else
						{
							//切り取り位置の設定
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 16.0f * (skipcountx + 1);
							src.m_bottom = src.m_top + 64.0f;

							//表示位置の設定
							dst.m_top = i*32.0f - 16.0f;
							dst.m_left = j*32.0f;
							dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
							dst.m_bottom = dst.m_top + 64.0f;

							x += skipcountx;
							if (skipcountx == 0)
								x++;
						}
					}

					//描画
					Draw::Draw(16, &src, &dst, c, 0.0f);

					j += skipcountx;
				}
			}
			//動く本棚表示
			if (m_map[mapnum][i][j] == 39)
			{
				int skipcountx = 0;
				int overcount = 0;
				for (int s = 1; m_map[mapnum][i][j + s] == 39; s++)
				{
					skipcountx++;
					if (skipcountx == 5)
					{
						skipcountx = 1;
						overcount += 1;
					}
				}
				for (int x = 0; x <= skipcountx;)
				{
					if (overcount > 0)
					{
						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;

						//表示位置の設定
						dst.m_top = i*32.0f - 16.0f;
						dst.m_left = j*32.0f + block->GetMoveshelf();
						dst.m_right = dst.m_left + 128.0f;
						dst.m_bottom = dst.m_top + 32.0f * 2;

						x += 4;
						overcount -= 1;
					}
					else
					{
						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 16.0f * (skipcountx + 1);
						src.m_bottom = src.m_top + 64.0f;

						//表示位置の設定
						dst.m_top = i *32.0f - 16.0f;
						dst.m_left = j*32.0f + block->GetMoveshelf();
						dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
						dst.m_bottom = dst.m_top + 32.0f * 2;

						x += skipcountx;
					}
				}

				//描画
				Draw::Draw(16, &src, &dst, c, 0.0f);

				j += skipcountx;
			}
			//絨毯
			if (m_map[mapnum][i][j] == 45)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 384.0f;
				src.m_bottom = src.m_top + 288.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 384.0f;
				dst.m_bottom = dst.m_top + 288.0f;

				//描画
				Draw::Draw(9, &src, &dst, c, 0.0f);
			}
			//何かある絨毯
			if (m_map[mapnum][i][j] == 46)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 96.0f;
				src.m_right = src.m_left + 32.0f;
				src.m_bottom = src.m_top + 32.0f;
				//表示位置の設定
				dst.m_top = i*32.0;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(17, &src, &dst, c, 0.0f);
			}
			//椅子
			if (m_map[mapnum][i][j] == 48)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 16.0f;
				src.m_bottom = src.m_top + 16.0f;
				//表示位置の設定
				dst.m_top = i*32.0 + 16.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(34, &src, &dst, c, 0.0f);
			}
			//階段
			if (m_map[mapnum][i][j] == 93)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 128.0f;
				src.m_bottom = src.m_top + 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f + 16.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(35, &src, &dst, c, 0.0f);

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 16.0f;

				//描画
				Draw::Draw(12, &src, &dst, c, 0.0f);
			}
		}
	}
}