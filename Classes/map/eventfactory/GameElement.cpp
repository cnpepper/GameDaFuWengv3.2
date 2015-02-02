#include "GameElement.h"
#include "CocosToast.h"
#include "PopupLayer.h"
USING_NS_CC;
#include "GUI/CCControlExtension/CCControl.h"
#include "ConstUtil.h"
<<<<<<< HEAD
#include "cocos2d/extensions/cocos-ext.h"
USING_NS_CC_EXT;
#include "GameBaseScene.h"
#include "GameManager.h"
=======
#include "cocos-ext.h"
USING_NS_CC_EXT;
//#include "GameBaseScene.h"
#include "SeaScene.h"
#include "GameManager.h"
#include "PlayerManager.h"
>>>>>>> origin/master
GameElementFactroy::GameElementFactroy()
{
}


GameElementFactroy::~GameElementFactroy()
{
}
<<<<<<< HEAD
void OperationHome::GetResult(GameBase* layer)
{
	//��������
	//����һ��ѡ��򣬸�����ҵ�ѡ��ȷ�����ĸ���֧
	popupLayer(layer);
	
}

void OperationHome::popupLayer(GameBase* layer)
=======
void OperationHome::GetResult(SeaScene* layer)
{
	//�������ݻ��չ�·��
	int curplayer = PlayerManager::getInstance()->_curPlayer;
	SeaScene* gamelayer = GameManager::getInstance()->gamelayer;
	if (4 == _tag || 5 == _tag || 6 == _tag)
	{
		if (2 == curplayer)
		{	
			//��Ǯ
			if (4 == _tag)
			{
				//�۳���Ӧ�Ľ�Ǯ����������ӽ�Ǯ
				PlayerManager::getInstance()->player2Money -= 500;
				PlayerManager::getInstance()->player1Money += 500;
				CocosToast::createToast(gamelayer, "-500", 1.0f, gamelayer->_player2Sprite->getPosition());
			}
			else if (5 == _tag)
			{
				//�۳���Ӧ�Ľ�Ǯ
				//�۳���Ӧ�Ľ�Ǯ����������ӽ�Ǯ
				PlayerManager::getInstance()->player2Money -= 800;
				PlayerManager::getInstance()->player1Money += 800;
				CocosToast::createToast(gamelayer, "-800", 1.0f, gamelayer->_player2Sprite->getPosition());
			}
			else if (6 == _tag)
			{
				//�۳���Ӧ�Ľ�Ǯ
				//�۳���Ӧ�Ľ�Ǯ����������ӽ�Ǯ
				PlayerManager::getInstance()->player2Money -= 1000;
				PlayerManager::getInstance()->player1Money += 1000;
				CocosToast::createToast(gamelayer, "-1000", 1.0f, gamelayer->_player2Sprite->getPosition());
			}
		}
		else
		{
			//����һ��ѡ��򣬸�����ҵ�ѡ��ȷ�����ĸ���֧
			popupLayer(gamelayer);
		}
	}
	else if (7 == _tag || 8 == _tag || 9 == _tag)
	{
		if (1 == curplayer)
		{
			//��Ǯ
			if (7 == _tag)
			{
				//�۳���Ӧ�Ľ�Ǯ����������ӽ�Ǯ
				PlayerManager::getInstance()->player2Money += 500;
				PlayerManager::getInstance()->player1Money -= 500;
				CocosToast::createToast(gamelayer, "-500", 1.0f, gamelayer->_player1Sprite->getPosition());
			}
			else if (8 == _tag)
			{
				//�۳���Ӧ�Ľ�Ǯ
				//�۳���Ӧ�Ľ�Ǯ����������ӽ�Ǯ
				PlayerManager::getInstance()->player2Money += 800;
				PlayerManager::getInstance()->player1Money -= 800;
				CocosToast::createToast(gamelayer, "-800", 1.0f, gamelayer->_player1Sprite->getPosition());
			}
			else if (9 == _tag)
			{
				//�۳���Ӧ�Ľ�Ǯ
				//�۳���Ӧ�Ľ�Ǯ����������ӽ�Ǯ
				PlayerManager::getInstance()->player2Money += 1000;
				PlayerManager::getInstance()->player1Money -= 1000;
				CocosToast::createToast(gamelayer, "-1000", 1.0f, gamelayer->_player1Sprite->getPosition());
			}
		}
		else
		{
			//����һ��ѡ��򣬸�����ҵ�ѡ��ȷ�����ĸ���֧
			popupLayer(gamelayer);
		}
	}
	else if ( 0 == _tag )
	{
		//����һ��ѡ��򣬸�����ҵ�ѡ��ȷ�����ĸ���֧
		popupLayer(layer);
	}

}

void OperationHome::popupLayer(SeaScene* layer)
>>>>>>> origin/master
{
	//����һ�������㣬����һ��ͼƬ
	PopupLayer* popDialog = PopupLayer::create(DIALOG_BG);
	Scale9Sprite *btnNormal = Scale9Sprite::create(DIALOG_BG);
	popDialog->setSprite9BackGround(btnNormal);
	//CONTENTSIZE �ǿ�ѡ�����ã����Բ����ã�������ð�������9ͼ����
	popDialog->setContentSize(CCSizeMake(Quit_Dialog_Size_Width, Quit_Dialog_Size_Height));
	popDialog->setTitle(DIALOG_TITLE);
	popDialog->setContentText(DIALOG_CONTENT, 20, 60, 250);
	//���ûص��������ص���һ��ccnode �Ի�ȡtag�жϵ����ť
	popDialog->setCallbackFunc(this, callfuncN_selector(OperationHome::quitButtonCallback));
	//
	popDialog->addButton(BUTTON_BG1, BUTTON_BG3, OK, Btn_Quit_OK_TAG);
	popDialog->addButton(BUTTON_BG2, BUTTON_BG3, CANCEL, Btn_Quit_Cancel_TAG);

	layer->addChild(popDialog);
}

void OperationHome::quitButtonCallback(Node *pNode)
{
<<<<<<< HEAD
	if (pNode->getTag() == Btn_Quit_OK_TAG)
	{
		//Director::getInstance()->end();
		//������ȷ����������˴˵�
		GameBase* layer = GameManager::getInstance()->gamebaselayer;
=======
	int curplayer = PlayerManager::getInstance()->_curPlayer;
	if (pNode->getTag() == Btn_Quit_OK_TAG)
	{
		//������ȷ����������˴˵�
		SeaScene* layer = GameManager::getInstance()->gamelayer;
>>>>>>> origin/master
		//ִ����صĶ�������
		auto ly = layer->_GameMap->getLayer("way");
		if (0 ==_tag)
		{
<<<<<<< HEAD
			ly->setTileGID(10, GameManager::getInstance()->_Player1Point);
			//�۳���Ӧ�Ľ�Ǯ
			CocosToast::createToast(layer, "-2000", 1.0f, layer->_player1Sprite->getPosition());
		}
		else if (4 == _tag)
		{
			ly->setTileGID(11, GameManager::getInstance()->_Player1Point);
			//�۳���Ӧ�Ľ�Ǯ
			CocosToast::createToast(layer, "-5000", 1.0f, layer->_player1Sprite->getPosition());
		}
		else if (5 == _tag)
		{
			ly->setTileGID(12, GameManager::getInstance()->_Player1Point);
			//�۳���Ӧ�Ľ�Ǯ
			CocosToast::createToast(layer, "-10000", 1.0f, layer->_player1Sprite->getPosition());
=======
			if (1 == curplayer)
			{
				ly->setTileGID(10, GameManager::getInstance()->_Player1Point);
				//�۳���Ӧ�Ľ�Ǯ
				PlayerManager::getInstance()->player1Money -= 2000;
				CocosToast::createToast(layer, "-2000", 1.0f, layer->_player1Sprite->getPosition());
			}
			else if (2 == curplayer)
			{
				ly->setTileGID(13, GameManager::getInstance()->_Player1Point);
				//�۳���Ӧ�Ľ�Ǯ
				PlayerManager::getInstance()->player2Money -= 2000;
				CocosToast::createToast(layer, "-2000", 1.0f, layer->_player2Sprite->getPosition());
			}
			
			
		}
		else if (4 == _tag || 7 == _tag)
		{
			if (1 == curplayer)
			{
				ly->setTileGID(11, GameManager::getInstance()->_Player1Point);
				//�۳���Ӧ�Ľ�Ǯ
				PlayerManager::getInstance()->player1Money -= 5000;
				CocosToast::createToast(layer, "-5000", 1.0f, layer->_player1Sprite->getPosition());
			}
			else if (2 == curplayer)
			{
				ly->setTileGID(14, GameManager::getInstance()->_Player1Point);
				//�۳���Ӧ�Ľ�Ǯ
				PlayerManager::getInstance()->player2Money -= 5000;
				CocosToast::createToast(layer, "-5000", 1.0f, layer->_player2Sprite->getPosition());
			}
			
		}
		else if (5 == _tag || 8 == _tag)
		{
			if (1 == curplayer)
			{
				ly->setTileGID(12, GameManager::getInstance()->_Player1Point);
				//�۳���Ӧ�Ľ�Ǯ
				PlayerManager::getInstance()->player1Money -= 10000;
				CocosToast::createToast(layer, "-10000", 1.0f, layer->_player1Sprite->getPosition());
			}
			else if (2 == curplayer)
			{
				ly->setTileGID(15, GameManager::getInstance()->_Player1Point);
				//�۳���Ӧ�Ľ�Ǯ
				PlayerManager::getInstance()->player2Money -= 10000;
				CocosToast::createToast(layer, "-10000", 1.0f, layer->_player2Sprite->getPosition());
			}
>>>>>>> origin/master
		}
		
	}
	else
	{
		//������ѡȡ���Ƴ�����
		pNode->getParent()->getParent()->removeFromParent();
	}

<<<<<<< HEAD
=======
}

//��Ʊ
void OperationStock::GetResult(SeaScene* layer)
{
	int player = PlayerManager::getInstance()->_curPlayer;
	SeaScene* ganelayer = GameManager::getInstance()->gamelayer;
	srand(time_t(NULL));
	int num = rand()%1000;
	
	char buffer[16] = { 0 };
	if (num<472)
	{
		
		
		sprintf(buffer, "+%d", (num * 10));
		if (1 == player)
		{
			PlayerManager::getInstance()->player1Money += (num * 10);
			CocosToast::createToast(ganelayer, buffer, 1.0f, ganelayer->_player1Sprite->getPosition());
			
		}
		else if (2 == player)
		{
			PlayerManager::getInstance()->player2Money += (num * 10);
			CocosToast::createToast(ganelayer, buffer, 1.0f, ganelayer->_player2Sprite->getPosition());
		}
		
	}
	else
	{
		sprintf(buffer, "-%d", (num * 10));
		if (1 == player)
		{
			PlayerManager::getInstance()->player1Money -= (num * 10);
			CocosToast::createToast(ganelayer, buffer, 1.0f, ganelayer->_player1Sprite->getPosition());

		}
		else if (2 == player)
		{
			PlayerManager::getInstance()->player2Money -= (num * 10);
			CocosToast::createToast(ganelayer, buffer, 1.0f, ganelayer->_player2Sprite->getPosition());
		}

	}
>>>>>>> origin/master
}