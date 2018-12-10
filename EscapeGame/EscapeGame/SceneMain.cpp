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
	Draw::LoadImageW(L"it.png", 4, TEX_SIZE_512);
	Draw::LoadImageW(L"whitewindow.png", 5, TEX_SIZE_1024);
	Draw::LoadImageW(L"kirara.png", 6, TEX_SIZE_512);
	Draw::LoadImageW(L"kanata.png", 7, TEX_SIZE_512);
	Draw::LoadImageW(L"towa.png", 8, TEX_SIZE_512);

	Draw::LoadImageW(L"hero.png", 10, TEX_SIZE_128);

	Draw::LoadImageW(L"TemporaryPlacement.png", 6, TEX_SIZE_256);
	Draw::LoadImageW(L"�A���}�b�v�`�b�v.png", 7, TEX_SIZE_32);
	Draw::LoadImageW(L"�I�}�b�v�`�b�v.png", 8, TEX_SIZE_64);
	Draw::LoadImageW(L"�O�~�}�b�v�`�b�v(�d�|��������).png", 9, TEX_SIZE_512);
	Draw::LoadImageW(L"���}�b�v�`�b�v.png", 10, TEX_SIZE_64);
	Draw::LoadImageW(L"�ǃ}�b�v�`�b�v.png", 11, TEX_SIZE_64);
	Draw::LoadImageW(L"BlackBlock.png", 12, TEX_SIZE_32);
	Draw::LoadImageW(L"��(��)�}�b�v�`�b�v.png", 13, TEX_SIZE_128);
	Draw::LoadImageW(L"�x�b�g�}�b�v�`�b�v.png", 14, TEX_SIZE_64);
	Draw::LoadImageW(L"�ԕr�}�b�v�`�b�v.png", 15, TEX_SIZE_32);
	Draw::LoadImageW(L"�{�I�}�b�v�`�b�v.png", 16, TEX_SIZE_64);

	//�A�C�e���I�u�W�F�N�g�쐬
	CObjItem* obji = new CObjItem();
	Objs::InsertObj(obji, OBJ_ITEM, 15);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//�w�i�I�u�W�F�N�g�쐬
	CObjBackGround* objg = new CObjBackGround();
	Objs::InsertObj(objg, OBJ_BGROUND, 9);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	//text�I�u�W�F�N�g�쐬
	CObjText* objt = new CObjText();
	Objs::InsertObj(objt, OBJ_TEXT, 12);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}
