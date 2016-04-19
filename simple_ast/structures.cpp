#include "structures.h"
#include "ast.h"

Structures::SymbolTable::IdList() {
}

Structures::Symbol::Identifier ( std::string identifier )  {
	this->idName = identifier;
}


/*
 idMap is a <string,Identifier> Map !
 Where string is the id. name (the "var name")
 and id is the identifier infos (A Structures::Identifier obj)
 */

AST::Node *Structures::SymbolTable::insertVariable ( std::__cxx11::string idName, AST::Node nextVar ) {
	if ( this->symbolMap.find( idName ) == this->symbolMap.end() ) {
		std::pair<std::string,Structures::Symbol> newElement ( idName,id );
		this->symbolMap.insert ( newElement );
		return true;
	} else {
		yyerror( "Variable redefinition! [%s]",idName.c_str() );
	}
	return new AST::Variable( idName,nextVar );
}

bool Structures::SymbolTable::containsIdentifier( std::string idName ) {
	return ( !( this->symbolMap.find( idName ) == this->symbolMap.end() ) );
}

AST::Node Structures::SymbolTable::getIdentifierValue( std::string id ) {
	if( !containsIdentifier( id ) ) {
		yyerror( "Variable \"%s\" used but not defined!",id.c_str() );
	}
	if( !symbolMap[id].initialized ) {
		yyerror( "Variable \"%s\" defined but not initilized!",id.c_str() );
	}
	return new AST::Variable( id, NULL );
}

AST::Node *Structures::SymbolTable::assignVariable( std::__cxx11::string id ) {
	if( !containsIdentifier( id ) ) {
		yyerror( "Variable \"%s\" used but not defined!",id.c_str() );
	}
	this->symbolMap[id].initialized=true;
	return new AST::Variable( id,NULL );
}

