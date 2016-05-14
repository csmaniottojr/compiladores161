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
#include <iostream>
#ifndef DATACONTAINER_H
#define DATACONTAINER_H

class DataContainer {
public:
	enum DataTypes {tInteger = 0, tDouble, tBool,tIntegerArr};
	DataContainer() {this->type = tInteger;  this->data = new int( 666 );};
	DataContainer( int value );
	DataContainer( double value );
	DataContainer( bool value );
	std::string typeToString();
	~DataContainer();
	void insertData( int &newDdata );
	void insertData( double &newDdata );
	void insertData( bool &newData );
	DataTypes getType() const;
	DataContainer operator+ ( DataContainer &other );
	DataContainer operator* ( DataContainer &other );
	DataContainer operator- ( DataContainer &other );
	DataContainer operator/ ( DataContainer &other );
	DataContainer operator> ( DataContainer &other );
	DataContainer operator< ( DataContainer &other );
	DataContainer operator>= ( DataContainer &other );
	DataContainer operator<= ( DataContainer &other );
	DataContainer operator== ( DataContainer &other );
	DataContainer operator!= ( DataContainer &other );
	DataContainer operator&& ( DataContainer &other );
	DataContainer operator|| ( DataContainer &other );
	DataContainer operator! ();
	bool operator==( const DataContainer &other ) const;
	void *data;
	friend std::ostream &operator<< ( std::ostream &out,const DataContainer &dataContainer );
private:
	void INCOMPATIBLE_TYPES_OPERATION_SUM( DataTypes type1,DataTypes type2 ) {
#define str(x) #x
		std::cerr<<"Can't sum a " << str( type1 ) <<" with a " << str( type2 ) << "!" <<std::endl;
#undef str
	};
	void INCOMPATIBLE_TYPES_OPERATION_MULT( DataTypes type1,DataTypes type2 ) {
#define str(x) #x
		std::cerr<<"Can't multiply a " << str( type1 ) <<" with a " << str( type2 ) << "!" <<std::endl;
#undef str
	};
	void INCOMPATIBLE_TYPES_OPERATION_DIV( DataTypes type1,DataTypes type2 ) {
#define str(x) #x
		std::cerr<<"Can't divide a " << str( type1 ) <<" with a " << str( type2 ) << "!" <<std::endl;
#undef str
	};
	void INCOMPATIBLE_TYPES_OPERATION_SUB( DataTypes type1,DataTypes type2 ) {
#define str(x) #x
		std::cerr<<"Can't subtract a " << str( type1 ) <<" with a " << str( type2 ) << "!" <<std::endl;
#undef str
	};
	DataTypes type;

};


#endif // DATACONTAINER_H
