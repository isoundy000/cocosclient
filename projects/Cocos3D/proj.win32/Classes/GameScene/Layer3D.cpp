#include "Layer3D.h"


Layer3D::Layer3D(void)
{
}


Layer3D::~Layer3D(void)
{
}

void Layer3D::onEnter()
{
	CC3Layer::onEnter();
	setTouchEnabled(true);
}

void Layer3D::onExit()
{
	setTouchEnabled(false);
	CC3Layer::onExit();
}

bool Layer3D::init()
{
	CC3Layer::init();

	
	setCC3Scene(Scene3D::create());
	return true;
}

void Layer3D::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,true);

}



// Scene

void Scene3D::setupCameraAndLight()
{
	// Create the camera, place it back a bit, and add it to the scene
	cam = CC3Camera::nodeWithName( "Camera" );
	//cam->setViewport(CC3ViewportMake(0,0,400,400));
	cam->setLocation( cc3v( 0, 3, 15 ) );
	cam->setTargetLocation(cc3v(0,0,0));

	addChild( cam );

	
	setAmbientLight( ccc4f(0.3f, 0.3f, 0.3f, 1.0f) );

	// Create a light, place it back and to the left at a specific
	// position (not just directional lighting), and add it to the scene
	lamp = CC3Light::nodeWithName( "Lamp" );
	lamp->setLocation( cc3v(30,30,30) );
	lamp->setIsDirectionalOnly( false );
	lamp->setForwardDirection(cc3v(1,0,0));
	addChild( lamp );
	CC3AttenuationCoefficients suyhao = {1,0,0};
	lamp->setAttenuation(suyhao);

}

void Scene3D::setupAxes()
{

	// axes
	CC3MeshNode *linex = CC3MeshNode::nodeWithName("linex");
	CC3Vector linedata[2] = {cc3v(0,0,0),cc3v(100,0,0)};
	linex->populateAsLineStripWith(2,linedata,true);
	linex->setColor(ccRED);


	addChild(linex);

	CC3MeshNode *liney = CC3MeshNode::nodeWithName("liney");
	CC3Vector linedatay[2] = {cc3v(0,0,0),cc3v(0,100,0)};
	liney->populateAsLineStripWith(2,linedatay,true);
	liney->setColor(ccGREEN);

	addChild(liney);

	CC3MeshNode *linez = CC3MeshNode::nodeWithName("linez");
	CC3Vector linedataz[2] = {cc3v(0,0,0),cc3v(0,0,100)};
	linez->populateAsLineStripWith(2,linedataz,true);
	linez->setColor(ccBLUE);

	addChild(linez);
}

void Scene3D::initializeScene()
{

	setBackdrop(CC3Backdrop::nodeWithColor(ccc4f(.1,.1,.1,1.)));
	//CC3Backdrop::nodeWithTexture(CC3Texture::textureFromFile())
 	setupCameraAndLight();
 	setupAxes();
 	setupScene();
// 
	this->selectShaders();
	this->createBoundingVolumes();
	this->createGLBuffers();
	this->releaseRedundantContent();

}

void Scene3D::setupScene()
{
	CC3Node *node = CC3Node::nodeWithName("a");
	addChild(node);
	node->setLocation(cc3v(.3, 2, 0));
	board = CC3PODResourceNode::nodeFromFile( "board.pod" );
	board->setScale(cc3v(.3, .3, .3));
		node->addChild( board );
		board->setLocation( cc3v( 1.5, -.7, 2 ) );
		board->setQuaternion(CC3Quaternion(.3, .3, .3, .3)); 
		board->setVisible(false);


		CC3ProjectionMatrix *matrix = CC3ProjectionMatrix::matrix();
		matrix->populateFromRotation(cc3v(45,65,-2));
		matrix->translateBy(cc3v(1,2.1,-2));

		CC3Vector a = matrix->extractTranslation();
		CC3PODResourceNode *board2 = CC3PODResourceNode::nodeFromFile("board.pod");
		board2->setScale(cc3v(.3, .3, .3));
		addChild(board2);


		CC3AffineMatrix *test = CC3AffineMatrix::matrix();
		test->translateBy(board->getLocation());
		CC3Quaternion quat;
		quat.fromRotation(board->getRotation());
		test->rotateByQuaternion(quat);
		test->scaleBy(board->getScale());

		return;

		//board->runAction(CC3RepeatForever::create(CC3RotateBy::actionWithDuration(10,cc3v(0,360,0))));

// 		CC3PODResourceNode *meshNode = CC3PODResourceNode::nodeFromFile( "models/xe.pod");
// 		meshNode->setLocation(cc3v(0,.5,-1));
// 		addChild(meshNode);
// 
// 		meshNode = CC3PODResourceNode::nodeFromFile( "models/xe.pod");
// 		meshNode->setLocation(cc3v(0,0,0));
// 		addChild(meshNode);
	
		//initWithGameLogic(new GameLogic());
}

void Scene3D::initWithGameLogic(GameLogic *logic)
{
	setupWithPlayer(logic->_front,true);
	setupWithPlayer(logic->_back,false);

	//addChild(CC3Node::nodeWithName("hn"));

}

void Scene3D::setupWithPlayer(Player *player,bool front)
{

	vector<GameObject *> objects = player->objects;
	for(vector<GameObject *>::iterator iter = player->objects.begin();iter != player->objects.end();iter++)
	{
		objects.push_back((*iter));
	}
	for(int i=0;i<objects.size();i++)
	{
		string path = "models/";
		path += getTypeGameObject(objects[i]->_type);
		path += ".pod";
		CC3PODResourceNode *meshNode = CC3PODResourceNode::nodeFromFile( path.c_str());
		objects[i]->setUserData(meshNode);
		if(meshNode)
		{
			addChild(meshNode);
			meshNode->setLocation(getRealPosition(objects[i]->_position));
			if(front)
			{
				meshNode->setDiffuseColor(ccc4f(.2,.2,.2,1));
				if(objects[i]->_type == GameObject::kMa)
				{
					meshNode->setRotation(cc3v(0,180,0));
				}
			}
				
			else
			{
				meshNode->setDiffuseColor(ccc4f(.8,.8,.8,1));
			}

		}

	}
}


void Scene3D::update( float dt )
{
	//CCLOG("%f",lamp->getLocation().z);

}

void Scene3D::touchEvent( GLuint touchType, const CCPoint& touchPoint )
{

	CC3Ray ray = cam->unprojectPoint(touchPoint);
	
}

CC3Vector Scene3D::getRealPosition(CCPoint pos)
{
	CC3Vector position;
	position.x = -3.5f + pos.y;
	position.y = 0;
	position.z = 3.5f - pos.x;
	return position;
}

string Scene3D::getTypeGameObject(GameObject::Type type)
{
	string ret = "tot";
	switch (type)
	{
	case GameObject::kHau:
		{
			ret = "hau";break;
		}
	case GameObject::kXe:
		{
			ret = "xe";break;
		}
	case GameObject::kTuong:
		{
			ret = "tuong";break;
		}
	case GameObject::kTot:
		{
			ret = "tot";break;
		}
	case GameObject::kTinh:
		{
			ret = "tinh";break;
		}
	case GameObject::kMa:
		{
			ret = "ma";break;
		}
	default:
		break;	
	}
	return ret;
}