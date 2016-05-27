#pragma once
#include "cocos3d.h"
#include "GameLogic/GameLogic.h"

USING_NS_COCOS3D;
class Scene3D;
class Layer3D : public CC3Layer
{
public:

	CREATE_FUNC(Layer3D);
	Layer3D(void);
	~Layer3D(void);

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	virtual void registerWithTouchDispatcher();
};

class Scene3D : public CC3Scene
{
public:
	Scene3D(){};
	~Scene3D(){};

	CREATE_FUNC(Scene3D);

	virtual void initializeScene();

	void setupCameraAndLight();
	void setupAxes();
	void setupScene();
	virtual void update( float dt );

	void initWithGameLogic(GameLogic *logic);
	CC3Vector getRealPosition(CCPoint pos);
	string getTypeGameObject(GameObject::Type type);

	void touchEvent( GLuint touchType, const CCPoint& touchPoint );

protected:
	CC3Camera *cam;
	CC3Light * lamp;
	CC3MeshNode *lampView;
	CC3PODResourceNode *allModels;
	CC3PODResourceNode * board;

	void setupWithPlayer(Player *player,bool front);

};