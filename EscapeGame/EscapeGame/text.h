#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
extern bool text_move;
extern int word;
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
	int time;
	int x, y;
};