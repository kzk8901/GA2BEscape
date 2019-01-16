//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}
//デストラクタ
CSceneMain::~CSceneMain()
{

}
//初期化メソッド
void CSceneMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"text1.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"text2.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"zyo-zi.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"image3.png", 3, TEX_SIZE_64);
	Draw::LoadImageW(L"whitewindow.png", 5, TEX_SIZE_1024);
	Draw::LoadImageW(L"kirara.png", 50, TEX_SIZE_512);
	Draw::LoadImageW(L"kanata.png", 51, TEX_SIZE_512);
	Draw::LoadImageW(L"towa.png", 52, TEX_SIZE_512);

	Draw::LoadImageW(L"kiraraMT.png", 60, TEX_SIZE_128);
	Draw::LoadImageW(L"kanataMT.png", 61, TEX_SIZE_128);
	Draw::LoadImageW(L"towaMT.png", 62, TEX_SIZE_128);
	Draw::LoadImageW(L"hero.png", 53, TEX_SIZE_128);

	Draw::LoadImageW(L"TemporaryPlacement.png", 6, TEX_SIZE_256);
	Draw::LoadImageW(L"植物マップチップ.png", 7, TEX_SIZE_32);
	Draw::LoadImageW(L"棚マップチップ.png", 8, TEX_SIZE_64);
	Draw::LoadImageW(L"絨毯マップチップ(仕掛け無い板).png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"床マップチップ.png", 10, TEX_SIZE_64);
	Draw::LoadImageW(L"壁マップチップ.png", 11, TEX_SIZE_64);
	Draw::LoadImageW(L"BlackBlock.png", 12, TEX_SIZE_32);
	Draw::LoadImageW(L"机(小)マップチップ.png", 13, TEX_SIZE_128);
	Draw::LoadImageW(L"ベットマップチップ.png", 14, TEX_SIZE_64);
	Draw::LoadImageW(L"花瓶マップチップ.png", 15, TEX_SIZE_32);
	Draw::LoadImageW(L"本棚マップチップ.png", 16, TEX_SIZE_64);
	Draw::LoadImageW(L"絨毯マップチップ(仕掛け).png", 17, TEX_SIZE_32);
	Draw::LoadImageW(L"fictionbookkey.png", 18, TEX_SIZE_64);
	Draw::LoadImageW(L"暗床マップチップ.png", 19, TEX_SIZE_64);
	Draw::LoadImageW(L"メモ付き机マップチップ.png", 20, TEX_SIZE_128);
	Draw::LoadImageW(L"本棚横マップチップ.png", 21, TEX_SIZE_64);
	Draw::LoadImageW(L"机マップチップ.png", 22, TEX_SIZE_256);
	Draw::LoadImageW(L"金庫マップチップ.png", 23, TEX_SIZE_128);
	Draw::LoadImageW(L"pasu.png", 24, TEX_SIZE_256);
	Draw::LoadImageW(L"pasu2.png", 25, TEX_SIZE_256);

	//アイテム関連
	Draw::LoadImageW(L"inu2.png", 30, TEX_SIZE_512);
	Draw::LoadImageW(L"nezumi2.png", 31, TEX_SIZE_512);
	Draw::LoadImageW(L"usagi2.png", 32, TEX_SIZE_512);
	Draw::LoadImageW(L"tori2.png", 33, TEX_SIZE_512);

	//アイテムオブジェクト作成
	CObjItem* obji = new CObjItem();
	Objs::InsertObj(obji, OBJ_ITEM, 99);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 53);

	//永遠オブジェクト作成
	CObjTowa* objw = new CObjTowa();
	Objs::InsertObj(objw, OBJ_TOWA, 61);

	//奏多オブジェクト作成
	CObjKanata* objn = new CObjKanata();
	Objs::InsertObj(objn, OBJ_KANATA, 62);

	//きららオブジェクト作成
	CObjKirara* objk = new CObjKirara();
	Objs::InsertObj(objk, OBJ_KIRARA, 60);

	//背景オブジェクト作成
	CObjBackGround* objg = new CObjBackGround();
	Objs::InsertObj(objg, OBJ_BGROUND, 9);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 98);

	//textオブジェクト作成
	CObjText* objt = new CObjText();
	Objs::InsertObj(objt, OBJ_TEXT, 100);

}

//実行中メソッド
void CSceneMain::Scene()
{

}
