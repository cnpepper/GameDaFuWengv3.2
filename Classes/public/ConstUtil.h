<<<<<<< HEAD
#ifndef _CONSTUTIL_H
#define _CONSTUTIL_H
//����Ƭͷ�õ�������ͼƬ�ĺ�
=======
﻿/****************************************************** 
* Program Assignment : 一些文件名的宏定义
* Author : 刘建均 
* Date : 2015 / 1 / 26  21 : 59
* Description :
***************************************************** / 
/******************************************************* 
* Source code in :源文件路径
* Function List: 函数表
*******************************************************/
#ifndef _CONSTUTIL_H
#define _CONSTUTIL_H
//定义片头用到的四张图片的宏
>>>>>>> origin/master
#define CHENG_IMAGE   "cheng.png"
#define MAI_IMAGE     "mai.png"
#define KE_IMAGE      "ke.png"
#define JI_IMAGE      "ji.png"

#define NORMAL_MENU   "normal_menu.png"
#define PRESS_MENU    "press_menu.png"
#define MENU_LOGO     "menuLogo.png"
#define RAINBOW       "rainbow.png"

#define  DIALOG_BG "popuplayer/dialog_bg.png"
#define  BUTTON_BG1 "popuplayer/button_bg1.png"
#define  BUTTON_BG2 "popuplayer/button_bg2.png"
#define  BUTTON_BG3 "popuplayer/button_bg3.png"

#define PATH_MARK_1 "map/mark1.png"
#define PATH_MARK_2 "map/mark2.png"
#define PATH_MARK_3 "map/mark3.png"
#define PATH_MARK_4 "map/mark4.png"
#define PATH_MARK_5 "map/mark5.png"
#define PATH_MARK_6 "map/mark6.png"

#define DIGITAL_0 "digital_0.png"
#define DIGITAL_1 "digital_1.png"
#define DIGITAL_2 "digital_2.png"
#define DIGITAL_3 "digital_3.png"
#define DIGITAL_4 "digital_4.png"
#define DIGITAL_5 "digital_5.png"
#define DIGITAL_6 "digital_6.png"
#define DIGITAL_7 "digital_7.png"
#define DIGITAL_8 "digital_8.png"
#define DIGITAL_9 "digital_9.png"




#define FONT_MENU     "Marker Felt"
#define SINGLE_GAME   "Single Game"
#define MULTI_GAME    "Multi Game"
#define MUSIC_ON      "Music On"
#define MUSIC_OFF     "Music Off"
#define QUIT_GAME     "Quit Game"
#define MUSIC_ON_KEY  "music_on"
#define OK "Ok"
#define CANCEL "Cancel"

#define DIALOG_TITLE  "Alert Message"
#define DIALOG_CONTENT "Do you want to quit ?"

#define BEACH_ITEM "map/beach_item.png"
#define SEA_ITEM "map/sea_item.png"
#define MOON_ITEM "map/moon_item.png"

#define STAGE_BACKGROUND "map/stage_background2.png"
#define RIGHT_BANNER "map/right_banner.png"
#define PLAYER_ME "map/player1.png"
#define PLAYER_ENEMY1 "map/player2.png"
#define GO_BUTTON "map/go.png"
#define PLAYER_ME_ANIM "map/player1_anim.png"
#define PLAYER_ENEMY1_ANIM "map/player2_anim.png"
#define PLAYER1_ANIM_PLIST   "map/player1_anim.plist"
#define PLAYER1_ANIM_PNG "map/player1_anim.png"

#define DICE_PLIST "map/dice.plist"
#define DICE_PNG_1 "dice_01.png"
#define DICE_PNG_2 "dice_02.png"
#define DICE_PNG_3 "dice_03.png"
#define DICE_PNG_4 "dice_04.png"
#define DICE_PNG_5 "dice_05.png"
#define DICE_PNG_6 "dice_06.png"

#define PLAYER2_ANIM_PLIST "map/player2_anim.plist"
#define PLAYER2_ANIM_PNG "map/player2_anim.png"

#define PLAYER_1_NAME "player1"
const int PLAYER_1_TAG = 1;
#define PLAYER_2_NAME "player2"
const int PLAYER_2_TAG = 2;

#define MSG_GO "msg_go"
#define MSG_BUY "msg_buy_land"
#define MSG_PICKONE_TOGO "msg_pickone_togo"
#define MSG_PAY_TOLLS "msg_pay_tolls"


const int MSG_GO_HIDE_TAG = 0;
const int MSG_GO_SHOW_TAG = 1;

const int MSG_BUY_BLANK_TAG = 2;
const int MSG_BUY_LAND_1_TAG = 3;
const int MSG_BUY_LAND_2_TAG = 4;

const int MSG_PICKONE_TOGO_TAG = 5;

const int MSG_PAY_TOLLS_1_TAG = 6;
const int MSG_PAY_TOLLS_2_TAG = 7;
const int MSG_PAY_TOLLS_3_TAG = 8;

const int LAND_BLANK_MONEY = 1000;
const int LAND_LEVEL_1_MONEY = 2000;
const int LAND_LEVEL_2_MONEY = 3000;

/*button size*/
const int Btn_Width = 222;
const int Btn_Height = 50;
const int Btn_FontSize = 20;
const int Quit_Dialog_Size_Width = 400;
const int Quit_Dialog_Size_Height = 220;
//const int Btn_Padding = 60;
const int Btn_Single_Game_TAG = 10001;
const int Btn_Multi_Game_TAG = 10002;
const int Btn_Music_TAG = 10003;
const int Btn_Quit_Game_TAG = 10004;
const int Btn_Quit_OK_TAG = 10005;
const int Btn_Quit_Cancel_TAG = 10006;
//const int LAND_LEVEL_3_MONEY = 5000;
#define  BUY_LAND_MSG "Do you want to buy the land ? need $  ";
#define PLAYER1_1_PARTICLE_PLIST "images/showClick.plist"
#define PLAYER2_1_PARTICLE_PLIST "images/fire.plist"

#define PLAYER1_1_PARTICLE_PNG "images/foot1.png"
#define PLAYER2_1_PARTICLE_PNG "images/foot2.png"

#define PLAYER1_2_PARTICLE_PNG "images/starfish1.png"
#define PLAYER2_2_PARTICLE_PNG "images/starfish2.png"

#define PLAYER1_3_PARTICLE_PNG "images/heart1.png"
#define PLAYER2_3_PARTICLE_PNG "images/heart2.png"
#endif