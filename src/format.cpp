#include "format.h"

#include <iomanip>
#include <string>

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
  int s, m, h = 0;
  // 3600/60 = 60
  s = seconds % 60;
  m = (seconds / 60) % 60;
  h = ((seconds / 60) / 60) % 60;
  std::stringstream str;
  str << std::setw(2) << std::setfill('0') << h << ":" << std::setw(2)
      << std::setfill('0') << m << ":" << std::setw(2) << std::setfill('0')
      << s;
  return str.str();
}