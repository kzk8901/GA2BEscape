#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
extern bool text_move;
extern int word;
extern int anime_move;
extern bool hero_move;
extern bool text_hide;
extern bool skip_anime;//アニメーション中テキストを進めなくするフラグ
extern int item_word;//物を調べた時の文章
//オブジェクト:タイトル
class CObjText :public CObj
{
public:
	CObjText() {};
	~CObjText() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;//キーフラグ
	bool skip_flag;//スキップフラグ
	bool anime_flag;
	int time;//テキスト表示上部管理時間
	int time_x;//テキスト表示下部管理時間
	int g;//テキストが２行か1行かの確認用
	int d;//だれが話しているか確認用
	bool f;//アニメーション中テキストを進めなくするフラグ
};