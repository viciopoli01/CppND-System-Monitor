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

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() {
  processes_.clear();

  for (const auto& i : LinuxParser::Pids()) {
    processes_.emplace_back(
        Process(i, LinuxParser::User(i), LinuxParser::Command(i)));
  }
  bool a = false;
  processes_[0].setCpuUtils(1.0);
  if(processes_[1]<processes_[0])
    a = true;
  
  std::sort(processes_.begin(), processes_.end());
  return processes_;
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() {
  if (Kernel_info == "") Kernel_info = LinuxParser::Kernel();
  return Kernel_info;
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// TODO: Return the operating system name
std::string System::OperatingSystem() {
  if (OSinfo == "") OSinfo = LinuxParser::OperatingSystem();
  return OSinfo;
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }