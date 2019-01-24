#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjMouse : public CObj
{
public:
	CObjMouse() {};
	~CObjMouse() {};
	void Init();    //イニシャライズ
	void Action();  //アクション
	void Draw();    //ドロー

	void SetPos(float px, float py, int mapnum) { m_px = px; m_py = py; nezumap = mapnum; }
	void SetnowMap(int mapnum) { nowmap = mapnum; }
	void SetMovevec(int vec);

	int GetSavevec() { return savevec; }

	bool GetMoveflag() { return move_flag; }
private:
	float m_px; //位置
	float m_py;
	float m_vx; //移動ベクトル
	float m_vy;
	float m_posture; //姿勢
	float m_speed; //歩く速度

	int movevec; //動く方向
	int savevec; //ひとつ前の行動セーブ用
	int m_ani_time;
	int m_ani_frame;
	int nowmap;  //現在マップ
	int nezumap; //鼠がいるマップセーブ用
	int m_time;  

	bool move_flag;
};