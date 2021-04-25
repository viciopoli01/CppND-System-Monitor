
#include "system.h"

#include <unistd.h>

#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

//  Return the system's CPU
Processor& System::Cpu() { return cpu_; }

//  Return a container composed of the system's processes
vector<Process>& System::Processes() {
  processes_.clear();

  for (const auto& i : LinuxParser::Pids()) {
    processes_.emplace_back(Process(i));
  }

  std::sort(processes_.begin(), processes_.end());
  // std::reverse(processes_.begin(), processes_.end());
  // Not needed because I overloaded "less than" with "more than"
  return processes_;
}

//  Return the system's kernel identifier (string)
std::string System::Kernel() {
  if (Kernel_info == "") Kernel_info = LinuxParser::Kernel();
  return Kernel_info;
}

//  Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

//  Return the operating system name
std::string System::OperatingSystem() {
  if (OSinfo == "") OSinfo = LinuxParser::OperatingSystem();
  return OSinfo;
}

//  Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

//  Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

//  Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }