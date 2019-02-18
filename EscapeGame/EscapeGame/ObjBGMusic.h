#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjBGMusic : public CObj
{
public:
	CObjBGMusic() {};
	~CObjBGMusic() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

	//BGM変更用関数
	void ChangeBGM(int bgmnum);

private:
	int NowBGM;

	bool PlayingSound[10];
};