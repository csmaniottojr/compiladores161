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
					return DataContainer( *thisValue + *otherValue );
					break;
				}
				case DataContainer::tDouble: { //Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue + *otherValue );
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
			}//Double *
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
			}//Double *
		}
	}
}
//Data insertion===================================================================================
//Integer========================================
void DataContainer::insertData( int &data ) {
	this->type = DataContainer::tInteger;
	this->data = &data;
}
//Double=========================================
void DataContainer::insertData( double &data ) {
	this->type = DataContainer::tDouble;
	this->data = &data;
}
//Information======================================================================================
DataContainer::DataTypes DataContainer::getType() const {
	return this->type;
}
//===============================================
std::ostream &operator<< ( std::ostream &out,const DataContainer &dataContainer ) {
	switch( dataContainer.getType() ) {
		case DataContainer::tDouble: {
			double *value = ( double * ) dataContainer.data;
			out << *value;
			return out;
			break;
		}
		case DataContainer::tInteger: {
			int *value = ( int * ) dataContainer.data;
			out << *value;
			return out;
			break;
		}
		default: {
			out << "Unimplementes DataContainer type print!";
			return out;
		}
	}
	return out;
};

