//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include "GameL\\Audio.h"
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
	Draw::LoadImageW(L"Image\\kagi.png", 0, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\mes11_01_bk.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\text2.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\��l��.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\image3.png", 3, TEX_SIZE_64);
	Draw::LoadImageW(L"Image\\whitewindow.png", 5, TEX_SIZE_1024);
	Draw::LoadImageW(L"Image\\�����.png", 50, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\�t��.png", 51, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\�i��.png", 52, TEX_SIZE_512);

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

	//�A�C�e���֘A
	Draw::LoadImageW(L"Image\\animal.png", 30, TEX_SIZE_512);
	Draw::LoadImageW(L"Image\\animal2.png", 33, TEX_SIZE_512);

	//SE�ݒ�
	Audio::LoadAudio(10, L"Sound\\SE\\SEDoor.wav", EFFECT);
	Audio::LoadAudio(11, L"Sound\\SE\\SECorrect.wav", EFFECT);
	Audio::LoadAudio(12, L"Sound\\SE\\SENocorrect.wav", EFFECT);
	Audio::LoadAudio(13, L"Sound\\SE\\SENumberlock.wav", EFFECT);
	Audio::LoadAudio(14, L"Sound\\SE\\SEItemGet.wav", EFFECT);
	Audio::LoadAudio(15, L"Sound\\SE\\SEMouse.wav", EFFECT);
	Audio::LoadAudio(16, L"Sound\\SE\\SEMovesound.wav", EFFECT);
	Audio::LoadAudio(17, L"Sound\\SE\\SEItemcheck.wav", EFFECT);

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
