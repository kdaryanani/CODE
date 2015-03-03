//
//  main.cpp
//  coen70Lab7
//*Do not make any changes to this file, use it to test your implementation.*
//*Include your map implementation appropiately.*


#include <iostream>
#include "map.h"

int main(int argc, const char * argv[])
{
    
    //Creating Maps
    Map<int,int>intMap;
    Map<string, int>strIntMap;
    Map<string, string> strMap;
    Map<int,string> intStrMap;
    
    //TestCases
    
    cout<<"=====Map(INT,INT)======\n";
    intMap.remove_key(1); //Shouldn't do anything.
    intMap.value_of(2); //Shouldn't do anything.
    
    intMap.insert(1, 10);
    intMap.insert(2, 20);
    intMap.insert(3, 30);
    intMap.insert(1, 40); //Shouldn't insert
    //    intMap.printMap(); Implementation not necessary, good for debugging.
    
    if (intMap.contains_key(2)) { //Should display: Contains key 2 with value 20
        cout<<"Contains key 2 with value "<<intMap.value_of(2)<<endl;
    }

    if (!intMap.contains_key(4)) {//Should display: Doesn't contain key 4
        cout<<"Doesn't contain key 4"<<endl;
    }
    
    intMap.remove_key(2);//Should remove "Key:2 Value:20"
    
    if (!intMap.contains_key(2)) {//Should display: Doesn't contain key 2
        cout<<"Doesn't contain key 2"<<endl;
    }
    
    
    //    intMap.printMap(); Implementation not necessary, good for debugging.
    
    
    
    
    cout<<"=====Map(STRING,INT)======\n";
    strIntMap.remove_key("ONE"); //Shouldn't do anything.
    strIntMap.value_of("ONE"); //Shouldn't do anything.
    
    strIntMap.insert("ONE", 10);
    strIntMap.insert("TWO", 20);
    strIntMap.insert("THREE", 30);
    strIntMap.insert("ONE", 40); //Shouldn't insert
    //    strIntMap.printMap(); Implementation not necessary, good for debugging.
    
    if (strIntMap.contains_key("TWO")) {//Should display: Contains key "TWO" with value 20
        cout<<"Contains key \"TWO\" with value "<<strIntMap.value_of("TWO")<<endl;
    }
    
    if (!strIntMap.contains_key("FOUR")) {//Should display: Doesn't contain key "FOUR"
        cout<<"Doesn't contain key \"FOUR\""<<endl;
    }
    
    strIntMap.remove_key("TWO");
    
    if (!strIntMap.contains_key("TWO")) {//Should display: Doesn't contain key "TWO"
        cout<<"Doesn't contain key \"TWO\""<<endl;
    }
    
    //    strIntMap.printMap(); Implementation not necessary, good for debugging.
    
    
    
    
    cout<<"=====Map(STRING,STRING)======\n";
    strMap.remove_key("ONE"); //Shouldn't do anything.
    strMap.value_of("ONE"); //Shouldn't do anything.
    
    strMap.insert("ONE", "STRING1");
    strMap.insert("TWO", "STRING2");
    strMap.insert("THREE", "STRING3");
    strMap.insert("ONE", "SHOULDN'T_BE_ADDED"); //Shouldn't insert
    //    strMap.printMap(); Implementation not necessary, good for debugging.
    
    if (strMap.contains_key("TWO")) {//Should display: Contains key "TWO" with value STRING2
        cout<<"Contains key \"TWO\" with value "<<strMap.value_of("TWO")<<endl;
    }
    
    if (!strMap.contains_key("FOUR")) {//Should display: Doesn't contain key "FOUR"
        cout<<"Doesn't contain key \"FOUR\""<<endl;
    }
    
    strMap.remove_key("TWO");
    
    if (!strMap.contains_key("TWO")) {//Should display: Doesn't contain key "TWO"
        cout<<"Doesn't contain key \"TWO\""<<endl;
    }
    
    //    strMap.printMap(); Implementation not necessary, good for debugging.
    
    
    
    
    cout<<"=====Map(INT,STRING)======\n";
    intStrMap.remove_key(1); //Shouldn't do anything.
    intStrMap.value_of(2); //Shouldn't do anything.
    
    intStrMap.insert(1, "STRING1");
    intStrMap.insert(2, "STRING2");
    intStrMap.insert(3, "STRING3");
    intStrMap.insert(1, "SHOULDN'T_BE_ADDED"); //Shouldn't insert
    //    intStrMap.printMap(); Implementation not necessary, good for debugging.
    
    if (intStrMap.contains_key(2)) { //Should display: Contains key 2 with value STRING2
        cout<<"Contains key 2 with value "<<intStrMap.value_of(2)<<endl;
    }
    if (!intStrMap.contains_key(4)) {//Should display: Doesn't contain key 4
        cout<<"Doesn't contain key 4"<<endl;
    }
    
    intStrMap.remove_key(2);//Should remove "Key:2 Value:20"
    
    if (!intStrMap.contains_key(2)) {//Should display: Doesn't contain key 2
        cout<<"Doesn't contain key 2"<<endl;
    }
    
    
    //    intStrMap.printMap(); Implementation not necessary, good for debugging.
    
    
     
    
    return 0;
}

