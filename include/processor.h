#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();
  void UpdateUtilization();

 private:
  long prevActive{0};
  long prevTotal{0};

  long currActive{0};
  long currTotal{0};
};

#endif