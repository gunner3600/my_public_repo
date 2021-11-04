#include "utils.h"

void square_fun(int &in_var) {
  in_var = in_var * in_var;
  printf("call square_fun()\n");
}

GaitState::GaitState(/* args */)
  : state_(State::StopControl)
  , start_time_{0, 0, 0, 0, 0, 0, 0}
  , ref_force_(0)
  , ref_location_(0)
{
  printf("construct GaitState\n");
  state_ = State::StopControl;
  m_class.add_test();
}

void GaitState::update_start_time(const uint32_t &in_time) {
  switch (state_)
  {
  case State::StopControl:
    start_time_.StopControl = in_time;
    break;
  case State::PreStrike:
    start_time_.PreStrike = in_time;
    break;
  case State::OnGround:
    start_time_.OnGround = in_time;
    break;
  case State::OnGroundLongTime:
    start_time_.OnGroundLongTime = in_time;
    break;
  case State::ReadyControl:
    start_time_.ReadyControl = in_time;
    break;
  case State::StartControl:
    start_time_.StartControl = in_time;
    break;
  case State::TurnAround:
    start_time_.TurnAround = in_time;
    break;
  default:
    break;
  }
}