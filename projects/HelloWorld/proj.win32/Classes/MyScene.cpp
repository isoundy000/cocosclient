#include "MyScene.h"
#include "..\..\Classes\3D\CC3HelloWorldLayer.h"
#include "..\..\Classes\3D\CC3HelloWorldScene.h"


MyScene::MyScene(void)
{
}


MyScene::~MyScene(void)
{
	/// Force remove all children before cocos3d' shutdown
	removeAllChildren();
	/// Clear unreleased cocos3d objects
	CCPoolManager::sharedPoolManager()->pop();

	/// 
	Cocos3d::shutdown();
}


bool MyScene::init()
{
	CCScene::init();

	this->addChild(Layer2D::create());
	return true;
}


bool Layer2D::init()
{
	CCLayer::init();

	setTouchEnabled(true);

	CC3Layer* cc3Layer = new CC3Layer();
	cc3Layer->init();cc3Layer->autorelease();
	CC3Scene* cc3Scene = MyScene3D::create();

	cc3Layer->setCC3Scene(cc3Scene);
	this->addChild(cc3Layer);
	
	return true;
}

void MyScene3D::initializeScene()
{

	CC3Camera* cam = CC3Camera::nodeWithName( "Camera" );
	cam->setLocation( cc3v( 0.0, 0.0, 100.0 ) );
	cam->setFarClippingDistance( 4000 );
	cam->setFieldOfView( 67.f );

	addChild( cam ); 


	CC3Light* lamp = CC3Light::nodeWithName( "Lamp" );
	lamp->setLocation( cc3v( 2.0, 0.0, 0.0 ) );
	lamp->setIsDirectionalOnly( false );
	cam->addChild( lamp );

	CC3ResourceNode* rezNode = CC3PODResourceNode::nodeFromFile( "3d/box.pod" );
	addChild( rezNode );
	rezNode->setLocation( cc3v( -20, 0, 0 ) );
	rezNode->setUniformScale( 5 );
	rezNode->runAction( CC3RepeatForever::create( CC3ActionAnimate::actionWithDuration(2.f) ) );

	//rezNode->setRotation( cc3v(0, -75, 75) );
}