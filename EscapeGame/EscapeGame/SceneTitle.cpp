//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include "GameL\\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "ObjBGMusic.h"

//コントラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"脱出ゲーム");
	Draw::LoadImageW(L"Image\\タイトル.png", 0, TEX_SIZE_1024);

	//BGM取得
	Audio::LoadAudio(0, L"Sound\\BGM\\BGMTitle.wav", SOUND_TYPE::BACK_MUSIC);

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();
    Objs::InsertObj(obj,OBJ_TITLE, 10);

	//音楽設定
	CObjBGMusic* objbgm = new CObjBGMusic();
	Objs::InsertObj(objbgm, OBJ_AUDIO, 0);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}

