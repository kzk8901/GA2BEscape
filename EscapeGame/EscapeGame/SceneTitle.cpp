//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
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
	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();
    Objs::InsertObj(obj,OBJ_TITLE, 10);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}

