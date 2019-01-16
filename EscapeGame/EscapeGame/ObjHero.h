#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;


extern int eventnumber_h;
extern bool eventflag_h; //イベントフラグ
//オブジェクト：主人公
class CObjHero : public CObj
{
   public:
	   CObjHero() {};
	   ~CObjHero() {};
	   void Init();    //イニシャライズ
	   void Action();  //アクション
	   void Draw();    //ドロー
	   bool GetMoveFlag() { return move_flag; }

	   void SetPX(float x) { m_px = x; }
	   void SetPY(float y) { m_py = y; }
	   void SetActionflag(bool a) { action_flag = a; }
	   void SetNumlock(bool n) { numlock_flag = n; }
	   void SetLockpiece(int num, int p) { locknum = num;  wpiece = p; }
	   void SetHeroEventFlag(bool e, int number) { eventflag_h = e; eventnumber_h = number; }
	   void SetMoveVec(int v) { m_vec = v;  m_savevec = v;  hero_vec=v;  move_flag = true; }
	   void SetShowItemNumber(int i);
	   void SetHeroIn(bool in) { hero_in = in; }
	   void SetVec(int vec) { hero_vec = vec; }
  private:
	  float m_px; //位置
	  float m_py;
	  float m_vx; //移動ベクトル
	  float m_vy;
	  float m_posture; //姿勢
	  float m_speed; //歩く速度

	  int m_ani_time;
	  int m_ani_frame;
	  int locknum;    //解いているロックナンバー
	  int m_vec;      //動く方向を決める変数
	  int m_time;     //動いてる時の時間管理
	  int m_savevec;  //一個前の移動方向を保存する変数
	  int wpiece;     //何桁かの変数
	  int unlocknum[20];  //解読中のナンバー
	  int selectnum;  //左から何番目の数を動かすのか
	  int word;   //テキストウィンドウ制御
	  int hero_vec;   //主人公の向いている方向

	  bool move_flag; //動くためのフラグ
	  bool key_flag;//長押し防止
	  bool action_flag; //動いてもいいか
	  bool numlock_flag; //ナンバーロックを解いているか
	  bool Key_flag;     //キー制御フラグ
	  bool Itemcheck;    //アイテム詳細確認中フラグ
	  bool hero_in;    //主人公を表示するかどうか
};