#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;
extern int text_m;//テキストの種類管理
extern bool text_loop;//テキストループ対策
extern bool room_c[3];
extern bool event_skip;//イベント飛ばし用
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
	int  CheckBlockNumber(int vec, int x, int y);
	int  HeroGetX() { return hero_x; }
	int  HeroGetY() { return hero_y; }
	int  KiraraGetX() { return kirara_x; }
	int  KiraraGetY() { return kirara_y; }
	int  TowaGetX() { return towa_x; }
	int  TowaGetY() { return towa_y; }
	int  KanataGetX() { return kanata_x; }
	int  KanataGetY() { return kanata_y; }
	int  MouseGetX() { return mouse_x; }
	int  MouseGetY() { return mouse_y; }

	bool ThereIsBlock(int vec ,int Characternum);//方向と動かすキャラ
	void HeroAction(int vec);
	void Mapchange(int mapn);
	void SetHero();
	void SetKirara();
	void SetTowa();
	void SetKanata();

	void SetEventNum(int e) { event_num = e; }//起こしたい最初のイベントを入れる

	void UnlockDoor(int vec, int num, int locknum);
	void Set_Map_Num(int n) { mapnum = n; }//マップナンバーをセットする
	float GetMoveshelf() { return moveshelf; }
private:
	int m_map[5][15][20];//マップ情報
	int notonblock[99];  //当たり判定あるブロックのナンバーはここに入れる
	int hero_x;   //主人公位置（X）
	int hero_y;   //主人公位置（Y）
	int kirara_x; //きらら位置（X）
	int kirara_y; //きらら位置（Y）
	int towa_x;   //永遠位置（X）
	int towa_y;   //永遠位置（Y）
	int kanata_x; //奏多位置（X）
	int kanata_y; //奏多位置（Y）
	int mouse_x;  //鼠位置(X)
	int mouse_y;  //鼠位置(Y)

	bool eventclockflag; //イベント中のフラグ
	int  eventclocktime; //イベント中の時間管理
	int  blockmovevec;   //ブロックの動く方向
	int   blockx;
	int   blocky;
	bool  blockdeleteYN;
	float blockm_x;
	float blockm_y;
	float moveshelf;
	int mapnum; //マップナンバー
	int animationtime;   //アニメーションのための時間管理

	int event_num;//イベントナンバー 0イベントなし
	bool event_clock[8];//1回しか起こさないイベントチェック
	int lockpasu;  //ナンバーロックのヒント表示用

	int tiherovec;//鼠用主人公位置保存用変数
	int acvec;    //鼠用仮移動方向保存用
	int mousemtime;//鼠用行動回数保存用

};