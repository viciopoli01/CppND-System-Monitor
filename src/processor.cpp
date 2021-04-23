#include "processor.h"

#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  currActive = LinuxParser::ActiveJiffies();
  currTotal = LinuxParser::Jiffies();
  float totald = currTotal - prevTotal;
  float actived = currActive - prevActive;
  UpdateUtilization();
  return actived / totald;
}

void Processor::UpdateUtilization() {
  if (prevTotal == 0 && prevActive == 0) {
    prevActive = LinuxParser::ActiveJiffies();
    prevTotal = LinuxParser::Jiffies();
    return;
  }
  prevActive = currActive;
  prevTotal = currTotal;
}