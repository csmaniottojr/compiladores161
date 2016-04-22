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

#ifndef DATACONTAINER_H
#define DATACONTAINER_H

class DataContainer
{
public:
        enum DataTypes{tInteger, tDouble};
        DataContainer(int value);
        DataContainer(double value);
        ~DataContainer();
        void insertData(int& data);
        void insertData(double& data);
        DataTypes getType();
        DataContainer operator+ (DataContainer& other);
        DataContainer operator* (DataContainer& other);
        bool operator==(const DataContainer& other) const;
        
private:
        void* data;
        DataTypes type;
        
};

#endif // DATACONTAINER_H
