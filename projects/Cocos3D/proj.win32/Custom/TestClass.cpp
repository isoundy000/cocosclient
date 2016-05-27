#include "TestClass.h"


TestClass::TestClass(void)
{
}


TestClass::~TestClass(void)
{
}

void TestClass::setPosition(CCPoint pos)
{
	myPos = pos;
}

CCPoint TestClass::getPosition()
{
	return myPos;
}