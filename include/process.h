#ifndef PROCESS_H
#define PROCESS_H

#include <linux_parser.h>

#include <string>

using std::string;
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int pid)
      : pid_(pid),
        user_(LinuxParser::User(pid)),
        command_(LinuxParser::Command(pid)),
        cpu_utilization_((float)LinuxParser::ActiveJiffies(pid) /
                         (float)LinuxParser::Jiffies()),
        ram_(LinuxParser::Ram(pid)),
        uptime_(LinuxParser::UpTime(pid)){};
  int Pid();
  string User();
  string Command();
  float CpuUtilization();
  string Ram();
  long int UpTime();
  bool operator<(Process const& a) const;
  float CPUutilNow();

 private:
  int pid_;
  string user_;
  string command_;
  float cpu_utilization_;
  string ram_;
  long int uptime_;
};

#endif