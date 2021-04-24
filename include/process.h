#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid, std::string user, std::string command)
      : pid_(pid), user_(user), command_(command){
        CpuUtilization();
      };
  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();            // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  float getCPUutil() const{return cpu_utilization;}
  // TODO: Declare any necessary private members
 private:
  int pid_{0};
  std::string user_{""};
  std::string command_{""};
  float cpu_utilization{0.0};
};

#endif