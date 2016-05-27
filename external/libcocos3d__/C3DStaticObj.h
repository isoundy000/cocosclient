#ifndef SCENEMODEL_H_
#define SCENEMODEL_H_

#include "C3DRenderNode.h"
#include "BundleData.h"
#include <vector>
using namespace std;
namespace cocos3d
{
class C3DMaterial;
class C3DScene;
class C3DNode;
class MeshBatch;

/**
*Defines this static object of the scene,which can change material.
*/
class C3DStaticObj : public C3DRenderNode
{
	friend class C3DScene;
public:

    static C3DStaticObj* create(const std::string& id);

	virtual bool loadFromFile(const std::string& fileName,bool isLoadAll=false);
	virtual bool load(bool isLoadAll=false);
	virtual bool load(const std::string& fileName);

	C3DNode::Type getType() const;

	void calculateBoundingBox_();

	virtual void copyFrom(const C3DTransform* other, C3DNode::CloneContext& context);
	virtual C3DNode* clone(CloneContext& context) const;

public:

    C3DStaticObj(const std::string& id);
    ~C3DStaticObj();

public:
	MeshData *_messData;
};
}

#endif
