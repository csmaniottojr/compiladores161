#include "ast.h"
#include "structures.h"


using namespace AST;

#define print std::cout
#define _case(X) {X break;}
#define _casePrint(X) {print << "X"; break;}

/*Aux methods*/
//===============================================
void BinOp::computeType() {
	std::cout << "[BinOp ("<< TypesString[left->type] <<" "<<TypesString[right->type]<<") ]"; 
	switch( left->type ) {
		case AST::tInt: {
			switch ( right->type ) {
				case AST::tInt:_case( this->type = AST::tInt; )
				case AST::tReal: _case( this->type = AST::tReal; )
				default:; //TODO Caso não seja compativel com INT!
			}
			break;
		}
		case AST::tReal: {
			switch ( right->type ) {
				case AST::tReal:;
				case AST::tInt: _case( this->type=AST::tReal; )
				default:; //TODO Caso não seja compativel com REAL!
			}
			break;
		}
		case AST::tBool: {
			switch( right->type ) {
				case AST::tBool: _case( this->type = AST::tBool; )
				default:;//TODO Caso não seja compativel com BOOL!
			}
		}
	}
}

/* ================Print Methods================*/
//Integer
//===============================================
void Integer::printTree() {
	std::cout << "inteiro "<< value;
	return;
}
//Double
//===============================================
void Double::printTree() {
	std::cout << "real "<<value;
	return;
}
//Boolean
//===============================================
void Boolean::printTree() {
	std::string result = ( value?"true":"false" );
	std::cout << "booleano "<<result;
}


//Binary Operation
//===============================================
void BinOp::printTree() {
	computeType();
	if( type == AST::undefined ) {
		std::cout <<"Operacao binaria com tipo indefinido!\n";
	}else{
	//	std::cout <<"\nOperacao binaria "<<tipoOperacoes[(int)type]<<"["<<tipoOperacoes[(int)left->type] << " , " << tipoOperacoes[(int)right->type]<<"]\n";
	}

std::cout <<"(";
left->printTree();
Types typeLeft = left->type, typeRight = right->type;


switch( op ) {
case AST::oplus: _case( print << " soma " << tipoOperacoes[( int )this->type] << " "; )
case AST::omult: _case( print << " multiplicacao "<< tipoOperacoes[( int )this->type] << " "; )
case AST::oassign: _case( print<< " = "; )
case AST::ominus: _case( print << " subtracao "<< tipoOperacoes[( int )this->type] << " "; )
case AST::oand: _case( print << " e "; )
case AST::odifferent: _case( print << " diferente de "<< tipoOperacoes[( int )this->type] << " "; )
case AST::odiv: _case( print << " divisao "<< tipoOperacoes[( int )this->type] << " "; )
case AST::oequal: _case ( print << " igual "<< tipoOperacoes[( int )this->type] << " "; )
case AST::ogreater: _case ( print << " maior que "<< tipoOperacoes[( int )this->type] << " "; )
case AST::ogreatereq: _case ( print << " maior ou igual que "<< tipoOperacoes[( int )this->type] << " "; )
case AST::oless:_case( print << " menor que "<< tipoOperacoes[( int )this->type] << " "; )
case AST::olesseq: _case ( print << " menor ou igual que "<< tipoOperacoes[( int )this->type] << " "; )
case AST::oor:_case ( print << " ou "; )
}
right->printTree();
std::cout <<")";
return;
}
//Block
//===============================================
void Block::printTree() {
	for ( Node *line: lines ) {
		line->printTree();
		std::cout << std::endl;
	}
}

//Variable
//===============================================
void Variable::printTree() {
	if( next != nullptr ) {
		next->printTree();
		std::cout << ", ";
	} else {
		std::string message = "Tipo Fantasma " + this->id;
		switch ( this->useType ) {
			case AST::Variable::atrib: {message = "atribuicao de variavel " + TypesString[( int )type] +" " + this->id ; break;}
			case AST::Variable::ini: {message = "inicializacao de variavel " + TypesString[( int )type] +" "+ this->id ; break;}
			case AST::Variable::read: {
				//std::cout<<"[ST  com "<<simbolTable->symbolMap.size()<<" atribuiu? "<<simbolTable->jaAtribuiu<<"]";
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

void Array::printTree() {
	if( next != nullptr ) {
		next->printTree();
		std::cout << ", ";
	} else {
		std::string message = "Tipo Fantasma " + this->id;
		switch ( this->useType ) {
			
			case AST::Array::ini: {message = "Declaracao de arranjo " + TypesString[( int )type] + " de tamanho "; break;}
			
		}
		std::cout<<message;
		this->tamanho->printTree();
		std::cout<<": " <<this->id;
		return;
	}
	std::cout << this->id;
	return;
}

void ArrayItem::printTree() {
	if( next != nullptr ) {
		next->printTree();
		std::cout << ", ";
	} else {
		std::string message = "Tipo Fantasma " + this->id;
		switch ( this->useType ) {
			
			case AST::ArrayItem::atrib: {
				message = "Atribuicao de valor para arranjo "+ TypesString[( int )type] + " " + this->id + ": \n+indice: " ; 
				std::cout<<message;
				this->indice->printTree();
				std::cout<<"\n+valor: ";

			break;}

			case AST::ArrayItem::read: {
				message = "arranjo "+ TypesString[( int )type] + " " + this->id + ": \n{+indice: " ; 
				std::cout<<message;
				this->indice->printTree();
				std::cout<<"}";

			break;}
		}
		
		return;
	}
	std::cout << this->id;
	return;
}






