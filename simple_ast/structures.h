#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>

namespace Structures {

	class Identifier {
	public:
		std::string idName;
		bool operator == (Identifier id2) {
			if((id2.idName.compare(this->idName))==0){
				return true;}
			return false;
		};
		Identifier(std::string);
	};

	class IdList {
	public:
		std::map<std::string , int> idMap;
		IdList();
//Returns true if sucefuly inserted the identifier in list. If a error ocurred, or the identifier was already inserted.
		bool insertIdentifier(Structures::Identifier id, int value);	
                bool containsIdentifier(Structures::Identifier id);
                int getIdentifierValue(Structures::Identifier id);
	};


}
