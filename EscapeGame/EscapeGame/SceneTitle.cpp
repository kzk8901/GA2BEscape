//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include "GameL\\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "ObjBGMusic.h"

//�R���g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"�E�o�Q�[��");
	Draw::LoadImageW(L"Image\\�^�C�g��.png", 0, TEX_SIZE_1024);

	//BGM�擾
	Audio::LoadAudio(0, L"Sound\\BGM\\BGMTitle.wav", SOUND_TYPE::BACK_MUSIC);

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();
    Objs::InsertObj(obj,OBJ_TITLE, 10);

	//���y�ݒ�
	CObjBGMusic* objbgm = new CObjBGMusic();
	Objs::InsertObj(objbgm, OBJ_AUDIO, 0);
}

//�Q�[�����C�����s�����\�b�h
void CSceneTitle::Scene()
{

}

