#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
extern int text_m;
//オブジェクト：ブロック＆背景
class CObjBlock : public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	int  GetX() { return hero_x; }
	int  GetY() { return hero_y; }

	bool ThereIsBlock(int vec);
	void HeroAction(int vec);
	void Mapchange();

	void UnlockDoor(int vec, int num);
private:
	int m_map[15][20];//マップ情報
	int hero_x; //主人公位置（X）
	int hero_y; //主人公位置（Y）
};