#include "BoxObject.h"

BoxObject::BoxObject(sf::Vector2f& m_position, TileSetManager& m_tileSetManager) 
	: TexturedObject(m_position, "box", m_tileSetManager, "cactus")
{

}

BoxObject::~BoxObject()
{
}
