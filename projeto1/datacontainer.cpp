/*
 * Copyright 2016 <Luis Decker> <luisgustavo.decker@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "datacontainer.h"
//DataContainer==================================
DataContainer::DataContainer( double value ) {
	insertData( value );
}

DataContainer::DataContainer( int value ) {
	insertData( value );
}

DataContainer::DataContainer( bool value ) {
	insertData( value );
}
DataContainer::~DataContainer() {
//TODO Dá muito pau, memory leak acontece nas melhores familias!
// 	switch( type ) {
// 		case DataContainer::tDouble: {
// 			delete[] ( double * ) data;
// 			break;
// 		}
// 		case DataContainer::tInteger: {
// 			delete ( int * ) data;
// 			break;
// 		}
// 	}
}

//DataContainer====================================================================================

//Operations=======================================================================================
//Equalty========================================
bool DataContainer::operator==( const DataContainer &other ) const {
	if( this->type != other.type ) {
		return false;
	}
	switch( this->type ) {
		case DataContainer::tInteger: {
			int *thisValue = ( int * )this->data;
			int *otherValue = ( int * )other.data;
			return ( *thisValue == *otherValue );
			break;
		}
		case DataContainer::tDouble: {
			double *thisValue = ( double * )this->data;
			double *otherValue = ( double * )other.data;
			return ( *thisValue == *otherValue );
			break;
		}
		case  DataContainer::tBool: {
			return ( *( bool * )this->data == *( bool * )other.data );
		}
	}
	return false;
}
//Addition=======================================
DataContainer DataContainer::operator+( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					//std::cout<<"[DEBUG][DataContainer] Vai somar " << *thisValue << " + " <<*otherValue<<std::endl;
					return DataContainer( *thisValue + *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue + *otherValue );
					break;
				}
				case DataContainer::tBool: {
					INCOMPATIBLE_TYPES_OPERATION_SUM( this->type,other.type );
					break;
				}
			}//Int + *
			break;
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue + *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue + *otherValue );
					break;
				}
				case DataContainer::tBool: {
					INCOMPATIBLE_TYPES_OPERATION_SUM( this->type,other.type );
					break;
				}
			}//Double *
			break;
		}
		case DataContainer::tBool: {
			INCOMPATIBLE_TYPES_OPERATION_SUM( this->getType(),other.getType() );
			break;
		}
	}
}
//Multiplication=================================
DataContainer DataContainer::operator*( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue * *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue * *otherValue );
					break;
				}
				case DataContainer::tBool: {
					INCOMPATIBLE_TYPES_OPERATION_MULT( this->getType(),other.getType() );
					break;
				}
			}//Int + *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue * *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue * *otherValue );
				}
				case DataContainer::tBool: {
					INCOMPATIBLE_TYPES_OPERATION_MULT( this->getType(),other.getType() );
					break;
				}
			}//Double *
		}
		case DataContainer::tBool: {
			INCOMPATIBLE_TYPES_OPERATION_MULT( this->getType(),other.getType() );
			break;
		}
	}
}

//Sub=================================
DataContainer DataContainer::operator-( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue - *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue - *otherValue );
					break;
				}
				case DataContainer::tBool: {
					INCOMPATIBLE_TYPES_OPERATION_SUB( this->getType(),other.getType() );
					break;
				}
			}//Int + *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue - *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue - *otherValue );
				}
				case DataContainer::tBool: {
					INCOMPATIBLE_TYPES_OPERATION_SUB( this->getType(),other.getType() );
					break;
				}
			}//Double *
		}
		case DataContainer::tBool: {
			INCOMPATIBLE_TYPES_OPERATION_SUB( this->getType(),other.getType() );
			break;
		}
	}
}

//Div=================================
DataContainer DataContainer::operator/( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue / *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue / *otherValue );
					break;
				}
				case DataContainer::tBool: {
					INCOMPATIBLE_TYPES_OPERATION_DIV( this->getType(),other.getType() );
					break;
				}
			}//Int + *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue / *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue / *otherValue );
				}
				case DataContainer::tBool: {
					INCOMPATIBLE_TYPES_OPERATION_DIV( this->getType(),other.getType() );
					break;
				}
			}//Double *
		}
		case DataContainer::tBool: {
			INCOMPATIBLE_TYPES_OPERATION_DIV( this->getType(),other.getType() );
			break;
		}
	}
}

//maior=================================
DataContainer DataContainer::operator>( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue > *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue > *otherValue );
					break;
				}
			}//Int + *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue > *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue > *otherValue );
				}
			}//Double *
		}
	}
}

//menor=================================
DataContainer DataContainer::operator<( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue < *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue < *otherValue );
					break;
				}
			}//Int + *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue < *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue < *otherValue );
				}
			}//Double *
		}
	}
}

//maior ou igual=================================
DataContainer DataContainer::operator>=( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue >= *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue >= *otherValue );
					break;
				}
			}//Int + *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue >= *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue >= *otherValue );
				}
			}//Double *
		}
	}
}

//menor ou igual=================================
DataContainer DataContainer::operator<=( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue <= *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue <= *otherValue );
					break;
				}
			}//Int <= *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue <= *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue <= *otherValue );
				}
			}//Double <=  *
		}
	}
}

//igual=================================
DataContainer DataContainer::operator==( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue == *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue == *otherValue );
					break;
				}
			}//Int + *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue == *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue == *otherValue );
				}
			}//Double *
		}
		case DataContainer::tBool: {
			if( other.type == DataContainer::tBool ) {
				bool *thisValue = ( bool * ) this->data;
				bool *otherValue = ( bool * ) other.data;
				return DataContainer( *thisValue == *otherValue );
			}
		}
	}
}

//diferente=================================
DataContainer DataContainer::operator!=( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue != *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue != *otherValue );
					break;
				}
			}//Int + *
		}
		case DataContainer::tDouble: {
			switch ( other.type ) {
				case DataContainer::tInteger: { //Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue != *otherValue );
					break;
				}
				case DataContainer::tDouble: {//Double Double
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue != *otherValue );
				}
			}//Double *
		}
		case DataContainer::tBool: {
			if( other.type == DataContainer::tBool ) {
				bool *thisValue = ( bool * ) this->data;
				bool *otherValue = ( bool * ) other.data;
				return DataContainer( *thisValue != *otherValue );
			}
		}
	}
}


//and=================================
DataContainer DataContainer::operator&&( DataContainer &other ) {
	if( this->type == DataContainer::tBool && other.type == DataContainer::tBool ) {
		bool *thisValue = ( bool * ) this->data;
		bool *otherValue = ( bool * ) other.data;
		return DataContainer( *thisValue && *otherValue );
	}
}

//or=================================
DataContainer DataContainer::operator||( DataContainer &other ) {
	if( this->type == DataContainer::tBool && other.type == DataContainer::tBool ) {
		bool *thisValue = ( bool * ) this->data;
		bool *otherValue = ( bool * ) other.data;
		return DataContainer( *thisValue || *otherValue );
	}
}

//not=================================
DataContainer DataContainer::operator!() {
	if( this->type == DataContainer::tBool ) {
		bool *thisValue = ( bool * ) this->data;
		return DataContainer( ! *thisValue );
	}
}

//Data insertion===================================================================================
//Integer========================================
void DataContainer::insertData( int &newData ) {
	this->type = DataContainer::tInteger;
	//std::cout<<"[DEBUG][DataContainer] Vai criar int " << newData << std::endl;
	this->data = new int( newData );
	//std::cout<<"[DEBUG][DataContainer] ctiou int " << *(int*)data << std::endl;
}
//Double=========================================
void DataContainer::insertData( double &newData ) {
	this->type = DataContainer::tDouble;
	//std::cout<<"[DEBUG][DataContainer] Vai criar double " << data << std::endl;
	this->data = new double( newData );
}
//Bool=========================================
void DataContainer::insertData( bool &newData ) {
	this->type = DataContainer::tBool;
	//std::cout<<"[DEBUG][DataContainer] Vai criar bool " << data << std::endl;
	this->data = new bool( newData );
}
//Information======================================================================================
DataContainer::DataTypes DataContainer::getType() const {
	return this->type;
}
//===============================================
std::ostream &operator<< ( std::ostream &out,const DataContainer &dataContainer ) {
	switch( dataContainer.getType() ) {
		case DataContainer::tDouble: {
			double value = *( double * ) dataContainer.data;
			out << value;
			return out;
			break;
		}
		case DataContainer::tInteger: {
			int value = *( int * ) dataContainer.data;
//			std::cout<<"[DEBUG][DataContainer] dentro << : " << *(int*)dataContainer.data << std::endl;
			out << value;
			return out;
			break;
		}
		case DataContainer::tBool: {
			bool value = *( bool * ) dataContainer.data;
			out << value;
			return out;
			break;
		}
		default: {
			out << "Unimplemented DataContainer type print!";
			return out;
		}
	}
	return out;
};

std::string DataContainer::typeToString() {
	switch ( this->type ) {
		case DataContainer::tBool: {return "booleanov"; break;}
		case DataContainer::tDouble: {return "real"; break;}
		case DataContainer::tInteger: {return "inteiro"; break;}
	}
}
