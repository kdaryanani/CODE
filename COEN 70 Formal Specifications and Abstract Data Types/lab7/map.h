#include <iostream>
#include "Pair.h"
#include <list>

using namespace std;

template<typename K, typename V>
class Map
{
public:
   /**
      Inserts a value into the map.
       @param key the key to insert
      @param value the value to insert
*/
void insert(K key, V Value);
   /**
      Determines whether the map contains a given key.
      @param key the key to check for
   */
bool contains_key(K Key);
   /**
      Retrieves the value of a given key.
      @param key the key to find
      @return the value
*/
V value_of(K Key);
   /**
      Removes the key and value.
      @param key the key to find
*/
void remove_key(K Key); // include case where the key doesnt exist

void print();
private:
   list< Pair<K, V> > data;
    V error1; //value for return function in terms of V
};

//iterator of type list pair
template <typename K, typename V>
void Map<K,V>::insert(K Key, V Value){
//create new pair and put pair in object of data
//push back each pait to end. 
//create a constructor and access pair using iterators
//iterator++. *it will give value of data. call functions
	typename list< Pair<K,V> >::iterator START = data.begin();
	typename list< Pair<K,V> >::iterator END = data.end();
	while(START!=END){
		if(START->get_first()==Key)
			return; // returns if the value is found
		START++;
	}
	Pair<K,V> temp=Pair<K,V>(Key,Value);		
	data.push_back(temp); // inserts the new pair into data list

}
	

template <typename K, typename V>
bool Map<K,V>::contains_key(K Key){
	typename list< Pair<K,V> >::iterator START = data.begin();
        typename list< Pair<K,V> >::iterator END = data.end();
        while(START!=END){
                if(START->get_first()==Key) // same contains type of funciton that helps with finding right key
                        return true;
                else
			START++;
        }
	
	return false; // returns boolian if there or not

}

template <typename K, typename V>
V Map<K,V>::value_of(K Key){
    
    if(!contains_key(Key))
		return error1; // error in terms of type V
	typename list< Pair<K,V> >::iterator START = data.begin();
        typename list< Pair<K,V> >::iterator END = data.end();
        while(START!=END){
                if(START->get_first()==Key)
                    return START->get_second(); // returns the value from the key
                	START++;
        }


}
template <typename K, typename V>
void Map<K,V>::remove_key(K Key){

	if(!contains_key(Key))
		return;
		
	typename list< Pair<K,V> >::iterator START = data.begin();
        typename list< Pair<K,V> >::iterator END = data.end();
        while(START!=END){
                if(START->get_first()==Key)
                    data.erase(START); // removes ellement using the list data function
                	START++;
        }
	

}


