#include "../Header/Element/Bumker/BunkerModel.h"

namespace Element
{
	namespace Bunker
	{
		BunkerData::BunkerData() { };

		BunkerData::BunkerData(sf::Vector2f position)
		{
			this->position = position;
		}
	}
}
