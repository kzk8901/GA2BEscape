#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjBGMusic : public CObj
{
public:
	CObjBGMusic() {};
	~CObjBGMusic() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[

	//BGM�ύX�p�֐�
	void ChangeBGM(int bgmnum);

private:
	int NowBGM;

	bool PlayingSound[10];
};