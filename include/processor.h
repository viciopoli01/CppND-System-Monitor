#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
  void UpdateUtilization();
  // TODO: Declare any necessary private members
 private:
  long prevActive{0};
  long prevTotal{0};

  long currActive{0};
  long currTotal{0};
};

#endif