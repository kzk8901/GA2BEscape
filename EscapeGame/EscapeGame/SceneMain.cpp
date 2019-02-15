//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\\Audio.h"
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
	Draw::LoadImageW(L"Image\\kagi.png", 0, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\mes11_01_bk.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\text2.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\主人公.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\image3.png", 3, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\whitewindow.png", 5, TEX_SIZE_1024);
	Draw::LoadImageW(L"Image\\きらら.png", 50, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\奏多.png", 51, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\永遠.png", 52, TEX_SIZE_512);

	Draw::LoadImageW(L"Image\\kiraraMT.png", 60, TEX_SIZE_256);
	Draw::LoadImageW(L"Image\\kanataMT.png", 61, TEX_SIZE_256);
	Draw::LoadImageW(L"Image\\towaMT.png", 62, TEX_SIZE_256);
	Draw::LoadImageW(L"Image\\heroMT.png", 53, TEX_SIZE_256);

	Draw::LoadImageW(L"Image\\TemporaryPlacement.png", 6, TEX_SIZE_256);
	Draw::LoadImageW(L"Image\\plant.png", 7, TEX_SIZE_32);
	Draw::LoadImageW(L"Image\\shelf.png", 8, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\carpet.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\floor.png", 10, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\wall.png", 11, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\BlackBlock.png", 12, TEX_SIZE_32);
	Draw::LoadImageW(L"Image\\littledesk.png", 13, TEX_SIZE_128);
	Draw::LoadImageW(L"Image\\bed.png", 14, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\vase.png", 15, TEX_SIZE_32);
	Draw::LoadImageW(L"Image\\bookshelf.png", 16, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\flagcarpet.png", 17, TEX_SIZE_32);
	Draw::LoadImageW(L"Image\\IceBlock.png", 18, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\darkfloor.png", 19, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\memosetdesk.png", 20, TEX_SIZE_128);
	Draw::LoadImageW(L"Image\\spebookshelf.png", 21, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\desk.png", 22, TEX_SIZE_256);
	Draw::LoadImageW(L"Image\\safe.png", 23, TEX_SIZE_128);
	Draw::LoadImageW(L"Image\\pasu.png", 24, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\pasu2.png", 25, TEX_SIZE_256);
	Draw::LoadImageW(L"Image\\book.png", 26, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\memo1.png", 27, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\memo2.png", 28, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\memo3.png", 29, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\chair.png", 34, TEX_SIZE_16);
	Draw::LoadImageW(L"Image\\stairs.png", 35, TEX_SIZE_128);
	Draw::LoadImageW(L"Image\\door.png", 36, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\hako.png", 37, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\iceyuka.png", 38, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\taru.png", 40, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\tana.png", 41, TEX_SIZE_256);
	Draw::LoadImageW(L"Image\\kagisetdesk.png", 44, TEX_SIZE_128);
	Draw::LoadImageW(L"Image\\danro.png", 45, TEX_SIZE_128);
	Draw::LoadImageW(L"Image\\wall2.png", 46, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\yazirusi.png", 63, TEX_SIZE_128);
	Draw::LoadImageW(L"Image\\food.png", 42, TEX_SIZE_256);
	Draw::LoadImageW(L"Image\\downstairs.png", 43, TEX_SIZE_128);
	Draw::LoadImageW(L"Image\\kagi2.png", 64, TEX_SIZE_64);
	

	Draw::LoadImageW(L"Image\\mouse.png", 39, TEX_SIZE_128);

	//アイテム関連
	Draw::LoadImageW(L"Image\\animal.png", 30, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\animal2.png", 33, TEX_SIZE_512);

	//SE設定
	Audio::LoadAudio(10, L"Sound\\SE\\SEDoor.wav", EFFECT);
	Audio::LoadAudio(11, L"Sound\\SE\\SECorrect.wav", EFFECT);
	Audio::LoadAudio(12, L"Sound\\SE\\SENocorrect.wav", EFFECT);
	Audio::LoadAudio(13, L"Sound\\SE\\SENumberlock.wav", EFFECT);
	Audio::LoadAudio(14, L"Sound\\SE\\SEItemGet.wav", EFFECT);
	Audio::LoadAudio(15, L"Sound\\SE\\SEMouse.wav", EFFECT);
	Audio::LoadAudio(16, L"Sound\\SE\\SEMovesound.wav", EFFECT);
	Audio::LoadAudio(17, L"Sound\\SE\\SEItemcheck.wav", EFFECT);

	//アイテムオブジェクト作成
	CObjItem* obji = new CObjItem();
	Objs::InsertObj(obji, OBJ_ITEM, 99);

	//鼠オブジェクト作成
	CObjMouse* objm = new CObjMouse();
	Objs::InsertObj(objm, OBJ_MOUSE, 50);

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
