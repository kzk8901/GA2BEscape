//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}
//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}
//���������\�b�h
void CSceneMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"kagi.png", 0, TEX_SIZE_64);
	Draw::LoadImageW(L"mes11_01_bk.png", 1, TEX_SIZE_512);
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
	Draw::LoadImageW(L"plant.png", 7, TEX_SIZE_32);
	Draw::LoadImageW(L"shelf.png", 8, TEX_SIZE_64);
	Draw::LoadImageW(L"carpet.png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"floor.png", 10, TEX_SIZE_64);
	Draw::LoadImageW(L"wall.png", 11, TEX_SIZE_64);
	Draw::LoadImageW(L"BlackBlock.png", 12, TEX_SIZE_32);
	Draw::LoadImageW(L"littledesk.png", 13, TEX_SIZE_128);
	Draw::LoadImageW(L"bed.png", 14, TEX_SIZE_64);
	Draw::LoadImageW(L"vase.png", 15, TEX_SIZE_32);
	Draw::LoadImageW(L"bookshelf.png", 16, TEX_SIZE_64);
	Draw::LoadImageW(L"flagcarpet.png", 17, TEX_SIZE_32);
	Draw::LoadImageW(L"fictionbookkey.png", 18, TEX_SIZE_64);
	Draw::LoadImageW(L"darkfloor.png", 19, TEX_SIZE_64);
	Draw::LoadImageW(L"memosetdesk.png", 20, TEX_SIZE_128);
	Draw::LoadImageW(L"spebookshelf.png", 21, TEX_SIZE_64);
	Draw::LoadImageW(L"desk.png", 22, TEX_SIZE_256);
	Draw::LoadImageW(L"safe.png", 23, TEX_SIZE_128);
	Draw::LoadImageW(L"pasu.png", 24, TEX_SIZE_256);
	Draw::LoadImageW(L"pasu2.png", 25, TEX_SIZE_256);
	Draw::LoadImageW(L"book.png", 26, TEX_SIZE_512);
	Draw::LoadImageW(L"memo1.png", 27, TEX_SIZE_512);
	Draw::LoadImageW(L"memo2.png", 28, TEX_SIZE_512);
	Draw::LoadImageW(L"memo3.png", 29, TEX_SIZE_512);
	Draw::LoadImageW(L"chair.png", 34, TEX_SIZE_16);
	Draw::LoadImageW(L"stairs.png", 35, TEX_SIZE_128);
	Draw::LoadImageW(L"door.png", 36, TEX_SIZE_64);
	Draw::LoadImageW(L"hako.png", 37, TEX_SIZE_64);
	Draw::LoadImageW(L"iceyuka.png", 38, TEX_SIZE_64);
	Draw::LoadImageW(L"mouse.png", 37, TEX_SIZE_128);

	//�A�C�e���֘A
	Draw::LoadImageW(L"inu.png", 30, TEX_SIZE_512);
	Draw::LoadImageW(L"nezumi.png", 31, TEX_SIZE_512);
	Draw::LoadImageW(L"usagi.png", 32, TEX_SIZE_512);
	Draw::LoadImageW(L"tori.png", 33, TEX_SIZE_512);

	//�A�C�e���I�u�W�F�N�g�쐬
	CObjItem* obji = new CObjItem();
	Objs::InsertObj(obji, OBJ_ITEM, 99);

	//�l�I�u�W�F�N�g�쐬
	CObjMouse* objm = new CObjMouse();
	Objs::InsertObj(objm, OBJ_MOUSE, 50);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 53);

	//�i���I�u�W�F�N�g�쐬
	CObjTowa* objw = new CObjTowa();
	Objs::InsertObj(objw, OBJ_TOWA, 61);

	//�t���I�u�W�F�N�g�쐬
	CObjKanata* objn = new CObjKanata();
	Objs::InsertObj(objn, OBJ_KANATA, 62);

	//�����I�u�W�F�N�g�쐬
	CObjKirara* objk = new CObjKirara();
	Objs::InsertObj(objk, OBJ_KIRARA, 60);

	//�w�i�I�u�W�F�N�g�쐬
	CObjBackGround* objg = new CObjBackGround();
	Objs::InsertObj(objg, OBJ_BGROUND, 9);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 98);

	//text�I�u�W�F�N�g�쐬
	CObjText* objt = new CObjText();
	Objs::InsertObj(objt, OBJ_TEXT, 100);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}
