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
	Draw::LoadImageW(L"image2.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"hakkou1.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"text2.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"zyo-zi.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"image3.png", 3, TEX_SIZE_64);
	Draw::LoadImageW(L"whitewindow.png", 5, TEX_SIZE_1024);
	Draw::LoadImageW(L"kirara.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"kanata.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"towa.png", 8, TEX_SIZE_512);

	Draw::LoadImageW(L"hero.png", 10, TEX_SIZE_128);


	//�A�C�e���I�u�W�F�N�g�쐬
	CObjItem* obji = new CObjItem();
	Objs::InsertObj(obji, OBJ_ITEM, 15);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//text�I�u�W�F�N�g�쐬
	CObjText* objt = new CObjText();
	Objs::InsertObj(objt, OBJ_TEXT, 11);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}
