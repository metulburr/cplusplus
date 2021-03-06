#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <initializer_list>
#include <algorithm> 

template <class KEY, class VALUE>
class Dict{
    public:
        std::map<KEY, VALUE> dictionary;
        
        void update(KEY k, VALUE v){
        //add a new key/value pair
            dictionary[k] = v;
        }
        
        std::vector<KEY> keys(){
        //return all keys from dictionary
            std::vector<KEY> v;
            for(class std::map<KEY, VALUE>::const_iterator it = dictionary.begin();
            it != dictionary.end(); ++it){
                v.push_back(it->first);
            }
            return v;
        }
        
        std::vector<VALUE> values(){
        //return all values from dictionary
            std::vector<VALUE> v;
            for(class std::map<KEY, VALUE>::const_iterator it = dictionary.begin();
            it != dictionary.end(); ++it){
                v.push_back(it->second);
            }
            return v;
        }
        VALUE pop(KEY k){
        //return value of key removed, removes key/value pair in process
            VALUE val = dictionary[k];
            dictionary.erase(k);
            return val;
        }
        
        VALUE get(KEY k){
        //return value of k given
            VALUE val = dictionary[k];
            return val;
        }
        
        void clear(){
            dictionary.clear();
        }
        
        void fromkeys(std::initializer_list<KEY> keys, VALUE v){
        //set all of list as keys, with each having a value of v
            for(auto k:keys){
                dictionary[k] = v;
            }
        }
        
        std::string display(){
            std::string disp;
            for(auto key:keys()){
                disp += key;
                disp += " -> ";
                disp += this->get(key);
                disp += '\n';
            }
            return disp;
        }
        
        std::vector<KEY> sorted(){
        //return vector of sorted keys
            std::vector<VALUE> v;
            for(class std::map<KEY, VALUE>::const_iterator it = dictionary.begin();
            it != dictionary.end(); ++it){
                v.push_back(it->second);
            }
            std::sort(v.begin(), v.end());
            std::vector<KEY> k;
            for (int i=0; i < v.size(); i++){
                for (auto key:keys()){
                    if (v[i]==get(key)){
                        k.push_back(key);
                    }
                }
            }
            return k;
        }
};

int main(){
    Dict<std::string, std::string> d;
    d.update("key", "value");
    d.update("key2", "value2");
    
    for (auto i:d.keys())
        std::cout << i << std::endl;
        
    for (auto i:d.values())
        std::cout << i << std::endl;

    std::cout << "removing " << d.pop("key2") << '\n';
    
    std::cout << d.dictionary["key"] << std::endl;
    std::cout << d.get("key") << std::endl;
    
    d.clear();
    
    d.fromkeys({"a", "b", "c", "d"}, "0");
    
    for(auto key:d.keys()){
        std::cout << key << " = " << d.get(key) << std::endl;
    }
    
    std::cout << d.display();
    
    
    Dict<std::string, int> dicter;
    dicter.update("key", 6);
    dicter.update("key2", 2);
    dicter.update("key3", 28);
    dicter.update("key4", 1);
    dicter.update("key5", 11);
    for(auto key:dicter.sorted()){
        std::cout << key << " = " << dicter.get(key) << std::endl;
    }

}
