/*
 * Copyright 2016 <copyright holder> <email>
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

DataContainer::DataContainer( double &value ) {
	insertData( value );
}

DataContainer::DataContainer( int value ) {
	insertData( value );
}
DataContainer::~DataContainer() {
}


//Operations=======================================================================================
//Equalty========================================
bool DataContainer::operator==( const DataContainer &other ) const {
	if( this->getType() != other.getType ) {
		return false;
	}
	switch( this->getType() ) {
		case DataContainer::tInteger:
			int *thisValue = ( int * )this->data;
			int *otherValue = ( int * )other.data;
			return ( *thisValue == *otherValue );
			break;
		case DataContainer::tDouble:
			double *thisValue = ( double * )this->data;
			double *otherValue = ( double * )other.data;
			return ( *thisValue == *otherValue );
			break;
	}
	return false;
}
//Addition=======================================
DataContainer DataContainer::operator+( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger:
			switch ( other.type ) {
				case DataContainer::tInteger://Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue + otherValue );
					break;
				case DataContainer::tDouble://Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue + *otherValue );
					break;
			}//Int + *
		case DataContainer::tDouble:
			switch ( other.type ) {
				case DataContainer::tInteger://Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue + *otherValue );
					break;
				case DataContainer::tDouble:
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue + *otherValue );
			}//Double *
	}
}
//Multiplication=================================
DataContainer DataContainer::operator*( DataContainer &other ) {
	switch( this->type ) {
		case DataContainer::tInteger:
			switch ( other.type ) {
				case DataContainer::tInteger://Int Int
					int *thisValue = ( int * )this->data;
					int *otherValue = ( int * )other.data;
					return DataContainer( *thisValue * otherValue );
					break;
				case DataContainer::tDouble://Int Double
					int *thisValue =  ( int * )this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue * *otherValue );
					break;
			}//Int + *
		case DataContainer::tDouble:
			switch ( other.type ) {
				case DataContainer::tInteger://Double Int
					double *thisValue = ( double * ) this->data;
					int *otherValue = ( int * ) other.data;
					return DataContainer( *thisValue * *otherValue );
					break;
				case DataContainer::tDouble:
					double *thisValue = ( double * ) this->data;
					double *otherValue = ( double * )other.data;
					return DataContainer( *thisValue * *otherValue );
			}//Double *
	}
}




//Data insertion===================================================================================
//Integer========================================
void DataContainer::insertData( int &data ) {
	this->type = DataContainer::tInteger;
	this->data = &data;
	this->type = DataTypes::DataContainer::tInteger;
	this->data = &data;
}
//Double=========================================
void DataContainer::insertData( double &data ) {
	this->type = DataTypes::DataContainer::tDouble;
	this->data = &data;
}
//Information======================================================================================
DataContainer::DataTypes DataContainer::getType() {
	return this->type;
}




