#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHero : public CObj
{
   public:
	   CObjHero() {};
	   ~CObjHero() {};
	   void Init();    //イニシャライズ
	   void Action();  //アクション
	   void Draw();    //ドロー

	   float GetX() { return m_px; }
	   float GetY() { return m_px; }
	   float GetVX() { return m_vx; }
	   float GetVY() { return m_vy; }

	   void SetX(float x) { m_px = x; }
	   void SetY(float y) { m_py = y; }
	   void SetVX(float vx) { m_vx = vx; }
	   void SetVY(float vy) { m_vy = vy; }


	   void SetUp(bool b) { m_hit_up = b; }
	   void SetDown(bool b) { m_hit_down = b; }
	   void SetLeft(bool b) { m_hit_left = b; }
	   void SetRight(bool b) { m_hit_right = b; }
   private:
	  float m_px; //位置
	  float m_py;
	  float m_vx; //移動ベクトル
	  float m_vy;
	  float m_posture; //姿勢
	  float m_speed; //歩く速度

	  int m_ani_time;
	  int m_ani_frame;

	  //blockとの衝突状態確認用
	  bool m_hit_up;
	  bool m_hit_down;
	  bool m_hit_left;
	  bool m_hit_right;
};