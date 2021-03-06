#include "C3DMaterial.h"
#include "C3DStream.h"
#include "C3DPass.h"
#include "C3DElementNode.h"
#include "C3DTexture.h"
#include "C3DTechnique.h"
#include "C3DSampler.h"
#include "MaterialParameter.h"
#include "C3DEffect.h"
#include "C3DVector3.h"
#include "C3DVector4.h"
#include "C3DRenderChannel.h"

namespace cocos3d
{
C3DMaterial::C3DMaterial(const std::string& name) : C3DResource(name)
{
    memset(_techniqueChannel, 0, sizeof(_techniqueChannel));
}

C3DMaterial::~C3DMaterial()
{
    // Destroy all the techniques.
    for (unsigned int i = 0, count = _techniques.size(); i < count; ++i)
    {
        C3DTechnique* technique = _techniques[i];
        if (technique)
        {
            SAFE_RELEASE(technique);
        }
    }
    memset(_techniqueChannel, 0, sizeof(_techniqueChannel));
}

C3DMaterial* C3DMaterial::create(const std::string& fileName)
{
	assert(!fileName.empty());

    // Load the material properties from file
    C3DElementNode* nodes = C3DElementNode::create(fileName);
    assert(nodes);
    if (nodes == NULL)
    {
        return NULL;
    }

    C3DElementNode* materialNodes = nodes->getNodeType().empty() ? nodes->getNextChild() : nodes;
    if (!materialNodes || materialNodes->getNodeType() != "material")
    {
        return NULL;
    }
	C3DMaterial* material = C3DMaterial::create(materialNodes);

	//material->setName(fileName);
    SAFE_DELETE(nodes);

	return material;
}

C3DMaterial* C3DMaterial::create(C3DElementNode* materialNodes)
{
    // Check if the Properties is valid and has a valid namespace.
    assert(materialNodes);
    if (!materialNodes || materialNodes->getNodeType() != "material")
    {
        return NULL;
    }

	// Create new material from the file passed in.

	C3DMaterial* material = new C3DMaterial("");
	if(material->load(materialNodes) == false)
	{
		SAFE_RELEASE(material);
		return NULL;
	}

	material->autorelease();
	return material;
}

//C3DMaterial* C3DMaterial::create(C3DEffect* effect)
//{
//    CC_ASSERT(effect);
//    if (effect == NULL)
//    {
//        CCLOGERROR("effect null in C3DMaterial::create()");
//        return NULL;
//    }
//
//    // Create a new material with a single technique and pass for the given effect.
//    C3DMaterial* material = new C3DMaterial();
//
//    C3DTechnique* technique = new C3DTechnique(NULL, material);
//    material->_techniques.push_back(technique);
//
//    C3DPass* pass = new C3DPass(NULL, technique, effect);
//    technique->_passes.push_back(pass);
//    effect->retain();
//
//    material->_techniqueChannel[TECH_USAGE_SCREEN] = technique;
//
//	material->autorelease();
//
//    return material;
//}

C3DMaterial* C3DMaterial::create(const std::string& vshPath, const std::string& fshPath, const std::string& defines)
{
    // Create a new material with a single technique and pass for the given effect
    C3DMaterial* material = new C3DMaterial("");

	cocos3d::C3DElementNode* tpMatNode = cocos3d::C3DElementNode::createEmptyNode("0", "material");
	if (!tpMatNode)
		return NULL;

	cocos3d::C3DElementNode* tpNodeTechnique = cocos3d::C3DElementNode::createEmptyNode("0", "technique");
	tpMatNode->addChildNode(tpNodeTechnique);

	cocos3d::C3DElementNode* tpNodePass = cocos3d::C3DElementNode::createEmptyNode("0", "pass");
	tpNodeTechnique->addChildNode(tpNodePass);
	tpNodePass->setElement("vertexShader", vshPath);
	tpNodePass->setElement("fragmentShader", fshPath);
	if(!defines.empty())
		tpNodePass->setElement("defines", defines);

	material->load(tpMatNode);
	material->autorelease();

	SAFE_DELETE(tpMatNode);

	return material;
}

unsigned int C3DMaterial::getTechniqueCount() const
{
    return _techniques.size();
}

C3DTechnique* C3DMaterial::getTechnique(unsigned int index) const
{
    assert(index < _techniques.size());

    return _techniques[index];
}

C3DTechnique* C3DMaterial::getTechnique(const std::string& id) const
{
    for (unsigned int i = 0, count = _techniques.size(); i < count; ++i)
    {
        C3DTechnique* t = _techniques[i];
        if (t->getId() == id)
        {
            return t;
        }
    }

    return NULL;
}

C3DTechnique* C3DMaterial::getTechnique() const
{
	return _techniqueChannel[TECH_USAGE_SCREEN];
}

C3DTechnique* C3DMaterial::getTechnique(TechniqueUsage usage) const
{
    CCAssert(usage >= 0 && usage < TECH_USAGE_NUM, "index out of range");
    return _techniqueChannel[usage];
}

bool C3DMaterial::setTechnique(TechniqueUsage usage, const std::string& id)
{
    CCAssert(usage >= 0 && usage < TECH_USAGE_NUM, "index out of range");
    C3DTechnique* t = getTechnique(id);
    if (t)
    {
        _techniqueChannel[usage] = t;
    }
    return t != NULL;
}

bool C3DMaterial::setTechnique(TechniqueUsage usage, unsigned int index)
{
    CCAssert(usage >= 0 && usage < TECH_USAGE_NUM, "index out of range");
    C3DTechnique* t = getTechnique(index);
    if (t)
    {
        _techniqueChannel[usage] = t;
    }
    return t != NULL;
}

bool C3DMaterial::save(C3DElementNode* nodes)
{
    C3DRenderState::save(nodes);

    for (size_t i = 0; i < this->_techniques.size(); i++)
    {
        C3DTechnique* technique = this->_techniques[i];
		C3DElementNode* techNode = C3DElementNode::createEmptyNode(technique->getId(), "technique");

		if (technique->save(techNode) == true)
        {
            nodes->addChildNode(techNode);
        }
		else
		{
			SAFE_DELETE(techNode);
			return false;
		}
    }

    return true;
}

C3DMaterial* C3DMaterial::clone() const
{
	C3DMaterial* other = new C3DMaterial("");
	((C3DRenderState*)other)->copyFrom(this);

	((C3DResource*)other)->copyFrom(this);

	for (size_t i = 0; i < _techniques.size(); i++)
	{
		other->_techniques.push_back(_techniques[i]->clone());
		other->_techniques[i]->retain();
		other->_techniques[i]->_parent = other;
		other->_techniques[i]->_material = other;

        for (int iUsage = 0; iUsage < TECH_USAGE_NUM; iUsage++)
        {
            if (_techniqueChannel[iUsage] == _techniques[i])
                other->_techniqueChannel[iUsage] = other->_techniques[i];
        }
	}

	other->autorelease();
	return other;
}

bool C3DMaterial::load(C3DElementNode* materialNodes)
{
    // Go through all the material properties and create techniques under this material.
    materialNodes->rewind();
	C3DElementNode* techniqueNodes = NULL;
    while ((techniqueNodes = materialNodes->getNextChild()))
    {
        if (techniqueNodes->getNodeType() == "technique")
        {
			C3DTechnique* technique = new C3DTechnique();
            if (technique->load(techniqueNodes) == false)
            {
				SAFE_RELEASE(technique);
                return false;
            }
			else
			{
				technique->_material = this;
				technique->_parent = this;
				this->_techniques.push_back(technique);
			}
        }
    }

    // Load uniform value parameters for this material
    C3DRenderState::load(materialNodes);

    // setup parameter from effect
    for (unsigned int i = 0, count = this->_techniques.size(); i < count; ++i)
    {
        C3DTechnique* technique = this->_techniques[i];
        if (technique)
        {
            for (unsigned int j = 0; j < technique->_passes.size(); ++j)
            {
                technique->_passes[j]->setupParametersFromEffect();
            }
        }
    }

    // Set the current technique to the first found technique
    if (this->getTechniqueCount() > 0)
    {
        this->setTechnique(TECH_USAGE_SCREEN, 0u);
        this->setTechnique(TECH_USAGE_SHADOWMAP, "_castshadow");
    }

	return true;
}
}