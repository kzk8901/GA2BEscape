//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjItem.h"
#include "ObjBlock.h"
#include "ObjBackGround.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;
bool room_c[3] = { false,false,false };
bool text_loop = true;
int text_m = -1;
bool event_skip = false;
//マップ情報--------------------------------------------
//1 = 壁, 2 = 主人公初期位置, 3 = 鍵付き壁(特定のカギ持っていれば開く)
//4 = 鍵おいてます, 5 = ナンバーロックドア , 6 = 偽アイテム
int block_data_map[8][15][20] =
{
	//スタートマップ1F mapnum==0
	{
		// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{  1, 1, 1, 1, 1, 1, 1, 1, 1,99, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{  1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, },// 1
		{  1,30,31,31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,31,31,30, 1, },// 2
		{  1, 0, 0, 0,45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 3
		{  1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 1, },// 4
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{ 95, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,97, },// 7
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{  1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, },//12
		{  1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 9, 0, 0, 0, 1, 1, 1, 1, 1, 1, },//13
		{  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//奏多マップ1Fmapnum==1
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1,93, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1,39,39,39,39,39,39,39,47, 0, 0, 0,35,35,35,35,35,35,35, 1, },// 1
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 3
		{ 1,35,38,35,35,35,35,35, 0, 0, 0, 0,35,35,35,35,35,35,35, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{ 1,35,35,35,35,35,35,35, 0, 0, 0, 0,35,35,35,35,35,35,35, 1, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,48,50,50,50,50,50,48, 1, },// 9
		{ 1, 0, 0, 0,10, 0, 0, 0, 0, 0, 0, 0, 0,50,50,50,50,50, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,48,50,50,50,50,50,48, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,50,51,50,50,50, 0, 1, },//12
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1,98, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//永遠マップ1Fmapnum==2
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1, 0, 0, 0, 0,33,41, 0, 0,43,31, 0, 0,42,33, 0, 0, 0, 0, 1, },// 1
		{ 1, 0, 0, 0, 0,33,33, 0, 0, 0, 0, 0, 0,33,33, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0,45,33,33, 0, 0, 0, 0, 0, 0,33,33,46, 0, 0, 0, 1, },// 3
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{96, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,40, 1, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//12
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//きららマップ1Fmapnum==3
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1, 0,44,34, 0, 0, 0, 0, 0, 0,35,35, 0,37,37, 0,35,35, 0, 1, },// 1
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0,45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 1, },// 3
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,94, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//12
		{ 1,30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,30, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//スタートマップ2F mapnum==4
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1,91, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 1
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 3
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,89, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//12
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//13
		{ 1,92, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//永遠2F mapnum==5
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 1
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 3
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//12
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1,90, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//奏多2F mapnum==6
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 1
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 2
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 3
		{ 1,35,35,35,35,35,35,35, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 4
		{ 1,60, 0,60, 0,60, 0,48, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 5
		{ 1, 0,60, 0,60, 0,60,48, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 6
		{88, 2, 0,60, 0,60, 0,48, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 7
		{ 1,10, 0,60,60, 0,60,48, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 8
		{ 1,60,60, 0, 0, 0, 0,48, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 9
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//10
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//11
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//12
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},

	//きらら2F mapnum==7
	{
		//0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },// 0
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 1
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 2
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 3
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 4
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 5
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 6
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,86, },// 7
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 8
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },// 9
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//10
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//11
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//12
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//13
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, },//14
	},
};
//マップ情報-------------------------------------------------
//イニシャライズ
void CObjBlock::Init()
{

	mapnum = 0;

	//主人公の位置を設定
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//マップデータをコピー
	memcpy(m_map, block_data_map, sizeof(int)*(8 * 15 * 20));

	SetHero();
	SetKirara();
	SetKanata();
	SetTowa();

	eventclockflag = false;
	eventclocktime = 0;
	blockx = 0;
	blocky = 0;
	blockm_x = 0.0f;
	blockm_y = 0.0f;
	moveshelf = 0.0f;
	blockdeleteYN = false;
	animationtime = 0;
	event_num = 0;
	lockpasu = 0;
	for (int i=0; i < 8; i++)
		event_clock[i] = false;

	((UserData*)Save::GetData())->number[0] = 402;
	((UserData*)Save::GetData())->number[1] = 402;
	((UserData*)Save::GetData())->number[2] = 112;

	//当たり判定のあるブロックはナンバーをここに入れる
	int blocknumber[99] =
	{
		1, 3, 5, 7, 8, 9,10,30,31,32,
		33,34,35,36,37,38,39,40,41,42,
		43,44,50,51,52,60,62,
	};

	for (int i = 0; i < 99; i++)
	{
		notonblock[i] = blocknumber[i];
	}
}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を設定
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//背景を設定
	CObjBackGround* bgro = (CObjBackGround*)Objs::GetObj(OBJ_BGROUND);
	//アイテム参照
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);
	//きららの位置を設定
	CObjKirara* kirara = (CObjKirara*)Objs::GetObj(OBJ_KIRARA);
	//永遠の位置を設定
	CObjTowa* towa = (CObjTowa*)Objs::GetObj(OBJ_TOWA);
	//奏多の位置を設定
	CObjKanata* kanata = (CObjKanata*)Objs::GetObj(OBJ_KANATA);

	//会話イベント動き↓-------------------------------------------------
	if (Input::GetVKey('O') == true)
	{
		event_num = 1;
		event_skip = true;
	}
	//デバック用------------------------------------------------
	if (Input::GetVKey('P') == true)
	{
		event_num = 9;
	}
	if (Input::GetVKey('L') == true)
	{
		event_num = 19;
	}
	if (Input::GetVKey('K') == true)
	{
		event_num = 13;
	}
	if (Input::GetVKey('J') == true)
	{
		event_num = 30;
	}
	//----------------------------------------------------------


	//オープニング開始---------------------------------
	//イベントナンバー(1〜9)
	if (event_num==1)
	{
		hero->SetHeroEventFlag(true,1);
	}
	if (event_num==2)
	{
		towa->SetTowaEventFlag(true, 1);
	}
	if (event_num==3)
	{
		hero->SetHeroEventFlag(true, 2);
	}
	if (event_num == 4)
	{
		kanata->SetKanataEventFlag(true, 1);
	}
	if (event_num == 5)
	{
		kirara->SetKiraraEventFlag(true, 1);
	}
	if (event_num == 6)
	{
		hero->SetVec(3);
		kanata->SetVec(3);
		event_num=7;
	}
	if (event_num == 7)
	{
		kanata->SetKanataEventFlag(true, 2);
	}
	if (event_num == 8)
	{
		towa->SetTowaEventFlag(true, 2);
	}
	if (event_num == 9)
	{
		towa->SetTowaEventFlag(true, 3);
		kanata->SetKanataEventFlag(true, 3);
		kirara->SetKiraraEventFlag(true, 2);
		hero_move = true;
	}
	//オープニング終了---------------------------------

	//奏多マップ1Fイベ開始-----------------------------
	//イベントナンバー(10〜15)
	//部屋に入ったとき
	if (event_clock[0] == false)
	{
		if (event_num == 10)
			hero->SetHeroEventFlag(true, 3);
		if (event_num == 11)
		{
			kanata->SetVec(1);
			event_num = 12;
		}
		if (event_num == 12)
		{
			event_num = 99;
			event_clock[0] = true;
		}	
	}
	//メモを入手した後
	if (event_num == 13)
		hero->SetHeroEventFlag(true, 4);
	if (event_num == 14)
	{
		kanata->SetVec(1);
		event_num = 15;
	}
	if (event_num == 15)
	{
		event_num = 99;
	}
	//奏多マップ1Fイベ終了-----------------------------

	//永遠マップ1Fイベ開始-----------------------------
	//イベントナンバー(16〜21)
	//部屋に入ったとき
	if (event_clock[1] == false)
	{
		if (event_num == 16)
			hero->SetHeroEventFlag(true, 5);
		if (event_num == 17)
		{
			towa->SetVec(2);
			event_num = 18;
		}
		if (event_num == 18)
		{
			event_num = 99;
			event_clock[1] = true;
		}
	}
	//メモを入手した後
	if (event_num == 19)
		hero->SetHeroEventFlag(true, 6);
	if (event_num == 20)
	{
		kanata->SetVec(3);
		event_num = 21;
	}
	if (event_num == 21)
	{
		event_num = 99;
	}

	//永遠マップ1Fイベ終了-----------------------------

	//きららマップ1Fイベ開始-----------------------------
	//イベントナンバー(22〜26)
	//部屋に入ったとき
	if (event_clock[2] == false)
	{
		if (event_num == 22)
			hero->SetHeroEventFlag(true, 7);
		if (event_num == 23)
		{
			event_num = 99;
			event_clock[2] = true;
		}
	}
	//メモを入手した後
	if (event_num == 24)
	{
		hero->SetVec(1);
		event_num = 25;
	}
	if (event_num == 25)
	{
		kirara->SetKiraraEventFlag(true,3);
	}
	if (event_num == 26)
	{
		event_num = 99;
	}

	//きららマップ1Fイベ終了-----------------------------

	//1F集合イベント開始---------------------------------
	//イベントナンバー(27、28)---------------------------
	if (event_num == 27)
	{
		word = 0;
		text_m = 6;
		hero->SetActionflag(true);
		hero->SetVec(1);
		kirara->SetVec(1);
		kanata->SetVec(2);
		towa->SetVec(2);
		event_num = 28;
	}
	if (event_num == 28)
	{
		event_clock[3] = true;
		event_num = 99;
	}
	//1F集合イベント終了---------------------------------

	//2F集合イベント開始---------------------------------
	//イベントナンバー(29〜33)---------------------------
	if (event_num == 29)
	{
		word = 0;
		text_m = 7;
		hero->SetActionflag(true);
		hero->SetVec(1);
		kirara->SetVec(1);
		kanata->SetVec(2);
		towa->SetVec(2);
		event_num = 30;
	}
	if (event_num == 30)
	{
		kirara->SetKiraraEventFlag(true, 4);
	}
	if (event_num == 31)
	{
		kanata->SetKanataEventFlag(true, 4);
	}
	if (event_num == 32)
	{
		towa->SetTowaEventFlag(true, 4);
	}
	if (event_num == 33)
	{
		kirara->SetKiraraEventFlag(true, 5);
		kanata->SetKanataEventFlag(true, 5);
		towa->SetTowaEventFlag(true, 5);
		event_clock[4] = true;
	}
	//2F集合イベント終了---------------------------------

	//移動マスを配置する---------------------------------
	if (event_num == 98)
	{
		if (mapnum == 0)
		{
			m_map[mapnum][kirara_y][kirara_x] = 95;
			m_map[mapnum][towa_y][towa_x] = 97;
			m_map[mapnum][kanata_y][kanata_x] = 99;
		}
		else if (mapnum == 4)
		{
			m_map[mapnum][kirara_y][kirara_x] = 87;
			m_map[mapnum][towa_y][towa_x] = 91;
			m_map[mapnum][kanata_y][kanata_x] = 89;
		}
		event_num = 99;
	}

	//主人公が探索を開始する---------------------------
	//イベントナンバー(99)
	if (event_num == 99)
	{
		hero->SetActionflag(false);
		event_num = 0;
	}

	//会話イベント動き↑-------------------------------------------------

	//氷床を歩く
	if (m_map[mapnum][hero_y][hero_x] == 61)
	{
		hero->SetHeroEventFlag(true, 100);
	}

	//スタートF1へ移動---------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 98 && hero->GetMoveFlag() == false||
		m_map[mapnum][hero_y][hero_x] == 96 && hero->GetMoveFlag() == false||
		m_map[mapnum][hero_y][hero_x] == 94 && hero->GetMoveFlag() == false)
	{
		text_loop = true;
		text_m = -2;
		//主人公の位置保存
		//奏多
		if (m_map[mapnum][hero_y][hero_x] == 98)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 2;
		}
		//永遠
		else if (m_map[mapnum][hero_y][hero_x] == 96)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 2;
		}
		//きらら
		else if (m_map[mapnum][hero_y][hero_x] == 94)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 2;
		}
		//次に行くナンバーを渡す
		Mapchange(0);
		//次のmapnumを入れる
		mapnum = 0;
		//アイテムがそろった状態で戻ってきた時
		if (itm->CheckItem( 9) == true &&
			itm->CheckItem(10) == true && 
			itm->CheckItem(11) == true && 
			event_clock[3] == false)
		{
			//キャラの位置を一度リセット
			block_data_map[0][hero_y][hero_x] = 0;
			block_data_map[1][kanata_y][kanata_x] = 0;
			block_data_map[2][towa_y][towa_x] = 0;
			block_data_map[3][kirara_y][kirara_x] = 0;

			//キャラを配置
			m_map[0][8][6] = 2;
			m_map[0][8][13] = 9;
			m_map[0][4][13] = 10;
			m_map[0][4][6] = 8;
			SetTowa();
			SetKanata();
			SetKirara();

			event_clock[3] = true;

			event_num = 27;
		}
		//ヒロイン表示
		if (event_clock[3] == false)
		{
			kanata->SetKanataIn(false);
			towa->SetTowaIn(false);
			kirara->SetKiraraIn(false);
		}
		else
		{
			kanata->SetKanataIn(true);
			towa->SetTowaIn(true);
			kirara->SetKiraraIn(true);
		}
		//主人公の位置更新
		SetHero();
	}

	//奏多マップ1Fへ移動-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 99 && hero->GetMoveFlag() == false||
		m_map[mapnum][hero_y][hero_x] == 92 && hero->GetMoveFlag() == false)
	{
		word=0;
		text_loop = true;
		if (room_c[0] == false)
		{
			text_m = 1;
			room_c[0] = true;
		}
		else if(room_c[0] == true)
		{
			text_m = -4;
		}
		//主人公の位置保存
		//1Fロビーから
		if (m_map[mapnum][hero_y][hero_x] == 99)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 2;
		}
		//2Fロビーから
		else if (m_map[mapnum][hero_y][hero_x] == 92)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 2;
		}
		//次に行くナンバーを渡す
		Mapchange(1);
		//次のmapnumを入れる
		mapnum = 1;
		//奏多表示
		if (event_clock[3] == false)
			kanata->SetKanataIn(true);
		else
		{
			kanata->SetKanataIn(false);
			towa->SetTowaIn(false);
			kirara->SetKiraraIn(false);
		}
		//主人公の位置更新
		SetHero();
		//奏多の位置更新
		SetKanata();
		//初めて部屋に入ったらイベントを起こす
		event_num = 10;
	}

	//永遠マップ1Fへ移動-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 97 && hero->GetMoveFlag() == false)
	{
		word = 0;
		text_loop = true;
		if (room_c[1] == false)
		{
			text_m = 2;
			room_c[1] = true;
		}
		else if (room_c[1] == true)
		{
			text_m = -5;
		}
		//主人公の位置保存
		m_map[mapnum][hero_y][hero_x - 1] = 2;
		//次に行くナンバーを渡す
		Mapchange(2);
		//次のmapnumを入れる
		mapnum = 2;
		//永遠表示
		if (event_clock[3] == false)
			towa->SetTowaIn(true);
		else
		{
			kanata->SetKanataIn(false);
			towa->SetTowaIn(false);
			kirara->SetKiraraIn(false);
		}
		//主人公の位置更新
		SetHero();
		//永遠の位置更新
		SetTowa();
		//初めて部屋に入ったらイベントを起こす
		event_num = 16;
	}

	//きららマップ1Fへ移動-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 95 && hero->GetMoveFlag() == false)
	{
		word = 0;
		text_loop = true;
		if (room_c[2] == false)
		{
			text_m = 0;
			room_c[2] = true;
		}
		else if (room_c[2] == true)
		{
			text_m = -3;
		}
		//主人公の位置保存
		m_map[mapnum][hero_y][hero_x + 1] = 2;
		//次に行くナンバーを渡す
		Mapchange(3);
		//次のmapnumを入れる
		mapnum = 3;
		//きらら表示
		if (event_clock[3] == false)
			kirara->SetKiraraIn(true);
		else
		{
			kanata->SetKanataIn(false);
			towa->SetTowaIn(false);
			kirara->SetKiraraIn(false);	
		}
		//主人公の位置更新
		SetHero();
		//きららの位置更新
		SetKirara();
		//初めて部屋に入ったらイベントを起こす
		event_num = 22;
	}

	//ロビーF2へ移動---------------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 93 && hero->GetMoveFlag() == false ||
		m_map[mapnum][hero_y][hero_x] == 90 && hero->GetMoveFlag() == false ||
		m_map[mapnum][hero_y][hero_x] == 88 && hero->GetMoveFlag() == false ||
		m_map[mapnum][hero_y][hero_x] == 86 && hero->GetMoveFlag() == false)
	{
		text_loop = true;
		text_m = -2;
		//主人公の位置保存
		//奏多1F
		if (m_map[mapnum][hero_y][hero_x] == 93)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 2;
		}
		//奏多2F
		else if (m_map[mapnum][hero_y][hero_x] == 88)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 2;
		}
		//永遠2F
		else if (m_map[mapnum][hero_y][hero_x] == 90)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 2;
		}
		//きらら2F
		else if (m_map[mapnum][hero_y][hero_x] == 86)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 2;
		}
		//次に行くナンバーを渡す
		Mapchange(4);
		//次のmapnumを入れる
		mapnum = 4;
		//初めて入ったらイベントを起こす
		if (event_clock[4] == false)
		{
			//キャラの位置を一度リセット
			block_data_map[4][hero_y][hero_x] = 0;
			block_data_map[0][kanata_y][kanata_x] = 0;
			block_data_map[0][towa_y][towa_x] = 0;
			block_data_map[0][kirara_y][kirara_x] = 0;

			//キャラを配置
			m_map[4][4][ 6] = 2; //主人公
			m_map[4][4][13] = 9; //永遠
			m_map[4][8][13] = 10;//奏多
			m_map[4][8][ 6] = 8; //きらら
			SetTowa();
			SetKanata();
			SetKirara();

			event_num = 29;
		}
		//ヒロイン表示
		if (event_clock[4] == true)
		{
			kanata->SetKanataIn(false);
			towa->SetTowaIn(false);
			kirara->SetKiraraIn(false);
		}
		else
		{
			kanata->SetKanataIn(true);
			towa->SetTowaIn(true);
			kirara->SetKiraraIn(true);
		}
		//主人公の位置更新
		SetHero();
	}

	//永遠マップ2Fへ移動-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 91 && hero->GetMoveFlag() == false)
	{
		/*word = 0;
		text_loop = true;
		if (room_c[1] == false)
		{
			text_m = 2;
			room_c[1] = true;
		}
		else if (room_c[1] == true)
		{
			text_m = -5;
		}*/
		//主人公の位置保存
		m_map[mapnum][hero_y + 1][hero_x] = 2;
		//次に行くナンバーを渡す
		Mapchange(5);
		//次のmapnumを入れる
		mapnum = 5;
		//永遠表示
		towa->SetTowaIn(true);
		//主人公の位置更新
		SetHero();
		//永遠の位置更新
		SetTowa();
		//初めて部屋に入ったらイベントを起こす
		//event_num = ;
	}

	//奏多マップ2Fへ移動-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 89 && hero->GetMoveFlag() == false)
	{
		/*word = 0;
		text_loop = true;
		if (room_c[0] == false)
		{
			text_m = 1;
			room_c[0] = true;
		}
		else if (room_c[0] == true)
		{
			text_m = -4;
		}*/
		//主人公の位置保存
		m_map[mapnum][hero_y][hero_x - 1] = 2;
		//次に行くナンバーを渡す
		Mapchange(6);
		//次のmapnumを入れる
		mapnum = 6;
		//奏多表示
		kanata->SetKanataIn(true);
		//主人公の位置更新
		SetHero();
		//奏多の位置更新
		SetKanata();
		//初めて部屋に入ったらイベントを起こす
		//event_num = ;
	}
	//奏多F2部屋つみ防止リセットボタン-----------------------
	if (Input::GetVKey('R') == true&&mapnum==6)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				m_map[mapnum][i][j] = block_data_map[mapnum][i][j];
			}
		}
		hero->SetVec(1);
		SetHero();
	}


	//きららマップ2Fへ移動-------------------------------
	if (m_map[mapnum][hero_y][hero_x] == 87 && hero->GetMoveFlag() == false)
	{
		/*word = 0;
		text_loop = true;
		if (room_c[2] == false)
		{
			text_m = 0;
			room_c[2] = true;
		}
		else if (room_c[2] == true)
		{
			text_m = -3;
		}*/
		//主人公の位置保存
		m_map[mapnum][hero_y][hero_x + 1] = 2;
		//次に行くナンバーを渡す
		Mapchange(7);
		//次のmapnumを入れる
		mapnum = 7;
		//きらら表示
			kirara->SetKiraraIn(true);
		//主人公の位置更新
		SetHero();
		//きららの位置更新
		SetKirara();
		//初めて部屋に入ったらイベントを起こす
		//event_num = ;
	}

	//----------------------------------------------

	//壁開ける用イベントフラグ
	if (eventclockflag == true)
	{
		hero->SetHeroEventFlag(true, 0);
		eventclocktime++;
		//------------------------------
		if (blockmovevec == 1)
			blockm_x += 0.5;
		if (blockmovevec == 2)
			blockm_x -= 0.5;
		if (blockmovevec == 3)
			blockm_y -= 0.5;
		if (blockmovevec == 4)
			blockm_y += 0.5;
		//------------------------------
		if (eventclocktime > 64)
		{
			hero->SetHeroEventFlag(false, 0);
			eventclocktime = 0;
			eventclockflag = 0;
			//ブロックを消さない際の動き
			if (blockdeleteYN == true)
			{
				if (blockmovevec == 1)
					m_map[mapnum][blocky][blockx + 1] = 1;
				if (blockmovevec == 2)
					m_map[mapnum][blocky][blockx - 1] = 1;
				if (blockmovevec == 3)
					m_map[mapnum][blocky - 1][blockx] = 1;
				if (blockmovevec == 4)
					m_map[mapnum][blocky + 1][blockx] = 1;
			}
			//後処理（初期化等）-----------
			if (blockmovevec == 1 || blockmovevec == 2)
				blockm_x = 0.0;
			if (blockmovevec == 3 || blockmovevec == 4)
				blockm_y = 0.0;
			//------------------------------
			m_map[mapnum][blocky][blockx] = 0;
		}
	}

	//棚動かす用イベントフラグ---------------------------
	if (moveshelf > 0.0f)
	{
		bool finishflag = false;
		hero->SetHeroEventFlag(true, 0);
		eventclocktime++;
		moveshelf += 0.5;
		if (eventclocktime > 64)
		{
			hero->SetHeroEventFlag(false, 0);
			eventclocktime = 0;
			for (int i = 0; finishflag == false; i++)
			{
				if (m_map[mapnum][blocky][blockx + i] != 39)
				{
					m_map[mapnum][blocky][blockx + i] = 36;
					for (int j = 1; finishflag == false; j++)
					{
						if (m_map[mapnum][blocky][blockx + i - j] == 39)
						{
							m_map[mapnum][blocky][blockx + i - j] = 36;
						}
						else if (m_map[mapnum][blocky][blockx  + i - j] != 39)
						{
							m_map[mapnum][blocky][blockx + i - j + 1] = 0;
							finishflag = true;
						}
					}
				}
			}
			//後処理
			moveshelf = 0.0f;
			blockx = 0;
			blocky = 0;
		}
	}

	//アニメーション動かす用
	animationtime++;
	if (animationtime >= 61)
	{
		animationtime = 0;
	}

	//状況に合わせて常に
	//背景切り替え
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			bgro->SetMapChip(mapnum, i, j, m_map[mapnum][i][j]);
		}
	}
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画表示位置

	//テキストウィンドウ2（縦向き）
	src.m_top = 10.0f;
	src.m_left = 10.0f;
	src.m_right = 230.0f;
	src.m_bottom = 495.0f;
	dst.m_top = 0.0f;
	dst.m_left =640.0f;
	dst.m_right =800.0f;
	dst.m_bottom = 480.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);



	//マップチップによるblock設置
	//切り取り位置の設定
	/*
	src.m_top = 0.0f;
	src.m_left = 320.5f;
	src.m_right =src.m_left+64.0f;
	src.m_bottom = 64.0f;
	*/

	for(int i=0;i<15;i++)
	{
		for(int j=0;j<20;j++)
		{
			//鍵付き扉表示
			if (m_map[mapnum][i][j] == 3)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}
			//鍵表示
			if (m_map[mapnum][i][j] == 4)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//ナンバーロックドア
			if (m_map[mapnum][i][j] == 5)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(3, &src, &dst, c, 0.0f);
			}
			//偽鍵表示
			if (m_map[mapnum][i][j] == 6)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 384.0f;
				src.m_right = 448.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//偽ブロック表示
			if (m_map[mapnum][i][j] == 7)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 320.5f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f + blockm_y;
				dst.m_left = j*32.0f + blockm_x;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			//----------------------------------------

			//家具等マップ内障害物--------------------
			//植物表示
			if (m_map[mapnum][i][j] == 30)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 16.0f;
				src.m_bottom = src.m_top + 32.0f;
				//表示位置の設定
				dst.m_top = i*32.0f-32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//描画
				Draw::Draw(7, &src, &dst, c, 0.0f);
			}
			//棚表示
			if (m_map[mapnum][i][j] == 31 || m_map[mapnum][i][j] == 34 || m_map[mapnum][i][j] == 43 || m_map[mapnum][i][j] == 44)
			{
				int skipcount = 0;
				int vase = 0;

				//花瓶の表示をする
				if (m_map[mapnum][i][j] == 34)
				{
					vase = 1;
				}

				if (m_map[mapnum][i][j + 1] == 31 || m_map[mapnum][i][j + 1] == 34 || m_map[mapnum][i][j + 1] == 43 || m_map[mapnum][i][j + 1] == 44)
				{
					skipcount++;
					//花瓶の表示をする
					if (m_map[mapnum][i][j + 1] == 34)
					{
						vase = 2;
					}
				}

				//棚表示
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f * (skipcount + 1);
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(8, &src, &dst, c, 0.0f);

				if (vase >= 1)
				{
					//切り取り位置の設定
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 32.0f;
					//表示位置の設定
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = (j + vase - 1) * 32.0f + 8.0f;
					dst.m_right = dst.m_left + 32.0f - 8.0f;
					dst.m_bottom = dst.m_top + 32.0f - 8.0f;

					//描画
					Draw::Draw(15, &src, &dst, c, 0.0f);
				}

				j += skipcount;
			}
			//机(小)表示
			if (m_map[mapnum][i][j] == 32)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 128.0f;
				src.m_bottom = src.m_top + 128.0f;

				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(13, &src, &dst, c, 0.0f);
			}
			//倉庫番用箱表示
			if (m_map[mapnum][i][j] == 60)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;

				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(37, &src, &dst, c, 0.0f);
			}
			//滑る床障害物（仮）
			if (m_map[mapnum][i][j] == 62)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 64.0f;
				src.m_bottom = src.m_top + 64.0f;

				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(38, &src, &dst, c, 0.0f);
				//描画
				Draw::Draw(18, &src, &dst, c, 0.0f);
			}
			//ベッド表示
			if (m_map[mapnum][i][j] == 33 ||
				m_map[mapnum][i][j] == 41 ||
				m_map[mapnum][i][j] == 42)
			{
				int skipcountx = 0;
				int county = 0;
				bool skip = false;

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 32.0f;
				src.m_bottom = src.m_top + 64.0f;

				if (m_map[mapnum][i + 1][j] == 33 || m_map[mapnum][i + 1][j] == 41 || m_map[mapnum][i + 1][j] == 42)
				{
					skip = true;
				}
				for (int s = 1; m_map[mapnum][i][j + s] == 33 || m_map[mapnum][i][j + s] == 41 || m_map[mapnum][i][j + s] == 42; s++)
				{
					skipcountx++;
				}
				while (m_map[mapnum][i - 1 - county][j] == 33 || m_map[mapnum][i - 1 - county][j] == 41 || m_map[mapnum][i - 1 - county][j] == 42)
				{
					county++;
				}

				if (skip == false)
				{
					//表示位置の設定
					dst.m_top = (i - county)*32.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
					dst.m_bottom = dst.m_top + 32.0f * (county + 1);

					//描画
					Draw::Draw(14, &src, &dst, c, 0.0f);
				}

				j += skipcountx;
			}
			//本棚表示
			if ((m_map[mapnum][i][j] == 35  
				|| m_map[mapnum][i][j] == 36 
				|| m_map[mapnum][i][j] == 37
				|| m_map[mapnum][i][j] == 38) 
				&& hero_y < i)
			{
				if (m_map[mapnum][i + 1][j] == 35 || m_map[mapnum][i + 1][j] == 36 || m_map[mapnum][i + 1][j] == 37 || m_map[mapnum][i + 1][j] == 38)
				{
					//切り取り位置の設定
					src.m_top = 0.0f;
					src.m_left = 32.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 32.0f;

					//表示位置の設定
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//描画
					Draw::Draw(21, &src, &dst, c, 0.0f);
				}
				else if (m_map[mapnum][i - 1][j] == 35 || m_map[mapnum][i - 1][j] == 36 || m_map[mapnum][i - 1][j] == 37 || m_map[mapnum][i - 1][j] == 38)
				{
					//切り取り位置の設定
					src.m_top = 0.0f;
					src.m_left = 0.0f;
					src.m_right = src.m_left + 32.0f;
					src.m_bottom = src.m_top + 64.0f;

					//表示位置の設定
					dst.m_top = i*32.0f - 16.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f;
					dst.m_bottom = dst.m_top + 32.0f;

					//描画
					Draw::Draw(21, &src, &dst, c, 0.0f);
				}
				else
				{
					int skipcountx = 0;
					int overcount = 0;

					for (int s = 1; m_map[mapnum][i][j + s] == 35 || m_map[mapnum][i][j + s] == 36 || m_map[mapnum][i][j + s] == 37 || m_map[mapnum][i][j + s] == 38; s++)
					{
						skipcountx++;
						if (skipcountx == 5)
						{
							skipcountx = 1;
							overcount += 1;
						}
					}

					for (int x = 0; x <= skipcountx;)
					{
						if (overcount > 0)
						{
							//切り取り位置の設定
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 64.0f;
							src.m_bottom = src.m_top + 64.0f;

							//表示位置の設定
							dst.m_top = i*32.0f - 16.0f;
							dst.m_left = j*32.0f;
							dst.m_right = dst.m_left + 128.0f;
							dst.m_bottom = dst.m_top + 64.0f;

							x += 4;
							overcount -= 1;
						}
						else
						{
							//切り取り位置の設定
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 16.0f * (skipcountx + 1);
							src.m_bottom = src.m_top + 64.0f;

							//表示位置の設定
							dst.m_top = i*32.0f - 16.0f;
							dst.m_left = j*32.0f;
							dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
							dst.m_bottom = dst.m_top + 64.0f;

							x += skipcountx;
							if (skipcountx == 0)
								x++;
						}
					}

					//描画
					Draw::Draw(16, &src, &dst, c, 0.0f);

					j += skipcountx;
				}
			}
			//動く本棚表示
			if (m_map[mapnum][i][j] == 39 && hero_y < i)
			{
				int skipcountx = 0;
				int overcount = 0;
				for (int s = 1; m_map[mapnum][i][j + s] == 39; s++)
				{
					skipcountx++;
					if (skipcountx == 5)
					{
						skipcountx = 1;
						overcount += 1;
					}
				}
				for (int x = 0; x <= skipcountx;)
				{
					if (overcount > 0)
					{
						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 64.0f;
						src.m_bottom = src.m_top + 64.0f;

						//表示位置の設定
						dst.m_top = i*32.0f - 16.0f;
						dst.m_left = j*32.0f + moveshelf;
						dst.m_right = dst.m_left + 128.0f;
						dst.m_bottom = dst.m_top + 32.0f * 2;

						x += 4;
						overcount -= 1;
					}
					else
					{
						//切り取り位置の設定
						src.m_top = 0.0f;
						src.m_left = 0.0f;
						src.m_right = src.m_left + 16.0f * (skipcountx + 1);
						src.m_bottom = src.m_top + 64.0f;

						//表示位置の設定
						dst.m_top = i *32.0f - 16.0f;
						dst.m_left = j*32.0f + moveshelf;
						dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
						dst.m_bottom = dst.m_top + 32.0f * 2;

						x += skipcountx;
					}
				}

				//描画
				Draw::Draw(16, &src, &dst, c, 0.0f);

				j += skipcountx;
			}
			//メモあり机表示
			if (m_map[mapnum][i][j] == 40)
			{
				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 128.0f;
				src.m_bottom = src.m_top + 128.0f;

				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//描画
				Draw::Draw(20, &src, &dst, c, 0.0f);
			}
			//大机(51の位置に金庫を置く)
			if (m_map[mapnum][i][j] == 50 || m_map[mapnum][i][j] == 51 || m_map[mapnum][i][j] == 52)
			{
				int skipcountx = 0;
				int county = 0;
				bool skip = false;

				//切り取り位置の設定
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = src.m_left + 256.0f;
				src.m_bottom = src.m_top + 256.0f;

				if (m_map[mapnum][i + 1][j] == 50 || m_map[mapnum][i + 1][j] == 51 || m_map[mapnum][i + 1][j] == 52)
				{
					skip = true;
				}
				for (int s = 1; m_map[mapnum][i][j + s] == 50 || m_map[mapnum][i][j + s] == 51 || m_map[mapnum][i][j + s] == 52; s++)
				{
					skipcountx++;
				}
				while (m_map[mapnum][i - 1 - county][j] == 50 || m_map[mapnum][i - 1 - county][j] == 51 || m_map[mapnum][i - 1 - county][j] == 52)
				{
					county++;
				}

				if (skip == false)
				{
					//表示位置の設定
					dst.m_top = (i - county)*32.0f;
					dst.m_left = j*32.0f;
					dst.m_right = dst.m_left + 32.0f * (skipcountx + 1);
					dst.m_bottom = dst.m_top + 32.0f * (county + 1);

					//描画
					Draw::Draw(22, &src, &dst, c, 0.0f);
				}

				j += skipcountx;

				for (int w = j - skipcountx; w <= j; w++)
				{
					for (int z = i - county; z <= i; z++)
					{
						if (m_map[mapnum][z][w] == 51)
						{
							//切り取り位置の設定
							src.m_top = 0.0f;
							src.m_left = 0.0f;
							src.m_right = src.m_left + 64.0f;
							src.m_bottom = src.m_top + 92.0f;

							//表示位置の設定
							dst.m_top = z * 32.0f - 16.0f;
							dst.m_left = w * 32.0f;
							dst.m_right = dst.m_left + 32.0f;
							dst.m_bottom = dst.m_top + 32.0f;

							//描画
							Draw::Draw(23, &src, &dst, c, 0.0f);
						}
						if (m_map[mapnum][z][w] == 52)
						{
							//切り取り位置の設定
							src.m_top = 0.0f;
							src.m_left = 64.0f;
							src.m_right = src.m_left + 64.0f;
							src.m_bottom = src.m_top + 92.0f;

							//表示位置の設定
							dst.m_top = z*32.0f - 16.0f;
							dst.m_left = w*32.0f;
							dst.m_right = dst.m_left + 32.0f;
							dst.m_bottom = dst.m_top + 32.0f;

							//描画
							Draw::Draw(23, &src, &dst, c, 0.0f);
						}
					}
				}
			}
		}
	}

	//ナンバーロック中の画像表示
	if (lockpasu > 0)
	{
		if (lockpasu == 1)
		{
			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = src.m_left + 256.0f;
			src.m_bottom = src.m_top + 256.0f;

			//表示位置の設定
			dst.m_top = 80.0f;
			dst.m_left = 150.0f;
			dst.m_right = dst.m_left + 320.0f;
			dst.m_bottom = dst.m_top + 320.0f;

			//描画
			Draw::Draw(24, &src, &dst, c, 0.0f);
		}
		if (lockpasu == 2)
		{
			//切り取り位置の設定
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = src.m_left + 256.0f;
			src.m_bottom = src.m_top + 256.0f;

			//表示位置の設定
			dst.m_top = 80.0f;
			dst.m_left = 150.0f;
			dst.m_right = dst.m_left + 320.0f;
			dst.m_bottom = dst.m_top + 320.0f;

			//描画
			Draw::Draw(25, &src, &dst, c, 0.0f);
		}
	}
}
//動く方向にブロックがあるかどうかの判定
//Characternum 1=主人公 2=きらら 3=奏多 4=永遠
bool CObjBlock::ThereIsBlock(int vec ,int Characternum)
{
	//主人公
	if (Characternum == 1)
	{
		//右動く時の動作
		if (vec == 1)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][hero_y][hero_x + 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
					//動かせる箱の判定
					if (notonblock[i] == 60)
					{
						for (int j = 0; j < 99; j++)
						{
							if (m_map[mapnum][hero_y][hero_x + 2] ==  0)
							{
								m_map[mapnum][hero_y][hero_x + 1] = 0;
								m_map[mapnum][hero_y][hero_x + 2] = 60;
								tib = true;
							}
						}
					}
				}
			}
			if (tib == true)
			{
				hero_x = hero_x + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//左動く時の動作
		if (vec == 2)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][hero_y][hero_x - 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
					//動かせる箱の判定
					if (notonblock[i] == 60)
					{
						for (int j = 0; j < 99; j++)
						{
							if (m_map[mapnum][hero_y][hero_x - 2] == 0)
							{
								m_map[mapnum][hero_y][hero_x - 1] = 0;
								m_map[mapnum][hero_y][hero_x - 2] = 60;
								tib = true;
							}
						}
					}
				}
			}
			if (tib == true)
			{
				hero_x = hero_x - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//上動く時の動作
		if (vec == 3)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][hero_y - 1][hero_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
					//動かせる箱の判定
					if (notonblock[i] == 60)
					{
						for (int j = 0; j < 99; j++)
						{
							if (m_map[mapnum][hero_y - 2][hero_x] == 0)
							{
								m_map[mapnum][hero_y - 1][hero_x] = 0;
								m_map[mapnum][hero_y - 2][hero_x] = 60;
								tib = true;
							}
						}
					}
				}
			}
			if (tib == true)
			{
				hero_y = hero_y - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//下動くときの動作
		if (vec == 4)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][hero_y + 1][hero_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
					//動かせる箱の判定
					if (notonblock[i] == 60)
					{
						for (int j = 0; j < 99; j++)
						{
							if (m_map[mapnum][hero_y + 2][hero_x] == 0)
							{
								m_map[mapnum][hero_y + 1][hero_x] = 0;
								m_map[mapnum][hero_y + 2][hero_x] = 60;
								tib = true;
							}
						}
					}
				}
			}
			if (tib == true)
			{
				hero_y = hero_y + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	//きらら
	else if (Characternum == 2)
	{
		//右動く時の動作
		if (vec == 1)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kirara_y][kirara_x + 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kirara_y][kirara_x] = 0;
				m_map[mapnum][kirara_y][kirara_x + 1] = 8;
				kirara_x = kirara_x + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//左動く時の動作
		if (vec == 2)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kirara_y][kirara_x - 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kirara_y][kirara_x] = 0;
				m_map[mapnum][kirara_y][kirara_x - 1] = 8;
				kirara_x = kirara_x - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//上動く時の動作
		if (vec == 3)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kirara_y - 1][kirara_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kirara_y][kirara_x] = 0;
				m_map[mapnum][kirara_y - 1][kirara_x] = 8;
				kirara_y = kirara_y - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//下動くときの動作
		if (vec == 4)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kirara_y + 1][kirara_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kirara_y][kirara_x] = 0;
				m_map[mapnum][kirara_y + 1][kirara_x] = 8;
				kirara_y = kirara_y + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	//永遠
	else if (Characternum == 3)
	{
		//右動く時の動作
		if (vec == 1)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][towa_y][towa_x + 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][towa_y][towa_x] = 0;
				m_map[mapnum][towa_y][towa_x + 1] = 9;
				towa_x = towa_x + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//左動く時の動作
		if (vec == 2)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][towa_y][towa_x - 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][towa_y][towa_x] = 0;
				m_map[mapnum][towa_y][towa_x - 1] = 9;
				towa_x = towa_x - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//上動く時の動作
		if (vec == 3)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][towa_y - 1][towa_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][towa_y][towa_x] = 0;
				m_map[mapnum][towa_y - 1][towa_x] = 9;
				towa_y = towa_y - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//下動くときの動作
		if (vec == 4)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][towa_y + 1][towa_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][towa_y][towa_x] = 0;
				m_map[mapnum][towa_y + 1][towa_x] = 9;
				towa_y = towa_y + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	//奏多
	else if (Characternum == 4)
	{
		//右動く時の動作
		if (vec == 1)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kanata_y][kanata_x + 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kanata_y][kanata_x] = 0;
				m_map[mapnum][kanata_y][kanata_x + 1] = 10;
				kanata_x = kanata_x + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//左動く時の動作
		if (vec == 2)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kanata_y][kanata_x - 1] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kanata_y][kanata_x] = 0;
				m_map[mapnum][kanata_y][kanata_x - 1] = 10;
				kanata_x = kanata_x - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//上動く時の動作
		if (vec == 3)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kanata_y - 1][kanata_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kanata_y][kanata_x] = 0;
				m_map[mapnum][kanata_y - 1][kanata_x] = 10;
				kanata_y = kanata_y - 1;
				return true;
			}
			else
			{
				return false;
			}
		}
		//下動くときの動作
		if (vec == 4)
		{
			bool tib = true;
			for (int i = 0; i < 99; i++)
			{
				if (m_map[mapnum][kanata_y + 1][kanata_x] == notonblock[i] && notonblock[i] != 0)
				{
					tib = false;
				}
			}
			if (tib == true)
			{
				m_map[mapnum][kanata_y][kanata_x] = 0;
				m_map[mapnum][kanata_y + 1][kanata_x] = 10;
				kanata_y = kanata_y + 1;
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}
//主人公アクション
void CObjBlock::HeroAction(int vec)
{
	//主人公の位置を設定
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//アイテム参照
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	//鍵判定
	if (m_map[mapnum][hero_y][hero_x] == 4)
	{
		m_map[mapnum][hero_y][hero_x] = 0;
		itm->GetItem(1);
		//((UserData*)Save::GetData())->item1 = true;
	}

	//右
	if (vec == 1)
	{
		if (m_map[mapnum][hero_y][hero_x + 1] == 3)
		{
			;
		}
		//鍵判定
		if (m_map[mapnum][hero_y][hero_x + 1] == 4)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 0;
			itm->GetItem(1);
		}
		//偽鍵判定
		if (m_map[mapnum][hero_y][hero_x + 1] == 6)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 0;
			itm->GetItem(2);
		}
		//偽壁判定
		if (m_map[mapnum][hero_y][hero_x + 1] == 7)
		{
			blockmovevec = 4;
			blockx = hero_x + 1; blocky = hero_y;
			blockdeleteYN = false;
			eventclockflag = true;
		}
		//机の上のメモを取る判定
		if (m_map[mapnum][hero_y][hero_x + 1] == 40)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 32;
			itm->GetItem(5);
		}
		//ベッドの上のメモ2を取る判定
		if (m_map[mapnum][hero_y][hero_x + 1] == 41)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 33;
			itm->GetItem(6);
		}
		//ベッドの上のメモ3を取る判定
		if (m_map[mapnum][hero_y][hero_x + 1] == 42)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 33;
			itm->GetItem(7);
		}
		//絨毯の下のメモ4を取る判定
		if (m_map[mapnum][hero_y][hero_x + 1] == 46)
		{
			m_map[mapnum][hero_y][hero_x + 1] = 0;
			itm->GetItem(8);
		}
	}
	//左
	if (vec == 2)
	{
		if (m_map[mapnum][hero_y][hero_x - 1] == 3)
		{
			;
		}
		//鍵判定
		if (m_map[mapnum][hero_y][hero_x - 1] == 4)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 0;
			itm->GetItem(1);
		}
		//偽鍵判定
		if (m_map[mapnum][hero_y][hero_x - 1] == 6)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 0;
			itm->GetItem(2);
		}
		//机の上のメモ1を取る判定
		if (m_map[mapnum][hero_y][hero_x - 1] == 40)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 32;
			itm->GetItem(5);
		}
		//ベッドの上のメモ2を取る判定
		if (m_map[mapnum][hero_y][hero_x - 1] == 41)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 33;
			itm->GetItem(6);
		}
		//ベッドの上のメモ3を取る判定
		if (m_map[mapnum][hero_y][hero_x - 1] == 42)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 33;
			itm->GetItem(7);
		}
		//絨毯の下のメモ4を取る判定
		if (m_map[mapnum][hero_y][hero_x - 1] == 46)
		{
			m_map[mapnum][hero_y][hero_x - 1] = 0;
			itm->GetItem(8);
		}
	}
	//上
	if (vec == 3)
	{
		//鍵付きドア判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 3 && itm->CheckItem(1))
		{
			itm->DeleteItem(1,false);
			itm->DeleteItem(2, true);
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (m_map[mapnum][i][j] == 6)
					{
						m_map[mapnum][i][j] = 0;
					}
				}
			}
			m_map[mapnum][hero_y - 1][hero_x] = 99;
		}
		//鍵判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 4)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 0;
			itm->GetItem(1);
		}
		//ナンバーロックドア判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 5)
		{
			//解いてる間動かないようにする
			hero->SetActionflag(true);
			//ナンバーロックの桁数とロックナンバー
			hero->SetLockpiece(1,4);
			//ナンバーロック解いてるフラグを立てる
			hero->SetNumlock(true);
		}
		//偽鍵判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 6)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 0;
			itm->GetItem(2);
		}
		//棚判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 37 && itm->CheckItem(9) && itm->CheckItem(10) && itm->CheckItem(11))
		{
			bool gby = false;
			itm->GetItem(3);
			for (int k = 0; gby == false; k++)
			{
				gby = true;
				if (m_map[mapnum][hero_y - 1][hero_x - k] == 37)
				{
					m_map[mapnum][hero_y - 1][hero_x - k] = 36;
					gby = false;
				}
				if (m_map[mapnum][hero_y - 1][hero_x + k] == 37)
				{
					m_map[mapnum][hero_y - 1][hero_x + k] = 36;
					gby = false;
				}
			}
			itm->DeleteItem(9, false);
			itm->DeleteItem(10, false);
			itm->DeleteItem(11, false);
		}
		//金庫判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 51 && itm->CheckItem(4))
		{
			m_map[mapnum][hero_y - 1][hero_x] = 52;
			event_num = 13;
			text_m = 4;
			itm->DeleteItem(4, false);
			itm->GetItem(11);
		}
		//棚判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 38)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 36;
			itm->GetItem(4);
		}
		//動く棚判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 39 && itm->CheckItem(3))
		{
			blockx = hero_x; blocky = hero_y - 1;
			itm->DeleteItem(3, false);
			moveshelf = 1.0f;
		}
		//机の上のメモ1を取る判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 40)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 32;
			itm->GetItem(5);
		}
		//ベッドの上のメモ2を取る判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 41)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 33;
			itm->GetItem(6);
		}
		//ベッドの上のメモ3を取る判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 42)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 33;
			itm->GetItem(7);
		}
		//絨毯の下のメモ4を取る判定
		if (m_map[mapnum][hero_y - 1][hero_x] == 46)
		{
			m_map[mapnum][hero_y - 1][hero_x] = 0;
			itm->GetItem(8);
		}
		//棚のナンバーロック解除
		if (m_map[mapnum][hero_y - 1][hero_x] == 43)
		{
			text_hide = true;
			//解いてる間動かないようにする
			hero->SetActionflag(true);
			//ナンバーロックの桁数
			hero->SetLockpiece(2,4);
			//ナンバーロック解いてるフラグを立てる
			hero->SetNumlock(true);
			//ヒント用の画像を表示する
			lockpasu = 2;
		}
		//棚のナンバーロック解除
		if (m_map[mapnum][hero_y - 1][hero_x] == 44)
		{
			text_hide = true;
			//解いてる間動かないようにする
			hero->SetActionflag(true);
			//ナンバーロックの桁数
			hero->SetLockpiece(3, 3);
			//ナンバーロック解いてるフラグを立てる
			hero->SetNumlock(true);
			//ヒント用の画像を表示する
			lockpasu = 1;
		}
	}
	//下
	if (vec == 4)
	{
		if (m_map[mapnum][hero_y + 1][hero_x] == 3 && itm->CheckItem(1))
		{
			m_map[mapnum][hero_y + 1][hero_x] = 0;
		}
		//鍵判定
		if (m_map[mapnum][hero_y + 1][hero_x] == 4)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 0;
			itm->GetItem(1);
		}
		//偽鍵判定
		if (m_map[mapnum][hero_y + 1][hero_x] == 6)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 0;
			itm->GetItem(2);
		}
		//机の上のメモを取る判定
		if (m_map[mapnum][hero_y + 1][hero_x] == 40)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 32;
			itm->GetItem(5);
		}
		//ベッドの上のメモ2を取る判定
		if (m_map[mapnum][hero_y + 1][hero_x] == 41)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 33;
			itm->GetItem(6);
		}
		//ベッドの上のメモ3を取る判定
		if (m_map[mapnum][hero_y + 1][hero_x] == 42)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 33;
			itm->GetItem(7);
		}
		//絨毯の下のメモ4を取る判定
		if (m_map[mapnum][hero_y + 1][hero_x] == 46)
		{
			m_map[mapnum][hero_y + 1][hero_x] = 0;
			itm->GetItem(8);
		}
	}
}
//マップ切り替え用関数
void CObjBlock::Mapchange(int mapn)
{
	//主人公の位置を設定
	CObjBackGround* bgro = (CObjBackGround*)Objs::GetObj(OBJ_BGROUND);
	//マップ保存-------------------------------------------
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			block_data_map[mapnum][i][j] = m_map[mapnum][i][j];
		}
	}

	//ローディング-----------------------------------------
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			m_map[mapn][i][j] = block_data_map[mapn][i][j];
		}
	}

	//背景切り替え
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			bgro->SetMapChip(mapnum, i, j, m_map[mapnum][i][j]);
		}
	}
}

//主人公の位置をセットする
void CObjBlock::SetHero()
{

	//主人公の位置を設定
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[mapnum][i][j] == 2)
			{
				hero_x = j; hero_y = i;
				hero->SetPX(32.0f*j);
				hero->SetPY(32.0f*i);
				m_map[mapnum][i][j] = 0;
			}
		}
	}
}

//主人公が氷ブロックに乗っているか調べる
bool CObjBlock::CheckIceBlock()
{
	if(m_map[mapnum][hero_y][hero_x] == 61)
		return true;
	else
		return false;
}

//永遠の位置をセットする
void CObjBlock::SetTowa()
{

	//永遠の位置を設定
	CObjTowa* towa = (CObjTowa*)Objs::GetObj(OBJ_TOWA);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[mapnum][i][j] == 9)
			{
				towa_x = j; towa_y = i;
				towa->SetPX(32.0f*j);
				towa->SetPY(32.0f*i);
			}
		}
	}
}

//奏多の位置をセットする
void CObjBlock::SetKanata()
{

	//奏多の位置を設定
	CObjTowa* kanata = (CObjTowa*)Objs::GetObj(OBJ_KANATA);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[mapnum][i][j] ==10)
			{
				kanata_x = j; kanata_y = i;
				kanata->SetPX(32.0f*j);
				kanata->SetPY(32.0f*i);
			}
		}
	}
}


//きららの位置をセットする
void CObjBlock::SetKirara()
{

	//きららの位置を設定
	CObjKirara* kirara = (CObjKirara*)Objs::GetObj(OBJ_KIRARA);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (m_map[mapnum][i][j] == 8)
			{
				kirara_x = j; kirara_y = i;
				kirara->SetPX(32.0f*j);
				kirara->SetPY(32.0f*i);
			}
		}
	}
}


//ナンバーロックドア開けるための関数
void CObjBlock::UnlockDoor(int vec, int num, int locknum)
{
	//アイテム参照
	CObjItem* itm = (CObjItem*)Objs::GetObj(OBJ_ITEM);

	
	if (((UserData*)Save::GetData())->number[0] == num && locknum == 1)
	{
		m_map[mapnum][hero_y - 1][hero_x] = 0;
	}
	//永遠部屋
	if (((UserData*)Save::GetData())->number[1] == num && locknum == 2)
	{
		itm->GetItem(10);
		//手元のメモを捨てる
		itm->DeleteItem(5,false);
		itm->DeleteItem(6,false);
		itm->DeleteItem(7,false);
		itm->DeleteItem(8,false);
		//戸棚に調べ終わったフラグを置く
		m_map[mapnum][hero_y - 1][hero_x] = 31;
		//マップ上のメモに関するものを消す
		m_map[2][1][6] = 33;
		m_map[2][1][13] = 33;
		m_map[2][3][15] = 0;
		m_map[2][7][18] = 32;
		text_m = 5;
		event_num = 19;
	}
	//きらら部屋
	if (((UserData*)Save::GetData())->number[2] == num && locknum == 3)
	{
		itm->GetItem(9);
		m_map[mapnum][hero_y - 1][hero_x] = 31;
		text_m = 3;
		event_num = 24;
	}

	//画像を消す
	lockpasu = 0;
}
int CObjBlock::CheckBlockNumber(int vec, int x, int y)
{
	//左上の値を返す
	if (vec == 1)
	{
		return m_map[mapnum][y - 1][x - 1];
	}
	//上の値を返す
	if (vec == 2)
	{
		return m_map[mapnum][y - 1][x];
	}
	//右上の値を返す
	if (vec == 3)
	{
		return m_map[mapnum][y - 1][x + 1];
	}
	//右の値を返す
	if (vec == 4)
	{
		return m_map[mapnum][y][x + 1];
	}
	//右下の値を返す
	if (vec == 5)
	{
		return m_map[mapnum][y + 1][x + 1];
	}
	//下の値を返す
	if (vec == 6)
	{
		return m_map[mapnum][y + 1][x];
	}
	//左下の値を返す
	if (vec == 7)
	{
		return m_map[mapnum][y + 1][x - 1];
	}
	//左の値を返す
	if (vec == 8)
	{
		return m_map[mapnum][y][x - 1];
	}
}