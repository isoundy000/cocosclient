#include "Base.h"
#include "C3DNode.h"
#include "C3DScene.h"
#include "C3DCamera.h"
#include "C3DLayer.h"

#include "C3DRenderSystem.h"
#include "C3DGeoWireRender.h"

#include "C3DAABB.h"
#include "C3DOBB.h"
#include "C3DActionManager.h"

namespace cocos3d
{
    C3DNode::C3DNode()
    : _scene(NULL),_parent(NULL),_active(true),
    _dirtyBits(NODE_DIRTY_ALL), _notifyHierarchyChanged(true), _listeners(NULL)
    {
        _id = "";
        
        _showAABB = false;
        _showOBB = false;
        
        _bb = NULL;
        _bbOrigin = NULL;
        
        _obb.clear();
        
        _actionManager = C3DActionManager::getInstance();
    }
    
    C3DNode::C3DNode(const std::string& id)
    : _scene(NULL),_parent(NULL),_active(true),
    _dirtyBits(NODE_DIRTY_ALL), _notifyHierarchyChanged(true), _listeners(NULL)
    {
        if (!id.empty())
        {
            _id = id;
        }
        
        _showAABB = false;
        _showOBB = false;
        
        _bb = NULL;
        _bbOrigin = NULL;
        
        _obb.clear();
        _actionManager = C3DActionManager::getInstance();
    }
    
    C3DNode::~C3DNode()
    {
        removeAllChildren();
        
        SAFE_DELETE(_listeners);
        
        if(_parent != NULL)
        {
            for(std::vector<C3DNode*>::iterator iter=_parent->_children.begin(); iter!=_parent->_children.end(); ++iter)
            {
                if(*iter==this)
                {
                    _parent->_children.erase(iter);
                    _parent = NULL;
                    break;
                }
            }
        }
        
        SAFE_DELETE(_bb);
        SAFE_DELETE(_bbOrigin);
        
        //string log = "node3d "; log += _id; log += " deleted !";
        //CCLOG("%s",log.c_str());
    }
    
    C3DNode* C3DNode::create(const std::string& id)
    {
        C3DNode* pRet = new C3DNode(id);
        
        pRet->autorelease();
        return pRet;
    }
    
    const std::string& C3DNode::getId()
    {
        return _id;
    }
    
    void C3DNode::setId(const std::string& id)
    {
        if (!id.empty())
        {
            _id = id;
        }
    }
    
    C3DNode::Type C3DNode::getType() const
    {
        return C3DNode::NodeType_Normal;
    }
    
    void C3DNode::addChild(C3DNode* child)
    {
        assert(child);
        
        if (child->_parent == this)
        {
            //  This node is already present in our hierarchy
            return;
        }
        
        child->retain();
        
        //  If the item belongs to another hierarchy, remove it first.
        if (child->_parent)
        {
            child->_parent->removeChild(child);
        }
        
        child->_parent = this;
        _children.push_back( child );
        
        child->transformChanged();
        onChildChanged(ADD, child);
        
        if (_notifyHierarchyChanged)
        {
            hierarchyChanged();
        }
    }
    
    void C3DNode::removeChild(C3DNode* child)
    {
        if (child == NULL || child->_parent != this)
        {
            // The child is not in our hierarchy.
            return;
        }
        
        for(std::vector<C3DNode*>::iterator iter=_children.begin(); iter!=_children.end(); ++iter)
        {
            if(*iter==child)
            {
                child->_parent = NULL;
                _children.erase(iter);
                
                break;
            }
        }
        
        if (_notifyHierarchyChanged)
        {
            hierarchyChanged();
        }
        
        onChildChanged(REMOVE, child);
        SAFE_RELEASE(child);
    }
    
    void C3DNode::removeAllChildren()
    {
        _notifyHierarchyChanged = false;
        for(std::vector<C3DNode*>::iterator iter=_children.begin(); iter!=_children.end();)
        {
            C3DNode* child = *iter;
            if (child == NULL || child->_parent != this)
            {
                ++iter;
                continue;
            }
            else
            {
                onChildChanged(REMOVE, child);
                child->_parent = NULL;
                SAFE_RELEASE(child);
                iter = _children.erase(iter);
            }
        }
        _children.clear();
        
        _notifyHierarchyChanged = true;
        hierarchyChanged();
    }
    
    void C3DNode::removeFromParent()
    {
        if (_parent)
        {
            _parent->removeChild(this);
        }
        
    }
    
    
    void C3DNode::setActionManager(C3DActionManager* actionManager)
    {
        if( actionManager != _actionManager ) {
            this->stopAllActions();
            CC_SAFE_RETAIN(actionManager);
            CC_SAFE_RELEASE(_actionManager);
            _actionManager = actionManager;
        }
    }
    
    C3DActionManager *C3DNode::getActionManager()
    {
        return _actionManager;
    }
    
    C3DAction *C3DNode::runAction(C3DAction* action)
    {
        CCAssert( action != NULL, "Argument must be non-nil");
        _actionManager->addAction(action, this, false);
        return action;
    }
    
    void C3DNode::stopAllActions()
    {
        _actionManager->removeAllActionsFromTarget(this);
    }
    
    void C3DNode::stopAction(C3DAction* action)
    {
        _actionManager->removeAction(action);
    }
    
    void C3DNode::stopActionByTag(int tag)
    {
        CCAssert( tag != kCCActionTagInvalid, "Invalid tag");
        _actionManager->removeActionByTag(tag, this);
    }
    
    C3DAction * C3DNode::getActionByTag(int tag)
    {
        CCAssert( tag != kCCActionTagInvalid, "Invalid tag");
        return _actionManager->getActionByTag(tag, this);
    }
    
    unsigned int C3DNode::numberOfRunningActions()
    {
        return _actionManager->numberOfRunningActionsInTarget(this);
    }
    
    
    
    C3DNode* C3DNode::getParent()
    {
        return _parent;
    }
    
    C3DNode* C3DNode::findNode(const std::string& id, bool recursive)
    {
        assert(!id.empty());
        
        for(std::vector<C3DNode*>::const_iterator iter=_children.begin(); iter!=_children.end(); ++iter)
        {
            if((*iter)->_id.compare(id) == 0)
            {
                return *iter;
            }
        }
        
        if (recursive)
        {
            for(std::vector<C3DNode*>::const_iterator iter=_children.begin(); iter!=_children.end(); ++iter)
            {
                C3DNode* match = (*iter)->findNode(id, true);
                if (match)
                {
                    return match;
                }
            }
        }
        
        return NULL;
    }
    
    void C3DNode::update(long elapsedTime)
    {
        size_t i;
        for (i = 0; i < _children.size(); ++i)
        {
            C3DNode* node = _children[i];
            if(node->active())
                node->update(elapsedTime);
        }
    }
    
    void C3DNode::draw()
    {
        size_t i;
        for (i = 0; i < _children.size(); ++i)
        {
            C3DNode* node = _children[i];
            if(node->active())
                node->draw();
        }
    }
    
    void C3DNode::drawDebug()
    {
        if (_showAABB)
            drawAABB();
        if (_showOBB)
            drawOBB();
    }
    
    unsigned int C3DNode::getTriangleCount() const
    {
        return 0;
    }
    
    C3DScene* C3DNode::getScene()
    {
        return _scene;
        //return C3DLayer::getInstance()->getScene();
    }
    
    C3DNode* C3DNode::getRootNode()
    {
        C3DNode* n = this;
        while (n->getParent())
        {
            n = n->getParent();
        }
        return n;
    }
    
    const C3DMatrix& C3DNode::getWorldMatrix()
    {
        if (_dirtyBits & NODE_DIRTY_WORLD)
        {
            // Clear our dirty flag immediately to prevent this block from being entered if our
            // parent calls our getWorldMatrix() method as a result of the following calculations.
            _dirtyBits &= ~NODE_DIRTY_WORLD;
            
            // If we have a parent, multiply our parent world transform by our local
            // transform to obtain our final resolved world transform.
            C3DNode* parent = getParent();
            if (parent)
            {
                C3DMatrix::multiply(parent->getWorldMatrix(), getMatrix(), &_world);
            }
            else
            {
                _world = getMatrix();
            }
            
            // Our world matrix was just updated, so call getWorldMatrix() on all child nodes
            // to force their resolved world matrices to be updated.
            for(std::vector<C3DNode*>::const_iterator iter=_children.begin(); iter!=_children.end(); ++iter)
            {
                (*iter)->getWorldMatrix();
            }
        }
        
        return _world;
    }
    
    const C3DMatrix& C3DNode::getWorldViewMatrix()
    {
        static C3DMatrix worldView;
        
        C3DMatrix::multiply(getViewMatrix(), getWorldMatrix(), &worldView);
        
        return worldView;
    }
    
    const C3DMatrix& C3DNode::getInverseTransposeWorldViewMatrix()
    {
        static C3DMatrix invTransWorldView;
        C3DMatrix::multiply(getViewMatrix(), getWorldMatrix(), &invTransWorldView);
        invTransWorldView.invert();
        invTransWorldView.transpose();
        return invTransWorldView;
    }
    
    const C3DMatrix& C3DNode::getInverseTransposeWorldMatrix()
    {
        static C3DMatrix invTransWorld;
        invTransWorld = getWorldMatrix();
        invTransWorld.invert();
        invTransWorld.transpose();
        return invTransWorld;
    }
    
    const C3DMatrix& C3DNode::getViewMatrix()
    {
        C3DScene* scene = getScene();
        C3DCamera* camera = scene ? scene->getActiveCamera() : NULL;
        if (camera)
        {
            return camera->getViewMatrix();
        }
        else
        {
            return C3DMatrix::identity();
        }
    }
    
    const C3DMatrix& C3DNode::getInverseViewMatrix()
    {
        C3DScene* scene = getScene();
        C3DCamera* camera = scene ? scene->getActiveCamera() : NULL;
        if (camera)
        {
            return camera->getInverseViewMatrix();
        }
        else
        {
            return C3DMatrix::identity();
        }
    }
    
    const C3DMatrix& C3DNode::getProjectionMatrix()
    {
        C3DScene* scene = getScene();
        C3DCamera* camera = scene ? scene->getActiveCamera() : NULL;
        if (camera)
        {
            return camera->getProjectionMatrix();
        }
        else
        {
            return C3DMatrix::identity();
        }
    }
    
    void C3DNode::setScene(C3DScene* scene)
    {
        _scene = scene;
        
        for (size_t i = 0; i < _children.size(); i++)
        {
            _children[i]->setScene(scene);
        }
    }
    
    const C3DMatrix& C3DNode::getViewProjectionMatrix()
    {
        C3DScene* scene = getScene();
        
        if (scene)
        {
            return scene->getViewProjectionMatrix();
        }
        else
        {
            return C3DMatrix::identity();
        }
    }
    
    const C3DMatrix& C3DNode::getInverseViewProjectionMatrix()
    {
        C3DScene* scene = getScene();
        C3DCamera* camera = scene ? scene->getActiveCamera() : NULL;
        if (camera)
        {
            return camera->getInverseViewProjectionMatrix();
        }
        
        return C3DMatrix::identity();
    }
    
    const C3DMatrix& C3DNode::getWorldViewProjectionMatrix()
    {
        static C3DMatrix worldViewProj;
        
        // Always re-calculate worldViewProjection matrix since it's extremely difficult
        // to track whether the camera has changed (it may frequently change every frame).
        C3DMatrix::multiply(getViewProjectionMatrix(), getWorldMatrix(), &worldViewProj);
        
        return worldViewProj;
    }
    
    C3DVector3 C3DNode::getTranslationWorld()
    {
        C3DVector3 translation;
        getWorldMatrix().getPosition(&translation);
        return translation;
    }
    
    const C3DQuaternion C3DNode::getRotationWorld()
    {
        C3DQuaternion quaternion;
        getWorldMatrix().getRotation(&quaternion);
        
        return quaternion;
    }
    
    C3DVector3 C3DNode::getTranslationView()
    {
        C3DVector3 translation;
        getWorldMatrix().getPosition(&translation);
        getViewMatrix().transformPoint(&translation);
        return translation;
    }
    
    C3DVector3 C3DNode::getRightVectorWorld()
    {
        C3DVector3 vector;
        getWorldMatrix().getRightVector(&vector);
        return vector;
    }
    
    C3DVector3 C3DNode::getRightVectorView()
    {
        C3DVector3 vector;
        getWorldMatrix().getRightVector(&vector);
        getViewMatrix().transformVector(&vector);
        return vector;
    }
    
    C3DVector3 C3DNode::getUpVectorWorld()
    {
        C3DVector3 vector;
        getWorldMatrix().getUpVector(&vector);
        return vector;
    }
    
    C3DVector3 C3DNode::getUpVectorView()
    {
        C3DVector3 vector;
        getWorldMatrix().getUpVector(&vector);
        getViewMatrix().transformVector(&vector);
        return vector;
    }
    
    C3DVector3 C3DNode::getForwardVectorWorld()
    {
        C3DVector3 vector;
        getWorldMatrix().getForwardVector(&vector);
        return vector;
    }
    
    C3DVector3 C3DNode::getForwardVectorView()
    {
        C3DVector3 vector;
        getWorldMatrix().getForwardVector(&vector);
        getViewMatrix().transformVector(&vector);
        return vector;
    }
    
    void C3DNode::setForwardVectorWorld(C3DVector3& forwardVector)
    {
        C3DVector3 up = getUpVectorWorld();
        C3DVector3 right;
        C3DVector3::cross(-forwardVector,up,&right);
        right.normalize();
        C3DVector3 pos = C3DVector3(0,0,0);
        C3DMatrix m  = C3DMatrix::createFromVectors(right,up,forwardVector,pos);
        
        setRotation(m);
    }
    
    const C3DVector3 C3DNode::getActiveCameraTranslationWorld()
    {
        C3DScene* scene = getScene();
        if (scene)
        {
            C3DCamera* camera = scene->getActiveCamera();
            if (camera)
            {
                return camera->getTranslationWorld();
            }
        }
        
        return C3DVector3::zero();
    }
    
    const C3DVector3 C3DNode::getActiveCameraTranslationView()
    {
        C3DScene* scene = getScene();
        if (scene)
        {
            C3DCamera* camera = scene->getActiveCamera();
            if (camera)
            {
                return camera->getTranslationView();
            }
        }
        
        return C3DVector3::zero();
    }
    
    void C3DNode::hierarchyChanged()
    {
        // When our hierarchy changes our world transform is affected, so we must dirty it.
        //transformChanged();
    }
    
    void C3DNode::addListener(C3DNode::Listener* listener)
    {
        if (_listeners == NULL)
            _listeners = new std::list<C3DNode::Listener*>();
        
        _listeners->push_back(listener);
    }
    
    void C3DNode::removeListener(C3DNode::Listener* listener)
    {
        if (_listeners)
        {
            for (std::list<Listener*>::iterator itr = _listeners->begin(); itr != _listeners->end(); itr++)
            {
                if ((*itr) == listener)
                {
                    _listeners->erase(itr);
                    break;
                }
            }
        }
    }
    
    void C3DNode::transformChanged()
    {
        // Our local transform was changed, so mark our world matrices dirty.
        _dirtyBits |= NODE_DIRTY_WORLD | NODE_DIRTY_BOUNDS_AABB | NODE_DIRTY_BOUNDS_OBB;
        
        if (_listeners)
        {
            for (std::list<Listener*>::iterator itr = _listeners->begin(); itr != _listeners->end(); itr++)
            {
                (*itr)->transformChanged(this);
            }
        }
        
        // Notify our children that their transform has also changed (since transforms are inherited).
        for(std::vector<C3DNode*>::const_iterator iter=_children.begin(); iter!=_children.end(); ++iter)
        {
            (*iter)->transformChanged();
        }
    }
    
    void C3DNode::setBoundsDirty()
    {
        // Mark ourself and our parent nodes as dirty
        // _dirtyBits |= NODE_DIRTY_BOUNDS;
        
        // Mark our parent bounds as dirty as well
        /*if (_parent)
         _parent->setBoundsDirty();*/
    }
    
    void C3DNode::setScreenPos(int x, int y, float depthZ)
    {
        if (_scene)
        {
            const C3DViewport* pViewport = C3DRenderSystem::getInstance()->getViewport();
            C3DCamera* camera = _scene->getActiveCamera();
            
            C3DVector3 src(x, y, depthZ), dst;
            
            camera->unproject(pViewport, &src, &dst);
            
            setPosition(dst);
        }
    }
    
    void C3DNode::setScreenPos(int x, int y)
    {
        if (_scene)
        {
            setScreenPos(x, y, _scene->getDefDepthZ());
        }
    }
    
    bool C3DNode::active()
    {
        return _active;
    }
    
    void C3DNode::active(bool active)
    {
        _active = active;
    }
    
    void C3DNode::copyFrom(const C3DTransform* other, C3DNode::CloneContext& context)
    {
        if (this == other)
            return;
        
        C3DTransform::copyFrom(other);
        const C3DNode* otherNode = static_cast<const C3DNode*>(other);
        _active = otherNode->_active;
        //_scene = otherNode->_scene;
        _id = otherNode->_id + context.idSuffix;
        _world = otherNode->_world;
        _dirtyBits = otherNode->_dirtyBits;
        _notifyHierarchyChanged = otherNode->_notifyHierarchyChanged;
        
        _showAABB = otherNode->_showAABB;
        _showOBB = otherNode->_showOBB;
        
        _obb = otherNode->_obb;
        _obbOrigin = otherNode->_obbOrigin;
        
        if (otherNode->_bbOrigin)
        {
            if (!_bbOrigin)
                _bbOrigin = new C3DAABB();
            _bbOrigin->_min = otherNode->_bbOrigin->_min;
            _bbOrigin->_max = otherNode->_bbOrigin->_max;
        }
        
        if (otherNode->_bb)
        {
            if (!_bb)
                _bb = new C3DAABB();
            _bb->_min = otherNode->_bb->_min;
            _bb->_max = otherNode->_bb->_max;
        }
        
        if (context.cloneChildren)
        {
            removeAllChildren();
            _notifyHierarchyChanged = false;
            for (size_t i = 0; i < otherNode->_children.size(); i++)
            {
                C3DNode* node = otherNode->_children[i];
                std::map<const C3DNode*, C3DNode*>::iterator itr = context.cloneMap.find(node);
                
                C3DNode* child = NULL;
                if (itr != context.cloneMap.end())
                {
                    child = itr->second;
                }
                else
                {
                    C3DNode* newNode = otherNode->_children[i]->clone(context);
                    if (newNode)
                    {
                        context.cloneMap[node] = newNode;
                        child = newNode;
                    }
                }
                if (child)
                {
                    addChild(child);
                }
            }
            _notifyHierarchyChanged = true;
            hierarchyChanged();
        }
    }
    
    C3DNode* C3DNode::clone(C3DNode::CloneContext& context) const
    {
        if (getType() == NodeType_Normal)
        {
            C3DNode* other = new C3DNode();
            other->copyFrom(this, context);
            other->autorelease();
            return other;
        }
        else
        {
            assert(false && "Not implemented");
            return NULL;
        }
    }
    
    void C3DNode::onChildChanged(ChangeEvent eventType, C3DNode* child)
    {
        if (_parent)
        {
            _parent->onChildChanged(eventType, child);
        }
    }
    
    C3DNode* C3DNode::clone(const std::string& idSuffix) const
    {
        CloneContext context;
        context.idSuffix = idSuffix;
        context.cloneChildren = true;
        return clone(context);
    }
    
    void C3DNode::calculateBoundingBox_()
    {
        C3DAABB box;
        
        box._min = C3DVector3(-1.0f, -1.0f, -1.0f);
        box._max = C3DVector3(1.0f, 1.0f, 1.0f);
        
        if (!_bbOrigin)
            _bbOrigin = new C3DAABB();
        _bbOrigin->_min = box._min;
        _bbOrigin->_max = box._max;
        
        if (!_bb)
            _bb = new C3DAABB();
        _bb->_min = box._min;
        _bb->_max = box._max;
    }
    
    void C3DNode::calculateBoundingBox()
    {
        if (_bb == NULL)
        {
            calculateBoundingBox_();
        }
        else
        {
            _bb->_min = _bbOrigin->_min;
            _bb->_max = _bbOrigin->_max;
        }
        _bb->transform(getWorldMatrix());
    }
    
    void C3DNode::calculateOrientedBoundingBox()
    {
        if (_bb && _obb.extents.isZero())
        {
            calculateOrientedBoundingBox_();
        }
        else if (!_obbOrigin.extents.isZero())
        {
            _obb = _obbOrigin;
            C3DMatrix worldmat = getWorldMatrix();
            
            _obb.transform(worldmat);
            
            worldmat.transformPoint(_bbOrigin->getCenter(), &_obb.center);
            _obb.completeExtAxis();
        }
    }
    
    void C3DNode::calculateOrientedBoundingBox_()
    {
        // build from aabb
        _obb.build(*_bb);
        _obbOrigin = _obb;
        C3DMatrix mat = getWorldMatrix();
        mat.invertOrthMat();
        _obbOrigin.transform(mat);
    }
    
    C3DAABB* C3DNode::getAABB()
    {
        if (_dirtyBits & NODE_DIRTY_BOUNDS_AABB)
        {
            _dirtyBits &= ~NODE_DIRTY_BOUNDS_AABB;
            
            calculateBoundingBox();
        }
        
        return _bb;
    }
    
    void C3DNode::showAABB(bool show)
    {
        _showAABB = show;
    }
    
    bool C3DNode::showAABB()
    {
        return _showAABB;
    }
    
    void C3DNode::showOBB(bool show)
    {
        _showOBB = show;
    }
    bool C3DNode::showOBB()
    {
        return _showOBB;
    }
    
    C3DOBB* C3DNode::getOBB()
    {
        if (_dirtyBits & NODE_DIRTY_BOUNDS_OBB)
        {
            _dirtyBits &= ~NODE_DIRTY_BOUNDS_OBB;
            
            calculateOrientedBoundingBox();
        }
        return &_obb;
    }
    
    void C3DNode::drawAABB()
    {
        if(_active == false)
            return;
        
        if(this->getAABB() == NULL)
        {
            return;
        }
        
        _scene->getGeoWireRender()->addBoundingBox(_bb, C3DVector4(1.0f, 0.0f, 0.0f, 1.0f));
    }
    
    void C3DNode::drawOBB()
    {
        if(_active == false)
            return;
        
        if (_obb.extents.isZero())
            return;
        
        getOBB();
        
        _scene->getGeoWireRender()->addOBB(&_obb, C3DVector4(1.0f, 0.0f, 0.0f, 1.0f));
    }
    
    const C3DVector4& C3DNode::getTimeParam(void)
    {
        static C3DVector4 zero(0.0, 0.0, 0.0, 0.0);
        
        if ( _scene != NULL )
        {
            return _scene->getTimeParam();
        }
        else
        {
            return zero;
        }
    }
}