#include "string2wstring.h"

wstring string2wstring(const std::string &str){
  wstring res(str.begin(), str.end());
  return res;
}
