#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
extern int text_m;
//�I�u�W�F�N�g�F�u���b�N���w�i
class CObjBackGround : public CObj
{
public:
	CObjBackGround() {};
	~CObjBackGround() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	void SetMapChip(int mpn, int mapsec, int mapthir, int mapchip) { m_map[mpn][mapsec][mapthir] = mapchip; mapnum = mpn; }
private:
	int m_map[5][15][20];//�}�b�v���
	int mapnum; //�}�b�v�i���o�[
	int animationtime;   //�A�j���[�V�����̂��߂̎��ԊǗ�
};