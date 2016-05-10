#include "ast.h"
#include "structures.h"

using namespace AST;

/* ================Print Methods================*/
//Integer
void Integer::printTree() {
	std::cout << "inteiro "<< value;
	return;
}
//Double
void Double::printTree() {
	std::cout << "real "<<value;
	return;
}
//Boolean
void Boolean::printTree() {
	std::string result = ( value?"true":"false" );
	std::cout << "booleano "<<result;
}


//Binary Operation
void BinOp::printTree() {
	std::cout <<"(";
	left->printTree();
	switch( op ) {
		case oplus: std::cout << " soma "; break;
		case omult: std::cout << " multiplicacao "; break;
		case AST::oassign: std::cout << " = "; break;
	}
	right->printTree();
	std::cout <<")";
	return;
}
//Block
void Block::printTree() {
	for ( Node *line: lines ) {
		line->printTree();
		std::cout << std::endl;
	}
}

//Variable
void Variable::printTree() {
	if( next != nullptr ) {
		next->printTree();
		std::cout << ", ";
	} else {
		std::string message = "Tipo Fantasma " + this->id;
		switch ( this->useType ) {
			case AST::Variable::atrib: {message = "atribuicao de variavel " + this->id ; break;}
			case AST::Variable::ini: {message = "inicializacao de variavel " + this->id ; break;}
			case AST::Variable::read: {
				//std::cout<<"[ST  com "<<simbolTable->symbolMap.size()<<" atribuiu? "<<simbolTable->jaAtribuiu<<"]";
				//DataContainer thisValue(4);
				switch( simbolTable->getidentifierType( this->id ) ) {
					case Structures::tBool: {
						message = "booleano "+ this->id;
						break;
					}
					case Structures::tDouble: {
						message = "real " + this->id;
						break;
					}
					case Structures::tInteger: {
						message = "inteiro " + this->id;
						break;
					}
				};
				//message="leitura de variavel "
				//message = "";  break;
			}
		}
		std::cout<<message;
		return;
	}
	std::cout << this->id;
	return;
}


/* ================Compute methods================*/
//Integer
DataContainer Integer::computeTree() {
	return DataContainer( value );
}
//Integer
DataContainer Double::computeTree() {
	return DataContainer( value );
}

DataContainer Boolean::computeTree() {
	return DataContainer( value );
}

//Binary Operation
DataContainer BinOp::computeTree() {
	DataContainer lvalue = left->computeTree();
	DataContainer rvalue = right->computeTree();
//	std::cout << "[Debug][AST] Operacao com " << *(int*)lvalue.data << " e " << *(int*)rvalue.data<<std::endl;
	switch( op ) {
		case oplus: {
			DataContainer value = lvalue + rvalue; return value; break;
		}
		case omult: {
			DataContainer value = lvalue * rvalue; return value; break;
		}
		case AST::oand: {
			DataContainer value = lvalue and rvalue; return value; break;
		}
		case AST::oor: {
			DataContainer value = lvalue or rvalue; return value; break;
		}
		/*Syntax: var assign expression*/
		case AST::oassign: {
			Variable *var = dynamic_cast<Variable *>( left );
			simbolTable->updateIdentifierValue( var->id,rvalue );
			//std::cout <<"valor de " << var->id <<" atualizado para " << simbolTable->symbolMap[var->id].value << "\n";
			DataContainer value = simbolTable->getIdentifierValue( var->id );
			return value;
			break;
		}
	}
	return DataContainer( 0 );
}
//Block
DataContainer Block::computeTree() {
	std::cout<<"[Block com "<<lines.size()<<"]\n";
	for ( Node *line: lines ) {
		DataContainer value = line->computeTree();
		//std::cout << "Computed " << value << std::endl;
	}
	return 0;
}
//Variable
DataContainer Variable::computeTree() {
	Structures::Symbol thisSymbol = simbolTable->symbolMap[this->id];
	return thisSymbol.value;
}


