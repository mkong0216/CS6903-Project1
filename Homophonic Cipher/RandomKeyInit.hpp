#ifndef RandomKeyInit_hpp
#define RandomKeyInit_hpp

#include <stdio.h>
#include <string>

class RandomKeyInit {

public:
  int GetPutativeKey(std::vector<int>);

private:
  bool sortbyth(const tuple<int, char, float>&, const tuple<int, char, float>&);
  //void map_char_to_num_by_freq(vector<pair<int, float>, int, float, char, int&);
};


#endif
