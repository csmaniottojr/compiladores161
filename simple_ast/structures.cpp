#include "structures.h"

Structures::IdList::IdList() {

}

Structures::Identifier::Identifier ( std::string identifier )  {
this->idName = identifier;
}



bool Structures::IdList::insertIdentifier ( Structures::Identifier id ,int value ) {
	if ( this->idMap.find( id.idName ) == this->idMap.end() ) {
		std::pair<std::string,int> newElement ( id.idName,value );
		this->idMap.insert ( newElement );
		return true;
	}
	return false;
}

