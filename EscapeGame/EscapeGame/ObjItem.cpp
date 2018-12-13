//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjItem.h"

void CObjItem::Init()
{
	ShowItem = 0;
	show = false;

	//所持アイテムリセット
	for (int i = 0; i < 8; i++)
	{
		((UserData*)Save::GetData())->item[i] = 0;
	}
}

void CObjItem::Action()
{

}

void CObjItem::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画表示位置

	//アイテム表示
	for (int i = 0; i < 8; i++)
	{
		if (((UserData*)Save::GetData())->item[i] != 0)
		{
			if (((UserData*)Save::GetData())->item[i] == 1 ||
				((UserData*)Save::GetData())->item[i] == 2)
			{
				src.m_top = 0.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 32.0f + 64.0f * i;
				dst.m_left = 650.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			if (((UserData*)Save::GetData())->item[i] == 3)
			{
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 64.0f;
				src.m_bottom = 64.0f;
				dst.m_top = 32.0f + 64.0f * i;
				dst.m_left = 650.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				Draw::Draw(18, &src, &dst, c, 0.0f);
			}
		}
	}

	if (show == true)
	{
		//ホワイトウインドウ表示
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 800.0f;
		src.m_bottom = 600.0f;
		dst.m_top = 64.0f;
		dst.m_left = 64.0f;
		dst.m_right = 576.0f;
		dst.m_bottom = 416.0f;
		Draw::Draw(5, &src, &dst, c, 0.0f);
		//アイテム巨大化表示
		/*
		src.m_top = 0.0f;
		src.m_left = 384.0f;
		src.m_right = 448.0f;
		src.m_bottom = 64.0f;
		*/
		dst.m_top = 80.0f;
		dst.m_left = 96.0f;
		dst.m_right = dst.m_left + 320.0f;
		dst.m_bottom = dst.m_top + 320.0f;
		if (ShowItem == 1)
		{
			src.m_top = 0.0f;
			src.m_left = 384.0f;
			src.m_right = 448.0f;
			src.m_bottom = 64.0f;
			Draw::Draw(0, &src, &dst, c, 0.0f);
		}
		if (ShowItem == 2)
		{
			src.m_top = 64.0f;
			src.m_left = 320.0f;
			src.m_right = 384.0f;
			src.m_bottom = 128.0f;
			Draw::Draw(0, &src, &dst, c, 0.0f);
		}
		if (ShowItem == 3)
		{
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;
			Draw::Draw(18, &src, &dst, c, 0.0f);
		}
	}
}

//そのアイテム持っているか確認のための関数
bool CObjItem::CheckItem(int item)
{
	//持ち物を確認し、そのアイテム持っていたらtrueを返す
	for (int i = 0; i < 8; i++)
	{
		if (((UserData*)Save::GetData())->item[i] == item)
		{
			return true;
		}
	}

	//持っていなかったらfalseを返す
	return false;
}
//アイテム削除用関数
//allがtrueならばすべて参照し、あてはまるものすべて消す
void CObjItem::DeleteItem(int item, bool all)
{
	//持ち物を確認し、そのアイテム持っていたら消して間を埋める
	for (int i = 0; i < 8; i++)
	{
		if (((UserData*)Save::GetData())->item[i] == item)
		{
			((UserData*)Save::GetData())->item[i] = 0;
			for (int j = i + 1; j < 8; j++)
			{
				((UserData*)Save::GetData())->item[j - 1] = ((UserData*)Save::GetData())->item[j];
				((UserData*)Save::GetData())->item[j] = 0;
				if (all == true)
				{
					i--;
				}
			}

			if (all == false)
				break;
		}
	}
}
//アイテムゲットのための関数
void CObjItem::GetItem(int item)
{
	//アイテムを手に持ったかのフラグ
	bool igf = false;

	//１～８までアイテムを持っているかを探す
	for (int i = 0; i < 8; i++)
	{
		if (((UserData*)Save::GetData())->item[i] == 0)
		{
			((UserData*)Save::GetData())->item[i] = item;
			igf = true;
			break;
		}
	}

	if (igf == false)
	{
		//所持アイテムがいっぱいのメッセージウインドウを出す
		;
	}
}