#include "process.h"

#include <linux_parser.h>
#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return this->pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  currActive = LinuxParser::ActiveJiffies(this->pid_);
  currTotal = LinuxParser::Jiffies();
  float totald = currTotal - prevTotal;
  float actived = currActive - prevActive;
  _UpdateUtilization();
  cpu_utilization = actived / totald;
  return cpu_utilization;
}

void Process::_UpdateUtilization() {
  if (prevTotal == 0 && prevActive == 0) {
    prevActive = LinuxParser::ActiveJiffies(this->pid_);
    prevTotal = LinuxParser::Jiffies();
    return;
  }
  prevActive = currActive;
  prevTotal = currTotal;
}

// TODO: Return the command that generated this process
string Process::Command() { return this->command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(this->pid_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return this->user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(this->pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  return getCPUutil() < a.getCPUutil();
}
