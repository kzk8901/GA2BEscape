#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
extern int text_m;
//オブジェクト：ブロック＆背景
class CObjBackGround : public CObj
{
public:
	CObjBackGround() {};
	~CObjBackGround() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	void SetMapChip(int mpn, int mapsec, int mapthir, int mapchip) { m_map[mpn][mapsec][mapthir] = mapchip; mapnum = mpn; }
private:
	int m_map[5][15][20];//マップ情報
	int mapnum; //マップナンバー
	int animationtime;   //アニメーションのための時間管理
};