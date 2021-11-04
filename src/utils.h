#ifndef SRC_UTILS_HEADER
#define SRC_UTILS_HEADER

#include <math.h>
#include <stdint.h>
#include <stdio.h>

void square_fun(int &in_var);

enum State {
  StopControl = 0,
  PreStrike,
  OnGround,
  OnGroundLongTime,
  ReadyControl,
  StartControl,
  TurnAround,
  Idle,
};

typedef struct _state_start_time {
  uint32_t StopControl;
  uint32_t PreStrike;
  uint32_t OnGround;
  uint32_t OnGroundLongTime;
  uint32_t ReadyControl;
  uint32_t StartControl;
  uint32_t TurnAround;
} state_start_time_t;

class minimal_class {
private:
  int test1;
  float test2;

public:
  minimal_class() : test1(5), test2(1.5f) {
    printf("construct minimal class\n");
  };
  ~minimal_class() { printf("deconstruct minimal class\n"); };
  void add_test() {
    test1++;
    test2 += 1;
    printf("test1: %d\ttest2: %f\n");
  };
};

class GaitState {
private:
  State state_;
  State last_state_;
  state_start_time_t start_time_;
  float ref_force_;
  float ref_location_;
  float last_ref_force_;
  float last_ref_location_;
  bool change_state_flag_;

public:
  minimal_class m_class;

public:
  GaitState(/* args */);
  ~GaitState() {
    // m_class.~minimal_class();
    printf("deconstruct GaitState\n");
  };
  void update_start_time(const uint32_t &in_time);
};

#endif // SRC_UTILS_HEADER