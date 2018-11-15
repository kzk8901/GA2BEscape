#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
//オブジェクト：ブロック＆背景
class CObjItem : public CObj
{
public:
	CObjItem() {};
	~CObjItem() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー

	bool CheckItem(int item);
	void DeleteItem(int item, bool all);
	void GetItem(int item);
	void SetShowItem(int item) { ShowItem = item; show = true; }
	void SetShow(bool which) { show = which; }
private:
	int ShowItem;
	bool show;
};